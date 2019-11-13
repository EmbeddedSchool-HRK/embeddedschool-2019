/*
 * Heartbeat_OrangeLED.c
 *
 *  Created on: Nov 11, 2019
 *      Author: Lenovo
 */

#include "drvLeds.h"
#include "Heartbeat_OrangeLED.h"

#define DELAY 100

void HeartBeat_ORANGELED()
{
drvLeds_on(LED_ORANGE);
HAL_Delay(DELAY);
drvLeds_off(LED_ORANGE);
HAL_Delay(DELAY);
}
