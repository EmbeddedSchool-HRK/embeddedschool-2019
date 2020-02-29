/*
 * heartbeat.c
 *
 *  Created on: 4 дек. 2019 г.
 *      Author: Korpyc
 */


#include "heartbeat.h"
#include "drvLeds.h"
#include "ulSysTime.h"

const ledsList_t led_heartbeat = LED_BLUE;

typedef enum{
	STATE_TURN_LED_ON,
	STATE_WAIT_DUTYCYCLE,
	STATE_TURN_LED_OFF,
	STATE_WAIT_PERIOD
}heartbeatStates_t;

static heartbeatStates_t currentState = STATE_TURN_LED_ON;

void Heartbeat_LED_ON(ledsList_t led_usage, uint32_t *startTime, heartbeatStates_t *nextState)
{
	drvLeds_on(led_usage);
			*startTime = ulSysTime_getCurrentTime();
			*nextState = STATE_WAIT_DUTYCYCLE;
}

void Heartbeat_WAIT_DUTYCYCLE(uint16_t dutyCycle, uint32_t *startTime, heartbeatStates_t *nextState )
{
	uint8_t isItTime = 0;
	isItTime = ulSysTime_isItTime(*startTime, dutyCycle);
			if (isItTime)
				{
				*nextState = STATE_TURN_LED_OFF;
				}
}

void Heartbeat_LED_OFF(ledsList_t led_usage, uint32_t *startTime, heartbeatStates_t *nextState)
{
	drvLeds_off(led_usage);
			*startTime = ulSysTime_getCurrentTime();
			*nextState = STATE_WAIT_PERIOD;

}

void Heartbeat_WAIT_PERIOD(uint16_t dutyCycle,uint16_t period, uint32_t *startTime, heartbeatStates_t *nextState)
{
	uint8_t isItTime = 0;
	isItTime = ulSysTime_isItTime(*startTime, period - dutyCycle);
			if (isItTime)
				{
				*nextState = STATE_TURN_LED_OFF;
				}
}

void Heartbeat_Run(uint16_t dutyCycle, uint16_t period)
{
	static	uint32_t startTime = 0;
	heartbeatStates_t nextState = currentState;

	switch(currentState)
	{
	case STATE_TURN_LED_ON:
		Heartbeat_LED_ON(led_heartbeat, &startTime, &nextState);
		break;

	case STATE_WAIT_DUTYCYCLE:
		Heartbeat_WAIT_DUTYCYCLE(dutyCycle, &startTime, &nextState);
		break;

	case STATE_TURN_LED_OFF:
		Heartbeat_LED_OFF(led_heartbeat, &startTime, &nextState);
		break;

	case STATE_WAIT_PERIOD:
		Heartbeat_WAIT_PERIOD(dutyCycle, period, &startTime, &nextState);
		break;

	default:
		nextState = STATE_TURN_LED_ON;
	}

	currentState = nextState;

}
