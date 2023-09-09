/*
 * STE_M_interface.h
 *
 *  Created on: Aug 17, 2023
 *      Author: User
 */

#ifndef HAL_STEPPER_STE_M_INTERFACE_H_
#define HAL_STEPPER_STE_M_INTERFACE_H_

/* ------------ Macros Declration ------------*/

/*number of steps */
#define STE_M_1_STEP 1
#define STE_M_2_STEP 2
#define STE_M_3_STEP 3
#define STE_M_4_STEP 4
#define STE_M_5_STEP 5
#define STE_M_6_STEP 6
#define STE_M_7_STEP 7
#define STE_M_8_STEP 8
#define STE_M_9_STEP 9
#define STE_M_10_STEP 10

/* PORTS*/
#define STE_M_PORTA 0
#define STE_M_PORTB 1
#define STE_M_PORTC 2
#define STE_M_PORTD 3

/*PINS*/
#define STE_M_PIN0  0
#define STE_M_PIN1  1
#define STE_M_PIN2  2
#define STE_M_PIN3  3
#define STE_M_PIN4  4
#define STE_M_PIN5  5
#define STE_M_PIN6  6
#define STE_M_PIN7  7




#define STE_M_FULL_STEP 4

/*number of steps */
/*
#define STE_M_BLUE 1
#define STE_M_2_BINK 2
#define STE_M_3_YELLOW 3
#define STE_M_4_ORANGE 4
*/
/* ------------ software interface Declration KAYPAD ------------*/


void STE_M_INITIAL();
/*make motor move forward x number of steps */
void STE_M_full_step_forward(u8 num_of_step);
/*make motor move backward x number of steps */
void STE_M_full_step_backward(u8 num_of_step);
/*make motor move forward half step */
void STE_M_half_step_forward();
/*make motor move backward half step */
void STE_M_half_step_backward();
/*make motor back to angle zero */
void STE_M_set_to_zero();



#endif /* HAL_STEPPER_STE_M_INTERFACE_H_ */
