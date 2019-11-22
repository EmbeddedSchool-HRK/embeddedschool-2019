/*
 * drvButtons.h
 *
 *  Created on: Nov 22, 2019
 *      Author: S1ckret
 */

#ifndef INC_DRVBUTTONS_H_
#define INC_DRVBUTTONS_H_

#include <stdint.h>

#define BUTTON_PRESS_TIME_SHORT 40
#define BUTTON_PRESS_TIME_LONG 300
#define BUTTON_PRESS_TIME_VERY_LONG 700
#define BUTTON_PRESS_TIME_1S 1000ul
#define BUTTON_PRESS_TIME_2S 2000ul

typedef enum
{
	BUTTON_UP,
	BUTTON_DOWN,
	BUTTON_LEFT,
	BUTTON_RIGHT,
	BUTTON_COUNT
} button_name_t;

uint8_t drvButton_isPressed(button_name_t button_name);

uint8_t drvButton_isPressedForTime(button_name_t button_name, uint32_t period);


#endif /* INC_DRVBUTTONS_H_ */
