/*
 * HeartbeatRun.c
 *
 *  Created on: Nov 11, 2019
 *      Author: Lenovo
 */

#include "drvLeds.h"
#include "HeartbeatRun.h"

#define DELAY 500


void HeartBeatRun()
{
  drvLeds_on(LED_ORANGE);
  drvLeds_on(LED_BLUE);;
  drvLeds_on(LED_GREEN);;
  drvLeds_on(LED_RED);
  HAL_Delay(DELAY);
  drvLeds_off(LED_ORANGE);
  drvLeds_off(LED_BLUE);
  drvLeds_off(LED_GREEN);
  drvLeds_off(LED_RED);
  HAL_Delay(DELAY);
}
