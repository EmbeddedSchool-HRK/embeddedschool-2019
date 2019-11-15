/*
 * heartbeat.c
 *
 *  Created on: 5 нояб. 2019 г.
 *      Author: S1ckret
 */
#include "heartbeat.h"

void Heartbeat(led_color_t led_color, uint32_t period, uint32_t dutycycle)
{
	drvLed_on(led_color);
	HAL_Delay(period);
	drvLed_off(led_color);
	HAL_Delay(period - dutycycle);
}
