#ifndef UART_H
#define UART_H

#include <stdbool.h>
#include <stdint.h>

typedef enum {
  UART_USART0 = 0,
  UART_USART1 = 1,
} uart_id_t;

void uart_init(uart_id_t uart, uint32_t baud);

void uart_putchar(uart_id_t uart, uint8_t value);
void uart_puts(uart_id_t uart, const char *text);
uint8_t uart_getchar(uart_id_t uart);

bool uart_tx_ready(uart_id_t uart);
bool uart_rx_ready(uart_id_t uart);

/* Enables the RX interrupt for the selected UART. Received bytes are placed in
 * an internal ring buffer and can be read with uart_ring_buffer_pop(). */
void uart_enable_rx_interrupt(uart_id_t uart);
void uart_disable_rx_interrupt(uart_id_t uart);
bool uart_ring_buffer_pop(uint8_t *value);

#endif
