/*
 * heartbeat.c
 *
 *  Created on: 30 нояб. 2019 г.
 *      Author: user
 */


#include "heartbeat.h"

void HeartBeat_run(uint32_t period, uint32_t dutycycle)
{
	drvLeds_on(LED_GREEN);
	HAL_Delay(dutycycle);
	drvLeds_off(LED_GREEN);
	HAL_Delay(period - dutycycle);
}
