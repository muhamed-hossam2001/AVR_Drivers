/*
 * DIO_Interface.c
 *
 *  Created on: Sep 17, 2021
 *      Author: dell
 */


#include"util/delay.h"
#include "../../LIB/STDTYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/CHECK_ERROR.h"
#include "SPI_Config.h"
#include "SPI_Interface.h"
#include "SPI_private.h"
#include "SPI_REG.h"


 void SPI_VoidSlaveInit()
{
	 /*Enable Master Mode*/
	 CLR_BIT(SPCR_REG,SPCR_REG_MSTR_PIN);
	 /*Set SPI Pins as Slave*/
	 /*
	  *   	 CLR_BIT(SPI_PORT,MOSI_PIN);
	  *  	 SET_BIT(SPI_PORT,MISO_PIN);
	  *  	 CLR_BIT(SPI_PORT,SS_PIN );
	  *  	 CLR_BIT(SPI_PORT,SCK_PIN);
	  *
	  */
	 u8 Temp = SPI_PORT;
	 Temp&=SLAVE_MODE_CONFIGURATIONS_PORTSPI_MASK;
	 Temp|=SLAVE_MODE_CONFIGURATIONS_PORTSPI;
	 SPI_PORT = Temp;

	 /*Enable SPI*/
	 SET_BIT(SPCR_REG,SPCR_REG_SPE_PIN);

}
 void SPI_VoidMasterInit()
{


	 /*Enable Master Mode*/
	 SET_BIT(SPCR_REG,SPCR_REG_MSTR_PIN);

	 /*Set SPI Pins as Master*/

	/*  SET_BIT(SPI_PORT,MOSI_PIN);
	 * CLR_BIT(SPI_PORT,MISO_PIN);
	 * //we make it Input ,as if we need it to make Master as a slave   ,We must make it Pulled up
	 * CLR_BIT(SPI_PORT,SS_PIN);
	 * SET_BIT(SPI_PORT,SCK_PIN);
	 */
	 u8 Temp = SPI_PORT;
	 Temp&=MASTER_MODE_CONFIGURATIONS_PORTSPI_MASK;
	 Temp|=MASTER_MODE_CONFIGURATIONS_PORTSPI;
	 SPI_PORT=Temp;

	 /*Setting Clock Prescaler*/
	 SPCR_REG&=PRESCALLER_MASK;
	 SPCR_REG|=CLOCK_PRESCALLER;

            if((CLOCK_PRESCALLER==PRESCALLER_DIV_4 )||(CLOCK_PRESCALLER==PRESCALLER_DIV_16)||(CLOCK_PRESCALLER==PRESCALLER_DIV_64 )||(CLOCK_PRESCALLER==PRESCALLER_DIV_128 ))
				{

					 CLR_BIT(SPSR_REG,SPSR_REG_SPI2X_PIN);

				}
		   else
				{

					 CLR_BIT(SPSR_REG,SPSR_REG_SPI2X_PIN);
				}

	  /*Enable SPI*/
		 SET_BIT(SPCR_REG,SPCR_REG_SPE_PIN);
}

void SPI_VidInit(void)
{

			/*
			 * to Select the Data order LSB First or MSB First
			 */
		#if(DATA_ORDER==DATA_ORDER_LSB_FIRST)
			{
				SET_BIT(SPCR_REG,SPCR_REG_DORD_PIN);

			}
		#else
			{
				CLR_BIT(SPCR_REG,SPCR_REG_DORD_PIN);

			}
		#endif
			/*
			 * To Enable or Disable the SPI Interrupt
			 */
		#if(SPI_INT==ENABLE)
			{
				SET_BIT(SPCR_REG,SPCR_REG_SPIE_PIN);

			}
		#else
			{
				CLR_BIT(SPCR_REG,SPCR_REG_SPIE_PIN);

			}
		#endif

			/*
			 * to Select the Clock Polarity (Idle State) of the clock (Low ,High)
			 */
		#if(CLOCK_POLARIT==CLOCK_POLARITY_HIGH_LEDING_FALLING)
			{
				SET_BIT(SPCR_REG,SPCR_REG_CPOL_PIN);

			}
		#else
			{
				CLR_BIT(SPCR_REG,SPCR_REG_CPOL_PIN);

			}
		#endif
			/*
			 * to Select the Clock Phase (Sample -Setup or Setup -Sample )
			 */
		#if( CLOCK_PHASE== LEADING_SETUP_TRAILING_SAMPLE)
			{
				SET_BIT(SPCR_REG,SPCR_REG_CPHA_PIN);

			}
		#else
			{
				CLR_BIT(SPCR_REG,SPCR_REG_CPHA_PIN);

			}
		#endif

			/*
			 *to select the Function of My MCU initially (Master ,Slave)
			 */
			#if(MODE==MASTER_MODE)
				{

					SPI_VoidMasterInit();


				}
			#else
				{

					SPI_VoidSlaveInit();

				}
			#endif


}



u8 SPI_u8Transciever(u8 Copy_u8Data)
{
	/*Setting the Data  Then starting transfer*/
	SPDR_REG=Copy_u8Data;

	/*waiting until all Data Shifted (transfer)*/
	while(GET_BIT(SPSR_REG,SPSR_REG_SPIF_PIN)==0);


	/*to down the SPI flag Reading flag which is finished in previous Step + Reading SPDR  */

	return SPDR_REG;
}
void SPI_VidInterruptEnable(u8 Copy_u8En_Dis)
{
	if(Copy_u8En_Dis==ENABLE)
	{
		SET_BIT(SPCR_REG,SPCR_REG_SPIE_PIN);
	}
	else if(Copy_u8En_Dis==DISABLE)
	{
		CLR_BIT(SPCR_REG,SPCR_REG_SPIE_PIN);
	}

}

 void SPI_VoidPrescalerSelect(u8 Copy_u8PreScaller)
{
	 u8 Local_u8Temp=SPCR_REG;


	if((Copy_u8PreScaller==PRESCALLER_DIV_4 )||(Copy_u8PreScaller==PRESCALLER_DIV_16)||(Copy_u8PreScaller==PRESCALLER_DIV_64 )||(Copy_u8PreScaller==PRESCALLER_DIV_128 ))
	{
		Local_u8Temp&=PRESCALLER_MASK;
		Local_u8Temp|=Copy_u8PreScaller;
		SPCR_REG=Local_u8Temp;
		CLR_BIT(SPSR_REG,SPSR_REG_SPI2X_PIN);

	}
	 else
	{
		 Local_u8Temp&=PRESCALLER_MASK;
		 Local_u8Temp|=Copy_u8PreScaller;
		 SPCR_REG=Local_u8Temp;
		 SET_BIT(SPSR_REG,SPSR_REG_SPI2X_PIN);
	}
}
