/*
 * drvLeds.c
 *
 *  Created on: 6 лист. 2019 р.
 *      Author: TheKeeper
 */

#include "main.h"
#include "drvLeds.h"

typedef struct {
  GPIO_TypeDef* port;
  uint16_t pin;
}led_t;

led_t LEDS[LED_Amount] = {
	{GPIOD, GPIO_PIN_13}, // LED_Orange
	{GPIOD, GPIO_PIN_15}, // LED_Blue
	{GPIOD, GPIO_PIN_12}, // LED_Green
	{GPIOD, GPIO_PIN_14}  // LED_Red
};

void drvLeds_on(ledslist_t ledName) {
  HAL_GPIO_WritePin (LEDS[ledName].port, LEDS[ledName].pin, GPIO_PIN_SET);
}
void drvLeds_off(ledslist_t ledName){
  HAL_GPIO_WritePin (LEDS[ledName].port, LEDS[ledName].pin, GPIO_PIN_RESET);
}
