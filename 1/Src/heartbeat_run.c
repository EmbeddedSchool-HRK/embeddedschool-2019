/*
 * heartbeat_run.c
 *
 *  Created on: Nov 2, 2019
 *      Author: Herr Satan
 */
#include "driver_LEDs.h"
#include "heartbeat_run.h"
#include "main.h"

void Heartbeat_Run (int duty_cycle){
  Led_On(LED_ORANG);
  HAL_Delay(duty_cycle);
  Led_Off(LED_ORANG);
  Led_On(LED_BLUE);
  HAL_Delay(duty_cycle);
  Led_Off(LED_BLUE);
  Led_On(LED_GREEN);
  HAL_Delay(duty_cycle);
  Led_Off(LED_GREEN);
  Led_On(LED_RED);
  HAL_Delay(duty_cycle);
  Led_Off(LED_RED);
}
