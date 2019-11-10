/*
 * drvLEDs_HeartBeat.c
 *
 *  Created on: 1 нояб. 2019 г.
 *      Author: AllSE
 */

#include "main.h"
#include "drvLEDs.h"
#include "drvLEDs_HeartBeat.h"

#define PERIOD 500
#define DUTY_CYCLE 100

void drvLEDs_HeartBeat() {
  drvLEDs_On(LED_Blue);
  HAL_Delay(PERIOD);
  drvLEDs_Off(LED_Blue);
  HAL_Delay(PERIOD - DUTY_CYCLE);
}
