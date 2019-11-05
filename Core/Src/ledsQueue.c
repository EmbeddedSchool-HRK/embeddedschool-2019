/*
 * heartbeat.c
 *
 *  Created on: 5 нояб. 2019 г.
 *      Author: S1ckret
 */
#include "stm32f4xx_hal.h"

#include "ledsQueue.h"

void LedsQueue_d(uint32_t time)
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


void LedsQueue(led_color_t* leds_queue, uint32_t count, uint32_t time)
{
	for (uint32_t i = 0; i < count; i++)
	{
		drvLed_on(leds_queue[i]);
		HAL_Delay(time);
		drvLed_off(leds_queue[i]);
	}
}
