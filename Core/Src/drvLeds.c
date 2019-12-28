/*
 * drvLeds.c
 *
 *  Created on: 5 нояб. 2019 г.
 *      Author: S1ckret
 */
#include "drvLeds.h"
#include "main.h"

typedef struct
{
	GPIO_TypeDef* Port;
	uint16_t Pin;
} Led_t;

static Led_t leds[LED_COUNT] =
{
	{LD4_GPIO_Port, LD4_Pin},	// Green
	{LD5_GPIO_Port, LD5_Pin},	// Red
	{LD3_GPIO_Port, LD3_Pin},	// Orange
	{LD6_GPIO_Port, LD6_Pin}	// Blue
};

void drvLed_on(led_color_t led_color)
{
	HAL_GPIO_WritePin(leds[led_color].Port, leds[led_color].Pin, GPIO_PIN_SET);
}

void drvLed_off(led_color_t led_color)
{
	HAL_GPIO_WritePin(leds[led_color].Port, leds[led_color].Pin, GPIO_PIN_RESET);
}


void drvLed_onAll()
{
	for(led_color_t led = 0; led < LED_COUNT; led++)
	{
		drvLed_on(led);
	}
}

void drvLed_offAll()
{
	for(led_color_t led = 0; led < LED_COUNT; led++)
	{
		drvLed_off(led);
	}
}
