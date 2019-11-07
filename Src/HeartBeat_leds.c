/*
 * HeartBeat_leds.c
 *
 *  Created on: Nov 7, 2019
 *      Author: morok__
 */


#include "HeartBeat_leds.h"
#include "DrvLEDs.h"


void HeartBeat_led_Red(uint16_t dutyCycle, uint16_t period){
  DrvLEDs_on(LED_RED);
  HAL_Delay(period);
  DrvLEDs_off(LED_RED);
  HAL_Delay(dutyCycle - period);
}
