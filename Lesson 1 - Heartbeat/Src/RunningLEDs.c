/*
 * RunningLEDs.c
 *
 *  Created on: 21 лист. 2019 р.
 *      Author: Local user Profile
 */

#include "RunningLEDs.h"
#include "drvLED.h"

void LEDsRun(uint16_t delay, ledlist_t LED_array[], uint16_t steps){
    for (uint8_t i = 0; i <= steps; i++)
    {
        drvLED_on(LED_array[i]);
        HAL_Delay(delay);
        drvLED_off(LED_array[i]);
        HAL_Delay(delay);
    }

}
