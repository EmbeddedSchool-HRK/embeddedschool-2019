/*
 * runningleds.c
 *
 *  Created on: 4 дек. 2019 г.
 *      Author: Korpyc
 */
#include "runningleds.h"
#include  "drvLeds.h"
#include  "ulSysTime.h"

typedef enum{
	STATE_TURN_LED_ON,
	STATE_WAIT_DUTYCYCLE,
	STATE_TURN_LED_OFF,
	STATE_WAIT_PERIOD,
	STATE_SCENARIO_STEP
}runningledsStates_t;

static runningledsStates_t currentState = STATE_TURN_LED_ON;



void Runningleds_LED_ON(ledsList_t led_usage, uint32_t *startTime, runningledsStates_t *nextState)
{
	drvLeds_on(led_usage);
			*startTime = ulSysTime_getCurrentTime();
			*nextState = STATE_WAIT_DUTYCYCLE;
}

void Runningleds_WAIT_DUTYCYCLE(uint16_t dutyCycle, uint32_t *startTime, runningledsStates_t *nextState )
{
	uint8_t isItTime = 0;
	isItTime = ulSysTime_isItTime(*startTime, dutyCycle);
			if (isItTime)
				{
				*nextState = STATE_TURN_LED_OFF;
				}
}

void Runningleds_LED_OFF(ledsList_t led_usage, uint32_t *startTime, runningledsStates_t *nextState)
{
	drvLeds_off(led_usage);
			*startTime = ulSysTime_getCurrentTime();
			*nextState = STATE_WAIT_PERIOD;

}

void Runningleds_WAIT_PERIOD(uint16_t dutyCycle,uint16_t period, uint32_t *startTime, runningledsStates_t *nextState)
{
	uint8_t isItTime = 0;
	isItTime = ulSysTime_isItTime(*startTime, period - dutyCycle);
			if (isItTime)
				{
				*nextState = STATE_SCENARIO_STEP;
				}
}

void Runningleds_SCENARIO_STEP(runningledsStates_t *nextState, uint8_t *scenario_step, uint8_t *led_amount)
{
	uint8_t step = *scenario_step;
	step++;
	if(step >= *led_amount) step = 0;
	*scenario_step = step;
	*nextState = STATE_TURN_LED_ON;
}

void RunningLeds(uint16_t dutyCycle, uint16_t period, uint8_t ledqueue[3], uint8_t led_amount)
{
	static	uint32_t startTime = 0;
	runningledsStates_t nextState = currentState;
	static uint8_t scenario_step = 0;


	switch(currentState)
	{
	case STATE_TURN_LED_ON :
		Runningleds_LED_ON(ledqueue[scenario_step], &startTime, &nextState);
		break;

	case STATE_WAIT_DUTYCYCLE :
		Runningleds_WAIT_DUTYCYCLE(dutyCycle, &startTime, &nextState);
		break;

	case STATE_TURN_LED_OFF :
		Runningleds_LED_OFF(ledqueue[scenario_step], &startTime, &nextState);
		break;

	case STATE_WAIT_PERIOD :
		Runningleds_WAIT_PERIOD(dutyCycle, period, &startTime, &nextState);
		break;
	case STATE_SCENARIO_STEP :
		Runningleds_SCENARIO_STEP(&nextState, &scenario_step, &led_amount);
		break;

	default:
		nextState = STATE_TURN_LED_ON;
	}

	currentState = nextState;
}
