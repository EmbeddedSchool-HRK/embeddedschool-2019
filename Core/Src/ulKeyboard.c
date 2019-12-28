/*
 * ulKeyboard.c
 *
 *  Created on: 28 дек. 2019 г.
 *      Author: S1ckret
 */

#include "ulKeyboard.h"
#include "drvKeyboard.h"
#include "drvLeds.h"

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

static void handler(drvKeyboard_key_t key)
{
	drvKeyboard_state_t keyState = drvKeyboard_getKeyState(key);
	led_color_t led = getLedName(key);

	if (key != KEY_MIDDLE)
	{
		if (keyState == KEY_PRESSED)
		{
			drvLed_on(led);
		}
		else
		{
			drvLed_off(led);
		}
	}
	else if (drvKeyboard_getKeyState(KEY_MIDDLE) == KEY_PRESSED)
	{
		drvLed_onAll();
	}
	else
	{
		drvLed_offAll();
	}
}

void ulKeyboard_init()
{
	drvKeyboard_registerCallback(handler);
}
