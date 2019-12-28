/*
 * ulKeyboard.c
 *
 *  Created on: 28 дек. 2019 г.
 *      Author: S1ckret
 */

#include "drvKeyboard.h"
#include "ulKeyboard.h"
#include "drvLeds.h"

#include <stdint.h>

static led_color_t getLedName(drvKeyboard_key_t key)
{
	led_color_t returnValue = LED_GREEN;
	switch(key)
	{
	case KEY_RIGHT: returnValue = LED_BLUE;
		break;
	case KEY_LEFT: returnValue = LED_ORANGE;
		break;
	case KEY_UP: returnValue = LED_RED;
		break;
	case KEY_DOWN: returnValue = LED_GREEN;
		break;
	default:
		break;
	}
	return returnValue;
}

void ulKeyboard_update()
{
	uint8_t isAnyKeyPressed = 0;
	for (drvKeyboard_key_t key = 0; key < KEY_COUNT; ++key)
	{
		drvKeyboard_state_t keyState = drvKeyboard_getKeyState(key);
		led_color_t led = getLedName(key);

		if (key != KEY_MIDDLE)
		{
			if (keyState == KEY_PRESSED)
			{
				drvLed_on(led);
				isAnyKeyPressed = 1;
			}
			else
			{
				drvLed_off(led);
			}
		}
	}

	if (drvKeyboard_getKeyState(KEY_MIDDLE) == KEY_PRESSED)
	{
		drvLed_onAll();
	}
	else if (!isAnyKeyPressed)
	{
		drvLed_offAll();
	}

}
