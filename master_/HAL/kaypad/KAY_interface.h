/*
 * KAY_interface.h
 *
 *  Created on: Aug 15, 2023
 *      Author: User
 */

#ifndef HAL_KAYPAD_KAY_INTERFACE_H_
#define HAL_KAYPAD_KAY_INTERFACE_H_

/* ------------ Macros Declration ------------*/

/* PORTS*/
#define KEYPAD_NOTPRESSED  0xff
#define KEYPAD_PORTA 0
#define KEYPAD_PORTB 1
#define KEYPAD_PORTC 2
#define KEYPAD_PORTD 3

/*PINS*/
#define KEYPAD_PIN0  0
#define KEYPAD_PIN1  1
#define KEYPAD_PIN2  2
#define KEYPAD_PIN3  3
#define KEYPAD_PIN4  4
#define KEYPAD_PIN5  5
#define KEYPAD_PIN6  6
#define KEYPAD_PIN7  7

/* ------------ software interface Declration KAYPAD ------------*/

void KEYPAD_INITIAL();
u8 KEYPAD_GETKEY(void);

#endif /* HAL_KAYPAD_KAY_INTERFACE_H_ */
