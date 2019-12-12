/*
 * drvLEDs_FourLightRun.c
 *
 *  Created on: 1 нояб. 2019 г.
 *      Author: AllSE
 */

//includes//

#include "stm32f4xx_hal.h"
#include "drvLEDs.h"
#include "drvLEDs_FourLightRun.h"
#include "ulSysTime.h"

//typedefs//

typedef enum{
  STATE_TURN_LED_ON,
  STATE_WAIT_DUTYCYCLE,
  STATE_TURN_LED_OFF,
  STATE_WAIT_PERIOD,
  STATE_NEXT_STEP
} FourLigtRun_t;

//massive of patterns//

uint16_t LEDPatternRun[] = {
  LED_Green,  LED_Orange, LED_Red,    LED_Orange,
  LED_Green,  LED_Red,    LED_Orange, LED_Green,
  LED_Orange, LED_Red
};

//size of pattern element//

int LEDPatternRunSize = sizeof(LEDPatternRun)/sizeof(uint16_t);

//variables//

static FourLigtRun_t currentState = STATE_TURN_LED_ON;
static uint32_t Step = 0;

//main program of drvLEDs_FourLigtRun//

void drvLEDs_FourLightRun(uint16_t PERIOD, uint16_t DUTY_CYCLE) {
  FourLigtRun_t nextState = currentState;
  uint8_t isItTime = 0;
  static uint32_t startTime = 0;


  switch(currentState){
  case STATE_TURN_LED_ON:
    drvLEDs_On(LEDPatternRun[Step]);
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
    drvLEDs_Off(LEDPatternRun[Step]);
    startTime = ulSysTime_getCurrentTime();
    nextState = STATE_WAIT_PERIOD;
   break;
  case STATE_WAIT_PERIOD:
    isItTime = ulSysTime_isItTime(startTime, PERIOD - DUTY_CYCLE);
    if (isItTime){
      nextState = STATE_NEXT_STEP;
    }
  break;
  case STATE_NEXT_STEP:
    if (Step < LEDPatternRunSize - 1){
      Step++;
    }else{
    Step = 0;
    }
    nextState = STATE_TURN_LED_ON;
  break;
  default:
    nextState = STATE_TURN_LED_ON;
  }
  currentState = nextState;
}
