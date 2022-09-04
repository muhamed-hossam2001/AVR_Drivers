
#ifndef WATCHDOG_TIMER_REG_H_
#define WATCHDOG_TIMER_REG_H_

/* Watchdog Timer Control Register */
#define WDTCR_REG *((volatile u8*)0x41)

/* Watchdog Timer Control Register Bits */
enum WDTCR_R
	{
		WDTCR_REG_WDP0 ,
		WDTCR_REG_WDP1 ,
		WDTCR_REG_WDP2 ,
		WDTCR_REG_WDE  ,
		WDTCR_REG_WDTOE

	};

#endif
