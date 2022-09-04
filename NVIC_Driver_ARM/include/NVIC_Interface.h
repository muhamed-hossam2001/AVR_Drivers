/****************************************************************************************************************************************/
/***********************************************	Author  : Doaa Mohamed  *************************************************************/
/***********************************************	Layer  : MCAL           *************************************************************/
/***********************************************	Date    : 11 March 2022 *************************************************************/
/***********************************************	Version : V1            *************************************************************/
/****************************************************************************************************************************************/

#ifndef _NVIC_INTERFACE_H_
#define _NVIC_INTERFACE_H_


#define ENABLE  1
#define DISABLE 0


/*
 * to select Group and subgroup configurations
 */

#define NVIC_PRIORTY_GROUP_16_SUB_0  	0x05FA0300
#define NVIC_PRIORTY_GROUP_8_SUB_2   	0x05FA0400
#define NVIC_PRIORTY_GROUP_4_SUB_4  	0x05FA0500
#define NVIC_PRIORTY_GROUP_2_SUB_8  	0x05FA0600
#define NVIC_PRIORTY_GROUP_0_SUB_16 	0x05FA0700

/*
 * the Position of External Interrupts in HW
 */
#define NVIC_WWDT_POS          0
#define NVIC_PVD_POS           1
#define NVIC_TAMPER_POS        2
#define NVIC_RTC_POS           3
#define NVIC_FLASH_POS         4
#define NVIC_RCC_POS           5
#define NVIC_EXTI0_POS         6
#define NVIC_EXTI1_POS         7
#define NVIC_EXTI2_POS         8
#define NVIC_EXTI3_POS         9
#define NVIC_EXTI4_POS         10
#define NVIC_DMA1_CH1_POS      11
#define NVIC_DMA1_CH2_POS      12
#define NVIC_DMA1_CH3_POS      13
#define NVIC_DMA1_CH4_POS      14
#define NVIC_DMA1_CH5_POS      15
#define NVIC_DMA1_CH6_POS      16
#define NVIC_DMA1_CH7_POS      17
#define NVIC_ADC1_2_POS        18
#define NVIC_CAN1_TX_POS       19
#define NVIC_CAN1_RX0_POS      20
#define NVIC_CAN1_RX1_POS      21
#define NVIC_CAN1_SCE_POS      22
#define NVIC_EXTI9_5_POS       23
#define NVIC_TIM1_BRK_POS      24
#define NVIC_TIM1_UP_POS       25
#define NVIC_TIM1_TRG_COM_POS  26
#define NVIC_TIM1_CC_POS       27
#define NVIC_TIM2_POS          28
#define NVIC_TIM3_POS          29
#define NVIC_TIM4_POS          30
#define NVIC_I2C1_EV_POS       31
#define NVIC_I2C1_ER_POS       32
#define NVIC_I2C2_EV_POS       33
#define NVIC_I2C2_ER_POS       34
#define NVIC_SPI1_POS          35
#define NVIC_SPI2_POS          36
#define NVIC_USART1_POS        37
#define NVIC_USART2_POS        38
#define NVIC_USART3_POS        39
#define NVIC_EXTI15_10_POS     40
#define NVIC_RTCAlarm_POS      41
#define NVIC_ OTG_FS_WKUP_POS  42
#define NVIC_TMR5_POS          50
#define NVIC_SPI3_POS          51
#define NVIC_UART4_POS         52
#define NVIC_UART5_POS         53
#define NVIC_TIM6_POS          54
#define NVIC_TIM7_POS          55
#define NVIC_DMA2_CH1_POS      56
#define NVIC_DMA2_CH2_POS      57
#define NVIC_DMA2_CH3_POS      58
#define NVIC_DMA2_CH4_POS      59
#define NVIC_DMA2_CH5_POS      60
#define NVIC_ETH_POS           61
#define NVIC_ETH_WKUP_POS      62
#define NVIC_CAN2_TX_POS       63
#define NVIC_CAN2_RX0_POS      64
#define NVIC_CAN2_RX1_POS      65
#define NVIC_CAN2_SCE_POS      66
#define NVIC_OTG_FS_POS        67










/*
 * Description  :NVIC initialization in Prebuild
 * Input  		:NO inputs
 * Return		: NO Return
 */
extern void NVIC_VoidInit();

/*
 * Description  :function to Enable the external interrupts to Execute
 * Input  		:Interrupt Number in HW Position
 * Return		:Status of the function to Check if it works Properly or not
 */
extern u8 NVIC_u8EnableInterrupt(u8 Copy_u8InterruptNumber);

/*
 * Description  :function to Disable the external interrupts from execution
 * Input  		:Interrupt Number in HW Position
 * Return		:Status of the function to Check if it works Properly or not
 */
extern u8 NVIC_u8DisableInterrupt(u8 Copy_u8InterruptNumber);

/*
 * Description  :function to Enable the pending flag of the external interrupts for testing
 * Input  		:Interrupt Number in HW Position
 * Return		:Status of the function to Check if it works Properly or not
 */
extern u8 NVIC_u8EnablePendingFlag(u8 Copy_u8InterruptNumber);

/*
 * Description  :function to Disable the external pending flag interrupts
 * Input  		:Interrupt Number in HW Position
 * Return		:Status of the function to Check if it works Properly or not
 */
extern u8 NVIC_u8DisablePendingFlag(u8 Copy_u8InterruptNumber);

/*
 * Description  :function to read active flag to Know if the interrupts is executing now or not
 * Input  		:Interrupt Number in HW Position ,Pointer for reading the flag
 * Return		:Status of the function to Check if it works Properly or not
 */
extern u8 NVIC_u8ReadingActiveFlag(u8 Copy_u8InterruptNumber,u8 *Copy_u8InterruptReadingActive);

/*
 * Description  :Function to set Software Priority
 * Input  		:Interrupt Number in vector table ,	Group Priority ,Sub Priority,Priority Configuration Select
 * Return		:no return
 */
 extern void NVIC_u8SetSoftwarePerority(u8 Copy_u8InterruptNumber,u8 Copy_u8GroupPeriorty,u8 Copy_SubPeriorty);

#endif
