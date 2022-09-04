
/****************************************************************************************************************************************/
/***********************************************	Author  : Doaa Mohamed  *************************************************************/
/***********************************************	Date    : 14 March 2022  ************************************************************/
/***********************************************	Version : V1            *************************************************************/
/****************************************************************************************************************************************/

#ifndef _EXTI_PRIVATE_H_
#define _EXTI_PRIVATE_H_

#define EXTI_BASE_ADDRESS  0x40010400
#define RESERVED           0

#define CONCAT(b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0)   CONC(b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0)
#define CONC(b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0)     0b##b31##b30##b29##b28##b27##b26##b25##b24##b23##b22##b21##b20##b19##b18##b17##b16##b15##b14##b13##b12##b11##b10##b9##b8##b7##b6##b5##b4##b3##b2##b1##b0

typedef struct EXTI_t
{
	volatile u32 EXTI_IMR_REG; 		/* Interrupt mask register (EXTI_IMR)            */
	volatile u32 EXTI_EMR_REG;		/* Event mask register (EXTI_EMR)	             */
	volatile u32 EXTI_RTSR_REG;		/* Rising trigger selection register (EXTI_RTSR  */
	volatile u32 EXTI_FTSR_REG;		/* Falling trigger selection register (EXTI_FTSR */
	volatile u32 EXTI_SWIER_REG;	/* Software interrupt event register (EXTI_SWIER */
	volatile u32 EXTI_PR_REG;		/* Pending register (EXTI_PR)	 				 */
}EXTI_t;

#define EXTI  ((volatile EXTI_t *)EXTI_BASE_ADDRESS)

/********************************** Registers Initializations values ****************************************/
/************************************************************************************************************/

#define EXTI_IMR_INITIAL_VALUE  CONCAT(RESERVED,RESERVED,RESERVED,RESERVED,RESERVED,RESERVED,RESERVED,RESERVED,RESERVED,RESERVED,RESERVED,RESERVED,RESERVED,RESERVED,RESERVED,RESERVED,EXTI_LINE15_EN_DIS,EXTI_LINE14_EN_DIS, EXTI_LINE13_EN_DIS, EXTI_LINE12_EN_DIS,EXTI_LINE11_EN_DIS,EXTI_LINE10_EN_DIS,EXTI_LINE9_EN_DIS,EXTI_LINE8_EN_DIS,EXTI_LINE7_EN_DIS,EXTI_LINE6_EN_DIS,EXTI_LINE5_EN_DIS,EXTI_LINE4_EN_DIS,EXTI_LINE3_EN_DIS,EXTI_LINE2_EN_DIS,EXTI_LINE1_EN_DIS,EXTI_LINE0_EN_DIS)

#define EXTI_RTSR_INITIAL_VALUE  CONCAT(RESERVED,RESERVED,RESERVED,RESERVED,RESERVED,RESERVED,RESERVED,RESERVED,RESERVED,RESERVED,RESERVED,RESERVED,RESERVED,RESERVED,RESERVED,RESERVED,EXTI_LINE15_RISING_EDGE_MODE,EXTI_LINE14_RISING_EDGE_MODE,EXTI_LINE13_RISING_EDGE_MODE,EXTI_LINE12_RISING_EDGE_MODE,EXTI_LINE11_RISING_EDGE_MODE,EXTI_LINE10_RISING_EDGE_MODE,EXTI_LINE9_RISING_EDGE_MODE,EXTI_LINE8_RISING_EDGE_MODE,EXTI_LINE7_RISING_EDGE_MODE,EXTI_LINE6_RISING_EDGE_MODE,EXTI_LINE5_RISING_EDGE_MODE,EXTI_LINE4_RISING_EDGE_MODE,EXTI_LINE3_RISING_EDGE_MODE,EXTI_LINE2_RISING_EDGE_MODE,EXTI_LINE1_RISING_EDGE_MODE,EXTI_LINE0_RISING_EDGE_MODE)

#define EXTI_FTSR_INITIAL_VALUE  CONCAT(RESERVED,RESERVED,RESERVED,RESERVED,RESERVED,RESERVED,RESERVED,RESERVED,RESERVED,RESERVED,RESERVED,RESERVED,RESERVED,RESERVED,RESERVED,RESERVED,EXTI_LINE15_FALLING_EDGE_MODE,EXTI_LINE14_FALLING_EDGE_MODE,EXTI_LINE13_FALLING_EDGE_MODE,EXTI_LINE12_FALLING_EDGE_MODE,EXTI_LINE11_FALLING_EDGE_MODE,EXTI_LINE10_FALLING_EDGE_MODE,EXTI_LINE9_FALLING_EDGE_MODE,EXTI_LINE8_FALLING_EDGE_MODE,EXTI_LINE7_FALLING_EDGE_MODE,EXTI_LINE6_FALLING_EDGE_MODE,EXTI_LINE5_FALLING_EDGE_MODE,EXTI_LINE4_FALLING_EDGE_MODE,EXTI_LINE3_FALLING_EDGE_MODE,EXTI_LINE2_FALLING_EDGE_MODE,EXTI_LINE1_FALLING_EDGE_MODE,EXTI_LINE0_FALLING_EDGE_MODE)


#endif






