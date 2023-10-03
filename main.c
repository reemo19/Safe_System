/*
 * main.c
 *
 *  Created on: Sep 23, 2023
 *      Author: hp
 */
#include "STD_TYPES.h"
#include"BIT_MATH.h"
#include"DIO_interface.h"
#include "CLCD_interface.h"
#include "KPD_interface.h"
#include "TIMER_TEST_interface.h"
#include "GIE.h"
#include "TWI.h"
#include "EEPROM.h"
#include "SERVO.h"
#include"util/delay.h"
#include "avr/interrupt.h"
#include<avr/io.h>

u8 firstDigit,sDigit,thDigit,lastDigit,pass=0,trypass=0,c=1,x,block;
int main()
{
	//twi
	TWI_voidMasterInit();

	//led
	DIO_u8SetPinDir(DIO_PORTC,DIO_PIN2,DIO_PIN_OUT);//G
	DIO_u8SetPinDir(DIO_PORTC,DIO_PIN3,DIO_PIN_OUT);//R

	//SERVO
	 DIO_u8SetPinDir(DIO_PORTD,DIO_PIN5,DIO_PIN_OUT);
	 //TIMER 1
	TIMER1_voidInit();
	TIMER1_voidSetICR(20000);
	//TIMER 0

	TIMER0_voidOfInit();
	TIMER0_voidPreLoadValue(192);
	GIE_voidEnable();
	//LCD
		  DIO_u8SetPortDir(DIO_PORTA, DIO_PORT_OUT);
		  DIO_u8SetPinDir(DIO_PORTC,DIO_PIN5,DIO_PIN_OUT);
		  DIO_u8SetPinDir(DIO_PORTC,DIO_PIN6,DIO_PIN_OUT);
			//kpd
			DIO_u8SetPortDir(DIO_PORTB, 0b00000111);
			DIO_u8SetPortValue(DIO_PORTB, 0xff);
			CLCD_voidInit();
	//var
u8 value;
CLCD_voidSendString("THE SAFE SYSTEM");
CLCD_voidGoToXY(1,0);
CLCD_voidSendString("enter '*' to start");
c=1;
	while(1)
	{

		 x=EEPROM_read(0x111);
		block= EEPROM_read(0x100);
		if(x==0xff)
		{

     				CLCD_voidSendCommand(0x01);
     				CLCD_voidSendString("password=----");
     				CLCD_voidGoToXY(0,9);
     				_delay_ms(500);
     				do
     				{
     					firstDigit=KPD_u8GetPressedKey();

     				} while (firstDigit==KPD_NO_PRESSED_KEY);
     				CLCD_voidWriteNumber(firstDigit);
     				_delay_ms(300);
     				CLCD_voidGoToXY(0,9);
     				CLCD_voidSendData('*');
     				do
 					{
 						sDigit=KPD_u8GetPressedKey();

 					} while (sDigit==KPD_NO_PRESSED_KEY);
     				CLCD_voidGoToXY(0,10);
 					CLCD_voidWriteNumber(sDigit);
 					_delay_ms(300);
 					CLCD_voidGoToXY(0,10);
 					CLCD_voidSendData('*');
 				
 				CLCD_voidGoToXY(0,11);
 				do
       			{
       				thDigit=KPD_u8GetPressedKey();

       			} while (thDigit==KPD_NO_PRESSED_KEY);
 				CLCD_voidGoToXY(0,11);
       			CLCD_voidWriteNumber(thDigit);
       			_delay_ms(300);
       			CLCD_voidGoToXY(0,11);
       			CLCD_voidSendData('*');
       			do
       			{
       				lastDigit=KPD_u8GetPressedKey();

       			} while (lastDigit==KPD_NO_PRESSED_KEY);
       			CLCD_voidGoToXY(0,12);
       			CLCD_voidWriteNumber(lastDigit);
       			_delay_ms(300);
       			CLCD_voidGoToXY(0,12);
       			CLCD_voidSendData('*');
              pass=(lastDigit)+1000*(thDigit)+100*(sDigit)+10*(firstDigit);
              EEPROM_write(0x111,pass);
              	_delay_ms(100);
              x=EEPROM_read(0x111);

              CLCD_voidSendCommand(0x01);

		}
		else if(x!=0xff&&c<4)
		{
			  CLCD_voidSendCommand(0x01);
			CLCD_voidSendString("check pass");
			_delay_ms(150);
                 CLCD_voidSendCommand(0x01);
                 CLCD_voidGoToXY(0,0);
                  CLCD_voidSendString("pass");
	     		CLCD_voidWriteNumber(c);
	     		CLCD_voidSendString("=----");
	     	   CLCD_voidGoToXY(0,6);
	     				_delay_ms(500);
	     				do
	     				{

	     					firstDigit=KPD_u8GetPressedKey();

	     				} while (firstDigit==KPD_NO_PRESSED_KEY);
	     				CLCD_voidGoToXY(0,6);
	     				CLCD_voidWriteNumber(firstDigit);
	     				_delay_ms(300);
	     				CLCD_voidGoToXY(0,6);
	     				CLCD_voidSendData('*');
	     				do
	 					{
	 						sDigit=KPD_u8GetPressedKey();

	 					} while (sDigit==KPD_NO_PRESSED_KEY);
	     				CLCD_voidGoToXY(0,7);
	 					CLCD_voidWriteNumber(sDigit);
	 					_delay_ms(300);
	 					CLCD_voidGoToXY(0,7);
	 					CLCD_voidSendData('*');

	 				do
	       			{
	       				thDigit=KPD_u8GetPressedKey();

	       			} while (thDigit==KPD_NO_PRESSED_KEY);
	 				CLCD_voidGoToXY(0,8);
	       			CLCD_voidWriteNumber(thDigit);
	       			_delay_ms(300);
	       			CLCD_voidGoToXY(0,8);
	       			CLCD_voidSendData('*');
	       			do
	       			{
	       				lastDigit=KPD_u8GetPressedKey();

	       			} while (lastDigit==KPD_NO_PRESSED_KEY);
	       			CLCD_voidGoToXY(0,9);
	       			CLCD_voidWriteNumber(lastDigit);
	       			_delay_ms(300);
	       			CLCD_voidGoToXY(0,9);
	       			CLCD_voidSendData('*');
	       			c++;
	             trypass=(lastDigit)+1000*(thDigit)+100*(sDigit)+10*(firstDigit);
	              CLCD_voidSendCommand(0x01);

	              		if(x==trypass)
	              		{

	              			SERVO_voidSendAngle(500);

	              				DIO_u8SetPinValue(DIO_PORTC,DIO_PIN2,DIO_HIGH);
	              				DIO_u8SetPinValue(DIO_PORTC,DIO_PIN3,DIO_LOW);

	              				c=4;
	              				CLCD_voidSendCommand(0x01);
	              				CLCD_voidSendString("open ^_^");
	              				CLCD_voidGoToXY(1,0);
	              		}
	              			else
	              			{

	              				//led
	              				DIO_u8SetPinValue(DIO_PORTC,DIO_PIN2,DIO_LOW);
	              				DIO_u8SetPinValue(DIO_PORTC,DIO_PIN3,DIO_HIGH);
	              				CLCD_voidSendCommand(0x01);
	              				if(c<4)
	              				{
	              			    CLCD_voidSendString("TRY AGAIN");
	              			  DIO_u8SetPinDir(DIO_PORTB,DIO_PIN7,DIO_PIN_OUT);
	              		    SET_BIT(PORTB,7);
	         			   _delay_ms(500);
	         				CLCD_voidSendCommand(0x01);
	         				DIO_u8SetPinDir(DIO_PORTB,DIO_PIN7,DIO_PIN_IN);
	         				 CLEAR_BIT(PORTB,7);
	    				         }
	              				else
	              				{

	              				CLCD_voidSendString("wrong password");
	              				CLCD_voidGoToXY(1,7);
	              				CLCD_voidSendString("-_-");
	              				DIO_u8SetPinDir(DIO_PORTB,DIO_PIN7,DIO_PIN_OUT);
	              				 SET_BIT(PORTB,7);
	              				EEPROM_write(0x100,0x00);
	              				block= EEPROM_read(0x100);
 	              			   _delay_ms(150);
                                 c=1;
	              				}

	              		}

		}


		}
	}
ISR(TIMER0_OVF_vect)
{
	static u16 a=0;
	a++;
	if(a==3907){
      TCNT0=192;
      a=0;
      if(block!=0xff){
	   // CLCD_voidSendCommand(0x01);
	        CLCD_voidGoToXY(1,0);
	    	CLCD_voidSendString("wait 30s!!!");
	    	DIO_u8SetPinDir(DIO_PORTB,DIO_PIN7,DIO_PIN_IN);
	    	 CLEAR_BIT(PORTB,7);
	    	_delay_ms(3000);
	    	 c=1;
	    	EEPROM_write(0x100,0xff);
	      block= EEPROM_read(0x100);
	     x=EEPROM_read(0x111);
	    	 CLCD_voidGoToXY(1,0);
	    	 CLCD_voidSendString("try know");

      }

	    }
	}
