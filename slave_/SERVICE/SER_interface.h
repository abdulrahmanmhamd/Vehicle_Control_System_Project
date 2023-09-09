 /******************************************************************************
 *
 * File Name: SER_interface.h
 *
 *******************************************************************************/

#ifndef SERVICE_SER_INTERFACE_H_
#define SERVICE_SER_INTERFACE_H_

/* ------------ APP SERVICE ------------*/
/* ------------ Macros Declaration ------------*/
#define NOTHING       0
#define Turn_on       1
#define Turn_off      2
#define Quit_program  3
#define HIGH_SPEED    150
#define MEDIUM_SPEED  30
#define MOVE          70
#define RED           5
#define STOP          0
#define YELLOW        4
#define GREEN         6








/* ------------ DIO SERVICE ------------*/
/* ------------ Macros Declaration ------------*/

/* PORTS*/
#define PORTA 0
#define PORTB 1
#define PORTC 2
#define PORTD 3
#define zero  0


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

/* ------------ DATA TYPES Declaration ------------*/

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


#endif /* SERVICE_SER_INTERFACE_H_ */
