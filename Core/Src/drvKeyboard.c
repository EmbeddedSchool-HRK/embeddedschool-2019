/*
 * drvButtons.c
 *
 *  Created on: Dec 25, 2019
 *      Author: S1ckret
 */


#include "drvKeyboard.h"

#include "main.h"

#define COUNTER_MIN_VALUE 5
#define COUNTER_MAX_VALUE 200
#define COUNTER_PRESSED_VALUE 180
#define COUNTER_RELEASED_VALUE 25

typedef struct
{
	uint8_t Counter;
	drvKeyboard_state_t State;
	GPIO_TypeDef* Port;
	uint16_t Pin;
} key_t;

static key_t keyboard[KEY_COUNT] =
{
	{COUNTER_MIN_VALUE, KEY_RELEASED, SW1_GPIO_Port, SW1_Pin},
	{COUNTER_MIN_VALUE, KEY_RELEASED, SW2_GPIO_Port, SW2_Pin},
	{COUNTER_MIN_VALUE, KEY_RELEASED, SW3_GPIO_Port, SW3_Pin},
	{COUNTER_MIN_VALUE, KEY_RELEASED, SW4_GPIO_Port, SW4_Pin},
	{COUNTER_MIN_VALUE, KEY_RELEASED, SW5_GPIO_Port, SW5_Pin}
};

static drvKeyboard_callback_t ptrCallback = NULL;

static void notify(drvKeyboard_key_t key);

drvKeyboard_state_t drvKeyboard_getKeyState(drvKeyboard_key_t key)
{
	return keyboard[key].State;
}

void drvKeyboard_update()
{
	for (uint8_t i = 0; i < KEY_COUNT; ++i)
	{
		uint8_t pinState = HAL_GPIO_ReadPin(keyboard[i].Port
				, keyboard[i].Pin);
		if (pinState)
		{
			--keyboard[i].Counter;
		}
		else
		{
			++keyboard[i].Counter;
		}

		if (keyboard[i].Counter > COUNTER_MAX_VALUE)
		{
			keyboard[i].Counter = COUNTER_MAX_VALUE;
		}
		else if (keyboard[i].Counter < COUNTER_MIN_VALUE)
		{
			keyboard[i].Counter = COUNTER_MIN_VALUE;
		}

		if ((keyboard[i].State == KEY_RELEASED)
				&& (keyboard[i].Counter == COUNTER_PRESSED_VALUE))
		{
			keyboard[i].State = KEY_PRESSED;
			notify(i);
		}
		else if ((keyboard[i].State == KEY_PRESSED)
				&& (keyboard[i].Counter == COUNTER_RELEASED_VALUE))
		{
			keyboard[i].State = KEY_RELEASED;
			notify(i);
		}
	}
}

void drvKeyboard_registerCallback(drvKeyboard_callback_t ptr_callback)
{
	ptrCallback = ptr_callback;
}

static void notify(drvKeyboard_key_t key)
{
	ptrCallback(key);
}
