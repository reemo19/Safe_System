
#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

 #define DIO_PIN0   0
 #define DIO_PIN1   1
 #define DIO_PIN2   2
 #define DIO_PIN3   3
 #define DIO_PIN4   4
 #define DIO_PIN5   5
 #define DIO_PIN6   6
 #define DIO_PIN7   7

#define DIO_PORTA   0
#define DIO_PORTB   1
#define DIO_PORTC   2
#define DIO_PORTD   3


#define DIO_PORT_OUT 0xff
#define DIO_PORT_IN  0


#define DIO_PIN_OUT 1
#define DIO_PIN_IN  0

#define DIO_HIGH   1
#define DIO_LOW    0

u8 DIO_u8SetPortValue(u8 Copy_u8Port,u8 Copy_u8Value);
u8 DIO_u8SetPinValue(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8Value);

u8 DIO_u8SetPortDir(u8 Copy_u8Port,u8 Copy_u8Direction);
u8 DIO_u8SetPinDir(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8Direction);

u8 DIO_u8GetPortValue(u8 Copy_u8Port,u8 *Copy_u8Value);
u8 DIO_u8GetPinValue(u8 Copy_u8Port,u8 Copy_u8Pin,u8 *Copy_u8Value);




#endif /* DIO_INTERFACE_H_ */
