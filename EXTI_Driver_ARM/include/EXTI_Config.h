/****************************************************************************************************************************************/
/***********************************************	Author  : Doaa Mohamed  *************************************************************/
/***********************************************	Layer  : MCAL           *************************************************************/
/***********************************************	Date    : 14 March 2022 *************************************************************/
/***********************************************	Version : V1            *************************************************************/
/****************************************************************************************************************************************/

#ifndef _EXTI_CONFIG_H_
#define _EXTI_CONFIG_H_


/********************************** Interrupt set-enable registers (NVIC_ISERx) *************************************/
/********************************************************************************************************************/

/* Output Pin Options:
 *
 * 		ENABLE
 * 		DISABLE
 */


/*for externals interrupts from [15 : 0]*/

#define EXTI_LINE0_EN_DIS                  ENABLE
#define EXTI_LINE1_EN_DIS                  DISABLE
#define EXTI_LINE2_EN_DIS                  DISABLE
#define EXTI_LINE3_EN_DIS                  DISABLE
#define EXTI_LINE4_EN_DIS                  DISABLE
#define EXTI_LINE5_EN_DIS                  DISABLE
#define EXTI_LINE6_EN_DIS                  DISABLE
#define EXTI_LINE7_EN_DIS                  DISABLE
#define EXTI_LINE8_EN_DIS                  DISABLE
#define EXTI_LINE9_EN_DIS                  ENABLE
#define EXTI_LINE10_EN_DIS                 DISABLE
#define EXTI_LINE11_EN_DIS                 DISABLE
#define EXTI_LINE12_EN_DIS                 DISABLE
#define EXTI_LINE13_EN_DIS                 DISABLE
#define EXTI_LINE14_EN_DIS                 DISABLE
#define EXTI_LINE15_EN_DIS                 DISABLE


/*if you want to make Line interrupts on any change   (FALLING ->ENABLE   RISING ->ENABLE )
 *if you want to make Line interrupts on Rising edge  (FALLING ->DISABLE  RISING ->ENABLE )
 *if you want to make Line interrupts on Failing edge (FALLING ->ENABLE   RISING ->DISABLE)
 */

/*To make line interrupts in Falling edge
 * 		ENABLE
 * 		DISABLE
 */
#define EXTI_LINE0_FALLING_EDGE_MODE       ENABLE
#define EXTI_LINE1_FALLING_EDGE_MODE	   DISABLE
#define EXTI_LINE2_FALLING_EDGE_MODE       DISABLE
#define EXTI_LINE3_FALLING_EDGE_MODE       DISABLE
#define EXTI_LINE4_FALLING_EDGE_MODE       DISABLE
#define EXTI_LINE5_FALLING_EDGE_MODE       DISABLE
#define EXTI_LINE6_FALLING_EDGE_MODE       DISABLE
#define EXTI_LINE7_FALLING_EDGE_MODE       DISABLE
#define EXTI_LINE8_FALLING_EDGE_MODE       DISABLE
#define EXTI_LINE9_FALLING_EDGE_MODE       ENABLE
#define EXTI_LINE10_FALLING_EDGE_MODE      DISABLE
#define EXTI_LINE11_FALLING_EDGE_MODE      DISABLE
#define EXTI_LINE12_FALLING_EDGE_MODE      DISABLE
#define EXTI_LINE13_FALLING_EDGE_MODE      DISABLE
#define EXTI_LINE14_FALLING_EDGE_MODE      DISABLE
#define EXTI_LINE15_FALLING_EDGE_MODE      DISABLE

/*To make line interrupts in Rising edge
 * 		ENABLE
 * 		DISABLE
 */
#define EXTI_LINE0_RISING_EDGE_MODE        DISABLE
#define EXTI_LINE1_RISING_EDGE_MODE	       DISABLE
#define EXTI_LINE2_RISING_EDGE_MODE        DISABLE
#define EXTI_LINE3_RISING_EDGE_MODE        DISABLE
#define EXTI_LINE4_RISING_EDGE_MODE        DISABLE
#define EXTI_LINE5_RISING_EDGE_MODE        DISABLE
#define EXTI_LINE6_RISING_EDGE_MODE        DISABLE
#define EXTI_LINE7_RISING_EDGE_MODE        DISABLE
#define EXTI_LINE8_RISING_EDGE_MODE        DISABLE
#define EXTI_LINE9_RISING_EDGE_MODE        DISABLE
#define EXTI_LINE10_RISING_EDGE_MODE       DISABLE
#define EXTI_LINE11_RISING_EDGE_MODE       DISABLE
#define EXTI_LINE12_RISING_EDGE_MODE       DISABLE
#define EXTI_LINE13_RISING_EDGE_MODE       DISABLE
#define EXTI_LINE14_RISING_EDGE_MODE       DISABLE
#define EXTI_LINE15_RISING_EDGE_MODE       DISABLE


#endif
