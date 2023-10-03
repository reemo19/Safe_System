/*
 * I2C.c
 *
 *  Created on: Aug 24, 2023
 *      Author: hp
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_INTERFACE.h"
#include "TWI.h"
#include "EEPROM.h"
#include <avr/io.h>
void EEPROM_write(u16 Copy_u16Address,u8 Copy_Data)
{
	u8 slv_w=0b10100000;

	TWI_Startcondition();
	TWI_senddata(slv_w);
	//lsb
	TWI_senddata((u8)Copy_u16Address);

	TWI_senddata(Copy_Data);
	TWI_stopcondition();
}

u8 EEPROM_read(u16 Copy_u16Address)
{
	u8 slv_w=0b10100000;
	u8 slv_r;
	slv_r=slv_w+1;

	//memory
	TWI_Startcondition();
	TWI_senddata(slv_w);
	TWI_senddata((u8)Copy_u16Address);
	///
	TWI_Startcondition();
	TWI_senddata(slv_r);

	u8 data=TWI_reseivedata();

	TWI_stopcondition();
	return data;

}
