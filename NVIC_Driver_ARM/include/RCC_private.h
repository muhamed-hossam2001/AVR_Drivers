/****************************************************************************************************************************************/
/***********************************************	Author  : Doaa Mohamed  *************************************************************/
/***********************************************	Date    : 2 March 2022  *************************************************************/
/***********************************************	Version : V1            *************************************************************/
/****************************************************************************************************************************************/

#ifndef _RCC_PRIVATE_H_
#define _RCC_PRIVATE_H_


/*
 * Register Definition
 */

/********************************************************  Clock control register (RCC_CR) ***********************************************/


#define  RCC_CR_REG           *((volatile u32*)  0x40021000)

enum RCC_CR_BITS
{
CR_HSI_ON,				/* to Enable the internal clock 8MHz */
CR_HSI_RDY,				/* Waiting flag to indicate that the internal clock is Enabled */
CR_HSITRIM_0=3,			/*Internal clock trimming to treat the error in clock by adding or subtracting steps +-40 kHz*/
CR_HSITRIM_1,
CR_HSITRIM_2,
CR_HSITRIM_3,
CR_HSITRIM_4,
CR_HSICAL_0,			/*internal clock reading by HW*/
CR_HSICAL_1,
CR_HSICAL_2,
CR_HSICAL_3,
CR_HSICAL_4,
CR_HSICAL_5,
CR_HSICAL_6,
CR_HSICAL_7,
CR_HSE_ON,				/*to enable the external clock */
CR_HSE_RDY,				/* Waiting flag to indicate that the External clock is Enabled */
CR_HSE_BYP,				/*to make xtal1 in MCU pins floating (Bypass mode) used in External RC clock*/
CR_CSS_ON,				/*Clock security system enable the clock detector is enabled by hardware when the HSE oscillator is ready, and disabled by hardware if a HSE clock failure is detected*/
CR_PLL_ON=24,			/*to Enable PLL circuit	 */
CR_PLL_RDY				/* Waiting flag to indicate that the PLL Circuit is Enabled */

};

/******************************************************** Clock configuration register (RCC_CFGR) ***********************************************/

#define  RCC_CFGR_REG          *((volatile u32*)  0x40021004)

enum  RCC_CFGR_BITS
{
CFGR_SW_0,
CFGR_SW_1,
CFGR_SWs_0,
CFGR_SWs_1,
CFGR_HPRE_0,
CFGR_HPRE_1,
CFGR_HPRE_2,
CFGR_HPRE_3,
CFGR_PPRE1_0,
CFGR_PPRE1_1,
CFGR_PPRE1_2,
CFGR_PPRE2_0,
CFGR_PPRE2_1,
CFGR_PPRE2_2,
CFGR_ADCPRE_0,
CFGR_ADCPRE_1,
CFGR_PLL_SRC,
CFGR_PLL_XTPRE,
CFGR_PLLMUL_0,
CFGR_PLLMUL_1,
CFGR_PLLMUL_2,
CFGR_PLLMUL_3,
CFGR_USB_PRE,
CFGR_MCO_0=24,
CFGR_MCO_1,
CFGR_MCO_2
};

/********************************************** AHB peripheral clock enable register (RCC_AHBENR) *************************************/
/**************************************************************************************************************************************/

#define  RCC_AHBENR_REG        *((volatile u32*)  0x40021014)
enum RCC_AHBENR_BITS
{
AHBENR_DMA1_EN     ,
AHBENR_DMA2_EN     ,
AHBENR_SRAM_EN     ,
AHBENR_FLITF_EN=4  ,
AHBENR_CRCE_N=6	   ,
AHBENR_FSMC_EN=8   ,
AHBENR_SDIO_EN=10
};

/********************************************** APB2 peripheral clock enable register (RCC_APB2ENR) ***********************************/
/**************************************************************************************************************************************/

#define  RCC_APB2ENR_REG       *((volatile u32*)  0x40021018)

enum RCC_APB2ENR_BITS
{
APB2ENR_AFIO_EN,
APB2ENR_IOPA_EN=2,
APB2ENR_IOPB_EN,
APB2ENR_IOPC_EN,
APB2ENR_IOPD_EN,
APB2ENR_IOPE_EN,
APB2ENR_IOPF_EN,
APB2ENR_IOPG_EN,
APB2ENR_ADC1_EN,
APB2ENR_ADC2_EN,
APB2ENR_TIM1_EN,
APB2ENR_SPI1_EN,
APB2ENR_TIM8_EN,
APB2ENR_USART1_EN,
APB2ENR_ADC3_EN,
APB2ENR_TIM9_EN=19,
APB2ENR_TIM10_EN,
APB2ENR_TIM11_EN,

};

/********************************************** APB1 peripheral clock enable register (RCC_APB2ENR) ***********************************/
/**************************************************************************************************************************************/

#define  RCC_APB1ENR_REG       *((volatile u32*)  0x4002101C)

enum RCC_APB1ENR_BITS
{
APB1ENR_TIM2_EN     ,
APB1ENR_TIM3_EN     ,
APB1ENR_TIM4_EN     ,
APB1ENR_TIM5_EN     ,
APB1ENR_TIM6_EN     ,
APB1ENR_TIM7_EN     ,
APB1ENR_TIM12_EN    ,
APB1ENR_TIM13_EN    ,
APB1ENR_TIM14_EN    ,
APB1ENR_WWD_GEN=11  ,
APB1ENR_SPI2_EN=14  ,
APB1ENR_SPI3_EN=17  ,
APB1ENR_USART2_EN   ,
APB1ENR_USART3_EN   ,
APB1ENR_USART4_EN   ,
APB1ENR_USART5_EN   ,
APB1ENR_I2C1_EN     ,
APB1ENR_I2C2_EN     ,
APB1ENR_USB_EN      ,
APB1ENR_CAN_EN=25   ,
APB1ENR_BKP_EN=27   ,
APB1ENR_PWR_EN      ,
APB1ENR_DAC_EN

};


/********************************************** APB1 peripheral clock enable register (RCC_APB2ENR) ***********************************/
/**************************************************************************************************************************************/

#define  RCC_CIR_REG           *((volatile u32*)  0x40021008)
#define  RCC_APB2RSTR_REG      *((volatile u32*)  0x4002100C)
#define  RCC_APB1RSTR_REG      *((volatile u32*)  0x40021010)




#define  RCC_BDCR_REG          *((volatile u32*)  0x40021020)
#define  RCC_CSR_REG           *((volatile u32*)  0x40021024)








#endif
