/****************************************************************************************************************************************/
/***********************************************	Author  : Doaa Mohamed  *************************************************************/
/***********************************************	Date    : 7 March 2022  *************************************************************/
/***********************************************	Version : V1            *************************************************************/
/****************************************************************************************************************************************/


#include "../../LIB/STDTYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/CHECK_ERROR.h"
#include "PORT_Config.h"
#include "PORT_Interface.h"
#include "PORT_REG.h"
#include "PORT_private.h"

void PORT_VoidInit()
{
/*Setting Initial Port Mode for Pins from [0:15] */
GPIOS_PORTA_CRL_INIT=PORTA_CRL_INITIAL_VALUE;
GPIOS_PORTB_CRL_INIT=PORTA_CRL_INITIAL_VALUE;
GPIOS_PORTC_CRL_INIT=PORTA_CRL_INITIAL_VALUE;

/*Setting Initial Port Mode for Pins from [16:31] */
GPIOS_PORTA_CRH_INIT=PORTA_CRH_INITIAL_VALUE;
GPIOS_PORTB_CRH_INIT=PORTB_CRH_INITIAL_VALUE;
GPIOS_PORTC_CRH_INIT=PORTC_CRH_INITIAL_VALUE;

/*Setting Initial Port Value */
GPIOS_PORTA_ODR_INIT=PORTA_ODR_INITIAL_VALUE;
GPIOS_PORTB_ODR_INIT=PORTB_ODR_INITIAL_VALUE;
GPIOS_PORTC_ODR_INIT=PORTC_ODR_INITIAL_VALUE;


}
