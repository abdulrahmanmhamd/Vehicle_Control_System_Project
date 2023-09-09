/*
 * SPI_program.c
 *
 *  Created on: Aug 25, 2023
 *  Author: User
 */

/* ------------ INCLUDES ------------*/
#include "C:\Users\User\Desktop\iti\interfasing\grad's project\master_\LIB\std_types.h"
#include "C:\Users\User\Desktop\iti\interfasing\grad's project\master_\LIB\bit_math.h"
#include"SPI_interface.h"
#include"SPI_private.h"
#include"SPI_config.h"
#include "C:\Users\User\Desktop\iti\interfasing\grad's project\master_\MCAL\DIO\DIO_interface.h"



void SPI_initil(SPI_CONFIG *copy_config)
{


	/*choose master or slave*/
	switch (copy_config->copy_master_slave) {
	case SPI_MASTER:
		CLR_BIT(SPI_SPCR_REG, SPI_SPCR_MSTER_BIN);
		break;
	case SPI_SLAVE:
		SET_BIT(SPI_SPCR_REG, SPI_SPCR_MSTER_BIN);
		break;
	}
	/*choose data order*/
	SPI_SPCR_REG|=(copy_config->copy_data_order<<SPI_SPCR_DORD_BIN);

	/*choose clock pol and pha*/
	CLR_BIT( SPI_SPCR_REG , SPI_SPCR_CPOL_BIN);//rising
	SET_BIT(SPI_SPCR_REG , SPI_SPCR_CPHA_BIN );//setup

	/*choose clock rate*/
	SPI_SPCR_REG|=(copy_config->copy_clock_rate);

	/*SPI enable*/
	SET_BIT(SPI_SPCR_REG ,SPI_SPCR_SPE_BIN);

}


void SPI_trans_receive(u8 copy_send_data,u8 *copy_receive_data)
{
	SPI_SPDR_REG=copy_send_data;
	while(GET_BIT(SPI_SPSR_REG ,SPI_SPSR_SPIF_BIN)==0)
		;
	*copy_receive_data=SPI_SPDR_REG;
}
