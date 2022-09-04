/****************************************************************************************************************************************/
/***********************************************	Author  : Doaa Mohamed  *************************************************************/
/***********************************************	Layer  : MCAL           *************************************************************/
/***********************************************	Date    : 11 March 2022 *************************************************************/
/***********************************************	Version : V1            *************************************************************/
/****************************************************************************************************************************************/

#ifndef _NVIC_CONFIG_H_
#define _NVIC_CONFIG_H_


/********************************** Interrupt set-enable registers (NVIC_ISERx) *************************************/
/********************************************************************************************************************/

/* Output Pin Options:
 *
 * 		ENABLE
 * 		DISABLE
 */
#define NVIC_ISER0_PIN0_INITIAL_VALUE    DISABLE             /*  NVIC_WWDT_POS       */
#define NVIC_ISER0_PIN1_INITIAL_VALUE    DISABLE             /*  NVIC_PVD_POS        */
#define NVIC_ISER0_PIN2_INITIAL_VALUE    DISABLE             /*  NVIC_TAMPER_POS     */
#define NVIC_ISER0_PIN3_INITIAL_VALUE    DISABLE             /*  NVIC_RTC_POS        */
#define NVIC_ISER0_PIN4_INITIAL_VALUE    DISABLE             /*  NVIC_FLASH_POS      */
#define NVIC_ISER0_PIN5_INITIAL_VALUE    DISABLE             /*  NVIC_RCC_POS        */
#define NVIC_ISER0_PIN6_INITIAL_VALUE    ENABLE              /*  NVIC_EXTI0_POS      */
#define NVIC_ISER0_PIN7_INITIAL_VALUE    DISABLE             /*  NVIC_EXTI1_POS      */
#define NVIC_ISER0_PIN8_INITIAL_VALUE    DISABLE             /*  NVIC_EXTI2_POS      */
#define NVIC_ISER0_PIN9_INITIAL_VALUE    DISABLE             /*  NVIC_EXTI3_POS      */
#define NVIC_ISER0_PIN10_INITIAL_VALUE   DISABLE             /*  NVIC_EXTI4_POS      */
#define NVIC_ISER0_PIN11_INITIAL_VALUE   DISABLE             /*  NVIC_DMA1_CH1_POS   */
#define NVIC_ISER0_PIN12_INITIAL_VALUE   DISABLE             /*  NVIC_DMA1_CH2_POS   */
#define NVIC_ISER0_PIN13_INITIAL_VALUE   DISABLE             /*  NVIC_DMA1_CH3_POS   */
#define NVIC_ISER0_PIN14_INITIAL_VALUE   DISABLE             /*  NVIC_DMA1_CH4_POS   */
#define NVIC_ISER0_PIN15_INITIAL_VALUE   DISABLE             /*  NVIC_DMA1_CH5_POS   */
#define NVIC_ISER0_PIN16_INITIAL_VALUE   DISABLE             /*  NVIC_DMA1_CH6_POS   */
#define NVIC_ISER0_PIN17_INITIAL_VALUE   DISABLE             /*  NVIC_DMA1_CH7_POS   */
#define NVIC_ISER0_PIN18_INITIAL_VALUE   DISABLE             /*  NVIC_ADC1_2_POS     */
#define NVIC_ISER0_PIN19_INITIAL_VALUE   DISABLE             /*  NVIC_CAN1_TX_POS    */
#define NVIC_ISER0_PIN20_INITIAL_VALUE   DISABLE             /*  NVIC_CAN1_RX0_POS   */
#define NVIC_ISER0_PIN21_INITIAL_VALUE   DISABLE             /*  NVIC_CAN1_RX1_POS   */
#define NVIC_ISER0_PIN22_INITIAL_VALUE   DISABLE             /*  NVIC_CAN1_SCE_POS   */
#define NVIC_ISER0_PIN23_INITIAL_VALUE   ENABLE             /*  NVIC_EXTI9_5_POS    */
#define NVIC_ISER0_PIN24_INITIAL_VALUE   DISABLE             /*  NVIC_TIM1_BRK_POS   */
#define NVIC_ISER0_PIN25_INITIAL_VALUE   DISABLE             /*  NVIC_TIM1_UP_POS    */
#define NVIC_ISER0_PIN26_INITIAL_VALUE   DISABLE             /*  NVIC_TIM1_TRG_COM_  */
#define NVIC_ISER0_PIN27_INITIAL_VALUE   DISABLE             /*  NVIC_TIM1_CC_POS    */
#define NVIC_ISER0_PIN28_INITIAL_VALUE   DISABLE             /*  NVIC_TIM2_POS       */
#define NVIC_ISER0_PIN29_INITIAL_VALUE   DISABLE             /*  NVIC_TIM3_POS       */
#define NVIC_ISER0_PIN30_INITIAL_VALUE   DISABLE             /*  NVIC_TIM4_POS       */
#define NVIC_ISER0_PIN31_INITIAL_VALUE   DISABLE             /*  NVIC_I2C1_EV_POS    */





