/*
 * drvKeyboard.c
 *
 *  Created on: 2 дек. 2019 г.
 *      Author: AllSE
 */


#include "drvKeyboard.h"
#include "stdint.h"
#include "stm32f4xx_hal.h"

#define COUNTER_MIN_VALUE 5
#define COUNTER_MAX_VALUE 200
#define COUNTER_PRESSED_VALUE 180
#define COUNTER_RELEASED_VALUE 20

typedef struct{
  uint8_t counter;
  drvKeyboardState_t state;
  GPIO_TypeDef* port;
  uint16_t pin;
}Key_t;

static callback_t ptrCallback = NULL;

static Key_t Keyboard [KEY_NUMBER] = {
              //counter             state         Port   Pin
/*KEY_UP*/      {COUNTER_MIN_VALUE, KEY_RELEASED, GPIOC, GPIO_PIN_6},
/*KEY_DOWN*/    {COUNTER_MIN_VALUE, KEY_RELEASED, GPIOC, GPIO_PIN_8},
/*KEY_LEFT*/    {COUNTER_MIN_VALUE, KEY_RELEASED, GPIOC, GPIO_PIN_9},
/*KEY_RIGHT*/   {COUNTER_MIN_VALUE, KEY_RELEASED, GPIOC, GPIO_PIN_11},
/*KEY_CENTER*/  {COUNTER_MIN_VALUE, KEY_RELEASED, GPIOA, GPIO_PIN_15}
};

void notyfy(drvKeyboard_Key_t keyName, drvKeyboardState_t event);

void drvKeyboard_RegisterCallback(callback_t callback){
  ptrCallback = callback;
}

drvKeyboardState_t drvKeyboard_getKeyState(drvKeyboard_Key_t keyName){
  return Keyboard[keyName].state;
}

void drvKeyboard_run(){
  for (drvKeyboard_Key_t Key = 0; Key < KEY_NUMBER; Key++){
    uint8_t pinState = HAL_GPIO_ReadPin(Keyboard[Key].port, Keyboard[Key].pin);
    if (pinState){
      Keyboard[Key].counter--;
    }
    else{
      Keyboard[Key].counter++;
    }
    if (Keyboard[Key].counter > COUNTER_MAX_VALUE) {
      Keyboard[Key].counter = COUNTER_MAX_VALUE;
    }
    if (Keyboard[Key].counter < COUNTER_MIN_VALUE) {
      Keyboard[Key].counter = COUNTER_MIN_VALUE;
    }
    if ((Keyboard[Key].counter == COUNTER_PRESSED_VALUE) && (Keyboard[Key].state == KEY_RELEASED)){
      Keyboard[Key].state = KEY_PRESSED;
      notyfy(Key, KEY_PRESSED);
    }
    if ((Keyboard[Key].counter == COUNTER_RELEASED_VALUE) && (Keyboard[Key].state == KEY_PRESSED)){
      Keyboard[Key].state = KEY_RELEASED;
      notyfy(Key, KEY_RELEASED);
    }
  }
}

void notyfy(drvKeyboard_Key_t keyName, drvKeyboardState_t event){
  ptrCallback(keyName, event);
}
