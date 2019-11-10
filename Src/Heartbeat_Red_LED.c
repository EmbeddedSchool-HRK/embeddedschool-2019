/*
 * Heartbeat_Red_LED.c
 *
 *  Created on: 10 нояб. 2019 г.
 *      Author: morok__
 */

#include "Drv_LEDs.h"
#include "Heartbeat_Red_LED.h"


void HeartBeat_led_Red(uint16_t DELAY) {
DrvLEDs_on(LED_RED);
HAL_Delay(DELAY);
DrvLEDs_off(LED_RED);
HAL_Delay(DELAY);
}
