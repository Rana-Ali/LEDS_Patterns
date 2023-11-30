/*****************************************************/
/************SWC    :DIO_INT**************************/
/************BY     :RANAALI**************************/
/************VERSION:1.0******************************/
/************DATE   :27/8/2022************************/
/*****************************************************/
#ifndef DIO_INT_H
#define DIO_INT_H

typedef enum 
{
	PORT_A,
	PORT_B,
	PORT_C,
	PORT_D
}et_ports;

typedef enum 
{
	Pin_0,
	Pin_1,
	Pin_2,
	Pin_3,
	Pin_4,
	Pin_5,
	Pin_6,
	Pin_7	
}et_pins;

typedef enum 
{
	Input,
	Output	
}et_Direction;

typedef enum 
{
	PinHigh,
	PinLow	
}et_PinValue;

//-----pins

/*Set DIO Pin Direction*/
void DIO_VidSetPinDir(u8 copy_u8Port,u8 copy_u8Pin,u8 copy_u8Direction);
/*Set DIO Pin Value*/
void DIO_VidSetPinVal(u8 copy_u8Port,u8 copy_u8Pin,u8 copy_u8Value);
/*Get DIO Pin Value*/
void DIO_VidGetPinVal(u8 copy_u8Port,u8 copy_u8Pin,u8*pu8Value);
u8 DIO_u8GetPinValue(u8 Copy_u8Port,u8 Copy_u8PinNo);

//----ports

/*Set DIO Port Direction*/
void DIO_VidSetPortDir(u8 copy_u8Port,u8 copy_u8Direction);
/*Set DIO Port Value*/
void DIO_VidSetPortVal(u8 copy_u8Port,u8 copy_u8Value);
/*Get DIO Port Value*/
void DIO_VidGetPortVal(u8 copy_u8Port,u8*pu8Value);




#endif
