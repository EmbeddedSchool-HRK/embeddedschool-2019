/*
 * startup.c
 *
 *  Created on: Nov 2, 2019
 *      Author: Herr Satan
 */
#include "startup.h"
#include "driver_LEDs.h"
#include "main.h"

void Startup (int startup){
	for(ledlist_t led_name = 0; led_name < LED_AMOUNT; led_name++){
	Led_On(led_name);
	}
	HAL_Delay(startup);
	for(ledlist_t led_name = 0; led_name < LED_AMOUNT; led_name++){
	Led_Off(led_name);
	}
}
