/*
 * LCD_program.c
 *
 *  Created on: Aug 14, 2023
 *      Author: User
 */

/* ------------ INCLUDES ------------*/
#include"C:\Users\User\Desktop\iti\interfasing\grad's project\slave_\LIB\bit_math.h"
#include"C:\Users\User\Desktop\iti\interfasing\grad's project\slave_\LIB\std_types.h"
#include"LCD_interface.h"
#include"LCD_private.h"
#include"LCD_config.h"
#include "C:\Users\User\Desktop\iti\interfasing\grad's project\slave_\MCAL\DIO\DIO_interface.h"
#include"util/delay.h"
#include <string.h>


void LCD_Initialization (lcd_config *copy_u8_con)
{
/*set_port_direction for data*/
DIO_set_port_direction(copy_u8_con->data_port,OUTPUT_PORT);

/*set_port_direction for RS*/
DIO_set_pin_direction(copy_u8_con->RS_port,copy_u8_con->RS_pin,OUTPUT);

/*set_port_direction for RW*/
DIO_set_pin_direction(copy_u8_con->RW_port,copy_u8_con->RW_pin,OUTPUT);

/*set_port_direction for ENABLE*/
DIO_set_pin_direction(copy_u8_con->EN_port,copy_u8_con->EN_pin,OUTPUT);

_delay_ms(30);
LCD_u8_write_command (copy_u8_con, FUNCTION_SET);

_delay_ms(1);
LCD_u8_write_command (copy_u8_con, DISPLAY_ON_OFF);

_delay_ms(2);
LCD_u8_write_command (copy_u8_con, DISPLAY_CLEAR);

LCD_u8_write_command (copy_u8_con, ENTRY_MODE_SET);

}


void LCD_u8_write_char (lcd_config *copy_u8_con,u8 charactar)
{
/*reset RS and RW */
	DIO_set_pin_value(copy_u8_con->RS_port,copy_u8_con->RS_pin,HIGH);
	DIO_set_pin_value(copy_u8_con->RW_port,copy_u8_con->RW_pin,LOW);

/*Send data through data port */
	DIO_set_port_value(copy_u8_con->data_port,charactar);

/*Set the (E) pin for a period ( 1ms is working) then reset it. */
	DIO_set_pin_value(copy_u8_con->EN_port,copy_u8_con->EN_pin,HIGH);
	_delay_ms(1);
	DIO_set_pin_value(copy_u8_con->EN_port,copy_u8_con->EN_pin,LOW);
}

void LCD_u8_write_string (lcd_config *copy_u8_con,u8 *string)
{
u8 i = 0;
for(i=0;string[i]!=0;i++)
{
	LCD_u8_write_char (copy_u8_con,string[i]);
}
}



void LCD_u8_write_command (lcd_config *copy_u8_con,u8 command)
{
/*reset RS and RW */
DIO_set_pin_value(copy_u8_con->RS_port,copy_u8_con->RS_pin,LOW);
DIO_set_pin_value(copy_u8_con->RW_port,copy_u8_con->RW_pin,LOW);

/*Send command through data port */
DIO_set_port_value(copy_u8_con->data_port,command);

/*Set the (E) pin for a period ( 1ms is working) then reset it. */
DIO_set_pin_value(copy_u8_con->EN_port,copy_u8_con->EN_pin,HIGH);
_delay_ms(1);
DIO_set_pin_value(copy_u8_con->EN_port,copy_u8_con->EN_pin,LOW);
}



void LCD_u8_clear_display (lcd_config *copy_u8_con)
{
	LCD_u8_write_command (copy_u8_con, DISPLAY_CLEAR);
}

void LCD_u8_set_position  (lcd_config *copy_u8_con,u8 copy_row,u8 copy_col)
{
   LCD_u8_write_command (copy_u8_con, (OFFSET | (copy_col+copy_row)));

}



void LCD_u8_display_shift(lcd_config *copy_u8_con)
{
	LCD_u8_write_command(copy_u8_con,LCD_U8_SHIFT_DISPLAY_LIFT);
}

void LCD_u8_display_right(lcd_config *copy_u8_con)
{
	LCD_u8_write_command(copy_u8_con,LCD_U8_SHIFT_DISPLAY_RIGHT);
}

u8 LCD_u8_convert_char_to_num(u8 input)
{
	return (input+0x30);
}


//void convert_u16_to_string(u16 value, u8 *str){
//
//        memset((u8 *)str, '\0', 4);
//        sprintf(str, "%d", value);
//
//}


//void LCD_Send_f32_Digit(lcd_config* copy_pstConfig , f32 num)
//{
//	u8 dot_point_location = 0;
//	u8 numStr[11] = {0};
//
//	s32 l_intPart = (s32)num;
//	f32 l_floatPart =  num - l_intPart;
//
//	snprintf(numStr , 6 , "%d" , l_intPart);
//
//	while(numStr[dot_point_location] != '\0')
//		++dot_point_location;
//
//	numStr[dot_point_location++] = '.';
//
//
//
//	numStr[dot_point_location++] = ((u32)(l_floatPart * 10) %10) + '0';
//	numStr[dot_point_location] = ((u32)(l_floatPart * 100) %10) + '0';
//
//	LCD_u8_write_string(copy_pstConfig,numStr);
//}
