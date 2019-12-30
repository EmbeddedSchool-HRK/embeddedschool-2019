/*
 * drvKeyboard_P.h
 *
 *  Created on: 29 дек. 2019 г.
 *      Author: S1ckret
 */

#ifndef INC_DRVKEYBOARD_PROTOTYPE_H_
#define INC_DRVKEYBOARD_PROTOTYPE_H_

//////////////////////////////////
/* 		PROTOTYPE MODULE		*/
//////////////////////////////////

/* P means prototype */

typedef enum
{
	KEY_STATE_RELEASED,
	KEY_STATE_PRESSED
} drvKeyboard_P_keyState_t;

typedef enum
{
	KEY_EVENT_ON_PRESS, 	/*Pressed just in the beginning after the debounce*/
	KEY_EVENT_SHORT_PRESS,  /*Pressed after short time*/
	KEY_EVENT_LONG_PRESS, 	/*Pressed after long time*/
	KEY_EVENT_RELEASED 		/*When key is released*/
} drvKeyboard_P_keyEvent_t;

typedef enum
{
	KEY_RIGHT,
	KEY_MIDDLE,
	KEY_LEFT,
	KEY_UP,
	KEY_DOWN,
	KEY_COUNT
} drvKeyboard_P_keyName_t;

// Callback function
typedef void (*drvKeyboard_P_callback_t)(drvKeyboard_P_keyName_t key, drvKeyboard_P_keyEvent_t event);

void drvKeyboard_P_update();

void drvKeyboard_P_registerCallback(drvKeyboard_P_keyName_t key, drvKeyboard_P_callback_t ptr_callback);

drvKeyboard_P_keyState_t drvKeyboard_P_getKeyState(drvKeyboard_P_keyName_t key);


#endif /* INC_DRVKEYBOARD_PROTOTYPE_H_ */
