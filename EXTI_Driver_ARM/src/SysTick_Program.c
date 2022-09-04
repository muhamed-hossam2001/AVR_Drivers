/****************************************************************************************************************************************/
/***********************************************	Author  : Doaa Mohamed  *************************************************************/
/***********************************************	Layer  : MCAL           *************************************************************/
/***********************************************	Date    : 17 March 2022 *************************************************************/
/***********************************************	Version : V1            *************************************************************/
/****************************************************************************************************************************************/

#include "BIT_MATH.h"
#include "CHECK_ERROR.h"
#include "STDTYPES.h"
#include "SysTick_Interface.h"
#include "SysTick_Private.h"
#include "SysTick_Config.h"



/*Global pointer to function to Set callback function from main to Single Intrval Function*/
void (*Global_PtrToFuncSingleInterval)(void)=NULL;

/*Global pointer to function to Set callback function from main to Peroidic Intrvals Function*/
void (*Global_PtrToFuncPeriodicIntervals)(void)=NULL;

/*to Differentiate between Entering Single Intrval Function and Periodic Intrvals Function */
#define SINGLE_INTERVAL_FUNC      0
#define PERIODIC_INTERVALS_FUNC   1

/*taking gabage initialy*/
u8 Global_u8FunctionFlag=2; /*taking gabage initialy*/

void STK_voidInit()
{
	/*to Enable or disable Systick interrupt choose from these options*/
#if (STK_INTERRUPT_EN_DIS==ENABLE)
	{
		SET_BIT(SYSTICK->CTRL_REG,CTRL_TICKINT);
	}
#else
	{
		CLR_BIT(SYSTICK->CTRL_REG,CTRL_TICKINT);
	}
#endif


	/*To select the clock source of Systick*/
#if (STK_CLOCK_SOURCE_SELECT==STK_CLOCK_SRC_AHB_DIV_8)
	{
		CLR_BIT(SYSTICK->CTRL_REG,CTRL_CLKSOURCE);
	}
#else
	{
		SET_BIT(SYSTICK->CTRL_REG,CTRL_CLKSOURCE);
	}
#endif


}

void STK_voidResetTimer()
{
	/*To Disable The Power of the Systick*/
	CLR_BIT(SYSTICK->CTRL_REG,CTRL_ENABLE);

	SYSTICK->LOAD_REG=0x00000000;

	/*To Enable The Power of the Systick*/
	SET_BIT(SYSTICK->CTRL_REG,CTRL_ENABLE);
}

u8 STK_u8EnableOrDisableInterrupt(u8 Copy_u8Enable_Disable)
{
	u8 Local_u8ErrorStatus=RT_OK;

	if(Copy_u8Enable_Disable==ENABLE)
	{
		 SET_BIT(SYSTICK->CTRL_REG,CTRL_TICKINT);
	}
	else if(Copy_u8Enable_Disable==DISABLE)
	{
		 CLR_BIT(SYSTICK->CTRL_REG,CTRL_TICKINT);
	}
	else
	{
		  Local_u8ErrorStatus=RT_NOK;
	}

	return Local_u8ErrorStatus;

}

u8 STK_u8EnableOrDisablePeriphral(u8 Copy_u8Enable_Disable)
{
	u8 Local_u8ErrorStatus=RT_OK;

	if(Copy_u8Enable_Disable==ENABLE)
	{
		 SET_BIT(SYSTICK->CTRL_REG,CTRL_ENABLE);
	}
	else if(Copy_u8Enable_Disable==DISABLE)
	{
		 CLR_BIT(SYSTICK->CTRL_REG,CTRL_ENABLE);
	}
	else
	{
		 Local_u8ErrorStatus=RT_NOK;
	}

		return Local_u8ErrorStatus;
}

void STK_u8SetReloadValue(u32 Copy_u8RelaodVal)
{
	SYSTICK->LOAD_REG=Copy_u8RelaodVal;
}

 u32 STK_u32ReadingCurrntTimerValue()
{
	 return SYSTICK->VAL_REG;
}

u32 STK_u32ReadingRemainingTimerValue()
{
	 return ( SYSTICK->LOAD_REG - SYSTICK->VAL_REG );
}

void STK_voidSetBusyWait_Synchronous(u32 Copy_u32TicksValue)
{
	/*to disable the Interrupt of Systick */
	CLR_BIT(SYSTICK->CTRL_REG,CTRL_TICKINT);

	/*To Set the Value of Load function*/
	SYSTICK->LOAD_REG=Copy_u32TicksValue;

	/*To Enable The Power of the Systick*/
	SET_BIT(SYSTICK->CTRL_REG,CTRL_ENABLE);

	/*Waiting untile Systick flag raised*/
	while(GET_BIT(SYSTICK->CTRL_REG,CTRL_COUNTFLAG)==0);
}

u8 STK_u8SetIntervalSingle_Asyncrounous(u32 Copy_u32TicksValue,void (*STK_SinglePtrtoFunc)(void))
{
	 u8 Local_u8ErrorStatus=RT_OK;

	if(STK_SinglePtrtoFunc!=NULL)
	{
		Global_PtrToFuncSingleInterval=STK_SinglePtrtoFunc;

		/*to disable the Interrupt of Systick */
		SET_BIT(SYSTICK->CTRL_REG,CTRL_TICKINT);

		/*To Set the Value of Load function*/
		SYSTICK->LOAD_REG=Copy_u32TicksValue;

		/*To Enable The Power of the Systick*/
		SET_BIT(SYSTICK->CTRL_REG,CTRL_ENABLE);

		/*To Indicate that Called Function is Single Interval*/
		Global_u8FunctionFlag=SINGLE_INTERVAL_FUNC;
	}
	else
	{
		Local_u8ErrorStatus=NULL_POINTER;
	}

	return Local_u8ErrorStatus;
}

 u8 STK_u8SetIntervalPeriodic_Asyncrounous(u32 Copy_u32TicksValue,void (*STK_PeriodicPtrtoFunc)(void))
 {
	 u8 Local_u8ErrorStatus=RT_OK;

	if(STK_PeriodicPtrtoFunc!=NULL)
	{
		Global_PtrToFuncPeriodicIntervals=STK_PeriodicPtrtoFunc;

		/*to disable the Interrupt of Systick */
		SET_BIT(SYSTICK->CTRL_REG,CTRL_TICKINT);

		/*To Set the Value of Load function*/
		SYSTICK->LOAD_REG=Copy_u32TicksValue;

		/*To Enable The Power of the Systick*/
		SET_BIT(SYSTICK->CTRL_REG,CTRL_ENABLE);

		/*To Indicate that Called Function is Single Interval*/
		Global_u8FunctionFlag=PERIODIC_INTERVALS_FUNC;
	}
	else
	{
		Local_u8ErrorStatus=NULL_POINTER;
	}

	return Local_u8ErrorStatus;
 }

void STK_voidStopTimer()
{
	/*To Disable The Power of the Systick*/
	CLR_BIT(SYSTICK->CTRL_REG,CTRL_ENABLE);

	SYSTICK->LOAD_REG=0x00000000;
	SYSTICK->VAL_REG =0x00000000;
}


void SysTick_Handler()
{
	if(Global_u8FunctionFlag==PERIODIC_INTERVALS_FUNC)
	{
		Global_PtrToFuncPeriodicIntervals();

	}
	else
	{
		Global_PtrToFuncSingleInterval();
		SYSTICK->LOAD_REG=0x00000000;
		SYSTICK->VAL_REG =0x00000000;
	}
}

