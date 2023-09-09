 /******************************************************************************
 *
 * File Name: SER_interface.h
 *
 *******************************************************************************/

#ifndef SERVICE_SER_INTERFACE_H_
#define SERVICE_SER_INTERFACE_H_

/* ------------ DIO SERVICE ------------*/

/* ------------ Macros Declaration ------------*/

/* PORTS*/
#define PORTA 0
#define PORTB 1
#define PORTC 2
#define PORTD 3


/*PINS*/
#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7

/*I/O*/
#define INPUT 0
#define OUTPUT 1
#define INPUT_PORT 0
#define OUTPUT_PORT 0xFF

/*H/L*/
#define HIGH_PORT 0xFF
#define LOW_PORT 0
#define HIGH_PIN 1
#define LOW_PIN 0



/* ------------ software interface Declaration DIO ------------*/
/*pins*/
void make_pin_IN_or_OUT(u8 copy_port,u8 copy_pin,u8 copy_direction);
void make_pin_low_or_high(u8 copy_port,u8 copy_pin,u8 copy_value);
void get_pin_Value(u8 copy_u8port ,u8 copy_u8pin,u8 *u8value );
void tog_pin(u8 copy_u8port ,u8 copy_u8pin);
/*ports*/
void make_port_IN_or_OUT(u8 copy_port,u8 copy_direction);
void make_port_low_or_high(u8 copy_port,u8 copy_value);




/* ------------ SPI SERVICE ------------*/

/* ------------ DATA TYPES ------------*/

/*MASTER OR SLAVE*/
typedef enum {
	SPI_MASTER_=0,
	SPI_SLAVE_

} SPI_MASTER_SLAVE_;


/*DATA ORDER*/
typedef enum {
	SPI_DATA_MSB_,SPI_DATA_LSB_

} SPI_DATA_ORDER_;


typedef enum {
	SPI_SCK4 , SPI_SCK16 , SPI_SCK64 , SPI_SCK128

} SPI_CLOCK_RATE_;

typedef struct {

	SPI_MASTER_SLAVE_ copy_master_slave_;
	SPI_DATA_ORDER_ copy_data_order_;
	SPI_CLOCK_RATE_ copy_clock_rate_;

} SPI_CONFIG_;

/* ------------ software interface Declaration SPI ------------*/

void SPI_transmiter_receive(u8 copy_send_Data,u8 *copy_receive_Data);
void SPI(SPI_CONFIG_ *copy_config_);




/* ------------ INTRRUPT SERVICE ------------*/


/* ------------ DATA TYPES ------------*/

/*func to ptr to save ISR*/
typedef struct {
	FUNC_PTR EXT_ISR_INT_0;
	FUNC_PTR EXT_ISR_INT_1;
	FUNC_PTR EXT_ISR_INT_2;
} EXT_INT_func_;

/*struct to save data from user*/
typedef struct {
	u8 EXT_INT_SC_INT_0_;
	u8 EXT_INT_SC_INT_1_;
	u8 EXT_INT_SC_INT_2_;
	u8 EXT_INT_SC_STATE_0;
	u8 EXT_INT_SC_STATE_1;
	u8 EXT_INT_SC_STATE_2;

} EXT_INT_;

/* ------------ Macros Declaration ------------*/

/*FOR INT1 AND INT0*/
#define _EXT_INT_SC_LOW_LEVEL     0x00
#define _EXT_INT_SC_ANY_CHANGE    0x01
#define _EXT_INT_SC_FALLING_EDGE  0x02
#define _EXT_INT_SC_RISING_EDGE   0x03
#define _EXT_INT_SC_DISABLE       0xFF

/*FOR INT2*/
#define _EXT_INT2_SC_FALLING_EDGE 0x00
#define _EXT_INT2_SC_RISING_EDGE  0x40


#define EXT_INT_SC_INT_0 0
#define EXT_INT_SC_INT_1 1
#define EXT_INT_SC_INT_2 2

/* ------------ software interface Declaration ------------*/
void INTERRUPT(EXT_INT_ *copy_inter_, EXT_INT_func_ *copy_func_);

#endif /* SERVICE_SER_INTERFACE_H_ */
