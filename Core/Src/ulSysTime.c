/*
 * ulSysTime.c
 *
 *  Created on: 16 нояб. 2019 г.
 *      Author: S1ckret
 */

#include <stdlib.h>
#include "stm32f4xx_hal.h"

#include "ulSysTime.h"

uint32_t ulSysTime_GetCurrentTime()
{
	return HAL_GetTick();
}

uint8_t ulSysTime_IsItTime(uint32_t startTime, uint32_t delay)
{
	uint8_t result = 0;
	uint32_t currentTime = ulSysTime_GetCurrentTime();
	uint32_t elapsedTime = abs((int32_t)currentTime - (int32_t)startTime);

	if (elapsedTime > delay)
	{
		result = 1;
	}

	return result;
}
