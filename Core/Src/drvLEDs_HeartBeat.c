/*
 * drvLEDs_HeartBeat.c
 *
 *  Created on: 1 нояб. 2019 г.
 *      Author: AllSE
 */

//includes//

#include "stm32f4xx_hal.h"
#include "drvLEDs.h"
#include "drvLEDs_HeartBeat.h"
#include "ulSysTime.h"

//constants//

const LedList_t LED_HeartBeat = LED_Blue;

//typedefs//

typedef enum{
  STATE_TURN_LED_ON,
  STATE_WAIT_DUTYCYCLE,
  STATE_TURN_LED_OFF,
  STATE_WAIT_PERIOD
} HertBeatStates_t;

//variables//

static HertBeatStates_t currentState = STATE_TURN_LED_ON;

//main program of drvLEDs_HeartBeat//

void drvLEDs_HeartBeat(uint16_t PERIOD, uint16_t DUTY_CYCLE) {
  HertBeatStates_t nextState = currentState;
  uint8_t isItTime = 0;
  static uint32_t startTime = 0;

  switch(currentState){
  case STATE_TURN_LED_ON:
    drvLEDs_On(LED_HeartBeat);
    startTime = ulSysTime_getCurrentTime();
    nextState = STATE_WAIT_DUTYCYCLE;
    break;
  case STATE_WAIT_DUTYCYCLE:
    isItTime = ulSysTime_isItTime(startTime, DUTY_CYCLE);
    if (isItTime){
      nextState = STATE_TURN_LED_OFF;
    }
    break;
  case STATE_TURN_LED_OFF:
    drvLEDs_Off(LED_HeartBeat);
    startTime = ulSysTime_getCurrentTime();
    nextState = STATE_WAIT_PERIOD;
   break;
  case STATE_WAIT_PERIOD:
    isItTime = ulSysTime_isItTime(startTime, PERIOD - DUTY_CYCLE);
    if (isItTime){
      nextState = STATE_TURN_LED_ON;
    }
  break;
  default:
    nextState = STATE_TURN_LED_ON;
  }
  currentState = nextState;
}
