/*
 * drvLeds.h
 *
 *  Created on: 3 дек. 2019 г.
 *      Author: Korpyc
 */

#ifndef DRVLEDS_H_
#define DRVLEDS_H_

typedef enum {
	LED_GREEN,
	LED_RED,
	LED_ORANGE,
	LED_BLUE,
	LED_AMOUNT
} ledsList_t;

void drvLeds_on(ledsList_t ledName);

void drveds_off(ledsList_t ledName);



#endif /* DRVLEDS_H_ */
