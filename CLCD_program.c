
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "CLCD_interface.h"
#include "DIO_INTERFACE.h"
#include <util/delay.h>
void CLCD_voidSendCommand(u8 copy_u8Command)
{
	/*Setting RS pin to low*/
DIO_u8SetPinValue(CLCD_CONTROL_PORT,CLCD_RS_PIN,DIO_LOW);
/*Setting RW pin low for write*/
//DIO_u8SetPinValue(CLCD_CONTROL_PORT,CLCD_RW_PIN,DIO_LOW);

/*Set command data pins*/
DIO_u8SetPortValue(CLCD_DATA_PORT,copy_u8Command);

/*Send Enable pulse*/
DIO_u8SetPinValue(CLCD_CONTROL_PORT,CLCD_E_PIN,DIO_HIGH);
_delay_ms(2);
DIO_u8SetPinValue(CLCD_CONTROL_PORT,CLCD_E_PIN,DIO_LOW);
}

void CLCD_voidInit(void)
{
	/*Wait more that 30 ms*/
	_delay_ms(40);

	/*Function set ,2 lines AND 5*8 size*/
	CLCD_voidSendCommand(0b00111000);
	/*Display on/off control:diplay enable,disable cursor*/
	CLCD_voidSendCommand(0b00001100);
	/*display clear*/
	CLCD_voidSendCommand(1);



}


void CLCD_voidSendData(u8 copy_u8Data)
{

	/*Setting RS pin to HIGH*/
	DIO_u8SetPinValue(CLCD_CONTROL_PORT,CLCD_RS_PIN,DIO_HIGH);
	/*Setting RW pin low for write*/
	//DIO_u8SetPinValue(CLCD_CONTROL_PORT,CLCD_RW_PIN,DIO_LOW);

	/*Set data pins*/
	DIO_u8SetPortValue(CLCD_DATA_PORT,copy_u8Data);

	/*Send Enable pulse*/
	DIO_u8SetPinValue(CLCD_CONTROL_PORT,CLCD_E_PIN,DIO_HIGH);
	_delay_ms(2);
	DIO_u8SetPinValue(CLCD_CONTROL_PORT,CLCD_E_PIN,DIO_LOW);


}

void CLCD_voidSendString(const u8* Copy_u8String)
{
u8 Local_u8Counter=0;
while(Copy_u8String[Local_u8Counter]!='\0')
{
    CLCD_voidSendData(Copy_u8String[Local_u8Counter]);
    Local_u8Counter++;
}

}


void CLCD_voidGoToXY(u8 Copy_u8Xposition,u8 Copy_u8Yposition)
{
  u8 Local_u8Address;

  if(Copy_u8Xposition==0)
  {
	  Local_u8Address=Copy_u8Yposition;
  }
  else if(Copy_u8Xposition==1)

  {
	  Local_u8Address=Copy_u8Yposition+0x40;
  }

  CLCD_voidSendCommand(Local_u8Address|(1<<7));
}


void CLCD_voidWriteNumber(u32 copy_u32Number)
{
	u8 Local_u8Digit;
	u8 Local_u8Counter=0;
	s8 Local_u8Counter2;
	static u8 Local_ArrayOfChar[10]={'0','1','2','3','4','5','6','7','8','9'};
	static u8 Local_ArrayOfDigits[10];

	if(copy_u32Number==0)
	{
		CLCD_voidSendData(Local_ArrayOfChar[0]);
	}
	else
	{

		while(copy_u32Number>0)
		{
			Local_u8Digit=copy_u32Number%10;
			copy_u32Number=copy_u32Number/10;
			Local_ArrayOfDigits[Local_u8Counter]=Local_ArrayOfChar[Local_u8Digit];
			Local_u8Counter++;
		}

		for(Local_u8Counter2=Local_u8Counter-1;Local_u8Counter2>=0;Local_u8Counter2--)
		{
			CLCD_voidSendData(Local_ArrayOfDigits[Local_u8Counter2]);
		}
	}
}
void CLCD_voidWriteSpecialChar(u8* copy_pu8Pattern,u8 copy_u8PatternNumber,u8 copy_u8Xposition,u8 copy_u8Yposition)
{
	u8 Local_u8CGRAM_Address=0;
	/*Set the CGRAM address*/
Local_u8CGRAM_Address=copy_u8PatternNumber*8;
CLCD_voidSendCommand(Local_u8CGRAM_Address|(1<<6));

for(u8 i=0;i<8;i++)
{
	CLCD_voidSendData(copy_pu8Pattern[i]);
}
/*go back to DDRAM to display the Arr*/
 CLCD_voidGoToXY(copy_u8Xposition,copy_u8Yposition);

CLCD_voidSendData(copy_u8PatternNumber);

}


