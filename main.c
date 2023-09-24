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
#include "SERVO.h"
#include"util/delay.h"
#include<avr/io.h>

u8 firstDigit,sDigit,thDigit,lastDigit,pass=0,trypass=0,c=0;
int main()
{
	//led
	DIO_u8SetPinDir(DIO_PORTD,DIO_PIN1,DIO_PIN_OUT);//G
	DIO_u8SetPinDir(DIO_PORTD,DIO_PIN2,DIO_PIN_OUT);//R

	//SERVO
	 DIO_u8SetPinDir(DIO_PORTD,DIO_PIN5,DIO_PIN_OUT);
	 //TIMER
	TIMER1_voidInit();
	TIMER1_voidSetICR(20000);
	//LCD
		  DIO_u8SetPortDir(DIO_PORTA, DIO_PORT_OUT);
		  DIO_u8SetPortDir(DIO_PORTB, 0x03);
			//kpd
			DIO_u8SetPortDir(DIO_PORTC, 0b00000111);
			DIO_u8SetPortValue(DIO_PORTC, 0xff);
			CLCD_voidInit();
	//var
u8 value;
CLCD_voidSendString("THE SAFE SYSTEM");
CLCD_voidGoToXY(1,0);
CLCD_voidSendString("enter '*' to start");
	while(1)
	{
		if(c==0)
		{
		  do{
		   value = KPD_u8GetPressedKey();
		    	 }while (value == 0xff);
              if(value==10){
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
 					//hours_counter=(second_digit-48)+10*(first_digit-48);
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
       			c++;
              pass=(lastDigit)+1000*(thDigit)+100*(sDigit)+10*(firstDigit);
              CLCD_voidSendCommand(0x01);
	}
		}
		else if(c<4)
		{

			CLCD_voidSendString("press '*' to ");
            CLCD_voidGoToXY(1,0);
            CLCD_voidSendString("enter password");
            do{
           					   value = KPD_u8GetPressedKey();
           					    	 }while (value == 0xff);
           			              if(value==10){
			 do{
					   value = KPD_u8GetPressedKey();
			    	 }while (value == 0xff);

	     				CLCD_voidSendCommand(0x01);

	     				CLCD_voidSendString("password");
	     				CLCD_voidWriteNumber(c);
	     				CLCD_voidSendString("=----");
	     				CLCD_voidGoToXY(0,10);
	     				_delay_ms(500);
	     				do
	     				{
	     					firstDigit=KPD_u8GetPressedKey();

	     				} while (firstDigit==KPD_NO_PRESSED_KEY);
	     				CLCD_voidWriteNumber(firstDigit);
	     				_delay_ms(300);
	     				CLCD_voidGoToXY(0,10);
	     				CLCD_voidSendData('*');
	     				do
	 					{
	 						sDigit=KPD_u8GetPressedKey();

	 					} while (sDigit==KPD_NO_PRESSED_KEY);
	     				CLCD_voidGoToXY(0,11);
	 					CLCD_voidWriteNumber(sDigit);
	 					_delay_ms(300);
	 					CLCD_voidGoToXY(0,11);
	 					CLCD_voidSendData('*');

	 				do
	       			{
	       				thDigit=KPD_u8GetPressedKey();

	       			} while (thDigit==KPD_NO_PRESSED_KEY);
	 				CLCD_voidGoToXY(0,12);
	       			CLCD_voidWriteNumber(thDigit);
	       			_delay_ms(300);
	       			CLCD_voidGoToXY(0,12);
	       			CLCD_voidSendData('*');
	       			do
	       			{
	       				lastDigit=KPD_u8GetPressedKey();

	       			} while (lastDigit==KPD_NO_PRESSED_KEY);
	       			CLCD_voidGoToXY(0,13);
	       			CLCD_voidWriteNumber(lastDigit);
	       			_delay_ms(300);
	       			CLCD_voidGoToXY(0,13);
	       			CLCD_voidSendData('*');
	       			c++;
	             trypass=(lastDigit)+1000*(thDigit)+100*(sDigit)+10*(firstDigit);
	              CLCD_voidSendCommand(0x01);

	              		if(pass==trypass)
	              		{
	              			SERVO_voidSendAngle(500);

	              				DIO_u8SetPinValue(DIO_PORTD,DIO_PIN1,DIO_HIGH);
	              				DIO_u8SetPinValue(DIO_PORTD,DIO_PIN2,DIO_LOW);

	              				c=4;
	              				CLCD_voidSendCommand(0x01);
	              				CLCD_voidSendString("open ^_^");
	              			}
	              			else
	              			{

	              				//led
	              				DIO_u8SetPinValue(DIO_PORTD,DIO_PIN1,DIO_LOW);
	              				DIO_u8SetPinValue(DIO_PORTD,DIO_PIN2,DIO_HIGH);
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
 	              			   _delay_ms(500);

	              				}

	              		}
			              }
		}


		}
	}


