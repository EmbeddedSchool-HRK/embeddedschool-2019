/*
 * ulSysTime.h
 *
 *  Created on: 17 нояб. 2019 г.
 *      Author: AllSE
 */

#ifndef SRC_ULSYSTIME_H_
#define SRC_ULSYSTIME_H_

#include "stdint.h"

uint32_t ulSysTime_getCurrentTime();
uint8_t ulSysTime_isItTime(uint32_t startTime, uint32_t delay);

#endif /* SRC_ULSYSTIME_H_ */