/*for externals interrupts from [32 : 63]*/
#define NVIC_ISER1_PIN0_INITIAL_VALUE     DISABLE            /* NVIC_I2C1_ER_POS      */
#define NVIC_ISER1_PIN1_INITIAL_VALUE     DISABLE            /* NVIC_I2C2_EV_POS      */
#define NVIC_ISER1_PIN2_INITIAL_VALUE     DISABLE            /* NVIC_I2C2_ER_POS      */
#define NVIC_ISER1_PIN3_INITIAL_VALUE     DISABLE            /* NVIC_SPI1_POS         */
#define NVIC_ISER1_PIN4_INITIAL_VALUE     DISABLE            /* NVIC_SPI2_POS         */
#define NVIC_ISER1_PIN5_INITIAL_VALUE     DISABLE            /* NVIC_USART1_POS       */
#define NVIC_ISER1_PIN6_INITIAL_VALUE     DISABLE            /* NVIC_USART2_POS       */
#define NVIC_ISER1_PIN7_INITIAL_VALUE     DISABLE            /* NVIC_USART3_POS       */
#define NVIC_ISER1_PIN8_INITIAL_VALUE     DISABLE            /* NVIC_EXTI15_10_POS    */
#define NVIC_ISER1_PIN9_INITIAL_VALUE     DISABLE            /* NVIC_RTCAlarm_POS     */
#define NVIC_ISER1_PIN10_INITIAL_VALUE    DISABLE            /* NVIC_ OTG_FS_WKUP_POS */
#define NVIC_ISER1_PIN11_INITIAL_VALUE    DISABLE            /* NVIC_TMR5_POS         */
#define NVIC_ISER1_PIN12_INITIAL_VALUE    DISABLE            /* NVIC_SPI3_POS         */
#define NVIC_ISER1_PIN13_INITIAL_VALUE    DISABLE            /* NVIC_UART4_POS        */
#define NVIC_ISER1_PIN14_INITIAL_VALUE    DISABLE            /* NVIC_UART5_POS        */
#define NVIC_ISER1_PIN15_INITIAL_VALUE    DISABLE            /* NVIC_TIM6_POS         */
#define NVIC_ISER1_PIN16_INITIAL_VALUE    DISABLE            /* NVIC_TIM7_POS         */
#define NVIC_ISER1_PIN17_INITIAL_VALUE    DISABLE            /* NVIC_DMA2_CH1_POS     */
#define NVIC_ISER1_PIN18_INITIAL_VALUE    DISABLE            /* NVIC_DMA2_CH2_POS     */
#define NVIC_ISER1_PIN19_INITIAL_VALUE    DISABLE            /* NVIC_DMA2_CH3_POS     */
#define NVIC_ISER1_PIN20_INITIAL_VALUE    DISABLE            /* NVIC_DMA2_CH4_POS     */
#define NVIC_ISER1_PIN21_INITIAL_VALUE    DISABLE            /* NVIC_DMA2_CH5_POS     */
#define NVIC_ISER1_PIN22_INITIAL_VALUE    DISABLE            /* NVIC_ETH_POS          */
#define NVIC_ISER1_PIN23_INITIAL_VALUE    DISABLE            /* NVIC_ETH_WKUP_POS     */
#define NVIC_ISER1_PIN24_INITIAL_VALUE    DISABLE            /* NVIC_CAN2_TX_POS      */
#define NVIC_ISER1_PIN25_INITIAL_VALUE    DISABLE            /* NVIC_CAN2_RX0_POS     */
#define NVIC_ISER1_PIN26_INITIAL_VALUE    DISABLE            /* NVIC_CAN2_RX1_POS     */
#define NVIC_ISER1_PIN27_INITIAL_VALUE    DISABLE            /* NVIC_CAN2_SCE_POS     */
#define NVIC_ISER1_PIN28_INITIAL_VALUE    DISABLE            /* NVIC_OTG_FS_POS       */
#define NVIC_ISER1_PIN29_INITIAL_VALUE    DISABLE
#define NVIC_ISER1_PIN30_INITIAL_VALUE    DISABLE
#define NVIC_ISER1_PIN31_INITIAL_VALUE    DISABLE



