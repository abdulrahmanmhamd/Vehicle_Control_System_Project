/*
 * _7SSD_program.c
 */
/* ------------ INCLUDES ------------*/
#include"C:\Users\User\Desktop\iti\interfasing\grad's project\slave_\LIB\bit_math.h"
#include"C:\Users\User\Desktop\iti\interfasing\grad's project\slave_\LIB\std_types.h"
#include"_7SSD_interface.h"
#include "C:\Users\User\Desktop\iti\interfasing\grad's project\slave_\MCAL\DIO\DIO_interface.h"
#include <util/delay.h>



/*ARRAY OF SEGMANT NUMBERS*/
u8 array_lower_numbers[10]= {0,1,2,3,4,5,6,7,8,9};
u8 array_upper_numbers[10]= {0,0b00010000,0b00100000,0b00110000,0b01000000,0b01010000,0b01100000,0b01110000,0b10000000,0b10010000};

/*should using decoder*/
void application_intialize(u8 copy_u8port,u8 copy_u8_4pinselection)
{
    if(copy_u8_4pinselection==UPPER)
    {

        DIO_set_4pin_direction(copy_u8port,copy_u8_4pinselection,OUTPUT);
    }

    else
    {
        DIO_set_4pin_direction(copy_u8port,copy_u8_4pinselection,OUTPUT);
    }
}

/*write a number on 7SSD */
void ssd_u8set_number(u8 copy_u8port,u8 copy_u8_4pinselection,u8 number)
{

    if(( copy_u8port<=PORTD)&&(number<=max_number))
    {

        if(copy_u8_4pinselection==UPPER)
        {

            DIO_set_4pin_value( copy_u8port, copy_u8_4pinselection, array_upper_numbers[number]);
        }
        else
        {
            DIO_set_4pin_value( copy_u8port,copy_u8_4pinselection,array_lower_numbers[number]);
        }


    }
}


/*display a numbers from 0 to 9 on 7SSD */
void ssd_display_numbers(u8 copy_u8port,u8 copy_u8_4pinselection)
{

    if(( copy_u8port<=PORTD))
    {
        u8 i=0;
        if(copy_u8_4pinselection==UPPER)
        {

            for(i=0; i<10; i++)
            {
                DIO_set_4pin_value( copy_u8port, copy_u8_4pinselection, array_upper_numbers[i]);
                _delay_ms(1000);
            }
        }
        else
        {
            for(i=0; i<10; i++)
            {
                DIO_set_4pin_value( copy_u8port,copy_u8_4pinselection,array_lower_numbers[i]);
                _delay_ms(1000);
            }

        }


    }
}





