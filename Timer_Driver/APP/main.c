//#include"avr/io.h"
//#include"avr/interrupt.h"
/*
#include"avr/io.h"
#include"avr/interrupt.h"
#include "../LIB/BIT_MATH.h"
#include"util/delay.h"


#define Angle_0_tickis 400
#define Angle_180_tickis 2600
void main(void)
{
  unsigned short int angle_tickes;
DDRD|=(1<<5);
TCCR1A|=(1<<COM1A1);
TCCR1A&=~(1<<WGM10);
TCCR1A|=(1<<WGM11);
TCCR1B|=(1<<WGM12)|(1<<WGM13);

TCCR1B|=(1<<CS11);
ICR1=20000;


while (1)
{
for( angle_tickes=Angle_0_tickis;angle_tickes<Angle_180_tickis;angle_tickes+=10)
{
  OCR1A=angle_tickes;
  _delay_ms(40);
}


for( angle_tickes=Angle_180_tickis;angle_tickes>Angle_0_tickis;angle_tickes-=10)
{
  OCR1A=angle_tickes;
  _delay_ms(40);
}

}

}*/

/*================================================================================CTC_Delay=================================*/
/*
#include"util/delay.h"
#include "../LIB/STDTYPES.h"
#include "../LIB/BIT_MATH.h"
#include "../LIB/CHECK_ERROR.h"
#include "../MCAL/PORT_Driver/PORT_REG.h"
#include "../MCAL/PORT_Driver/PORT_Private.h"
#include "../MCAL/PORT_Driver/PORT_Interface.h"
#include "../MCAL/PORT_Driver/PORT_Config.h"
//#include "../MCAL/External_Interrupt_Driver/External_Interrupt_Interface.h"
//#include "../MCAL/External_Interrupt_Driver/External_Interrupt_Config.h"
#include "../MCAL/DIO_Driver/DIO_REG.h"
#include "../MCAL/DIO_Driver/DIO_Interface.h"
#include "../MCAL/GIE_Driver/GIE_REG.h"
#include "../MCAL/GIE_Driver/GIE_Interface.h"
//#include "../HAL/LCD_Module/LCD_Config.h"
//#include "../HAL/LCD_Module/LCD_Interface.h"
#include "../MCAL/Timer_Driver/Timer_REG.h"
#include "../MCAL/Timer_Driver/Timer_Interface.h"
#include "../MCAL/Timer_Driver/Timer_Private.h"
#include "../MCAL/Timer_Driver/Timer_Config.h"

void ISR_TIM1CTC(void)
{
	static u32 counter=0;
	static u8 State=0;

	counter++;
	if(counter==4000)
	{
		TOG_BIT(State,0);
		DIO_U8SetPinVal(PORT_B,PIN_1,State);

		counter=0;

	}

}

#define FIRST_RISING   0
#define RISING_2       1
#define FALLING_2      2

u16 Period_Time_Ticks;
u16 Ton_Time_Ticks;

int main(void)
{
PORT_VoidInit();
//LCD_VoidInit();
//TMR1_VoidInit_Prebuild();
EXTI_VidEnableOrDisableGIE(ENABLE);
TMR0_VoidInit_Prebuild();
//SendAddressTimer_Callback(&ISR_TIM1CTC,1);

TMR0_VoidSetPreLoadValue(250);
EXTI_u8INT0SetCallback(ISR_TIM1CTC);

while (1)
{




}





return 0;

}
*/
/*================================================================================PWM_Led_dutycycle 25%,20ms=================================*/
/*
#include"util/delay.h"
#include "../LIB/STDTYPES.h"
#include "../LIB/BIT_MATH.h"
#include "../LIB/CHECK_ERROR.h"
#include "../MCAL/PORT_Driver/PORT_REG.h"
#include "../MCAL/PORT_Driver/PORT_Private.h"
#include "../MCAL/PORT_Driver/PORT_Interface.h"
#include "../MCAL/PORT_Driver/PORT_Config.h"
//#include "../MCAL/External_Interrupt_Driver/External_Interrupt_Interface.h"
//#include "../MCAL/External_Interrupt_Driver/External_Interrupt_Config.h"
#include "../MCAL/DIO_Driver/DIO_REG.h"
#include "../MCAL/DIO_Driver/DIO_Interface.h"
#include "../MCAL/GIE_Driver/GIE_REG.h"
#include "../MCAL/GIE_Driver/GIE_Interface.h"
//#include "../HAL/LCD_Module/LCD_Config.h"
//#include "../HAL/LCD_Module/LCD_Interface.h"
#include "../MCAL/Timer_Driver/Timer_REG.h"
#include "../MCAL/Timer_Driver/Timer_Interface.h"
#include "../MCAL/Timer_Driver/Timer_Private.h"
#include "../MCAL/Timer_Driver/Timer_Config.h"

void __vector_10(void) __attribute__((signal));
void __vector_10(void)
{
	static u32 counter=0;
	counter++;
	if(counter==5)
	{
		DIO_U8SetPinVal(PORT_B,PIN_1,LOW);
	}
	if(counter==20)
	{
		DIO_U8SetPinVal(PORT_B,PIN_1,HIGH);
		counter=0;
	}

}

#define FIRST_RISING   0
#define RISING_2       1
#define FALLING_2      2

u16 Period_Time_Ticks;
u16 Ton_Time_Ticks;

int main(void)
{
PORT_VoidInit();
//LCD_VoidInit();
//TMR1_VoidInit_Prebuild();
EXTI_VidEnableOrDisableGIE(ENABLE);
TMR0_VoidInit_Prebuild();
//SendAddressTimer_Callback(&ISR_TIM1CTC,1);

//TMR0_VoidSetPreLoadValue(125);
//DIO_U8SetPinVal(PORT_B,PIN_1,HIGH);
//EXTI_u8INT0SetCallback(ISR_TIM1CTC);

while (1)
{

for(u8 i=0;i<255;i++)
{
	TMR0_VoidSetPreLoadValue(i);
	_delay_ms(5);
}
for(u8 i=255;i>0;i--)
{
	TMR0_VoidSetPreLoadValue(i);
	_delay_ms(5);
}


}





return 0;

}
*/

