/****************************************************************************************************************************************/
/***********************************************	Author  : Doaa Mohamed  *************************************************************/
/***********************************************	Date    : 8 March 2022  *************************************************************/
/***********************************************	Version : V3            *************************************************************/
/****************************************************************************************************************************************/

#include "../../LIB/STDTYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/CHECK_ERROR.h"
#include "ADC_Config.h"
#include "ADC_Private.h"
#include "ADC_Interface.h"
#include "ADC_REG.h"

 /*The step of ADC which equal to (Vreferance /(2^Resolution))*/
const f32 Step=4.8828125;

/*Pionter to U16 instead of 16 to access ADCL and ADCH Simutinouslly as ADCH after ADCL direct so we can access them with Pointer to u16 ( ADCL|ADCH>>8 )*/
#define ADC_10_BIT_RESULT (*(volatile u16*)0x24)

/*Global Pointer to function to Set callback function*/
static void(*ADC_VidCallBack_ISR_Funtion)(void)=NULL;

/*Variable to get the reading of ADC*/
static u16*Global_pu16ADC_Reading=NULL;

u8 Global_u8State=IDIL;

void ADC_VoidInit_PreBuild(void)
{
	ADMUX_REG=ADMUX_INITAIL_VALUE;
	ADCSRA_REG=ADCSRA_REG_INITAIL_VALUE;
}

u8 ADC_u8AdjustmentSelect_Postbuild(u8 Copy_u8Justfication)
{
	u8 Local_u8Status=RT_OK;
if(Copy_u8Justfication==LEFT_JUSTFICATION)
	{
	 SetBit(ADMUX_REG,ADLAR);
	}
else if (Copy_u8Justfication==RIGHT_JUSTFICATION)
	{
	 ClearBit(ADMUX_REG,ADLAR);
	}
else
	{
	 Local_u8Status=RT_NOK;
	}

return Local_u8Status;

}

void ADC_VoidVrefSelect_Postbuild(u8 Copy_u8Vref)
{
	u8 Local_u8Temp=ADMUX_REG;
	Local_u8Temp&=SELECT_VREF_MASK;
	Local_u8Temp|=Copy_u8Vref;
	ADMUX_REG=Local_u8Temp;
}

void ADC_VoidPrescalerSelect_Postbuild(enum ADC_PRESACLEERS Copy_u8Prescaler)
{
	u8 Local_u8Temp=ADCSRA_REG;
	Local_u8Temp&=SELECT_PRESCALER_MASK;
	Local_u8Temp|=Copy_u8Prescaler;
	ADCSRA_REG=Local_u8Temp;
}

u8 ADC_u8ONO_OFFStateSelect_Postbuild(u8 Copy_u8ADC_State)
{
	u8 Local_u8Status=RT_OK;

	if(Copy_u8ADC_State==ENABLE)
		{
		 SetBit(ADCSRA_REG,ADEN);
		}
	else if (Copy_u8ADC_State==DISABLE)
		{
		 ClearBit(ADCSRA_REG,ADEN);
		}
	else
		{
		 Local_u8Status=RT_NOK;
		}

	return Local_u8Status;
}

u8 ADC_u8AutoTriggerEnable_Postbuild(u8 Copy_u8ADC_AutoTriggerEnable,u8 Copy_u8TriggerSource)
{
	u8 Local_u8Status=RT_OK;

	if(Copy_u8ADC_AutoTriggerEnable==ENABLE)
		{

		 SetBit(ADCSRA_REG,ADATE);
		 u8 Local_u8Temp=ADCSRA_REG;
		Local_u8Temp&=SELECT_AUTO_TRIGER_SOURSE_MASK;
		Local_u8Temp|=Copy_u8TriggerSource;
		ADCSRA_REG=Local_u8Temp;

		}
	else if (Copy_u8ADC_AutoTriggerEnable==DISABLE)
		{
		 ClearBit(ADCSRA_REG,ADATE);
		}
	else
		{
		 Local_u8Status=RT_NOK;
		}

	return Local_u8Status;
}

