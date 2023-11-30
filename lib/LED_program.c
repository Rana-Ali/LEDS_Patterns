/******************LED Program*******************/
/**********Author: Rana Ali *********************/
/********************Ver.: 01********************/
/****************Date:17/08/2023.****************/
/************************************************/

#include "../inc/std_types.h"
#include "../inc/bitmath.h"
#include "DIO_Int.h"
#include "LED_private.h"
#include "LED_config.h"
#include "LED_interface.h"
#include "KPD_Int.h"
#include "FreeRTOS.h"
#include "task.h"


LED_STATE currentstate = IDLE;
LED_STATE previousstate ;
extern u8 key;


LED_PATTERN patterns[]=
{
	{1,{0,-1}},
	{500,{255,0,-1}},
	{250,{1,2,4,8,16,32,64,128,-1}},
	{250,{128,64,32,16,8,4,2,1,-1}},
	{250,{7,56,193,14,112,131,28,224,-1}},
	{300,{24,36,66,129,-1}},
	{300,{129,66,36,24,-1}},
	{250,{1,2,4,8,16,32,64,128,64,32,16,8,4,2,1,-1}},
	{300,{1,3,7,15,31,63,127,255,-1}},
	{1000,{255,0,-1}}
};
    u8 NumberOfPatterns = (sizeof(patterns)/sizeof(patterns[0]));
void LED_vidInit(void)
{
	/*Set Led Port direction as output*/
	DIO_VidSetPortDir(Animation_Port,Output);

}

void LED_vidActivatePattern(void*pvParameters)
{
	u8  static i=0;
	u16  static localcounter=0;
while(1)
{
localcounter++;
if(Valid_pattern)
{
	i=0;
	localcounter=0;
	currentstate=key;

}
if((patterns[currentstate].pattern[i])==-1)
{
	i=0;
}
if(localcounter==patterns[currentstate].delay){
i++;
localcounter=0;

}
DIO_VidSetPortVal(Animation_Port,patterns[currentstate].pattern[i]);

vTaskDelay(1);

}
}



