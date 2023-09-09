/*
 * ADC_config.h
 *
 *  Created on: Aug 20, 2023
 *      Author: User
 */

#ifndef MCAL_ADC_ADC_CONFIG_H_
#define MCAL_ADC_ADC_CONFIG_H_

/*OPTIONS
 *VOLTAGE REFRANCE
 *
 *   1- ACD_VREF_AREF
 *   2- ACD_VREF_AVCC
 *   3- ACD_VREF_2.56V
 * */

#define ADC_VOLTAGE_REFRANCE ACD_VREF_AVCC



/*OPTIONS
 *
 *     1- ADC_PRESCALER_2
 *     2- ADC_PRESCALER_4
 *     3- ADC_PRESCALER_8
 *     4- ADC_PRESCALER_16
 *     5- ADC_PRESCALER_32
 *     6- ADC_PRESCALER_64
 *     7- ADC_PRESCALER_128
 * */


#define ADC_PRESCALER  ADC_PRESCALER_128


#endif /* MCAL_ADC_ADC_CONFIG_H_ */
