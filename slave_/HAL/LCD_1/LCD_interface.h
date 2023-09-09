/*
 * LCD_interface.h
 *
 *  Created on: Aug 14, 2023
 *      Author: User
 */

#ifndef HAL_LCD_1_LCD_INTERFACE_H_
#define HAL_LCD_1_LCD_INTERFACE_H_


/* ------------ Macros Declaration ------------*/
/* PORTS*/
#define LCD_PORTA 0
#define LCD_PORTB 1
#define LCD_PORTC 2
#define LCD_PORTD 3


/*PINS*/
#define LCD_PIN0 0
#define LCD_PIN1 1
#define LCD_PIN2 2
#define LCD_PIN3 3
#define LCD_PIN4 4
#define LCD_PIN5 5
#define LCD_PIN6 6
#define LCD_PIN7 7



/*ROW*/
#define LCD_ROW_1 0
#define LCD_ROW_2 0x40
/*COL*/
#define LCD_COL_1  0
#define LCD_COL_2  1
#define LCD_COL_3  2
#define LCD_COL_4  3
#define LCD_COL_5  4
#define LCD_COL_6  5
#define LCD_COL_7  6
#define LCD_COL_8  7
#define LCD_COL_9  8
#define LCD_COL_10 9
#define LCD_COL_11 10
#define LCD_COL_12 11
#define LCD_COL_13 12
#define LCD_COL_14 13
#define LCD_COL_15 14
#define LCD_COL_16 15


#define LCD_U8_INC_SHIFT_ON  0x04
#define LCD_U8_INC_SHIFT_OFF 0x05
#define LCD_U8_DEC_SHIFT_ON  0x07
#define LCD_U8_DEC_SHIFT_OFF 0x06
#define LCD_U8_SHIFT_DISPLAY_RIGHT 0x1C
#define LCD_U8_SHIFT_DISPLAY_LIFT 0x18


/* ------------ DATA_TYPES Declaration ------------*/
typedef struct
{
 u8 data_port;
 u8 RS_port;
 u8 RW_port;
 u8 EN_port;
 u8 RW_pin;
 u8 RS_pin;
 u8 EN_pin;

}lcd_config;

/* ------------ software interface Declaration LCD ------------*/
void LCD_Initialization (lcd_config *copy_u8_con);

void LCD_u8_write_char (lcd_config *copy_u8_con,u8 charactar);

void LCD_u8_write_string (lcd_config *copy_u8_con,u8 *string);

void LCD_u8_write_command (lcd_config *copy_u8_con,u8 command);

void LCD_u8_clear_display (lcd_config *copy_u8_con);

void LCD_u8_set_position  (lcd_config *copy_u8_con,u8 copy_row,u8 copy_col);

void LCD_u8_display_shift();

void LCD_u8_display_right();

u8 LCD_u8_convert_char_to_num(u8 input);

void convert_u16_to_string(u16 value, u8 *str);

void LCD_Send_f32_Digit(lcd_config* copy_pstConfig , f32 num);

#endif /* HAL_LCD_1_LCD_INTERFACE_H_ */
