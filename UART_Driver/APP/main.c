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
#include "../MCAL/PORT_Driver/PORT_Interface.h"
#include "../MCAL/PORT_Driver/PORT_Config.h"
#include "../MCAL/UART_Driver/UART_REG.h"
#include "../MCAL/UART_Driver/UART_Interface.h"
#include "../MCAL/UART_Driver/UART_Config.h"
#include "../MCAL/PORT_Driver/PORT_REG.h"
#include "../MCAL/PORT_Driver/PORT_Interface.h"
#include "../MCAL/PORT_Driver/PORT_Private.h"
#include "../MCAL/PORT_Driver/PORT_Config.h"
#include "../MCAL/DIO_Driver/DIO_REG.h"
#include "../MCAL/DIO_Driver/DIO_Interface.h"
#include "../HAL/LCD_Module/LCD_Interface.h"
#include "../HAL/LCD_Module/LCD_Private.h"
#include "../HAL/LCD_Module/LCD_Config.h"

int main(void)
{


u8 Recieved;
PORT_VoidInit();
LCD_VoidInit();
UART_VoidInit();
//UART_VoidTXSendData('a');


/*Test of Print to debuger*/
//log_print ( "\n");
//log_print ( "Doaa %f Mohamed %d Shafiy %d Mobark  %c  %s \t",-10.64522,-3 , 200 ,'a' ,"Medo");


while(1)
{
	Recieved=UART_u16RXRecieveData();
	//if(Recieved=='s')
	LCD_VoidSendData( Recieved);
	/*if(Recieved =='1')
	{
		//DIO_U8SetPinVal(PORT_D,PIN_7,HIGH);
	}
	else if(Recieved=='0')

	{
		DIO_U8SetPinVal(PORT_D,PIN_7,LOW);
	}*/

}



	return 0;

}

