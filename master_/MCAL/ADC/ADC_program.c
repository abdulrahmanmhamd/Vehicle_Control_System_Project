/*
 * ADC_program.c
 *
 *  Created on: Aug 20, 2023
 *      Author: User
 */

/* ------------ INCLUDES ------------*/
#include "C:\Users\User\Desktop\iti\interfasing\grad's project\master_\LIB\std_types.h"
#include "C:\Users\User\Desktop\iti\interfasing\grad's project\master_\LIB\bit_math.h"
#include "ADC_interface.h"
#include "ADC_config.h"
#include "ADC_privait.h"

void ADC_initial()
{
	/*1- config voltage reference*/
	ADMUX_REG|=(ADC_VOLTAGE_REFRANCE <<ADMUX_REFS0_BIT);
	/*2- config PRESCALER */
	ADCSRA_REG|=ADC_PRESCALER;
	/*
	 * it will choose right adj
	 */
	/*3- set ADEN */
	 SET_BIT(ADCSRA_REG,ADCSRA_ADEN_BIT);

}


void ADC_start_convertion (u8 copy_selectchannle , u16 *cop_return)
{
	if(copy_selectchannle<=ADC_CHANNEL_7)
	{
		/*1- select channel*/
		ADMUX_REG|=copy_selectchannle;
		/*2- start convention*/
		SET_BIT(ADCSRA_REG,ADCSRA_ADCSC_BIT);
		/*Check if convention end*/
		while(GET_BIT(ADCSRA_REG,ADCSRA_ADCSC_BIT)==1)
			;
		*cop_return=(ADCL_REG|(ADCH_REG<<ADC_LAR_BIT));
	}
	else
	{
		/*no operation*/
	}

}

