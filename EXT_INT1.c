/*
 * EXT_INT1.c
 *
 * Created: 5/1/2023 10:03:26 AM
 *  Author: hp
 */ 

#include "EXT_INT1.h"
#include <avr/interrupt.h>
#include "BIT_MATH.h"
#include "std_types.h"

#define I_BIT (7)		/*The I-bit in the SREG register */


/* Global variable to hold the address of the callback function in the application */
void (*g_callBackPtr)(void) = NULL_PTR;

/*External INT1 Interrupt Service Routine */
ISR(INT1_vect)
{
	
	if(g_callBackPtr != NULL_PTR)
	{
		(*g_callBackPtr)();
	}

}


/* External INT1 enable and configuration function */
void INT1_Init(void)
{
	CLR_BIT(SREG, I_BIT);		
	CLR_BIT(DDRD, PD3);
	SET_BIT(PORTD, PD3);
	SET_BIT(GICR, INT1);
	SET_BIT(MCUCR, ISC11);
	CLR_BIT(MCUCR, ISC10);
	SET_BIT(SREG, I_BIT);
}

/* Set the callback function address */


void INT1_setCallBack(void(*a_ptr)(void))
{
	g_callBackPtr = a_ptr;
}
