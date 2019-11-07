/*
 * drvLeds.h
 *
 *  Created on: 6 нояб. 2019 г.
 *      Author: Win10Pro
 */

#ifndef DRVLEDS_H_
#define DRVLEDS_H_

typedef enum {
  LED_GREEN,
  LED_RED,
  LED_AMOUNT
}ledsList_t;

void drvLeds_on(ledsList_t ledName);

void drvLeds_off(ledsList_t ledName);

#endif /* DRVLEDS_H_ */
