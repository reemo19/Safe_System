/*
 * GIE.c
 *
 *  Created on: Aug 17, 2023
 *      Author: hp
 */
#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"DIO_interface.h"
#include"util/delay.h"
#include"GIE.h"
#include <avr/interrupt.h>

void GIE_voidEnable()
{
	SET_BIT(SREG,7);
}
void GIE_voidDisable()
{
	CLEAR_BIT(SREG,7);
}
