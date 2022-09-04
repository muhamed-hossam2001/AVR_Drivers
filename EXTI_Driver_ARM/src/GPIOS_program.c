
#include "BIT_MATH.h"
#include "STDTYPES.h"
#include "CHECK_ERROR.h"
#include "GPIOS_interface.h"
#include "GPIOS_private.h"
#include "GPIOS_config.h"


u8 GPIOS_u8SetPinDir(u8 Copy_u8PORT, u8 Copy_u8PIN,u8 Copy_u8Mode)
{
	u8 Local_u8ErrorStatus=RT_OK;

	if(Copy_u8PORT>2||Copy_u8PIN>15)
	{
		Local_u8ErrorStatus=RT_NOK;
	}
	else
	{
		if(Copy_u8PIN<=7)
		{
			switch(Copy_u8PORT)
					{
						case GPIOS_PORTA:
										{
											GPIOS_PORTA_CRL&=~((0x0F)<<Copy_u8PIN*4);
											GPIOS_PORTA_CRL|=Copy_u8Mode<<Copy_u8PIN*4;
											break;
										}
						case GPIOS_PORTB:
										{
											GPIOS_PORTB_CRL&=~((0x0F)<<Copy_u8PIN*4);
											GPIOS_PORTB_CRL|=Copy_u8Mode<<Copy_u8PIN*4;
											break;
										}
						case GPIOS_PORTC:
										{
											GPIOS_PORTC_CRL&=~((0x0F)<<(Copy_u8PIN*4));
											GPIOS_PORTC_CRL|=Copy_u8Mode<<(Copy_u8PIN*4);
											break;
										}
					}

		}
		else
		{
			Copy_u8PIN=Copy_u8PIN-8;

			switch(Copy_u8PORT)
					{
					case GPIOS_PORTA:
									{
										GPIOS_PORTA_CRH&=~((0x0F)<<Copy_u8PIN*4);
										GPIOS_PORTA_CRH|=Copy_u8Mode<<Copy_u8PIN*4;
										break;
									}
					case GPIOS_PORTB:
									{
										GPIOS_PORTB_CRH&=~((0x0F)<<Copy_u8PIN*4);
										GPIOS_PORTB_CRH|=Copy_u8Mode<<Copy_u8PIN*4;
										break;
									}
					case GPIOS_PORTC:
									{
										GPIOS_PORTC_CRH&=~((0x0F)<<Copy_u8PIN*4);
										GPIOS_PORTC_CRH|=Copy_u8Mode<<Copy_u8PIN*4;
										break;
									}
					}

		 }
	}

	return Local_u8ErrorStatus;
}

u8 GPIOS_u8SetPortVal(u8 Copy_u8PORT,u32 Copy_u8PortVal)
{
	u8 Local_u8ErrorStatus=RT_OK;

	if(Copy_u8PORT>2)
	{
		Local_u8ErrorStatus=RT_NOK;

	}
	else
	{
		switch(Copy_u8PORT)
		{
			case GPIOS_PORTA:
							{
								GPIOS_PORTA_ODR=Copy_u8PortVal;
								break;
							}
			case GPIOS_PORTB:
							{
								GPIOS_PORTB_ODR=Copy_u8PortVal;
								break;
							}
			case GPIOS_PORTC:
							{
								GPIOS_PORTC_ODR=Copy_u8PortVal;
								break;
							}
		}

	}

	return Local_u8ErrorStatus;
}

u8 GPIOS_u8GetPinVal(u8 Copy_u8PORT,u8 Copy_u8PIN ,u8 *Copy_U8ptrPinVal)
{
	u8 Local_u8ErrorStatus=RT_OK;

		if(Copy_u8PORT>2||Copy_u8PIN>15)
		{
			Local_u8ErrorStatus=RT_NOK;

		}
		else
		{
			/*to follow misra Rules that No More one return in function*/
				switch(Copy_u8PORT)
						{
							case GPIOS_PORTA:
											{
												*Copy_U8ptrPinVal =GET_BIT(GPIOS_PORTA_IDR,Copy_u8PIN);
												break;
											}
							case GPIOS_PORTB:
											{
												*Copy_U8ptrPinVal=GET_BIT(GPIOS_PORTB_IDR,Copy_u8PIN);
												break;
											}
							case GPIOS_PORTC:
											{
												*Copy_U8ptrPinVal= GET_BIT(GPIOS_PORTC_IDR,Copy_u8PIN);
												break;
											}
						}


		}

		return Local_u8ErrorStatus;
}

