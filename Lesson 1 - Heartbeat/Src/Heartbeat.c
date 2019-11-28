/*
 * Heartbeat.c
 *
 *  Created on: 14 лист. 2019 р.
 *      Author: Local user Profile
 */

#include "Heartbeat.h"
#include "drvLED.h"

void Heartbeat(uint16_t pulsewidth, uint16_t period){
    uint16_t delay = period - pulsewidth;
    drvLED_on(LED_Red);
    HAL_Delay(pulsewidth);
    drvLED_off(LED_Red);
    HAL_Delay(delay);
}
