/*
 * ulSysTime.h
 *
 *  Created on: 16 нояб. 2019 г.
 *      Author: S1ckret
 */

#ifndef INC_ULSYSTIME_H_
#define INC_ULSYSTIME_H_

#include "stdint.h"

uint32_t ulSysTime_GetCurrentTime();

uint8_t ulSysTime_IsItTime(uint32_t startTime, uint32_t delay);

#endif /* INC_ULSYSTIME_H_ */
