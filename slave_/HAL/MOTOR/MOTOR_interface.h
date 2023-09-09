/*
 * MOTOR_interface.h
 *
 *  Created on: Sep 4, 2023
 *      Author: User
 */

#ifndef HAL_MOTOR_MOTOR_INTERFACE_H_
#define HAL_MOTOR_MOTOR_INTERFACE_H_


/*************************************************
 *  API functions
 *************************************************/
#define PA0 0
#define PA1 1
#define PB0 0
#define PB1 1

void motor_init();
//void set_speed_left (u8);
void set_speed_right(u8 speed);
void move_forward();
//void move_backward();
//void move_right(u8);
void move_left(u8 speed_right);
void motor_stop();

#endif /* HAL_MOTOR_MOTOR_INTERFACE_H_ */
