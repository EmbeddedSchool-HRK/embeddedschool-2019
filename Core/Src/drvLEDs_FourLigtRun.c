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
  for (int i = 0; i<LEDPatternRunSize; i++){
    drvLEDs_On(LEDPatternRun[i]);
    HAL_Delay(PERIOD);
    drvLEDs_Off(LEDPatternRun[i]);
  }
}
