/*
 * drvButtons.h
 *
 *  Created on: Nov 22, 2019
 *      Author: S1ckret
 */

#ifndef INC_DRVBUTTONS_H_
#define INC_DRVBUTTONS_H_

#include <stdint.h>

typedef enum
{
	BUTTON_UP,
	BUTTON_DOWN,
	BUTTON_LEFT,
	BUTTON_RIGHT,
	BUTTON_COUNT
} button_name_t;

uint8_t drvButton_isPressed(button_name_t button_name);


#endif /* INC_DRVBUTTONS_H_ */
