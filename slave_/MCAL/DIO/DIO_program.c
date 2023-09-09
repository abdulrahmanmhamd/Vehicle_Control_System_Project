/*
 * program.c
 * Created on: Aug 11, 2023
 * Author: ABDELRAHMAN MOHAMED
 */

/* ------------ INCLUDES ------------*/
#include"C:\Users\User\Desktop\iti\interfasing\grad's project\slave_\LIB\bit_math.h"
#include"C:\Users\User\Desktop\iti\interfasing\grad's project\slave_\LIB\std_types.h"
#include"DIO_private.h"
#include"DIO_interface.h"

/*ARRAY OF DDRS*/
u8 volatile * DDR_ARR[4]= {DIO_U8DDRA ,DIO_U8DDRB,DIO_U8DDRC,DIO_U8DDRD};

/*ARRAY OF PORTS*/
u8 volatile * PORT_AAR[4]= {DIO_U8PORTA,DIO_U8PORTB,DIO_U8PORTC,DIO_U8PORTD};

/*ARRAY OF PORTS*/
u8 volatile *PIN_ARR[4]= {DIO_U8PINA, DIO_U8PINB,DIO_U8PINC,(DIO_U8PINC-3)};






/*port level*/

/* set port direction it input or output */
void DIO_set_port_direction(u8 copy_u8port,u8 copy_u8direction )
{

    if((copy_u8port<=PORTD))
    {
        *DDR_ARR[copy_u8port]=copy_u8direction;
    }
    else
    {
        /* no operation */
    }

}

/* set port pins it all  = 1  or  0 */
void DIO_set_port_value(u8 copy_u8port,u8 copy_u8value )
{
    if((copy_u8port<=PORTD))
    {
        *PORT_AAR[copy_u8port]=copy_u8value;
    }
    else
    {
        /* no operation */
    }

}

/* get value from port*/
void DIO_get_port_value(u8 copy_u8port,u8 *u8value )
{
	if((copy_u8port<=PORTD))
	    {
		*u8value=*PIN_ARR[copy_u8port];
	    }
	    else
	    {
	        /* no operation */
	    }

}



/*4pin level*/

/* set 4 pins direction it input or output */
void DIO_set_4pin_direction(u8 copy_u8port,u8 copy_u8_4pinselection,u8 copy_u8direction )
{
    /* if you want to make 4 pins input and 4 pins output
     * make output first
     */
    if(copy_u8port<=PORTD)
    {
        if(copy_u8direction==OUTPUT)
        {
            if(copy_u8_4pinselection==LOWER)
            {
                *DDR_ARR[copy_u8port]=0x0F;
            }
            else
            {
                *DDR_ARR[copy_u8port]=0xF0;
            }

        }
        else
        {
            *DDR_ARR[copy_u8port]=0x00;
        }

    }
    else
    {
        /* no operation */
    }

}

/* set 4 pins it all  = 1  or  0 */
void DIO_set_4pin_value(u8 copy_u8port,u8 copy_u8_4pinselection,u8 copy_u8value )
{
    if(copy_u8port<=PORTD)
    {
        if(copy_u8_4pinselection==LOWER)
        {
            *PORT_AAR[copy_u8port]=copy_u8value;
        }
        else
        {
            *PORT_AAR[copy_u8port]=copy_u8value;
        }

    }
    else
    {
        /*NO OPERATION*/
    }

}




void DIO_get_4pin_value(u8 copy_u8port,u8 copy_u8_4pinselection,u8 *u8value )
{

	if(copy_u8port<=PORTD)
	    {
	        if(copy_u8_4pinselection==LOWER)
	        {
	        	*u8value=*PIN_ARR[copy_u8port];
	        }
	        else
	        {
	        	*u8value=*PIN_ARR[copy_u8port];
	        }

	    }
	    else
	    {
	        /*NO OPERATION*/
	    }


}



/*pin level*/

/* set bin direction it input or output */
void DIO_set_pin_direction(u8 copy_u8port,u8 copy_u8pin,u8 copy_u8direction )
{

    if((copy_u8port<=PORTD)&&copy_u8pin<=PIN7)
    {
        if(copy_u8direction==OUTPUT)
        {

        	  SET_BIT(*DDR_ARR[copy_u8port],copy_u8pin);
        }
        else
        {
            CLR_BIT(*DDR_ARR[copy_u8port],copy_u8pin);
        }

    }
    else
    {
        /* no operation */
    }

}


/* set pin 1 or 0 */
void DIO_set_pin_value(u8 copy_u8port,u8 copy_u8pin,u8 copy_u8value )
{
    if((copy_u8port<=PORTD)&&copy_u8pin<=PIN7)
    {
        if(copy_u8value==HIGH)
        {
            SET_BIT(*PORT_AAR[copy_u8port],copy_u8pin);
        }
        else
        {
            CLR_BIT(*PORT_AAR[copy_u8port],copy_u8pin);
        }

    }
    else
    {
        /* no operation */
    }

}

/* get value from pin*/
void DIO_get_pin_value(u8 copy_u8port,u8 copy_u8pin,u8 *u8value )
{

    if((copy_u8port<=PORTD)&&copy_u8pin<=PIN7)
    {

    	*u8value =GET_BIT(*PIN_ARR[copy_u8port],copy_u8pin);
    }
    else
    {
        /* no operation */
    }

}

void DIO_tog_pin_value(u8 copy_u8port ,u8 copy_u8pin)
{
	 if((copy_u8port<=PORTD)&&copy_u8pin<=PIN7)
	    {

		DIO_set_pin_direction(copy_u8port,copy_u8pin,OUTPUT);
		TOG_BIT(*PORT_AAR[copy_u8port],copy_u8pin);

	    }
	    else
	    {
	        /* no operation */
	    }
}


