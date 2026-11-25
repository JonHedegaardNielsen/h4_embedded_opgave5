#include "../include/uart.h"
#include "../include/ProjectDefines.h"
#include "../include/ring_buffer.h"

#include <avr/interrupt.h>
#include <avr/io.h>

static ring_buffer_t rx_buffer;

static uint16_t uart_ubrr(uint32_t baud) {
  return (uint16_t)((F_CPU / (16UL * baud)) - 1UL);
}

void uart_init(uart_id_t uart, uint32_t baud) {
  uint16_t ubrr = uart_ubrr(baud);

  if (uart == UART_USART0) {
    UBRR0H = (uint8_t)(ubrr >> 8);
    UBRR0L = (uint8_t)ubrr;

    UCSR0A = 0;
    UCSR0B = (1 << TXEN0) | (1 << RXEN0);
    UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);
  } else {
    UBRR1H = (uint8_t)(ubrr >> 8);
    UBRR1L = (uint8_t)ubrr;

    UCSR1A = 0;
    UCSR1B = (1 << TXEN1) | (1 << RXEN1);
    UCSR1C = (1 << UCSZ11) | (1 << UCSZ10);
  }
}

void uart_putchar(uart_id_t uart, uint8_t value) {
  if (uart == UART_USART0) {
    while (!(UCSR0A & (1 << UDRE0))) {
    }
    UDR0 = value;
  } else {
    while (!(UCSR1A & (1 << UDRE1))) {
    }
    UDR1 = value;
  }
}

void uart_puts(uart_id_t uart, const char *text) {
  while (*text != '\0') {
    uart_putchar(uart, (uint8_t)*text);
    text++;
  }
}

uint8_t uart_getchar(uart_id_t uart) {
  if (uart == UART_USART0) {
    while (!(UCSR0A & (1 << RXC0))) {
    }
    return UDR0;
  }

  while (!(UCSR1A & (1 << RXC1))) {
  }
  return UDR1;
}

bool uart_tx_ready(uart_id_t uart) {
  if (uart == UART_USART0) {
    return (UCSR0A & (1 << UDRE0)) != 0;
  }
  return (UCSR1A & (1 << UDRE1)) != 0;
}

bool uart_rx_ready(uart_id_t uart) {
  if (uart == UART_USART0) {
    return (UCSR0A & (1 << RXC0)) != 0;
  }
  return (UCSR1A & (1 << RXC1)) != 0;
}

void uart_enable_rx_interrupt(uart_id_t uart) {
  ring_buffer_init(&rx_buffer);

  if (uart == UART_USART0) {
    UCSR0B |= (1 << RXCIE0);
  } else {
    UCSR1B |= (1 << RXCIE1);
  }

  sei();
}

void uart_disable_rx_interrupt(uart_id_t uart) {
  if (uart == UART_USART0) {
    UCSR0B &= (uint8_t)~(1 << RXCIE0);
  } else {
    UCSR1B &= (uint8_t)~(1 << RXCIE1);
  }
}

bool uart_ring_buffer_pop(uint8_t *value) {
  return ring_buffer_pop(&rx_buffer, value);
}

/* Only the RX interrupt for the selected UART is enabled by the application.
 * Keeping both ISRs means the selected UART can be changed in ProjectDefines.h
 * without changing this file. */
ISR(USART0_RX_vect) {
  uint8_t value = UDR0;
  (void)ring_buffer_push(&rx_buffer, value);
}

ISR(USART1_RX_vect) {
  uint8_t value = UDR1;
  (void)ring_buffer_push(&rx_buffer, value);
}
