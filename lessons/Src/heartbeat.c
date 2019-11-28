/*
 * heartbeat.c
 *
 *  Created on: 6 нояб. 2019 г.
 *      Author: Win10Pro
 */

#include "main.h"
#include "heartbeat.h"
// #include "drvLeds.h"
#include "ulStates.h"

static ledsList_t LED_array[] = {LED_BLUE};

static heartbeatStates_t currentState = STATE_TURN_LED_ON;

void Heartbeat_run(uint16_t dutyCycle, uint16_t period)
{
  heartbeatStates_t nextState = currentState;
  uint8_t isItTime = 0;
  static uint32_t startTime = 0;

  switch(currentState) {
  case STATE_TURN_LED_ON:
    ulStates_LED_ON( LED_array, startTime, &nextState, 0);
    break;
  case STATE_WAIT_DUTYCYCLE:
    ulStates_WAIT_DUTYCYCLE(isItTime, startTime, dutyCycle, &nextState);
    break;
  case STATE_TURN_LED_OFF:
    ulStates_LED_OFF( LED_array, startTime, &nextState, 0);
    break;
  case STATE_WAIT_PERIOD:
    ulStates_WAIT_PERIOD(isItTime, startTime, dutyCycle, period, &nextState);
    break;
  default:
    nextState = STATE_TURN_LED_ON;
  }

  currentState = nextState;
}
