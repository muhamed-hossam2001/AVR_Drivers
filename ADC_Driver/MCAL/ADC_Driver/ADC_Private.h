/****************************************************************************************************************************************/
/***********************************************	Author  : Doaa Mohamed  *************************************************************/
/***********************************************	Date    : 8 March 2022  *************************************************************/
/***********************************************	Version : V3            *************************************************************/
/****************************************************************************************************************************************/

#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_

#define CONCAT(b7,b6,b5,b4,b3,b2,b1,b0)    CONC(b7,b6,b5,b4,b3,b2,b1,b0)
#define CONC(b7,b6,b5,b4,b3,b2,b1,b0)      0b##b7##b6##b5##b4##b3##b2##b1##b0

#define ADMUX_INITAIL_VALUE       CONCAT(ADMUX_REFS1,ADMUX_REFS0,ADMUX_ADLAR,ADMUX_MUX4,ADMUX_MUX3,ADMUX_MUX2,ADMUX_MUX1,ADMUX_MUX0 )
#define ADCSRA_REG_INITAIL_VALUE  CONCAT(ADCSRA_ADEN,ADCSRA_ADSC,ADCSRA_ADATE,ADCSRA_ADIF,ADCSRA_ADIE,ADCSRA_ADPS2,ADCSRA_ADPS1,ADCSRA_ADPS0 )


#endif /* ADC_PRIVATE_H_ */
