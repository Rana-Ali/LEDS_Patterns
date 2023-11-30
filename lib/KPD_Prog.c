/********************************** Header Files INCLUSIONS ****************************/
#include "../inc/std_types.h"
#include "util/delay.h"
#include "KPD_config.h"
#include "DIO_Int.h"
#include "KPD_Int.h"
#include "FreeRTOS.h"
#include "task.h"

/***************************************************************************************/

/*************************************** Constants *************************************/
/* Values of the Key Pad switches                                                      */
/* Matrix is not standard it depends on the connection between the Micro and KeyPad    */
const u8 KPD_au8SwitchVal[4][4] =
{
	{7,4,1,10},
	{8,5,2,0},
	{9,6,3,11},
	{12,13,14,15}
};
u8 volatile key= NOT_PRESSED;
/***************************************************************************************/



/***************************************************************************************/
/* Description! Interface to get the ID of the pressed key, return 0 incase no key     */
/*              is pressed, this function doesn't handle the sitaution if 2 keys are   */
/*              pressed at the same time                               	     		   */
/* Input      ! Nothing                                                                */
/* Output     ! Nothing                                                                */
/***************************************************************************************/
void KPD_GetPressedKey(void*pvParameters)
{
	u8 LOC_u8Column;

	u8 LOC_u8Row;

                                                                   
while(1) {
	/* Looping on columns of the Key Pad */                                                                               
	for (LOC_u8Column = 0 + COL_INIT; LOC_u8Column < COL_FIN; LOC_u8Column++)
	{
		/* Activate the Column                                                                                           */
		DIO_VidSetPinVal(PORT, LOC_u8Column, PinLow);

		/* Loop on the rows of the Key Pad */                                                                            
		for (LOC_u8Row = 0 + ROW_INIT; LOC_u8Row < ROW_FIN; LOC_u8Row++)
		{
			/* Check the status of the switch   */                                                                
			if (!DIO_u8GetPinValue(PORT, LOC_u8Row))
			{
				/* Get the value of the currently pressed switch                                                             */
				key = KPD_au8SwitchVal[LOC_u8Column - COL_INIT][LOC_u8Row - ROW_INIT];

				/* Wait until the switch is released (Single Press)                                                          */
				while (!DIO_u8GetPinValue(PORT, LOC_u8Row));

				/* Delay to avoid bouncing                                                                                   */
			
			}
		}
		
		/* Deactivate the Column                                                                                         */
		DIO_VidSetPinVal(PORT, LOC_u8Column, PinHigh);
	}
		vTaskDelay(1);
}
}


void KPD_vidInit(void)
{
	DIO_VidSetPinDir(PORT,Pin_0,Input);
	DIO_VidSetPinDir(PORT,Pin_1,Input);
	DIO_VidSetPinDir(PORT,Pin_2,Input);
	DIO_VidSetPinDir(PORT,Pin_3,Input);
	DIO_VidSetPinDir(PORT,Pin_4,Output);
	DIO_VidSetPinDir(PORT,Pin_5,Output);
	DIO_VidSetPinDir(PORT,Pin_6,Output);
	DIO_VidSetPinDir(PORT,Pin_7,Output);
	DIO_VidSetPinVal(PORT,Pin_0,PinHigh);
	DIO_VidSetPinVal(PORT,Pin_1,PinHigh);
	DIO_VidSetPinVal(PORT,Pin_2,PinHigh);
	DIO_VidSetPinVal(PORT,Pin_3,PinHigh);

}