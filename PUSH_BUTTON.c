#include "PUSH_BUTTON.h"

#include <avr/io.h>

void push_button_init(push_button_t *button) {
	// Set button pin as input
	*button->ddr_reg &= ~(1 << button->pin_num);
	// Enable pull-up resistor on button pin
	*button->port_reg |= (1 << button->pin_num);
	// Initialize LED pin as output
	led_init(button->led_config);
}

uint8_t push_button_is_pressed(push_button_t *button) {
	// Return true if button is pressed (logic low)
	uint8_t is_pressed = !(*button->pin_reg & (1 << button->pin_num));
	// Set LED state based on button state
	if (is_pressed) {
		led_set_state(LED_ON, button->led_config);
		} else {
		led_set_state(LED_OFF, button->led_config);
	}
	return is_pressed;
}