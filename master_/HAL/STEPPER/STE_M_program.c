/*
 * STE_M_program.c
 *
 *  Created on: Aug 17, 2023
 *      Author: User
 */

/* ------------ INCLUDES ------------*/
#include "C:\Users\User\Desktop\iti\interfasing\grad's project\master_\LIB\std_types.h"
#include "C:\Users\User\Desktop\iti\interfasing\grad's project\master_\LIB\bit_math.h"
#include"STE_M_interface.h"
#include "C:\Users\User\Desktop\iti\interfasing\grad's project\master_\MCAL\DIO\DIO_interface.h"
#include"STE_M_config.h"
#include<util/delay.h>



void STE_M_INITIAL()
{
	DIO_set_pin_direction(STE_M_PORT ,STE_M_BLUE,OUTPUT);
	DIO_set_pin_direction(STE_M_PORT ,STE_M_2_BINK,OUTPUT);
	DIO_set_pin_direction(STE_M_PORT ,STE_M_3_YELLOW,OUTPUT);
	DIO_set_pin_direction(STE_M_PORT ,STE_M_4_ORANGE,OUTPUT);
}


/*make motor move forward x number of steps */
void STE_M_full_step_forward(u8 num_of_step)
{
	u8 step_coun=0 ;
for(step_coun=0 ; step_coun<num_of_step ; step_coun++)
{
		DIO_set_pin_value(STE_M_PORT ,STE_M_BLUE,HIGH);
		DIO_set_pin_value(STE_M_PORT ,STE_M_2_BINK,LOW);
		DIO_set_pin_value(STE_M_PORT ,STE_M_3_YELLOW,LOW);
		DIO_set_pin_value(STE_M_PORT ,STE_M_4_ORANGE,LOW);

		_delay_ms(5);
		DIO_set_pin_value(STE_M_PORT ,STE_M_BLUE,LOW);
		DIO_set_pin_value(STE_M_PORT ,STE_M_2_BINK,HIGH);
		DIO_set_pin_value(STE_M_PORT ,STE_M_3_YELLOW,LOW);
		DIO_set_pin_value(STE_M_PORT ,STE_M_4_ORANGE,LOW);

		_delay_ms(5);
		DIO_set_pin_value(STE_M_PORT ,STE_M_BLUE,LOW);
		DIO_set_pin_value(STE_M_PORT ,STE_M_2_BINK,LOW);
		DIO_set_pin_value(STE_M_PORT ,STE_M_3_YELLOW,HIGH);
		DIO_set_pin_value(STE_M_PORT ,STE_M_4_ORANGE,LOW);

		_delay_ms(5);
		DIO_set_pin_value(STE_M_PORT ,STE_M_BLUE,LOW);
		DIO_set_pin_value(STE_M_PORT ,STE_M_2_BINK,LOW);
		DIO_set_pin_value(STE_M_PORT ,STE_M_3_YELLOW,LOW);
		DIO_set_pin_value(STE_M_PORT ,STE_M_4_ORANGE,HIGH);

		_delay_ms(5);
		DIO_set_pin_value(STE_M_PORT ,STE_M_BLUE,LOW);
		DIO_set_pin_value(STE_M_PORT ,STE_M_2_BINK,LOW);
		DIO_set_pin_value(STE_M_PORT ,STE_M_3_YELLOW,LOW);
		DIO_set_pin_value(STE_M_PORT ,STE_M_4_ORANGE,LOW);
		_delay_ms(5);

}
}

