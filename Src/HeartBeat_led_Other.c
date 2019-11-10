/*
 * HeartBeat_led_Other.c
 *
 *  Created on: 10 нояб. 2019 г.
 *      Author: morok__
 */


#include "Drv_LEDs.h"
#include "Heartbeat_Red_LED.h"

void HeartBeat_led_Other(uint16_t period, uint16_t dutycycle) {
  DrvLEDs_on(LED_GREEN);
  HAL_Delay(dutycycle);
  DrvLEDs_off(LED_GREEN);
  HAL_Delay(period - dutycycle);
  DrvLEDs_on(LED_ORANGE);
  HAL_Delay(dutycycle);
  DrvLEDs_off(LED_ORANGE);
  HAL_Delay(period - dutycycle);
  DrvLEDs_on(LED_BLUE);
  HAL_Delay(dutycycle);
  DrvLEDs_off(LED_BLUE);
  HAL_Delay(period - dutycycle);
}
