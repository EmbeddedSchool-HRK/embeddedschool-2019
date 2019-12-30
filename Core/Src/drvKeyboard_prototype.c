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

void drvKeyboard_P_update()
{
	for (drvKeyboard_P_keyName_t key = 0; key < KEY_COUNT; ++key)
	{
		uint8_t status = HAL_GPIO_ReadPin(keyboard[key].Port, keyboard[key].Pin);

		switch (keyboard[key].PhysicalState)
		{
		case STATE_START:
		{
			if (status == keyboard[key].Trigger)
			{
				keyboard[key].StartTime = ulSysTime_GetCurrentTime();
				keyboard[key].PhysicalState = STATE_DEBOUNCE;
			}
		}
			break;
		case STATE_DEBOUNCE:
		{
			if (status == keyboard[key].Trigger)
			{
				if (ulSysTime_IsItTime(keyboard[key].StartTime, DEBOUNCE_DELAY))
				{
					// It was a real press.
					keyboard[key].PhysicalState = STATE_PRESSED;
					keyboard[key].LogicalState = KEY_STATE_PRESSED;
					// Try to call user's function
					if (keyboard[key].PtrCallback)
					{
						keyboard[key].PtrCallback(key, KEY_EVENT_ON_PRESS);
					}
				}
			}
			else
			{
				// It was bounce. Start over.
				keyboard[key].PhysicalState = STATE_START;
			}
		}
			break;
		case STATE_PRESSED:
		{
			// Check if button is still pressed.
			if (status == keyboard[key].Trigger)
			{
				// Check for long press.
				if (ulSysTime_IsItTime(keyboard[key].StartTime, LONG_PRESS_DELAY))
				{
					keyboard[key].PhysicalState = STATE_WAIT_TILL_RELEASED;
					// Try to call user's function
					if (keyboard[key].PtrCallback)
					{
						keyboard[key].PtrCallback(key, KEY_EVENT_LONG_PRESS);
					}
				}
			}
			else
			{
				// Button is released.
				// Check for short press.
				if (ulSysTime_IsItTime(keyboard[key].StartTime, SHORT_PRESS_DELAY))
				{
					keyboard[key].PhysicalState = STATE_WAIT_TILL_RELEASED;
					// Try to call user's function
					if (keyboard[key].PtrCallback)
					{
						keyboard[key].PtrCallback(key, KEY_EVENT_SHORT_PRESS);
					}
				}
				else
				{
					// Too small press delay.
					// Button is released.
					// Start over.
					keyboard[key].PhysicalState = STATE_START;
					keyboard[key].LogicalState = KEY_STATE_RELEASED;
					// Try to call user's function
					if (keyboard[key].PtrCallback)
					{
						keyboard[key].PtrCallback(key, KEY_EVENT_RELEASED);
					}

				}
			}
		}
			break;
		case STATE_WAIT_TILL_RELEASED:
		{
			if (status != keyboard[key].Trigger)
			{
				// Button is released. Start over.
				keyboard[key].PhysicalState = STATE_START;
				keyboard[key].LogicalState = KEY_STATE_RELEASED;
				// Try to call user's function
				if (keyboard[key].PtrCallback)
				{
					keyboard[key].PtrCallback(key, KEY_EVENT_RELEASED);
				}
			}
		}
			break;
		default:
			keyboard[key].LogicalState = KEY_STATE_RELEASED;
			keyboard[key].PhysicalState = STATE_START;
			break;
		}
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
