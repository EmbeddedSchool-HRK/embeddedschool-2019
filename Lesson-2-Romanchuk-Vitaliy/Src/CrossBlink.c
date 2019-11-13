/*
 *
 *
 *	CrossBlink.c
 *	
 *	Autor: Romanchuk.Vitaliy
 *	
 *
 *
 */

#include "main.h"
#include "stdint.h"
#include "drv_LEDs.h"
#include "CrossBlink.h"

uint16_t ArLEDs[] = {
 LED_Blue,  LED_Green, LED_Red,
 LED_Red,   LED_Blue,  LED_Green,
 LED_Green, LED_Red,   LED_Blue
};

int ArLEDsSize = sizeof(ArLEDs) / sizeof(uint16_t);

void lcb_func(uint32_t period, uint32_t dutycycle) {
 for (int i = 0; i < ArLEDsSize; i++) {
 drvLeds_on(ArLEDs[i]);
 HAL_Delay(dutycycle);
 drvLeds_off(ArLEDs[i]);
 HAL_Delay(period - dutycycle);
}
}