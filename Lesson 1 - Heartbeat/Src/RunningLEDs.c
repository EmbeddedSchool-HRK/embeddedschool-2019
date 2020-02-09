/*
 * RunningLEDs.c
 *
 *  Created on: 21 лист. 2019 р.
 *      Author: Local user Profile
 */

#include "RunningLEDs.h"
#include "drvLED.h"
#include "ulSysTime.h"

typedef enum
{
	STATE_LED_ON,
	STATE_WAIT_DELAY_ON,
	STATE_LED_OFF,
	STATE_WAIT_DELAY_OFF,
	STATE_LED_CHANGE
} LEDRunStates_t;

static LEDRunStates_t LEDRunState = STATE_LED_ON;

static LEDRunStates_t StateChangeDelay(uint32_t StartTime, uint32_t delay,
									   LEDRunStates_t CurrentState, LEDRunStates_t NextState)
{

	LEDRunStates_t state = CurrentState;
	static uint8_t IsItTime = 0;
	IsItTime = ulSysTime_CheckIfTime(StartTime, delay);
	if (IsItTime)
	{
		state = NextState;
	}
	return state;
}

void LEDsRun(uint16_t delay, ledlist_t LED_array[], uint16_t steps)
{
	static uint8_t step = 0;
	static uint32_t StartTime = 0;
	LEDRunStates_t NextState = LEDRunState;
	switch (LEDRunState)
	{
	case STATE_LED_ON:
		drvLED_on(LED_array[step]);
		StartTime = ulSysTime_GetTime();
		NextState = STATE_WAIT_DELAY_ON;
		break;
	case STATE_WAIT_DELAY_ON:
		NextState = StateChangeDelay(StartTime, delay, STATE_WAIT_DELAY_ON, STATE_LED_OFF);
		break;
	case STATE_LED_OFF:
		drvLED_off(LED_array[step]);
		StartTime = ulSysTime_GetTime();
		NextState = STATE_WAIT_DELAY_OFF;
		break;
	case STATE_WAIT_DELAY_OFF:
		NextState = StateChangeDelay(StartTime, delay, STATE_WAIT_DELAY_OFF, STATE_LED_CHANGE);
		break;
	case STATE_LED_CHANGE:
		if (step < steps - 1)
			step++;
		else
			step = 0;
		NextState = STATE_LED_ON;
		break;
	default:
		LEDRunState = STATE_LED_ON;
	}
	LEDRunState = NextState;
}
