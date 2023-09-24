
#include "STD_TYPES.h"
#include"BIT_MATH.h"
#include "DIO_INTERFACE.h"
#include <avr/io.h>

u8 DIO_u8SetPortValue(u8 Copy_u8Port,u8 Copy_u8Value)
{
   u8 Local_u8ErrorState=0;
   if((Copy_u8Port>DIO_PORTD)||(Copy_u8Port<DIO_PORTA))
   {
	   Local_u8ErrorState=1;
	  return Local_u8ErrorState;
   }
   else
   {
	   switch(Copy_u8Port)
	   {
	   case DIO_PORTA:PORTA=Copy_u8Value;break;
	   case DIO_PORTB:PORTB=Copy_u8Value;break;
	   case DIO_PORTC:PORTC=Copy_u8Value;break;
	   case DIO_PORTD:PORTD=Copy_u8Value;break;
	   default:;
        }
   }
return Local_u8ErrorState;
}
u8 DIO_u8SetPinValue(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8Value){

 u8 Local_u8ErrorState=0;

 if((Copy_u8Port>DIO_PORTD)||(Copy_u8Port<DIO_PORTA))
    {
 	   Local_u8ErrorState=1;
 	  return Local_u8ErrorState;
    }
 else if ((Copy_u8Pin>DIO_PIN7)||(Copy_u8Pin<DIO_PIN0))
 {
	   Local_u8ErrorState=1;
       return Local_u8ErrorState;
 }
 else
 {
	 if(Copy_u8Value==DIO_HIGH)
	 {

		 switch(Copy_u8Port)
		 {
		 case DIO_PORTA:SET_BIT(PORTA,Copy_u8Pin);break;
		 case DIO_PORTB:SET_BIT(PORTB,Copy_u8Pin);break;
		 case DIO_PORTC:SET_BIT(PORTC,Copy_u8Pin);break;
		 case DIO_PORTD:SET_BIT(PORTD,Copy_u8Pin);break;
         default:;
		 }
	 }
	 else if(Copy_u8Value==DIO_LOW)
	 {
		 switch(Copy_u8Port)
		 		 {
		 case DIO_PORTA:CLEAR_BIT(PORTA,Copy_u8Pin);break;
		 case DIO_PORTB:CLEAR_BIT(PORTB,Copy_u8Pin);break;
		 case DIO_PORTC:CLEAR_BIT(PORTC,Copy_u8Pin);break;
		 case DIO_PORTD:CLEAR_BIT(PORTD,Copy_u8Pin);break;
		 default:;
		 		 }
	 }
 }
 return Local_u8ErrorState;
}

u8 DIO_u8SetPortDir(u8 Copy_u8Port,u8 Copy_u8Direction)
{
	u8 Local_u8ErrorState=0;
if((Copy_u8Port>DIO_PORTD)||(Copy_u8Port<DIO_PORTA))
{
	   Local_u8ErrorState=1;
	  return Local_u8ErrorState;
}
else
{

     switch(Copy_u8Port)
     {
     case DIO_PORTA:DDRA=Copy_u8Direction;break;
     case DIO_PORTB:DDRB=Copy_u8Direction;break;
     case DIO_PORTC:DDRC=Copy_u8Direction;break;
     case DIO_PORTD:DDRD=Copy_u8Direction;break;
     default:;
     }
  }

return Local_u8ErrorState;
}
u8 DIO_u8SetPinDir(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8Direction)
{
	u8 Local_u8ErrorState=0;

	 if((Copy_u8Port>DIO_PORTD)||(Copy_u8Port<DIO_PORTA))
	    {
	 	   Local_u8ErrorState=1;
	 	  return Local_u8ErrorState;
	    }
	 else if ((Copy_u8Pin>DIO_PIN7)||(Copy_u8Pin<DIO_PIN0))
	 {
		   Local_u8ErrorState=1;
	       return Local_u8ErrorState;
	 }
	 else
	 {
		 if(Copy_u8Direction==DIO_PIN_OUT)
		 {
			switch(Copy_u8Port)
			{case DIO_PORTA:SET_BIT(DDRA,Copy_u8Pin);break;
			case DIO_PORTB:SET_BIT(DDRB,Copy_u8Pin);break;
			case DIO_PORTC:SET_BIT(DDRC,Copy_u8Pin);break;
			case DIO_PORTD:SET_BIT(DDRD,Copy_u8Pin);break;
			}
		 }
		 else if(Copy_u8Direction==DIO_PIN_IN)
		 {
			 switch(Copy_u8Port)
			{
		    case DIO_PORTA:CLEAR_BIT(DDRA,Copy_u8Pin);break;
			case DIO_PORTB:CLEAR_BIT(DDRB,Copy_u8Pin);break;
			case DIO_PORTC:CLEAR_BIT(DDRC,Copy_u8Pin);break;
			case DIO_PORTD:CLEAR_BIT(DDRD,Copy_u8Pin);break;
			}

		 }

	 }
return Local_u8ErrorState;
}

u8 DIO_u8GetPortValue(u8 Copy_u8Port,u8 *Copy_u8Value)
{
	u8 Local_u8ErrorState=0;
	if((Copy_u8Port>DIO_PORTD)||(Copy_u8Port<DIO_PORTA))
	{
		   Local_u8ErrorState=1;
		  return Local_u8ErrorState;
	}
	else
	{
		switch(Copy_u8Port)
		{
		case DIO_PORTA:*Copy_u8Value=PINA;break;
		case DIO_PORTB:*Copy_u8Value=PINB;break;
		case DIO_PORTC:*Copy_u8Value=PINC;break;
		case DIO_PORTD:*Copy_u8Value=PIND;break;
default:;

		}
	}
return Local_u8ErrorState;

}
u8 DIO_u8GetPinValue(u8 Copy_u8Port,u8 Copy_u8Pin,u8 *Copy_u8Value)
{
	u8 Local_u8ErrorState=0;

		 if((Copy_u8Port>DIO_PORTD)||(Copy_u8Port<DIO_PORTA))
		    {
		 	   Local_u8ErrorState=1;
		 	  return Local_u8ErrorState;
		    }
		 else if ((Copy_u8Pin>DIO_PIN7)||(Copy_u8Pin<DIO_PIN0))
		 {
			   Local_u8ErrorState=1;
		       return Local_u8ErrorState;
		 }
		 else
		 {
			switch(Copy_u8Port)
			{
			case DIO_PORTA:*Copy_u8Value=GET_BIT(PINA,Copy_u8Pin);break;
			case DIO_PORTB:*Copy_u8Value=GET_BIT(PINB,Copy_u8Pin);break;
			case DIO_PORTC:*Copy_u8Value=GET_BIT(PINC,Copy_u8Pin);break;
			case DIO_PORTD:*Copy_u8Value=GET_BIT(PIND,Copy_u8Pin);break;
			}
		 }
return Local_u8ErrorState;
}