/********************************** Interrupt clear-enable re*************************************/
/*************************************************************************************************/

/* Output Pin Options:
 *
 * 		ENABLE
 * 		DISABLE
 */
#define NVIC_ICER0_PIN0_INITIAL_VALUE    DISABLE              /*  NVIC_WWDT_POS       */
#define NVIC_ICER0_PIN1_INITIAL_VALUE    DISABLE              /*  NVIC_PVD_POS        */
#define NVIC_ICER0_PIN2_INITIAL_VALUE    DISABLE              /*  NVIC_TAMPER_POS     */
#define NVIC_ICER0_PIN3_INITIAL_VALUE    DISABLE              /*  NVIC_RTC_POS        */
#define NVIC_ICER0_PIN4_INITIAL_VALUE    DISABLE              /*  NVIC_FLASH_POS      */
#define NVIC_ICER0_PIN5_INITIAL_VALUE    DISABLE              /*  NVIC_RCC_POS        */
#define NVIC_ICER0_PIN6_INITIAL_VALUE    DISABLE              /*  NVIC_EXTI0_POS      */
#define NVIC_ICER0_PIN7_INITIAL_VALUE    DISABLE              /*  NVIC_EXTI1_POS      */
#define NVIC_ICER0_PIN8_INITIAL_VALUE    DISABLE              /*  NVIC_EXTI2_POS      */
#define NVIC_ICER0_PIN9_INITIAL_VALUE    DISABLE              /*  NVIC_EXTI3_POS      */
#define NVIC_ICER0_PIN10_INITIAL_VALUE   DISABLE              /*  NVIC_EXTI4_POS      */
#define NVIC_ICER0_PIN11_INITIAL_VALUE   DISABLE              /*  NVIC_DMA1_CH1_POS   */
#define NVIC_ICER0_PIN12_INITIAL_VALUE   DISABLE              /*  NVIC_DMA1_CH2_POS   */
#define NVIC_ICER0_PIN13_INITIAL_VALUE   DISABLE              /*  NVIC_DMA1_CH3_POS   */
#define NVIC_ICER0_PIN14_INITIAL_VALUE   DISABLE              /*  NVIC_DMA1_CH4_POS   */
#define NVIC_ICER0_PIN15_INITIAL_VALUE   DISABLE              /*  NVIC_DMA1_CH5_POS   */
#define NVIC_ICER0_PIN16_INITIAL_VALUE   DISABLE              /*  NVIC_DMA1_CH6_POS   */
#define NVIC_ICER0_PIN17_INITIAL_VALUE   DISABLE              /*  NVIC_DMA1_CH7_POS   */
#define NVIC_ICER0_PIN18_INITIAL_VALUE   DISABLE              /*  NVIC_ADC1_2_POS     */
#define NVIC_ICER0_PIN19_INITIAL_VALUE   DISABLE              /*  NVIC_CAN1_TX_POS    */
#define NVIC_ICER0_PIN20_INITIAL_VALUE   DISABLE              /*  NVIC_CAN1_RX0_POS   */
#define NVIC_ICER0_PIN21_INITIAL_VALUE   DISABLE              /*  NVIC_CAN1_RX1_POS   */
#define NVIC_ICER0_PIN22_INITIAL_VALUE   DISABLE              /*  NVIC_CAN1_SCE_POS   */
#define NVIC_ICER0_PIN23_INITIAL_VALUE   DISABLE              /*  NVIC_EXTI9_5_POS    */
#define NVIC_ICER0_PIN24_INITIAL_VALUE   DISABLE              /*  NVIC_TIM1_BRK_POS   */
#define NVIC_ICER0_PIN25_INITIAL_VALUE   DISABLE              /*  NVIC_TIM1_UP_POS    */
#define NVIC_ICER0_PIN26_INITIAL_VALUE   DISABLE              /*  NVIC_TIM1_TRG_COM_  */
#define NVIC_ICER0_PIN27_INITIAL_VALUE   DISABLE              /*  NVIC_TIM1_CC_POS    */
#define NVIC_ICER0_PIN28_INITIAL_VALUE   DISABLE              /*  NVIC_TIM2_POS       */
#define NVIC_ICER0_PIN29_INITIAL_VALUE   DISABLE              /*  NVIC_TIM3_POS       */
#define NVIC_ICER0_PIN30_INITIAL_VALUE   DISABLE              /*  NVIC_TIM4_POS       */
#define NVIC_ICER0_PIN31_INITIAL_VALUE   DISABLE              /*  NVIC_I2C1_EV_POS    */

