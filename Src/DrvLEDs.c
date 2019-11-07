/*
 * DrvLEDs.c
 *
 *  Created on: Nov 7, 2019
 *      Author: morok__
 */


#include "DrvLEDs.h"
#include "main.h"


typedef struct {
	GPIO_TypeDef* port;
	uint16_t pin;
}LED_type;

LED_type leds[LED_COUNT] = {
		{LD6_GPIO_Port, LD6_Pin},  // LED_BLUE
		{LD5_GPIO_Port, LD5_Pin},  // LED_RED
		{LD3_GPIO_Port, LD3_Pin},  // LED_ORANGE
		{LD4_GPIO_Port, LD4_Pin},  // LED_GREEN

};

void DrvLEDs_on(LED_LIST ledName){

	HAL_GPIO_WritePin(leds[ledName].port, leds[ledName].pin, GPIO_PIN_SET);

}

void DrvLEDs_off(LED_LIST ledName){

	HAL_GPIO_WritePin(leds[ledName].port, leds[ledName].pin, GPIO_PIN_RESET);

}

