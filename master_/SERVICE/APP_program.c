
 /******************************************************************************
 *
 * File Name: APP_program.c
 *
 *******************************************************************************/


#include "C:\Users\User\Desktop\iti\interfasing\DAY18\AVR\LIB\std_types.h"
#include "C:\Users\User\Desktop\iti\interfasing\DAY18\AVR\LIB\bit_math.h"
#include "C:\Users\User\Desktop\iti\interfasing\DAY18\AVR\MCAL\DIO\DIO_interface.h"
#include "C:\Users\User\Desktop\iti\interfasing\grad's project\master_\HAL\LED\LED_interface.h"
#include "APP_interface.h"


/*-----------APP SERVICE-----------*/


/*Engine Temperature Controller State*/
void Vehicle_SetupEngineTempController(u8 temp_ptr,Engine_Temperature_Controller_State *ET_stste)
{
	*ET_stste=ENGINEFANOFF;

    if(temp_ptr<40||temp_ptr>60)
    {
    	*ET_stste=ENGINEFANON;
    }
    else
    {
    	*ET_stste=ENGINEFANOFF;
    }

}


/*control AC*/
void control_AC(u8 copy_port,u8 copy_pin,u8 copy_state)
{
DIO_set_pin_direction(copy_port,copy_pin,OUTPUT);
  if (copy_state)
  {
	DIO_set_pin_value(copy_port,copy_pin,HIGH);
  }
  else
  {
	DIO_set_pin_value(copy_port,copy_pin,LOW);
  }
 }



/*control motor fan*/
void control_motor_fan(u8 copy_port,u8 copy_pin,Engine_Temperature_Controller_State copy_state)
{
DIO_set_pin_direction(copy_port,copy_pin,OUTPUT);
	if (copy_state== ENGINEFANON)
	{
		DIO_set_pin_value(copy_port,copy_pin,HIGH);
	}
	else if (copy_state== ENGINEFANOFF)
	{
		DIO_set_pin_value(copy_port,copy_pin,LOW);
	}
	}


/*control car lights*/
void flash()
{

	 led_turn_on_or_off(PORTB,PIN2,1);
}

void turn_off()
{
	led_turn_on_or_off(PORTB,PIN2,0);
}

