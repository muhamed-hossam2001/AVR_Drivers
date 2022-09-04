	#include "BIT_MATH.h"
#include "STDTYPES.h"
#include "CHECK_ERROR.h"
#include "EXTI_Config.h"
#include "EXTI_Private.h"
#include "EXTI_Interface.h"
#include "GPIOS_private.h"
#include "GPIOS_interface.h"
#include "GPIOS_config.h"

/*Global Pointer To Function to Set Callback function fromm Main*/
static void(* Global_PtrToEXTIFunction[16])(void)={NULL};

void EXTI_voidInit()
{
	EXTI->EXTI_FTSR_REG=EXTI_FTSR_INITIAL_VALUE;
	EXTI->EXTI_RTSR_REG=EXTI_RTSR_INITIAL_VALUE;
	EXTI->EXTI_IMR_REG =EXTI_IMR_INITIAL_VALUE;
}
u8 EXTI_u8InterruptEnableDisable(u8 Copy_u8InterruptLine,u8 Copy_u8InterruptEn_Dis)
{
	u8 Local_u8ErrorStatus=RT_OK;

		if(Copy_u8InterruptEn_Dis==ENABLE)
		{
			SET_BIT(EXTI->EXTI_IMR_REG,Copy_u8InterruptLine);
		}
		else if(Copy_u8InterruptEn_Dis==DISABLE)
		{
			CLR_BIT(EXTI->EXTI_IMR_REG,Copy_u8InterruptLine);
		}
		else
		{
			Local_u8ErrorStatus=RT_NOK;
		}

	return Local_u8ErrorStatus;
}

u8 EXTI_u8InterruptEnableSense(u8 Copy_u8InterruptLine,u8 Copy_u8InterruptSense)
{
	u8 Local_u8ErrorStatus=RT_OK;

	if(Copy_u8InterruptSense>2)
	{
		Local_u8ErrorStatus=RT_NOK;
	}
	else
	{
		switch(Copy_u8InterruptSense)
		{
			case EXTI_RISING_EDGE :{SET_BIT(EXTI->EXTI_RTSR_REG,Copy_u8InterruptLine);break;}
			case EXTI_FALLING_EDGE:{SET_BIT(EXTI->EXTI_FTSR_REG,Copy_u8InterruptLine);break;}
			case EXTI_ON_CHANGE   :{
									SET_BIT(EXTI->EXTI_FTSR_REG,Copy_u8InterruptLine);
									SET_BIT(EXTI->EXTI_RTSR_REG,Copy_u8InterruptLine);
									break;
									}
			default 			  : {Local_u8ErrorStatus=RT_NOK;}
		}
	}


	return Local_u8ErrorStatus;
}


u8 EXTI_u8InterruptDisableSense(u8 Copy_u8InterruptLine,u8 Copy_u8InterruptSense)
{
	u8 Local_u8ErrorStatus=RT_OK;

	if(Copy_u8InterruptSense>2)
	{
		Local_u8ErrorStatus=RT_NOK;
	}
	else
	{
		switch(Copy_u8InterruptSense)
		{
			case EXTI_RISING_EDGE :{CLR_BIT(EXTI->EXTI_RTSR_REG,Copy_u8InterruptLine);break;}
			case EXTI_FALLING_EDGE:{CLR_BIT(EXTI->EXTI_FTSR_REG,Copy_u8InterruptLine);break;}
			case EXTI_ON_CHANGE   :{
									CLR_BIT(EXTI->EXTI_FTSR_REG,Copy_u8InterruptLine);
									CLR_BIT(EXTI->EXTI_RTSR_REG,Copy_u8InterruptLine);
									break;
									}
			default 			  : {Local_u8ErrorStatus=RT_NOK;}
		}
	}


	return Local_u8ErrorStatus;
}

u8  EXTI_u8SettingSoftwareInterrupt(u8 Copy_u8InterruptLine,u8 Copy_u8InterruptEn_Dis)
{
	u8 Local_u8ErrorStatus=RT_OK;

		if(Copy_u8InterruptEn_Dis==ENABLE)
		{
			/*To Ensure that the EXTI is enabled*/
			SET_BIT(EXTI->EXTI_IMR_REG,Copy_u8InterruptLine);

			/*Check if EXTI SWIER Line x is Set to 1 or Not */
			if(GET_BIT(EXTI->EXTI_SWIER_REG,Copy_u8InterruptLine)!=0)
			{
				/*to Clear EXTI SWIER Line x we must Clear the Corresponding to it in Pending flag Register */
				EXTI_u8ClearPendingFlag(Copy_u8InterruptLine);

				/*then You can make Normal Software Interrupt  */
				SET_BIT(EXTI->EXTI_SWIER_REG,Copy_u8InterruptLine);
			}

		}
		else if(Copy_u8InterruptEn_Dis==DISABLE)
		{
			SET_BIT(EXTI->EXTI_PR_REG,Copy_u8InterruptLine);
		}
		else
		{
			Local_u8ErrorStatus=RT_NOK;
		}

	return Local_u8ErrorStatus;
}


