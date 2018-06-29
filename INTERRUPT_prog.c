/*
 * INTERRUPT_prog.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Eng Mohamed Hamdy
 */

#include "Type.h"
#include "Macros.h"
#include "INTERRUPT_interface.h"
#include "INTERRUPT_private.h"



void INTERRUPT_VidInit(void)
{
	SET_BIT(SREG,7);        //global interrupt enable

	CLEAR_BIT(MCUCR,3);     //Inte. Sense Control: Any logical change on INT1 generates an inte. request
	SET_BIT(MCUCR,2);

	SET_BIT(GICR,7); 	    //INT1 enable
}
