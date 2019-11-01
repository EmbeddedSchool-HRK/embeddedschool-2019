/*
 * drvLEDs_FourLigtRun.c
 *
 *  Created on: 1 нояб. 2019 г.
 *      Author: AllSE
 */

#include "stm32f4xx_hal.h"
#include "drvLEDs.h"
#include "drvLEDs_FourLigtRun.h"

void drvLEDs_FourLightRun(uint32_t period) {
  drvLEDs_Off(LED_Red);
  drvLEDs_On(LED_Orange);
  HAL_Delay(period);
  drvLEDs_Off(LED_Orange);
  drvLEDs_On(LED_Blue);
  HAL_Delay(period);
  drvLEDs_Off(LED_Blue);
  drvLEDs_On(LED_Green);
  HAL_Delay(period);
  drvLEDs_Off(LED_Green);
  drvLEDs_On(LED_Red);
  HAL_Delay(period);
}
