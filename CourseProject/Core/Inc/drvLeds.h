/*
 * drvLeds.h
 *
 *  Created on: 30 нояб. 2019 г.
 *      Author: user
 */

#ifndef INC_DRVLEDS_H_
#define INC_DRVLEDS_H_
#include "stm32f4xx.h"
#include "stm32f4xx_hal_gpio.h"

typedef enum{
	LED_ORANGE,
	LED_BLUE,
	LED_GREEN,
	LED_RED,
	LED_AMOUNT
}ledlist_t;


void drvLeds_on(ledlist_t SelectedLed);

void drvLeds_off(ledlist_t SelectedLed);


#endif /* INC_DRVLEDS_H_ */
