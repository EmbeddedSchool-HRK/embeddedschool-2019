/*
 *
 *
 *	drv_LEDs.h
 *
 *	Author: Romanchuk.Vitaliy
 *	
 *
 */

#ifndef SRC_DRV_LEDS_H_
#define SRC_DRV_LEDS_H_

#include "main.h"
#include "stdint.h"

typedef enum { LED_Orange, LED_Blue, LED_Green, LED_Red, LED_Amount }ledslist_t;
void drvLeds_on(ledslist_t ledName);
void drvLeds_off(ledslist_t ledName);

#endif /* SRC_DRV_LEDS_H_ */