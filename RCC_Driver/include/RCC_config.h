/****************************************************************************************************************************************/
/***********************************************	Author  : Doaa Mohamed  *************************************************************/
/***********************************************	Date    : 2 March 2022  *************************************************************/
/***********************************************	Version : V1            *************************************************************/
/****************************************************************************************************************************************/

#ifndef _RCC_CONFIG_H_
#define _RCC_CONFIG_H_

/********************************************************  Clock control register (RCC_CR) ***********************************************/
/*****************************************************************************************************************************************/

/*
 * Internal clock Enable or Disable
 * 		Options:
 * 			1-ENABLE
 * 			2-DISABLE
 */

#define RCC_HSI_EN_DIS   	 	  ENABLE
/*
 * External clock Enable or Disable
 * 		Options:
 * 			1-ENABLE
 * 			2-DISABLE
 */

#define RCC_HSE_EN_DIS    	  	  DISABLE


/*
 *Clock security system enable the clock detector is enabled by hardware when the HSE oscillator is ready,
 *Clock  and disabled by hardware if a HSE clock failure is detected
 * 		Options:
 * 			1-ENABLE
 * 			2-DISABLE
 */
#define RCC_CLOCK_SECURITY_SYSTEM  ENABLE
/*
 * Enable or Disable Phase locked loop clock multiplyer
 * 		Options:
 * 			1-ENABLE
 * 			2-DISABLE
 */
#define RCC_PLL_EN_DIS        	  ENABLE


/********************************************************  Clock configuration register (RCC_CFGR) ********************************************/
/**********************************************************************************************************************************************/

/*
 *System clock switch selection MASK and Choice
 */
/*
 * Options:
 * 		1-RCC_INTERNAL_SYSTEM_CLK
 * 		2-RCC_EXTENAL_SYSTEM_CLK
 * 		3-RCC_PLL_SYSTEM_CLK
 */
#define RCC_CLK_SYSTEM_SELECT    RCC_PLL_SYSTEM_CLK


/*Note : if you select External clock you can choose the type  (RC) ,Crystal  */

#if RCC_HSE_EN_DIS==ENABLE
 	 #define RCC_EXTERNAL_CLK_SELECT  RCC_CLK_EXTERNAL_CRYSTAL
#endif

/*
 * AHB Prescaller Configurations
 */
/*Prescaller Division value for AHB
 * Options:
 *       1-RCC_AHB_CLK_PRESCALLER_NO_DIV
 *       2-RCC_AHB_CLK_PRESCALLER_DIV_2
 *       3-RCC_AHB_CLK_PRESCALLER_DIV_4
 *       4-RCC_AHB_CLK_PRESCALLER_DIV_8
 *       5-RCC_AHB_CLK_PRESCALLER_DIV_16
 *       6-RCC_AHB_CLK_PRESCALLER_DIV_64
 *       7-RCC_AHB_CLK_PRESCALLER_DIV_128
 *       8-RCC_AHB_CLK_PRESCALLER_DIV_256
 *       9-RCC_AHB_CLK_PRESCALLER_DIV_512
 *
 * */
#define RCC_AHB_PRESCALLER_DIV_SELECT  RCC_AHB_CLK_PRESCALLER_DIV_2

/*
 * ABP1 Prescaller Configurations
 */
/*Prescaller Division value for ABP1
 * Options:
 *       1-RCC_ABP1_CLK_PRESCALLER_NO_DIV
 *       2-RCC_ABP1_CLK_PRESCALLER_DIV_2
 *       3-RCC_ABP1_CLK_PRESCALLER_DIV_4
 *       4-RCC_ABP1_CLK_PRESCALLER_DIV_8
 *       5-RCC_ABP1_CLK_PRESCALLER_DIV_16
 *
  */
#define RCC_ABP1_PRESCALLER_DIV_SELECT  RCC_ABP1_CLK_PRESCALLER_DIV_2

/*
 * ABP2 Prescaller Configurations
 */

/*Prescaller Division value for ABP1
 * Options:
 *       1-RCC_ABP2_CLK_PRESCALLER_NO_DIV
 *       2-RCC_ABP2_CLK_PRESCALLER_DIV_2
 *       3-RCC_ABP2_CLK_PRESCALLER_DIV_4
 *       4-RCC_ABP2_CLK_PRESCALLER_DIV_8
 *       5-RCC_ABP2_CLK_PRESCALLER_DIV_16
 *
  */

#define RCC_ABP2_PRESCALLER_DIV_SELECT  RCC_ABP2_CLK_PRESCALLER_DIV_4

