#ifndef uart_h
#define uart_h
#include <stdint.h>
#include <avr/io.h>

int uart_init(void);
void uart_putByte(uint8_t b);
void uart_putStream(const uint8_t *buf, uint16_t len);

#endif
