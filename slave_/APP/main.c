 /******************************************************************************
 *
 * File Name: main.c
 *
 *******************************************************************************/
/*-------------------------------------------- SLAVE -----------------------------------------------------------*/

	/*---------------------------INCLUDES----------------------------------*/

#include "C:\Users\User\Desktop\iti\interfasing\grad's project\slave_\LIB\std_types.h"
#include "C:\Users\User\Desktop\iti\interfasing\grad's project\slave_\LIB\bit_math.h"
#include "C:\Users\User\Desktop\iti\interfasing\grad's project\slave_\SERVICE\SER_interface.h"
#include "C:\Users\User\Desktop\iti\interfasing\grad's project\slave_\HAL\LCD_1\LCD_interface.h"
#include "C:\Users\User\Desktop\iti\interfasing\grad's project\slave_\HAL\LED\LED_interface.h"
#include "C:\Users\User\Desktop\iti\interfasing\grad's project\slave_\HAL\_7SEDMENT\_7SSD_interface.h"
#include "C:\Users\User\Desktop\iti\interfasing\grad's project\slave_\HAL\MOTOR\MOTOR_interface.h"
#include <util/delay.h>

/*----------------------------------------- PROGRAM --------------------------------------------------*/
int main(void)
{
/*-----------------Configuration-----------------*/

  /*--LCD Configuration--*/
	lcd_config LCD =
	{
	 .data_port =LCD_PORTC,
	 .RS_port=LCD_PORTB,
	 .RW_port=LCD_PORTB,
	 .EN_port=LCD_PORTB,
	 .RS_pin=LCD_PIN0,
	 .RW_pin=LCD_PIN1,
	 .EN_pin=LCD_PIN2,
	};

  /*--SPI Configuration--*/
	SPI_CONFIG_ SPI_CON=
	{
	 .copy_master_slave_=1,
     .copy_data_order_=1,
	 .copy_clock_rate_=0
    };



	/*----Variables and Arrays----*/
	u8 begin[]=" welcome";
	u8 op1[]=" 1)TURN ON ENGINE";
	u8 op2[]=" 2)TURN OFF ENGINE";
	u8 op3[]=" 3)QUIT THE SYSTEM";
	u8 Turn_choose_1[]=" Turn on";
	u8 Turn_choose_2[]=" Turn off";
	u8 Turn_choose_3[]=" Quit program";
	u8 get_key='\0';
	u8 traffic_count='\0';


	/*---------Pins Control------------*/
	make_pin_IN_or_OUT(PORTB,PIN4,INPUT);
	make_pin_IN_or_OUT(PORTB,PIN5,INPUT);
	make_pin_IN_or_OUT(PORTB,PIN6,INPUT);
	make_pin_IN_or_OUT(PORTB,PIN7,INPUT);
	make_pin_IN_or_OUT(PORTD,PIN5,OUTPUT);




	/*------------Initializations-------------*/
	/*---LCD Initialization---*/
	  LCD_Initialization(&LCD);

	/*---SPI Initialization---*/
	  SPI(&SPI_CON);

	/*--- 7SD Initialization---*/
	  application_intialize(PORTA , _7SDLOWER);

	/*---MOTOR Initialization---*/
	  motor_init();


	/*-----Write welcome on LCD-----*/
	LCD_u8_write_string(&LCD, begin);
	_delay_ms(1000);
	LCD_u8_clear_display(&LCD);


	while(1)
	{

			/*---------option 1----------*/
			LCD_u8_write_string(&LCD,op1);
			_delay_ms(2000);
			LCD_u8_clear_display(&LCD);

			/*---------option 2---------*/
			LCD_u8_write_string(&LCD,op2);
			_delay_ms(2000);
			LCD_u8_clear_display(&LCD);

			/*----------option 3---------*/
			LCD_u8_write_string(&LCD,op3);
			_delay_ms(2000);
			LCD_u8_clear_display(&LCD);

			/*----------receive data----------*/
			SPI_transmiter_receive(NOTHING,&get_key);


	/*-----------------------------------------------ENGINE ON-------------------------------------*/
			if(get_key==Turn_on)
			{
				LCD_u8_write_string(&LCD,Turn_choose_1);
				_delay_ms(1000);
				LCD_u8_clear_display(&LCD);


	/*------------ control motor speed based on traffic light ---------------*/

			/*--make speed = ZERO --*/
				motor_stop();

				/*------------------- RED ON ------------------------*/
				for(traffic_count=RED;traffic_count>STOP;traffic_count--)
				{
					ssd_u8set_number( PORTA, _7SDSET_LOWER,traffic_count);
					led_turn_on_or_off(LED_PORTD,LED_PIN0,TURN_ON );
					_delay_ms(1200);
					if(traffic_count==1)
					{
						ssd_u8set_number( PORTA, _7SDSET_UPPER,zero);
					}

				}
				/*--------------- RED OFF ----------------------*/
				led_turn_on_or_off(LED_PORTD,LED_PIN0,TURN_OFF);



				/*--make speed = MEDIUM_SPEED--*/
				set_speed_right(MEDIUM_SPEED);
				move_forward();

				/*------------------- YELLOW ON ------------------------*/
				for(traffic_count=YELLOW;traffic_count>STOP;traffic_count--)
				{
					ssd_u8set_number( PORTA, _7SDSET_UPPER,traffic_count);
					led_turn_on_or_off(LED_PORTD,LED_PIN1,TURN_ON );
					_delay_ms(1200);
					if(traffic_count==1)
					{
						ssd_u8set_number( PORTA, _7SDSET_UPPER,zero);
					}
				}

				/*----------------- YELLOW OFF ------------------------*/

				led_turn_on_or_off(LED_PORTD,LED_PIN1,TURN_OFF );


				/*make motor move*/
				set_speed_right(MOVE);
				move_forward();

				/*------------------- GREEN ON ------------------------*/

				for(traffic_count=GREEN;traffic_count>STOP;traffic_count--)
				{
					ssd_u8set_number( PORTA, _7SDSET_UPPER,traffic_count);
					led_turn_on_or_off(LED_PORTD,LED_PIN2,TURN_ON);
					_delay_ms(1200);
					if(traffic_count==1)
					{
						ssd_u8set_number( PORTA, _7SDSET_UPPER,zero);

					}
				}

				/*------------------- GREEN OFF ------------------------*/
				led_turn_on_or_off(LED_PORTD,LED_PIN2,TURN_OFF );

				/*make speed = HIGH_SPEED*/
				set_speed_right(HIGH_SPEED);
				move_forward();
			    ssd_u8set_number( PORTA, _7SDSET_UPPER,zero);//for simulation glitch




			}



    /*----------------------------------------------- ENGINE OFF -------------------------------------*/
			else if (get_key==Turn_off )
			{
				LCD_u8_write_string(&LCD,Turn_choose_2);
				_delay_ms(1000);
				LCD_u8_clear_display(&LCD);
				motor_stop();

			}



    /*----------------------------------------------- QUIT PROGRAM -------------------------------------*/

			else if (get_key==Quit_program)
			{
				LCD_u8_write_string(&LCD,Turn_choose_3);
				_delay_ms(1000);
				LCD_u8_clear_display(&LCD);
				ssd_u8set_number( PORTA, _7SDSET_UPPER,zero);
				motor_stop();
				break;
			}

	}// End of while

return 0;

}// End of main