u8 GPIOS_u8SetPinVal(u8 Copy_u8PORT,u8 Copy_u8PIN, u8 Copy_u8PinVal)
{
	u8 Local_u8ErrorStatus=RT_OK;


		if(Copy_u8PORT>2||Copy_u8PIN>15)
		{
			Local_u8ErrorStatus=RT_NOK;

		}
		else
		{
			/*to set the output of the PIN or Set input Pull Up/Down*/
			if(Copy_u8PinVal==GPIOS_HIGH ||Copy_u8PinVal==GPIOS_PULL_UP)
			{
				switch(Copy_u8PORT)
						{
							case GPIOS_PORTA:
											{
												 SET_BIT(GPIOS_PORTA_ODR,Copy_u8PIN);
												break;
											}
							case GPIOS_PORTB:
											{
												 SET_BIT(GPIOS_PORTB_ODR,Copy_u8PIN);
												break;
											}
							case GPIOS_PORTC:
											{
												 SET_BIT(GPIOS_PORTC_ODR,Copy_u8PIN);
												break;
											}
						}
			}
			else
			{
				switch(Copy_u8PORT)
						{
							case GPIOS_PORTA:
											{
												 CLR_BIT(GPIOS_PORTA_ODR,Copy_u8PIN);
												break;
											}
							case GPIOS_PORTB:
											{
												 CLR_BIT(GPIOS_PORTB_ODR,Copy_u8PIN);
												break;
											}
							case GPIOS_PORTC:
											{
												 CLR_BIT(GPIOS_PORTC_ODR,Copy_u8PIN);
												break;
											}
						}

			}


		}

		return Local_u8ErrorStatus;
}

u8 GPIOS_u8ClearPin(u8 Copy_u8PORT,u8 Copy_u8PIN)
{
	u8 Local_u8ErrorStatus=RT_OK;


		if(Copy_u8PORT>2||Copy_u8PIN>15)
		{
			Local_u8ErrorStatus=RT_NOK;

		}
		else
		{
			/*to set the output of the PIN or Set input Pull Up/Down*/

				switch(Copy_u8PORT)
						{
							case GPIOS_PORTA:
											{
												GPIOS_PORTA_BRR=1<<Copy_u8PIN;
												break;
											}
							case GPIOS_PORTB:
											{
												GPIOS_PORTB_BRR=1<<Copy_u8PIN;
												break;
											}
							case GPIOS_PORTC:
											{
												GPIOS_PORTC_BRR=1<<Copy_u8PIN;
												break;
											}

						}


		}

		return Local_u8ErrorStatus;
}

u8 GPIOS_u8ClearPort(u8 Copy_u8PORT)
{
	u8 Local_u8ErrorStatus=RT_OK;


		if(Copy_u8PORT>2)
		{
			Local_u8ErrorStatus=RT_NOK;

		}
		else
		{
			/*to set the output of the PIN or Set input Pull Up/Down*/

				switch(Copy_u8PORT)
						{
							case GPIOS_PORTA:
											{
												GPIOS_PORTA_BRR=0xFFFFFFFF;
												break;
											}
							case GPIOS_PORTB:
											{
												GPIOS_PORTB_BRR=0xFFFFFFFF;
												break;
											}
							case GPIOS_PORTC:
											{
												GPIOS_PORTC_BRR=0xFFFFFFFF;
												break;
											}

						}


		}

		return Local_u8ErrorStatus;
}

u8 GPIOS_u8SetPin(u8 Copy_u8PORT,u8 Copy_u8PIN)
{
	u8 Local_u8ErrorStatus=RT_OK;


		if(Copy_u8PORT>2||Copy_u8PIN>15)
		{
			Local_u8ErrorStatus=RT_NOK;

		}
		else
		{
			/*to set the output of the PIN or Set input Pull Up/Down*/

				switch(Copy_u8PORT)
						{
							case GPIOS_PORTA:
											{
												GPIOS_PORTA_BSRR=1<<Copy_u8PIN;
												break;
											}
							case GPIOS_PORTB:
											{
												GPIOS_PORTB_BSRR=1<<Copy_u8PIN;
												break;
											}
							case GPIOS_PORTC:
											{
												GPIOS_PORTC_BSRR=1<<Copy_u8PIN;
												break;
											}

						}


		}

		return Local_u8ErrorStatus;
}

