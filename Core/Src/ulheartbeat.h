/*
 * ulheartbeat.h
 *
 *  Created on: 15 нояб. 2019 г.
 *      Author: Herr Satan
 */

#ifndef ULHEARTBEAT_H_
#define ULHEARTBEAT_H_

#include "driver_LEDs.h"
#include "ulsystime.h"
#include "stdint.h"

typedef enum {
  STATE_ON,
  STATE_DUTY_CYCLE,
  STATE_OFF,
  STATE_PERIOD,
  STATE_LED_Increment
}heartbeat_t;

void ulHeartbeat (ledlist_t color, int period, int duty_cycle);

#endif /* ULHEARTBEAT_H_ */
