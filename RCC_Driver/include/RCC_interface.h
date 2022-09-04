/****************************************************************************************************************************************/
/***********************************************	Author  : Doaa Mohamed  *************************************************************/
/***********************************************	Date    : 2 March 2022  *************************************************************/
/***********************************************	Version : V1            *************************************************************/
/****************************************************************************************************************************************/

#ifndef _RCC_INTERFACE_H_
#define _RCC_INTERFACE_H_


#define AHB_BUS   0
#define ABP1_BUS  1
#define ABP2_BUS  2

#define ENABLE   1
#define DISABLE  0

/********************************************************  Clock control register (RCC_CR) ***********************************************/
/*****************************************************************************************************************************************/

/*
 * Internal Clock trimming Mask and shift bit
 */

#define RCC_CLK_TRIM_MASK   0xFFFFFF07
#define RCC_CLK_TRIM_SHIFT  3
/*
 *Internal clock Reading Mask and shift bit
 */
#define RCC_CLK_READING_MASK   0xFFFF00FF
#define RCC_CLK_READING_SHIFT  8


/********************************************************  Clock configuration register (RCC_CFGR)  **************************************/
/*****************************************************************************************************************************************/
/*
 *System clock switch selection MASK and Choice
 */
#define RCC_SYSTEM_CLK_SELECT_MASK   0xFFFFFFFC
#define RCC_SYSTEM_CLK_SELECT_SHIFT  0

#define RCC_INTERNAL_SYSTEM_CLK	     0
#define RCC_EXTENAL_SYSTEM_CLK       1
#define RCC_PLL_SYSTEM_CLK           2

/*To select the External Clock RC or Crystal*/

#define RCC_CLK_EXTERNAL_RC       0
#define RCC_CLK_EXTERNAL_CRYSTAL  1
/*
 * AHB Prescaller Configurations
 */
#define RCC_AHB_CLK_PRESCALLER_MASK   0xFFFFFF0F
#define RCC_AHB_CLK_PRESCALLER_SHIFT  4

/*Prescaller Division value for AHB */
#define RCC_AHB_CLK_PRESCALLER_NO_DIV  0x00
#define RCC_AHB_CLK_PRESCALLER_DIV_2   0x08
#define RCC_AHB_CLK_PRESCALLER_DIV_4   0x09
#define RCC_AHB_CLK_PRESCALLER_DIV_8   0x0A
#define RCC_AHB_CLK_PRESCALLER_DIV_16  0x0B
#define RCC_AHB_CLK_PRESCALLER_DIV_64  0x0C
#define RCC_AHB_CLK_PRESCALLER_DIV_128 0x0D
#define RCC_AHB_CLK_PRESCALLER_DIV_256 0x0E
#define RCC_AHB_CLK_PRESCALLER_DIV_512 0x0F


/*
 * ABP1 Prescaller Configurations
 */
#define RCC_ABP1_CLK_PRESCALLER_MASK   0xFFFFF8FF
#define RCC_ABP1_CLK_PRESCALLER_SHIFT  8

/*Prescaller Division value for ABP1 */
#define RCC_ABP1_CLK_PRESCALLER_NO_DIV  0x00
#define RCC_ABP1_CLK_PRESCALLER_DIV_2   0x04
#define RCC_ABP1_CLK_PRESCALLER_DIV_4   0x05
#define RCC_ABP1_CLK_PRESCALLER_DIV_8   0x06
#define RCC_ABP1_CLK_PRESCALLER_DIV_16  0x07

/*
 * ABP2 Prescaller Configurations
 */
#define RCC_ABP2_CLK_PRESCALLER_MASK   0xFFFFC7FF
#define RCC_ABP2_CLK_PRESCALLER_SHIFT  11

/*Prescaller Division value for ABP2 */
#define RCC_ABP2_CLK_PRESCALLER_NO_DIV  0x00
#define RCC_ABP2_CLK_PRESCALLER_DIV_2   0x04
#define RCC_ABP2_CLK_PRESCALLER_DIV_4   0x05
#define RCC_ABP2_CLK_PRESCALLER_DIV_8   0x06
#define RCC_ABP2_CLK_PRESCALLER_DIV_16  0x07

/*
 * ADC Prescaler Configurations
 */
#define RCC_ADC_CLK_PRESCALLER_MASK   0xFFFF3FFF
#define RCC_ADC_CLK_PRESCALLER_SHIFT  14

/*Prescaler Division value for  ADC */
#define RCC_ADC_CLK_PRESCALLER_DIV_2   0x00
#define RCC_ADC_CLK_PRESCALLER_DIV_4   0x01
#define RCC_ADC_CLK_PRESCALLER_DIV_8   0x02
#define RCC_ADC_CLK_PRESCALLER_DIV_16  0x03


/* PLL entry clock source*/

#define RCC_PLL_CLK_HSI_DIV_2   0
#define RCC_PLL_CLK_HSE		    1

/*HSE divider for PLL entry*/

#define RCC_PLL_CLK_HSE_NO_DIV  0
#define RCC_PLL_CLK_HSE_DIV_2   1

/*
 * PLL multiplication factor Configurations
 */

#define RCC_PLL_CLK_MULTIPLER_MASK   0xFFC3FFFF
#define RCC_PLL_CLK_MULTIPLER_SHIFT  18

 #define RCC_PLL_MUL_2     0x00
 #define RCC_PLL_MUL_3	   0x01
 #define RCC_PLL_MUL_4     0x02
 #define RCC_PLL_MUL_5     0x03
 #define RCC_PLL_MUL_6     0x04
 #define RCC_PLL_MUL_7     0x05
 #define RCC_PLL_MUL_8     0x06
 #define RCC_PLL_MUL_9     0x07
 #define RCC_PLL_MUL_10    0x08
 #define RCC_PLL_MUL_11    0x09
 #define RCC_PLL_MUL_12    0x0A
 #define RCC_PLL_MUL_13    0x0B
 #define RCC_PLL_MUL_14    0x0C
 #define RCC_PLL_MUL_15    0x0D
 #define RCC_PLL_MUL_16    0x0E


/*
 * Microcontroller clock output
 */
#define RCC_MCU_CLK_OUT_MASK   0xF0FFFFFF
#define RCC_MCU_CLK_OUT_SHIFT  24

#define RCC_MCU_CLK_OUT_NO         0x00
#define RCC_MCU_CLK_OUT_SYS        0x04
#define RCC_MCU_CLK_OUT_ENXTENAL   0x06
#define RCC_MCU_CLK_OUT_INTERNAL   0x05
#define RCC_MCU_CLK_OUT_PLL_DIV_2  0x07


 extern void RCC_voidInit();

 extern u8 RCC_VoidEnablePeriphral(u8 Copy_u8Bus, u8 Copy_u8PrephralId);

 extern u8 RCC_VoidDisablePeriphral(u8 Copy_u8Bus, u8 Copy_u8PrephralId);






#endif
