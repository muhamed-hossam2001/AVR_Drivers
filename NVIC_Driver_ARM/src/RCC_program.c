
#include "BIT_MATH.h"
#include "STDTYPES.h"
#include "CHECK_ERROR.h"
#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"


u8 RCC_VoidEnablePeriphral(u8 Copy_u8Bus, u8 Copy_u8PrephralId)
{
	u8 Local_u8ErrorStatus=RT_OK;

	if(Copy_u8Bus>2 ||Copy_u8PrephralId>31)
	{
		Local_u8ErrorStatus=RT_NOK;
	}
	else
	{
		switch(Copy_u8Bus)
		{
		case AHB_BUS :{SET_BIT(RCC_AHBENR_REG,Copy_u8PrephralId);break;}
		case ABP1_BUS:{SET_BIT(RCC_APB1ENR_REG,Copy_u8PrephralId);break;}
		case ABP2_BUS:{SET_BIT(RCC_APB2ENR_REG,Copy_u8PrephralId);break;}
		}
	}

	return Local_u8ErrorStatus;
}




u8 RCC_VoidDisablePeriphral(u8 Copy_u8Bus, u8 Copy_u8PrephralId)
{
	u8 Local_u8ErrorStatus=RT_OK;

	if(Copy_u8Bus>2||Copy_u8PrephralId>31)
	{
		Local_u8ErrorStatus=RT_NOK;
	}
	else
	{
		switch(Copy_u8Bus)
		{
		case AHB_BUS :{CLR_BIT(RCC_AHBENR_REG,Copy_u8PrephralId);break;}
		case ABP1_BUS:{CLR_BIT(RCC_APB1ENR_REG,Copy_u8PrephralId);break;}
		case ABP2_BUS:{CLR_BIT(RCC_APB2ENR_REG,Copy_u8PrephralId);break;}
		}
	}

	return Local_u8ErrorStatus;
}



