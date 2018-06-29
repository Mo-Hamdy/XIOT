/*
 * DIO_interface.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Eng Mohamed Hamdy
 */

#ifndef DIO_H_
#define DIO_H_

//Ports Name
#define DIO_PORTA		0
#define DIO_PORTB 		1
#define DIO_PORTC 		2
#define DIO_PORTD 		3

#define HIGH		 1
#define LOW  		 0

#define OUTPUT 		 1
#define INPUT 		 0

//Set the value of output pin in port
void DIO_vidSetPinValue(u8 u8PortNumberCpy,u8 u8PinNumberCpy,u8 u8ValueCpy);

//Get the value of input pin in port
u8 DIO_u8GetPinValue(u8 u8PortNumberCpy,u8 u8PinNumberCpy);

//Set the direction of pin in port
void DIO_vidSetPinDirection(u8 u8PortNumberCpy,u8 u8PinNumberCpy,u8 u8DirectionCpy);

//Set port direction
void DIO_vidSetPortDirection(u8 u8PortNumberCpy,u8 u8ValueCpy);

//Set the output value of port
void DIO_vidSetPortValue(u8 u8PortNumberCpy,u8 u8ValueCpy);

//Get the input value on port
u8 DIO_u8GetPortValue(u8 u8PortNumberCpy);



#endif /* DIO_H_ */
