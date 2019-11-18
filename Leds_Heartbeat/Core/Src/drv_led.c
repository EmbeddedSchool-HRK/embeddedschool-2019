/*
 * drv_led.c
 *
 *  Created on: 18 нояб. 2019 г.
 *      Author: vit
 */
#include "main.h"
#include "drv_led.h"


typedef struct{
	GPIO_TypeDef* port;
	uint16_t pin;
}led_type;

led_type array[Counter] =
{
	{GPIOD, GPIO_PIN_12},
	{GPIOD, GPIO_PIN_13},
	{GPIOD, GPIO_PIN_14},
	{GPIOD, GPIO_PIN_15}
};

void Leds_activation(led_colour led_number){
  HAL_GPIO_WritePin(array[led_number].port, array[led_number].pin, GPIO_PIN_SET);
}

void Leds_disable(led_colour led_number){
  HAL_GPIO_WritePin(array[led_number].port, array[led_number].pin, GPIO_PIN_RESET);
}
