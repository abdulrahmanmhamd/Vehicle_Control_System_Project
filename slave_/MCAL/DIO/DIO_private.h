/*
 * private.h
 *
 *  Created on: Aug 11, 2023
 *      Author: User
 */

#ifndef MCAL_DIO_DIO_PRIVATE_H_
#define MCAL_DIO_DIO_PRIVATE_H_
/*A REGSTERS */
#define DIO_U8PORTA ((volatile u8*)0x3B)
#define DIO_U8DDRA  ((volatile u8*)0x3A)
#define DIO_U8PINA  ((volatile u8*)0x39)

/*B REGSTERS */
#define DIO_U8PORTB ((volatile u8*)0x38)
#define DIO_U8DDRB  ((volatile u8*)0x37)
#define DIO_U8PINB  ((volatile u8*)0x36)

/*C REGSTERS */
#define DIO_U8PORTC ((volatile u8*)0x35)
#define DIO_U8DDRC  ((volatile u8*)0x34)
#define DIO_U8PINC  ((volatile u8*)0x33)

/*D REGSTERS */
#define DIO_U8PORTD ((volatile u8*)0x32)
#define DIO_U8DDRD  ((volatile u8*)0x31)
#define U8PIND  ((volatile u8*)0x30)

#endif /* MCAL_DIO_DIO_PRIVATE_H_ */
