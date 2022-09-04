
/****************************************************************************************************************************************/
/***********************************************	Author  : Doaa Mohamed  *************************************************************/
/***********************************************	Layer  : MCAL           *************************************************************/
/***********************************************	Date    : 11 March 2022 ************************************************************/
/***********************************************	Version : V1            *************************************************************/
/****************************************************************************************************************************************/

#ifndef _NVIC_PRIVATE_H_
#define _NVIC_PRIVATE_H_

#define NVICC_BASE_ADDRESS  0xE000E100

#define CONCAT(b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0)   CONC(b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0)
#define CONC(b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0)     0b##b31##b30##b29##b28##b27##b26##b25##b24##b23##b22##b21##b20##b19##b18##b17##b16##b15##b14##b13##b12##b11##b10##b9##b8##b7##b6##b5##b4##b3##b2##b1##b0


/********************************** Interrupt set-enable registers (NVIC_ISERx) *************************************/
/********************************************************************************************************************/

#define NVIC_ISER0_REG  *((volatile u32*)(NVICC_BASE_ADDRESS+0x000))
#define NVIC_ISER1_REG  *((volatile u32*)(NVICC_BASE_ADDRESS+0x004))


#define NVIC_ISER0_INITIAL_VALUE  CONCAT(NVIC_ISER0_PIN31_INITIAL_VALUE,NVIC_ISER0_PIN30_INITIAL_VALUE,NVIC_ISER0_PIN29_INITIAL_VALUE,NVIC_ISER0_PIN28_INITIAL_VALUE      ,NVIC_ISER0_PIN27_INITIAL_VALUE,NVIC_ISER0_PIN26_INITIAL_VALUE,NVIC_ISER0_PIN25_INITIAL_VALUE,NVIC_ISER0_PIN24_INITIAL_VALUE,         NVIC_ISER0_PIN23_INITIAL_VALUE,NVIC_ISER0_PIN22_INITIAL_VALUE,NVIC_ISER0_PIN21_INITIAL_VALUE,NVIC_ISER0_PIN20_INITIAL_VALUE       ,NVIC_ISER0_PIN19_INITIAL_VALUE,NVIC_ISER0_PIN18_INITIAL_VALUE,NVIC_ISER0_PIN17_INITIAL_VALUE,NVIC_ISER0_PIN16_INITIAL_VALUE        ,NVIC_ISER0_PIN15_INITIAL_VALUE,NVIC_ISER0_PIN14_INITIAL_VALUE,NVIC_ISER0_PIN13_INITIAL_VALUE,NVIC_ISER0_PIN12_INITIAL_VALUE       ,NVIC_ISER0_PIN11_INITIAL_VALUE,NVIC_ISER0_PIN10_INITIAL_VALUE,NVIC_ISER0_PIN9_INITIAL_VALUE,NVIC_ISER0_PIN8_INITIAL_VALUE       ,NVIC_ISER0_PIN7_INITIAL_VALUE,NVIC_ISER0_PIN6_INITIAL_VALUE,NVIC_ISER0_PIN5_INITIAL_VALUE,NVIC_ISER0_PIN4_INITIAL_VALUE    ,NVIC_ISER0_PIN3_INITIAL_VALUE,NVIC_ISER0_PIN2_INITIAL_VALUE,NVIC_ISER0_PIN1_INITIAL_VALUE,NVIC_ISER0_PIN0_INITIAL_VALUE)
#define NVIC_ISER1_INITIAL_VALUE  CONCAT(NVIC_ISER1_PIN31_INITIAL_VALUE,NVIC_ISER1_PIN30_INITIAL_VALUE,NVIC_ISER1_PIN29_INITIAL_VALUE,NVIC_ISER1_PIN28_INITIAL_VALUE      ,NVIC_ISER1_PIN27_INITIAL_VALUE,NVIC_ISER1_PIN26_INITIAL_VALUE,NVIC_ISER1_PIN25_INITIAL_VALUE,NVIC_ISER1_PIN24_INITIAL_VALUE,         NVIC_ISER1_PIN23_INITIAL_VALUE,NVIC_ISER1_PIN22_INITIAL_VALUE,NVIC_ISER1_PIN21_INITIAL_VALUE,NVIC_ISER1_PIN20_INITIAL_VALUE       ,NVIC_ISER1_PIN19_INITIAL_VALUE,NVIC_ISER1_PIN18_INITIAL_VALUE,NVIC_ISER1_PIN17_INITIAL_VALUE,NVIC_ISER1_PIN16_INITIAL_VALUE        ,NVIC_ISER1_PIN15_INITIAL_VALUE,NVIC_ISER1_PIN14_INITIAL_VALUE,NVIC_ISER1_PIN13_INITIAL_VALUE,NVIC_ISER1_PIN12_INITIAL_VALUE       ,NVIC_ISER1_PIN11_INITIAL_VALUE,NVIC_ISER1_PIN10_INITIAL_VALUE,NVIC_ISER1_PIN9_INITIAL_VALUE,NVIC_ISER1_PIN8_INITIAL_VALUE       ,NVIC_ISER1_PIN7_INITIAL_VALUE,NVIC_ISER1_PIN6_INITIAL_VALUE,NVIC_ISER1_PIN5_INITIAL_VALUE,NVIC_ISER1_PIN4_INITIAL_VALUE    ,NVIC_ISER1_PIN3_INITIAL_VALUE,NVIC_ISER1_PIN2_INITIAL_VALUE,NVIC_ISER1_PIN1_INITIAL_VALUE, NVIC_ISER1_PIN0_INITIAL_VALUE)


