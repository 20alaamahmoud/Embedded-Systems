/*
 * LED.h
 *
 * Created: 5/6/2023 2:38:23 PM
 *  Author: hp
 */ 


#ifndef LED_H_
#define LED_H_


#define F_CPU (16000000UL)
// Define the pins for each LED
#define LED_1_PIN PB7
#define LED_2_PIN PA6
#define LED_3_PIN PA5
#define LED_4_PIN PA4


// Define the LED identifiers
typedef enum {
	LED_1,
	LED_2,
	LED_3,
	LED_4
} led_t;

// Initialize the LED pins
void led_init(void)
{
	 SET_BIT(DDRB,PB7);
	 SET_BIT(DDRA,PA6);
	 SET_BIT(DDRA,PA5);
	 SET_BIT(DDRA,PA4);
}


void toggle_led(led_t led)
{
	TOGGLE_BIT(PORTB,PB7);
	_delay_ms(500);
	CLR_BIT(PORTB,PB7);
	TOGGLE_BIT(PORTA,PA6);
	_delay_ms(500);
	CLR_BIT(PORTA,PA6);
	TOGGLE_BIT(PORTA,PA5);
	_delay_ms(500);
	CLR_BIT(PORTA,PA5);
	TOGGLE_BIT(PORTA,PA4);
	_delay_ms(500);
	CLR_BIT(PORTA,PA4);
}
// Turn on all LEDs
void led_on_all(void)
{
	 PORTB |= (1 << PB7);
	 PORTA |= (1 << PA6) | (1 << PA5) | (1 << PA4);
}

// Turn off all LEDs
void led_off_all(void)
{
	PORTB &= ~(1 << PB7);
	PORTA &= ~(1 << PA6) & ~(1 << PA5) & ~(1 << PA4);
}

// Flash all LEDs five times
void flash_leds(void)
{
	for (int i = 0; i < 5; i++)
	{
		led_on_all();
		_delay_ms(5000);
		led_off_all();
		_delay_ms(5000);
	}
}

#endif /* LED_H_ */