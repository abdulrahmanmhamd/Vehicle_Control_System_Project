/*
 * _7SSD_interface.h
 *
 *  Created on: Aug 12, 2023
 *      Author: User
 */

#ifndef HAL__7SEDMENT__7SSD_INTERFACE_H_
#define HAL__7SEDMENT__7SSD_INTERFACE_H_

/* ------------ Macros Declration ------------*/
#define cathod 1

#define max_number 9

/*upper begin from 4 to 7 /lower begin from 0 to 3*/
#define _7SDUPPER 1
#define _7SDLOWER 0

#define _7SDSET_UPPER 0xF0
#define _7SDSET_LOWER 0x0F

/* ------------ DATA TYPES Declration  ------------*/


typedef enum{

	ZERO,one,two,three,four,five,six,seven,eight,nine

}numbers;

/* ------------ software interface Declration DIO ------------*/

/*write a number on 7SSD */
void ssd_u8set_number(u8  copy_u8port,u8 copy_u8_4pinselection,u8 number);


/*intialize port*/
void application_intialize(u8 copy_u8port,u8 copy_u8_4pinselection);


/*display a numbers from 0 to 9 on 7SSD */
void ssd_display_numbers(u8 copy_u8port ,u8 copy_u8_4pinselection);



#endif /* HAL__7SEDMENT__7SSD_INTERFACE_H_ */
