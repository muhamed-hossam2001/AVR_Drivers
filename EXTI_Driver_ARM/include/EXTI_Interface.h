/****************************************************************************************************************************************/
/***********************************************	Author  : Doaa Mohamed  *************************************************************/
/***********************************************	Layer  : MCAL           *************************************************************/
/***********************************************	Date    : 14 March 2022  ************************************************************/
/***********************************************	Version : V1            *************************************************************/
/****************************************************************************************************************************************/

#ifndef _EXTI_INTERFACE_H_
#define _EXTI_INTERFACE_H_


#define ENABLE  1
#define DISABLE 0


/*
 *External Lines in MCU (Line 0 Connect (PINA0 ,PINB0 ,PINC0) etc... and each line like it.
 */
#define EXTI_LINE0  	(u8)0
#define EXTI_LINE1  	(u8)1
#define EXTI_LINE2  	(u8)2
#define EXTI_LINE3  	(u8)3
#define EXTI_LINE4  	(u8)4
#define EXTI_LINE5  	(u8)5
#define EXTI_LINE6  	(u8)6
#define EXTI_LINE7  	(u8)7
#define EXTI_LINE8  	(u8)8
#define EXTI_LINE9  	(u8)9
#define EXTI_LINE10  	(u8)10
#define EXTI_LINE11  	(u8)11
#define EXTI_LINE12  	(u8)12
#define EXTI_LINE13  	(u8)13
#define EXTI_LINE14  	(u8)14
#define EXTI_LINE15  	(u8)15
/*
 * External interrupts Event selection
 */
#define EXTI_RISING_EDGE  0
#define EXTI_FALLING_EDGE 1
#define EXTI_ON_CHANGE    2


/*
 * Description  :External interrupt initialization in Prebuild
 * Input  		:NO inputs
 * Return		:NO Return
 */
extern void EXTI_voidInit();

/*
 * Description  :function to Enable the external interrupts to Execute
 * Input  		:EXTI Line Number ,Interrupt Enable or disable select
 * Return		:Status of the function to Check if it works Properly or not
 */
extern u8 EXTI_u8InterruptEnableDisable(u8 Copy_u8InterruptLine,u8 Copy_u8InterruptEn_Dis);

/*
 * Description  :function to Disable Sense the external interrupts for line number
 * Input  		:EXTI Line Number ,Interrupt sense
 * Return		:Status of the function to Check if it works Properly or not
 */
extern u8 EXTI_u8InterruptDisableSense(u8 Copy_u8InterruptLine,u8 Copy_u8InterruptSense);

/*
 * Description  :function to Disable Sense the external interrupts for line number
 * Input  		:EXTI Line Number ,Interrupt sense
 * Return		:Status of the function to Check if it works Properly or not
 */
extern u8 EXTI_u8InterruptEnableSense(u8 Copy_u8InterruptLine,u8 Copy_u8InterruptSense);

/*
 * Description  :Function to Clear Pending Flage
 * Input  		:Line Number of EXTIx
 * Return		:No Return
 */
extern void  EXTI_u8ClearPendingFlag(u8 Copy_u8InterruptLine);

/*
 * Description  :Callback function
 * Input  		:Pointer to function ,Line Number of EXTIx
 * Return		:Status of the function to Check if it works Properly or not
 */
extern u8 EXTI_u8SetCallBackFunc(void (*EXTI_Ptr)(void) ,u8 Copy_u8EXTILine);


#endif
