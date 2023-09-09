/*
 * SPT_2_interface.h
 *
 *  Created on: Sep 5, 2023
 *      Author: User
 */

#ifndef MCAL_SPT_2_SPT_2_INTERFACE_H_
#define MCAL_SPT_2_SPT_2_INTERFACE_H_


/*************************************************
 *  API functions
 *************************************************/
/* to put in the PWM_init function */
#define TIMER_0                         0
#define TIMER_2                         2

void PWM_init(u8 u8TimerNumber);
void PWM_SetDutyValue(u8 DutyValue, u8 u8TimerNumber);
void PWM_SetDutyCycle(u8 DutyCycle, u8 u8TimerNumber);

#endif /* MCAL_SPT_2_SPT_2_INTERFACE_H_ */
