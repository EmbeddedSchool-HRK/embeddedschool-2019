/*
 * drvLeds.c
 *
 *  Created on: Nov 11, 2019
 *      Author: Lenovo
 */

#include "drvLeds.h"
#include "main.h"

typedef struct {
  GPIO_TypeDef* port;
  uint16_t pin;
}LedList_t;

LedList_t leds[LED_SCORE] = {
  {LD4_GPIO_Port, LD4_Pin},  //GREEN
  {LD5_GPIO_Port, LD5_Pin},  //RED
  {LD6_GPIO_Port, LD6_Pin},  //BLUE
  {LD3_GPIO_Port, LD3_Pin}   //ORANGE
};

void drvLeds_on(leds_t ledName){
  HAL_GPIO_WritePin(leds[ledName].port, leds[ledName].pin, GPIO_PIN_SET);
}

void drvLeds_off(leds_t ledName){
  HAL_GPIO_WritePin(leds[ledName].port, leds[ledName].pin, GPIO_PIN_RESET);
}

