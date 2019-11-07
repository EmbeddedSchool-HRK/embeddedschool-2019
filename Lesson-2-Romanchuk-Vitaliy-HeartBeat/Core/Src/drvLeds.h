/*
 * drvLeds.h
 *
 *  Created on: Nov 5, 2019
 *      Author: TheKeeper
 */

#ifndef SRC_DRVLEDS_H_
#define SRC_DRVLEDS_H_

#include "main.h"

typedef enum {
  LED_Orange,
  LED_Blue,
  LED_Green,
  LED_Red,
  LED_Amount
}ledslist_t;
void drvLeds_on(ledslist_t ledName);
void drvLeds_off(ledslist_t ledName);

#endif /* SRC_DRVLEDS_H_ */
