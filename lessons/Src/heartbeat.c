/*
 * heartbeat.c
 *
 *  Created on: 6 нояб. 2019 г.
 *      Author: Win10Pro
 */

#include "main.h"
#include "heartbeat.h"
#include "drvLeds.h"

void Heartbeat_run(uint16_t dutyCycle, uint16_t period)
{
  drvLeds_on(LED_ORANGE);
  HAL_Delay(dutyCycle);
  drvLeds_off(LED_ORANGE);
  HAL_Delay(period - dutyCycle);
  drvLeds_on(LED_BLUE);
  HAL_Delay(dutyCycle);
  drvLeds_off(LED_BLUE);
  HAL_Delay(period - dutyCycle);
  drvLeds_on(LED_RED);
  HAL_Delay(dutyCycle);
  drvLeds_off(LED_RED);
  HAL_Delay(period - dutyCycle);
  drvLeds_on(LED_GREEN);
  HAL_Delay(dutyCycle);
  drvLeds_off(LED_GREEN);
  HAL_Delay(period - dutyCycle);
}
