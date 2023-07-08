/*
 * GccApplication4.c
 *
 * Created: 5/6/2023 1:09:58 PM
 * Author : hp
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#define F_CPU (16000000UL)
#include <util/delay.h>
#include "EXT_INT1.h"
#include "BIT_MATH.h"
#include "std_types.h"
#include "LED.h"


int main(void)
{
	INT1_Init();				// Enable external INT1
	
	//sei();						// Enable the global interrupts
	INT1_setCallBack(&flash_leds);
	
	led_init();
	

	while (1)
	{
		for (int i = 0; i < 5; i++)
		{
			toggle_led(LED_1);
			toggle_led(LED_2);
			toggle_led(LED_3);
			toggle_led(LED_4);
		}
	}
	return 0;
}
