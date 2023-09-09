/*
 * SPI_interface.h
 *
 *  Created on: Aug 25, 2023
 *      Author: User
 */

#ifndef MCAL_SPI_SPI_INTERFACE_H_
#define MCAL_SPI_SPI_INTERFACE_H_

/* ------------ DATA TYPES ------------*/

/*MASTER OR SLAVE*/
typedef enum {
	SPI_MASTER=0,
	SPI_SLAVE

} SPI_MASTER_SLAVE;


/*DATA ORDER*/
typedef enum {
	SPI_DATA_MSB,SPI_DATA_LSB

} SPI_DATA_ORDER;


typedef enum {
	SPI_SCK_4 , SPI_SCK_16 , SPI_SCK_64 , SPI_SCK_128

} SPI_CLOCK_RATE;

typedef struct {

	SPI_MASTER_SLAVE copy_master_slave;
	SPI_DATA_ORDER copy_data_order;
	SPI_CLOCK_RATE copy_clock_rate;

} SPI_CONFIG;

/* ------------ software interface Declaration SPI ------------*/

void SPI_initil(SPI_CONFIG *copy_config);
void SPI_trans_receive(u8 copy_send_data,u8 *copy_receive_data);

#endif /* MCAL_SPI_SPI_INTERFACE_H_ */
