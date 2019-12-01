/*
 * heartbeat.c
 *
 *  Created on: Nov 25, 2019
 *      Author: Slavon
 */

#include "heartbeat.h"

void heartbeat(time_t Duty_Cycle, time_t period){
drvLeds_ON(LED_RED);
HAL_Delay(Duty_Cycle);
drvLeds_OFF(LED_RED);
HAL_Delay(period-Duty_Cycle);	
}			
