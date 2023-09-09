/*
 * MOTOR_program.c
 *
 *  Created on: Sep 4, 2023
 *      Author: User
 */

#include "C:\Users\User\Desktop\iti\interfasing\grad's project\slave_\LIB\std_types.h"
#include "C:\Users\User\Desktop\iti\interfasing\grad's project\slave_\LIB\bit_math.h"
#include "C:\Users\User\Desktop\iti\interfasing\grad's project\slave_\MCAL\SPT_2\SPT_2_interface.h"
#include "C:\Users\User\Desktop\iti\interfasing\grad's project\slave_\MCAL\DIO\DIO_interface.h"
#include "MOTOR_private.h"
#include "MOTOR_interface.h"






 void motor_init()
 {
	 DIO_set_pin_direction(PORTB,PIN0,OUTPUT);
	 DIO_set_pin_direction(PORTB,PIN1,OUTPUT);
	 DIO_set_pin_direction(PORTA,PIN0,OUTPUT);
	 DIO_set_pin_direction(PORTA,PIN1,OUTPUT);



PWM_init(TIMER_0);
PWM_init(TIMER_2);

 }


 void move_forward()
 {
	 DIO_U8PORTA |= (1<<PA0);
	 DIO_U8PORTA &= (~(1<<PA1));

	 DIO_U8PORTB |= (1<<PB0);
	 DIO_U8PORTB &= (~(1<<PB1));

 }


 /* void move_backward()
  {

	 	make_pin_low_or_high(PORTB ,PIN1,HIGH);
	 	get_pin_Value(PORTB ,PIN0,HIGH);
	    make_pin_low_or_high(PORTA ,PIN1,HIGH);
	    get_pin_Value(PORTA ,PIN0,HIGH);

  }
*/

 /* void set_speed_left (u8 speed)
  {
	  PWM_SetDutyCycle( speed, TIMER_0);
  }
*/

  void set_speed_right (u8 speed)
  {
	  PWM_SetDutyCycle( speed, TIMER_2);
  }


  /* void move_right(u8 speed_left)
   {
	    set_speed_right(0);
		  set_speed_left(speed_left);

   }
*/


	 void motor_stop()
	 {
     //set_speed_left(0);
     set_speed_right(0);
	 }