u8 GPIOS_u8SetPort(u8 Copy_u8PORT)
{
	u8 Local_u8ErrorStatus=RT_OK;


		if(Copy_u8PORT>2)
		{
			Local_u8ErrorStatus=RT_NOK;


		}
		else
		{
			/*to set the output of the PIN or Set input Pull Up/Down*/

				switch(Copy_u8PORT)
						{
							case GPIOS_PORTA:
											{
												GPIOS_PORTA_BSRR=0x0000FFFF;
												break;
											}
							case GPIOS_PORTB:
											{
												GPIOS_PORTB_BSRR=0x0000FFFF;
												break;
											}
							case GPIOS_PORTC:
											{
												GPIOS_PORTC_BSRR=0x0000FFFF;
												break;
											}

						}


		}

		return Local_u8ErrorStatus;
}

u8 GPIOS_u8LockPort(u8 Copy_u8PORT)
{
	u8 Local_u8ErrorStatus=RT_OK;
	u8 Local_u8ReadingOnly;

		if(Copy_u8PORT>2)
		{
			Local_u8ErrorStatus=RT_NOK;

		}
		else
		{
			/*to set the output of the PIN or Set input Pull Up/Down*/

				switch(Copy_u8PORT)
						{
							case GPIOS_PORTA:
											{
												SET_BIT(GPIOS_PORTA_LCKR,PIN_16);
												CLR_BIT(GPIOS_PORTA_LCKR,PIN_16);
												SET_BIT(GPIOS_PORTA_LCKR,PIN_16);
												Local_u8ReadingOnly=GET_BIT(GPIOS_PORTA_LCKR,PIN_16);
												SET_BIT(GPIOS_PORTA_LCKR,PIN_16);
												break;
											}
							case GPIOS_PORTB:
											{
												SET_BIT(GPIOS_PORTB_LCKR,PIN_16);
												CLR_BIT(GPIOS_PORTB_LCKR,PIN_16);
												SET_BIT(GPIOS_PORTB_LCKR,PIN_16);
												Local_u8ReadingOnly=GET_BIT(GPIOS_PORTB_LCKR,PIN_16);
												SET_BIT(GPIOS_PORTB_LCKR,PIN_16);

												break;
											}
							case GPIOS_PORTC:
											{
												SET_BIT(GPIOS_PORTC_LCKR,PIN_16);
												CLR_BIT(GPIOS_PORTC_LCKR,PIN_16);
												SET_BIT(GPIOS_PORTC_LCKR,PIN_16);
												Local_u8ReadingOnly=GET_BIT(GPIOS_PORTC_LCKR,PIN_16);
												SET_BIT(GPIOS_PORTC_LCKR,PIN_16);
												break;
											}

						}


		}

		return Local_u8ErrorStatus;
}

u8 GPIOS_u8LockPin(u8 Copy_u8PORT,u8 Copy_u8PIN )
{
	u8 Local_u8ErrorStatus=RT_OK;


		if(Copy_u8PORT>2||Copy_u8PIN>15)
		{
			Local_u8ErrorStatus=RT_NOK;

		}
		else
		{

				switch(Copy_u8PORT)
						{
							case GPIOS_PORTA:
											{
												 CLR_BIT(GPIOS_PORTA_LCKR,PIN_16);
												 SET_BIT(GPIOS_PORTA_ODR,Copy_u8PIN);
												break;
											}
							case GPIOS_PORTB:
											{
												CLR_BIT(GPIOS_PORTB_LCKR,PIN_16);
											    SET_BIT(GPIOS_PORTB_ODR,Copy_u8PIN);
												break;
											}
							case GPIOS_PORTC:
											{
												CLR_BIT(GPIOS_PORTC_LCKR,PIN_16);
												SET_BIT(GPIOS_PORTC_ODR,Copy_u8PIN);
												break;
											}
						}


		}

		return Local_u8ErrorStatus;
}














