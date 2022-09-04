/*
 * INTERFACE.h
 *
 *  Created on: Sep 17, 2021
 *      Author: dell
 */

#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_


/*SPI Control Register Configurations*/

/*
 * to Select the Data order LSB First or MSB First
 */
#define DATA_ORDER_LSB_FIRST 1
#define DATA_ORDER_MSB_FIRST 0

/*
 *to select the Function of My MCU initially (Master ,Slave)
 */

#define MASTER_MODE   1
#define SLAVE_MODE    0

/*
 * to Select the Clock Polarity (Idle State) of the clock (Low ,High)
 */
#define CLOCK_POLARITY_LOW_LEDING_RISING   0
#define CLOCK_POLARITY_HIGH_LEDING_FALLING 1

/*
 * to Select the Clock Phase (Sample -Setup or Setup -Sample )
 */
#define LEADING_SAMPLE_TRAILING_SETUP   0
#define LEADING_SETUP_TRAILING_SAMPLE   1



/*
 * to Select the Prescaller of Clock generation in Master
 */

#define PRESCALLER_MASK		    0xFC
#define PRESCALLER_DIV_4    	(u8)0
#define PRESCALLER_DIV_16		(u8)1
#define PRESCALLER_DIV_64		(u8)2
#define PRESCALLER_DIV_128		(u8)3
#define PRESCALLER_DIV_2		(u8)0
#define PRESCALLER_DIV_8		(u8)1
#define PRESCALLER_DIV_32		(u8)2
#define PRESCALLER_DIV_64_X2	(u8)3


/*
 * Set Configuration bits for PORTB SS ,SCK ,MISO ,MOSI to slave
 */
#define SLAVE_MODE_CONFIGURATIONS_PORTSPI_MASK  0b00001111
#define SLAVE_MODE_CONFIGURATIONS_PORTSPI	    0b01000000

/*
 * Set Configuration bits for PORTB SS ,SCK ,MISO ,MOSI to Master
 */
#define MASTER_MODE_CONFIGURATIONS_PORTSPI_MASK  0b00001111
#define MASTER_MODE_CONFIGURATIONS_PORTSPI	    0b10100000

/*to enable or disable interrupt*/
#define ENABLE      1
#define DISABLE		0



extern void SPI_VidInit(void);

extern void SPI_VidInterruptEnable(u8 Copy_u8En_Dis);

extern u8	SPI_u8Transciever(u8 Copy_u8Data);

extern void SPI_VoidSlaveInit();

extern void SPI_VoidMasterInit();

extern void SPI_VoidPrescalerSelect(u8 Copy_u8PreScaller);





#endif
