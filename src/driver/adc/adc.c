#include "adc.h"

int adc_init(void)
{

ADMUX = 1<<REFS0 | 1<<MUX2 | 1<<MUX1 | 1<<MUX0;

ADCSRA = 1<<ADEN | 1<<ADIE | 1<<ADPS2 | 1<<ADPS0;

DIDR0 = 0xFF;





}

void adc_start(void)
{
 ADCSRA |= 1<<ADSC;
}


