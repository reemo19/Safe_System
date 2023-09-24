
#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"DIO_interface.h"
#include"KPD_interface.h"


u8 KPD_u8GetPressedKey(void)
{
	u8 Local_u8PressedKey=KPD_NO_PRESSED_KEY,Local_u8Col_INDEX,Local_u8Row_INDEX;
    u8 Local_u8PinState;
static u8 Local_u8KPDArr[ROW_NUMBER][COLUMN_NUMBER]=KPD_ARR;
static u8 Local_u8KPDColumnArr[COLUMN_NUMBER]={KPD_COLUMN0_PIN,KPD_COLUMN1_PIN,KPD_COLUMN2_PIN};
static u8 Local_u8KPDRowArr[ROW_NUMBER]={KPD_ROW0_PIN,KPD_ROW1_PIN,KPD_ROW2_PIN,KPD_ROW3_PIN};


	for(Local_u8Col_INDEX=0;Local_u8Col_INDEX<COLUMN_NUMBER;Local_u8Col_INDEX++)
	{

	DIO_u8SetPinValue(KPD_PORT,Local_u8KPDColumnArr[Local_u8Col_INDEX],DIO_LOW);

		for(Local_u8Row_INDEX=0;Local_u8Row_INDEX<ROW_NUMBER;Local_u8Row_INDEX++)
		{
			DIO_u8GetPinValue(KPD_PORT,Local_u8KPDRowArr[Local_u8Row_INDEX],&Local_u8PinState);
			if(DIO_LOW==Local_u8PinState)
			{

				Local_u8PressedKey=Local_u8KPDArr[Local_u8Row_INDEX][Local_u8Col_INDEX];
               /*Polling(busy waiting until the key is releassed)*/
				while(DIO_LOW==Local_u8PinState)
				{
					DIO_u8GetPinValue(KPD_PORT,Local_u8KPDRowArr[Local_u8Row_INDEX],&Local_u8PinState);

				}
				return Local_u8PressedKey;
			}
		}
		DIO_u8SetPinValue(KPD_PORT,Local_u8KPDColumnArr[Local_u8Col_INDEX],DIO_HIGH);
	}
	return Local_u8PressedKey;
}

