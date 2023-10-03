/*
 * I2C.h
 *
 *  Created on: Aug 24, 2023
 *      Author: hp
 */

#ifndef EEPROM_H_
#define EEPROM_H_

void EEPROM_write(u16 Copy_u16Address,u8 Copy_Data);
u8 EEPROM_read(u16 Copy_u16Address);
#endif /* EEPROM_H_ */