/*for externals interrupts from [32 : 63]*/
#define NVIC_ICER1_PIN0_INITIAL_VALUE     DISABLE             /* NVIC_I2C1_ER_POS      */
#define NVIC_ICER1_PIN1_INITIAL_VALUE     DISABLE             /* NVIC_I2C2_EV_POS      */
#define NVIC_ICER1_PIN2_INITIAL_VALUE     DISABLE             /* NVIC_I2C2_ER_POS      */
#define NVIC_ICER1_PIN3_INITIAL_VALUE     DISABLE             /* NVIC_SPI1_POS         */
#define NVIC_ICER1_PIN4_INITIAL_VALUE     DISABLE             /* NVIC_SPI2_POS         */
#define NVIC_ICER1_PIN5_INITIAL_VALUE     DISABLE             /* NVIC_USART1_POS       */
#define NVIC_ICER1_PIN6_INITIAL_VALUE     DISABLE             /* NVIC_USART2_POS       */
#define NVIC_ICER1_PIN7_INITIAL_VALUE     DISABLE             /* NVIC_USART3_POS       */
#define NVIC_ICER1_PIN8_INITIAL_VALUE     DISABLE             /* NVIC_EXTI15_10_POS    */
#define NVIC_ICER1_PIN9_INITIAL_VALUE     DISABLE             /* NVIC_RTCAlarm_POS     */
#define NVIC_ICER1_PIN10_INITIAL_VALUE    DISABLE             /* NVIC_ OTG_FS_WKUP_POS */
#define NVIC_ICER1_PIN11_INITIAL_VALUE    DISABLE             /* NVIC_TMR5_POS         */
#define NVIC_ICER1_PIN12_INITIAL_VALUE    DISABLE             /* NVIC_SPI3_POS         */
#define NVIC_ICER1_PIN13_INITIAL_VALUE    DISABLE             /* NVIC_UART4_POS        */
#define NVIC_ICER1_PIN14_INITIAL_VALUE    DISABLE             /* NVIC_UART5_POS        */
#define NVIC_ICER1_PIN15_INITIAL_VALUE    DISABLE             /* NVIC_TIM6_POS         */
#define NVIC_ICER1_PIN16_INITIAL_VALUE    DISABLE             /* NVIC_TIM7_POS         */
#define NVIC_ICER1_PIN17_INITIAL_VALUE    DISABLE             /* NVIC_DMA2_CH1_POS     */
#define NVIC_ICER1_PIN18_INITIAL_VALUE    DISABLE             /* NVIC_DMA2_CH2_POS     */
#define NVIC_ICER1_PIN19_INITIAL_VALUE    DISABLE             /* NVIC_DMA2_CH3_POS     */
#define NVIC_ICER1_PIN20_INITIAL_VALUE    DISABLE             /* NVIC_DMA2_CH4_POS     */
#define NVIC_ICER1_PIN21_INITIAL_VALUE    DISABLE             /* NVIC_DMA2_CH5_POS     */
#define NVIC_ICER1_PIN22_INITIAL_VALUE    DISABLE             /* NVIC_ETH_POS          */
#define NVIC_ICER1_PIN23_INITIAL_VALUE    DISABLE             /* NVIC_ETH_WKUP_POS     */
#define NVIC_ICER1_PIN24_INITIAL_VALUE    DISABLE             /* NVIC_CAN2_TX_POS      */
#define NVIC_ICER1_PIN25_INITIAL_VALUE    DISABLE             /* NVIC_CAN2_RX0_POS     */
#define NVIC_ICER1_PIN26_INITIAL_VALUE    DISABLE             /* NVIC_CAN2_RX1_POS     */
#define NVIC_ICER1_PIN27_INITIAL_VALUE    DISABLE             /* NVIC_CAN2_SCE_POS     */
#define NVIC_ICER1_PIN28_INITIAL_VALUE    DISABLE             /* NVIC_OTG_FS_POS       */
#define NVIC_ICER1_PIN29_INITIAL_VALUE    DISABLE
#define NVIC_ICER1_PIN30_INITIAL_VALUE    DISABLE
#define NVIC_ICER1_PIN31_INITIAL_VALUE    DISABLE


/********************************** Interrupt clear-pending registers (NVIC_ICPRx) *************************************/
/**********************************************************************************************************************/
/* Output Pin Options:
 *
 * 		ENABLE
 * 		DISABLE
 */

