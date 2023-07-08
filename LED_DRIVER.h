#ifndef LED_DRIVER_H
#define LED_DRIVER_H

//#include <stdint.h>
#define F_CPU (16000000UL)
#include <util/delay.h>
#include "std_types.h"



typedef enum
{
	LED_OFF = 0,
	LED_ON = 1
} led_state_t;

typedef struct
{
	volatile uint8_t* ddr;
	volatile uint8_t* port;
	volatile uint8_t pin;
} led_config_t;

void led_init(led_config_t* config);
void led_set_state(led_state_t state, led_config_t* config);

#endif /* LED_DRIVER_H */