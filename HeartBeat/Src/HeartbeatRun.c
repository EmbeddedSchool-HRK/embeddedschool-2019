/*
 * HeartbeatRun.c
 *
 *  Created on: Nov 11, 2019
 *      Author: Lenovo
 */

#include "drvLeds.h"
#include "HeartbeatRun.h"

#define DELAY 500

Leds[LED_SCORE] = {LED_GREEN, LED_RED, LED_BLUE, LED_ORANGE};

void HeartBeatRun()
{
  for (uint16_t ledName = 0; ledName< LED_SCORE -1 ; ledName++){
  drvLeds_on(Leds[ledName]);
  HAL_Delay(DELAY);
  drvLeds_off(Leds[ledName]);
  }
}

