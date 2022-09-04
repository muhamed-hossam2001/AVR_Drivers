/*
 * DIO_Interface.c
 *
 *  Created on: Sep 17, 2021
 *      Author: dell
 */


#include "../../LIB/STDTYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "DIO_REG.h"
#include "DIO_Interface.h"


u8 DIO_U8SetPortDir(enum PORTS Copy_u8PortNo,u8  Copy_u8dDir)
{

	 u8 Local_Status=RT_OK;
if(Copy_u8PortNo<0||Copy_u8PortNo>3)
{
	Local_Status=RT_NOK;

}
else
{
	switch(Copy_u8PortNo)
	{
	case 0:{DDRA_REG=Copy_u8dDir; break;}
	case 1:{DDRB_REG=Copy_u8dDir; break;}
	case 2:{DDRC_REG=Copy_u8dDir; break;}
	case 3:{DDRD_REG=Copy_u8dDir; break;}
	}
}
return Local_Status;
}

u8 DIO_U8SetPortVal(enum PORTS Copy_u8PortNo , u8 Copy_Val)
{
	u8 Local_Status=RT_OK;
	if(Copy_u8PortNo <0||Copy_u8PortNo>3)
	{
		 Local_Status=RT_NOK;

	}
	else
	{
		switch(Copy_u8PortNo)
		{
		case 0:{PORTA_REG=Copy_Val; break;}
		case 1:{PORTB_REG=Copy_Val; break;}
		case 2:{PORTC_REG=Copy_Val; break;}
		case 3:{PORTD_REG=Copy_Val; break;}
		}
	}
	return Local_Status;

}

u8 DIO_U8GetPortVal(enum PORTS Copy_u8PortNo, u8* u8_Val)
{

	u8 Local_Status=RT_OK;
	if(Copy_u8PortNo<0|| Copy_u8PortNo>3)
	{
		Local_Status=RT_NOK;

	}
	else
	{
		switch(Copy_u8PortNo)
		{
		case 0:{*u8_Val=PINA_REG; break;}
		case 1:{*u8_Val=PINB_REG; break;}
		case 2:{*u8_Val=PINC_REG; break;}
		case 3:{*u8_Val=PIND_REG; break;}
		}
	}
	return Local_Status;

}

u8 DIO_U8SetPinDir(enum PORTS Copy_u8PortNo , enum PINS Copy_u8PinNo,u8 Copy_u8Dir)
{	u8 Local_Status=RT_OK;
if(Copy_u8PortNo>=0||Copy_u8PortNo<=3)
{
	if(Copy_u8PinNo>=0||Copy_u8PinNo<=7)
	{
		if(Copy_u8Dir == HIGH)
		{
			switch(Copy_u8PortNo)
			{
			case 0:
			{
				SetBit(DDRA_REG,Copy_u8PinNo);
				break;
			}
			case 1:
			{
				SetBit(DDRB_REG,Copy_u8PinNo);
				break;
			}
			case 2:
			{
				SetBit(DDRC_REG,Copy_u8PinNo);
				break;
			}
			case 3:
			{
				SetBit(DDRD_REG,Copy_u8PinNo);
				break;
			}

			}
		}
		else if(Copy_u8Dir==LOW)
		{
			switch(Copy_u8PortNo)
			{
				case 0:
				{
					ClearBit(DDRA_REG,Copy_u8PinNo);
					break;
				}
				case 1:
				{
					ClearBit(DDRB_REG,Copy_u8PinNo);
					break;
				}
				case 2:
				{
					ClearBit(DDRC_REG,Copy_u8PinNo);
					break;
				}
				case 3:
				{
					ClearBit(DDRD_REG,Copy_u8PinNo);
					break;
				}

			}
		}
		else
		{
			Local_Status=RT_NOK;
		}

	}
	else
	{
		Local_Status=RT_NOK;
	}
}
else
{
	Local_Status=RT_NOK;
}


	return Local_Status;

}

u8 DIO_U8SetPinVal(enum PORTS Copy_u8PortNo,enum PINS  Copy_u8PinNo,u8 Copy_Val)

{
	u8 Local_Status=RT_OK;
if(Copy_u8PortNo>=0||Copy_u8PortNo<=3)
{
	if(Copy_u8PinNo>=0||Copy_u8PinNo<=7)
	{
		if(Copy_Val == HIGH)
		{
			switch(Copy_u8PortNo)
			{
			case 0:
			{
				SetBit(PORTA_REG,Copy_u8PinNo);
				break;
			}
			case 1:
			{
				SetBit(PORTB_REG,Copy_u8PinNo);
				break;
			}
			case 2:
			{
				SetBit(PORTC_REG,Copy_u8PinNo);
				break;
			}
			case 3:
			{
				SetBit(PORTD_REG,Copy_u8PinNo);
				break;
			}

			}
		}
		else if(Copy_Val==LOW)
		{
			switch(Copy_u8PortNo)
			{
				case 0:
				{
					ClearBit(PORTA_REG,Copy_u8PinNo);
					break;
				}
				case 1:
				{
					ClearBit(PORTB_REG,Copy_u8PinNo);
					break;
				}
				case 2:
				{
					ClearBit(PORTC_REG,Copy_u8PinNo);
					break;
				}
				case 3:
				{
					ClearBit(PORTD_REG,Copy_u8PinNo);
					break;
				}

			}
		}
		else
		{
			Local_Status=RT_NOK;
		}

	}
	else
	{
		Local_Status=RT_NOK;
	}
}
else
{
	Local_Status=RT_NOK;
}


	return Local_Status;
}

u8 DIO_U8GetPinVal(enum PORTS Copy_u8PortNo,enum PINS  Copy_u8PinNo, u8* u8_Val)
{
	u8 Local_Status=RT_OK;
	if(Copy_u8PortNo>=0||Copy_u8PortNo<=3)
	{
		if(Copy_u8PinNo>=0||Copy_u8PinNo<=7)
		{

				switch(Copy_u8PortNo)
				{
				case 0:
				{
					*u8_Val=GetBit(PINA_REG,Copy_u8PinNo);
					break;
				}
				case 1:
				{
					*u8_Val=GetBit(PINB_REG,Copy_u8PinNo);
					break;
				}
				case 2:
				{
					*u8_Val=GetBit(PINC_REG,Copy_u8PinNo);
					break;
				}
				case 3:
				{
					*u8_Val=GetBit(PIND_REG,Copy_u8PinNo);
					break;
				}

				}

		}
		else
		{
			Local_Status=RT_NOK;
		}
	}
	else
	{
		Local_Status=RT_NOK;
	}


		return Local_Status;
}
