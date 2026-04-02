/*
 * Copyright (c) 2026
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <errno.h>
#include <stdbool.h>
#include <stdint.h>
#include <zephyr/device.h>
#include <zephyr/drivers/sensor.h>
#include <zephyr/kernel.h>
#include <zephyr/sys/printk.h>

#include "arm_math.h"

#define PRODUCER_STACK_SIZE 1024
#define CONSUMER_STACK_SIZE 1024
#define PRODUCER_PRIORITY 5
#define CONSUMER_PRIORITY 5
#define PRODUCER_PERIOD_MS 1000
#define CONSUMER_PERIOD_MS 1300
#define SENSOR_QUEUE_LENGTH 6
#define CIRCULAR_BUFFER_LENGTH 32
#define FFT_SIZE 32
#define FFT_COMPLEX_BIN_COUNT ((FFT_SIZE / 2) - 1)
#define FFT_BAND_COUNT ((FFT_SIZE / 2) + 1)

#define TEMP_SENSOR_NODE DT_ALIAS(ambient_temp0)

#if !DT_NODE_EXISTS(TEMP_SENSOR_NODE)
#error "No ambient-temp0 devicetree alias found for the onboard P3T1755DP sensor"
#endif

struct sensor_sample {
	uint32_t sequence;
	int32_t temperature_milli_c;
	int64_t uptime_ms;
};

struct demo_stats {
	uint32_t produced;
	uint32_t consumed;
	uint32_t dropped;
	uint32_t fft_runs;
	uint32_t buffer_overwrites;
	int32_t last_temperature_milli_c;
};

struct circular_buffer {
	struct sensor_sample samples[CIRCULAR_BUFFER_LENGTH];
	uint8_t head;
	uint8_t count;
};

K_MSGQ_DEFINE(sensor_msgq, sizeof(struct sensor_sample), SENSOR_QUEUE_LENGTH, 4);
K_SEM_DEFINE(sample_ready_sem, 0, SENSOR_QUEUE_LENGTH);
K_MUTEX_DEFINE(console_mutex);

static struct demo_stats stats;
static struct circular_buffer fft_buffer;
static const struct device *const temp_sensor = DEVICE_DT_GET(TEMP_SENSOR_NODE);
static arm_rfft_fast_instance_f32 fft_instance;
static struct k_thread producer_thread_data;
static struct k_thread consumer_thread_data;
K_THREAD_STACK_DEFINE(producer_stack, PRODUCER_STACK_SIZE);
K_THREAD_STACK_DEFINE(consumer_stack, CONSUMER_STACK_SIZE);
static float fft_input[FFT_SIZE];
static float fft_output[FFT_SIZE];
static float fft_magnitude[FFT_BAND_COUNT];

static int32_t sensor_value_to_milli_c(const struct sensor_value *value)
{
	return (int32_t)(((int64_t)value->val1 * 1000) + (value->val2 / 1000));
}

static uint32_t magnitude_to_milli(float value)
{
	if (value <= 0.0f) {
		return 0U;
	}

	return (uint32_t)((value * 1000.0f) + 0.5f);
}

static bool circular_buffer_push(struct circular_buffer *buffer,
				 const struct sensor_sample *sample)
{
	bool overwrote_oldest = (buffer->count == CIRCULAR_BUFFER_LENGTH);

	buffer->samples[buffer->head] = *sample;
	buffer->head = (buffer->head + 1U) % CIRCULAR_BUFFER_LENGTH;

	if (!overwrote_oldest) {
		buffer->count++;
	}

	return overwrote_oldest;
}

static uint8_t circular_buffer_oldest_index(const struct circular_buffer *buffer)
{
	if (buffer->count == CIRCULAR_BUFFER_LENGTH) {
		return buffer->head;
	}

	return 0U;
}

static uint32_t circular_buffer_average_interval_ms(const struct circular_buffer *buffer)
{
	uint8_t oldest = circular_buffer_oldest_index(buffer);
	uint64_t total_interval_ms = 0U;

	for (uint8_t i = 1U; i < buffer->count; i++) {
		const struct sensor_sample *previous =
			&buffer->samples[(oldest + i - 1U) % CIRCULAR_BUFFER_LENGTH];
		const struct sensor_sample *current =
			&buffer->samples[(oldest + i) % CIRCULAR_BUFFER_LENGTH];

		if (current->uptime_ms > previous->uptime_ms) {
			total_interval_ms += (uint64_t)(current->uptime_ms - previous->uptime_ms);
		}
	}

	if (total_interval_ms == 0U) {
		return PRODUCER_PERIOD_MS;
	}

	return (uint32_t)(total_interval_ms / (buffer->count - 1U));
}

static void prepare_fft_input(const struct circular_buffer *buffer,
			      uint32_t *start_sequence,
			      uint32_t *end_sequence,
			      uint32_t *sample_interval_ms)
{
	uint8_t oldest = circular_buffer_oldest_index(buffer);
	float mean = 0.0f;

	for (uint8_t i = 0U; i < CIRCULAR_BUFFER_LENGTH; i++) {
		const struct sensor_sample *sample =
			&buffer->samples[(oldest + i) % CIRCULAR_BUFFER_LENGTH];

		fft_input[i] = sample->temperature_milli_c / 1000.0f;
		mean += fft_input[i];
	}

	mean /= (float)CIRCULAR_BUFFER_LENGTH;

	for (uint8_t i = 0U; i < CIRCULAR_BUFFER_LENGTH; i++) {
		fft_input[i] -= mean;
	}

	for (uint8_t i = CIRCULAR_BUFFER_LENGTH; i < FFT_SIZE; i++) {
		fft_input[i] = 0.0f;
	}

	*start_sequence = buffer->samples[oldest].sequence;
	*end_sequence =
		buffer->samples[(oldest + CIRCULAR_BUFFER_LENGTH - 1U) % CIRCULAR_BUFFER_LENGTH].sequence;
	*sample_interval_ms = circular_buffer_average_interval_ms(buffer);
	if (*sample_interval_ms == 0U) {
		*sample_interval_ms = 1U;
	}
}

static void run_fft_and_print(bool overwrote_oldest)
{
	uint32_t fft_runs;
	uint32_t buffer_overwrites;
	uint32_t start_sequence;
	uint32_t end_sequence;
	uint32_t sample_interval_ms;
	uint32_t sample_rate_millihz;
	uint32_t band_width_millihz;

	prepare_fft_input(&fft_buffer, &start_sequence, &end_sequence, &sample_interval_ms);
	arm_rfft_fast_f32(&fft_instance, fft_input, fft_output, 0);

	fft_magnitude[0] = (fft_output[0] < 0.0f) ? -fft_output[0] : fft_output[0];
	arm_cmplx_mag_f32(&fft_output[2], &fft_magnitude[1], FFT_COMPLEX_BIN_COUNT);
	fft_magnitude[FFT_SIZE / 2] = (fft_output[1] < 0.0f) ? -fft_output[1] : fft_output[1];

	sample_rate_millihz = 1000000U / sample_interval_ms;
	band_width_millihz = sample_rate_millihz / FFT_SIZE;

	k_mutex_lock(&console_mutex, K_FOREVER);
	stats.fft_runs++;
	fft_runs = stats.fft_runs;
	buffer_overwrites = stats.buffer_overwrites;
	printk("[fft         ] run=%u window_seq=%u..%u interval=%u ms buffer=%s overwrites=%u\n",
	       fft_runs, start_sequence, end_sequence, sample_interval_ms,
	       overwrote_oldest ? "overwrite" : "fill", buffer_overwrites);

	for (uint32_t band = 0U; band < FFT_BAND_COUNT; band++) {
		uint32_t low_millihz = band * band_width_millihz;
		uint32_t high_millihz = (band == (FFT_SIZE / 2)) ?
			(sample_rate_millihz / 2U) : ((band + 1U) * band_width_millihz);
		uint32_t magnitude_milli = magnitude_to_milli(fft_magnitude[band]);

		printk("[fft         ] band=%u range=%u.%03u-%u.%03u Hz magnitude=%u.%03u\n",
		       band,
		       low_millihz / 1000U, low_millihz % 1000U,
		       high_millihz / 1000U, high_millihz % 1000U,
		       magnitude_milli / 1000U, magnitude_milli % 1000U);
	}
	k_mutex_unlock(&console_mutex);
}

static void print_producer_status(const struct sensor_sample *sample, uint32_t queue_depth,
					 uint32_t produced, uint32_t dropped)
{
	int32_t whole = sample->temperature_milli_c / 1000;
	int32_t fraction = sample->temperature_milli_c % 1000;

	if (fraction < 0) {
		fraction = -fraction;
	}

	k_mutex_lock(&console_mutex, K_FOREVER);
	printk("[sensor_thread] seq=%u temp=%d.%03d C uptime=%lld ms queue=%u produced=%u dropped=%u\n",
	       sample->sequence, whole, fraction, (long long)sample->uptime_ms,
	       queue_depth, produced, dropped);
	k_mutex_unlock(&console_mutex);
}

static void print_queue_full(const struct sensor_sample *sample, uint32_t dropped)
{
	int32_t whole = sample->temperature_milli_c / 1000;
	int32_t fraction = sample->temperature_milli_c % 1000;

	if (fraction < 0) {
		fraction = -fraction;
	}

	k_mutex_lock(&console_mutex, K_FOREVER);
	printk("[sensor_thread] queue full, dropping seq=%u temp=%d.%03d C dropped=%u\n",
	       sample->sequence, whole, fraction, dropped);
	k_mutex_unlock(&console_mutex);
}

static void print_consumer_status(const struct sensor_sample *sample, uint32_t queue_depth,
					 uint32_t produced, uint32_t consumed,
					 uint32_t dropped)
{
	int32_t whole = sample->temperature_milli_c / 1000;
	int32_t fraction = sample->temperature_milli_c % 1000;

	if (fraction < 0) {
		fraction = -fraction;
	}

	k_mutex_lock(&console_mutex, K_FOREVER);
	printk("[queue_thread ] seq=%u temp=%d.%03d C uptime=%lld ms queue=%u produced=%u consumed=%u dropped=%u\n",
	       sample->sequence, whole, fraction, (long long)sample->uptime_ms,
	       queue_depth, produced, consumed, dropped);
	k_mutex_unlock(&console_mutex);
}

static void print_sensor_error(int ret)
{
	k_mutex_lock(&console_mutex, K_FOREVER);
	printk("[sensor_thread] failed to read onboard P3T1755DP sensor (err=%d)\n", ret);
	k_mutex_unlock(&console_mutex);
}

void sensor_thread(void *arg1, void *arg2, void *arg3)
{
	ARG_UNUSED(arg1);
	ARG_UNUSED(arg2);
	ARG_UNUSED(arg3);

	uint32_t sequence = 1U;

	while (1) {
		struct sensor_value temperature_value;
		struct sensor_sample sample = {
			.sequence = sequence,
			.uptime_ms = k_uptime_get(),
		};
		uint32_t produced;
		uint32_t dropped;
		uint32_t queue_depth;
		int ret;

		ret = sensor_sample_fetch(temp_sensor);
		if (ret == 0) {
			ret = sensor_channel_get(temp_sensor, SENSOR_CHAN_AMBIENT_TEMP,
						 &temperature_value);
		}

		if (ret != 0) {
			print_sensor_error(ret);
			k_msleep(PRODUCER_PERIOD_MS);
			continue;
		}

		sample.temperature_milli_c = sensor_value_to_milli_c(&temperature_value);

		if (k_msgq_put(&sensor_msgq, &sample, K_NO_WAIT) == 0) {
			k_mutex_lock(&console_mutex, K_FOREVER);
			stats.produced++;
			stats.last_temperature_milli_c = sample.temperature_milli_c;
			produced = stats.produced;
			dropped = stats.dropped;
			k_mutex_unlock(&console_mutex);
			queue_depth = k_msgq_num_used_get(&sensor_msgq);
			print_producer_status(&sample, queue_depth, produced, dropped);
			k_sem_give(&sample_ready_sem);
		} else {
			k_mutex_lock(&console_mutex, K_FOREVER);
			stats.dropped++;
			dropped = stats.dropped;
			k_mutex_unlock(&console_mutex);
			print_queue_full(&sample, dropped);
		}

		sequence++;
		k_msleep(PRODUCER_PERIOD_MS);
	}
}

void queue_thread(void *arg1, void *arg2, void *arg3)
{
	ARG_UNUSED(arg1);
	ARG_UNUSED(arg2);
	ARG_UNUSED(arg3);

	while (1) {
		struct sensor_sample sample;
		bool overwrote_oldest;
		uint32_t produced;
		uint32_t consumed;
		uint32_t dropped;
		uint32_t queue_depth;

		k_sem_take(&sample_ready_sem, K_FOREVER);

		if (k_msgq_get(&sensor_msgq, &sample, K_NO_WAIT) != 0) {
			k_mutex_lock(&console_mutex, K_FOREVER);
			printk("[queue_thread ] semaphore signaled but queue was empty\n");
			k_mutex_unlock(&console_mutex);
			continue;
		}

		k_mutex_lock(&console_mutex, K_FOREVER);
		stats.consumed++;
		produced = stats.produced;
		consumed = stats.consumed;
		dropped = stats.dropped;
		k_mutex_unlock(&console_mutex);
		queue_depth = k_msgq_num_used_get(&sensor_msgq);
		print_consumer_status(&sample, queue_depth, produced, consumed, dropped);

		overwrote_oldest = circular_buffer_push(&fft_buffer, &sample);
		if (overwrote_oldest) {
			k_mutex_lock(&console_mutex, K_FOREVER);
			stats.buffer_overwrites++;
			k_mutex_unlock(&console_mutex);
		}

		if (fft_buffer.count == CIRCULAR_BUFFER_LENGTH) {
			run_fft_and_print(overwrote_oldest);
		}

		k_msleep(CONSUMER_PERIOD_MS);
	}
}

int main(void)
{
	arm_status fft_status;

	if (!device_is_ready(temp_sensor)) {
		k_mutex_lock(&console_mutex, K_FOREVER);
		printk("Onboard P3T1755DP sensor is not ready\n");
		k_mutex_unlock(&console_mutex);
		return -ENODEV;
	}

	fft_status = arm_rfft_fast_init_f32(&fft_instance, FFT_SIZE);
	if (fft_status != ARM_MATH_SUCCESS) {
		k_mutex_lock(&console_mutex, K_FOREVER);
		printk("CMSIS-DSP FFT init failed (status=%d)\n", fft_status);
		k_mutex_unlock(&console_mutex);
		return -EINVAL;
	}

	k_mutex_lock(&console_mutex, K_FOREVER);
	printk("Starting Zephyr internals demo on FRDM-MCXN947\n");
	printk("Thread 1: onboard P3T1755DP producer over I3C, Thread 2: queue consumer\n");
	printk("Kernel objects: thread, semaphore, mutex, message queue, circular buffer\n");
	printk("FFT: %u-sample circular window processed with CMSIS-DSP\n",
	       CIRCULAR_BUFFER_LENGTH);
	k_mutex_unlock(&console_mutex);

	k_thread_create(&producer_thread_data, producer_stack,
			K_THREAD_STACK_SIZEOF(producer_stack), sensor_thread,
			NULL, NULL, NULL, PRODUCER_PRIORITY, 0, K_NO_WAIT);

	k_thread_create(&consumer_thread_data, consumer_stack,
			K_THREAD_STACK_SIZEOF(consumer_stack), queue_thread,
			NULL, NULL, NULL, CONSUMER_PRIORITY, 0, K_NO_WAIT);

	while (1) {
		k_sleep(K_SECONDS(5));
	}

	return 0;
}
