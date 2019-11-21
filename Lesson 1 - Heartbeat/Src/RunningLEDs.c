/*
 * RunningLEDs.c
 *
 *  Created on: 21 лист. 2019 р.
 *      Author: Local user Profile
 */

#include "RunningLEDs.h"
#include "drvLED.h"

void LEDsRun(uint16_t delay){
    for (uint8_t i = 0; i < LED_Count; i++)
    {
        drvLED_on(i);
        HAL_Delay(delay);
        drvLED_off(i);
        HAL_Delay(delay);
    }

}
