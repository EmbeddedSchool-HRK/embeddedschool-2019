/*
 * drvLeds.c
 *
 *  Created on: 4 нояб. 2019 г.
 *      Author: av
 */

#include "drvLeds.h"
#include "main.h"

typedef struct{
	GPIO_TypeDef* port;
	uint16_t pin;
}led_t;

led_t leds[LED_AMOUNT]={
  {GPIOD, GPIO_PIN_13},     //LED_ORANGE
  {GPIOD, GPIO_PIN_12},     //LED_GREEN
  {GPIOD, GPIO_PIN_14},     //LED_RED
  {GPIOD, GPIO_PIN_15}      //LED_BLUE
};

void drvLeds_on (ledsList_t ledName){
  HAL_GPIO_WritePin(leds[ledName].port, leds[ledName].pin, GPIO_PIN_SET);
}

void drvLeds_off(ledsList_t ledName){
  HAL_GPIO_WritePin(leds[ledName].port, leds[ledName].pin, GPIO_PIN_RESET);
}
