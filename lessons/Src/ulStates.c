/*
 * ulStatesFunctions.c
 *
 *  Created on: 21 нояб. 2019 г.
 *      Author: Win10Pro
 */

#include "ulStates.h"

void ulStates_LED_ON(ledsList_t LED_array[], heartbeatStates_t startTime, heartbeatStates_t *ptr_nextState, uint8_t step) {
  drvLeds_on(LED_array[step]);
  startTime = ulSysTime_getCurrentTime();
  *ptr_nextState = STATE_WAIT_DUTYCYCLE;
}

void ulStates_WAIT_DUTYCYCLE(uint8_t isItTime, heartbeatStates_t startTime, uint32_t dutycycle, heartbeatStates_t *ptr_nextState) {
  isItTime = ulSysTime_isItTime(startTime, dutycycle);
  if (isItTime) {
    *ptr_nextState = STATE_TURN_LED_OFF;
  }
}

void ulStates_LED_OFF(ledsList_t LED_array[], heartbeatStates_t startTime, heartbeatStates_t *ptr_nextState, uint8_t step) {
  drvLeds_off(LED_array[step]);
  startTime = ulSysTime_getCurrentTime();
  *ptr_nextState = STATE_WAIT_PERIOD;
}

void ulStates_WAIT_PERIOD(uint8_t isItTime, heartbeatStates_t startTime, uint32_t dutycycle, uint32_t period, heartbeatStates_t *ptr_nextState) {
  isItTime = ulSysTime_isItTime(startTime, period - dutycycle);
  if (isItTime) {
    *ptr_nextState = STATE_SWITCH_LED;
  }

}

uint8_t ulStates_SWITCH_LED(uint8_t step) {
 step++;
 return step;
}
