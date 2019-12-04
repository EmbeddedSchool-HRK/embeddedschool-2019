/*
 * heartbeat.c
 *
 *  Created on: 4 дек. 2019 г.
 *      Author: Korpyc
 */


#include "heartbeat.h"
#include "drvLeds.h"

void Heartbeat_Run(uint16_t dutyCycle, uint16_t period)
{
	drvLeds_on(LED_RED);
	HAL_Delay(dutyCycle);
	drveds_off(LED_RED);
	HAL_Delay(period - dutyCycle);
}
