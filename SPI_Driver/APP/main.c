
#include "../LIB/STDTYPES.h"
#include "../LIB/BIT_MATH.h"
#include "../LIB/CHECK_ERROR.h"
#include "../MCAL/DIO_Driver/DIO_REG.h"
#include "../MCAL/DIO_Driver/DIO_Interface.h"
#include "../MCAL/PORT_Driver/PORT_REG.h"
#include "../MCAL/PORT_Driver/PORT_Config.h"
#include "../MCAL/PORT_Driver/PORT_Private.h"
#include "../MCAL/PORT_Driver/PORT_Interface.h"
#include "../MCAL/SPI_Driver/SPI_REG.h"
#include "../MCAL/SPI_Driver/SPI_Config.h"
#include "../MCAL/SPI_Driver/SPI_Private.h"
#include "../MCAL/SPI_Driver/SPI_Interface.h"

#define SREG_REG *((volatile u8*)0x5F)
//#define flag 0x20



void SPI_MAster()
{
  DDRB_REG=0b10110000;
  SPCR_REG|=(1<<SPCR_REG_DORD_PIN)|(1<<SPCR_REG_MSTR_PIN)|(1<<SPCR_REG_CPHA_PIN) |(1<<0)  |(1<<1) |(1<<2);
  SPCR_REG|=(1<<SPCR_REG_SPE_PIN);

}
void SPI_Slave_INIT()
{
  DDRB_REG=0b01000000;
  SPCR_REG|=(1<<SPCR_REG_DORD_PIN)|(1<<SPCR_REG_SPIE_PIN)|(1<<SPCR_REG_CPHA_PIN);
  SPCR_REG|=(1<<SPCR_REG_SPE_PIN);

}
void SPI_SendByte(u8 data)
{
  SPDR_REG=data;
  while(GET_BIT(SPSR_REG,SPSR_REG_SPIF_PIN)==0);

}
u8 SPI_reciveByte()
{
  u8 Rdata;
  while(GET_BIT(SPSR_REG,SPSR_REG_SPIF_PIN)==0);
  Rdata=SPDR_REG;
  return Rdata;
}

u8 SPI_TRANS(u8 Data)
{
  SPDR_REG=Data;
  while(GET_BIT(SPSR_REG,SPSR_REG_SPIF_PIN)==0);
  return (SPDR_REG);
}
u8 m=0;
u8 flag = 0;

//void main()
//{
//  SPI_MAster();
//  //DDRC=0xFF;
//     //DDRD=0xFF;
//  //LCD_VoidInit();
//
//
//
//
//
//while(1)
//{
//
//  SPI_TRANS(1);
//  _delay_ms(1000);
//  SPI_TRANS(0);
//  _delay_ms(1000);
//
//}
//}

int main(void)
{
PORT_VoidInit();
  //SPI_Slave_INIT();
	SPI_VidInit();
  //DDRC=0xFF;
  //DDRD_REG=0xFF;
  SREG_REG |=(1<<7);



  while(1)
  {
	  if(flag == 1)
	     {
	       if(m==1)
	         DIO_U8SetPinVal(PORT_A,0,HIGH);
	       else if(m==0)
	    	   DIO_U8SetPinVal(PORT_A,0,LOW);
	       flag = 0;

	     }

	   }
  return 0;
  }


void __vector_12 (void)  __attribute((signal)) ;
void __vector_12 (void )
{
  m=SPDR_REG;
  flag = 1 ;

}
