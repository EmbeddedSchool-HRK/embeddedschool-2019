/*
 * heartbeat.c
 *
 *  Created on: Nov 13, 2019
 *      Author: Violetta
 */

#include "heartbeat.h"

void heartbeat(led_t LEDsColour, int Time)
{
	drvLeds_ON(LEDsColour);
    Delay(Time);
    drvLeds_OFF(LEDsColour);
    Delay(Time);
}