/********************************** Interrupt clear-enable registers (NVIC_ICERx) *************************************/
/**********************************************************************************************************************/

#define NVIC_ICER0_REG  *((volatile u32*)(NVICC_BASE_ADDRESS+0x080))
#define NVIC_ICER1_REG  *((volatile u32*)(NVICC_BASE_ADDRESS+0x084))

#define NVIC_ICER0_INITIAL_VALUE  CONCAT(NVIC_ICER0_PIN31_INITIAL_VALUE,NVIC_ICER0_PIN30_INITIAL_VALUE,NVIC_ICER0_PIN29_INITIAL_VALUE,NVIC_ICER0_PIN28_INITIAL_VALUE      ,NVIC_ICER0_PIN27_INITIAL_VALUE,NVIC_ICER0_PIN26_INITIAL_VALUE,NVIC_ICER0_PIN25_INITIAL_VALUE,NVIC_ICER0_PIN24_INITIAL_VALUE,         NVIC_ICER0_PIN23_INITIAL_VALUE,NVIC_ICER0_PIN22_INITIAL_VALUE,NVIC_ICER0_PIN21_INITIAL_VALUE,NVIC_ICER0_PIN20_INITIAL_VALUE       ,NVIC_ICER0_PIN19_INITIAL_VALUE,NVIC_ICER0_PIN18_INITIAL_VALUE,NVIC_ICER0_PIN17_INITIAL_VALUE,NVIC_ICER0_PIN16_INITIAL_VALUE        ,NVIC_ICER0_PIN15_INITIAL_VALUE,NVIC_ICER0_PIN14_INITIAL_VALUE,NVIC_ICER0_PIN13_INITIAL_VALUE,NVIC_ICER0_PIN12_INITIAL_VALUE       ,NVIC_ICER0_PIN11_INITIAL_VALUE,NVIC_ICER0_PIN10_INITIAL_VALUE,NVIC_ICER0_PIN9_INITIAL_VALUE,NVIC_ICER0_PIN8_INITIAL_VALUE       ,NVIC_ICER0_PIN7_INITIAL_VALUE,NVIC_ICER0_PIN6_INITIAL_VALUE,NVIC_ICER0_PIN5_INITIAL_VALUE,NVIC_ICER0_PIN4_INITIAL_VALUE    ,NVIC_ICER0_PIN3_INITIAL_VALUE,NVIC_ICER0_PIN2_INITIAL_VALUE,NVIC_ICER0_PIN1_INITIAL_VALUE,NVIC_ICER0_PIN0_INITIAL_VALUE)
#define NVIC_ICER1_INITIAL_VALUE  CONCAT(NVIC_ICER1_PIN31_INITIAL_VALUE,NVIC_ICER1_PIN30_INITIAL_VALUE,NVIC_ICER1_PIN29_INITIAL_VALUE,NVIC_ICER1_PIN28_INITIAL_VALUE      ,NVIC_ICER1_PIN27_INITIAL_VALUE,NVIC_ICER1_PIN26_INITIAL_VALUE,NVIC_ICER1_PIN25_INITIAL_VALUE,NVIC_ICER1_PIN24_INITIAL_VALUE,         NVIC_ICER1_PIN23_INITIAL_VALUE,NVIC_ICER1_PIN22_INITIAL_VALUE,NVIC_ICER1_PIN21_INITIAL_VALUE,NVIC_ICER1_PIN20_INITIAL_VALUE       ,NVIC_ICER1_PIN19_INITIAL_VALUE,NVIC_ICER1_PIN18_INITIAL_VALUE,NVIC_ICER1_PIN17_INITIAL_VALUE,NVIC_ICER1_PIN16_INITIAL_VALUE        ,NVIC_ICER1_PIN15_INITIAL_VALUE,NVIC_ICER1_PIN14_INITIAL_VALUE,NVIC_ICER1_PIN13_INITIAL_VALUE,NVIC_ICER1_PIN12_INITIAL_VALUE       ,NVIC_ICER1_PIN11_INITIAL_VALUE,NVIC_ICER1_PIN10_INITIAL_VALUE,NVIC_ICER1_PIN9_INITIAL_VALUE,NVIC_ICER1_PIN8_INITIAL_VALUE       ,NVIC_ICER1_PIN7_INITIAL_VALUE,NVIC_ICER1_PIN6_INITIAL_VALUE,NVIC_ICER1_PIN5_INITIAL_VALUE,NVIC_ICER1_PIN4_INITIAL_VALUE    ,NVIC_ICER1_PIN3_INITIAL_VALUE,NVIC_ICER1_PIN2_INITIAL_VALUE,NVIC_ICER1_PIN1_INITIAL_VALUE,NVIC_ICER1_PIN0_INITIAL_VALUE)


