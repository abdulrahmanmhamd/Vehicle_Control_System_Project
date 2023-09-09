/*
 * LCD_config.h
 *
 *  Created on: Aug 14, 2023
 *      Author: User
 */

#ifndef HAL_LCD_1_LCD_CONFIG_H_
#define HAL_LCD_1_LCD_CONFIG_H_
/*
 *  Function set options
 *                 1-data length (DL)>>DB4  1- 8 bits DL=1
 *                                          2- 4 bits DL=0
 *
 *                 2-no of lines (N)>>DB3   1- 1 line N=0
 *                                          2- 2 lines N=1
 *
 **                3-font        (F)>>DB2   1- 5x7 F=0
 *                                          2- 5x10 F=1
 * */


/*
 *  display on/off options
 *                1-entire display (D)>>DB2   1- on  D=1
 *                                            2- off D=0
 *
 *                2-cursor display (C)>>DB1   1- on  C=1
 *                                            2- off C=0
 *
 **               3-char indicated  (B)>>DB0  1- on  B=1
 *                                            2- off B=0
 * */


/*
 *  entry mode set options
 *                1-INC OR DEC     (I/D)>>DB1   1- lift  I/D=1
 *                                              2- right I/D=0
 *
 *                2-SHIFT          (SH)>>DB0    1- ON  SH=1
 *                                              2- OFF SH=0
 *
 *  if you wont to shift lift   make I/D=LCD_U8_DEC  and SH=ON
 *  if you wont to shift right  make I/D=LCD_U8_DEC  and SH=ON
 *
 *  if you wont to INC in DDRAM make I/D= LCD_U8_INC and SH=OFF
 *  if you wont to DEC in DDRAM make I/D=LCD_U8_DEC  and SH=OFF
 */


/*OPTIONS
*      1-LCD_U8_INC
*      2-LCD_U8_DEC
*/
#define LCD_U8_SHIFT_INC_DEC  LCD_U8_INC



/*OPTIONS
 *      1-LCD_U8_SHIFT_ON
 *      2-LCD_U8_SHIFT_OFF
 */
#define LCD_U8_SHIFT_ON_OFF LCD_U8_SHIFT_OFF

#define ENTRY_MODE_SET (0x04 | LCD_U8_SHIFT_ON_OFF | LCD_U8_SHIFT_INC_DEC)






/*OPTIONS
 *      1-LCD_U8_ENTIER_DIS_ON
 *      2-LCD_U8_ENTIER_DIS_OFF
 */
#define LCD_U8_ENTIER_DIS  LCD_U8_ENTIER_DIS_ON



/*OPTIONS
 *      1-LCD_U8_CURSOR_DIS_ON
 *      2-LCD_U8_CURSOR_DIS_OFF
 */
#define LCD_U8_CURSOR_DIS  LCD_U8_CURSOR_DIS_ON



/*OPTIONS
 *      1-LCD_U8_CHAR_INDC_ON
 *      2-LCD_U8_CHAR_INDC_OFF
 */
#define LCD_U8_CHAR_INDC LCD_U8_CHAR_INDC_OFF

#define DISPLAY_ON_OFF (0x08 | LCD_U8_CHAR_INDC | LCD_U8_CURSOR_DIS | LCD_U8_ENTIER_DIS)





/*OPTIONS
 *      1-LCD_U8_4BIT_BITMODE
 *      2-LCD_U8_8BIT_BITMODE
 */
#define LCD_U8_BITMODE  LCD_U8_8BIT_BITMODE



/*OPTIONS
 *      1-LCD_U8_1_LINE
 *      2-LCD_U8_2_LINES
 */
#define LCD_U8_LINE  LCD_U8_2_LINES



/*OPTIONS
 *      1-LCD_U8_5x7_FONT
 *      2-LCD_U8_5x10_FONT
 */
#define LCD_U8_FONT  LCD_U8_5x7_FONT

#define FUNCTION_SET (0x20 | LCD_U8_LINE | LCD_U8_BITMODE | LCD_U8_FONT)




#endif /* HAL_LCD_1_LCD_CONFIG_H_ */
