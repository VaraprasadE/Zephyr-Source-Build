/*
 * Copyright (c) 2022 Libre Solar Technologies GmbH
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/drivers/uart.h>

#include "circular_buffer.h"

/* change this to any other UART peripheral if desired */
#define UART_DEVICE_NODE DT_CHOSEN(zephyr_shell_uart)

#define FRAME_START_BYTE 'S'
#define FRAME_END_BYTE 'E'
#define FRAME_DATA_LENGTH 12U
#define FRAME_LENGTH (FRAME_DATA_LENGTH + 2U)

K_SEM_DEFINE(uart_data_ready, 0, CIRCULAR_BUFFER_SIZE);

static const struct device *const uart_dev = DEVICE_DT_GET(UART_DEVICE_NODE);
static circular_buffer uart_rx_buffer;
static uint8_t frame_buffer[FRAME_LENGTH];
static size_t frame_pos;
static bool frame_started;
static uint32_t dropped_bytes;

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
		print_frame(frame_buffer);
	} else {
		print_uart("Invalid frame: missing end byte\r\n");
	}

	reset_frame_state();
}

int main(void)
{
	uint8_t received_byte;

	if (!device_is_ready(uart_dev)) {
		printk("UART device not found!");
		return 0;
	}

	circular_buffer_init(&uart_rx_buffer);
	reset_frame_state();

	/* configure interrupt and callback to receive data */
	int ret = uart_irq_callback_user_data_set(uart_dev, serial_cb, NULL);

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

	return 0;
}
