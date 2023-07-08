#ifndef PUSH_BUTTON_H_
#define PUSH_BUTTON_H_

#include <stdint.h>
#define F_CPU (16000000UL)
#include <util/delay.h>
#include "std_types.h"
#include "LED_DRIVER.h"

typedef struct {
	volatile uint8_t *ddr_reg;
	volatile uint8_t *port_reg;
	volatile uint8_t *pin_reg;
	uint8_t pin_num;
	led_config_t *led_config;
} push_button_t;

void push_button_init(push_button_t *button);
uint8_t push_button_is_pressed(push_button_t *button);

#endif /* PUSH_BUTTON_H_ */