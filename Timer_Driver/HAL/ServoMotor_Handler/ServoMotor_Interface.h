/*
 * LM35_Program.c
 *
 *  Created on: Oct 16, 2021
 *      Author: dell
 */

#ifndef HAL_ServoMottor_MODULE_INTERFACE
#define HAL_ServoMotor_MODULE_INTERFACE



#define TIMER1_CHANNELA 0
#define TIMER1_CHANNELB 1

/*to initialize the LM35 Which Initialize the Timer1S
 * input:No input
 * Output:No return
 */
extern void ServoMotor_VoidInit();

/*to set the angle of ServoMotor
 * input:value of Angle,Timer1_Channel
 * Output:no return
 */

extern void ServoMotor_u16SetAngle(u16 Copy_u16Adngle,u8 Copy_u8Channel );


/*to Map the angle to specified ON_Time
 * input:MaxServoAngle,MinServoAngle,MaxON_Time,MinON_Time,EnteredAngletobe mapped
 * Output: Suitable ON_time
 */
extern u16 SERVO_MOTOR_u16Maapping_Function(s32 Copy_s32MaxAngle,s32 Copy_s32MinAngle,s32 MaxONTime,s32 MinONTime,s32 Copy_s32EnteredAngle);

#endif
