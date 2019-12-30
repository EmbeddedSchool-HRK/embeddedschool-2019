/*
 * ulSysTime.c
 *
 *  Created on: Nov 29, 2019
 *      Author: vit
 */

#include "ulSysTime.h"


 uint32_t ulSysTime_getCurrentTime(){
	 return HAL_GetTick();
 }

 uint8_t ulSysTime_isItTime(uint32_t startTime, uint32_t delay){
	 uint32_t currentTime = ulSysTime_getCurrentTime();
	 uint8_t returnValue = 0;

	 if(currentTime - startTime > delay){
		 returnValue = 1;
	 }

		 return returnValue;
 }
