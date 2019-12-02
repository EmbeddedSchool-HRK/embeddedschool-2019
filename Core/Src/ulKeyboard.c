/*
 * ulKeyboard.c
 *
 *  Created on: Dec 2, 2019
 *      Author: AllSE
 */

#include "ulKeyboard.h"
#include "drvKeyboard.h"
#include "drvLEDs.h"

static LedList_t glueTable[LED_AMOUNT] = {
  LED_Red,
  LED_Green,
  LED_Orange,
  LED_Blue
};

void handler(drvKeyboard_Key_t keyName, drvKeyboardState_t event);

void ulKeyboard_init(){
  drvKeyboard_RegisterCallback(handler);
}

void handler(drvKeyboard_Key_t keyName, drvKeyboardState_t event){
  if(keyName != KEY_CENTER){
    if(event == KEY_PRESSED){
      drvLEDs_On(glueTable[keyName]);
    }
    else{
      drvLEDs_Off(glueTable[keyName]);
    }
  }
  else{
    if(event == KEY_PRESSED){
      drvLEDs_On(LED_Red);
      drvLEDs_On(LED_Green);
      drvLEDs_On(LED_Orange);
      drvLEDs_On(LED_Blue);
    }
    else{
      drvLEDs_Off(LED_Red);
      drvLEDs_Off(LED_Green);
      drvLEDs_Off(LED_Orange);
      drvLEDs_Off(LED_Blue);
    }
  }
}

