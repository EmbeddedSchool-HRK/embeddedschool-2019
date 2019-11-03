/*
 * heartbeat_run.c
 *
 *  Created on: Nov 2, 2019
 *      Author: Herr Satan
 */
#include "driver_LEDs.h"
#include "heartbeat_run.h"
#include "main.h"

ledlist_t scenario[LED_AMOUNT] = {LED_ORANG,LED_GREEN,LED_RED,LED_BLUE};

void Heartbeat_Run (int duty_cycle){
  for(ledlist_t led_name = 0; led_name < LED_AMOUNT; led_name++)
    {
	  Led_On(scenario[led_name]);
	  HAL_Delay(duty_cycle);
	  Led_Off(scenario[led_name]);
    }
}