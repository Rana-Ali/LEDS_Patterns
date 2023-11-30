/*
 * GccApplication2.c
 *
 * Created: 11/26/2023 2:01:49 PM
 * Author : lenovo
 */ 

#include <avr/io.h>
#include "../inc/std_types.h"
#include "../inc/bitmath.h"
#include "../lib/DIO_Int.h"
#include "../lib/LED_interface.h"
#include "../lib/KPD_Int.h"
#include "../lib/FreeRTOS.h"
#include "../lib/task.h"





int main(void)
{	
	LED_vidInit();
	KPD_vidInit();
	/*Create an Rtos Task*/
	xTaskCreate(KPD_GetPressedKey, NULL, 250, NULL, 3, NULL);
	xTaskCreate(LED_vidActivatePattern, NULL, 250, NULL, 3, NULL);
	
	/*Start Rtos*/
	vTaskStartScheduler();
while(1)
{
	
}

return 0;
}

