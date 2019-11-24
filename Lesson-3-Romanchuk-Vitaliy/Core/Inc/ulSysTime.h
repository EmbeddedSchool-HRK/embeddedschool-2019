/*
 * ulSysTime.h
 *
 *  Created on: 24 лист. 2019 р.
 *      Author: Romanchuk.Vitaliy
 */

#ifndef INC_ULSYSTIME_H_
#define INC_ULSYSTIME_H_

uint32_t ulSysTime_getCurrentTime();

uint8_t ulSysTime_isItTime(uint32_t startTime, uint32_t delay);

#endif /* INC_ULSYSTIME_H_ */
