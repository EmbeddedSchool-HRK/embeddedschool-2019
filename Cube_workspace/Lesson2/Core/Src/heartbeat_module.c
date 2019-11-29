/*
 * heartbeat_module.c
 *
 *  Created on: 19 нояб. 2019 г.
 *      Author: vit
 */
#include "heartbeat_module.h"
#include "ulSysTime.h"
#include "drv_led.h"

led_colour mass[Counter] =
{
		Led_Green,
		Led_Orange,
		Led_Red,
		Led_Blue,
};

//const led_colour led_heartbeat = LED_BLUE;

typedef enum{
	STATE_TURN_LED_ON,
	STATE_WAIT_DUTYCYCLE,
	STATE_TURN_LED_OFF,
	STATE_WAIT_PERIOD
}heartbeatStates_t;

static heartbeatStates_t currentState = STATE_TURN_LED_ON;

void heartbeat_moving(int duty_cycle,int period){

	heartbeatStates_t nextState = currentState;
	uint8_t isItTime = 0;
	static uint32_t startTime = 0;

	switch(currentState){
	case STATE_TURN_LED_ON :
		Leds_activation(mass[Counter]);
		startTime = ulSysTime_getCurrentTime();
		nextState = STATE_WAIT_DUTYCYCLE;
		break;
	case STATE_WAIT_DUTYCYCLE :
		isItTime = ulSysTime_isItTime(startTime, duty_cycle);
		if (isItTime) {
			nextState = STATE_TURN_LED_OFF;
		}
		break;
	case STATE_TURN_LED_OFF :
		Leds_disable(mass[Counter]);
		startTime = ulSysTime_getCurrentTime();
		nextState = STATE_WAIT_PERIOD;
		break;
	case STATE_WAIT_PERIOD:
		isItTime = ulSysTime_isItTime(startTime, period - duty_cycle);
		if (isItTime) {
			nextState = STATE_TURN_LED_ON;
		}
		break;
	default:
		nextState = STATE_TURN_LED_ON;
	}
	currentState = nextState;
}


/*void heartbeat_moving(int duty_cycle){
	for(led_colour colour = 0; colour < Counter; colour++){
		Leds_activation(mass[colour]);
		HAL_Delay(duty_cycle);
		Leds_disable(mass[colour]);
		HAL_Delay(duty_cycle);
		}
}*/



void all_leds_blinking(int dual_duty_cycle){
	for(led_colour colour = 0; colour < Counter; colour++){
	Leds_activation(colour);
		}

	HAL_Delay(dual_duty_cycle);
	for(led_colour colour = 0; colour < Counter; colour++){
	Leds_disable(colour);
		}
}


