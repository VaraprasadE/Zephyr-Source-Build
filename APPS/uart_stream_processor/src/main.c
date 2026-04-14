/*
 * Copyright (c) 2022 Libre Solar Technologies GmbH
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/drivers/uart.h>
#include <string.h>

#include "circular_buffer.h"
#include "static_memory_pool.h"

/* change this to any other UART peripheral if desired */
#define UART_DEVICE_NODE DT_CHOSEN(zephyr_shell_uart)

#define FRAME_START_BYTE 'S'
#define FRAME_END_BYTE 'E'
#define FRAME_DATA_LENGTH 12U
#define FRAME_LENGTH (FRAME_DATA_LENGTH + 2U)

#define PARSER_THREAD_STACK_SIZE 1024U
#define PROCESSING_THREAD_STACK_SIZE 1024U
#define PARSER_THREAD_PRIORITY 5
#define PROCESSING_THREAD_PRIORITY 5

BUILD_ASSERT(FRAME_LENGTH <= STATIC_MEMORY_POOL_DATA_SIZE,
	"FRAME_LENGTH must fit in static memory pool node data");

K_SEM_DEFINE(uart_data_ready, 0, CIRCULAR_BUFFER_SIZE);
K_MSGQ_DEFINE(frame_queue, sizeof(static_pool_node *), STATIC_MEMORY_POOL_CAPACITY, 4);

static const struct device *const uart_dev = DEVICE_DT_GET(UART_DEVICE_NODE);
static circular_buffer uart_rx_buffer;
static static_memory_pool frame_pool;
static uint8_t frame_buffer[FRAME_LENGTH];
static size_t frame_pos;
static bool frame_started;
static uint32_t dropped_bytes;
static uint32_t dropped_frames;
static uint32_t queue_failures;

K_THREAD_STACK_DEFINE(parser_thread_stack, PARSER_THREAD_STACK_SIZE);
K_THREAD_STACK_DEFINE(processing_thread_stack, PROCESSING_THREAD_STACK_SIZE);

static struct k_thread parser_thread_data;
static struct k_thread processing_thread_data;

/*
 * Read bytes from the UART FIFO and push them into the circular buffer.
 * The ISR stays short by deferring frame parsing to thread context.
 */
void serial_cb(const struct device *dev, void *user_data)
{
	uint8_t c;
	ARG_UNUSED(user_data);

	if (!uart_irq_update(dev)) {
		return;
	}

	if (!uart_irq_rx_ready(dev)) {
		return;
	}

	while (uart_fifo_read(dev, &c, 1) == 1) {
		if (circular_buffer_push(&uart_rx_buffer, c)) {
			k_sem_give(&uart_data_ready);
		} else {
			dropped_bytes++;
		}
	}
}

/*
 * Print a null-terminated string character by character to the UART interface
 */
void print_uart(const char *buf)
{
	while (*buf != '\0') {
		uart_poll_out(uart_dev, *buf++);
	}
}

static void print_frame(const uint8_t *frame)
{
	print_uart("Frame received: ");

	for (size_t i = 0; i < FRAME_LENGTH; i++) {
		uart_poll_out(uart_dev, frame[i]);
	}

	print_uart("\r\n");
}

static bool queue_completed_frame(void)
{
	static_pool_node *node;
	int ret;

	node = static_memory_pool_acquire(&frame_pool);
	if (node == NULL) {
		dropped_frames++;
		print_uart("Frame dropped: memory pool empty\r\n");
		return false;
	}

	memcpy(node->data, frame_buffer, FRAME_LENGTH);
	node->length = FRAME_LENGTH;

	ret = k_msgq_put(&frame_queue, &node, K_NO_WAIT);
	if (ret != 0) {
		queue_failures++;
		(void)static_memory_pool_release(&frame_pool, node);
		print_uart("Frame dropped: queue full\r\n");
		return false;
	}

	return true;
}

static void reset_frame_state(void)
{
	frame_pos = 0U;
	frame_started = false;
}

