/*
 * heartbeat_module.c
 *
 *  Created on: 19 нояб. 2019 г.
 *      Author: vit
 */
#include "heartbeat_module.h"
#include "main.h"
#include "drv_led.h"

led_colour mass[Counter] =
{
		Led_Green,
		Led_Orange,
		Led_Red,
		Led_Blue,
};

void heartbeat_moving(int duty_cycle){
	for(led_colour colour = 0; colour < Counter; colour++){
		  Leds_activation(mass[colour]);
		  HAL_Delay(duty_cycle);
		  Leds_disable(mass[colour]);
		  HAL_Delay(duty_cycle);
}
}
void all_leds_blinking(int dual_duty_cycle){
	for(led_colour colour = 0; colour < Counter; colour++){
	Leds_activation(colour);
		}

	HAL_Delay(dual_duty_cycle);
	for(led_colour colour = 0; colour < Counter; colour++){
	Leds_disable(colour);
		}
}


