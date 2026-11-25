#ifndef PROJECT_DEFINES_H
#define PROJECT_DEFINES_H

/* CPU clock used by the UART baud-rate calculation. */
#define F_CPU 16000000UL

/* Baud rate used on both UARTs. */
#define BAUD 9600UL

/* Username sent when the ':' start character is received.
 * Jon's username from the assignment table is "Betjenten". */
#define USERNAME "Betjenten"

/* Select which USART receives the incoming characters.
 *   0 = USART0 (the CP2102 connection)
 *   1 = USART1
 * The other USART is used for transmitting the username and echoing data.
 */
#define RX_UART 0
#define TX_UART 1

#if (RX_UART != 0 && RX_UART != 1) || (TX_UART != 0 && TX_UART != 1)
#error "RX_UART and TX_UART must be 0 (USART0) or 1 (USART1)"
#endif

#if RX_UART == TX_UART
#error "RX_UART and TX_UART must use different USARTs"
#endif

#endif