u8 ADC_u8GetDigitalValChannel(u8 Copy_u8Channel,u16 *Reading_Channel)
{
	u8 Local_u8Status=RT_OK;

	/*Checking if ADC IDIL and finish Previous Conversion*/
	if(Global_u8State==IDIL)
	{
		/*Making it Buzy as it begun New Conversion */
		Global_u8State=BUZY;

		/*Starting Counter of Time out Mechanism at Zero*/
		u32 Local_u32Counter=0;

		/*Choosing Channel from 8 to start conversion*/
		u8 Local_u8Temp=ADMUX_REG;
		Local_u8Temp&=SELECT_ENDED_CHANNEL_MASK;
		Local_u8Temp|=Copy_u8Channel;
		ADMUX_REG=Local_u8Temp;

		/*Start Conversion Enable bit*/
		SetBit(ADCSRA_REG,ADSC);
		/*Checking if the configuration file.h Set flag of ADC_PIE or Not */
		if(GetBit(ADCSRA_REG,ADIE)==DISABLE)
		{
			while((GetBit(ADCSRA_REG,ADIF)!=1)&&(Local_u32Counter<TIME_OUT_WAITING))
			{
				Local_u32Counter++;
			}
			/*Checking if TIME out is expired or not or return Function status */
			if(Local_u32Counter==TIME_OUT_WAITING)
			{
				/*return error status because the time defined in configuration is out*/
				Local_u8Status=RT_NOK;
			}
		      else
			{
		    	/*Entering here indicate ADC finish its conversion correctly */

		    	/*First thing to clear Flag*/
				SetBit(ADCSRA_REG,ADIF);

				/*Checking on Pointer Allocation*/
				if(Reading_Channel!=NULL)
				{
				/*At Left justification we may return result 8 bit only with error maximum 3 degree difference */
					if(GetBit(ADMUX_REG,ADLAR)==LEFT_JUSTFICATION)
					{
						*Reading_Channel= ADCH_REG;
					}
				/*At Right justification we return result all 10 bit with no error */
					else if (GetBit(ADMUX_REG,ADLAR)==RIGHT_JUSTFICATION)
					{
						*Reading_Channel=ADC_10_BIT_RESULT ;
					}
				/*Return Function state to Idle state as conversion completed*/
					Global_u8State=IDIL;
				}
				else
				{
					Local_u8Status=NULL_POINTER;
				}
			}


		}
	}
	else
	{
		Local_u8Status=BUSY_FUNC;
	}

return Local_u8Status;
}

u8 ADC_u8GetDigitalValChannelAsynchronus(u8 Copy_u8Channel,u16 *Reading_Channel,void(*ADC_Notifications)(void))
{
	u8 Local_u8Status=RT_OK;
	/*Checking if ADC IDIL and finish Previous Conversion*/
	if(Global_u8State==IDIL)
	{
		u8 Local_u8Temp=ADMUX_REG;

			if(Reading_Channel!=NULL||ADC_Notifications!=NULL)
			{
				/*Making it Buzy as it begun New Conversion */
				Global_u8State=BUZY;
				/*Choosing Channel from 8 to start conversion*/
				Local_u8Temp&=SELECT_ENDED_CHANNEL_MASK;
				Local_u8Temp|=Copy_u8Channel;
				ADMUX_REG=Local_u8Temp;

				ADC_VidCallBack_ISR_Funtion=ADC_Notifications;

				/*Make global Pointer has same pointing to Reading channel in main*/
				Global_pu16ADC_Reading=	Reading_Channel;

				/*Open Peripheral interrupt Enable*/
				SetBit(ADCSRA_REG,ADSC);
				SetBit(ADCSRA_REG,ADIE);

			}
			else
			{
				Local_u8Status=NULL_POINTER;
			}

	}
	else
	{
		/*in case Not Entering ISR (Conversion Completed) ,it remain Busy*/
		return BUSY_FUNC;
	}



return Local_u8Status;
}

u8 SendAddress_Callback(void (*ISR_ADC)(void))
{ u8 Local_u8Status=RT_OK;
	if(ISR_ADC!=0)
	{
		ADC_VidCallBack_ISR_Funtion=ISR_ADC;
	}
	else
	{
		return NULL_POINTER;
	}
	return Local_u8Status;

}

void __vector_16 (void) __attribute__((signal));
void __vector_16 (void)
{
	if(GetBit(ADMUX_REG,ADLAR)==LEFT_JUSTFICATION)
	{
		*Global_pu16ADC_Reading= ADCH_REG;
	}
	else if (GetBit(ADMUX_REG,ADLAR)==RIGHT_JUSTFICATION)
	{
		*Global_pu16ADC_Reading=ADC_10_BIT_RESULT ;
	}

	Global_u8State=IDIL;
	ADC_VidCallBack_ISR_Funtion();
	ClearBit(ADCSRA_REG,ADIE);
}






