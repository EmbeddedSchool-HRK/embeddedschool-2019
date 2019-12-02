/*
 * heartbeat.h
 *
 *  Created on: Nov 25, 2019
 *      Author: Slavon
 */

#include "drvLeds.h"
#include "stdint.h"
#include "stm32f4xx_hal.h"

#ifndef SRC_HEARTBEAT_H_
#define SRC_HEARTBEAT_H_

typedef uint16_t time_t;

void heartbeat(time_t Duty_Cycle, time_t period);

#endif /* SRC_HEARTBEAT_H_ */
