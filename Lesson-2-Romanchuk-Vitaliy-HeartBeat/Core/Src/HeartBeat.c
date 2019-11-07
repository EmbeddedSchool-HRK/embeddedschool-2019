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
drvLeds_on(LED_Blue);
HAL_Delay(dutycycle);
drvLeds_on(LED_Green);
HAL_Delay(dutycycle);
drvLeds_off(LED_Green);
HAL_Delay(period - dutycycle);
drvLeds_off(LED_Blue);
HAL_Delay(period - dutycycle);
drvLeds_off(LED_Orange);
HAL_Delay(period - dutycycle);
}
void four_minutes_func(uint32_t period) {
drvLeds_on(LED_Red);
HAL_Delay(period);
}
