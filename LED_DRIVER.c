#include "LED_DRIVER.h"
#include <avr/io.h>

void led_init(led_config_t* config)
{
	*(config->ddr) |= (1 << config->pin);
}

void led_set_state(led_state_t state, led_config_t* config)
{
	if (state == LED_ON)
	{
		*(config->port) |= (1 << config->pin);		// Turn ON the LED
	}
	else
	{
		*(config->port) &= ~(1 << config->pin);		// Turn OFF the LED
	}
}