/*
 *
 *
 * HeartBeat.c
 * 
 * Autor: Romanchuk.Vitaliy
 *
 *
 */
#include "main.h"
#include "stdint.h"
#include "drv_LEDs.h"
#include "ulSysTime.h"
#include "HeartBeat.h"

const ledslist_t LED_HeartBeat = LED_Orange;

typedef enum {
  State_Turn_LED_On,
  State_Wait_Dutycycle,
  State_Turn_LED_Off,
  State_Wait_Period
}HeartBeatStates_t;

static HeartBeatStates_t CurrentState = State_Turn_LED_On;

void hb_ol(uint32_t period, uint32_t dutycycle) {

  HeartBeatStates_t NextState = CurrentState;
  uint8_t IsItTime = 0;
  static uint32_t StartTime = 0;

  switch (CurrentState) {
  case State_Turn_LED_On:
	drvLeds_on(LED_HeartBeat);
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
	drvLeds_off(LED_HeartBeat);
	StartTime = ulSysTime_getCurrentTime();
	NextState = State_Wait_Period;
    break;
  case State_Wait_Period:
	IsItTime = ulSysTime_isItTime(StartTime, period - dutycycle);
	if (IsItTime) {
		NextState = State_Turn_LED_On;
  }
    break;
  default:
	NextState = State_Turn_LED_On;
}
  CurrentState = NextState;
}
