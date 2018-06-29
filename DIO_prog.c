/*
 * DIO_prog.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Eng Mohamed Hamdy
 */
#include "Type.h"
#include "Macros.h"
#include "DIO_private.h"
#include "DIO_interface.h"


/***************************************************************************************/
/* Description! Interface to set the Output value of the pin                           */
/* Input      ! Port number , Pin number , Value to set                                */
/* Output     ! Nothing                                                                */
/***************************************************************************************/
void DIO_vidSetPinValue(u8 u8PortNumberCpy,u8 u8PinNumberCpy,u8 u8ValueCpy)
{
	switch(u8PortNumberCpy)
	{
		case DIO_PORTA:
			if(u8ValueCpy==HIGH)
			{
				SET_BIT(PORTA,u8PinNumberCpy);
			}
			else
			{
				CLEAR_BIT(PORTA,u8PinNumberCpy);
			}
		break;
		case DIO_PORTB:
			if(u8ValueCpy==HIGH)
			{
				SET_BIT(PORTB,u8PinNumberCpy);
			}
			else
			{
				CLEAR_BIT(PORTB,u8PinNumberCpy);
			}
		break;
		case DIO_PORTC:
			if(u8ValueCpy==HIGH)
			{
				SET_BIT(PORTC,u8PinNumberCpy);
			}
			else
			{
				CLEAR_BIT(PORTC,u8PinNumberCpy);
			}
		break;
		case DIO_PORTD:
			if(u8ValueCpy==HIGH)
			{
				SET_BIT(PORTD,u8PinNumberCpy);
			}
			else
			{
				CLEAR_BIT(PORTD,u8PinNumberCpy);
			}
		break;
	}
}

/***************************************************************************************/
/* Description! Interface to read an input digital pin                                 */
/* Input      ! Port number , Pin number                                               */
/* Output     ! u8 contains the Pin value                                              */
/***************************************************************************************/
u8 DIO_u8GetPinValue(u8 u8PortNumberCpy,u8 u8PinNumberCpy)
{
	u8 Loc_u8PinValue=0;
	switch(u8PortNumberCpy)
	{
		case DIO_PORTA:

			Loc_u8PinValue=GET_BIT(PINA,u8PinNumberCpy);
		break;
		case DIO_PORTB:

			Loc_u8PinValue=GET_BIT(PINB,u8PinNumberCpy);
			break;
		case DIO_PORTC:

			Loc_u8PinValue=GET_BIT(PINC,u8PinNumberCpy);
		break;
		case DIO_PORTD:

			Loc_u8PinValue=GET_BIT(PIND,u8PinNumberCpy);
		break;
	}
	return Loc_u8PinValue;
}

/***************************************************************************************/
/* Description! Interface to Set the direction of PIN                                  */
/* Input      ! Port number , Pin number, Desired Direction                            */
/* Output     ! Nothing                                                                */
/***************************************************************************************/
void DIO_vidSetPinDirection(u8 u8PortNumberCpy,u8 u8PinNumberCpy,u8 u8DirectionCpy)
{
	switch(u8PortNumberCpy)
	{
		case DIO_PORTA:
			if(u8DirectionCpy==OUTPUT)
			{
				SET_BIT(DDRA,u8PinNumberCpy);
			}
			else
			{
				CLEAR_BIT(DDRA,u8PinNumberCpy);
			}
		break;

		case DIO_PORTB:
			if(u8DirectionCpy==OUTPUT)
			{
				SET_BIT(DDRB,u8PinNumberCpy);
			}
			else
			{
				CLEAR_BIT(DDRB,u8PinNumberCpy);
			}
		break;

		case DIO_PORTC:
			if(u8DirectionCpy==OUTPUT)
			{
				SET_BIT(DDRC,u8PinNumberCpy);
			}
			else
			{
				CLEAR_BIT(DDRC,u8PinNumberCpy);
			}
		break;

		case DIO_PORTD:
			if(u8DirectionCpy==OUTPUT)
			{
				SET_BIT(DDRD,u8PinNumberCpy);
			}
			else
			{
				CLEAR_BIT(DDRD,u8PinNumberCpy);
			}
		break;
	}
}

/***************************************************************************************/
/* Description! Interface to set port direction                                        */
/* Input      ! Port number , Desired Direction                                        */
/* Output     ! Nothing                                                                */
/***************************************************************************************/
void DIO_vidSetPortDirection(u8 u8PortNumberCpy,u8 u8ValueCpy)
{
	switch(u8PortNumberCpy)
	{
		case DIO_PORTA:

			DDRA = u8ValueCpy;
		break;

		case DIO_PORTB:

			DDRB = u8ValueCpy;
		break;

		case DIO_PORTC:

			DDRC = u8ValueCpy;
		break;

		case DIO_PORTD:

			DDRD = u8ValueCpy;
		break;
	}
}

/***************************************************************************************/
/* Description! Interface to set the output value of port                              */
/* Input      ! Port number , Desired output value                                     */
/* Output     ! Nothing                                                                */
/***************************************************************************************/
void DIO_vidSetPortValue(u8 u8PortNumberCpy,u8 u8ValueCpy)
{
	switch(u8PortNumberCpy)
	{
		case DIO_PORTA:

			PORTA=u8ValueCpy; // 3shan ana bn2l data msh bs 0 aw 1
		break;

		case DIO_PORTB:

			PORTB=u8ValueCpy;
		break;

		case DIO_PORTC:

			PORTC=u8ValueCpy;
		break;

		case DIO_PORTD:

			PORTD=u8ValueCpy;
		break;
	}
}

/***************************************************************************************/
/* Description! Interface to get the input value on Port                               */
/* Input      ! Port number                                                            */
/* Output     ! Port Value                                                             */
/***************************************************************************************/
u8 DIO_u8GetPortValue(u8 u8PortNumberCpy)
{
	u8 LOC_u8Return = 0x00;
	switch(u8PortNumberCpy)
	{
		case DIO_PORTA:

			LOC_u8Return = PINA;
		break;
		case DIO_PORTB:
			LOC_u8Return = PINB;
		break;
		case DIO_PORTC:
			LOC_u8Return = PINC;
		break;
		case DIO_PORTD:
			LOC_u8Return = PIND;
		break;
	}
	return LOC_u8Return;
}
