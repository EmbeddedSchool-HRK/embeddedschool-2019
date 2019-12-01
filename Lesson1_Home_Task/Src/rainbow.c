/*
 * heartbeat.c
 *
 *  Created on: Nov 25, 2019
 *      Author: Slavon
 */
 
#include "rainbow.h"

void rainbow(time_t pulse_delay, list_t led[], int leds_number){
for( int i=0; i<=leds_number; i++)
{	
drvLeds_ON(led[i]);
HAL_Delay(pulse_delay);
drvLeds_OFF(led[i]);
}
}
