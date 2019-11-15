/*
 * ulsystime.h
 *
 *  Created on: 15 нояб. 2019 г.
 *      Author: Herr Satan
 */
#include "stdint.h"
#ifndef ULSYSTIME_H_
#define ULSYSTIME_H_

uint32_t ulsystime_Get_Time();

uint8_t ulsystime_Its_Time(uint32_t start_time, uint32_t delay);

#endif /* ULSYSTIME_H_ */
