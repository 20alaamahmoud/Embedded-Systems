/*
 * assignmentLab4.c
 *
 * Created: 3/25/2023 9:37:11 PM
 *  Author: Alaa
 */ 
#define F_CPU (16000000UL)
#include <util/delay.h>
#include "BIT_MATH.h"
#include "ATmega32_Rrgiosters.h"
#include <avr/io.h>


void SEVEN_SEG_voidInit(void)
{
	SET_BIT(DDRA,3);	CLR_BIT(PORTA,3);
	DDRB |= 0b0010111;
}
void SEVEN_SEG_voidDisplay(int number)
{
	PORTB &= 0b11101000;
	PORTB |= (((number%10 & 0b00001000) <<1) |(number%10 & 0b00000111));
}
void push_button_increase(void)
{
	CLR_BIT(DDRD,7);
	SET_BIT(PORTD,7);
	
}
void push_button_decrease(void)
{
	CLR_BIT(DDRD,6);
	SET_BIT(PORTD,6);
	
}
int main(void)
{
	//int count1=0;
	//int count2=0;
	int count=0;
	push_button_increase();
	push_button_decrease();
	SEVEN_SEG_voidInit();
	
	while(1)
	{
		if (GET_BIT(PIND,PIN7) == 0)
		{
			_delay_ms(150);
			if (GET_BIT(PIND,PIN7) == 0)
			{
				//count1++;
				count++;
				
				SEVEN_SEG_voidDisplay(count%10);
				
				
				if(count==10)
				{
					break;
				}
			}
		}
		if (GET_BIT(PIND,PIN6) == 0)
		{
			_delay_ms(150);
			if (GET_BIT(PIND,PIN6) == 0)
			{
				count--;
				SEVEN_SEG_voidDisplay(count%10);
				if(count==0)
				{
					break;
				}
			}
		}
	}
}


