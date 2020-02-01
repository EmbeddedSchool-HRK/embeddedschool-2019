/*
 * ulSysTime.c
 *
 *  Created on: 1 лют. 2020 р.
 *      Author: Local user Profile
 */

#include "ulSysTime.h"

uint32_t ulSysTime_GetTime(){
	return HAL_GetTick();
}

uint8_t ulSysTime_CheckIfTime(uint32_t TimeStart, uint32_t TimeDelay){
	uint8_t varReturn = 0;
	uint32_t TimeCurrent = ulSysTime_GetTime();
	uint32_t TimeDelta = 0;
	if(TimeCurrent<TimeStart){
		TimeDelta = 0xFFFFFFFF - TimeStart + TimeCurrent;
	}
	else{
		TimeDelta = TimeCurrent - TimeStart;
	}
	if(TimeDelta>TimeDelay){
		varReturn = 1;
	}
	return varReturn;
}
