/* LM35_program.c*/

/* ------------ INCLUDES ------------*/
#include "C:\Users\User\Desktop\iti\interfasing\grad's project\master_\LIB\std_types.h"
#include "C:\Users\User\Desktop\iti\interfasing\grad's project\master_\LIB\bit_math.h"
#include"LM35_interface.h"
#include "C:\Users\User\Desktop\iti\interfasing\grad's project\master_\MCAL\DIO\DIO_interface.h"
#include"C:\Users\User\Desktop\iti\interfasing\grad's project\master_\MCAL\ADC\ADC_interface.h"



u16 read_LM35_value(u8 copy_pin)
{
  u32 copy_retvalue=0;
  DIO_set_pin_direction(PORTA,copy_pin,INPUT);
  ADC_initial();
  ADC_start_convertion(copy_pin ,&copy_retvalue);
  copy_retvalue=(copy_retvalue/2.0)-1;
  return copy_retvalue;
}



