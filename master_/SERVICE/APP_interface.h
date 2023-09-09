
 /******************************************************************************
 *
 * File Name:APP_interface.h
 *
 *******************************************************************************/

#ifndef SERVICE_APP_INTERFACE_H_
#define SERVICE_APP_INTERFACE_H_


/*----------- APP SERVICE -----------*/

/* ------------ Macros Declaration ------------*/
#define NOTHING       0
#define Turn_on       1
#define Turn_off      2
#define Quit_program  3


/* ------------ DATA TYPES Declaration ------------*/

/*Air Condition State*/
typedef enum
{
    ACOFF, ACON

} Air_Condion_State;


/*Engine Temperature Controller State*/
typedef enum
{
    ENGINEFANOFF, ENGINEFANON

} Engine_Temperature_Controller_State;



/* ------------ software interface Declaration ------------*/

/*Engine Temperature Controller State*/
void Vehicle_SetupEngineTempController(u8 temp_ptr,Engine_Temperature_Controller_State *ET_stste);

/*control AC*/
void control_AC(u8 copy_port,u8 copy_pin,Air_Condion_State copy_state);

/*control motor fan*/
void control_motor_fan(u8 copy_port,u8 copy_pin,Engine_Temperature_Controller_State copy_state);

/*control car lights*/
void flash();
void turn_off();

#endif /* SERVICE_APP_INTERFACE_H_ */
