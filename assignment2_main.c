/*
 * GccApplication2.c
 *
 * Created: 4/11/2023 9:05:22 AM
 * Author : hp
 */ 

#include "ATmega32_Rrgiosters.h"
#include "BIT_MATH.h"
#include <stdio.h>
#include "lcd.h"
#include "keypad.h"
#include <stdbool.h>
#include <stdlib.h>
// #define F_CPU (16000000UL)
// #include <util/delay.h>
int main(void)
{
	LCD_Init();
	keypad_init();
	LCD_String("Calculator");
	LCD_String("					");
	LCD_String("					");
	unsigned char a=0,b=0,op=0,value;
	unsigned char result=0;
	bool s=true;
	while (1)
	{
		value=keypad_get_value();
		if (value)
		{
			if (value==67) //button on/c to clear Display
			{
				LCD_Clear();
			}
			else if (value==61 && op) //button = to show result
			{
				switch (op)
				{
					case '+' :
					result= (a-48) + (b-48);
					break;
					case '*':
					result= (a-48) * (b-48);
					break;
					case '-':
					result= (a-48) - (b-48);
					break;
					case '/':
					result= (a-48)/(b-48);
					break;
				}
				LCD_Char(61);
				char str[10];
				sprintf(str, "%d", result);
				LCD_String(str);
				_delay_ms(500);
			}
			else if (value==42 || value == 43 || value ==45 || value==47 ) //column to select operation
			{
				if (value != INVALID_KEYPAD_PRESS)
				{
					op=value;
					LCD_Char(value);
					_delay_ms(250);
					s=false;
					continue;
				}
			}
			else if (value >= 48 && value <=57) //Read number from user
			{
				if (s)
				{
					a=value;
					if (a != INVALID_KEYPAD_PRESS)
					{
						LCD_Char(a);
						_delay_ms(250);
					}
				}
				else
				{
					b=value;
					if (b!= INVALID_KEYPAD_PRESS)
					{
						LCD_Char(b);
						_delay_ms(250);
					}
				}
				
			}
		}
	}
}

