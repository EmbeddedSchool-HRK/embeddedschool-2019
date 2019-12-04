/*
 * runningleds.c
 *
 *  Created on: 4 дек. 2019 г.
 *      Author: Korpyc
 */
#include "runningleds.h"
#include  "drvLeds.h"

void RunningLeds(uint16_t dutyCycle, uint16_t period)
{
	drvLeds_on(LED_GREEN);
	HAL_Delay(dutyCycle);
	drveds_off(LED_GREEN);
	HAL_Delay(period - dutyCycle);
	drvLeds_on(LED_BLUE);
	HAL_Delay(dutyCycle);
	drveds_off(LED_BLUE);
	HAL_Delay(period - dutyCycle);
	drvLeds_on(LED_ORANGE);
	HAL_Delay(dutyCycle);
	drveds_off(LED_ORANGE);
	HAL_Delay(period - dutyCycle);
}
