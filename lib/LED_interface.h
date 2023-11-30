/*****************LED Interface******************/
/**********Author: Rana Ali**********************/
/****************Date:17/08/2023.****************/
/************************************************/

#ifndef LED_INTERFACE_H
#define LED_INTERFACE_H

#define MAX_LENGTH 16

typedef enum 
{
IDLE=0,
FLASHING,
SHIFT_LEFT,
SHIFT_RIGHT,
SHIFT_LEFT_VARY_BRIGHTNESS,
DIVERGENCE,
CONVERGENCE,
PINGPONG,
SNAKE_EFFECT,
PULSING
}LED_STATE;

typedef struct
{
u16  delay;
s32 pattern[MAX_LENGTH];
}LED_PATTERN;

void LED_vidInit(void);
void LED_vidActivatePattern(void*ptr);



#endif
