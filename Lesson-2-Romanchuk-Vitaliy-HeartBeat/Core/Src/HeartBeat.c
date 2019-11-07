/*
 * HeartBeat.c
 *
 *  Created on: 6 лист. 2019 р.
 *      Author: TheKeeper
 */

#include "main.h"
#include "HeartBeat.h"
#include "drvLeds.h"

void five_minutes_func(uint32_t period, uint32_t dutycycle) {
drvLeds_on(LED_Orange);
HAL_Delay(dutycycle);
drvLeds_off(LED_Orange);
HAL_Delay(period - dutycycle);
}
