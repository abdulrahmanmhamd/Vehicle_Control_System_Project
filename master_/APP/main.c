 /******************************************************************************
 *
 * File Name: main.c
 *
 *******************************************************************************/
/*-------------------------------------------- MASTER -----------------------------------------------------------*/

	/*---------------------------INCLUDES----------------------------------*/

#include "C:\Users\User\Desktop\iti\interfasing\grad's project\master_\LIB\std_types.h"
#include "C:\Users\User\Desktop\iti\interfasing\grad's project\master_\LIB\bit_math.h"
#include "C:\Users\User\Desktop\iti\interfasing\grad's project\master_\HAL\kaypad\KAY_interface.h"
#include "C:\Users\User\Desktop\iti\interfasing\grad's project\master_\SERVICE\SER_interface.h"
#include "C:\Users\User\Desktop\iti\interfasing\grad's project\master_\HAL\LM35\LM35_interface.h"
#include "C:\Users\User\Desktop\iti\interfasing\grad's project\master_\SERVICE\APP_interface.h"
#include "C:\Users\User\Desktop\iti\interfasing\grad's project\master_\HAL\STEPPER\STE_M_interface.h"
#include "util/delay.h"

/*----------------------------------------- PROGRAM --------------------------------------------------*/

int main(void)
{


/*-------Configuration-------*/

	/*--SPI Configuration--*/
	SPI_CONFIG_ SPI_CON=
	{
	 .copy_master_slave_=0,
     .copy_data_order_=1,
	 .copy_clock_rate_=0
    };

	/*--Interrupt 1 Configuration--*/
	EXT_INT_ EXI1 = { .EXT_INT_SC_INT_1_ = EXT_INT_SC_INT_1, .EXT_INT_SC_STATE_1 =
			_EXT_INT_SC_RISING_EDGE};
	EXT_INT_func_ I1 = { .EXT_ISR_INT_1 = &flash};
	INTERRUPT(&EXI1,&I1 );

	/*--Interrupt 0 Configuration--*/
	EXT_INT_ EXI0 = { .EXT_INT_SC_INT_0_ = EXT_INT_SC_INT_0, .EXT_INT_SC_STATE_0 =
			_EXT_INT_SC_FALLING_EDGE};
	EXT_INT_func_ I0 = { .EXT_ISR_INT_0 = &turn_off };
	INTERRUPT(&EXI0,&I0 );


	/*-----------Variables----------*/
	static u8 key =KEYPAD_NOTPRESSED ;
	u8  Receive = '\0';
	u8  AC_controler='\0';
	u8  flag_0=0;
	u8  flag_1=0;
	u16 engine_temp='\0';
	Engine_Temperature_Controller_State fan_state='\0';


	/*---------Pins Control------------*/
	make_pin_IN_or_OUT(PORTB,PIN5,OUTPUT);
	make_pin_IN_or_OUT(PORTB,PIN6,OUTPUT);
	make_pin_IN_or_OUT(PORTB,PIN7,OUTPUT);
	make_pin_IN_or_OUT(PORTD,PIN2,INPUT);
	make_pin_IN_or_OUT(PORTA,PIN0,INPUT);


	/*------------Initializations-------------*/
	/*---KEYPAD Initialization---*/
	KEYPAD_INITIAL();

	/*---SPI Initialization---*/
    SPI(&SPI_CON);

	/*---STEPPER MOTOR Initialization---*/
    STE_M_INITIAL();





while(1)
{

	/*-------------------Get key value-----------------------*/
	 key=KEYPAD_GETKEY();
	 if(key== Turn_on || key== Turn_off || key==Quit_program )
	 {
		 /*--Send key value--*/
		 SPI_transmiter_receive(key,&Receive);

   /*----------------------------------------------- QUIT PROGRAM -------------------------------------*/
		 if (key==Quit_program )
		 {
				 break;
		 }
	 }



	/*--------control engine fan based on engine temperature---------*/
		    engine_temp=read_LM35_value(LM35_PIN1);
			Vehicle_SetupEngineTempController(engine_temp,&fan_state);
			control_motor_fan(PORTD,PIN1,fan_state);


	/*------------------------------control AC ---------------------*/
			get_pin_Value(PORTA,PIN0,&AC_controler);
		    control_AC(PORTD, PIN0,AC_controler);

		    if(AC_controler)
		    {
		    	if(flag_0==0)
		    	{
			    	STE_M_full_step_forward(STE_M_1_STEP);
			    	flag_1++;
			    	flag_0++;
		    	}
		    }
		    else
			{
		     flag_0=0;
				   if(flag_1)
				   {
				    STE_M_full_step_backward(STE_M_1_STEP);
				    flag_1=0;
				   }
			}


	}
return 0;
}









