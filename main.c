/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Eng Mohamed Hamdy
 */

#include "Type.h"
#include "Macros.h"
#include "DIO_interface.h"
#include<avr/interrupt.h>
#include "INTERRUPT_interface.h"
#include "ADC_interface.h"
#include "TIMER_interface.h"
#include "UART_interface.h"


/*
 *I'm writing this Project for "ATmega32" Microcontroller
 */

//Timer Variable
u16 OVF_counter=0;
u8 Desired_time=0;
u8 Temp_Analog_Reading=0;
u8 Temp_Digital_Reading=0;


int main(void)
{

	INTERRUPT_VidInit();						//initiate INT1 driver
	DIO_vidSetPinDirection(DIO_PORTD,3,INPUT); 	//set Port D Pin 3 as input for INT1 (Switch)
	DIO_vidSetPinValue(DIO_PORTD,3,HIGH);	   	//pull up resistance
	DIO_vidSetPinDirection(DIO_PORTD,7,OUTPUT); //set Port D Pin 7 as output for LED

	UART_voidInit();	//initiate UART driver

	ADC_vidInit();		//initiate ADC driver

	TIMER_vidInit();	//initiate TIMER driver

	 while (1)
	 {

	 }
	 return 0;
}


ISR(INT1_vect)
{
	if(DIO_u8GetPinValue(DIO_PORTD,3)==LOW)			//check if switch pressed or not
	{
		DIO_vidSetPinValue(DIO_PORTD,7,HIGH);		//LED ON

		UART_voidSendByte('p');
		UART_voidSendByte('r');
		UART_voidSendByte('e');
		UART_voidSendByte('s');
		UART_voidSendByte('s');
		UART_voidSendByte('e');
		UART_voidSendByte('d');
		UART_voidSendByte(' ');

		UART_voidSendByte('L');
		UART_voidSendByte('E');
		UART_voidSendByte('D');
		UART_voidSendByte(' ');
		UART_voidSendByte('O');
		UART_voidSendByte('N');
		UART_voidSendByte(' ');

	}

	else											//Switch is not pressed
	{
		DIO_vidSetPinValue(DIO_PORTD,7,LOW);		//LED OFF

		UART_voidSendByte('L');
		UART_voidSendByte('E');
		UART_voidSendByte('D');
		UART_voidSendByte(' ');
		UART_voidSendByte('O');
		UART_voidSendByte('F');
		UART_voidSendByte('F');
		UART_voidSendByte(' ');

	}
}


ISR(TIMER0_OVF_vect)	//Timer comes every 3 sec to get temp reading and send it through UART
{
	OVF_counter ++;
	if(OVF_counter==31250)
	{
		OVF_counter=0;
		Desired_time++;
		if(Desired_time==3)		// 3 second Desired time
		{
			Desired_time=0;

			/*
			 * assume Using LM35 temperature sensor
			 * (1 mv=1 Celsius) to  (1v = 100c)
			 */
			 Temp_Analog_Reading  = ADC_u8GetValue();
			 Temp_Digital_Reading = (Temp_Analog_Reading*5*100)/256;

			 UART_voidSendByte(Temp_Digital_Reading);

		}
	}
}
