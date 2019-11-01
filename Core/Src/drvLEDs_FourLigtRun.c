/*
 * drvLEDs_FourLigtRun.c
 *
 *  Created on: 1 нояб. 2019 г.
 *      Author: AllSE
 */

#include "stm32f4xx_hal.h"
#include "drvLEDs.h"
#include "drvLEDs_FourLigtRun.h"

uint16_t LEDPatternRun[] = {
  LED_Green,  LED_Orange, LED_Red,    LED_Orange,
  LED_Green,  LED_Red,    LED_Orange, LED_Green,
  LED_Orange, LED_Red
};

int LEDPatternRunSize = sizeof(LEDPatternRun)/sizeof(uint16_t);

void drvLEDs_FourLightRun(uint32_t period) {
  for (int i = 0; i<LEDPatternRunSize; i++){
    drvLEDs_On(LEDPatternRun[i]);
    HAL_Delay(period);
    drvLEDs_Off(LEDPatternRun[i]);
  }
}