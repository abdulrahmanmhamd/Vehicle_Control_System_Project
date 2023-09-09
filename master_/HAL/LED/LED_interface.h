/*
 * LED_interface.h
 *
 *  Created on: Aug 12, 2023
 *      Author: User
 */

#ifndef HAL_LED_LED_INTERFACE_H_
#define HAL_LED_LED_INTERFACE_H_


/* PORTS*/
#define LED_PORTA 0
#define LED_PORTB 1
#define LED_PORTC 2
#define LED_PORTD 3


/*PINS*/
#define LED_PIN0 0
#define LED_PIN1 1
#define LED_PIN2 2
#define LED_PIN3 3
#define LED_PIN4 4
#define LED_PIN5 5
#define LED_PIN6 6
#define LED_PIN7 7


/*ON/OFF*/
#define TURN_ON 1
#define TURN_OFF 0

/* ------------ software interface Declration DIO ------------*/

/*LED level*/
void led_turn_on_or_off(u8 copy_u8port,u8 copy_u8pin,u8 copy_u8turn );

/*turn on 1 sce and off 1 sce*/
void led_turn_on_and_off(u8 copy_u8port, u8 copy_u8pin );


/*8 LEDS level*/

void _8leds_turn_on_or_off(u8 copy_u8port,u8 copy_u8turn );

/*turn on 1 sce and off 1 sce*/
void _8leds_turn_on_and_off(u8 copy_u8port );

#endif /* HAL_LED_LED_INTERFACE_H_ */
