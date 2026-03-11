#include "uart.h"
#define Baud_register_Value ((F_CPU / (16 * Baud_Rate)))
int uart_init(void)

{
	DDRD |= (1 << PD1); // pin configuration  
	UCSR0B |= (1 << TXEN0); // Transmit

	UCSR0C |= ( 1 << UCSZ01) | ( 1 << UCSZ00); // Gives 8-N-1 configuration
	
	UBBRO = Baud_register_Value;

	return 0;

}

void uart_putByte(uint8_t b)
{
	while ((UCSR0A & (1 << UDRE0) == 0);	//Wait for the data register to be empty
	UDR0 = b;				//Transmit the character passed to the function
}

void uart_putStream(const uint8_t *buf, uint16_t len)
{
	for(uint8_t Index = 0; Index < len; Index++)
	{
		uart_putByte(buf[Index]);
	}
}
		

