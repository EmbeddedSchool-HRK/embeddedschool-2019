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

#include "ulStates.h"

#define SCENARIO_LEDS 5

static ledsList_t LED_array [SCENARIO_LEDS] =
{LED_ORANGE, LED_BLUE, LED_RED, LED_GREEN, LED_BLUE};

void ulRunningLeds(uint32_t dutycycle, uint32_t period) {
  heartbeatStates_t currentState = STATE_TURN_LED_ON;
  heartbeatStates_t nextState = currentState;
  static uint8_t isItTime = 0;
  static uint32_t startTime = 0;

  for(uint8_t step = 0; step < SCENARIO_LEDS;) {
    switch(currentState) {
    case STATE_TURN_LED_ON:
      ulStates_LED_ON(LED_array, startTime, &nextState, step);
      break;
    case STATE_WAIT_DUTYCYCLE:
      ulStates_WAIT_DUTYCYCLE(isItTime, startTime, dutycycle, &nextState);
      break;
    case STATE_TURN_LED_OFF:
      ulStates_LED_OFF(LED_array, startTime, &nextState, step);
      break;
    case STATE_WAIT_PERIOD:
      ulStates_WAIT_PERIOD(isItTime, startTime, dutycycle, period, &nextState);
      break;
    case STATE_SWITCH_LED:
      ulStates_SWITCH_LED(step);
      break;
    default:
      nextState = STATE_TURN_LED_ON;
    }

    currentState = nextState;
  }
}
