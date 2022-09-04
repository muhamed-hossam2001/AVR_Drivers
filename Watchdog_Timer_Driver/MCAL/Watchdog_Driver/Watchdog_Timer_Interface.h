/*
 * INTERFACE.h
 *
 *  Created on: Sep 17, 2021
 *      Author: dell
 */

#ifndef WATCHDOG_TIMER_INTERFACE_H_
#define WATCHDOG_TIMER_INTERFACE_H_


/* Watchdog Timer Control Register */

/*
 * to Select  Number of WDT Oscillator Cycles
 */
#define WDT_TIME_OUT_SELECT_MASK  0b11111000
#define WDT_TIME_OUT_SELECT_SHIFT  0

#define WDT_16K_TIME_OUT16.3ms    0x00
#define WDT_32K_TIME_OUT32.5ms    0x01
#define WDT_64K_TIME_OUT65ms      0x02
#define WDT_128K_TIME_OUT0.13s    0x03
#define WDT_256K_TIME_OUT0.26s    0x04
#define WDT_512K_TIME_OUT0.52s    0x05
#define WDT_1024K_TIME_OUT1s      0x06
#define WDT_2048K_TIME_OUT2.1s    0x07

/*
 * To Enable or disable the Watchdog timer
 */
#define ENABLE  1
#define DISABLE 0


extern void WDT_VoidInit_Preduild(void);

extern void WDT_voidEnable_Postbuild(void);

extern void WDT_voidDisable_Postbuild();

extern void WDT_voidSleepTimeOut_Postbuild(u8 Copy_u8TimeOut);

#endif
