#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "TIMER_TEST_interface.h"
#include "DIO_INTERFACE.h"
#include <avr/io.h>
#include <avr/interrupt.h>

void TIMER0_voidOfInit(void)
{


/*NORMAL MODE WAVEFORM*/
	CLEAR_BIT(TCCR0,WGM01);
	CLEAR_BIT(TCCR0,WGM00);

	/*PRESCALLER BY 8*/
	TCNT0=0;
	CLEAR_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS01);
	CLEAR_BIT(TCCR0,CS02);

	/*ENABLE THE INTERRUPT*/
	SET_BIT(TIMSK,TOIE0);


}
void TIMER0_voidCtcInit(void)
{

	/*NORMAL MODE WAVEFORM*/
		SET_BIT(TCCR0,WGM01);
		CLEAR_BIT(TCCR0,WGM00);

	/*PRESCALLER BY 64*/

		SET_BIT(TCCR0,CS00);
		SET_BIT(TCCR0,CS01);
		CLEAR_BIT(TCCR0,CS02);

		/*ENABLE THE INTERRUPT*/

		SET_BIT(TIMSK,OCIE0);
}


void TIMER0_voidPWMFastInit(void)
{
/*fast pwm*/
	SET_BIT(TCCR0,WGM01);
	SET_BIT(TCCR0,WGM00);

/*NON-INVERTED MODE*/

SET_BIT(TCCR0,COM01);
CLEAR_BIT(TCCR0,COM00);

/*PRESCALLER BY 8*/
CLEAR_BIT(TCCR0,CS00);
SET_BIT(TCCR0,CS01);
CLEAR_BIT(TCCR0,CS02);
}
void TIMER1_voidNormalInit(void)
{/*Normal mode*/
	/*PRESCALLER BY 8*/
	CLEAR_BIT(TCCR1B,CS10);
	SET_BIT(TCCR1B,CS11);
	CLEAR_BIT(TCCR1B,CS12);

}




void TIMER1_voidSetTimerValue(u16 Copy_u16Value)
{
TCNT1=Copy_u16Value;
}

u16 Timer1_u16GetTimerValue(void)
{
return TCNT1;
}




void TIMER1_voidInit(void)
{

/*non inverted*/
SET_BIT(TCCR1A,COM1A1);
CLEAR_BIT(TCCR1A,COM1A0);

/*PWM WITH ICR1*/
SET_BIT(TCCR1A,WGM11);
SET_BIT(TCCR1B,WGM12);
SET_BIT(TCCR1B,WGM13);
CLEAR_BIT(TCCR1A,WGM10);
/*PRESCALLER BY 8*/
CLEAR_BIT(TCCR1B,CS10);
SET_BIT(TCCR1B,CS11);
CLEAR_BIT(TCCR1B,CS12);
}
void TIMER1_voidSetICR(u16 Copy_u16Value)
{
ICR1=Copy_u16Value;
}


void TIMER1_voidCtcChannelA(u16 Copy_u16Value)
{
OCR1A=Copy_u16Value;
}


void TIMER0_voidCtcValue(u8 Copy_u8Value)
{
OCR0=Copy_u8Value;
}
void TIMER0_voidPreLoadValue(u8 Copy_u8Value)
{
TCNT0=Copy_u8Value;
}





/*CTC*/
//void __vector_10(void)
//{
//
//	u8 static Local_u8Counter=0;
//	Local_u8Counter++;
//
//	if(Local_u8Counter==15)
//	{
//
//		DIO_u8SetPinValue(DIO_PORTA,DIO_PIN0,DIO_LOW);
//	}
//	else if (Local_u8Counter==20)
//	{
//		DIO_u8SetPinValue(DIO_PORTA,DIO_PIN0,DIO_HIGH);
//		Local_u8Counter=0;
//	}
//}
/////*OF*/
//void __vector_11(void)
//{
//
//
//}
