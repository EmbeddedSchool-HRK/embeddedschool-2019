/*
 * drv_led.h
 *
 *  Created on: 18 нояб. 2019 г.
 *      Author: vit
 */

#ifndef SRC_DRV_LED_H_
#define SRC_DRV_LED_H_

typedef enum {
	Led_Green,
	Led_Orange,
	Led_Red,
	Led_Blue,
	Counter
}led_colour;

void Leds_activation(led_colour colour);
void Leds_disable(led_colour colour);

#endif /* SRC_DRV_LED_H_ */
