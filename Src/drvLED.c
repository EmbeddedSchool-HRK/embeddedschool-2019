/*
 * drvLED.c
 *
 *  Created on: Nov 13, 2019
 *      Author: Violetta
 */

#include "drvLED.h"
#include "main.h"

void drvLeds_ON(led_t LEDsColour)
{
	HAL_GPIO_WritePin(GPIOD, LEDsColour, GPIO_PIN_SET);
}

void drvLeds_OFF(led_t LEDsColour)
{
	HAL_GPIO_WritePin(GPIOD, LEDsColour, GPIO_PIN_RESET);
}
 void Delay(int Time)
 {
	 HAL_Delay(Time);
 }
