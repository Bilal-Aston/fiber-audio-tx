#include "uart.h"

#define Baud_register_Value ((F_CPU / (16 * Baud_Rate)) - 1)
#define Baue_Rate 115200UL
#define F_CPU 20E6

int uart_init(void)

{
	TXD0 |= (1 << PD1); // pin configuration  
	UCSR0A |= (1 << U2X0); // Driver at normal speed
	UCSR0B |= (1 << TXEN0); // Transmit

	UCSR0C |= ( 1 << UCSZ01) | ( 1 << UCSZ00); // Gives 8-N-1 configuration
	
	UBBRO = Baud_register_Value;

	return = 0;

}

void uart_putByte(uint8_t b)
{
	UCSR0A |= (1 << UDRE0);
}

void uart_putStream(const uint8_t *buf, uint16_t len)
{
	char buf[len-1];
	int uart_putStream;

	while ((uart_putByte = read(0, buf, len-1)) > 0)
	    write(1, buf, n);
	    return 0;	
}
		

