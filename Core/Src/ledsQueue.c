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


static ledsQueueState_t StateTurnLedOn(uint32_t* startTime, const led_color_t led_color);

static ledsQueueState_t StateDutycycle(const ledsQueueState_t currentState, uint32_t startTime, uint32_t nextTime);

static ledsQueueState_t StateTurnLedOff(uint32_t* startTime, const led_color_t led_color);

static ledsQueueState_t StateIncrement(uint32_t* currentIndex, uint32_t maxIndex);

void LedsQueue(led_color_t* leds_queue, uint32_t count, uint32_t time)
{
	static ledsQueueState_t currentState = STATE_TURN_LED_ON;
	static ledsQueueState_t nextState = STATE_DUTYCYCLE;

	static uint32_t startTime = 0;
	static uint32_t currentLedIndex = 0;
	switch (currentState)
	{
	case STATE_TURN_LED_ON :
		nextState = StateTurnLedOn(&startTime, leds_queue[currentLedIndex]);
		break;
	case STATE_DUTYCYCLE :
		nextState = StateDutycycle(currentState, startTime, time);
		break;
	case STATE_TURN_LED_OFF :
		nextState = StateTurnLedOff(&startTime, leds_queue[currentLedIndex]);
		break;
	case STATE_INCREMENT :
		nextState = StateIncrement(&currentLedIndex, count);
		break;
	default:
		nextState = STATE_TURN_LED_ON;
	}

	currentState = nextState;
}


static ledsQueueState_t StateTurnLedOn(uint32_t* startTime, const led_color_t led_color)
{
	drvLed_on(led_color);
	*startTime = ulSysTime_GetCurrentTime();
	return STATE_DUTYCYCLE;
}

static ledsQueueState_t StateDutycycle(const ledsQueueState_t currentState, uint32_t startTime, uint32_t nextTime)
{
	uint8_t isItTime = ulSysTime_IsItTime(startTime, nextTime);
	ledsQueueState_t nextState = currentState;
	if (isItTime)
	{
		nextState = STATE_TURN_LED_OFF;
	}
	return nextState;
}

static ledsQueueState_t StateTurnLedOff(uint32_t* startTime, const led_color_t led_color)
{
	drvLed_off(led_color);
	*startTime = ulSysTime_GetCurrentTime();
	return STATE_INCREMENT;
}

static ledsQueueState_t StateIncrement(uint32_t* currentIndex, uint32_t maxIndex)
{
	*currentIndex = ++(*currentIndex) % maxIndex;
	return STATE_TURN_LED_ON;
}

