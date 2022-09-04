/*
 * DIO_REG.h
 *
 *  Created on: Sep 17, 2021
 *      Author: dell
 */

#ifndef SPI_REG_H_
#define SPI_REG_H_

/* SPI Control Register*/
#define  SPCR_REG *((volatile u8*)0x2D)

enum SPCR_Reg
{

	SPCR_REG_SPR0_PIN,
	SPCR_REG_SPR1_PIN,
	SPCR_REG_CPHA_PIN,
	SPCR_REG_CPOL_PIN,
	SPCR_REG_MSTR_PIN,
	SPCR_REG_DORD_PIN,
	SPCR_REG_SPE_PIN,
	SPCR_REG_SPIE_PIN,

};

/*===========================================================================================*/

/* SPI Status Register */
#define SPSR_REG *((volatile u8*)0x2E)

enum SPSR_Reg
{
	SPSR_REG_SPI2X_PIN,
	SPSR_REG_WCOL_PIN=6,
	SPSR_REG_SPIF_PIN=7
};

/*===========================================================================================*/

/*SPI Data Register – SPDR */
#define SPDR_REG *((volatile u8*)0x2F)

/*============================================================================================*/
/* Group B Registers */
#define DDRB_REG *((volatile u8*)0x37)
#define PORTB_REG *((volatile u8*)0x38)
#define PINB_REG *((volatile u8*)0x36)




#endif
