/*
 * runningleds.c
 *
 *  Created on: 4 дек. 2019 г.
 *      Author: Korpyc
 */
#include "runningleds.h"
#include  "drvLeds.h"

void RunningLeds(uint16_t dutyCycle, uint16_t period, uint8_t ledqueue[3])
{
	for(uint8_t i=0;i<3;i++)
	{
	drvLeds_on(ledqueue[i]);
	HAL_Delay(dutyCycle);
	drveds_off(ledqueue[i]);
	HAL_Delay(period - dutyCycle);
	}
}
