/*
 * EXT_INT1.h
 *
 * Created: 5/1/2023 10:02:34 AM
 *  Author: hp
 */ 


#ifndef EXT_INT1_H_
#define EXT_INT1_H_
#define F_CPU (16000000UL)
#include <util/delay.h>

void INT1_Init(void);
void INT1_setCallBack(void(*a_ptr)(void));


#endif /* EXT_INT1_H_ */