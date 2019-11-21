/*
 * drvLeds.h
 *
 *  Created on: Nov 14, 2019
 *      Author: Slavon
 */

#include "stdint.h"
#include "main.h"

#ifndef SRC_DRVLEDS_H_
#define SRC_DRVLEDS_H_

typedef enum {
	LED_RED,
	LED_GREEN,
	LED_ORANGE,
	LED_BLUE,
	LED_AMOUNT
} list_t;

typedef struct{
	GPIO_TypeDef* port;
	uint16_t pin;
}type_t;

void drvLeds_ON(list_t ledName);

void drvLeds_OFF(list_t ledName);

#endif /* SRC_DRVLEDS_H_ */
