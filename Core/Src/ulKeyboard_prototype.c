/*
 * ulKeyboard_prototype.c
 *
 *  Created on: 30 дек. 2019 г.
 *      Author: S1ckret
 */

#include "ulKeyboard_prototype.h"
#include "drvKeyboard_prototype.h"
#include "drvLeds.h"

static void controllBlueLed(drvKeyboard_P_keyName_t key, drvKeyboard_P_keyEvent_t event);
static void controllAllLeds(drvKeyboard_P_keyName_t key, drvKeyboard_P_keyEvent_t event);
static void controllOrangeLed(drvKeyboard_P_keyName_t key, drvKeyboard_P_keyEvent_t event);
static void controllRedLed(drvKeyboard_P_keyName_t key, drvKeyboard_P_keyEvent_t event);
static void controllGreenLed(drvKeyboard_P_keyName_t key, drvKeyboard_P_keyEvent_t event);

void ulKeyboard_P_init()
{
	drvKeyboard_P_registerCallback(KEY_RIGHT, 	controllBlueLed);
	drvKeyboard_P_registerCallback(KEY_MIDDLE, 	controllAllLeds);
	drvKeyboard_P_registerCallback(KEY_LEFT, 	controllOrangeLed);
	drvKeyboard_P_registerCallback(KEY_UP, 		controllRedLed);
	drvKeyboard_P_registerCallback(KEY_DOWN, 	controllGreenLed);
}

static void controllBlueLed(drvKeyboard_P_keyName_t key, drvKeyboard_P_keyEvent_t event)
{
	if (event == KEY_EVENT_ON_PRESS)
	{
		drvLed_on(LED_BLUE);
	}
	else if (event == KEY_EVENT_RELEASED)
	{
		drvLed_off(LED_BLUE);
	}
}

static void controllAllLeds(drvKeyboard_P_keyName_t key, drvKeyboard_P_keyEvent_t event)
{
	if (event == KEY_EVENT_ON_PRESS)
	{
		drvLed_onAll();
	}
	else if (event == KEY_EVENT_RELEASED)
	{
		drvLed_offAll();
	}
}

static void controllOrangeLed(drvKeyboard_P_keyName_t key, drvKeyboard_P_keyEvent_t event)
{
	if (event == KEY_EVENT_ON_PRESS)
	{
		drvLed_on(LED_ORANGE);
	}
	else if (event == KEY_EVENT_RELEASED)
	{
		drvLed_off(LED_ORANGE);
	}
}

static void controllRedLed(drvKeyboard_P_keyName_t key, drvKeyboard_P_keyEvent_t event)
{
	if (event == KEY_EVENT_ON_PRESS)
	{
		drvLed_on(LED_RED);
	}
	else if (event == KEY_EVENT_RELEASED)
	{
		drvLed_off(LED_RED);
	}
}

static void controllGreenLed(drvKeyboard_P_keyName_t key, drvKeyboard_P_keyEvent_t event)
{
	if (event == KEY_EVENT_ON_PRESS)
	{
		drvLed_on(LED_GREEN);
	}
	else if (event == KEY_EVENT_RELEASED)
	{
		drvLed_off(LED_GREEN);
	}
}




