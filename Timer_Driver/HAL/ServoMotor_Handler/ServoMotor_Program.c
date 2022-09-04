/*
 * LM35_Program.c
 *
 *  Created on: Oct 16, 2021
 *      Author: dell
 */


/*
 * LCD_Program.c
 *
 *  Created on: Sep 24, 2021
 *      Author: dell
 */
#include"util/delay.h"
#include "../../LIB/STDTYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/CHECK_ERROR.h"
#include"../../MCAL/Timer_Driver/Timer_Config.h"
#include"../../MCAL/Timer_Driver/Timer_Private.h"
#include"../../MCAL/Timer_Driver/Timer_Interface.h"
#include "../ServoMotor_Handler/ServoMotor_Interface.h"

#define Angle_0_tickis 750
#define Angle_180_tickis 2500


void ServoMotor_VoidInit()
{
	TMR1_VoidInit_Prebuild();
}



void ServoMotor_u16SetAngle(u16 Copy_u16Adngle,u8 Copy_u8Channel )
{

if ( Copy_u8Channel==TIMER1_CHANNELB)
{
	OCR1B_REG=Copy_u16Adngle;
			  _delay_ms(40);
}

else if(Copy_u8Channel==TIMER1_CHANNELA)
{
	OCR1A_REG=Copy_u16Adngle;
			  _delay_ms(40);
}
}
/*Take Angle and give suitable ON_Time*/
u16 SERVO_MOTOR_u16Maapping_Function(s32 Copy_s32MaxAngle,s32 Copy_s32MinAngle,s32 MaxONTime,s32 MinONTime,s32 Copy_s32EnteredAngle)
{
    s32 Local_s32LineSlope=(MaxONTime-MinONTime)/(Copy_s32MaxAngle-Copy_s32MinAngle);
    s32 Local_s32Mapped_Number=Local_s32LineSlope*(Copy_s32EnteredAngle-Copy_s32MaxAngle) +MaxONTime;
    return Local_s32Mapped_Number;

}
