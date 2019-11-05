/*
 * ledsInit.c
 *
 *  Created on: 5 нояб. 2019 г.
 *      Author: S1ckret
 */

#include "stm32f4xx_hal.h"

#include "drvLeds.h"
#include "ledsInit.h"


void ledsInit(uint32_t time)
{
	drvLed_on(LED_BLUE);
	drvLed_on(LED_GREEN);
	drvLed_on(LED_ORANGE);
	drvLed_on(LED_RED);
	HAL_Delay(time);
	drvLed_off(LED_BLUE);
	drvLed_off(LED_GREEN);
	drvLed_off(LED_ORANGE);
	drvLed_off(LED_RED);
}
