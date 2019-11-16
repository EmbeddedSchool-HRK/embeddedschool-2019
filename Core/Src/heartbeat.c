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

// Returns time when the Led was turned on.
static uint32_t StateTurnLedOn(heartbeatState_t* state, const led_color_t led_color);

static void StateDutycycle(heartbeatState_t* state, uint32_t startTime, uint32_t nextTime);

// Returns time when the Led was turned off.
static uint32_t StateTurnLedOff(heartbeatState_t* state, const led_color_t led_color);

static void StatePeriod(heartbeatState_t* state, uint32_t startTime, uint32_t nextTime);

void Heartbeat(led_color_t led_color, uint32_t dutyCycle, uint32_t period)
{
	static heartbeatState_t currentState = STATE_TURN_LED_ON;
	static heartbeatState_t nextState = STATE_DUTYCYCLE;

	static uint32_t startTime = 0;
	switch (currentState)
	{
	case STATE_TURN_LED_ON :
		startTime = StateTurnLedOn(&nextState, led_color);
		break;
	case STATE_DUTYCYCLE :
		StateDutycycle(&nextState, startTime, dutyCycle);
		break;
	case STATE_TURN_LED_OFF :
		startTime = StateTurnLedOff(&nextState, led_color);
		break;
	case STATE_PERIOD :
		StatePeriod(&nextState, startTime, period - dutyCycle);
		break;
	default:
		nextState = STATE_TURN_LED_ON;
	}

	currentState = nextState;
}

// Returns time when the Led was turned on.
static uint32_t StateTurnLedOn(heartbeatState_t* state, const led_color_t led_color)
{
	drvLed_on(led_color);
	*state = STATE_DUTYCYCLE;
	return ulSysTime_GetCurrentTime();
}

static void StateDutycycle(heartbeatState_t* state, uint32_t startTime, uint32_t nextTime)
{
	uint8_t isItTime = ulSysTime_IsItTime(startTime, nextTime);
	if (isItTime)
	{
		*state = STATE_TURN_LED_OFF;
	}
}

// Returns time when the Led was turned off.
static uint32_t StateTurnLedOff(heartbeatState_t* state, const led_color_t led_color)
{
	drvLed_off(led_color);
	*state = STATE_PERIOD;
	return ulSysTime_GetCurrentTime();
}

static void StatePeriod(heartbeatState_t* state, uint32_t startTime, uint32_t nextTime)
{
	uint8_t isItTime = ulSysTime_IsItTime(startTime, nextTime);
	if (isItTime)
	{
		*state = STATE_TURN_LED_ON;
	}
}
