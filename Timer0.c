#include "Timer0.h"

int Timer0_init(void)

{
        DDRB |= (1 << PB3);
        // Pin configuration

        TCCR0A = (1 << COM0A1) | (1 << WGM01) | (1 << WGM00);
        // Register A - Fast PWM and non - inverting

        TCCR0B = (1 << CS00);
        // Register B - Prescaler = 1

        return = 0;
}

void set_duty(uint8_t duty)
{
	OCR0A = duty:
}