#define NVIC_ICPR0_PIN0_INITIAL_VALUE    DISABLE              /*  NVIC_WWDT_POS       */
#define NVIC_ICPR0_PIN1_INITIAL_VALUE    DISABLE              /*  NVIC_PVD_POS        */
#define NVIC_ICPR0_PIN2_INITIAL_VALUE    DISABLE              /*  NVIC_TAMPER_POS     */
#define NVIC_ICPR0_PIN3_INITIAL_VALUE    DISABLE              /*  NVIC_RTC_POS        */
#define NVIC_ICPR0_PIN4_INITIAL_VALUE    DISABLE              /*  NVIC_FLASH_POS      */
#define NVIC_ICPR0_PIN5_INITIAL_VALUE    DISABLE              /*  NVIC_RCC_POS        */
#define NVIC_ICPR0_PIN6_INITIAL_VALUE    DISABLE              /*  NVIC_EXTI0_POS      */
#define NVIC_ICPR0_PIN7_INITIAL_VALUE    DISABLE              /*  NVIC_EXTI1_POS      */
#define NVIC_ICPR0_PIN8_INITIAL_VALUE    DISABLE              /*  NVIC_EXTI2_POS      */
#define NVIC_ICPR0_PIN9_INITIAL_VALUE    DISABLE              /*  NVIC_EXTI3_POS      */
#define NVIC_ICPR0_PIN10_INITIAL_VALUE   DISABLE              /*  NVIC_EXTI4_POS      */
#define NVIC_ICPR0_PIN11_INITIAL_VALUE   DISABLE              /*  NVIC_DMA1_CH1_POS   */
#define NVIC_ICPR0_PIN12_INITIAL_VALUE   DISABLE              /*  NVIC_DMA1_CH2_POS   */
#define NVIC_ICPR0_PIN13_INITIAL_VALUE   DISABLE              /*  NVIC_DMA1_CH3_POS   */
#define NVIC_ICPR0_PIN14_INITIAL_VALUE   DISABLE              /*  NVIC_DMA1_CH4_POS   */
#define NVIC_ICPR0_PIN15_INITIAL_VALUE   DISABLE              /*  NVIC_DMA1_CH5_POS   */
#define NVIC_ICPR0_PIN16_INITIAL_VALUE   DISABLE              /*  NVIC_DMA1_CH6_POS   */
#define NVIC_ICPR0_PIN17_INITIAL_VALUE   DISABLE              /*  NVIC_DMA1_CH7_POS   */
#define NVIC_ICPR0_PIN18_INITIAL_VALUE   DISABLE              /*  NVIC_ADC1_2_POS     */
#define NVIC_ICPR0_PIN19_INITIAL_VALUE   DISABLE              /*  NVIC_CAN1_TX_POS    */
#define NVIC_ICPR0_PIN20_INITIAL_VALUE   DISABLE              /*  NVIC_CAN1_RX0_POS   */
#define NVIC_ICPR0_PIN21_INITIAL_VALUE   DISABLE              /*  NVIC_CAN1_RX1_POS   */
#define NVIC_ICPR0_PIN22_INITIAL_VALUE   DISABLE              /*  NVIC_CAN1_SCE_POS   */
#define NVIC_ICPR0_PIN23_INITIAL_VALUE   DISABLE              /*  NVIC_EXTI9_5_POS    */
#define NVIC_ICPR0_PIN24_INITIAL_VALUE   DISABLE              /*  NVIC_TIM1_BRK_POS   */
#define NVIC_ICPR0_PIN25_INITIAL_VALUE   DISABLE              /*  NVIC_TIM1_UP_POS    */
#define NVIC_ICPR0_PIN26_INITIAL_VALUE   DISABLE              /*  NVIC_TIM1_TRG_COM_  */
#define NVIC_ICPR0_PIN27_INITIAL_VALUE   DISABLE              /*  NVIC_TIM1_CC_POS    */
#define NVIC_ICPR0_PIN28_INITIAL_VALUE   DISABLE              /*  NVIC_TIM2_POS       */
#define NVIC_ICPR0_PIN29_INITIAL_VALUE   DISABLE              /*  NVIC_TIM3_POS       */
#define NVIC_ICPR0_PIN30_INITIAL_VALUE   DISABLE              /*  NVIC_TIM4_POS       */
#define NVIC_ICPR0_PIN31_INITIAL_VALUE   DISABLE              /*  NVIC_I2C1_EV_POS    */

