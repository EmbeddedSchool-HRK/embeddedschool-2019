/*
 * ulStatesFunctions.h
 *
 *  Created on: 21 нояб. 2019 г.
 *      Author: Win10Pro
 */

#ifndef ULSTATES_H_
#define ULSTATES_H_

#include "drvLeds.h"
#include "stdint.h"

typedef enum{
  STATE_TURN_LED_ON,
  STATE_WAIT_DUTYCYCLE,
  STATE_TURN_LED_OFF,
  STATE_WAIT_PERIOD,
  STATE_SWITCH_LED
}heartbeatStates_t;

void ulStates_LED_ON(ledsList_t LED_array[], heartbeatStates_t startTime, heartbeatStates_t *ptr_nextState, uint8_t step);

void ulStates_WAIT_DUTYCYCLE(uint8_t isItTime, heartbeatStates_t startTime, uint32_t dutycycle, heartbeatStates_t *ptr_nextState);

void ulStates_LED_OFF(ledsList_t LED_array[], heartbeatStates_t startTime, heartbeatStates_t *ptr_nextState, uint8_t step);

void ulStates_WAIT_PERIOD(uint8_t isItTime, heartbeatStates_t startTime, uint32_t dutycycle, uint32_t period, heartbeatStates_t *ptr_nextState);

uint8_t ulStates_SWITCH_LED(uint8_t step);

#endif /* ULSTATES_H_ */
