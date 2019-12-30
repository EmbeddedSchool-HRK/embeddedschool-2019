/*
 * ulSysTime.h
 *
 *  Created on: Nov 29, 2019
 *      Author: vit
 */
#include "main.h"

#ifndef SRC_ULSYSTIME_H_
#define SRC_ULSYSTIME_H_

uint32_t ulSysTime_getCurrentTime();

uint8_t ulSysTime_isItTime(uint32_t startTime,uint32_t delay);


#endif /* SRC_ULSYSTIME_H_ */
