/*****************************************************/
/************SWC    :DIO_PROG*************************/
/************BY     :RANAALI**************************/
/************VERSION:1.0******************************/
/************DATE   :27/8/2022************************/
/*****************************************************/
#include "../inc/std_types.h"
#include "../inc/bitmath.h"
#include "DIO_Private.h"
#include "DIO_Int.h"

//-----pins

/*Set DIO Pin Direction*/
void DIO_VidSetPinDir(u8 copy_u8Port,u8 copy_u8Pin,u8 copy_u8Direction)
{
	if (copy_u8Direction==Output)
	{
		switch (copy_u8Port)
		{
			case PORT_A: SET_BIT(DDRA,copy_u8Pin); break;
			case PORT_B: SET_BIT(DDRB,copy_u8Pin); break;
			case PORT_C: SET_BIT(DDRC,copy_u8Pin); break;
			case PORT_D: SET_BIT(DDRD,copy_u8Pin); break;
		}
	}
	else if (copy_u8Direction==Input)
	{
			switch (copy_u8Port)
		{
			case PORT_A: CLR_BIT(DDRA,copy_u8Pin); break;
			case PORT_B: CLR_BIT(DDRB,copy_u8Pin); break;
			case PORT_C: CLR_BIT(DDRC,copy_u8Pin); break;
			case PORT_D: CLR_BIT(DDRD,copy_u8Pin); break;
		}
	}
}
/*Set DIO Pin Value*/
void DIO_VidSetPinVal(u8 copy_u8Port,u8 copy_u8Pin,u8 copy_u8Value)
{
	if (copy_u8Value==PinHigh)
	{
		switch (copy_u8Port)
		{
			case PORT_A: SET_BIT(PORTA,copy_u8Pin); break;
			case PORT_B: SET_BIT(PORTB,copy_u8Pin); break;
			case PORT_C: SET_BIT(PORTC,copy_u8Pin); break;
			case PORT_D: SET_BIT(PORTD,copy_u8Pin); break;
		}
	}
	else if (copy_u8Value==PinLow)
	{
			switch (copy_u8Port)
		{
			case PORT_A: CLR_BIT(PORTA,copy_u8Pin); break;
			case PORT_B: CLR_BIT(PORTB,copy_u8Pin); break;
			case PORT_C: CLR_BIT(PORTC,copy_u8Pin); break;
			case PORT_D: CLR_BIT(PORTD,copy_u8Pin); break;
		}
	}
}

void DIO_VidGetPinVal(u8 copy_u8Port,u8 copy_u8Pin,u8*pu8Value)
{
	switch (copy_u8Port)
		{
			case PORT_A: *pu8Value=GET_BIT(PINA,copy_u8Pin); break;
			case PORT_B: *pu8Value=GET_BIT(PINB,copy_u8Pin); break;
			case PORT_C: *pu8Value=GET_BIT(PINC,copy_u8Pin); break;
			case PORT_D: *pu8Value=GET_BIT(PIND,copy_u8Pin); break;
		}
}
u8 DIO_u8GetPinValue(u8 Copy_u8Port,u8 Copy_u8PinNo)
{
	u8 Local_u8Reading=0;
	if(Copy_u8PinNo<8)
	{
		switch(Copy_u8Port)
		{
		case PORT_A: Local_u8Reading = GET_BIT(PINA,Copy_u8PinNo); break;
		case PORT_B: Local_u8Reading = GET_BIT(PINB,Copy_u8PinNo); break;
		case PORT_C: Local_u8Reading = GET_BIT(PINC,Copy_u8PinNo); break;
		case PORT_D: Local_u8Reading = GET_BIT(PIND,Copy_u8PinNo); break;
		}
	}
	return Local_u8Reading;
}

//----ports

/*Set DIO Port Direction*/
void DIO_VidSetPortDir(u8 copy_u8Port,u8 copy_u8Direction)
{
	if (copy_u8Direction==Output)
	{
		switch (copy_u8Port)
		{
			case PORT_A: DDRA =0xff; break;
			case PORT_B: DDRB =0xff; break;
			case PORT_C: DDRC =0xff; break;
			case PORT_D: DDRD =0xff; break;
		}
	}
	else if (copy_u8Direction==Input)
	{
			switch (copy_u8Port)
		{
			case PORT_A: DDRA =0x00; break;
			case PORT_B: DDRB =0x00; break;
			case PORT_C: DDRC =0x00; break;
			case PORT_D: DDRD =0x00; break;
		}
	}
}
/*Set DIO Port Value*/
void DIO_VidSetPortVal(u8 copy_u8Port,u8 copy_u8Value)
{
	switch (copy_u8Port)
		{
			case PORT_A: PORTA = copy_u8Value;  break;
			case PORT_B: PORTB = copy_u8Value;  break;
			case PORT_C: PORTC = copy_u8Value;  break;
			case PORT_D: PORTD = copy_u8Value;  break;
		}
}
/*Get DIO Port Value*/
void DIO_VidGetPortVal(u8 copy_u8Port,u8*pu8Value)
{
	switch (copy_u8Port)
		{
			case PORT_A: *pu8Value=PORTA; break;
			case PORT_B: *pu8Value=PORTB; break;
			case PORT_C: *pu8Value=PORTC; break;
			case PORT_D: *pu8Value=PORTD; break;
		}
}
