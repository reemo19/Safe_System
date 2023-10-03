/*
 * I2C.h
 *
 *  Created on: Aug 24, 2023
 *      Author: hp
 */

#ifndef TWI_H_
#define TWI_H_

void TWI_voidMasterInit();
void TWI_SetMyAddress(u8 Copy_u8ADDress);
void TWI_Startcondition();
void TWI_stopcondition();
void TWI_senddata(u8 Copy_data);
u8 TWI_reseivedata();
#endif /* TWI_H_ */
