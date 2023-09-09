/*
 * interface.h

 * Created on: Aug 11, 2023
 * Author: abdelrahman mohamed
 */
#ifndef MCAL_DIO_DIO_INTERFACE_H_
#define MCAL_DIO_DIO_INTERFACE_H_

/* ------------ Macros Declaration ------------*/

/* PORTS*/
#define PORTA 0
#define PORTB 1
#define PORTC 2
#define PORTD 3


/*PINS*/
#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7

/*I/O*/
#define INPUT 0
#define OUTPUT 1
#define INPUT_PORT 0
#define OUTPUT_PORT 0xFF

/*H/L*/
#define HIGH_PORT 0xFF
#define LOW_PORT 0
#define HIGH 1
#define LOW 0

/*upper begin from 4 to 7 /lower begin from 0 to 3*/
#define UPPER 1
#define LOWER 0

#define SET_UPPER 0xF0
#define SET_LOWER 0x0F

/* ------------ software interface Declaration DIO ------------*/


/*port level*/
void DIO_set_port_direction(u8 copy_u8port, u8 copy_u8direction );//DDR
void DIO_set_port_value(u8 copy_u8port ,u8 copy_u8value );//PORT
void DIO_get_port_value(u8 copy_u8port ,u8 *u8value );//PIN


/*4pin level*/
void DIO_set_4pin_direction(u8 copy_u8port ,u8 copy_u8_4pinselection,u8 copy_u8direction );
void DIO_set_4pin_value(u8 copy_u8port ,u8 copy_u8_4pinselection,u8 copy_u8value );
void DIO_get_4pin_value(u8 copy_u8port ,u8 copy_u8_4pinselection,u8 *u8value );

/*pin level*/
void DIO_set_pin_direction(u8 copy_u8port ,u8 copy_u8pin,u8 copy_u8direction );
void DIO_set_pin_value(u8 copy_u8port ,u8 copy_u8pin,u8 copy_u8value );
void DIO_get_pin_value(u8 copy_u8port ,u8 copy_u8pin,u8 *u8value );
void DIO_tog_pin_value(u8 copy_u8port ,u8 copy_u8pin);


#endif /* MCAL_DIO_DIO_INTERFACE_H_ */
