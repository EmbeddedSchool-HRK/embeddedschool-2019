/*
 * driver_LEDs.h
 *
 *  Created on: Nov 1, 2019
 *      Author: Herr Satan
 */

#ifndef DRIVER_LEDS_H_
#define DRIVER_LEDS_H_

typedef enum {
	LED_ORANG,
	LED_GREEN,
	LED_RED,
	LED_BLUE,
	LED_AMOUNT
}ledlist_t;

void Led_On(ledlist_t led_name);
void Led_Off(ledlist_t led_name);

#endif /* DRIVER_LEDS_H_ */
