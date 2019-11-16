/*
 * heartbeat.h
 *
 *  Created on: 5 нояб. 2019 г.
 *      Author: S1ckret
 */

#ifndef INC_HEARTBEAT_H_
#define INC_HEARTBEAT_H_

#include "stdint.h"

#include "drvLeds.h"

void Heartbeat(led_color_t led_color, uint32_t period, uint32_t dutycycle);

#endif /* INC_HEARTBEAT_H_ */
