/*
 *
 *
 *	CrossBlink.c
 *	
 *	Autor: Romanchuk.Vitaliy
 *	
 *
 *
 */

#include "main.h"
#include "stdint.h"
#include "drv_LEDs.h"
#include "CrossBlink.h"
#include "ulSysTime.h"

uint16_t ArLEDs[] = {
 LED_Blue,  LED_Green, LED_Red,
 LED_Red,   LED_Blue,  LED_Green,
 LED_Green, LED_Red,   LED_Blue
};

int ArLEDsSize = sizeof(ArLEDs) / sizeof(uint16_t);

typedef enum {
  State_Turn_LED_On,
  State_Wait_Dutycycle,
  State_Turn_LED_Off,
  State_Wait_Period,
  State_Next_Step
}CrossBlink_t;

static CrossBlink_t CurrentState = State_Turn_LED_On;
static uint32_t Step = 0;

void lcb_func(uint32_t period, uint32_t dutycycle) {

  CrossBlink_t NextState = CurrentState;
  uint8_t IsItTime = 0;
  static uint32_t StartTime = 0;

  switch (CurrentState) {
  case State_Turn_LED_On:
	drvLeds_on(ArLEDs[Step]);
	StartTime = ulSysTime_getCurrentTime();
	NextState = State_Wait_Dutycycle;
	break;
  case State_Wait_Dutycycle:
	IsItTime = ulSysTime_isItTime(StartTime, dutycycle);
	if (IsItTime) {
	  NextState = State_Turn_LED_Off;
  }
    break;
  case State_Turn_LED_Off:
	drvLeds_off(ArLEDs[Step]);
	StartTime = ulSysTime_getCurrentTime();
	NextState = State_Wait_Period;
    break;
  case State_Wait_Period:
	IsItTime = ulSysTime_isItTime(StartTime, period - dutycycle);
	if (IsItTime) {
		NextState = State_Next_Step;
  }
    break;
  case State_Next_Step:
	if (Step < ArLEDsSize) {
	Step++;
}
	else {
	Step = 0;
}
NextState = State_Turn_LED_On;
  break;
  default:
	NextState = State_Turn_LED_On;
}
  CurrentState = NextState;
}
