


#ifndef SPI_CONFIG_H_
#define SPI_CONFIG_H_




/*SPI Control Register Configurations*/

/*
 * to Select the Data order LSB First or MSB First
 * Option:
 * 		  DATA_ORDER_LSB_FIRST
 *        DATA_ORDER_MSB_FIRST
 */
#define DATA_ORDER DATA_ORDER_LSB_FIRST

/*
 *to select the Function of My MCU initially (Master ,Slave)
 *Options:
 *        MASTER_MODE
 *        SLAVE_MODE
 */

#define MODE SLAVE_MODE


/*
 * to Select the Clock Polarity (Idle State) of the clock (Low ,High)
 * Options:
 *         CLOCK_POLARITY_LOW_LEDING_RISING
 *         CLOCK_POLARITY_HIGH_LEDING_FALLING
 */
#define  CLOCK_POLARIT CLOCK_POLARITY_LOW_LEDING_RISING


/*
 * to Select the Clock Phase (Sample -Setup or Setup -Sample )
 * Options:
 *         LEADING_SAMPLE_TRAILING_SETUP
 *         LEADING_SETUP_TRAILING_SAMPLE
 */
#define CLOCK_PHASE LEADING_SETUP_TRAILING_SAMPLE

/*
 * to Select the Prescaller of Clock generation in Master
 * Options:
 *        PRESCALLER_DIV_4
 *        PRESCALLER_DIV_16
 *        PRESCALLER_DIV_64
 *        PRESCALLER_DIV_128
 *        PRESCALLER_DIV_2
 *        PRESCALLER_DIV_8
 *        PRESCALLER_DIV_32
 *        PRESCALLER_DIV_64_X2
 */


#define CLOCK_PRESCALLER   PRESCALLER_DIV_128

/*
 * To Enable or Disable the SPI Interrupt
 */

#define SPI_INT   ENABLE


/*
 * MOSI PIN
 * MISO PIN
 * SCK  PIN
 * SS   PIN
*/

#define SPI_PORT DDRB_REG

enum SPI_EXTERNAL_PINS
{
	SS_PIN=4,
	MOSI_PIN,
	MISO_PIN,
	SCK_PIN
};


#endif
