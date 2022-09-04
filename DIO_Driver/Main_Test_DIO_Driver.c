#include"util/delay.h"
#include "../Files/STDTYPES.h"
#include "../Files/BIT_MATH.h"
#include "DIO_interface.h"
#include "DIO_REG.h"
#include "PORT_REG.h"
#include "PORT_Config.h"
#include "PORT_private.h"
#include "PORT_Interface.h"




int main(void)
{
u8 mm;
PORT_VoidInit();
SetBit(PORTD_REG,PIN0);
SetBit(PORTD_REG,PIN1);
u8 CounterUp=0;
u8 CounterDown=10;
u8 Counter=-1;
u8 arr[]= {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0xFF,0x6F};

	while(1)
	{

		while(GetBit(PINA_REG,PIN0)&&GetBit(PINA_REG,PIN1)&&GetBit(PINA_REG,PIN5)&&(!GetBit(PINA_REG,PIN2)))
		{CounterUp++;
		CounterDown--;
			for(u8 l=0;l<30;l++)
			{
				_delay_ms(10);

							ClearBit(PORTD_REG,PIN0);
							SetBit(PORTD_REG,PIN1);
							mm=DIO_U8SetPortVal(PORTC,arr[CounterUp-1]);
							//_delay_ms(500);
							if(CounterUp==10)
							{
								CounterUp=0;
							}
				_delay_ms(10);

							ClearBit(PORTD_REG,PIN1);
							SetBit(PORTD_REG,PIN0);
							mm=DIO_U8SetPortVal(PORTC,arr[CounterDown]);
							//_delay_ms(500);
							if(CounterDown==0)
							{
								CounterDown=10;
							}

			}
		}
		if(GetBit(PINA_REG,PIN0)&&(!GetBit(PINA_REG,PIN2))&&GetBit(PINA_REG,PIN5)&&(!GetBit(PINA_REG,PIN1)))
		{



			CounterUp++;
			ClearBit(PORTD_REG,PIN0);
			SetBit(PORTD_REG,PIN1);
			mm=DIO_U8SetPortVal(PORTC,arr[CounterUp-1]);
			_delay_ms(500);
			if(CounterUp==10)
			{
				CounterUp=0;
			}

		}

		if(GetBit(PINA_REG,PIN1)&&(!GetBit(PINA_REG,PIN2))&&GetBit(PINA_REG,PIN5)&&(!GetBit(PINA_REG,PIN0)))
			{
			SetBit(PORTB_REG,PIN0);
			CounterDown--;
					ClearBit(PORTD_REG,PIN1);
					SetBit(PORTD_REG,PIN0);
					mm=DIO_U8SetPortVal(PORTC,arr[CounterDown]);
					_delay_ms(500);
					if(CounterDown==0)
					{
						CounterDown=10;
			        }
			}

			if((GetBit(PINA_REG,PIN2)||(GetBit(PINA_REG,PIN2)&&GetBit(PINA_REG,PIN0))||(GetBit(PINA_REG,PIN2)&&GetBit(PINA_REG,PIN1)))&&GetBit(PINA_REG,PIN5))
			{

				for(int j=0 ;j<10;j++)
				{


					for(int i=0 ;i<10;i++)
					{
								for(int k=0;k<30;k++)
									{
									ClearBit(PORTD_REG,PIN1);
									SetBit(PORTD_REG,PIN0);
									mm=DIO_U8SetPortVal(PORTC,arr[j]);
									_delay_ms(10);
									ClearBit(PORTD_REG,PIN0);
									SetBit(PORTD_REG,PIN1);
									mm=DIO_U8SetPortVal(PORTC,arr[i]);
									_delay_ms(10);
									}

					 }

				}
	    }
			if(GetBit(PINA_REG,PIN3)&&(!GetBit(PINA_REG,PIN4))&&GetBit(PINA_REG,PIN5))
			{Counter=-1;
				for(int i=0;i<2;i++)
				{
					while(Counter!=9)
					{
						Counter++;
						mm=DIO_U8SetPortVal(PORTB,1<<Counter);
						_delay_ms(200);

					}
					_delay_ms(200);

					while(Counter!=0)
					{
						Counter--;
						mm=DIO_U8SetPortVal(PORTB,1<<Counter);
						_delay_ms(200);


					}
				}
				_delay_ms(100);
			}
			if((GetBit(PINA_REG,PIN4)||(GetBit(PINA_REG,PIN3)&&GetBit(PINA_REG,PIN4)))&&GetBit(PINA_REG,PIN5))
			{
				Counter=-1;
					for(int i=0;i<2;i++)
				{
					while(Counter!=4)

					{
						Counter++;
						for(int k=0;k<30;k++)
					{

						mm=DIO_U8SetPortVal(PORTB,1<<Counter);
						_delay_ms(10);
						mm=DIO_U8SetPortVal(PORTB,128>>Counter);
						_delay_ms(10);
					}
					}
					_delay_ms(100);

					while(Counter!=0)
					{

						Counter--;
						for(int k=0;k<30;k++)
							{

							mm=DIO_U8SetPortVal(PORTB,1<<Counter);
								_delay_ms(10);
								mm=DIO_U8SetPortVal(PORTB,128>>Counter);
								_delay_ms(10);

							}

					}
				}

					_delay_ms(100);
			}



	}
	return 0;
}
