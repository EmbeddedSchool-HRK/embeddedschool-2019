/*
 * drvLeds.h
 *
 *  Created on: 5 нояб. 2019 г.
 *      Author: S1ckret
 */

#ifndef SRC_DRVLEDS_H_
#define SRC_DRVLEDS_H_

typedef enum
{
	LED_GREEN = 0,
	LED_RED,
	LED_ORANGE,
	LED_BLUE,
	LED_COUNT
} led_color_t;

void drvLed_on(led_color_t led_color);

void drvLed_off(led_color_t led_color);

#endif /* SRC_DRVLEDS_H_ */
