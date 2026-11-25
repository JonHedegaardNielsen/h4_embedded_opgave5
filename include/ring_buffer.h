#ifndef RING_BUFFER_H
#define RING_BUFFER_H

#include <stdbool.h>
#include <stdint.h>

/* The buffer size must be 256 because the head and tail indices are 8-bit.
 * This makes every index access atomic on AVR, so the UART interrupt and the
 * main loop can access the buffer without disabling interrupts. */
#define RING_BUFFER_SIZE 256U

#if RING_BUFFER_SIZE != 256U
#error "RING_BUFFER_SIZE must be 256 for the 8-bit index wrap-around"
#endif

typedef struct {
  uint8_t data[RING_BUFFER_SIZE];
  volatile uint8_t head; /* Written by the producer (UART RX interrupt). */
  volatile uint8_t tail; /* Written by the consumer (main loop). */
} ring_buffer_t;

void ring_buffer_init(ring_buffer_t *buffer);
bool ring_buffer_push(ring_buffer_t *buffer, uint8_t value);
bool ring_buffer_pop(ring_buffer_t *buffer, uint8_t *value);
bool ring_buffer_is_empty(const ring_buffer_t *buffer);
bool ring_buffer_is_full(const ring_buffer_t *buffer);

#endif
