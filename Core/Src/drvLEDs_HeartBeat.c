/*
 * drvLEDs_HeartBeat.c
 *
 *  Created on: 1 нояб. 2019 г.
 *      Author: AllSE
 */

#include "stm32f4xx_hal.h"
#include "drvLEDs.h"
#include "drvLEDs_HeartBeat.h"

void drvLEDs_HeartBeat(uint32_t period, uint32_t dutycycle) {
  drvLEDs_On(LED_Blue);
  HAL_Delay(dutycycle);
  drvLEDs_Off(LED_Blue);;
  HAL_Delay(period - dutycycle);
}
