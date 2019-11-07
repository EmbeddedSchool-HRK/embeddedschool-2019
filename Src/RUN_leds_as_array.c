/*
 * RUN_leds_as_array.c
 *
 *  Created on: Nov 7, 2019
 *      Author: morok__
 */


#include "RUN_leds_as_array.h"
#include "DrvLEDs.h"


void LEDs_run_as_array(uint16_t dutyCycle, uint16_t period){
  DrvLEDs_on(LED_BLUE);
  HAL_Delay(period);
  DrvLEDs_off(LED_BLUE);
  HAL_Delay(dutyCycle - period);
  DrvLEDs_on(LED_RED);
  HAL_Delay(period);
  DrvLEDs_off(LED_RED);
  HAL_Delay(dutyCycle - period);
  DrvLEDs_on(LED_ORANGE);
  HAL_Delay(period);
  DrvLEDs_off(LED_ORANGE);
  HAL_Delay(dutyCycle - period);
  DrvLEDs_on(LED_GREEN);
  HAL_Delay(period);
  DrvLEDs_off(LED_GREEN);
  HAL_Delay(dutyCycle - period);
}
