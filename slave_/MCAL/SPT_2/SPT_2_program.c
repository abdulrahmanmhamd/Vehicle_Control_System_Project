/*
 * SPT_2_program.c
 *
 *  Created on: Sep 5, 2023
 *      Author: User
 */


#include"C:\Users\User\Desktop\iti\interfasing\grad's project\slave_\LIB\bit_math.h"
#include"C:\Users\User\Desktop\iti\interfasing\grad's project\slave_\LIB\std_types.h"
#include "SPT_2_private.h"
#include "SPT_2_config.h"
#include "SPT_2_interface.h"
#include "C:\Users\User\Desktop\iti\interfasing\grad's project\slave_\MCAL\DIO\DIO_interface.h"


void PWM_init(u8 u8TimerNumber)
{
	switch(u8TimerNumber)
	{
	    case TIMER_2:
	    	 /* OC2 PIN TO BE OUTPUT */
	    	//TIMER 2 IN PIN 7 PORTD

	    	/* OC2 PIN TO BE OUTPUT
	    	 TIMER 2 IN PIN 7 PORTD*/
	    	DIO_set_pin_direction(PORTD ,PIN7,OUTPUT);

	    	 /*Disable Timer 2*/
	    	 TCCR2 = DISABLE_MODULE_VALUE;
	    	 /* Setting pre scaler */
	    	 TCCR2 = (Fast_PRESCALER_1)|(FAST_PWM)|(NON_INVERT);
	    	 /* Initializing the timer with zero */
	    	 TCNT2 = ZER0_INITIALIZER;
	         break;

	    case TIMER_0:
	    	/* OC0 PIN TO BE OUTPUT */
	    	//TIMER 0 IN PIN 3 PORTB

	    	/* OC0 PIN TO BE OUTPUT
	    	 TIMER 0 IN PIN 3 PORTB*/
	    	DIO_set_pin_direction(PORTB ,PIN3,OUTPUT);

	    	/* Disable Timer 0 */
	    	TCCR0 = DISABLE_MODULE_VALUE;
	    	/* Setting pre scaler */

	    	TCCR0 = (Fast_PRESCALER_1)|(FAST_PWM)|(NON_INVERT);
	    	/* Initializing the timer with zero */
	    	TCNT0 = ZER0_INITIALIZER;
	    	break;

	    default:
	    	 break;
	}
	return;
}

void PWM_SetDutyValue(u8 DutyValue, u8 u8TimerNumber)
{

	  switch(u8TimerNumber)
	  {

	  case TIMER_2:

		  OCR2 = DutyValue;
		  break;

	  case TIMER_0:

		  OCR0 = DutyValue;
		  break;

	  default:
		   break;
	  }
	  return;
}


void PWM_SetDutyCycle(u8 DutyCycle, u8 u8TimerNumber)
{
	  u8 PWM_actual_Duty ;


	  PWM_actual_Duty = (DutyCycle * TIMER_MAX_VALUE) / DUTY_CYCLE_MAX_VALUE;

	  switch(u8TimerNumber)
	  {

	  case TIMER_2:
		  OCR2 = PWM_actual_Duty;
		  break;

	  case TIMER_0:
		  OCR0 = PWM_actual_Duty;
		  break;

	  default:
		  break;
	  }
}
