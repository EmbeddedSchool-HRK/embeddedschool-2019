/*
 * drvButtons.c
 *
 *  Created on: Nov 22, 2019
 *      Author: S1ckret
 */

#include "main.h"

#include "drvButtons.h"

typedef struct
{
	GPIO_TypeDef* Port;
	uint16_t Pin;
} Button_t;

static Button_t buttons[BUTTON_COUNT] =
{
	{SWT4_GPIO_Port, SWT4_Pin},	// Up
	{SWT5_GPIO_Port, SWT5_Pin},	// Down
	{SWT3_GPIO_Port, SWT3_Pin},	// Left
	{SWT1_GPIO_Port, SWT1_Pin},	// Right
};

uint8_t drvButton_isPressed(button_name_t button_name)
{
	return !HAL_GPIO_ReadPin(buttons[button_name].Port, buttons[button_name].Pin);
}

