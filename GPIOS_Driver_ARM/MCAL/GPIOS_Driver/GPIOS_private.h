/****************************************************************************************************************************************/
/***********************************************	Author  : Doaa Mohamed  *************************************************************/
/***********************************************	Date    : 2 March 2022  *************************************************************/
/***********************************************	Version : V1            *************************************************************/
/****************************************************************************************************************************************/

#ifndef _GPIOS_PRIVATE_H_
#define _GPIOS_PRIVATE_H_


/*
 * Register Definition
 */

/********************************************************  GPIO and AFIO PORTA Registers ***********************************************/
/***************************************************************************************************************************************/


#define  GPIOS_PORTA_CRL       *((volatile u32*)  0x40010800)
#define  GPIOS_PORTA_CRH       *((volatile u32*)  0x40010804)
#define  GPIOS_PORTA_IDR       *((volatile u32*)  0x40010808)
#define  GPIOS_PORTA_ODR       *((volatile u32*)  0x4001080C)
#define  GPIOS_PORTA_BSRR      *((volatile u32*)  0x40010810)
#define  GPIOS_PORTA_BRR       *((volatile u32*)  0x40010814)
#define  GPIOS_PORTA_LCKR      *((volatile u32*)  0x40010818)



/********************************************************  GPIO and AFIO PORTB Registers *************************************/
/**************************************************************************************************************************************/

#define  GPIOS_PORTB_CRL       *((volatile u32*)  0x40010C00)
#define  GPIOS_PORTB_CRH       *((volatile u32*)  0x40010C04)
#define  GPIOS_PORTB_IDR       *((volatile u32*)  0x40010C08)
#define  GPIOS_PORTB_ODR       *((volatile u32*)  0x40010C0C)
#define  GPIOS_PORTB_BSRR      *((volatile u32*)  0x40010C10)
#define  GPIOS_PORTB_BRR       *((volatile u32*)  0x40010C14)
#define  GPIOS_PORTB_LCKR      *((volatile u32*)  0x40010C18)



/********************************************************  GPIO and AFIO PORTC Registers *************************************/
/**************************************************************************************************************************************/

#define  GPIOS_PORTC_CRL       *((volatile u32*)  0x40011000)
#define  GPIOS_PORTC_CRH       *((volatile u32*)  0x40011004)
#define  GPIOS_PORTC_IDR       *((volatile u32*)  0x40011008)
#define  GPIOS_PORTC_ODR       *((volatile u32*)  0x4001100C)
#define  GPIOS_PORTC_BSRR      *((volatile u32*)  0x40011010)
#define  GPIOS_PORTC_BRR       *((volatile u32*)  0x40011014)
#define  GPIOS_PORTC_LCKR      *((volatile u32*)  0x40011018)






#endif
