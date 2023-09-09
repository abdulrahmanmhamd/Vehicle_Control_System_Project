/*
 * ADC_interface.h
 *
 *  Created on: Aug 20, 2023
 *      Author: User
 */

#ifndef MCAL_ADC_ADC_INTERFACE_H_
#define MCAL_ADC_ADC_INTERFACE_H_

/* ------------ Macros Declaration ------------*/

/*CHANNEL SELACTION*/

#define ADC_CHANNEL_0  0
#define ADC_CHANNEL_1  1
#define ADC_CHANNEL_2  2
#define ADC_CHANNEL_3  3
#define ADC_CHANNEL_4  4
#define ADC_CHANNEL_5  5
#define ADC_CHANNEL_6  6
#define ADC_CHANNEL_7  7


/* ------------ software interface Declaration ADC ------------*/

void ADC_initial();
void ADC_start_convertion(u8  copy_selectchannle , u16 *cop_return);

#endif /* MCAL_ADC_ADC_INTERFACE_H_ */
