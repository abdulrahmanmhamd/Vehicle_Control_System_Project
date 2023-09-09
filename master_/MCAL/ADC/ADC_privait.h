/*
 * ADC_privait.h
 *
 *  Created on: Aug 20, 2023
 *      Author: User
 */

#ifndef MCAL_ADC_ADC_PRIVAIT_H_
#define MCAL_ADC_ADC_PRIVAIT_H_

#define ADMUX_REG  (*(volatile u8*)0x27)
#define ADCSRA_REG (*(volatile u8*)0x26)
#define ADCH_REG   (*(volatile u8*)0x25)
#define ADCL_REG   (*(volatile u8*)0x24)


/*MUX PINS*/
#define ADMUX_MUX0_BIT  0
#define ADMUX_MUX1_BIT  1
#define ADMUX_MUX2_BIT  2
#define ADMUX_MUX3_BIT  3
#define ADMUX_MUX4_BIT  4
#define ADMUX_ADLAR_BIT 5
#define ADMUX_REFS0_BIT 6
#define ADMUX_REFS1_BIT 7


/*ADCSRA PINS*/

#define ADCSRA_ADCPS0_BIT 0
#define ADCSRA_ADCPS1_BIT 1
#define ADCSRA_ADCPS2_BIT 2
#define ADCSRA_ADCSC_BIT  6
#define ADCSRA_ADEN_BIT   7


/*vref selection*/

#define ACD_VREF_AREF  0
#define ACD_VREF_AVCC  1
#define ACD_VREF_2_56V 3


/*PRESCALER SELACTION*/

#define ADC_PRESCALER_2   1
#define ADC_PRESCALER_4   2
#define ADC_PRESCALER_8   3
#define ADC_PRESCALER_16  4
#define ADC_PRESCALER_32  5
#define ADC_PRESCALER_64  6
#define ADC_PRESCALER_128 7
#define ADC_LAR_BIT       8


#endif /* MCAL_ADC_ADC_PRIVAIT_H_ */
