#include "circular_buffer.h"

void circular_buffer_init(circular_buffer *cb)
{
    cb->head = 0;
    cb->tail = 0;
}

bool circular_buffer_push(circular_buffer *cb, uint8_t data_element)
{
    if (((cb->head + 1) & CIRCULAR_MASK) == cb->tail) {
        return false;
    }

    cb->buffer[cb->head] = data_element;
    cb->head = (cb->head + 1) & CIRCULAR_MASK;

    return true;
}

bool circular_buffer_pop(circular_buffer *cb, uint8_t *data_element)
{
    if ((cb->head == cb->tail) || (data_element == NULL)) {
        return false;
    }

    *data_element = cb->buffer[cb->tail];
    cb->tail = (cb->tail + 1) & CIRCULAR_MASK;

    return true;
}

