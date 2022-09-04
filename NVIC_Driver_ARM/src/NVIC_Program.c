/****************************************************************************************************************************************/
/***********************************************	Author  : Doaa Mohamed  *************************************************************/
/***********************************************	Layer  : MCAL           *************************************************************/
/***********************************************	Date    : 11 March 2022 *************************************************************/
/***********************************************	Version : V1            *************************************************************/
/****************************************************************************************************************************************/
#include "BIT_MATH.h"
#include "CHECK_ERROR.h"
#include "STDTYPES.h"
#include "NVIC_Interface.h"
#include "NVIC_Config.h"
#include "NVIC_Private.h"


void NVIC_VoidInit()
{

	/*
	 * to Setting the Priority Of group and sub Configurations
	 * xxxx    xxxy    xxyy    xyyy    yyyy
	 * where x is the bits of group priority and y is the bits of sub priority
	 */
	SCB_AIRCR_REG=NVIC_GROUP_SUB_CONFIGURATIONS;

	NVIC_ICER0_REG=NVIC_ICER0_INITIAL_VALUE;
	NVIC_ICER1_REG=NVIC_ICER1_INITIAL_VALUE;

	NVIC_ISPR0_REG=NVIC_ISPR0_INITIAL_VALUE;
	NVIC_ISPR1_REG=NVIC_ISPR1_INITIAL_VALUE;

	NVIC_ICPR0_REG=NVIC_ICPR0_INITIAL_VALUE;
	NVIC_ICPR1_REG=NVIC_ICPR0_INITIAL_VALUE;

	NVIC_ISER0_REG=NVIC_ISER0_INITIAL_VALUE;
	NVIC_ISER1_REG=NVIC_ISER1_INITIAL_VALUE;
}

u8 NVIC_u8EnableInterrupt(u8 Copy_u8InterruptNumber)
{
	u8 Local_u8ErrorStatus=RT_OK;

	if(Copy_u8InterruptNumber<32)
	{
		NVIC_ISER0_REG=1<<Copy_u8InterruptNumber;
	}
	else if(Copy_u8InterruptNumber<64)
	{
		Copy_u8InterruptNumber-=32;
		NVIC_ISER1_REG=1<<Copy_u8InterruptNumber;
	}
	else
	{
		Local_u8ErrorStatus=RT_NOK;
	}


	return Local_u8ErrorStatus;
}


u8 NVIC_u8DisableInterrupt(u8 Copy_u8InterruptNumber)
{
	u8 Local_u8ErrorStatus=RT_OK;

	if(Copy_u8InterruptNumber<32)
	{
		NVIC_ICER0_REG=1<<Copy_u8InterruptNumber;
	}
	else if(Copy_u8InterruptNumber<64)
	{
		Copy_u8InterruptNumber-=32;
		NVIC_ICER1_REG=1<<Copy_u8InterruptNumber;
	}
	else
	{
		Local_u8ErrorStatus=RT_NOK;
	}


	return Local_u8ErrorStatus;
}

u8 NVIC_u8EnablePendingFlag(u8 Copy_u8InterruptNumber)
{
	u8 Local_u8ErrorStatus=RT_OK;

	if(Copy_u8InterruptNumber<32)
	{

		NVIC_ISPR0_REG=1<<Copy_u8InterruptNumber;
		//GPIOS_u8SetPinVal(GPIOS_PORTA,PIN_0, GPIOS_HIGH);

	}
	else if(Copy_u8InterruptNumber<64)
	{
		Copy_u8InterruptNumber-=32;
		NVIC_ISPR1_REG=1<<Copy_u8InterruptNumber;
	}
	else
	{
		Local_u8ErrorStatus=RT_NOK;
	}


	return Local_u8ErrorStatus;
}

u8 NVIC_u8DisablePendingFlag(u8 Copy_u8InterruptNumber)
{
	u8 Local_u8ErrorStatus=RT_OK;

	if(Copy_u8InterruptNumber<32)
	{
		NVIC_ICPR0_REG=1<<Copy_u8InterruptNumber;
	}
	else if(Copy_u8InterruptNumber<64)
	{
		Copy_u8InterruptNumber-=32;
		NVIC_ICPR1_REG=1<<Copy_u8InterruptNumber;
	}
	else
	{
		Local_u8ErrorStatus=RT_NOK;
	}


	return Local_u8ErrorStatus;
}


u8 NVIC_u8ReadingActiveFlag(u8 Copy_u8InterruptNumber,u8 *Copy_u8InterruptReadingActive)
{
	u8 Local_u8ErrorStatus=RT_OK;

	if(Copy_u8InterruptNumber<32)
	{
		*Copy_u8InterruptReadingActive=GET_BIT(NVIC_IABR0_REG,Copy_u8InterruptNumber);
	}
	else if(Copy_u8InterruptNumber<64)
	{
		Copy_u8InterruptNumber-=32;
		*Copy_u8InterruptReadingActive=GET_BIT(NVIC_IABR1_REG,Copy_u8InterruptNumber);
	}
	else
	{
		Local_u8ErrorStatus=RT_NOK;
	}


	return Local_u8ErrorStatus;
}
void NVIC_u8SetSoftwarePerority(u8 Copy_u8InterruptNumber_Pos,u8 Copy_u8GroupPeriorty,u8 Copy_SubPeriorty)
{

	/* (Copy_u32PriortyConfigurationSelect-NVIC_PRIORTY_GROUP_16_SUB_NON)                                                this to get which part for Group  priority and part of sub
	 * ((Copy_u32PriortyConfigurationSelect-NVIC_PRIORTY_GROUP_16_SUB_NON)/256)                                          to get it mapped in 4 bits only
	 * (Copy_u8GroupPeriorty>>((Copy_u32PriortyConfigurationSelect-NVIC_PRIORTY_GROUP_16_SUB_NON)/256))                  Putting Group priority in its location in 4 bits
	 * Copy_SubPeriorty|(Copy_u8GroupPeriorty>>((Copy_u32PriortyConfigurationSelect-NVIC_PRIORTY_GROUP_16_SUB_NON)/256)) Putting Sub priority in its location in 4 bits
	 * xxxx    xxxy    xxyy    xyyy    yyyy
	 * where x is the bits of group priority and y is the bits of sub priority
	 */
	u8 Local_u8Periorty=Copy_SubPeriorty|(Copy_u8GroupPeriorty<<((NVIC_GROUP_SUB_CONFIGURATIONS-NVIC_PRIORTY_GROUP_16_SUB_0)/256));

	/*
	 *as first 4 bits in each byte reserved for Interrupt number is reserved so we must write at second 4  bits of byte
	 */
	NVIC_IPR_REG[Copy_u8InterruptNumber_Pos]=Local_u8Periorty<<4;



}
