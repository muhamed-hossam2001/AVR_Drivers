
#include "BIT_MATH.h"
#include "CHECK_ERROR.h"
#include "STDTYPES.h"
#include "PORT_REG.h"
#include "PORT_Interface.h"
#include "PORT_Config.h"
#include "PORT_private.h"
#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"
#include "GPIOS_private.h"
#include "GPIOS_interface.h"
#include "GPIOS_config.h"
#include "NVIC_Private.h"
#include "NVIC_Interface.h"
#include "NVIC_Config.h"
#include "EXTI_Interface.h"
void mama(void);

int main()
{

	RCC_voidInit();
	RCC_VoidEnablePeriphral(ABP2_BUS,APB2ENR_IOPA_EN);
	RCC_VoidEnablePeriphral(ABP2_BUS,0);
	//GPIOS_u8SetPinDir(GPIOS_PORTA,PIN_8,GPIOS_OUTPUT_PUSH_PULL_10MHZ);
	//GPIOS_u8SetPinDir(GPIOS_PORTA,PIN_0,GPIOS_INPUT_PULL_UP_DOWN);
	//GPIOS_u8SetPinVal(GPIOS_PORTA,PIN_0,1);
	PORT_VoidInit();
	EXTI_u8SetCallBackFunc(mama,EXTI_LINE0);
	EXTI_voidInit();

	NVIC_VoidInit();
	//NVIC_u8EnableInterrupt(NVIC_EXTI0_POS);
	//NVIC_u8EnablePendingFlag(NVIC_EXTI0_POS);




	//GPIOS_u8SetPinVal(GPIOS_PORTA,PIN_0, GPIOS_HIGH);
	while(1)
	{
		/*GPIOS_u8SetPin(GPIOS_PORTA,PIN_0);
		for(u16 i=1;i<500;i++)
		{
			for(u16 t=1;t<500;t++)
					{
						asm("NOP");
					}

		}
		GPIOS_u8ClearPin(GPIOS_PORTA,PIN_0);
		for(u16 i=1;i<500;i++)
			{
				for(u16 t=1;t<500;t++)
						{
							asm("NOP");
						}

			}*/

	}
	return 0;
}

void mama(void)
{
	GPIOS_u8SetPinVal(GPIOS_PORTA,PIN_8, GPIOS_HIGH);
}
