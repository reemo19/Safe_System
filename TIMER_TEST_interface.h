#ifndef TIMER_TEST_INTERFACE_H_
#define TIMER_TEST_INTERFACE_H_

#define RIS    1
#define FALL   2



void TIMER0_voidOfInit(void);
void TIMER0_voidCtcInit(void);

void TIMER0_voidCtcValue(u8 Copy_u8Value);

void TIMER0_voidPreLoadValue(u8 Copy_u8Value);

void TIMER0_voidPWMFastInit(void);


void TIMER1_voidInit(void);

void TIMER1_voidNormalInit(void);

void TIMER1_voidSetTimerValue(u16 Copy_u16Value);
u16 Timer1_u16GetTimerValue(void);
void TIMER1_voidSetICR(u16 Copy_u16Value);


void TIMER1_voidCtcChannelA(u16 Copy_u16Value);


//void __vector_10(void) __attribute__((signal));
//void __vector_10(void) __attribute__((signal));


#endif /* TIMER_TEST_INTERFACE_H_ */