/********************************** Interrupt set-pending registers (NVIC_ISPRx) *************************************/
/**********************************************************************************************************************/

#define NVIC_ISPR0_REG  *((volatile u32*)(NVICC_BASE_ADDRESS+0x100))
#define NVIC_ISPR1_REG  *((volatile u32*)(NVICC_BASE_ADDRESS+0x104))

#define NVIC_ISPR0_INITIAL_VALUE  CONCAT(NVIC_ISPR0_PIN31_INITIAL_VALUE,NVIC_ISPR0_PIN30_INITIAL_VALUE,NVIC_ISPR0_PIN29_INITIAL_VALUE,NVIC_ISPR0_PIN28_INITIAL_VALUE      ,NVIC_ISPR0_PIN27_INITIAL_VALUE,NVIC_ISPR0_PIN26_INITIAL_VALUE,NVIC_ISPR0_PIN25_INITIAL_VALUE,NVIC_ISPR0_PIN24_INITIAL_VALUE,         NVIC_ISPR0_PIN23_INITIAL_VALUE,NVIC_ISPR0_PIN22_INITIAL_VALUE,NVIC_ISPR0_PIN21_INITIAL_VALUE,NVIC_ISPR0_PIN20_INITIAL_VALUE       ,NVIC_ISPR0_PIN19_INITIAL_VALUE,NVIC_ISPR0_PIN18_INITIAL_VALUE,NVIC_ISPR0_PIN17_INITIAL_VALUE,NVIC_ISPR0_PIN16_INITIAL_VALUE        ,NVIC_ISPR0_PIN15_INITIAL_VALUE,NVIC_ISPR0_PIN14_INITIAL_VALUE,NVIC_ISPR0_PIN13_INITIAL_VALUE,NVIC_ISPR0_PIN12_INITIAL_VALUE       ,NVIC_ISPR0_PIN11_INITIAL_VALUE,NVIC_ISPR0_PIN10_INITIAL_VALUE,NVIC_ISPR0_PIN9_INITIAL_VALUE,NVIC_ISPR0_PIN8_INITIAL_VALUE       ,NVIC_ISPR0_PIN7_INITIAL_VALUE,NVIC_ISPR0_PIN6_INITIAL_VALUE,NVIC_ISPR0_PIN5_INITIAL_VALUE,NVIC_ISPR0_PIN4_INITIAL_VALUE    ,NVIC_ISPR0_PIN3_INITIAL_VALUE,NVIC_ISPR0_PIN2_INITIAL_VALUE,NVIC_ISPR0_PIN1_INITIAL_VALUE,NVIC_ISPR0_PIN0_INITIAL_VALUE)
#define NVIC_ISPR1_INITIAL_VALUE  CONCAT(NVIC_ISPR1_PIN31_INITIAL_VALUE,NVIC_ISPR1_PIN30_INITIAL_VALUE,NVIC_ISPR1_PIN29_INITIAL_VALUE,NVIC_ISPR1_PIN28_INITIAL_VALUE      ,NVIC_ISPR1_PIN27_INITIAL_VALUE,NVIC_ISPR1_PIN26_INITIAL_VALUE,NVIC_ISPR1_PIN25_INITIAL_VALUE,NVIC_ISPR1_PIN24_INITIAL_VALUE,         NVIC_ISPR1_PIN23_INITIAL_VALUE,NVIC_ISPR1_PIN22_INITIAL_VALUE,NVIC_ISPR1_PIN21_INITIAL_VALUE,NVIC_ISPR1_PIN20_INITIAL_VALUE       ,NVIC_ISPR1_PIN19_INITIAL_VALUE,NVIC_ISPR1_PIN18_INITIAL_VALUE,NVIC_ISPR1_PIN17_INITIAL_VALUE,NVIC_ISPR1_PIN16_INITIAL_VALUE        ,NVIC_ISPR1_PIN15_INITIAL_VALUE,NVIC_ISPR1_PIN14_INITIAL_VALUE,NVIC_ISPR1_PIN13_INITIAL_VALUE,NVIC_ISPR1_PIN12_INITIAL_VALUE       ,NVIC_ISPR1_PIN11_INITIAL_VALUE,NVIC_ISPR1_PIN10_INITIAL_VALUE,NVIC_ISPR1_PIN9_INITIAL_VALUE,NVIC_ISPR1_PIN8_INITIAL_VALUE       ,NVIC_ISPR1_PIN7_INITIAL_VALUE,NVIC_ISPR1_PIN6_INITIAL_VALUE,NVIC_ISPR1_PIN5_INITIAL_VALUE,NVIC_ISPR1_PIN4_INITIAL_VALUE    ,NVIC_ISPR1_PIN3_INITIAL_VALUE,NVIC_ISPR1_PIN2_INITIAL_VALUE,NVIC_ISPR1_PIN1_INITIAL_VALUE,NVIC_ISPR1_PIN0_INITIAL_VALUE)