/*================================================================================PWM_Led_Servomotor_Timer1_20mswith =================================*/
/*
#include"util/delay.h"
#include "../LIB/STDTYPES.h"
#include "../LIB/BIT_MATH.h"
#include "../LIB/CHECK_ERROR.h"
#include "../MCAL/PORT_Driver/PORT_REG.h"
#include "../MCAL/PORT_Driver/PORT_Private.h"
#include "../MCAL/PORT_Driver/PORT_Interface.h"
#include "../MCAL/PORT_Driver/PORT_Config.h"
//#include "../MCAL/External_Interrupt_Driver/External_Interrupt_Interface.h"
//#include "../MCAL/External_Interrupt_Driver/External_Interrupt_Config.h"
#include "../MCAL/DIO_Driver/DIO_REG.h"
#include "../MCAL/DIO_Driver/DIO_Interface.h"
#include "../MCAL/GIE_Driver/GIE_REG.h"
#include "../MCAL/GIE_Driver/GIE_Interface.h"
//#include "../HAL/LCD_Module/LCD_Config.h"
//#include "../HAL/LCD_Module/LCD_Interface.h"
#include "../MCAL/Timer_Driver/Timer_REG.h"
#include "../MCAL/Timer_Driver/Timer_Interface.h"
#include "../MCAL/Timer_Driver/Timer_Private.h"
#include "../MCAL/Timer_Driver/Timer_Config.h"
#include "../HAL/ServoMotor_Handler/ServoMotor_Interface.h"

void __vector_10(void) __attribute__((signal));
void __vector_10(void)
{
	static u32 counter=0;
	counter++;
	if(counter==5)
	{
		DIO_U8SetPinVal(PORT_B,PIN_1,LOW);
	}
	if(counter==20)
	{
		DIO_U8SetPinVal(PORT_B,PIN_1,HIGH);
		counter=0;
	}

}

#define FIRST_RISING   0
#define RISING_2       1
#define FALLING_2      2

u16 Period_Time_Ticks;
u16 Ton_Time_Ticks;

int main(void)
{
PORT_VoidInit();
//LCD_VoidInit();
TMR1_VoidInit_Prebuild();
EXTI_VidEnableOrDisableGIE(ENABLE);
TMR1_VoidSetTopVal(20000);
//TMR0_VoidInit_Prebuild();
//SendAddressTimer_Callback(&ISR_TIM1CTC,1);

//TMR0_VoidSetPreLoadValue(125);
//DIO_U8SetPinVal(PORT_B,PIN_1,HIGH);
//EXTI_u8INT0SetCallback(ISR_TIM1CTC);

while (1)
{

for(u16 i=750;i<2500;i++)
{
	TMR1_VoidSetCompareMathChannelA(i);
	_delay_ms(5);
}
for(u16 i=2500;i>750;i--)
{
	TMR1_VoidSetCompareMathChannelA(i);
	_delay_ms(5);
}

//TMR1_VoidSetCompareMathChannelA(SERVO_MOTOR_u16Maapping_Function(180,0,2500,750, 100));
//_delay_ms(300);
//TMR1_VoidSetCompareMathChannelA(SERVO_MOTOR_u16Maapping_Function(180,0,2500,750, 20));
//_delay_ms(300);
//TMR1_VoidSetCompareMathChannelA(SERVO_MOTOR_u16Maapping_Function(180,0,2500,750, 180));
//_delay_ms(300);
//SERVO_MOTOR_s32Maapping_Function(s32 Copy_s32MaxAngle,s32 Copy_s32MinAngle,s32 MaxONTime,s32 MinONTime,s32 Copy_s32EnteredAngle)
}


return 0;

}
*/
/*=============================ICU_SW__probem in timer1 in ChannelA ,B configurations  SS()================== */
/*
#include"util/delay.h"
#include "../LIB/STDTYPES.h"
#include "../LIB/BIT_MATH.h"
#include "../LIB/CHECK_ERROR.h"
#include "../MCAL/PORT_Driver/PORT_REG.h"
#include "../MCAL/PORT_Driver/PORT_Private.h"
#include "../MCAL/PORT_Driver/PORT_Interface.h"
#include "../MCAL/PORT_Driver/PORT_Config.h"
#include "../MCAL/External_Interrupt_Driver/External_Interrupt_REG.h"
#include "../MCAL/External_Interrupt_Driver/External_Interrupt_Private.h"
#include "../MCAL/External_Interrupt_Driver/External_Interrupt_Interface.h"
#include "../MCAL/External_Interrupt_Driver/External_Interrupt_Config.h"
#include "../MCAL/DIO_Driver/DIO_REG.h"
#include "../MCAL/DIO_Driver/DIO_Interface.h"
#include "../MCAL/GIE_Driver/GIE_REG.h"
#include "../MCAL/GIE_Driver/GIE_Interface.h"
#include "../HAL/LCD_Module/LCD_Interface.h"
#include "../HAL/LCD_Module/LCD_Config.h"
#include "../MCAL/Timer_Driver/Timer_REG.h"
#include "../MCAL/Timer_Driver/Timer_Interface.h"
#include "../MCAL/Timer_Driver/Timer_Private.h"
#include "../MCAL/Timer_Driver/Timer_Config.h"
//#include "../HAL/ServoMotor_Handler/ServoMotor_Interface.h"

void __vector_10(void) __attribute__((signal));
void __vector_10(void)
{

}

#define FIRST_RISING   0
#define FALLING_1      1
#define RISING_2       2


u16 Period_Time_Ticks=0;
u16 Ton_Time_Ticks=0;

int main(void)
{
PORT_VoidInit();
LCD_VoidInit();
EXTI_voidEnableOrDisableInterruptPin_Prebuild();
EXTI_VidControlSense_Prebuild();
EXTI_VidEnableOrDisableGIE(ENABLE);
TMR0_VoidInit_Prebuild();
TMR0_VoidSetCTCValue(64);
TMR1_VoidInit_Prebuild();
 //ss();


//void ICU_SW(void);
//SendAddress_Callback(&ICU_SW);


//LCD_VoidSendString("Period_Time =");

while (1)
{
	//Waiting Untile The values are Ready
	while((Ton_Time_Ticks==0)&&(Period_Time_Ticks==0));
	LCD_VoidGoToPos(0,0);
	LCD_VoidSendString("ON_Time =");
	LCD_VoidSendNumber(Ton_Time_Ticks);
	LCD_VoidGoToPos(1,0);
	LCD_VoidSendString("Period_time =");
	LCD_VoidSendNumber(Period_Time_Ticks);




}


return 0;

}

void __vector_1(void) __attribute__ ((signal));
void __vector_1(void)
{
static u8 PWM_state=FIRST_RISING;

if(PWM_state ==FIRST_RISING)
{
	 TMR1_VoidStartTimer();
	 EXTI_u8ControlSense_Postbuild(INT0,FALLING_EDGE);
	 PWM_state=FALLING_1;
}
else if(PWM_state ==FALLING_1)
{	Ton_Time_Ticks=TMR1_VoidGetTimerVal();
	EXTI_u8ControlSense_Postbuild(INT0,RISING_EDGE);
	PWM_state=RISING_2;

}
else if(PWM_state ==RISING_2)
{

	 Period_Time_Ticks=TMR1_VoidGetTimerVal();
	 TMR1_VoidResetTimer();
	 EXTI_u8ControlSense_Postbuild(INT0,FALLING_EDGE);
	 PWM_state=FALLING_1;

}

}

*/
/*=========================================ICU_HW_ probem in timer1 in ChannelA ,B configurations  SS()==============================================*/

