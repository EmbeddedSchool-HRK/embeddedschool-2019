/*
 * drvLeds.c
 *
 *  Created on: 30 нояб. 2019 г.
 *      Author: user
 */

#include "drvLeds.h"

typedef struct
{
	GPIO_TypeDef * LedPort;
	uint16_t LedName;
} leds_t;

leds_t Leds[LED_AMOUNT] ={{GPIOD, GPIO_PIN_13}, {GPIOD, GPIO_PIN_15}, {GPIOD, GPIO_PIN_12}, {GPIOD, GPIO_PIN_14}} ;

void drvLeds_on(ledlist_t selectedLed)
{
	HAL_GPIO_WritePin(Leds[selectedLed].LedPort, Leds[selectedLed].LedName, GPIO_PIN_SET);
}
void drvLeds_off(ledlist_t selectedLed)
{
	HAL_GPIO_WritePin(Leds[selectedLed].LedPort, Leds[selectedLed].LedName, GPIO_PIN_RESET);
}
