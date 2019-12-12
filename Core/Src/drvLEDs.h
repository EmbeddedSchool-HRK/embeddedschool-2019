/*
 * drvLEDs.h
 *
 *  Created on: 1 нояб. 2019 г.
 *      Author: AllSE
 */

#include "stm32f4xx_hal.h"

#ifndef SRC_DRVLEDS_H_
#define SRC_DRVLEDS_H_

typedef enum {
  LED_Green,
  LED_Orange,
  LED_Red,
  LED_Blue,
  LED_AMOUNT
} LedList_t;

typedef struct{
  GPIO_TypeDef* Port;
  uint16_t Pin;
} Led_t;

void drvLEDs_On(LedList_t Led_Name);
void drvLEDs_Off(LedList_t Led_Name);

#endif /* SRC_DRVLEDS_H_ */
