/****************************************************************************************************************************************/
/***********************************************	Author  : Doaa Mohamed  *************************************************************/
/***********************************************	Date    : 8 March 2022  *************************************************************/
/***********************************************	Version : V3            *************************************************************/
/****************************************************************************************************************************************/

#ifndef ADC_REG_H_
#define ADC_REG_H_


/********************************* MCU Control and Status Register *****************************************************/

#define SFIOR_REG *((volatile u8*)0x50)
enum SFIOR
{
ADTS0=5,
ADTS1,
ADTS2
};

/******************* ADC Multiplexer Selection Register To select Channel  and Vref and Justification ******************************/
#define ADMUX_REG *((volatile u8*)0x27)

/*ADMUX register bits*/
enum ADMUX
	{
	MUX0,
	MUX1,
	MUX2,
	MUX3,
	MUX4,
	ADLAR,
	REFS0,
	REFS1
	  };


/************************ ADC Control and Status Register A – ADCSRA to Enable the ADC , Start Conversion, Prescaller to clock*************/

#define ADCSRA_REG *((volatile u8*)0x26)

/*ADCSRA Bits Configurations*/
enum ADCSRA{
	ADPS0,
	ADPS1,
	ADPS2,
	ADIE,
	ADIF,
	ADATE,
	ADSC,
	ADEN};
/*ADC Result Register High*/
#define ADCH_REG *((volatile u8*)0x25)

/*ADC Result Register Low*/
#define ADCL_REG *((volatile u8*)0x24)

#endif