/********************************** Interrupt clear-pending registers (NVIC_ICPRx) *************************************/
/**********************************************************************************************************************/

#define NVIC_ICPR0_REG   *((volatile u32*)(NVICC_BASE_ADDRESS+0x180))
#define NVIC_ICPR1_REG   *((volatile u32*)(NVICC_BASE_ADDRESS+0x184))

#define NVIC_ICPR0_INITIAL_VALUE CONCAT(NVIC_ICPR0_PIN31_INITIAL_VALUE,NVIC_ICPR0_PIN30_INITIAL_VALUE,NVIC_ICPR0_PIN29_INITIAL_VALUE,NVIC_ICPR0_PIN28_INITIAL_VALUE      ,NVIC_ICPR0_PIN27_INITIAL_VALUE,NVIC_ICPR0_PIN26_INITIAL_VALUE,NVIC_ICPR0_PIN25_INITIAL_VALUE,NVIC_ICPR0_PIN24_INITIAL_VALUE,         NVIC_ICPR0_PIN23_INITIAL_VALUE,NVIC_ICPR0_PIN22_INITIAL_VALUE,NVIC_ICPR0_PIN21_INITIAL_VALUE,NVIC_ICPR0_PIN20_INITIAL_VALUE       ,NVIC_ICPR0_PIN19_INITIAL_VALUE,NVIC_ICPR0_PIN18_INITIAL_VALUE,NVIC_ICPR0_PIN17_INITIAL_VALUE,NVIC_ICPR0_PIN16_INITIAL_VALUE        ,NVIC_ICPR0_PIN15_INITIAL_VALUE,NVIC_ICPR0_PIN14_INITIAL_VALUE,NVIC_ICPR0_PIN13_INITIAL_VALUE,NVIC_ICPR0_PIN12_INITIAL_VALUE       ,NVIC_ICPR0_PIN11_INITIAL_VALUE,NVIC_ICPR0_PIN10_INITIAL_VALUE,NVIC_ICPR0_PIN9_INITIAL_VALUE,NVIC_ICPR0_PIN8_INITIAL_VALUE       ,NVIC_ICPR0_PIN7_INITIAL_VALUE,NVIC_ICPR0_PIN6_INITIAL_VALUE,NVIC_ICPR0_PIN5_INITIAL_VALUE,NVIC_ICPR0_PIN4_INITIAL_VALUE    ,NVIC_ICPR0_PIN3_INITIAL_VALUE,NVIC_ICPR0_PIN2_INITIAL_VALUE,NVIC_ICPR0_PIN1_INITIAL_VALUE,NVIC_ICPR0_PIN0_INITIAL_VALUE)
#define NVIC_ICPR1_INITIAL_VALUE CONCAT(NVIC_ICPR1_PIN31_INITIAL_VALUE,NVIC_ICPR1_PIN30_INITIAL_VALUE,NVIC_ICPR1_PIN29_INITIAL_VALUE,NVIC_ICPR1_PIN28_INITIAL_VALUE      ,NVIC_ICPR1_PIN27_INITIAL_VALUE,NVIC_ICPR1_PIN26_INITIAL_VALUE,NVIC_ICPR1_PIN25_INITIAL_VALUE,NVIC_ICPR1_PIN24_INITIAL_VALUE,         NVIC_ICPR1_PIN23_INITIAL_VALUE,NVIC_ICPR1_PIN22_INITIAL_VALUE,NVIC_ICPR1_PIN21_INITIAL_VALUE,NVIC_ICPR1_PIN20_INITIAL_VALUE       ,NVIC_ICPR1_PIN19_INITIAL_VALUE,NVIC_ICPR1_PIN18_INITIAL_VALUE,NVIC_ICPR1_PIN17_INITIAL_VALUE,NVIC_ICPR1_PIN16_INITIAL_VALUE        ,NVIC_ICPR1_PIN15_INITIAL_VALUE,NVIC_ICPR1_PIN14_INITIAL_VALUE,NVIC_ICPR1_PIN13_INITIAL_VALUE,NVIC_ICPR1_PIN12_INITIAL_VALUE       ,NVIC_ICPR1_PIN11_INITIAL_VALUE,NVIC_ICPR1_PIN10_INITIAL_VALUE,NVIC_ICPR1_PIN9_INITIAL_VALUE,NVIC_ICPR1_PIN8_INITIAL_VALUE       ,NVIC_ICPR1_PIN7_INITIAL_VALUE,NVIC_ICPR1_PIN6_INITIAL_VALUE,NVIC_ICPR1_PIN5_INITIAL_VALUE,NVIC_ICPR1_PIN4_INITIAL_VALUE    ,NVIC_ICPR1_PIN3_INITIAL_VALUE,NVIC_ICPR1_PIN2_INITIAL_VALUE,NVIC_ICPR1_PIN1_INITIAL_VALUE,NVIC_ICPR1_PIN0_INITIAL_VALUE)


/********************************** Interrupt active bit registers (NVIC_IABRx) *************************************/
/**********************************************************************************************************************/

#define NVIC_IABR0_REG  *((volatile u32*)(NVICC_BASE_ADDRESS+0x200))
#define NVIC_IABR1_REG  *((volatile u32*)(NVICC_BASE_ADDRESS+0x204))

/********************************** Interrupt priority registers (NVIC_IPRx) *************************************/
/******************************************************************************************************************/

#define NVIC_IPR_REG  ((volatile u8*)(NVICC_BASE_ADDRESS+0x300))


/*********************** Application interrupt and reset control register (SCB_AIRCR) *****************************/
/******************************************************************************************************************/

#define SCB_AIRCR_REG  *((volatile u32*)(0xE000ED00+0x0C))







#endif






