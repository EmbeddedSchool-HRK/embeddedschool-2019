/*
 * drvKeyboard.h
 *
 *  Created on: 2 дек. 2019 г.
 *      Author: AllSE
 */

#ifndef SRC_DRVKEYBOARD_H_
#define SRC_DRVKEYBOARD_H_

typedef enum{
  KEY_RELEASED,
  KEY_PRESSED
} drvKeyboardState_t;

typedef enum{
  KEY_UP,
  KEY_DOWN,
  KEY_LEFT,
  KEY_RIGHT,
  KEY_CENTER,
  KEY_NUMBER
}drvKeyboard_Key_t;

typedef void (*callback_t) (drvKeyboard_Key_t keyName, drvKeyboardState_t event);

drvKeyboardState_t drvKeyboard_getKeyState(drvKeyboard_Key_t keyName);

void drvKeyboard_RegisterCallback(callback_t callback);

void drvKeyboard_run();

#endif /* SRC_DRVKEYBOARD_H_ */
