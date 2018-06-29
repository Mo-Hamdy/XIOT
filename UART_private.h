/*
 * UART_private.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Eng Mohamed Hamdy
 */

#ifndef UART_PRIVATE_H_
#define UART_PRIVATE_H_


#define	UCSRB		*((volatile u8*)0x2A)
#define UBRRL		*((volatile u8*)0x29)
#define UDR 		*((volatile u8*)0x2C)
#define UCSRA 		*((volatile u8*)0x2B)
#define UCSRC 		*((volatile u8*)0x40)


#endif /* UART_PRIVATE_H_ */
