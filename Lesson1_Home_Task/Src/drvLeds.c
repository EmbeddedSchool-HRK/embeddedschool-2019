/*
 * drvLeds.c
 *
 *  Created on: Nov 14, 2019
 *      Author: Slavon
 */


#include "drvLeds.h"

type_t led[LED_AMOUNT] = {
    {GPIOD, GPIO_PIN_14}, // RED
    {GPIOD, GPIO_PIN_12}, // GREEN
    {GPIOD, GPIO_PIN_13}, // ORANGE
    {GPIOD, GPIO_PIN_15}, // BLUE
};

void drvLeds_ON(list_t ledName)
{
  HAL_GPIO_WritePin(led[ledName].port, led[ledName].pin, GPIO_PIN_SET);
}


void drvLeds_OFF(list_t ledName)
{
  HAL_GPIO_WritePin(led[ledName].port, led[ledName].pin, GPIO_PIN_RESET);
}
