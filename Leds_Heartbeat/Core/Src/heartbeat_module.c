/*
 * heartbeat_module.c
 *
 *  Created on: 19 нояб. 2019 г.
 *      Author: vit
 */
#include "heartbeat_module.h"
#include "main.h"
#include "drv_led.h"

void heartbeat_moving(int duty_cycle){
	Leds_activation(Led_Green);
	HAL_Delay(duty_cycle);
	Leds_disable(Led_Green);
	Leds_activation(Led_Orange);
	HAL_Delay(duty_cycle);
	Leds_disable(Led_Orange);
	Leds_activation(Led_Red);
	HAL_Delay(duty_cycle);
	Leds_disable(Led_Red);
	Leds_activation(Led_Blue);
	HAL_Delay(duty_cycle);
	Leds_disable(Led_Blue);
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
