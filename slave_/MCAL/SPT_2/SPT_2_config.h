/*
 * SPT_2_config.h
 *
 *  Created on: Sep 5, 2023
 *      Author: User
 */

#ifndef MCAL_SPT_2_SPT_2_CONFIG_H_
#define MCAL_SPT_2_SPT_2_CONFIG_H_

/* TCCR0. (0111 1011) 0x
 * Bit 7    FOC0: writing a logical one to the FOC0 bit, an immediate compare match is forced on the Waveform Generation unit.
 * Bit 6,3  WGM01:0:  1 1 Fast PWM
 * Bit 5:4  COM01:0:  1 1 Set OC0 on compare match, clear OC0 at TOP
 * Bit 2:0  CS02:0: Clock Select  0 1 1 clkI/O/64 (From prescaler )
 */

#define Fast_PRESCALER_0    0x00
#define Fast_PRESCALER_1    0x01
#define	Fast_PRESCALER_8    0x02
#define	Fast_PRESCALER_64   0x03
#define	Fast_PRESCALER_256  0x04
#define	Fast_PRESCALER_1024 0x05


#define DISABLE_MODULE_VALUE 		    0x00

#define ZER0_INITIALIZER                0x00
/* Max counts of timer0 is 2^8=255 */
#define TIMER_MAX_VALUE                 255
/* max Percentage Value (100%) */
#define DUTY_CYCLE_MAX_VALUE            100

#endif /* MCAL_SPT_2_SPT_2_CONFIG_H_ */
