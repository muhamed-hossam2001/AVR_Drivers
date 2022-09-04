
#ifndef WATCHDOG_CONFIG_H_
#define WATCHDOG_CONFIG_H_


/* Watchdog Timer Control Register */

/*
 * to Select  Number of WDT Oscillator Cycles
 */

/*Options:
 *
 *    WDT_16K_TIME_OUT16.3ms
 *    WDT_32K_TIME_OUT32.5ms
 *    WDT_64K_TIME_OUT65ms
 *    WDT_128K_TIME_OUT0.13s
 *    WDT_256K_TIME_OUT0.26s
 *    WDT_512K_TIME_OUT0.52s
 *    WDT_1024K_TIME_OUT1s
 *    WDT_2048K_TIME_OUT2.1s
 *
 */
#define WDT_TIME_OUT  WDT_1024K_TIME_OUT1s

/*Options:
 *	  ENABLE
 * 	  DISABLE
 */
#define WDT_INITIAL_STATE ENABLE




#endif
