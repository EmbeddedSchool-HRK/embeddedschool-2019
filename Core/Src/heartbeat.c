/*
 * heartbeat.c
 *
 *  Created on: 5 нояб. 2019 г.
 *      Author: S1ckret
 */

#include "stm32f4xx_hal.h"

#include "heartbeat.h"
#include "ulSysTime.h"

typedef enum
{
	STATE_TURN_LED_ON,
	STATE_DUTYCYCLE,
	STATE_TURN_LED_OFF,
	STATE_PERIOD
} heartbeatState_t;

static heartbeatState_t StateTurnLedOn(uint32_t* startTime, const led_color_t led_color);

static heartbeatState_t StateDutycycle(const heartbeatState_t currentState, uint32_t startTime, uint32_t nextTime);

static heartbeatState_t StateTurnLedOff(uint32_t* startTime, const led_color_t led_color);

static heartbeatState_t StatePeriod(const heartbeatState_t currentState, uint32_t startTime, uint32_t nextTime);

void Heartbeat(led_color_t led_color, uint32_t dutyCycle, uint32_t period)
{
	static heartbeatState_t currentState = STATE_TURN_LED_ON;
	static heartbeatState_t nextState = STATE_DUTYCYCLE;

	static uint32_t startTime = 0;
	switch (currentState)
	{
	case STATE_TURN_LED_ON :
		nextState = StateTurnLedOn(&startTime, led_color);
		break;
	case STATE_DUTYCYCLE :
		nextState = StateDutycycle(currentState, startTime, dutyCycle);
		break;
	case STATE_TURN_LED_OFF :
		nextState = StateTurnLedOff(&startTime, led_color);
		break;
	case STATE_PERIOD :
		nextState = StatePeriod(currentState, startTime, period - dutyCycle);
		break;
	default:
		nextState = STATE_TURN_LED_ON;
	}

	currentState = nextState;
}

static heartbeatState_t StateTurnLedOn(uint32_t* startTime, const led_color_t led_color)
{
	drvLed_on(led_color);
	*startTime = ulSysTime_GetCurrentTime();
	return STATE_DUTYCYCLE;
}

static heartbeatState_t StateDutycycle(const heartbeatState_t currentState, uint32_t startTime, uint32_t nextTime)
{
	uint8_t isItTime = ulSysTime_IsItTime(startTime, nextTime);
	heartbeatState_t nextState = currentState;
	if (isItTime)
	{
		nextState = STATE_TURN_LED_OFF;
	}
	return nextState;
}

static heartbeatState_t StateTurnLedOff(uint32_t* startTime, const led_color_t led_color)
{
	drvLed_off(led_color);
	*startTime = ulSysTime_GetCurrentTime();
	return STATE_PERIOD;
}

static heartbeatState_t StatePeriod(const heartbeatState_t currentState, uint32_t startTime, uint32_t nextTime)
{
	uint8_t isItTime = ulSysTime_IsItTime(startTime, nextTime);
	heartbeatState_t nextState = currentState;
	if (isItTime)
	{
		nextState = STATE_TURN_LED_ON;
	}
	return nextState;
}
