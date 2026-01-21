#define F_CPU 20E6
#include "timer1.h"

#define Compare 499

int timer1_init(void)
{
	OCR1A = Compare;
	TCCR1B = 1<<WGM12 | 1<<CS10;
	TIMSK1 = 1<<OCIE1A;
	return 0;
}


