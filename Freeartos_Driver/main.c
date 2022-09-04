/*
 * main.c
 *
 *  Created on: Dec 18, 2021
 *      Author: dell
 */

#include "avr/io.h"
#include "FreeRTOS.h"
#include "semphr.h"
#include "task.h"

#include "LIB/STDTYPES.h"
#include "LIB/BIT_MATH.h"
#include "LIB/CHECK_ERROR.h"
#include "MCAL/PORT_Driver/PORT_REG.h"
#include "MCAL/PORT_Driver/PORT_Config.h"
#include "MCAL/PORT_Driver/PORT_Private.h"
#include "MCAL/PORT_Driver/PORT_Interface.h"
#include "MCAL/DIO_Driver/DIO_REG.h"
#include "MCAL/DIO_Driver/DIO_Interface.h"
#include "HAL/LCD_Module/LCD_Config.h"
#include "HAL/LCD_Module/LCD_Interface.h"

xSemaphoreHandle LCD_SMPHRE;

void Task1(void *PVPARAM);
void Task2(void *PVPARAM);
#define SET_BIT(VAR,BIT)	     ( VAR |=(1 << (BIT)))
#define CLR_BIT(VAR,BIT)	(VAR &=	~(1 << (BIT)))
#define GET_BIT(VAR,BIT)	  (((VAR	>>BIT)	&  1))
#define TOG_BIT(VAR,BIT)	(VAR ^= (1 << (BIT)))


int main(void)
{
	PORT_VoidInit();
	LCD_VoidInit();
	vSemaphoreCreateBinary(LCD_SMPHRE);
	xTaskCreate(Task1,"Red",configMINIMAL_STACK_SIZE,NULL,1,NULL);
	xTaskCreate(Task2,"Green",configMINIMAL_STACK_SIZE,NULL,1,NULL);

	vTaskStartScheduler();
	while(1)
	{

	}
	return 0;
}
void Task1(void *PVPARAM)
{//DDRA|=(1<<0);
	u8 stat=xSemaphoreTake(LCD_SMPHRE,100);
	if(stat==pdPASS)
	{
		LCD_VoidSendString("MEKO");
		xSemaphoreGive(LCD_SMPHRE);

	}


	while (1)
	{


	//	vTaskDelay(10);

	}
}
void Task2(void *PVPARAM)
{	//DDRA|=(1<<1);
	u8 stat=xSemaphoreTake(LCD_SMPHRE,100);
	if(stat==pdPASS)
		{
	 	 LCD_VoidSendString("Doaa");
			xSemaphoreGive(LCD_SMPHRE);

		}
	while (1)
	{

	//	vTaskDelay(10);

	}
}
