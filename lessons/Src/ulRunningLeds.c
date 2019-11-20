/*
 * ulRunningLeds.c
 *
 *  Created on: 21 нояб. 2019 г.
 *      Author: Win10Pro
 */

#include "main.h"
#include "stm32f4xx.h"
#include "drvLeds.h"
#include "ulSysTime.h"
#include "ulRunningLeds.h"

#define SCENARIO_LEDS 5

ledsList_t LED_array [SCENARIO_LEDS] =
{LED_ORANGE, LED_BLUE, LED_RED, LED_GREEN, LED_BLUE};
typedef enum{
  STATE_TURN_LED_ON,
  STATE_WAIT_DUTYCYCLE,
  STATE_TURN_LED_OFF,
  STATE_WAIT_PERIOD,
  STATE_SWITCH_LED
}heartbeatStates_t;

static heartbeatStates_t currentState = STATE_TURN_LED_ON;

void ulRunningLeds(uint32_t dutycycle, uint32_t period) {
  heartbeatStates_t nextState = currentState;
  uint8_t isItTime = 0;
  static uint32_t startTime = 0;

  for(uint8_t step = 0; step < SCENARIO_LEDS;) {
    switch(currentState) {
    case STATE_TURN_LED_ON:
      drvLeds_on(LED_array[step]);
      startTime = ulSysTime_getCurrentTime();
      nextState = STATE_WAIT_DUTYCYCLE;
      break;
    case STATE_WAIT_DUTYCYCLE:
      isItTime = ulSysTime_isItTime(startTime, dutycycle);
      if (isItTime) {
        nextState = STATE_TURN_LED_OFF;
      }
      break;
    case STATE_TURN_LED_OFF:
      drvLeds_off(LED_array[step]);
      startTime = ulSysTime_getCurrentTime();
      nextState = STATE_WAIT_PERIOD;
      break;
    case STATE_WAIT_PERIOD:
      isItTime = ulSysTime_isItTime(startTime, period - dutycycle);
      if (isItTime) {
        nextState = STATE_SWITCH_LED;
      }
      break;
    case STATE_SWITCH_LED:
      step++;
      break;
    default:
      nextState = STATE_TURN_LED_ON;
    }
    currentState = nextState;
  }
}
