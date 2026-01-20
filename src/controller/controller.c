#include "controller.h"
#include "../driver/pwm/timer0.h"
#include "../driver/trigger/timer1.h"
#include "../driver/adc/adc.h"
#include "../driver/mapping/mapping.h"

int controller_init(void)
{
	if(timer0_init() || adc_init() ||  timer1_init()) 
	{
		return 1;
	} else {
		sei();
		return 0;
	}
}

ISR(TIMER1_COMPA_vect)
{
    // Start ADC Conversion
    adc_start();
}

ISR(ADC_vect)
{
    // Map Latest ADC Value and update duty cycle 
    set_duty(adc_map(ADC));

}
