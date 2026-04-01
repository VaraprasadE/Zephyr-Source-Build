/*
 * Copyright (c) 2026
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <stdint.h>
#include <zephyr/device.h>
#include <zephyr/drivers/sensor.h>
#include <zephyr/kernel.h>
#include <zephyr/sys/printk.h>

#define PRODUCER_STACK_SIZE 1024
#define CONSUMER_STACK_SIZE 1024
#define PRODUCER_PRIORITY 5
#define CONSUMER_PRIORITY 5
#define PRODUCER_PERIOD_MS 1000
#define CONSUMER_PERIOD_MS 1300
#define SENSOR_QUEUE_LENGTH 6

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
	int32_t last_temperature_milli_c;
};

K_MSGQ_DEFINE(sensor_msgq, sizeof(struct sensor_sample), SENSOR_QUEUE_LENGTH, 4);
K_SEM_DEFINE(sample_ready_sem, 0, SENSOR_QUEUE_LENGTH);
K_MUTEX_DEFINE(console_mutex);

static struct demo_stats stats;
static const struct device *const temp_sensor = DEVICE_DT_GET(TEMP_SENSOR_NODE);
static struct k_thread producer_thread_data;
static struct k_thread consumer_thread_data;
K_THREAD_STACK_DEFINE(producer_stack, PRODUCER_STACK_SIZE);
K_THREAD_STACK_DEFINE(consumer_stack, CONSUMER_STACK_SIZE);

static int32_t sensor_value_to_milli_c(const struct sensor_value *value)
{
	return (int32_t)(((int64_t)value->val1 * 1000) + (value->val2 / 1000));
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

		k_msleep(CONSUMER_PERIOD_MS);
	}
}

int main(void)
{
	if (!device_is_ready(temp_sensor)) {
		k_mutex_lock(&console_mutex, K_FOREVER);
		printk("Onboard P3T1755DP sensor is not ready\n");
		k_mutex_unlock(&console_mutex);
		return -ENODEV;
	}

	k_mutex_lock(&console_mutex, K_FOREVER);
	printk("Starting Zephyr internals demo on FRDM-MCXN947\n");
	printk("Thread 1: onboard P3T1755DP producer over I3C, Thread 2: queue consumer\n");
	printk("Kernel objects: thread, semaphore, mutex, message queue\n");
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
