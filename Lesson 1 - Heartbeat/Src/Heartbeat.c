/*
 * Heartbeat.c
 *
 *  Created on: 14 лист. 2019 р.
 *      Author: Local user Profile
 */

#include "Heartbeat.h"
#include "drvLED.h"
#include "ulSysTime.h"

typedef enum
{
	STATE_LED_ON,
	STATE_WAIT_DUTYCYCLE,
	STATE_LED_OFF,
	STATE_WAIT_PAUSE
} heartbeatStates_t;

static heartbeatStates_t HeartbeatState = STATE_LED_ON;

static heartbeatStates_t StateChangeDelay(uint32_t StartTime, uint32_t delay,
										  heartbeatStates_t CurrentState, heartbeatStates_t NextState)
{

	heartbeatStates_t state = CurrentState;
	static uint8_t IsItTime = 0;
	IsItTime = ulSysTime_CheckIfTime(StartTime, delay);
	if (IsItTime)
	{
		state = NextState;
	}
	return state;
}

void Heartbeat(uint16_t pulsewidth, uint16_t period)
{
	heartbeatStates_t NextState = HeartbeatState;
	static uint32_t StartTime = 0;
	switch (HeartbeatState)
	{
	case STATE_LED_ON:
		drvLED_on(LED_Red);
		StartTime = ulSysTime_GetTime();
		NextState = STATE_WAIT_DUTYCYCLE;
		break;
	case STATE_WAIT_DUTYCYCLE:
		NextState = StateChangeDelay(StartTime, pulsewidth, STATE_WAIT_DUTYCYCLE, STATE_LED_OFF);
		break;
	case STATE_LED_OFF:
		drvLED_off(LED_Red);
		StartTime = ulSysTime_GetTime();
		NextState = STATE_WAIT_PAUSE;
		break;
	case STATE_WAIT_PAUSE:
		NextState = StateChangeDelay(StartTime, period - pulsewidth, STATE_WAIT_PAUSE, STATE_LED_ON);
		break;
	default:
		HeartbeatState = STATE_LED_ON;
	}
	HeartbeatState = NextState;
}
