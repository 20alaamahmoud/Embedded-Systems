#define F_CPU (16000000UL)
#include <util/delay.h>
#include "ATmega32_Rrgiosters.h"
#include "BIT_MATH.h"
#include "lcd.h"
#include <avr/io.h>


#define SET_CURSOR_LOCATION (0x80)

void LCD_Init(void)						/* LCD Initialization function */
{
	LCD_Data_Dir |= 0b00010111;			/* Set PB0, PB1, PB2, and PB4 as OUTPUT */
	LCD_Command_Dir |= (1 << RS) | (1 << EN);	/* Set RS, EN as OUTPUT */
	
	_delay_ms(15);				/* LCD Power ON delay always > 15ms */
	LCD_Command(0x02);			/* initialize LCD in 4-bit mode */
	LCD_Command(0x28);			/* initialize the LCD in 4-bit mode, 2 lines, and 5*8 format */
	LCD_Command(0x0C);			/* Display ON, Cursor OFF */
	LCD_Command(0x06);			/* Shift cursor from left to right on read/write */
	LCD_Command(0x01);			/* Clear Display */
	LCD_Command(0x80);			/* Cursor at home position */
}

void LCD_Command(unsigned char cmd)
{
	PORTB &= 0b11101000;		/* Clear the 4 bits of the data bus */
	PORTB |= (((((cmd&0xF0) >> 4) & 0b00001000) << 1 ) | (((cmd&0xF0) >> 4) & 0b00000111));	/* Send the lowest 4 bits of cmd to the data bus */
	CLR_BIT (LCD_Command_Port, RS);		/* RS = 0 command reg. */
	SET_BIT (LCD_Command_Port, EN);		/* Enable pulse */
	_delay_us(1);						/* more than 450 ns */
	CLR_BIT (LCD_Command_Port, EN);		/* Display pulse */
	_delay_ms(2);						/* wait for the longest command */
	
	PORTB &= 0b11101000;		/* Clear the 4 bits of the data bus */
	PORTB |= ((((cmd&0x0F) & 0b00001000) << 1 ) | ((cmd&0x0F) & 0b00000111));	/* Send the lowest 4 bits of cmd to the data bus */
	SET_BIT (LCD_Command_Port, EN);		/* Enable pulse */
	_delay_us(1);						/* more than 450 ns */
	CLR_BIT (LCD_Command_Port, EN);		/* Display pulse */
	_delay_ms(2);						/* wait for the longest command */
}

void LCD_Char(unsigned char char_data)
{
	PORTB &= 0b11101000;		/* Clear the 4 bits of the data bus */
	PORTB |= (((((char_data&0xF0) >> 4) & 0b00001000) << 1 ) | (((char_data&0xF0) >> 4) & 0b00000111));	/* Send the highest 4 bits of data to the data bus */
	SET_BIT (LCD_Command_Port, RS);		/* RS = 1 data reg. */
	SET_BIT (LCD_Command_Port, EN);		/* Enable pulse */
	_delay_us(1);						/* more than 450 ns */
	CLR_BIT (LCD_Command_Port, EN);		/* Display pulse */
	_delay_us(100);						/* more than 43us for data writing */
	
	PORTB &= 0b11101000;
	PORTB |= ((((char_data&0x0F) & 0b00001000) << 1 ) | ((char_data&0x0F) & 0b00000111));	/* Send the lowest 4 bits of data to the data bus */
	SET_BIT (LCD_Command_Port, EN);		/* Enable pulse */
	_delay_us(1);						/* more than 450 ns */
	CLR_BIT (LCD_Command_Port, EN);		/* Display pulse */
	_delay_us(100);						/* more than 43us for data writing */
}

void LCD_String(char *str)
{
	int i;
	for (i=0; str[i]!=0; i++)	/* send each char of string till NULL */
	{
		LCD_Char(str[i]);		/* call LCD data write */
	}
}

void LCD_goToRowColumn(unsigned char row,unsigned char col)
{
	unsigned char Address = 0;
	
	/* first of all calculate the required address */
	
	switch(row)
	{
		case 0:
		Address=col;
		break;
		case 1:
		Address=col+0x40;
		break;
		case 2:
		Address=col+0x14;
		break;
		case 3:
		Address=col+0x54;
		break;
	}
	/* to write to a specific address in the LCD */
	/* we need to apply the corresponding command 0b10000000+Address */
	LCD_Command(Address | SET_CURSOR_LOCATION);
}

void LCD_Clear(void)
{
	LCD_Command(0x01);
}