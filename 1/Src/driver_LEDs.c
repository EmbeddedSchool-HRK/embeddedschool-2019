/*
 * driver_LEDs.c
 *
 *  Created on: Nov 2, 2019
 *      Author: Herr Satan
 */


#include "driver_LEDs.h"
#include "main.h"

typedef struct {
	GPIO_TypeDef* port;
	uint16_t pin;
}led_t;

led_t led[LED_AMOUNT] = {
  {GPIOD, GPIO_PIN_13}, // orange
  {GPIOD, GPIO_PIN_12}, // green
  {GPIOD, GPIO_PIN_14}, // red
  {GPIOD, GPIO_PIN_15} // blue
};

void Led_On(ledlist_t led_name){
  HAL_GPIO_WritePin(led[led_name].port, led[led_name].pin, GPIO_PIN_SET);
}

void Led_Off(ledlist_t led_name){
  HAL_GPIO_WritePin(led[led_name].port, led[led_name].pin, GPIO_PIN_RESET);
}
