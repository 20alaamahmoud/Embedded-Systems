#ifndef KEYPAD_H_
#define KEYPAD_H_

#define F_CPU (16000000UL)

#include <util/delay.h>

#include "BIT_MATH.h"
#include "ATmega32_Rrgiosters.h"


#define INVALID_KEYPAD_PRESS (0xFF)



void keypad_init();

unsigned char keypad_get_value();

#endif		/*KEYPAD_H_*/