#include"util/delay.h"
#include "../LIB/STDTYPES.h"
#include "../LIB/BIT_MATH.h"
#include "../LIB/CHECK_ERROR.h"
#include "../MCAL/PORT_Driver/PORT_REG.h"
#include "../MCAL/PORT_Driver/PORT_Private.h"
#include "../MCAL/PORT_Driver/PORT_Interface.h"
#include "../MCAL/PORT_Driver/PORT_Config.h"
#include "../MCAL/DIO_Driver/DIO_REG.h"
#include "../MCAL/DIO_Driver/DIO_Interface.h"
#include "../MCAL/GIE_Driver/GIE_REG.h"
#include "../MCAL/GIE_Driver/GIE_Interface.h"
#include "../HAL/LCD_Module/LCD_Interface.h"
#include "../HAL/LCD_Module/LCD_Config.h"
#include "../MCAL/Timer_Driver/Timer_REG.h"
#include "../MCAL/Timer_Driver/Timer_Interface.h"
#include "../MCAL/Timer_Driver/Timer_Private.h"
#include "../MCAL/Timer_Driver/Timer_Config.h"
//#include "../HAL/ServoMotor_Handler/ServoMotor_Interface.h"

void __vector_10(void) __attribute__((signal));
void __vector_10(void)
{

}