static void process_received_byte(uint8_t byte)
{
	if ((byte == '\r') || (byte == '\n')) {
		return;
	}

	if (!frame_started) {
		if (byte == FRAME_START_BYTE) {
			frame_started = true;
			frame_buffer[0] = byte;
			frame_pos = 1U;
		}

		return;
	}

	if (byte == FRAME_START_BYTE) {
		frame_buffer[0] = byte;
		frame_pos = 1U;
		print_uart("Resync on start byte\r\n");
		return;
	}

	frame_buffer[frame_pos++] = byte;

	if (frame_pos < FRAME_LENGTH) {
		return;
	}

	if (frame_buffer[FRAME_LENGTH - 1U] == FRAME_END_BYTE) {
		(void)queue_completed_frame();
	} else {
		print_uart("Invalid frame: missing end byte\r\n");
	}

	reset_frame_state();
}

static void parser_thread(void *arg1, void *arg2, void *arg3)
{
	uint8_t received_byte;

	ARG_UNUSED(arg1);
	ARG_UNUSED(arg2);
	ARG_UNUSED(arg3);

	while (1) {
		k_sem_take(&uart_data_ready, K_FOREVER);

		while (circular_buffer_pop(&uart_rx_buffer, &received_byte)) {
			process_received_byte(received_byte);
		}

		if (dropped_bytes > 0U) {
			print_uart("Warning: circular buffer overflow\r\n");
			dropped_bytes = 0U;
		}
	}
}

static void processing_thread(void *arg1, void *arg2, void *arg3)
{
	static_pool_node *node;
	int ret;

	ARG_UNUSED(arg1);
	ARG_UNUSED(arg2);
	ARG_UNUSED(arg3);

	while (1) {
		ret = k_msgq_get(&frame_queue, &node, K_FOREVER);
		if (ret != 0) {
			continue;
		}

		print_frame(node->data);

		if (!static_memory_pool_release(&frame_pool, node)) {
			print_uart("Error: failed to release node to pool\r\n");
		}
	}
}

int main(void)
{
	int ret;

	if (!device_is_ready(uart_dev)) {
		printk("UART device not found!");
		return 0;
	}

	circular_buffer_init(&uart_rx_buffer);
	static_memory_pool_init(&frame_pool);
	reset_frame_state();
	dropped_bytes = 0U;
	dropped_frames = 0U;
	queue_failures = 0U;

	k_thread_create(&parser_thread_data,
				parser_thread_stack,
				K_THREAD_STACK_SIZEOF(parser_thread_stack),
				parser_thread,
				NULL,
				NULL,
				NULL,
				PARSER_THREAD_PRIORITY,
				0,
				K_NO_WAIT);

	k_thread_create(&processing_thread_data,
				processing_thread_stack,
				K_THREAD_STACK_SIZEOF(processing_thread_stack),
				processing_thread,
				NULL,
				NULL,
				NULL,
				PROCESSING_THREAD_PRIORITY,
				0,
				K_NO_WAIT);

	/* configure interrupt and callback to receive data */
	ret = uart_irq_callback_user_data_set(uart_dev, serial_cb, NULL);

	if (ret < 0) {
		if (ret == -ENOTSUP) {
			printk("Interrupt-driven UART API support not enabled\n");
		} else if (ret == -ENOSYS) {
			printk("UART device does not support interrupt-driven API\n");
		} else {
			printk("Error setting UART callback: %d\n", ret);
		}
		return 0;
	}
	uart_irq_rx_enable(uart_dev);

	print_uart("UART frame parser ready\r\n");
	print_uart("Expected frame: S + 12 data bytes + E\r\n");
	print_uart("Parser task -> pool -> message queue -> processing task\r\n");

	while (1) {
		if (dropped_frames > 0U) {
			print_uart("Warning: frame dropped due to empty pool\r\n");
			dropped_frames = 0U;
		}

		if (queue_failures > 0U) {
			print_uart("Warning: frame queue overflow\r\n");
			queue_failures = 0U;
		}

		k_sleep(K_MSEC(250));
	}

	return 0;
}
