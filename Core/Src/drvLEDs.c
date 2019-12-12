/*
 * drvLEDs.c
 *
 *  Created on: 1 нояб. 2019 г.
 *      Author: AllSE
 */

#include "drvLEDs.h"

Led_t LEDs[LED_AMOUNT] = {
                //Port   Pin
  /*LED_Green*/  {GPIOD, GPIO_PIN_12},
  /*LED_Orange*/ {GPIOD, GPIO_PIN_13},
  /*LED_Red*/    {GPIOD, GPIO_PIN_14},
  /*LED_Blue*/   {GPIOD, GPIO_PIN_15}
};

void drvLEDs_On(LedList_t Led_Name){
  HAL_GPIO_WritePin(
    LEDs[Led_Name].Port,
	LEDs[Led_Name].Pin,
	GPIO_PIN_SET
	);
}

void drvLEDs_Off(LedList_t Led_Name){
  HAL_GPIO_WritePin(
    LEDs[Led_Name].Port,
    LEDs[Led_Name].Pin,
    GPIO_PIN_RESET
    );
}
