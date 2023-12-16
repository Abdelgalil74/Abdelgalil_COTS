/*
 * ADC_program.c
 *
 *  Created on: Dec 13, 2023
 *      Author: bagiz
 */


#include "STD_TYPES.h"
#include "ErrType.h"
#include "bit_math.h"

#include "ADC_register.h"
#include "ADC_private.h"
#include "ADC_config.h"
#include "ADC_interface.h"



void ADC_voidInit(void)
{
	/*Set AVCC as reference voltage*/

	SET_BIT(ADMUX,ADMUX_REFS0);
	CLR_BIT(ADMUX,ADMUX_REFS1);


	/*Select Left or Right adjust result for resolution configuration */
#if ADC_u8RESOLUTION == EIGHT_BIT
	SET_BIT(ADMUX,ADMUX_ADLAR);		/*LEFT*/
#elif ADC_u8RESOLUTION == TEN_BIT
	CLR_BIT(ADMUX,ADMUX_ADLAR);  /*ñññRIGH */
#else
#error Wrong ADC_u8RESOLUTION configuration
#endif

	/*Disabled auto trigger */
	CLR_BIT(ADCSRA,ADCSRA_ADATE);
	/*Disabled interrupt enable*/
	CLR_BIT(ADCSRA,ADCSRA_ADIE);


	/*Enable ADC*/
	SET_BIT(ADCSRA,ADCSRA_ADEN);

	/*configure prescaler */
	ADCSRA &=PRESCALER_BIT_MASK;
	ADCSRA |= ADC_u8PRESCALER_DIVISION_FACTOR << PRESCALER_BIT_POS;

}

uint16 ADC_u8GetChannelReading(uint8 Copy_u8Channel)
{
	/*Set input channel */
	ADMUX &=CHANNEL_BIT_MASK;		/*clear the channel selection bits */
	ADMUX |= Copy_u8Channel;

	/*start conversion*/
	SET_BIT(ADCSRA,ADCSRA_ADSC);

	/*Polling on the conversion complete*/
	while((GET_BIT(ADCSRA,ADCSRA_ADSC))==0);


	SET_BIT(ADCSRA,ADCSRA_ADIE);


#if ADC_u8RESOLUTION == EIGHT_BITS
	return ADCH;
#elif ADC_u8RESOLUTION == TEN_BITS
	return ADC;

#endif




	return ADCH;
}