/*make motor move backward x number of steps */
void STE_M_full_step_backward(u8 num_of_step)
{
	u8 step_coun=0 ;
for(step_coun=0 ; step_coun<num_of_step ; step_coun++)
{

		DIO_set_pin_value(STE_M_PORT ,STE_M_BLUE,LOW);
		DIO_set_pin_value(STE_M_PORT ,STE_M_2_BINK,LOW);
		DIO_set_pin_value(STE_M_PORT ,STE_M_3_YELLOW,LOW);
		DIO_set_pin_value(STE_M_PORT ,STE_M_4_ORANGE,HIGH);

		_delay_ms(5);
		DIO_set_pin_value(STE_M_PORT ,STE_M_BLUE,LOW);
		DIO_set_pin_value(STE_M_PORT ,STE_M_2_BINK,LOW);
		DIO_set_pin_value(STE_M_PORT ,STE_M_3_YELLOW,HIGH);
		DIO_set_pin_value(STE_M_PORT ,STE_M_4_ORANGE,LOW);

		_delay_ms(5);
		DIO_set_pin_value(STE_M_PORT ,STE_M_BLUE,LOW);
		DIO_set_pin_value(STE_M_PORT ,STE_M_2_BINK,HIGH);
		DIO_set_pin_value(STE_M_PORT ,STE_M_3_YELLOW,LOW);
		DIO_set_pin_value(STE_M_PORT ,STE_M_4_ORANGE,LOW);

		_delay_ms(5);
		DIO_set_pin_value(STE_M_PORT ,STE_M_BLUE,HIGH);
		DIO_set_pin_value(STE_M_PORT ,STE_M_2_BINK,LOW);
		DIO_set_pin_value(STE_M_PORT ,STE_M_3_YELLOW,LOW);
		DIO_set_pin_value(STE_M_PORT ,STE_M_4_ORANGE,LOW);

		_delay_ms(5);
		DIO_set_pin_value(STE_M_PORT ,STE_M_BLUE,LOW);
		DIO_set_pin_value(STE_M_PORT ,STE_M_2_BINK,LOW);
		DIO_set_pin_value(STE_M_PORT ,STE_M_3_YELLOW,LOW);
		DIO_set_pin_value(STE_M_PORT ,STE_M_4_ORANGE,LOW);
		_delay_ms(5);

}

}


/*make motor move forward half step */
void STE_M_half_step_forward()
{
	DIO_set_pin_value(STE_M_PORT ,STE_M_BLUE,HIGH);
	DIO_set_pin_value(STE_M_PORT ,STE_M_2_BINK,LOW);
	DIO_set_pin_value(STE_M_PORT ,STE_M_3_YELLOW,LOW);
	DIO_set_pin_value(STE_M_PORT ,STE_M_4_ORANGE,LOW);

	_delay_ms(5);
	DIO_set_pin_value(STE_M_PORT ,STE_M_BLUE,LOW);
	DIO_set_pin_value(STE_M_PORT ,STE_M_2_BINK,HIGH);
	DIO_set_pin_value(STE_M_PORT ,STE_M_3_YELLOW,LOW);
	DIO_set_pin_value(STE_M_PORT ,STE_M_4_ORANGE,LOW);
}


/*make motor move backward half step */
void STE_M_half_step_backward()
{
	DIO_set_pin_value(STE_M_PORT ,STE_M_BLUE,LOW);
	DIO_set_pin_value(STE_M_PORT ,STE_M_2_BINK,LOW);
	DIO_set_pin_value(STE_M_PORT ,STE_M_3_YELLOW,LOW);
	DIO_set_pin_value(STE_M_PORT ,STE_M_4_ORANGE,HIGH);

	_delay_ms(5);
	DIO_set_pin_value(STE_M_PORT ,STE_M_BLUE,LOW);
	DIO_set_pin_value(STE_M_PORT ,STE_M_2_BINK,LOW);
	DIO_set_pin_value(STE_M_PORT ,STE_M_3_YELLOW,HIGH);
	DIO_set_pin_value(STE_M_PORT ,STE_M_4_ORANGE,LOW);
	_delay_ms(5);
}

/*make motor back to angle zero */
void STE_M_set_to_zero()
{
	DIO_set_pin_value(STE_M_PORT ,STE_M_BLUE,LOW);
	DIO_set_pin_value(STE_M_PORT ,STE_M_2_BINK,LOW);
	DIO_set_pin_value(STE_M_PORT ,STE_M_3_YELLOW,LOW);
	DIO_set_pin_value(STE_M_PORT ,STE_M_4_ORANGE,LOW);
	_delay_ms(5);

}
