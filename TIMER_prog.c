/*
 * TIMER_prog.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Eng Mohamed Hamdy
 */

#include "Type.h"
#include "Macros.h"
#include "TIMER_interface.h"
#include "TIMER_private.h"



void TIMER_vidInit(void)
{
	CLEAR_BIT(TCCR0,7);		//disable Force Output Compare

	CLEAR_BIT(TCCR0,6); 	//Waveform Generation Mode: normal mode
	CLEAR_BIT(TCCR0,3);

	CLEAR_BIT(TCCR0,5); 	//Normal port operation, OC0 disconnected.
	CLEAR_BIT(TCCR0,4);

	CLEAR_BIT(TCCR0,2); 	//Clock Select: No prescaling
	CLEAR_BIT(TCCR0,1);
	SET_BIT(TCCR0,0);

	TCNT0=0;				//Timer/Counter Register for read and write operations

	SET_BIT(TIMSK,0);		//Timer/Counter0 Output Compare Match Interrupt Enable

	SET_BIT(SREG,7);		//global interrupt enable

}



