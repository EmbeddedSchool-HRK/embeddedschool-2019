/*
 * ulSysTime.c
 *
 *  Created on: 17 нояб. 2019 г.
 *      Author: AllSE
 */

#include "ulSysTime.h"
#include "stm32f4xx_hal.h"

uint32_t ulSysTime_getCurrentTime(){
  return HAL_GetTick();
}

uint8_t ulSysTime_isItTime(uint32_t startTime, uint32_t delay){
  uint32_t currentTime = ulSysTime_getCurrentTime();
  uint8_t returnValue = 0;
  if ((startTime < currentTime && currentTime - startTime >= delay) || (startTime > currentTime && currentTime + startTime >= delay)){
	returnValue = 1;
  }
	return returnValue;
}
