/*
 * heartbeat.c
 *
 *  Created on: Nov 2, 2019
 *      Author: Herr Satan
 */

#include "heartbeat.h"
#include "driver_LEDs.h"
#include "main.h"

void Heartbeat (ledlist_t color, int period, int duty_cycle){
  Led_On(color);
  HAL_Delay(duty_cycle);
  Led_Off(color);
  HAL_Delay(period-duty_cycle);
}
