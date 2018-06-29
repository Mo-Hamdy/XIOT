/*
 * UART_prog.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Eng Mohamed Hamdy
 */

#include "Type.h"
#include "Macros.h"
#include "./UART_private.h"
#include "./UART_interface.h"


void UART_voidInit(void)
{
	CLEAR_BIT(UCSRB,7);
	CLEAR_BIT(UCSRB,6);
	CLEAR_BIT(UCSRB,5);
	SET_BIT(UCSRB,4);//RX enable
	SET_BIT(UCSRB,3);//TX enable
	CLEAR_BIT(UCSRB,2);
	CLEAR_BIT(UCSRB,1);
	CLEAR_BIT(UCSRB,0);

	SET_BIT(UCSRC,7);   //Accessing the UCSRC Register
	CLEAR_BIT(UCSRC,6); //Asynchronous mode
	CLEAR_BIT(UCSRC,5); //Parity Disabled
	CLEAR_BIT(UCSRC,4);
	CLEAR_BIT(UCSRC,3); //One Stop Bit
	SET_BIT(UCSRC,2);   //8-bits data (Character Size) in a frame.
	SET_BIT(UCSRC,1);
	CLEAR_BIT(UCSRC,0); //Clock Polarity

	UBRRL=51;           //Baud Rate 9600
}

void UART_voidSendByte(u8 u8Byte)
{
	while(GET_BIT(UCSRA,5)==0); //Data Register Empty ?
	UDR=u8Byte;
}

u8 UART_u8RecieveByte(void)
{
	while(GET_BIT(UCSRA,7)==0); //Receive Complete ?
	return UDR;
}
