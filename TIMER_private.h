/*
 * TIMER_private.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Eng Mohamed Hamdy
 */

#ifndef TIMER_PRIVATE_H_
#define TIMER_PRIVATE_H_


#define SREG 		*((volatile u8*)0x5F)
#define TIMSK 		*((volatile u8*)0x59)
#define TCCR0 		*((volatile u8*)0x53)
#define TCNT0 		*((volatile u8*)0x52)


#endif /* TIMER_PRIVATE_H_ */
