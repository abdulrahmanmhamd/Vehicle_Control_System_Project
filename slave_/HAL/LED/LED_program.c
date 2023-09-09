/*
 * LED_program.c
 *
 *  Created on: Aug 12, 2023
 *      Author: User
 */

/* ------------ INCLUDES ------------*/
#include"C:\Users\User\Desktop\iti\interfasing\grad's project\slave_\LIB\bit_math.h"
#include"C:\Users\User\Desktop\iti\interfasing\grad's project\slave_\LIB\std_types.h"
#include"LED_interface.h"
#include "C:\Users\User\Desktop\iti\interfasing\grad's project\slave_\MCAL\DIO\DIO_interface.h"
#include <util/delay.h>


/*LED level*/
void led_turn_on_or_off(u8 copy_u8port,u8 copy_u8pin,u8 copy_u8turn )
{
	if((copy_u8port<=PORTD)&&copy_u8pin<=PIN7)
	    {

		   DIO_set_pin_direction(copy_u8port,copy_u8pin,OUTPUT);

	        if(copy_u8turn==TURN_ON)
	        {

	        	DIO_set_pin_value(copy_u8port,copy_u8pin,HIGH);
	        	_delay_ms(1000);

	        }
	        else
	        {

	        	DIO_set_pin_value(copy_u8port,copy_u8pin,LOW);
	        	_delay_ms(1000);

	        }

	    }
	    else
	    {
	        /* no operation */
	    }
}

/*turn on 1 sce and off 1 sce*/
void led_turn_on_and_off(u8 copy_u8port, u8 copy_u8pin )
{
	if((copy_u8port<=PORTD)&&copy_u8pin<=PIN7)
	    {

		   DIO_set_pin_direction(copy_u8port,copy_u8pin,OUTPUT);
	        	DIO_set_pin_value(copy_u8port,copy_u8pin,HIGH);
	        	_delay_ms(1000);
	        	DIO_set_pin_value(copy_u8port,copy_u8pin,LOW);
	        	_delay_ms(1000);
	        }
	    else
	    {
	        /* no operation */
	    }

}



/*8 LEDS level*/
void _8leds_turn_on_or_off(u8 copy_u8port,u8 copy_u8turn)
{
	if((copy_u8port<=PORTD))
	    {

		   DIO_set_port_direction(copy_u8port,OUTPUT_PORT);

	        if(copy_u8turn==TURN_ON)
	        {

	        	DIO_set_port_value(copy_u8port,HIGH_PORT);
	        	_delay_ms(1000);
	        }
	        else
	        {

	        	DIO_set_port_value(copy_u8port,LOW_PORT);
	        	_delay_ms(1000);

	        }

	    }
	    else
	    {
	        /* no operation */
	    }

}


/*turn on for 8 leds for 1 sec and off 1 sce*/
void _8leds_turn_on_and_off(u8 copy_u8port)
{
	if((copy_u8port<=PORTD))
	    {

		 DIO_set_port_direction(copy_u8port,OUTPUT_PORT);
		        DIO_set_port_value(copy_u8port,HIGH_PORT);
	        	_delay_ms(1000);
	        	DIO_set_port_value(copy_u8port,LOW_PORT);
	        	_delay_ms(1000);

	        }
	    else
	    {
	        /* no operation */
	    }

}


