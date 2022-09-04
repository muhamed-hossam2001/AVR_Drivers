/*
 * DIO_Interface.c
 *
 *  Created on: Sep 17, 2021
 *      Author: dell
 */



#include "../../LIB/STDTYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/CHECK_ERROR.h"
#include "Watchdog_Timer_Config.h"
#include "Watchdog_Timer_Interface.h"
#include "Watchdog_Timer_private.h"
#include "Watchdog_Timer_REG.h"

void WDT_VoidInit_Preduild(void)
{
	WDTCR_REG&=WDT_TIME_OUT_SELECT_MASK;
	WDTCR_REG|=WDT_TIME_OUT<<WDT_TIME_OUT_SELECT_SHIFT;

	#if(WDT_INITIAL_STATE==ENABLE)
	{
		SET_BIT(WDTCR_REG,WDTCR_REG_WDE);
	}
	#endif

}

void WDT_voidEnable_Postbuild()
{
	SET_BIT(WDTCR_REG,WDTCR_REG_WDE);
}

void WDT_voidDisable_Postbuild()
{
	WDTCR_REG|=0b00011000;
	CLR_BIT(WDTCR_REG,WDTCR_REG_WDE);
}

void WDT_voidSleepTimeOut_Postbuild(u8 Copy_u8TimeOut)
{
	u8 Local_u8TimeOutTemp=WDTCR_REG;
	Local_u8TimeOutTemp&=WDT_TIME_OUT_SELECT_MASK;
	Local_u8TimeOutTemp|=WDT_TIME_OUT<<WDT_TIME_OUT_SELECT_SHIFT;
	WDTCR_REG=Local_u8TimeOutTemp;
}
