/*
 * hearbeat_module.h
 *
 *  Created on: 19 нояб. 2019 г.
 *      Author: vit
 */

#ifndef SRC_HEARTBEAT_MODULE_H_
#define SRC_HEARTBEAT_MODULE_H_
#include "drv_led.h"

void heartbeat_moving(int duty_cycle, int period);
void all_leds_blinking(int dual_duty_cycle, int period);

#endif /* SRC_HEARTBEAT_MODULE_H_ */