#define FIRST_RISING   0
#define FALLING_1      1
#define RISING_2       2


u16 Period_Time_Ticks=0;
u16 Ton_Time_Ticks=0;

int main(void)
{
PORT_VoidInit();
LCD_VoidInit();
//EXTI_voidEnableOrDisableInterruptPin_Prebuild();
//EXTI_VidControlSense_Prebuild();
EXTI_VidEnableOrDisableGIE(ENABLE);
TMR0_VoidInit_Prebuild();
TMR0_VoidSetCTCValue(64);
TMR1_VoidInit_Prebuild();
 //ss();


//void ICU_SW(void);
//SendAddress_Callback(&ICU_SW);


//LCD_VoidSendString("Period_Time =");

while (1)
{
	//Waiting Untile The values are Ready
	while((Ton_Time_Ticks==0)&&(Period_Time_Ticks==0));
	LCD_VoidGoToPos(0,0);
	LCD_VoidSendString("ON_Time =");
	LCD_VoidSendNumber(Ton_Time_Ticks);
	LCD_VoidGoToPos(1,0);
	LCD_VoidSendString("Period_time =");
	LCD_VoidSendNumber(Period_Time_Ticks);

}


return 0;

}


void __vector_6(void) __attribute__((signal));
void __vector_6(void)
{

static u16 Local_u16Recording1;
static u16 Local_u16Recording2;
static u16 Local_u16Recording3;
static u8 Local_u8FlagState =FIRST_RISING;

   if( Local_u8FlagState ==FIRST_RISING)
{
	Local_u16Recording1=TMR1_VoidReadInputCapture();
	TMR1_VoidSetInputCaptureEdge(CAPTURE_EDGE_DETECTION_FALLING);
	Local_u8FlagState=FALLING_1;
}
else if(Local_u8FlagState==FALLING_1)
{
	Local_u16Recording2=TMR1_VoidReadInputCapture();
	Ton_Time_Ticks=Local_u16Recording2-Local_u16Recording1;
	TMR1_VoidSetInputCaptureEdge(CAPTURE_EDGE_DETECTION_RISING);
	 Local_u8FlagState=RISING_2;

}
else if(Local_u8FlagState ==RISING_2)
{
	Local_u16Recording3=TMR1_VoidReadInputCapture();
	Period_Time_Ticks=Local_u16Recording3-Local_u16Recording1;
	//TMR1_VoidSetInputCaptureEdge(CAPTURE_EDGE_DETECTION_FALLING);
	Local_u8FlagState=FIRST_RISING;

}
}

