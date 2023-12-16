/*
 * ADC_register.h
 *
 *  Created on: Dec 13, 2023
 *      Author: bagiz
 */

#ifndef ADC_REGISTER_H_
#define ADC_REGISTER_H_


#define   ADMUX 				*((volatile uint8 *)0x27)
#define   ADMUX_REFS1			7U
#define   ADMUX_REFS0			6U
#define   ADMUX_ADLAR			5U

#define   ADCSRA 				*((volatile uint8 *)0x26)
#define   ADCSRA_ADEN			7U
#define   ADCSRA_ADSC			6U
#define   ADCSRA_ADATE			5U
#define   ADCSRA_ADIE			4U
//#define   ADCSRA_ADIE			3U


#define   ADCH				 *((volatile uint8 *)0x25)


#define   ADCL 				*((volatile uint8 *)0x24)

#define   ADC 				*((volatile uint16 *)0x24)


#endif /* ADC_REGISTER_H_ */
