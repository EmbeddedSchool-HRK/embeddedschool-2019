/*
 * drvLcd.h
 *
 *  Created on: 18 нояб. 2019 г.
 *      Author: S1ckret
 */

#ifndef INC_DRVLCD_H_
#define INC_DRVLCD_H_

#include <stdint.h>

void drvLcd_Init();
void drvLcd_Pulse();
void drvLcd_SendChar(uint8_t byte);
void drvLcd_SendString(uint8_t* str);
void drvLcd_SetCursor(uint8_t line, uint8_t column);

#endif /* INC_DRVLCD_H_ */
