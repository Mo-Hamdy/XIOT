/*
 * ADC_prog.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Eng Mohamed Hamdy
 */

#include "Type.h"
#include "Macros.h"
#include "ADC_interface.h"
#include "ADC_private.h"


void ADC_vidInit(void)
{

	CLEAR_BIT(ADMUX,7);  //set the reference to 5volt
	SET_BIT(ADMUX,6);

	SET_BIT(ADMUX,5);    //set left adjust

	CLEAR_BIT(ADMUX,0);  //set the first channel to read
	CLEAR_BIT(ADMUX,1);
	CLEAR_BIT(ADMUX,2);
	CLEAR_BIT(ADMUX,3);
	CLEAR_BIT(ADMUX,4);

	SET_BIT(ADCSRA,7);   //ADC enable
	CLEAR_BIT(ADCSRA,6);
	CLEAR_BIT(ADCSRA,5); //ADC Auto Trigger disable
	SET_BIT(ADCSRA,4);   //ADC Interrupt Flag
	CLEAR_BIT(ADCSRA,3); //ADC Interrupt disable

	SET_BIT(ADCSRA,2);   //ADC Prescaler Select Bits, Division Factor =128
	SET_BIT(ADCSRA,1);
	SET_BIT(ADCSRA,0);

}

u8 ADC_u8GetValue(void)
{
	SET_BIT(ADCSRA,6);            //ADC start conversion
	while(GET_BIT(ADCSRA,4)==0);  // check on ADC Interrupt Flag
	SET_BIT(ADCSRA,4);            // Clear ADC Interrupt Flag
	return ADCH;
}
