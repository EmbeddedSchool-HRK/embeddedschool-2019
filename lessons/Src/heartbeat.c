/*
 * heartbeat.c
 *
 *  Created on: 6 нояб. 2019 г.
 *      Author: Win10Pro
 */

#include "main.h"
#include "heartbeat.h"
#include "drvLeds.h"

ledsList_t LED_array = {LED_BLUE};
// здесь вводить последовательность светодиодов

typedef enum{
  STATE_TURN_LED_ON,
  STATE_WAIT_DUTYCYCLE,
  STATE_TURN_LED_OFF,
  STATE_WAIT_PERIOD
}heartbeatStates_t;

static heartbeatStates_t currentState = STATE_TURN_LED_ON;

void Heartbeat_run(uint16_t dutyCycle, uint16_t period)
{
  heartbeatStates_t nextState = currentState;
  uint8_t isItTime = 0;
  static uint32_t startTime = 0;

  switch(currentState) {
  case STATE_TURN_LED_ON:
    drvLeds_on(LED_array);
    startTime = ulSysTime_getCurrentTime();
    nextState = STATE_WAIT_DUTYCYCLE;
    break;
  case STATE_WAIT_DUTYCYCLE:
    isItTime = ulSysTime_isItTime(startTime, dutyCycle);
    if (isItTime) {
      nextState = STATE_TURN_LED_OFF;
    }
    break;
  case STATE_TURN_LED_OFF:
    drvLeds_off(LED_array);
    startTime = ulSysTime_getCurrentTime();
    nextState = STATE_WAIT_PERIOD;
    break;
  case STATE_WAIT_PERIOD:
    isItTime = ulSysTime_isItTime(startTime, period - dutyCycle);
    if (isItTime) {
      nextState = STATE_TURN_LED_ON;
    }
    break;
  default:
    nextState = STATE_TURN_LED_ON;
  }

  currentState = nextState;
/*
  for (uint16_t ledName = 0; ledName < LED_AMOUNT - 1 ; ledName++) {
  drvLeds_on(LED_array[ledName]);
  HAL_Delay(dutyCycle);
  drvLeds_off(LED_array[ledName]);
  HAL_Delay(period - dutyCycle);
  }
*/
}
