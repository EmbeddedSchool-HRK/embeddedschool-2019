/*
 * drvButtons.c
 *
 *  Created on: Nov 22, 2019
 *      Author: S1ckret
 */

#include "main.h"

#include "drvButtons.h"
#include "ulSysTime.h"

typedef enum
{
	StateIsPressed,
	StateIsReleased,
} button_state_t;

typedef struct
{
	GPIO_TypeDef* Port;
	uint16_t Pin;
	button_state_t State;
	uint32_t startTime;
} Button_t;

static Button_t buttons[BUTTON_COUNT] =
{
	{SWT4_GPIO_Port, SWT4_Pin, StateIsPressed},	// Up
	{SWT5_GPIO_Port, SWT5_Pin, StateIsPressed},	// Down
	{SWT3_GPIO_Port, SWT3_Pin, StateIsPressed},	// Left
	{SWT1_GPIO_Port, SWT1_Pin, StateIsPressed},	// Right
};

uint8_t drvButton_isPressed(button_name_t button_name)
{
	return !HAL_GPIO_ReadPin(buttons[button_name].Port, buttons[button_name].Pin);
}

uint8_t drvButton_isPressedForTime(button_name_t button_name, uint32_t period)
{

	button_state_t* currentState = &buttons[button_name].State;
	button_state_t nextState = *currentState;

	uint32_t* startTime = &buttons[button_name].startTime;

	uint8_t returnValue = 0;

	switch (*currentState)
	{
	case StateIsPressed:
		if (drvButton_isPressed(button_name))
		{
			nextState = StateIsReleased;
			*startTime = ulSysTime_GetCurrentTime();
		}
		break;
	case StateIsReleased:
		if (!(drvButton_isPressed(button_name)))
		{
			if (ulSysTime_IsItTime(*startTime, period))
			{
				nextState = StateIsPressed;
				returnValue = 1;
			}
		}
		break;
	default:
		nextState = StateIsPressed;
		break;
	}

	*currentState = nextState;
	return returnValue;

	return 0;
}
