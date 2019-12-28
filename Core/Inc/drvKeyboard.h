/*
 * drvButtons.h
 *
 *  Created on: Dec 25, 2019
 *      Author: S1ckret
 */

#ifndef INC_DRVKEYBOARD_H_
#define INC_DRVKEYBOARD_H_

typedef enum
{
	KEY_RELEASED,
	KEY_PRESSED
} drvKeyboard_state_t;

typedef enum
{
	KEY_RIGHT,
	KEY_MIDDLE,
	KEY_LEFT,
	KEY_UP,
	KEY_DOWN,
	KEY_COUNT
} drvKeyboard_key_t;

typedef void (*drvKeyboard_callback_t)(drvKeyboard_key_t);

drvKeyboard_state_t drvKeyboard_getKeyState(drvKeyboard_key_t key);

void drvKeyboard_update();

void drvKeyboard_registerCallback(drvKeyboard_callback_t ptr_callback);

#endif /* INC_DRVKEYBOARD_H_ */
