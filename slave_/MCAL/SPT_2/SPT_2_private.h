/*
 * SPT_2_private.h
 *
 *  Created on: Sep 5, 2023
 *      Author: User
 */

#ifndef MCAL_SPT_2_SPT_2_PRIVATE_H_
#define MCAL_SPT_2_SPT_2_PRIVATE_H_

#define TCCR2     (*(volatile u8*)0x45)
#define TCNT2     (*(volatile u8*)0x44)
#define OCR2      (*(volatile u8*)0x43)

#define TCCR0     (*(volatile u8*)0x53)
#define TCNT0     (*(volatile u8*)0x52)
#define OCR0      (*(volatile u8*)0x5C)

#define FAST_PWM  (1<<3)|(1<<6)
#define NON_INVERT (1<<5)

#endif /* MCAL_SPT_2_SPT_2_PRIVATE_H_ */
