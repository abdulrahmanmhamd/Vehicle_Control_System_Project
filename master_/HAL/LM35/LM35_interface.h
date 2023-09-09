/*
 * LM35_interface.h
 *
 *  Created on: Aug 20, 2023
 *      Author: User
 */

#ifndef HAL_LM35_LM35_INTERFACE_H_
#define HAL_LM35_LM35_INTERFACE_H_


/* ------------ Macros Declaration ------------*/

/*PINS*/
#define LM35_PIN0 0
#define LM35_PIN1 1
#define LM35_PIN2 2
#define LM35_PIN3 3
#define LM35_PIN4 4
#define LM35_PIN5 5
#define LM35_PIN6 6
#define LM35_PIN7 7

/*------------ software interface Declaration LM35------------*/
u16 read_LM35_value(u8 copy_pin);

#endif /* HAL_LM35_LM35_INTERFACE_H_ */
