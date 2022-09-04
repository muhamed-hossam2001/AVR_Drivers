/****************************************************************************************************************************************/
/***********************************************	Author  : Doaa Mohamed  *************************************************************/
/***********************************************	Layer  : MCAL           *************************************************************/
/***********************************************	Date    : 17 March 2022 *************************************************************/
/***********************************************	Version : V1            *************************************************************/
/****************************************************************************************************************************************/
#ifndef _SYSTICK_INTERFACE_H_
#define _SYSTICK_INTERFACE_H_




#define ENABLE   1
#define DISABLE  0

/*
 * To select the clock source of systick
 */
#define  STK_CLOCK_SRC_AHB_DIV_8   0
#define  STK_CLOCK_SRC_AHB_NO_DIV  1


/**************************************************** Functions *****************************************************/
/********************************************************************************************************************/


/*
 * Discription:Function to initiate Systick in prebuild
 * Parameters :No input
 * Return 	  :No return
 */
extern void STK_voidInit();

/*
 * Discription:Function to Enable or disable Systick interrupt in Postbuild
 * Parameters :Enable or DISABLE
 * Return 	  :the error status of the function to Know if it works Properly or not
 */
extern u8 STK_u8EnableOrDisableInterrupt(u8 Copy_u8Enable_Disable);

/*
 * Discription:Function to Enable or disable Systick Power in Postbuild
 * Parameters :No input
 * Return 	  :the error status of the function to Know if it works Properly or not
 */
extern u8 STK_u8EnableOrDisablePeriphral(u8 Copy_u8Enable_Disable);

/*
 * Discription: Function to read the value of current counts in Systick
 * Parameters :No input
 * Return 	  :Current Timer reading
 */
extern u32 STK_u32ReadingCurrntTimerValue();

/*
 * Discription:Function to read the value of Remaining counts in Systick
 * Parameters :No input
 * Return 	  :Current Timer reading
 */
extern u32 STK_u32ReadingRemainingTimerValue();

/*
 * Discription:Function to Set delay as buzy waiting(Polling) using syncronous thichnecq without interrupt
 * Parameters :Number of ticks
 * Return 	  :No return
 */
extern void STK_voidSetBusyWait_Synchronous(u32 Copy_u32TicksValue);

/*
 * Discription:Function to Set delay using Asyncronous thichnecq with interrupt but for single time not periodic
 * Parameters :Number of ticks
 * Return 	  :the error status of the function to Know if it works Properly or not
 */
extern u8 STK_u8SetIntervalSingle_Asyncrounous(u32 Copy_u32TicksValue,void (*STK_SinglePtrtoFunc)(void));

/*
 * Discription:Function to Set delay using Asyncronous thichnecq with interrupt but Periodic Time
 * Parameters :Number of ticks ,Notification pointer to function
 * Return 	  :the error status of the function to Know if it works Properly or not
 */
extern u8 STK_u8SetIntervalPeriodic_Asyncrounous(u32 Copy_u32TicksValue,void (*STK_PeriodicPtrtoFunc)(void));

/*
 * Discription:Function to stop counting of the systick
 * Parameters :Number of ticks, Notification pointer to function
 * Return 	  :No return
 */
extern void STK_voidStopTimer();

/*
 * Discription:Function to Reset counting of the systick
 * Parameters :No parametrers
 * Return 	  :No return
 */
extern void STK_voidResetTimer();





#endif
