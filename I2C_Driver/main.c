/*
 * main.c
 *
 *  Created on: Nov 20, 2021
 *      Author: dell
 */

#include "avr/io.h"
#define START_CONDITION 		0x08
#define REPETED_START_CONDITION 0x10
#define SLA_W_ACK 				0x18
#define SLA_R_ACK 				0x40
#define SLA_W_NACK 				0x20
#define DATA_BYTE_ACK 			0x28
#define DATA_BYTE_NACK 			0x30
#define ARBITRATION_LOSST 		0x38


void I2C_VoidMasterInit()
{
	TWCR=(1<<TWEN)|(1<<TWEA);
	TWBR=2;
	//prescaller 00

}



void I2C_VoidSlaveInit()
{
	TWAR=1<<1 //myaddress
	TWCR=(1<<TWEA)|(1<<TWEN);
	TWBR=2;
}



void I2C_VoidStartCondition()
{
	TWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);//clear flag
	while (!(TWCR & (1<<TWINT)));         //wait till start
	while((TWSR & 0xF8)==START_CONDITION); //check for ack

	//while (!(TWCR & (1<<TWINT)));   //while((TWCR&0F8)!=START_CONDITION)
}


void I2C_VoidStartREPEATEDCondition()
{
	TWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);//clear flag
	while (!(TWCR & (1<<TWINT)));         //wait till start
	while((TWSR & 0xF8)==REPETED_START_CONDITION); //check for ack

	//while (!(TWCR & (1<<TWINT)));   //while((TWCR&0F8)!=START_CONDITION)
}



void I2C_VoidSendSlaveAddressWriteReq(unsigned char Addresss)
{
	TWDR=Addresss<<1;
	//
	//ClearBit(TWAR,TWGCE);
	TWCR = (1<<TWINT) | (1<<TWEN);
	while (!(TWCR & (1<<TWINT)));         //wait till start
	while((TWSR & 0xF8)==SLA_W_ACK); //check for ack
	/*
	TWAR=(Addresss<<1);
	ClearBit(TWAR,TWGCE);*/
}
void I2C_VoidSendSlaveAddressReadReq(unsigned char Addresss)
{
	TWDR=Addresss<<1;
		//
		//ClearBit(TWAR,TWGCE);
		TWCR = (1<<TWINT) | (1<<TWEN);
		while (!(TWCR & (1<<TWINT)));         //wait till start
		while((TWSR & 0xF8)==SLA_R_ACK); //check for ack

	//TWAR=(Addresss<<1)|(1<<TWGCE);
}


void I2C_VoidStopCondition()
{
	TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWSTO);
}


I2C_VoidWrite_Byte(unsigned char DATA)
{
	TWDR = DATA;
	TWCR = (1<<TWINT) | (1<<TWEN);
	while (!(TWCR & (1<<TWINT)));
	while ((TWSR & 0xF8) == DATA_BYTE_ACK);

}
unsigned char I2C_u8Read_Byte()
{	while (!(TWCR & (1<<TWINT)));
	//return TWDR ;
	TWCR = (1<<TWINT) | (1<<TWEN);
	while (!(TWCR & (1<<TWINT)));
	if ((TWSR & 0xF8) == DATA_BYTE_ACK)
		return TWDR ;
	else
		return 0;
}


void I2C_CheckSlaveAddressRecivedWithWriteRequest()
{
	TWCR = (1<<TWINT) | (1<<TWEN);
	while (!(TWCR & (1<<TWINT)));
	while ((TWSR & 0xF8) == DATA_BYTE_ACK);
	while (!(TWCR & (1<<TWINT)));
}
void I2C_CheckSlaveAddressRecivedWithReadRequest()
{
	while (!(TWCR & (1<<TWINT)));
}
int main(void)
{

	while(1)
	{

	}
	return 0;
}
