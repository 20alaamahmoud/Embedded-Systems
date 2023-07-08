/*
 * GccApplication3.c
 *
 * Created: 4/14/2023 3:26:37 PM
 * Author : hp
 */ 

#include "LED_DRIVER.h"
#include "PUSH_BUTTON.h"
#include <avr/io.h>
#include "std_types.h"


int main(void)
{
    /* Replace with your application code */
	
	// Initialize the LED pins
	led_config_t led_1 = {
		.ddr = &DDRB,
		.port = &PORTB,
		.pin = 7
	};
	
	led_config_t led_2= {
		.ddr = &DDRA,
		.port = &PORTA,
		.pin = 6
	};
	led_config_t led_3 = {
		.ddr = &DDRA,
		.port = &PORTA,
		.pin = 5
	};
	led_config_t led_4 = {
		.ddr = &DDRA,
		.port = &PORTA,
		.pin = 4
	};
	led_init(&led_1);
	led_init(&led_2);
	led_init(&led_3);
	led_init(&led_4);

	// Create push button objects
	push_button_t button_1 = {&DDRD, &PORTD, &PIND, PD3};
	push_button_t button_2 = {&DDRD, &PORTD, &PIND, PD5};
	push_button_t button_3 = {&DDRD, &PORTD, &PIND, PD6};
	push_button_t button_4 = {&DDRD, &PORTD, &PIND, PD7};

	// Initialize push buttons
	push_button_init(&button_1);
	push_button_init(&button_2);
	push_button_init(&button_3);
	push_button_init(&button_4);
	
    while (1) 
    {

		/*
		
		//IF we use LED Driver Only
		
		led_set_state(LED_ON, &led_1);			// Turn on LED 1
		led_set_state(LED_OFF, &led_2);			// Turn off LED 2
		led_set_state(LED_ON, &led_3);			// Turn on LED 3
		led_set_state(LED_OFF, &led_4);			// Turn off LED 4
		_delay_ms(1000);
								
		led_set_state(LED_OFF, &led_1);			// Turn off LED 1
		led_set_state(LED_ON, &led_2);			// Turn on LED 2
		led_set_state(LED_OFF, &led_3);			// Turn off LED 3
		led_set_state(LED_ON, &led_4);			// Turn on LED 4
		_delay_ms(1000);	
		
		*/	
		
		// Check which button is pressed and light corresponding LED
		if (push_button_is_pressed(&button_1))
		{
			led_set_state(LED_ON, &led_2);			// Turn on LED 2
		} 
		else 
		{
			led_set_state(LED_OFF, &led_2);			// Turn off LED 2
		}

		if (push_button_is_pressed(&button_2)) 
		{
			led_set_state(LED_ON, &led_3);			// Turn on LED 3
		} 
		else 
		{
			led_set_state(LED_OFF, &led_3);			// Turn off LED 3
		}

		if (push_button_is_pressed(&button_3))
		{
			led_set_state(LED_ON, &led_4);			// Turn on LED 4
		} 
		else 
		{
			led_set_state(LED_OFF, &led_4);			// Turn off LED 4
		}

		if (push_button_is_pressed(&button_4))
		{
			led_set_state(LED_ON, &led_1);			// Turn on LED 1
		}
		else 
		{
			led_set_state(LED_OFF, &led_1);			// Turn off LED 1
		}
	}
    return 0;
}

