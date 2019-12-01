/*
 * heartbeat.c
 *
 *  Created on: Nov 25, 2019
 *      Author: Slavon
 */
 
#include "rainbow.h"

void rainbow(time_t pulse_delay){
drvLeds_ON(LED_BLUE);
HAL_Delay(pulse_delay);
drvLeds_OFF(LED_BLUE);
drvLeds_ON(LED_GREEN);
HAL_Delay(pulse_delay);
drvLeds_OFF(LED_GREEN);	
drvLeds_ON(LED_ORANGE);
HAL_Delay(pulse_delay);
drvLeds_OFF(LED_ORANGE);
}