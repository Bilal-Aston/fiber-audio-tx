#include "timer1.h"

#define Compare 499

int timer1_init(void)
{
	//set top value
	OCR1A = Compare;

	//set ctc - top = ocr1a - no prescaler
	TCCR1B = 1<<WGM12 | 1<<CS10;

	//enable interrupt on compare match
	TIMSK1 |= 1<<OCIE1A;
	
	return 0;
}


