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

const led_colour diode = Led_Green;

typedef enum{
	STATE_TURN_LED_ON,
	STATE_WAIT_DUTYCYCLE,
	STATE_TURN_LED_OFF,
	STATE_WAIT_PERIOD,
	STATE_SWITCH_STEP
}heartbeatStates_t;

static heartbeatStates_t currentState = STATE_TURN_LED_ON;

void heartbeat_moving(int duty_cycle,int period){

	heartbeatStates_t nextState = currentState;
	uint8_t isItTime = 0;
	static uint32_t startTime = 0;

	switch(currentState){
	case STATE_TURN_LED_ON :
		Leds_activation(diode);
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
		Leds_disable(diode);
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

void all_leds_blinking(int dual_duty_cycle,int period){

	heartbeatStates_t nextState = currentState;
	uint8_t isItTime = 0;
	static uint32_t startTime = 0;
	static uint32_t step = 0;
	switch(currentState){
	case STATE_TURN_LED_ON :
		Leds_activation(diode);
		startTime = ulSysTime_getCurrentTime();
		nextState = STATE_WAIT_DUTYCYCLE;
		break;
	case STATE_WAIT_DUTYCYCLE :
		isItTime = ulSysTime_isItTime(startTime, dual_duty_cycle);
		if (isItTime) {
			nextState = STATE_TURN_LED_OFF;
		}
		break;
	case STATE_TURN_LED_OFF :
		Leds_disable(diode);
		startTime = ulSysTime_getCurrentTime();
		nextState = STATE_WAIT_PERIOD;
		break;
	case STATE_WAIT_PERIOD:
		isItTime = ulSysTime_isItTime(startTime, period - dual_duty_cycle);
		if (isItTime) {
			nextState = STATE_TURN_LED_ON;
		}
		break;
	case STATE_SWITCH_STEP:
		if(step < Counter){
			step++;
		}
		else{
			step = 0;
		}

	default:
		nextState = STATE_TURN_LED_ON;
	}
	currentState = nextState;
}