/*for externals interrupts from [32 : 63]*/
#define NVIC_ICPR1_PIN0_INITIAL_VALUE     DISABLE             /* NVIC_I2C1_ER_POS      */
#define NVIC_ICPR1_PIN1_INITIAL_VALUE     DISABLE             /* NVIC_I2C2_EV_POS      */
#define NVIC_ICPR1_PIN2_INITIAL_VALUE     DISABLE             /* NVIC_I2C2_ER_POS      */
#define NVIC_ICPR1_PIN3_INITIAL_VALUE     DISABLE             /* NVIC_SPI1_POS         */
#define NVIC_ICPR1_PIN4_INITIAL_VALUE     DISABLE             /* NVIC_SPI2_POS         */
#define NVIC_ICPR1_PIN5_INITIAL_VALUE     DISABLE             /* NVIC_USART1_POS       */
#define NVIC_ICPR1_PIN6_INITIAL_VALUE     DISABLE             /* NVIC_USART2_POS       */
#define NVIC_ICPR1_PIN7_INITIAL_VALUE     DISABLE             /* NVIC_USART3_POS       */
#define NVIC_ICPR1_PIN8_INITIAL_VALUE     DISABLE             /* NVIC_EXTI15_10_POS    */
#define NVIC_ICPR1_PIN9_INITIAL_VALUE     DISABLE             /* NVIC_RTCAlarm_POS     */
#define NVIC_ICPR1_PIN10_INITIAL_VALUE    DISABLE             /* NVIC_ OTG_FS_WKUP_POS */
#define NVIC_ICPR1_PIN11_INITIAL_VALUE    DISABLE             /* NVIC_TMR5_POS         */
#define NVIC_ICPR1_PIN12_INITIAL_VALUE    DISABLE             /* NVIC_SPI3_POS         */
#define NVIC_ICPR1_PIN13_INITIAL_VALUE    DISABLE             /* NVIC_UART4_POS        */
#define NVIC_ICPR1_PIN14_INITIAL_VALUE    DISABLE             /* NVIC_UART5_POS        */
#define NVIC_ICPR1_PIN15_INITIAL_VALUE    DISABLE             /* NVIC_TIM6_POS         */
#define NVIC_ICPR1_PIN16_INITIAL_VALUE    DISABLE             /* NVIC_TIM7_POS         */
#define NVIC_ICPR1_PIN17_INITIAL_VALUE    DISABLE             /* NVIC_DMA2_CH1_POS     */
#define NVIC_ICPR1_PIN18_INITIAL_VALUE    DISABLE             /* NVIC_DMA2_CH2_POS     */
#define NVIC_ICPR1_PIN19_INITIAL_VALUE    DISABLE             /* NVIC_DMA2_CH3_POS     */
#define NVIC_ICPR1_PIN20_INITIAL_VALUE    DISABLE             /* NVIC_DMA2_CH4_POS     */
#define NVIC_ICPR1_PIN21_INITIAL_VALUE    DISABLE             /* NVIC_DMA2_CH5_POS     */
#define NVIC_ICPR1_PIN22_INITIAL_VALUE    DISABLE             /* NVIC_ETH_POS          */
#define NVIC_ICPR1_PIN23_INITIAL_VALUE    DISABLE             /* NVIC_ETH_WKUP_POS     */
#define NVIC_ICPR1_PIN24_INITIAL_VALUE    DISABLE             /* NVIC_CAN2_TX_POS      */
#define NVIC_ICPR1_PIN25_INITIAL_VALUE    DISABLE             /* NVIC_CAN2_RX0_POS     */
#define NVIC_ICPR1_PIN26_INITIAL_VALUE    DISABLE             /* NVIC_CAN2_RX1_POS     */
#define NVIC_ICPR1_PIN27_INITIAL_VALUE    DISABLE             /* NVIC_CAN2_SCE_POS     */
#define NVIC_ICPR1_PIN28_INITIAL_VALUE    DISABLE             /* NVIC_OTG_FS_POS       */
#define NVIC_ICPR1_PIN29_INITIAL_VALUE    DISABLE
#define NVIC_ICPR1_PIN30_INITIAL_VALUE    DISABLE
#define NVIC_ICPR1_PIN31_INITIAL_VALUE    DISABLE



/********************************** Interrupt Set-pending registers (NVIC_ICPRx) *************************************/
/**********************************************************************************************************************/
/* Output Pin Options:
 *
 * 		ENABLE
 * 		DISABLE
 */

