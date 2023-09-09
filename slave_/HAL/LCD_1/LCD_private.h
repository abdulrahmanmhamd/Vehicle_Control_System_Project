/*
 * LCD_private.h
 *
 *  Created on: Aug 14, 2023
 *      Author: User
 */

#ifndef HAL_LCD_1_LCD_PRIVATE_H_
#define HAL_LCD_1_LCD_PRIVATE_H_


/* display clear */
#define DISPLAY_CLEAR 0x01


/*Function set*/
#define LCD_U8_4BIT_BITMODE 0
#define LCD_U8_8BIT_BITMODE 0x10

#define LCD_U8_1_LINE 0
#define LCD_U8_2_LINES 0x08

#define LCD_U8_5x7_FONT 0
#define LCD_U8_5x10_FONT 0x04


/* display on/off */
#define  LCD_U8_ENTIER_DIS_ON 0x04
#define  LCD_U8_ENTIER_DIS_OFF 0

#define LCD_U8_CURSOR_DIS_ON 0x02
#define LCD_U8_CURSOR_DIS_OFF 0

#define LCD_U8_CHAR_INDC_ON 0x01
#define LCD_U8_CHAR_INDC_OFF 0

/* entry mode set */
#define LCD_U8_INC 0x02
#define LCD_U8_DEC 0

#define LCD_U8_SHIFT_ON 0x01
#define LCD_U8_SHIFT_OFF 0


#define RETURN_HOME 0x02

/*OFFSET*/
#define OFFSET 0x80




#endif /* HAL_LCD_1_LCD_PRIVATE_H_ */
