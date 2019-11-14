/*
 * drvLeds.c
 *
 *  Created on: 6 нояб. 2019 г.
 *      Author: Win10Pro
 */

#include "drvLeds.h"
#include "main.h"

typedef struct {
  GPIO_TypeDef* port;
  uint16_t pin;
}led_t;

led_t leds[LED_AMOUNT] = {
  {LD3_GPIO_Port, LD3_Pin}, //LED_ORANE
  {LD6_GPIO_Port, LD6_Pin}, //LED_BLUE
  {LD5_GPIO_Port, LD5_Pin}, //LED_RED
  {LD4_GPIO_Port, LD4_Pin}, //LED_GREEN
};

void drvLeds_on(ledsList_t ledName) {
  HAL_GPIO_WritePin(leds[ledName].port, leds[ledName].pin, GPIO_PIN_SET);
}

void drvLeds_off(ledsList_t ledName) {
  HAL_GPIO_WritePin(leds[ledName].port, leds[ledName].pin, GPIO_PIN_RESET);
}
