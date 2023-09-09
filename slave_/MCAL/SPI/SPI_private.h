/*
 * SPI_private.h
 *
 *  Created on: Aug 25, 2023
 *      Author: User
 */

#ifndef MCAL_SPI_SPI_PRIVATE_H_
#define MCAL_SPI_SPI_PRIVATE_H_


#define SPI_SPDR_REG (*(volatile u8*)0x02F)

#define SPI_SPSR_REG (*(volatile u8*)0x02E)

/*PINS USED*/
#define SPI_SPSR_SPL2X_BIN 0
#define SPI_SPSR_SPIF_BIN  7

#define SPI_SPCR_REG (*(volatile u8*)0x02D)
/*PINS USED*/
#define SPI_SPCR_SPR0_BIN  0
#define SPI_SPCR_SPR1_BIN  1
#define SPI_SPCR_CPHA_BIN  2
#define SPI_SPCR_CPOL_BIN  3
#define SPI_SPCR_MSTER_BIN 4
#define SPI_SPCR_DORD_BIN  5
#define SPI_SPCR_SPE_BIN   6
#define SPI_SPCR_SPIE_BIN  7

/*data order*/
#define SPI_LSB_DATAORDER 1
#define SPI_MSB_DATAORDER 0

/*slave or master*/
#define SPI_MASTER 0x01
#define SPI_SLAVE 0x00



#define SPI_CPOL_AND_CPHA 0x02  //SETUP FIRST , RISING FRIST

/*clock rate*/
//SPI2X=0
#define SPI_SCK_4   0
#define SPI_SCK_16  1
#define SPI_SCK_64  2
#define SPI_SCK_128 3

#endif /* MCAL_SPI_SPI_PRIVATE_H_ */
