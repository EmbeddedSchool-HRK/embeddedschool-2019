/*
 * drvLeds.h
 *
 *  Created on: Nov 11, 2019
 *      Author: Lenovo
 */

#ifndef DRVLEDS_H_
#define DRVLEDS_H_


typedef enum {
	LED_GREEN,
	LED_RED,
	LED_BLUE,
	LED_ORANGE,
	LED_SCORE
}leds_t;

void drvLeds_on(leds_t ledName);

void drvLeds_off(leds_t ledName);


#endif /* DRVLEDS_H_ */
