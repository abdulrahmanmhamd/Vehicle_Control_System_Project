/*
 * KAY_config.h
 *
 *  Created on: Aug 15, 2023
 *      Author: User
 */

#ifndef HAL_KAYPAD_KAY_CONFIG_H_
#define HAL_KAYPAD_KAY_CONFIG_H_

#define KEYPAD_COLOUMN_NUM 4
#define KEYPAD_ROW_NUM    4

/*port selectd */
#define KEYPAD_PORT   KEYPAD_PORTC

/*pins selectd */
#define KEYPAD_ROW0	     KEYPAD_PIN0
#define KEYPAD_ROW1  	 KEYPAD_PIN1
#define KEYPAD_ROW2  	 KEYPAD_PIN2
#define KEYPAD_ROW3  	 KEYPAD_PIN3

#define KEYPAD_COLOUMN0 KEYPAD_PIN4
#define KEYPAD_COLOUMN1 KEYPAD_PIN5
#define KEYPAD_COLOUMN2 KEYPAD_PIN6
#define KEYPAD_COLOUMN3 KEYPAD_PIN7



#define KEYPAD_ARR   {{'c',0,'=','+'},{1,2,3,'-'},{4,5,6,'*'},{7,8,9,0xfd}}


#endif /* HAL_KAYPAD_KAY_CONFIG_H_ */
