/*
 * drvLEDs_FourLigtRun.c
 *
 *  Created on: 1 нояб. 2019 г.
 *      Author: AllSE
 */

#include "main.h"
#include "drvLEDs.h"
#include "drvLEDs_FourLigtRun.h"

#define PERIOD 500

uint16_t LEDPatternRun[] = {
  LED_Green,  LED_Orange, LED_Red,    LED_Orange,
  LED_Green,  LED_Red,    LED_Orange, LED_Green,
  LED_Orange, LED_Red
};

int LEDPatternRunSize = sizeof(LEDPatternRun)/sizeof(uint16_t);

void drvLEDs_FourLightRun() {
  drvLEDs_Off(LED_Red);
  drvLEDs_On(LED_Orange);
  HAL_Delay(PERIOD);
  drvLEDs_Off(LED_Orange);
  drvLEDs_On(LED_Blue);
  HAL_Delay(PERIOD);
  drvLEDs_Off(LED_Blue);
  drvLEDs_On(LED_Green);
  HAL_Delay(PERIOD);
  drvLEDs_Off(LED_Green);
  drvLEDs_On(LED_Red);
  HAL_Delay(PERIOD);
}
