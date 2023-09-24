
#ifndef KPD_INTERFACE_H_
#define KPD_INTERFACE_H_
/*********************************************************/
#define KPD_ARR   {{1,2,3},{4,5,6},{7,8,9},{10,0,11}}

#define KPD_NO_PRESSED_KEY 0xff

/******************************************************************************/
/*************************  USER CONFIGURATION ********************************/
#define KPD_PORT              DIO_PORTC

#define KPD_COLUMN0_PIN       DIO_PIN0
#define KPD_COLUMN1_PIN       DIO_PIN1
#define KPD_COLUMN2_PIN       DIO_PIN2
//#define KPD_COLUMN3_PIN       DIO_PIN3

#define KPD_ROW0_PIN          DIO_PIN3
#define KPD_ROW1_PIN          DIO_PIN4
#define KPD_ROW2_PIN          DIO_PIN5
#define KPD_ROW3_PIN          DIO_PIN6
/******************************************************************************/
#define COLUMN_NUMBER     3
#define ROW_NUMBER        4
/******************************************************************************/
u8 KPD_u8GetPressedKey(void);



#endif /* KPD_INTERFACE_H_ */
