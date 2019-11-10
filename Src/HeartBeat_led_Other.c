/*
 * HeartBeat_led_Other.c
 *
 *  Created on: 10 нояб. 2019 г.
 *      Author: morok__
 */


#include "Drv_LEDs.h"
#include "Heartbeat_Red_LED.h"

LED_LIST array_example [LED_COUNT] = {LED_BLUE, LED_ORANGE, LED_GREEN};

void HeartBeat_led_Other(uint16_t period, uint16_t dutycycle) {
  for (uint16_t ledName = 0; ledName< LED_COUNT -1 ; ledName++){
  DrvLEDs_on(array_example[ledName]);
  HAL_Delay(dutycycle);
  DrvLEDs_off(array_example[ledName]);
  HAL_Delay(period - dutycycle);
  }
 }
