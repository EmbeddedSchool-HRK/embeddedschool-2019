/*
 * heartbeat.c
 *
 *  Created on: 5 нояб. 2019 г.
 *      Author: S1ckret
 */
#include "stm32f4xx_hal.h"

#include "ledsQueue.h"
#include "ulSysTime.h"

void LedsQueue_default(uint32_t time)
{
	drvLed_on(LED_ORANGE);
	HAL_Delay(time);
	drvLed_off(LED_ORANGE);

	drvLed_on(LED_BLUE);
	HAL_Delay(time);
	drvLed_off(LED_BLUE);

	drvLed_on(LED_GREEN);
	HAL_Delay(time);
	drvLed_off(LED_GREEN);

	drvLed_on(LED_RED);
	HAL_Delay(time);
	drvLed_off(LED_RED);
}


typedef enum
{
	STATE_TURN_LED_ON,
	STATE_DUTYCYCLE,
	STATE_TURN_LED_OFF,
	STATE_INCREMENT
} ledsQueueState_t;

// Returns time when the Led was turned on.
static uint32_t StateTurnLedOn(ledsQueueState_t* state, const led_color_t led_color);

static void StateDutycycle(ledsQueueState_t* state, uint32_t startTime, uint32_t nextTime);

// Returns time when the Led was turned off.
static uint32_t StateTurnLedOff(ledsQueueState_t* state, const led_color_t led_color);

static void StateIncrement(ledsQueueState_t* state, uint32_t* currentIndex, uint32_t maxIndex);

void LedsQueue(led_color_t* leds_queue, uint32_t count, uint32_t time)
{
	static ledsQueueState_t currentState = STATE_TURN_LED_ON;
	static ledsQueueState_t nextState = STATE_DUTYCYCLE;

	static uint32_t startTime = 0;
	static uint32_t currentLedIndex = 0;
	switch (currentState)
	{
	case STATE_TURN_LED_ON :
		startTime = StateTurnLedOn(&nextState, leds_queue[currentLedIndex]);
		break;
	case STATE_DUTYCYCLE :
		StateDutycycle(&nextState, startTime, time);
		break;
	case STATE_TURN_LED_OFF :
		startTime = StateTurnLedOff(&nextState, leds_queue[currentLedIndex]);
		break;
	case STATE_INCREMENT :
		StateIncrement(&nextState, &currentLedIndex, count);
		break;
	default:
		nextState = STATE_TURN_LED_ON;
	}

	currentState = nextState;
}


// Returns time when the Led was turned on.
static uint32_t StateTurnLedOn(ledsQueueState_t* state, const led_color_t led_color)
{
	drvLed_on(led_color);
	*state = STATE_DUTYCYCLE;
	return ulSysTime_GetCurrentTime();
}

static void StateDutycycle(ledsQueueState_t* state, uint32_t startTime, uint32_t nextTime)
{
	uint8_t isItTime = ulSysTime_IsItTime(startTime, nextTime);
	if (isItTime)
	{
		*state = STATE_TURN_LED_OFF;
	}
}

// Returns time when the Led was turned off.
static uint32_t StateTurnLedOff(ledsQueueState_t* state, const led_color_t led_color)
{
	drvLed_off(led_color);
	*state = STATE_INCREMENT;
	return ulSysTime_GetCurrentTime();
}

static void StateIncrement(ledsQueueState_t* state, uint32_t* currentIndex, uint32_t maxIndex)
{
	if (*currentIndex < maxIndex)
	{
		(*currentIndex)++;
	}
	else
	{
		*currentIndex = 0;
	}
	*state = STATE_TURN_LED_ON;
}

