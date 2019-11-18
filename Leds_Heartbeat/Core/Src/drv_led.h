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
}led_colours;

void Leds_activation(led_colours colour);
void Leds_disable(led_colours colour);

#endif /* SRC_DRV_LED_H_ */
