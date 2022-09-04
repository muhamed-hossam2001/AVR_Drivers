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
#include "../MCAL/ADC_Driver/ADC_Interface.h"
#include "../MCAL/ADC_Driver/ADC_Config.h"
#include "../MCAL/ADC_Driver/ADC_Private.h"
//#include "../MCAL/GIE_Driver/GIE_REG.h"
//#include "../MCAL/GIE_Driver/GIE_Interface.h"
#include "../HAL/LCD_Module/LCD_Config.h"
#include "../HAL/LCD_Module/LCD_Interface.h"
#include "../HAL/Keypad_Module/Keypad_Config.h"
#include "../HAL/Keypad_Module/Keypad_Interface.h"
#include "../HAL/LM35_Module/LM35_Interface.h"
#include "../HAL/LED_Module/LED_Interface.h"

void INT17_INTERRUPT();
u8 Local_u8KeyPressed;
static u32 Global_u8SetTemp=0;

#define MAX_SIZE 3
s8 top=-1;
u8 item[MAX_SIZE];
void push(u8 Element);
void pop(void);
u32 power(u32 a, u32 b);
u16 Global_u16Temp=0;
u16 Global_u16LDR_Measure=0;
int main(void)
{
	PORT_VoidInit();
	LCD_VoidInit();
	LM35_VoidInit();
    SendAddress_Callback(INT17_INTERRUPT);


	while(1)
	{



		LCD_VoidSendString("1-Automatic");
		LCD_VoidGoToPos(1,0);
		LCD_VoidSendString("2-Manual");

		do
		{
			Local_u8KeyPressed=Keypad_u8GetPressedKey();
		}while(Local_u8KeyPressed==TR_NOT_PRESSED);

		if(Local_u8KeyPressed=='1')
		 {
			do{
				    LCD_VoidClearDisplay();
					ADC_u8GetDigitalValChannel(SINGLE_ENDED_CHANNEL_ADC1,&Global_u16Temp);
					LCD_VoidSendString("Temprature=");
					LCD_VoidSendNumber(LM35_u16GetTempretureWithUnit(Global_u16Temp,Celsuis_Degree));
					_delay_ms(100);
					if(LM35_u16GetTempretureWithUnit(Global_u16Temp,Celsuis_Degree)>=30)
					{
						 DC_MOTOR_VidRotateClockWise();
					}
					else
					{
						DC_MOTOR_VidStop();
					}
					ADC_u8GetDigitalValChannel(SINGLE_ENDED_CHANNEL_ADC2,&Global_u16LDR_Measure);
					if(Global_u16Temp<=20)
					{
						 LED_U8ON_OFF(PORTB,LED0,LED_ON);
						 LED_U8ON_OFF(PORTB,LED1,LED_ON);
						 LED_U8ON_OFF(PORTB,LED2,LED_ON);
						 LED_U8ON_OFF(PORTB,LED3,LED_ON);
						 LED_U8ON_OFF(PORTB,LED4,LED_ON);
						 LED_U8ON_OFF(PORTB,LED5,LED_ON);
						 LED_U8ON_OFF(PORTB,LED6,LED_ON);
						 LED_U8ON_OFF(PORTB,LED7,LED_ON);


					}

					else if(Global_u16Temp>20&&Global_u16Temp<=131)
					{
						LED_U8ON_OFF(PORTB,LED0,LED_ON);
						LED_U8ON_OFF(PORTB,LED1,LED_ON);
					    LED_U8ON_OFF(PORTB,LED2,LED_ON);
					    LED_U8ON_OFF(PORTB,LED3,LED_ON);
					    LED_U8ON_OFF(PORTB,LED4,LED_ON);
					    LED_U8ON_OFF(PORTB,LED5,LED_ON);
					    LED_U8ON_OFF(PORTB,LED6,LED_ON);
					    LED_U8ON_OFF(PORTB,LED7,LED_OFF);
					}
					else if(Global_u16Temp>131&&Global_u16Temp<=252)
							{
							LED_U8ON_OFF(PORTB,LED0,LED_ON);
							LED_U8ON_OFF(PORTB,LED1,LED_ON);
						    LED_U8ON_OFF(PORTB,LED2,LED_ON);
						    LED_U8ON_OFF(PORTB,LED3,LED_ON);
						    LED_U8ON_OFF(PORTB,LED4,LED_ON);
						    LED_U8ON_OFF(PORTB,LED5,LED_ON);
						    LED_U8ON_OFF(PORTB,LED6,LED_OFF);
						    LED_U8ON_OFF(PORTB,LED7,LED_OFF);
							}
					else if(Global_u16Temp>252&&Global_u16Temp<=373)
									{
							LED_U8ON_OFF(PORTB,LED0,LED_ON);
							LED_U8ON_OFF(PORTB,LED1,LED_ON);
							LED_U8ON_OFF(PORTB,LED2,LED_ON);
							LED_U8ON_OFF(PORTB,LED3,LED_ON);
							LED_U8ON_OFF(PORTB,LED4,LED_ON);
							LED_U8ON_OFF(PORTB,LED5,LED_OFF);
							LED_U8ON_OFF(PORTB,LED6,LED_OFF);
							LED_U8ON_OFF(PORTB,LED7,LED_OFF);
									}
					else if(Global_u16Temp>373&&Global_u16Temp<=494)
									{
									LED_U8ON_OFF(PORTB,LED0,LED_ON);
									LED_U8ON_OFF(PORTB,LED1,LED_ON);
								 LED_U8ON_OFF(PORTB,LED2,LED_ON);
								 LED_U8ON_OFF(PORTB,LED3,LED_ON);
								 LED_U8ON_OFF(PORTB,LED4,LED_OFF);
								 LED_U8ON_OFF(PORTB,LED5,LED_OFF);
								 LED_U8ON_OFF(PORTB,LED6,LED_OFF);
								 LED_U8ON_OFF(PORTB,LED7,LED_OFF);
									}
					else if(Global_u16Temp>494&&Global_u16Temp<=615)
									{
									LED_U8ON_OFF(PORTB,LED0,LED_ON);
									LED_U8ON_OFF(PORTB,LED1,LED_ON);
									 LED_U8ON_OFF(PORTB,LED2,LED_ON);
									 LED_U8ON_OFF(PORTB,LED3,LED_OFF);
									 LED_U8ON_OFF(PORTB,LED4,LED_OFF);
									 LED_U8ON_OFF(PORTB,LED5,LED_OFF);
									 LED_U8ON_OFF(PORTB,LED6,LED_OFF);
									 LED_U8ON_OFF(PORTB,LED7,LED_OFF);
									}
					else if(Global_u16Temp>615&&Global_u16Temp<=736)
									{
									LED_U8ON_OFF(PORTB,LED0,LED_ON);
									LED_U8ON_OFF(PORTB,LED1,LED_ON);
									 LED_U8ON_OFF(PORTB,LED2,LED_OFF);
									 LED_U8ON_OFF(PORTB,LED3,LED_OFF);
									 LED_U8ON_OFF(PORTB,LED4,LED_OFF);
									 LED_U8ON_OFF(PORTB,LED5,LED_OFF);
									 LED_U8ON_OFF(PORTB,LED6,LED_OFF);
									 LED_U8ON_OFF(PORTB,LED7,LED_OFF);
									}
					else if(Global_u16Temp>857&&Global_u16Temp<=978)
									{
									LED_U8ON_OFF(PORTB,LED0,LED_ON);
									LED_U8ON_OFF(PORTB,LED1,LED_OFF);
								    LED_U8ON_OFF(PORTB,LED2,LED_OFF);
								    LED_U8ON_OFF(PORTB,LED3,LED_OFF);
								    LED_U8ON_OFF(PORTB,LED4,LED_OFF);
								    LED_U8ON_OFF(PORTB,LED5,LED_OFF);
								    LED_U8ON_OFF(PORTB,LED6,LED_OFF);
								    LED_U8ON_OFF(PORTB,LED7,LED_OFF);
									}
			Local_u8KeyPressed=Keypad_u8GetPressedKey();
			}while(Local_u8KeyPressed==TR_NOT_PRESSED);


		 }
		else if(Local_u8KeyPressed=='2')
	  {

			do
			{
				LCD_VoidClearDisplay();
				LCD_VoidSendString("1-Light System");
				LCD_VoidGoToPos(1,0);
				LCD_VoidSendString("2-Temp System");
				Local_u8KeyPressed=Keypad_u8GetPressedKey();




			if(Local_u8KeyPressed=='1')
			{
				LCD_VoidClearDisplay();
				LCD_VoidSendString("1-LED_ON");
				LCD_VoidGoToPos(1,0);
				LCD_VoidSendString("2-LED_OFF");
				do
				{

				Local_u8KeyPressed=Keypad_u8GetPressedKey();
				switch(Local_u8KeyPressed)

				{
				case '1':{LED_U8ON_OFF(PORTB,LED0,LED_ON);break;}
				case '2':{LED_U8ON_OFF(PORTB,LED0,LED_OFF);break;}
				}
				}while((Local_u8KeyPressed==TR_NOT_PRESSED||Local_u8KeyPressed=='1'||Local_u8KeyPressed=='2')&&Local_u8KeyPressed!='r');


			}
			else if(Local_u8KeyPressed=='2')
			{
				LCD_VoidClearDisplay();
				LCD_VoidSendString("1-SetTemp");
				LCD_VoidGoToPos(1,0);
				LCD_VoidSendString("2-Change Temp");
				do
				{
					Local_u8KeyPressed=Keypad_u8GetPressedKey();
				}while(Local_u8KeyPressed==TR_NOT_PRESSED);

					switch(Local_u8KeyPressed)

				{
					case '1':
					{
						LCD_VoidClearDisplay();
						LCD_VoidSendString("Enter Temp,Please!");
						u8 i=0;
						_delay_ms(1000);
						LCD_VoidClearDisplay();

						while(i<=2)
						{
								do
								{
								Local_u8KeyPressed=Keypad_u8GetPressedKey();
								}while(Local_u8KeyPressed==TR_NOT_PRESSED);

								LCD_VoidSendData(Local_u8KeyPressed);
								push(Local_u8KeyPressed-'0');
						        i++;
						}
						u8 Local_u8Counter=0;
						for(u32 l=power(10,top);l>=1;l/=10)
						{
							Global_u8SetTemp+=item[Local_u8Counter++]*l;
						}

						LCD_VoidSendNumber(Global_u8SetTemp);
						_delay_ms(1000);
						break;
					}
					case '2':
					{
						LCD_VoidClearDisplay();
						LCD_VoidSendString("1-Increment");
						LCD_VoidGoToPos(1,0);
						LCD_VoidSendString("2-Decrement");

						do
						{
								Local_u8KeyPressed=Keypad_u8GetPressedKey();
								switch(Local_u8KeyPressed)
								{
									case '1':{
										 LCD_VoidClearDisplay();
										ADC_u8GetDigitalValChannel(SINGLE_ENDED_CHANNEL_ADC1,&Global_u16Temp);
										LCD_VoidSendString("Temprature=");
										++Global_u16Temp;
									LCD_VoidSendNumber(LM35_u16GetTempretureWithUnit(Global_u16Temp,Celsuis_Degree));
									LCD_VoidSendString(" c");

									break;
									}
									case '2':{
										 LCD_VoidClearDisplay();
										ADC_u8GetDigitalValChannel(SINGLE_ENDED_CHANNEL_ADC1,&Global_u16Temp);
										LCD_VoidSendString("Temprature=");
										--Global_u16Temp;
										LCD_VoidSendNumber(LM35_u16GetTempretureWithUnit(Global_u16Temp,Celsuis_Degree));
										LCD_VoidSendString(" c");

										break;
									}
								}
						}while((Local_u8KeyPressed==TR_NOT_PRESSED||Local_u8KeyPressed=='1'||Local_u8KeyPressed=='2')&&Local_u8KeyPressed!='r');
						break;

					}
				}

		 }




			Local_u8KeyPressed=Keypad_u8GetPressedKey();

			}while(Local_u8KeyPressed==TR_NOT_PRESSED&&Local_u8KeyPressed!='r');



		}


	}


	return 0;

}






u32 power(u32 a, u32 b)
{   if(b==0)
	return 1;
      for (u8 i=1; i<b; i++)
            a *=a;
      return a;
}
u8 isEmpty()
{
	return top < 0;
}

void push(u8 Element)
{
	if (top >= MAX_SIZE-1)
	{
		LCD_VoidSendString("Stack Full");
	}
	else
	{
		top++;
		item[top] = Element;
	}
}
void pop()
{
	if (isEmpty())
		LCD_VoidSendString("No Data deleted");
	else
		top--;
}

void INT17_INTERRUPT()
{
	PORTA_REG^=(1<<0);
}
