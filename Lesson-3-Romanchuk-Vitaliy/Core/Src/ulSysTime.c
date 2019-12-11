/*
 * ulSysTime.c
 *
 *  Created on: 24 лист. 2019 р.
 *      Author: Romanchuk.Vitaliy
 */

#include "stdint.h"
#include "stdlib.h"
#include "stm32f4xx.h"
#include "ulSysTime.h"

uint32_t ulSysTime_getCurrentTime() {
	return HAL_GetTick();
}

uint8_t ulSysTime_isItTime(uint32_t startTime, uint32_t delay) {
  uint32_t currentTime = ulSysTime_getCurrentTime();
  uint8_t returnValue = 0;
  if (abs(currentTime - startTime) > delay) {
    returnValue = 1;
}
  return returnValue;
}


