/**
 * @file main.c
 * @author jon
 * @date 2026-11-24
 * @brief UART handshake and ring-buffer echo application.
 *
 * The program waits for ':' on RX_UART. When received, the username is sent in
 * the format ":username:" on TX_UART. It then waits for ';' on RX_UART. When
 * ';' is received, the RX interrupt is enabled and every received byte is
 * echoed back on TX_UART using the ring buffer.
 */

#include "include/ProjectDefines.h"
#include "include/uart.h"

#include <stdint.h>

typedef enum {
  WAIT_FOR_START,      /* Wait for ':'. */
  WAIT_FOR_ACTIVATION, /* Username sent; wait for ';'. */
  RING_BUFFER_ACTIVE,  /* Echo received bytes from the ring buffer. */
} app_state_t;

#define RX_UART_ID ((uart_id_t)RX_UART)
#define TX_UART_ID ((uart_id_t)TX_UART)

int main(void) {
  uart_init(RX_UART_ID, BAUD);
  uart_init(TX_UART_ID, BAUD);

  app_state_t state = WAIT_FOR_START;

  for (;;) {
    switch (state) {
    case WAIT_FOR_START:
      if (uart_getchar(RX_UART_ID) == ':') {
        uart_putchar(TX_UART_ID, ':');
        uart_puts(TX_UART_ID, USERNAME);
        uart_putchar(TX_UART_ID, ':');
        state = WAIT_FOR_ACTIVATION;
      }
      break;

    case WAIT_FOR_ACTIVATION:
      if (uart_getchar(RX_UART_ID) == ';') {
        uart_enable_rx_interrupt(RX_UART_ID);
        state = RING_BUFFER_ACTIVE;
      }
      break;

    case RING_BUFFER_ACTIVE: {
      uint8_t value;
      while (uart_ring_buffer_pop(&value)) {
        uart_putchar(TX_UART_ID, value);
      }
      break;
    }
    }
  }

  return 0;
}
