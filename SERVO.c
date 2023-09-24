/*
 * SERVO.c
 *
 *  Created on: Aug 21, 2023
 *      Author: hp
 */

#include "STD_TYPES.h"
#include"BIT_MATH.h"
#include"DIO_interface.h"
#include"TIMER_TEST_interface.h"
#include"SERVO.h"
#include"util/delay.h"
#include<avr/io.h>


void SERVO_voidSendAngle(u32 Copy_angle)
{

	//TIMER1_voidSetChannelA(1000+Copy_angle);
	//TIMER1_voidSetChannelA(5.556*Copy_angle+1500);
	//TIMER1_voidCtcChannelA(5.556*Copy_angle+1500);
	TIMER1_voidCtcChannelA(Copy_angle+1000);
	_delay_ms(10);
}
