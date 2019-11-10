/*
 * Heartbeat_Red_LED.h
 *
 *  Created on: 10 нояб. 2019 г.
 *      Author: morok__
 */

#ifndef HEARTBEAT_RED_LED_H_
#define HEARTBEAT_RED_LED_H_

#include <stdint.h>
#include "main.h"

void HeartBeat_led_Red(uint16_t DELAY);
void HeartBeat_led_Other(uint16_t period, uint16_t dutycycle);

#endif /* HEARTBEAT_RED_LED_H_ */
