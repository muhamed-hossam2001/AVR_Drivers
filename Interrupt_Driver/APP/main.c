/*
 * main.c
 *
 *  Created on: Sep 28, 2021
 *      Author: dell
 */
#include"util/delay.h"
#include "../LIB/STDTYPES.h"
#include "../LIB/BIT_MATH.h"
#include "../LIB/CHECK_ERROR.h"
#include "../MCAL/PORT_Driver/PORT_REG.h"
#include "../MCAL/PORT_Driver/PORT_Config.h"
#include "../MCAL/PORT_Driver/PORT_Private.h"
#include "../MCAL/PORT_Driver/PORT_Interface.h"
#include "../MCAL/DIO_Driver/DIO_REG.h"
#include "../MCAL/DIO_Driver/DIO_Interface.h"
#include "../MCAL/External_Interrupt_Driver/External_Interrupt_REG.h"
#include "../MCAL/External_Interrupt_Driver/External_Interrupt_Interface.h"
#include "../MCAL/External_Interrupt_Driver/External_Interrupt_Config.h"
#include "../MCAL/GIE_Driver/GIE_REG.h"
#include "../MCAL/GIE_Driver/GIE_Interface.h"





void INT0_INTERRUPT(void);

int main(void)
{

	PORT_VoidInit();
	SendAddress_Callback(INT0_INTERRUPT,0);
    EXTI_VidEnableOrDisableGIE(ENABLE);
    EXTI_voidEnableOrDisableInterruptPin_Prebuild();
    EXTI_VidControlSense_Prebuild();


	while(1)
	{

	}

	return 0;

}

void INT0_INTERRUPT()
{
	PORTA_REG^= (1 << 0);
}