/*
 * ADC Prescaler Configurations
 */

/*Prescaler Division value for  ADC
 *   Options:
 *   	1-RCC_ADC_CLK_PRESCALLER_DIV_2
 *   	2-RCC_ADC_CLK_PRESCALLER_DIV_4
 *   	3-RCC_ADC_CLK_PRESCALLER_DIV_8
 *   	4-RCC_ADC_CLK_PRESCALLER_DIV_16
 */


#define RCC_ADC_PRESCALLER_DIV_SELECT RCC_ADC_CLK_PRESCALLER_DIV_2

/*
 * Note: if you choose PLL as clock system you must Configure these options
 */
#if RCC_CLK_SYSTEM_SELECT ==RCC_PLL_SYSTEM_CLK
/*
 * PLL entry clock source
 * 	Options:
 * 	     1-RCC_PLL_CLK_HSI_DIV_2
 * 	     2-RCC_PLL_CLK_HSE
 */

#define RCC_PLL_CLK_SELECT  RCC_PLL_CLK_HSE


/*HSE divider for PLL entry
 *    Options:
 *    	1-RCC_PLL_CLK_HSE_NO_DIV
 *    	2-RCC_PLL_CLK_HSE_DIV_2
 */
#define RCC_PLL_HSE_CLK_SELECT  RCC_PLL_CLK_HSE_NO_DIV


/*
 * PLL multiplication factor Configurations
 * 		Options:
 * 	       1-RCC_PLL_MUL_2
 * 	       2-RCC_PLL_MUL_3
 * 	       3-RCC_PLL_MUL_4
 * 	       4-RCC_PLL_MUL_5
 * 	       5-RCC_PLL_MUL_6
 * 	       6-RCC_PLL_MUL_7
 * 	       7-RCC_PLL_MUL_8
 * 	       8-RCC_PLL_MUL_9
 * 	       9-RCC_PLL_MUL_10
 * 	       10-RCC_PLL_MUL_11
 * 	       11-RCC_PLL_MUL_12
 * 	       12-RCC_PLL_MUL_13
 * 	       13-RCC_PLL_MUL_14
 * 	       14-RCC_PLL_MUL_15
 * 	       15-RCC_PLL_MUL_16
 */
#define RCC_PLL_MUL_SELECT  RCC_PLL_MUL_3

#endif
/*
 * Microcontroller clock output
 * 	  Options:
 * 	  	  1-RCC_MCU_CLK_OUT_NO
 * 	  	  2-RCC_MCU_CLK_OUT_SYS
 * 	  	  3-RCC_MCU_CLK_OUT_ENXTENAL
 * 	  	  4-RCC_MCU_CLK_OUT_INTERNAL
 * 	  	  5-RCC_MCU_CLK_OUT_PLL_DIV_2
 *
 */
#define RCC_MCU_OUT_SELECT  RCC_MCU_CLK_OUT_NO

/*********************************************AHB peripheral clock enable register (RCC_AHBENR) *********************************************/
/*******************************************************************************************************************************************/
/*
 * to Enable or disable clock in DMA1
 * 		Options:
 * 			1-ENABLE
 * 			2-DISABLE
 *
 */
#define RCC_DMI1_CLK_EN_DIS   DISABLE

/*
 * to Enable or disable clock in DMA2
 * 		Options:
 * 			1-ENABLE
 * 			2-DISABLE
 *
 */
#define RCC_DMI2_CLK_EN_DIS   DISABLE
/*
 * to Enable or disable clock in SRAM
 * 		Options:
 * 			1-ENABLE
 * 			2-DISABLE
 *
 */
#define RCC_SRAM_CLK_EN_DIS   DISABLE
/*
 * to Enable or disable clock in FLITF
 * 		Options:
 * 			1-ENABLE
 * 			2-DISABLE
 *
 */
#define RCC_FLITF_CLK_EN_DIS   DISABLE
/*
 * to Enable or disable clock in CRC
 * 		Options:
 * 			1-ENABLE
 * 			2-DISABLE
 *
 */
#define RCC_CRC_CLK_EN_DIS   DISABLE
/*
 * to Enable or disable clock in FSMC
 * 		Options:
 * 			1-ENABLE
 * 			2-DISABLE
 *
 */
#define RCC_FSMC_CLK_EN_DIS   DISABLE
/*
 * to Enable or disable clock in SDIO
 * 		Options:
 * 			1-ENABLE
 * 			2-DISABLE
 *
 */
#define RCC_SDIO_CLK_EN_DIS   DISABLE





#endif
