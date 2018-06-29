/*
 * INTERRUPT_private.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Eng Mohamed Hamdy
 */

#ifndef INTERRUPT_PRIVATE_H_
#define INTERRUPT_PRIVATE_H_


#define SREG 		*((volatile u8*)0x5F)
#define MCUCR 		*((volatile u8*)0x55)
#define GICR 		*((volatile u8*)0x5B)
#define GIFR 		*((volatile u8*)0x5A)


#endif /* INTERRUPT_PRIVATE_H_ */
