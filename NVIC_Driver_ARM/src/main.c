
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

int main()
{

	RCC_voidInit();
	RCC_VoidEnablePeriphral(ABP2_BUS,APB2ENR_IOPA_EN);
	GPIOS_u8SetPinDir(GPIOS_PORTA,PIN_8,GPIOS_OUTPUT_PUSH_PULL_10MHZ);
	//PORT_VoidInit();
	//NVIC_VoidInit();
	NVIC_u8EnableInterrupt(NVIC_EXTI0_POS);
	NVIC_u8EnablePendingFlag(NVIC_EXTI0_POS);




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

void EXTI0_IRQHandler(void)
{
	GPIOS_u8SetPinVal(GPIOS_PORTA,PIN_8, GPIOS_HIGH);


}
