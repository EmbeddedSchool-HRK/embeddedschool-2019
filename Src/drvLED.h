/*
 * drvLED.h
 *
 *  Created on: Nov 13, 2019
 *      Author: Violetta
 */

#ifndef DRVLED_H_
#define DRVLED_H_
#include "main.h"

typedef enum
{
	LED_BLUE = LD6_Pin,
	LED_RED = LD5_Pin,
	LED_ORANGE = LD3_Pin,
	LED_GREEN = LD4_Pin

}led_t;

void drvLeds_ON(led_t LEDsColour);
void drvLeds_OFF(led_t LEDsColour);
void Delay(int Time);


#endif /* DRVLED_H_ */
