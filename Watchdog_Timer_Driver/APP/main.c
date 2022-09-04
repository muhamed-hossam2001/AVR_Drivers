#include "util/delay.h"
#include "../LIB/BIT_MATH.h"
#include "../LIB/STDTYPES.h"
#include "../LIB/CHECK_ERROR.h"

#include "../MCAL/PORT_Driver/PORT_REG.h"
#include "../MCAL/PORT_Driver/PORT_Interface.h"
#include "../MCAL/PORT_Driver/PORT_Private.h"
#include "../MCAL/PORT_Driver/PORT_Config.h"

#include "../MCAL/Watchdog_Driver/Watchdog_Timer_REG.h"
#include "../MCAL/Watchdog_Driver/Watchdog_Timer_Interface.h"
#include "../MCAL/Watchdog_Driver/Watchdog_Timer_Private.h"
#include "../MCAL/Watchdog_Driver/Watchdog_Timer_Config.h"

#include "../MCAL/DIO_Driver/DIO_REG.h"
#include "../MCAL/DIO_Driver/DIO_Interface.h"



int main(void)
{ PORT_VoidInit();
	DIO_U8SetPinVal(PORT_B,PIN_3,HIGH);
	_delay_ms(1000);
	DIO_U8SetPinVal(PORT_B,PIN_3,LOW );

	WDT_VoidInit_Preduild();

	while(1)
	{

	}
	return 0;
}
