/*
 * MOTOR_private.h
 *
 *  Created on: Sep 5, 2023
 *      Author: User
 */

#ifndef HAL_MOTOR_MOTOR_PRIVATE_H_
#define HAL_MOTOR_MOTOR_PRIVATE_H_

#define DIO_U8PORTA (*(volatile u8*)0x3B)


/*B REGSTERS */
#define DIO_U8PORTB (*(volatile u8*)0x38)


/*C REGSTERS */
#define DIO_U8PORTC (*(volatile u8*)0x35)


/*D REGSTERS */
#define DIO_U8PORTD (*(volatile u8*)0x32)


#endif /* HAL_MOTOR_MOTOR_PRIVATE_H_ */
