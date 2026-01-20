#include "controller.h"
#include <avr/sleep.h>

int main(void)
{
	controller_init();
	set_sleep_mode(SLEEP_MODE_IDLE);

	while(1)
	{
	        sleep_mode();         
	}
}