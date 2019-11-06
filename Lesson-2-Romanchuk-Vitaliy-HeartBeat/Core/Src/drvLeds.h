/*
 * drvLeds.h
 *
 *  Created on: Nov 5, 2019
 *      Author: TheKeeper
 */

#ifndef SRC_DRVLEDS_H_
#define SRC_DRVLEDS_H_

typedef enum {
  LED_Orange,
  LED_Blue,
  LED_Green,
  Led_Red
}leds_t;
void drvLeds_on(leds_t ledName);

void drvLeds_off(leds_t ledName);

#endif /* SRC_DRVLEDS_H_ */
