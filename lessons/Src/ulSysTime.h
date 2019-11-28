/*
 * ulSysTime.h
 *
 *  Created on: 21 нояб. 2019 г.
 *      Author: Win10Pro
 */

#ifndef ULSYSTIME_H_
#define ULSYSTIME_H_

#include "stdint.h"

uint32_t ulSysTime_getCurrentTime();

uint8_t ulSysTime_isItTime(uint32_t startTime, uint32_t delay);

#endif /* ULSYSTIME_H_ */