#define NVIC_ISPR0_PIN0_INITIAL_VALUE    DISABLE              /*  NVIC_WWDT_POS       */
#define NVIC_ISPR0_PIN1_INITIAL_VALUE    DISABLE              /*  NVIC_PVD_POS        */
#define NVIC_ISPR0_PIN2_INITIAL_VALUE    DISABLE              /*  NVIC_TAMPER_POS     */
#define NVIC_ISPR0_PIN3_INITIAL_VALUE    DISABLE              /*  NVIC_RTC_POS        */
#define NVIC_ISPR0_PIN4_INITIAL_VALUE    DISABLE              /*  NVIC_FLASH_POS      */
#define NVIC_ISPR0_PIN5_INITIAL_VALUE    DISABLE              /*  NVIC_RCC_POS        */
#define NVIC_ISPR0_PIN6_INITIAL_VALUE    DISABLE               /*  NVIC_EXTI0_POS      */
#define NVIC_ISPR0_PIN7_INITIAL_VALUE    DISABLE              /*  NVIC_EXTI1_POS      */
#define NVIC_ISPR0_PIN8_INITIAL_VALUE    DISABLE              /*  NVIC_EXTI2_POS      */
#define NVIC_ISPR0_PIN9_INITIAL_VALUE    DISABLE              /*  NVIC_EXTI3_POS      */
#define NVIC_ISPR0_PIN10_INITIAL_VALUE   DISABLE              /*  NVIC_EXTI4_POS      */
#define NVIC_ISPR0_PIN11_INITIAL_VALUE   DISABLE              /*  NVIC_DMA1_CH1_POS   */
#define NVIC_ISPR0_PIN12_INITIAL_VALUE   DISABLE              /*  NVIC_DMA1_CH2_POS   */
#define NVIC_ISPR0_PIN13_INITIAL_VALUE   DISABLE              /*  NVIC_DMA1_CH3_POS   */
#define NVIC_ISPR0_PIN14_INITIAL_VALUE   DISABLE              /*  NVIC_DMA1_CH4_POS   */
#define NVIC_ISPR0_PIN15_INITIAL_VALUE   DISABLE              /*  NVIC_DMA1_CH5_POS   */
#define NVIC_ISPR0_PIN16_INITIAL_VALUE   DISABLE              /*  NVIC_DMA1_CH6_POS   */
#define NVIC_ISPR0_PIN17_INITIAL_VALUE   DISABLE              /*  NVIC_DMA1_CH7_POS   */
#define NVIC_ISPR0_PIN18_INITIAL_VALUE   DISABLE              /*  NVIC_ADC1_2_POS     */
#define NVIC_ISPR0_PIN19_INITIAL_VALUE   DISABLE              /*  NVIC_CAN1_TX_POS    */
#define NVIC_ISPR0_PIN20_INITIAL_VALUE   DISABLE              /*  NVIC_CAN1_RX0_POS   */
#define NVIC_ISPR0_PIN21_INITIAL_VALUE   DISABLE              /*  NVIC_CAN1_RX1_POS   */
#define NVIC_ISPR0_PIN22_INITIAL_VALUE   DISABLE              /*  NVIC_CAN1_SCE_POS   */
#define NVIC_ISPR0_PIN23_INITIAL_VALUE   DISABLE              /*  NVIC_EXTI9_5_POS    */
#define NVIC_ISPR0_PIN24_INITIAL_VALUE   DISABLE              /*  NVIC_TIM1_BRK_POS   */
#define NVIC_ISPR0_PIN25_INITIAL_VALUE   DISABLE              /*  NVIC_TIM1_UP_POS    */
#define NVIC_ISPR0_PIN26_INITIAL_VALUE   DISABLE              /*  NVIC_TIM1_TRG_COM_  */
#define NVIC_ISPR0_PIN27_INITIAL_VALUE   DISABLE              /*  NVIC_TIM1_CC_POS    */
#define NVIC_ISPR0_PIN28_INITIAL_VALUE   DISABLE              /*  NVIC_TIM2_POS       */
#define NVIC_ISPR0_PIN29_INITIAL_VALUE   DISABLE              /*  NVIC_TIM3_POS       */
#define NVIC_ISPR0_PIN30_INITIAL_VALUE   DISABLE              /*  NVIC_TIM4_POS       */
#define NVIC_ISPR0_PIN31_INITIAL_VALUE   DISABLE              /*  NVIC_I2C1_EV_POS    */

