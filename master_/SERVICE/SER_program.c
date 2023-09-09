 /******************************************************************************
 *
 * File Name: SER_program.c
 *
 *******************************************************************************/
#include "C:\Users\User\Desktop\iti\interfasing\grad's project\master_\LIB\std_types.h"
#include "C:\Users\User\Desktop\iti\interfasing\grad's project\master_\LIB\bit_math.h"
#include "C:\Users\User\Desktop\iti\interfasing\grad's project\master_\MCAL\DIO\DIO_interface.h"
#include "C:\Users\User\Desktop\iti\interfasing\grad's project\master_\MCAL\SPI\SPI_interface.h"
#include"C:\Users\User\Desktop\iti\interfasing\grad's project\master_\MCAL\interrupts\INT_interface.h"
#include"SER_interface.h"

/* ------------ DIO SERVICE ------------*/

/*pins*/
void make_pin_IN_or_OUT(u8 copy_port,u8 copy_pin,u8 copy_direction)
{

	DIO_set_pin_direction(copy_port ,copy_pin,copy_direction);

}


void make_pin_low_or_high(u8 copy_port,u8 copy_pin,u8 copy_value)
{

	DIO_set_pin_value(copy_port,copy_pin,copy_value);

}

void get_pin_Value(u8 copy_port ,u8 copy_pin,u8 *value )
{

	DIO_get_pin_value(copy_port  ,copy_pin ,value );

}

void tog_pin(u8 copy_port ,u8 copy_pin)
{

	DIO_tog_pin_value(copy_port ,copy_pin);

}
/*ports*/
void make_port_IN_or_OUT(u8 copy_port,u8 copy_direction)
{

	DIO_set_port_direction(copy_port, copy_direction );
}

void make_port_low_or_high(u8 copy_port,u8 copy_value)
{
	 DIO_set_port_value(copy_port ,copy_value);
}



/* ------------ SPI SERVICE ------------*/

void SPI_transmiter_receive(u8 copy_send_Data,u8 *copy_receive_Data)
{
	SPI_trans_receive(copy_send_Data,copy_receive_Data);
}

void SPI(SPI_CONFIG_ *copy_config_)
{
	SPI_initil(copy_config_);
}


/* ------------ INTRRUPT SERVICE ------------*/

void INTERRUPT(EXT_INT_ *copy_inter_, EXT_INT_func_ *copy_func_){

	EXT_INT_initial(copy_inter_,copy_func_);

}


