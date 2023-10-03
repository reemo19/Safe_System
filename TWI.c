/*
 * I2C.c
 *
 *  Created on: Aug 24, 2023
 *      Author: hp
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_INTERFACE.h"
#include <avr/io.h>
#include "TWI.h"
void TWI_voidMasterInit()
{
	/*freq 15000*/
	TWBR=255;
CLEAR_BIT(TWSR,TWPS0);
CLEAR_BIT(TWSR,TWPS1);
//ENABLE TWI
TWCR=(1<<TWEN);
}
void TWI_SetMyAddress(u8 Copy_u8ADDress)
{
	TWAR=TWAR&0x1;
	TWAR=TWAR|(Copy_u8ADDress<<1);
}
void TWI_Startcondition()
{
	//START         PREF ENABLE  clear FLAG
	TWCR=(1<<TWSTA)|(1<<TWEN)|(1<<TWINT);
	//WHAIT
	while(GET_BIT(TWCR,TWINT)==0);

}
void TWI_stopcondition()
{
	//stop
	TWCR=(1<<TWSTO)|(1<<TWEN)|(1<<TWINT);
}

void TWI_senddata(u8 Copy_data)
{
	TWDR=Copy_data;
	TWCR=(1<<TWEN)|(1<<TWINT);
	while(GET_BIT(TWCR,TWINT)==0);
}
u8 TWI_reseivedata()
{
	TWCR=(1<<TWEN)|(1<<TWINT);
	while(GET_BIT(TWCR,TWINT)==0);
	return TWDR;
}







