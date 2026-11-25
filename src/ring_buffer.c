#include "../include/ring_buffer.h"

void ring_buffer_init(ring_buffer_t *buffer) {
  buffer->head = 0;
  buffer->tail = 0;
}

bool ring_buffer_is_empty(const ring_buffer_t *buffer) {
  return buffer->head == buffer->tail;
}

bool ring_buffer_is_full(const ring_buffer_t *buffer) {
  return (uint8_t)(buffer->head + 1U) == buffer->tail;
}

bool ring_buffer_push(ring_buffer_t *buffer, uint8_t value) {
  uint8_t next_head = (uint8_t)(buffer->head + 1U);

  if (next_head == buffer->tail) {
    /* The buffer is full. Keep the oldest data and drop the new value. */
    return false;
  }

  buffer->data[buffer->head] = value;
  buffer->head = next_head;
  return true;
}

bool ring_buffer_pop(ring_buffer_t *buffer, uint8_t *value) {
  if (buffer->head == buffer->tail) {
    return false;
  }

  *value = buffer->data[buffer->tail];
  buffer->tail = (uint8_t)(buffer->tail + 1U);
  return true;
}
