/*
 * drvLEDs_AllLight.c
 *
 *  Created on: 1 нояб. 2019 г.
 *      Author: AllSE
 */

#include "stm32f4xx_hal.h"
#include "drvLEDs.h"
#include "drvLEDs_AllLight.h"

void drvLEDs_AllLight(uint32_t period) {
  drvLEDs_On(LED_Green);
  drvLEDs_On(LED_Red);
  drvLEDs_On(LED_Orange);
  drvLEDs_On(LED_Blue);
  HAL_Delay(period);
  drvLEDs_Off(LED_Green);
  drvLEDs_Off(LED_Red);
  drvLEDs_Off(LED_Orange);
  drvLEDs_Off(LED_Blue);
}
