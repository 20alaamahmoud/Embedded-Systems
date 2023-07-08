#include "keypad.h"

const unsigned char arr[4][4]={{55, 56, 57,47 },
	{52, 53, 54, 42},
		{49, 50, 51,45},
			{67, 48, 61, 43}};
	
unsigned char keypad_get_value(void)
{
	unsigned char col, row, ans = INVALID_KEYPAD_PRESS;
	for (row = 5 ; row>=2 ; row--)
	{
		PORTC |= 0b00111100; /*write High on all row*/
		
		CLR_BIT(PORTC,row); /*write low on one row*/
		
		for(col=7 ; col>=3 ; col--)
		{
			if(col==4)
			col--;
			
			if(GET_BIT(PIND,col)==0)
			{
				_delay_ms(120);
				if(GET_BIT(PIND,col)==0)
				{
					if(col==3)
					{
						ans=arr[5-row][7-col-1];
						break;
					}
					else
					{
						ans=arr[5-row][7-col];
						break;
					}
				}
			}
		}
	}
	return ans;
}
void keypad_init()
{
	/*set pins cols as input*/
	CLR_BIT(DDRD,PIN7);
	CLR_BIT(DDRD,PIN6);
	CLR_BIT(DDRD,PIN5);
	CLR_BIT(DDRD,PIN3);
	/*set pins of rows as output*/
	SET_BIT(DDRC,PIN5);
	SET_BIT(DDRC,PIN4);
	SET_BIT(DDRC,PIN3);
	SET_BIT(DDRC,PIN2);
	/* set col pull up*/
	SET_BIT(PORTD,PIN7);
	SET_BIT(PORTD,PIN6);
	SET_BIT(PORTD,PIN5);
	SET_BIT(PORTD,PIN3);
	
}