#ifndef LCD_H_
#define LCD_H_
#define F_CPU (16000000UL)
#include <util/delay.h>
#include "BIT_MATH.h"
#include "ATmega32_Rrgiosters.h"

#define LCD_Data_Port			PORTB			//Define LCD data port
#define LCD_Data_Dir			DDRB			//Define LCD data port direction
#define LCD_Command_Port		PORTA			//Define LCD command port
#define LCD_Command_Dir			DDRA			//Define LCD command port direction
#define RS						PA3			//Define Register Select (data/command)
#define EN						PA2			//Define Enable signal pin

void LCD_Init(void);
void LCD_Command(unsigned char cmd);
void LCD_Char(unsigned char char_data);
void LCD_String(char *str);
void LCD_clear(void);
void LCD_goToRowColumn(unsigned char row,unsigned char col);
void LCD_Clear(void);

#endif		/* LCD_H_ */