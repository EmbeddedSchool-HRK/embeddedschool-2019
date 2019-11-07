/*
 * DrvLEDs.h
 *
 *  Created on: Nov 7, 2019
 *      Author: morok__
 */

#ifndef DRVLEDS_H_
#define DRVLEDS_H_

typedef enum {
  LED_BLUE,
  LED_RED,
  LED_ORANGE,
  LED_GREEN,
  LED_COUNT
}LED_LIST;


void DrvLEDs_on(LED_LIST ledName);

void DrvLEDs_off(LED_LIST ledName);

#endif /* DRVLEDS_H_ */
