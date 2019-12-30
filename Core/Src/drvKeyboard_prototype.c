/*
 * drvKeyboard_prototype.c
 *
 *  Created on: 29 дек. 2019 г.
 *      Author: S1ckret
 */

#include "drvKeyboard_prototype.h"

#include "PrivateDefines.h"
#include "ulSysTime.h"

#define DEBOUNCE_DELAY 5
#define LONG_PRESS_DELAY 1500
#define SHORT_PRESS_DELAY 100

typedef enum
{
	STATE_START = 0,
	STATE_DEBOUNCE,
	STATE_PRESSED,
	STATE_WAIT_TILL_RELEASED
} key_state_t;

typedef struct
{
	key_state_t PhysicalState;
	drvKeyboard_P_keyState_t LogicalState;
	drvKeyboard_P_callback_t PtrCallback;
	uint32_t StartTime;						// Time when button is pressed.
	uint8_t Trigger; 						// Expected value from GPIO when button is pressed
	GPIO_TypeDef* Port;
	uint16_t Pin;
} key_t;

static key_t keyboard[KEY_COUNT] =
{
	{STATE_START, KEY_STATE_RELEASED, NULL, 0, 0, SWT1_GPIO_Port, SWT1_Pin},	/* RIGHT  */
	{STATE_START, KEY_STATE_RELEASED, NULL, 0, 0, SWT2_GPIO_Port, SWT2_Pin},	/* MIDDLE */
	{STATE_START, KEY_STATE_RELEASED, NULL, 0, 0, SWT3_GPIO_Port, SWT3_Pin},	/* LEFT	  */
	{STATE_START, KEY_STATE_RELEASED, NULL, 0, 0, SWT4_GPIO_Port, SWT4_Pin},	/* UP	  */
	{STATE_START, KEY_STATE_RELEASED, NULL, 0, 0, SWT5_GPIO_Port, SWT5_Pin},	/* DOWN	  */
};

static void notify(drvKeyboard_P_keyName_t key, drvKeyboard_P_keyEvent_t event);
static key_state_t releaseButton(drvKeyboard_P_keyName_t key);

static key_state_t stateStart			(key_state_t currentState, drvKeyboard_P_keyName_t key, uint8_t pinStatus);
static key_state_t stateDebounce		(key_state_t currentState, drvKeyboard_P_keyName_t key, uint8_t pinStatus);
static key_state_t statePresed			(key_state_t currentState, drvKeyboard_P_keyName_t key, uint8_t pinStatus);
static key_state_t stateWaitTillReleased(key_state_t currentState, drvKeyboard_P_keyName_t key, uint8_t pinStatus);

void drvKeyboard_P_update()
{
	for (drvKeyboard_P_keyName_t key = 0; key < KEY_COUNT; ++key)
	{
		uint8_t status = HAL_GPIO_ReadPin(keyboard[key].Port, keyboard[key].Pin);
		key_state_t currentState = keyboard[key].PhysicalState;
		key_state_t nextState = STATE_START;

		switch (currentState)
		{
		case STATE_START:
			nextState = stateStart(currentState, key, status);
			break;
		case STATE_DEBOUNCE:
			nextState = stateDebounce(currentState, key, status);
			break;
		case STATE_PRESSED:
			nextState = statePresed(currentState, key, status);
			break;
		case STATE_WAIT_TILL_RELEASED:
			nextState = stateWaitTillReleased(currentState, key, status);
			break;
		default:
			keyboard[key].LogicalState = KEY_STATE_RELEASED;
			keyboard[key].PhysicalState = STATE_START;
			break;
		}
		keyboard[key].PhysicalState = nextState;
	}
}

void drvKeyboard_P_registerCallback(drvKeyboard_P_keyName_t key,
					drvKeyboard_P_callback_t ptr_callback)
{
	keyboard[key].PtrCallback = ptr_callback;
}

drvKeyboard_P_keyState_t drvKeyboard_P_getKeyState(drvKeyboard_P_keyName_t key)
{
	return keyboard[key].LogicalState;
}

static void notify(drvKeyboard_P_keyName_t key, drvKeyboard_P_keyEvent_t event)
{
	// Try to call user's function
	if (keyboard[key].PtrCallback)
	{
		keyboard[key].PtrCallback(key, event);
	}
}

static key_state_t releaseButton(drvKeyboard_P_keyName_t key)
{
	// Start over.
	keyboard[key].LogicalState = KEY_STATE_RELEASED;
	notify(key, KEY_EVENT_RELEASED);
	return STATE_START;
}

static key_state_t stateStart(key_state_t currentState, drvKeyboard_P_keyName_t key, uint8_t pinStatus)
{
	key_state_t nextState = currentState;
	if (pinStatus == keyboard[key].Trigger)
	{
		keyboard[key].StartTime = ulSysTime_GetCurrentTime();
		nextState = STATE_DEBOUNCE;
	}
	return nextState;
}

static key_state_t stateDebounce(key_state_t currentState, drvKeyboard_P_keyName_t key, uint8_t pinStatus)
{
	key_state_t nextState = currentState;
	if (pinStatus == keyboard[key].Trigger)
	{
		if (ulSysTime_IsItTime(keyboard[key].StartTime, DEBOUNCE_DELAY))
		{
			// It was a real press.
			nextState = STATE_PRESSED;
			keyboard[key].LogicalState = KEY_STATE_PRESSED;
			notify(key, KEY_EVENT_ON_PRESS);
		}
	}
	else
	{
		// It was a bounce.
		nextState = STATE_START;
	}
	return nextState;
}

static key_state_t statePresed(key_state_t currentState, drvKeyboard_P_keyName_t key, uint8_t pinStatus)
{
	// We save pressed state to keep checking for long press.
	key_state_t nextState = currentState;
	// Check if button is still pressed.
	if (pinStatus == keyboard[key].Trigger)
	{
		// Check for long press.
		if (ulSysTime_IsItTime(keyboard[key].StartTime, LONG_PRESS_DELAY))
		{
			nextState = STATE_WAIT_TILL_RELEASED;
			notify(key, KEY_EVENT_LONG_PRESS);
		}
	}
	else
	{
		// Button is released.
		// Check for short press.
		if (ulSysTime_IsItTime(keyboard[key].StartTime, SHORT_PRESS_DELAY))
		{
			nextState = STATE_WAIT_TILL_RELEASED;
			notify(key, KEY_EVENT_SHORT_PRESS);
		}
		else
		{
			// Too small press delay.
			nextState = releaseButton(key);
		}
	}
	return nextState;
}

static key_state_t stateWaitTillReleased(key_state_t currentState, drvKeyboard_P_keyName_t key, uint8_t pinStatus)
{
	key_state_t nextState = currentState;
	if (pinStatus != keyboard[key].Trigger)
	{
		nextState = releaseButton(key);
	}
	return nextState;
}