u8  EXTI_u8ReddingPendingFlag(u8 Copy_u8InterruptLine)
{
	return GET_BIT(EXTI->EXTI_PR_REG,Copy_u8InterruptLine);
}

void  EXTI_u8ClearPendingFlag(u8 Copy_u8InterruptLine)
{
	/*To Clear Pending Flag we Must Write 1 in it*/
	 SET_BIT(EXTI->EXTI_PR_REG,Copy_u8InterruptLine);
}

u8 EXTI_u8SetCallBackFunc(void (*EXTI_Ptr)(void) ,u8 Copy_u8EXTILine)
{
	u8 Local_u8ErrorStatus=RT_OK;

	if(EXTI_Ptr!=NULL)
	{
		Global_PtrToEXTIFunction[Copy_u8EXTILine]=EXTI_Ptr;

	}
	else
	{
		Local_u8ErrorStatus=RT_NOK;
	}
	return Local_u8ErrorStatus;
}



/*ISR of all EXTI Lines*/

void EXTI0_IRQHandler(void)
{
	Global_PtrToEXTIFunction[0]();

	/*to stop Self Nesting interrupt*/
	EXTI_u8ClearPendingFlag(EXTI_LINE0);
}
void EXTI1_IRQHandler(void)
{
	Global_PtrToEXTIFunction[1]();

	/*to stop Self Nesting interrupt*/
	EXTI_u8ClearPendingFlag(EXTI_LINE1);
}

void EXTI2_IRQHandler(void)
{
	Global_PtrToEXTIFunction[2]();

	/*to stop Self Nesting interrupt*/
	EXTI_u8ClearPendingFlag(EXTI_LINE2);
}

void EXTI3_IRQHandler(void)
{
	Global_PtrToEXTIFunction[3]();

	/*to stop Self Nesting interrupt*/
	EXTI_u8ClearPendingFlag(EXTI_LINE3);
}

void EXTI4_IRQHandler(void)
{
	Global_PtrToEXTIFunction[4]();

	/*to stop Self Nesting interrupt*/
	EXTI_u8ClearPendingFlag(EXTI_LINE4);
}

void EXTI5_IRQHandler(void)
{
	Global_PtrToEXTIFunction[5]();

	/*to stop Self Nesting interrupt*/
	EXTI_u8ClearPendingFlag(EXTI_LINE5);
}

void EXTI6_IRQHandler(void)
{
	Global_PtrToEXTIFunction[6]();

	/*to stop Self Nesting interrupt*/
	EXTI_u8ClearPendingFlag(EXTI_LINE6);
}

void EXTI7_IRQHandler(void)
{
	Global_PtrToEXTIFunction[7]();

	/*to stop Self Nesting interrupt*/
	EXTI_u8ClearPendingFlag(EXTI_LINE7);
}

void EXTI8_IRQHandler(void)
{
	Global_PtrToEXTIFunction[8]();

	/*to stop Self Nesting interrupt*/
	EXTI_u8ClearPendingFlag(EXTI_LINE8);
}

void EXTI9_IRQHandler(void)
{
	Global_PtrToEXTIFunction[9]();

	/*to stop Self Nesting interrupt*/
	EXTI_u8ClearPendingFlag(EXTI_LINE9);
}

void EXTI10_IRQHandler(void)
{
	Global_PtrToEXTIFunction[10]();

	/*to stop Self Nesting interrupt*/
	EXTI_u8ClearPendingFlag(EXTI_LINE10);
}

void EXTI11_IRQHandler(void)
{
	Global_PtrToEXTIFunction[11]();

	/*to stop Self Nesting interrupt*/
	EXTI_u8ClearPendingFlag(EXTI_LINE11);
}

void EXTI12_IRQHandler(void)
{
	Global_PtrToEXTIFunction[12]();

	/*to stop Self Nesting interrupt*/
	EXTI_u8ClearPendingFlag(EXTI_LINE12);
}

void EXTI13_IRQHandler(void)
{
	Global_PtrToEXTIFunction[13]();

	/*to stop Self Nesting interrupt*/
	EXTI_u8ClearPendingFlag(EXTI_LINE13);
}

void EXTI14_IRQHandler(void)
{
	Global_PtrToEXTIFunction[14]();

	/*to stop Self Nesting interrupt*/
	EXTI_u8ClearPendingFlag(EXTI_LINE14);
}

void EXTI15_IRQHandler(void)
{
	Global_PtrToEXTIFunction[15]();

	/*to stop Self Nesting interrupt*/
	EXTI_u8ClearPendingFlag(EXTI_LINE15);
}





