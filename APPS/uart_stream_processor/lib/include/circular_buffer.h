#ifndef CIRCULAR_BUFFER_H
#define CIRCULAR_BUFFER_H

#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

#define CIRCULAR_BUFFER_SIZE 16U
#define CIRCULAR_MASK (CIRCULAR_BUFFER_SIZE - 1U)

/**
 * @brief Fixed-size circular buffer for byte-oriented data.
 *
 * The buffer stores UART or other byte-stream data using a power-of-two
 * capacity and head/tail indices for efficient wraparound.
 */
typedef struct circular_buffer
{
    uint8_t buffer[CIRCULAR_BUFFER_SIZE];
    uint8_t head;
    uint8_t tail;
}circular_buffer;

/**
 * @brief Initialize a circular buffer instance.
 *
 * Resets the head and tail indices so the buffer starts empty.
 *
 * @param cb Pointer to the circular buffer instance to initialize.
 */
void circular_buffer_init(circular_buffer *cb);

/**
 * @brief Push one byte into the circular buffer.
 *
 * Stores a byte at the current head position and advances the head index.
 * The operation fails if the buffer is full.
 *
 * @param cb Pointer to the circular buffer instance.
 * @param data_element Byte value to store in the buffer.
 *
 * @retval true The byte was stored successfully.
 * @retval false The buffer is full and the byte was not stored.
 */
bool circular_buffer_push(circular_buffer *cb, uint8_t data_element);

/**
 * @brief Pop one byte from the circular buffer.
 *
 * Reads a byte from the current tail position and advances the tail index.
 * The operation fails if the buffer is empty or if @p data_element is NULL.
 *
 * @param cb Pointer to the circular buffer instance.
 * @param data_element Pointer to the output byte.
 *
 * @retval true A byte was read successfully.
 * @retval false The buffer is empty or the output pointer is invalid.
 */
bool circular_buffer_pop(circular_buffer *cb, uint8_t *data_element);

#endif /* CIRCULAR_BUFFER_H */