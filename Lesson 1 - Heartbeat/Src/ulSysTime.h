/*
 * ulSysTime.h
 *
 *  Created on: 1 лют. 2020 р.
 *      Author: Local user Profile
 */

#ifndef ULSYSTIME_H_
#define ULSYSTIME_H_

#include "stm32f4xx_hal.h"

uint32_t ulSysTime_GetTime();

uint8_t ulSysTime_CheckIfTime(uint32_t TimeStart, uint32_t TimeDelay);

#endif /* ULSYSTIME_H_ */
