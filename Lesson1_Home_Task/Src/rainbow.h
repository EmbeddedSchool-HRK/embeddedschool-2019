/*
 * heartbeat.h
 *
 *  Created on: Nov 25, 2019
 *      Author: Slavon
 */

#include "drvLeds.h"
#include "stdint.h"
#include "stm32f4xx_hal.h"
#include "heartbeat.h"

#ifndef SRC_RAINBOW_H_
#define SRC_RAINBOW_H_


void rainbow(time_t pulse_delay, list_t led[], int leds_number);

#endif /* SRC_RAINBOW_H_ */