/*for externals interrupts from [32 : 63]*/
#define NVIC_ISPR1_PIN0_INITIAL_VALUE     DISABLE             /* NVIC_I2C1_ER_POS      */
#define NVIC_ISPR1_PIN1_INITIAL_VALUE     DISABLE             /* NVIC_I2C2_EV_POS      */
#define NVIC_ISPR1_PIN2_INITIAL_VALUE     DISABLE             /* NVIC_I2C2_ER_POS      */
#define NVIC_ISPR1_PIN3_INITIAL_VALUE     DISABLE             /* NVIC_SPI1_POS         */
#define NVIC_ISPR1_PIN4_INITIAL_VALUE     DISABLE             /* NVIC_SPI2_POS         */
#define NVIC_ISPR1_PIN5_INITIAL_VALUE     DISABLE             /* NVIC_USART1_POS       */
#define NVIC_ISPR1_PIN6_INITIAL_VALUE     DISABLE             /* NVIC_USART2_POS       */
#define NVIC_ISPR1_PIN7_INITIAL_VALUE     DISABLE             /* NVIC_USART3_POS       */
#define NVIC_ISPR1_PIN8_INITIAL_VALUE     DISABLE             /* NVIC_EXTI15_10_POS    */
#define NVIC_ISPR1_PIN9_INITIAL_VALUE     DISABLE             /* NVIC_RTCAlarm_POS     */
#define NVIC_ISPR1_PIN10_INITIAL_VALUE    DISABLE             /* NVIC_ OTG_FS_WKUP_POS */
#define NVIC_ISPR1_PIN11_INITIAL_VALUE    DISABLE             /* NVIC_TMR5_POS         */
#define NVIC_ISPR1_PIN12_INITIAL_VALUE    DISABLE             /* NVIC_SPI3_POS         */
#define NVIC_ISPR1_PIN13_INITIAL_VALUE    DISABLE             /* NVIC_UART4_POS        */
#define NVIC_ISPR1_PIN14_INITIAL_VALUE    DISABLE             /* NVIC_UART5_POS        */
#define NVIC_ISPR1_PIN15_INITIAL_VALUE    DISABLE             /* NVIC_TIM6_POS         */
#define NVIC_ISPR1_PIN16_INITIAL_VALUE    DISABLE             /* NVIC_TIM7_POS         */
#define NVIC_ISPR1_PIN17_INITIAL_VALUE    DISABLE             /* NVIC_DMA2_CH1_POS     */
#define NVIC_ISPR1_PIN18_INITIAL_VALUE    DISABLE             /* NVIC_DMA2_CH2_POS     */
#define NVIC_ISPR1_PIN19_INITIAL_VALUE    DISABLE             /* NVIC_DMA2_CH3_POS     */
#define NVIC_ISPR1_PIN20_INITIAL_VALUE    DISABLE             /* NVIC_DMA2_CH4_POS     */
#define NVIC_ISPR1_PIN21_INITIAL_VALUE    DISABLE             /* NVIC_DMA2_CH5_POS     */
#define NVIC_ISPR1_PIN22_INITIAL_VALUE    DISABLE             /* NVIC_ETH_POS          */
#define NVIC_ISPR1_PIN23_INITIAL_VALUE    DISABLE             /* NVIC_ETH_WKUP_POS     */
#define NVIC_ISPR1_PIN24_INITIAL_VALUE    DISABLE             /* NVIC_CAN2_TX_POS      */
#define NVIC_ISPR1_PIN25_INITIAL_VALUE    DISABLE             /* NVIC_CAN2_RX0_POS     */
#define NVIC_ISPR1_PIN26_INITIAL_VALUE    DISABLE             /* NVIC_CAN2_RX1_POS     */
#define NVIC_ISPR1_PIN27_INITIAL_VALUE    DISABLE             /* NVIC_CAN2_SCE_POS     */
#define NVIC_ISPR1_PIN28_INITIAL_VALUE    DISABLE             /* NVIC_OTG_FS_POS       */
#define NVIC_ISPR1_PIN29_INITIAL_VALUE    DISABLE
#define NVIC_ISPR1_PIN30_INITIAL_VALUE    DISABLE
#define NVIC_ISPR1_PIN31_INITIAL_VALUE    DISABLE

/* to select the bits of Group and Subgroup ->Numbers
 *Options:
 *      NVIC_PRIORTY_GROUP_16_SUB_0
 *      NVIC_PRIORTY_GROUP_8_SUB_2
 *      NVIC_PRIORTY_GROUP_4_SUB_4
 *      NVIC_PRIORTY_GROUP_2_SUB_8
 *      NVIC_PRIORTY_GROUP_0_SUB_16
 */

#define NVIC_GROUP_SUB_CONFIGURATIONS NVIC_PRIORTY_GROUP_4_SUB_4

#endif
