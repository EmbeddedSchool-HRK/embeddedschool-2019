/*
 *
 *
 * HeartBeat.c
 * 
 * Autor: Romanchuk.Vitaliy
 *
 *
 */
#include "main.h"
#include "stdint.h"
#include "drv_LEDs.h"
#include "HeartBeat.h"

void hb_ol(uint32_t period, uint32_t dutycycle) {
 drvLeds_on(LED_Orange);
 HAL_Delay(dutycycle);
 drvLeds_off(LED_Orange);
 HAL_Delay(period - dutycycle);
}