void RCC_voidInit()
{
	/*to select clock system*/
	/*Setting configurations to Intenal clock*/
#if (RCC_CLK_SYSTEM_SELECT==RCC_INTERNAL_SYSTEM_CLK)
	{
		RCC_CFGR_REG&= RCC_SYSTEM_CLK_SELECT_MASK;
		RCC_CFGR_REG|=RCC_INTERNAL_SYSTEM_CLK<<RCC_SYSTEM_CLK_SELECT_SHIFT;
		/*final action is to Power the HSI circuit*/
		SET_BIT(RCC_CR_REG,CR_HSI_ON);

	}

	/*setting CLCK Security system*/
	#if(RCC_CLOCK_SECURITY_SYSTEM==ENABLE)
		{
			SET_BIT(RCC_CR_REG,CR_CSS_ON);
		}
	#else
		{
			CLR_BIT(RCC_CR_REG,CR_CSS_ON);
		}
	#endif


	/*Setting Microcontroller Output Clock */
	RCC_CFGR_REG&= RCC_MCU_CLK_OUT_MASK;
	RCC_CFGR_REG|=RCC_MCU_OUT_SELECT<<RCC_MCU_CLK_OUT_SHIFT;

	/*Setting the precscaller of AHB BUS*/
	RCC_CFGR_REG&=RCC_AHB_CLK_PRESCALLER_MASK;
	RCC_CFGR_REG|= RCC_AHB_PRESCALLER_DIV_SELECT<<RCC_AHB_CLK_PRESCALLER_SHIFT;

	/*Setting the precscaller of ABP1 BUS*/
	RCC_CFGR_REG&=RCC_ABP1_CLK_PRESCALLER_MASK;
	RCC_CFGR_REG|= RCC_ABP1_PRESCALLER_DIV_SELECT<<RCC_ABP1_CLK_PRESCALLER_SHIFT;

	/*Setting the precscaller of ABP2 BUS*/
	RCC_CFGR_REG&=RCC_ABP2_CLK_PRESCALLER_MASK;
	RCC_CFGR_REG|= RCC_ABP2_PRESCALLER_DIV_SELECT<<RCC_ABP2_CLK_PRESCALLER_SHIFT;


	/*Setting configurations to External clock*/
#elif(RCC_CLK_SYSTEM_SELECT==RCC_EXTENAL_SYSTEM_CLK)
	{
		RCC_CFGR_REG&= RCC_SYSTEM_CLK_SELECT_MASK;
	    RCC_CFGR_REG|=RCC_EXTENAL_SYSTEM_CLK<<RCC_SYSTEM_CLK_SELECT_SHIFT;

	    /* to select RC clock or Crystal by using Bypass Circuit*/
	    #if(RCC_EXTERNAL_CLK_SELECT==RCC_CLK_EXTERNAL_RC)
	    {
	    	SET_BIT(RCC_CR_REG,CR_HSE_BYP);
	    }
		#elif(RCC_EXTERNAL_CLK_SELECT==RCC_CLK_EXTERNAL_CRYSTAL)
	    {
	    	CLR_BIT(RCC_CR_REG,CR_HSE_BYP);
	    }
		#endif
	    /*final action is to Power the HSE circuit*/
	    SET_BIT(RCC_CR_REG,CR_HSE_ON);

	}
	/*Setting configurations to PLL Circuit */

#elif (RCC_CLK_SYSTEM_SELECT==RCC_PLL_SYSTEM_CLK)
	{
		/*Setting Clock system as PLL*/
		RCC_CFGR_REG&= RCC_SYSTEM_CLK_SELECT_MASK;
	    RCC_CFGR_REG|=RCC_PLL_SYSTEM_CLK<<RCC_SYSTEM_CLK_SELECT_SHIFT;

	    /*Setting the Multiplication factor of PLL*/
	    RCC_CFGR_REG&=RCC_PLL_CLK_MULTIPLER_MASK ;
	    RCC_CFGR_REG|=RCC_PLL_MUL_SELECT<<RCC_PLL_CLK_MULTIPLER_SHIFT;


		#if(RCC_PLL_CLK_SELECT==RCC_PLL_CLK_HSE)
	    {
	    	/*Setting PLL source as External clock*/
	    	SET_BIT(RCC_CFGR_REG,CFGR_PLL_SRC);

	    	/*Setting External clock as RC or crystal*/
			#if(RCC_EXTERNAL_CLK_SELECT==RCC_CLK_EXTERNAL_RC)
			{
				SET_BIT(RCC_CR_REG,CR_HSE_BYP);
			}
			#elif(RCC_EXTERNAL_CLK_SELECT==RCC_CLK_EXTERNAL_CRYSTAL)
			{
				CLR_BIT(RCC_CR_REG,CR_HSE_BYP);
			}
			#endif

			/*Setting PLL source as External Division by 2 or not*/
			#if  (RCC_PLL_HSE_CLK_SELECT==RCC_PLL_CLK_HSE_DIV_2)
			{
				SET_BIT(RCC_CFGR_REG,CFGR_PLL_XTPRE);
			}
			#elif(RCC_PLL_HSE_CLK_SELECT==RCC_PLL_CLK_HSE_NO_DIV)
			{
				CLR_BIT(RCC_CFGR_REG,CFGR_PLL_XTPRE);
			}
			#endif

			/*final action is to Power the HSE circuit*/
			SET_BIT(RCC_CR_REG,CR_HSE_ON);
	    }
		#elif(RCC_PLL_CLK_SELECT==RCC_PLL_CLK_HSI_DIV_2)
	    {
	    	/*Setting PLL source as Internal clock*/
	    	CLR_BIT(RCC_CFGR_REG,CFGR_PLL_SRC);
	    	/*final action is to Power the HSI circuit*/
	    	SET_BIT(RCC_CR_REG,CR_HSION);
	    }
		#endif


	    /*final action is to Power the PLL circuit*/
	    SET_BIT(RCC_CR_REG,CR_PLL_ON);

	}
#endif





}
