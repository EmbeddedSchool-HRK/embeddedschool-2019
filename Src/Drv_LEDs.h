/*
 * Drv_LEDs.h
 *
 *  Created on: 10 нояб. 2019 г.
 *      Author: morok__
 */

#ifndef DRV_LEDS_H_
#define DRV_LEDS_H_

typedef enum {
  LED_BLUE,
  LED_RED,
  LED_ORANGE,
  LED_GREEN,
  LED_COUNT
}LED_LIST;


void DrvLEDs_on(LED_LIST ledName);

void DrvLEDs_off(LED_LIST ledName);

#endif /* DRV_LEDS_H_ */
