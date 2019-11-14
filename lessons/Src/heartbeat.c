/*
 * heartbeat.c
 *
 *  Created on: 6 нояб. 2019 г.
 *      Author: Win10Pro
 */

#include "main.h"
#include "heartbeat.h"
#include "drvLeds.h"

ledsList_t LED_array [LED_AMOUNT] = {LED_ORANGE, LED_BLUE, LED_RED,LED_GREEN};
// здесь вводить последовательность светодиодов


void Heartbeat_run(uint16_t dutyCycle, uint16_t period)
{
  for (uint16_t ledName = 0; ledName < LED_AMOUNT - 1 ; ledName++) {
  drvLeds_on(LED_array[ledName]);
  HAL_Delay(dutyCycle);
  drvLeds_off(LED_array[ledName]);
  HAL_Delay(period - dutyCycle);
  }
}
