/*
 * ulsystime.c
 *
 *  Created on: 15 нояб. 2019 г.
 *      Author: Herr Satan
 */
#include "ulsystime.h"
#include "stdint.h"
#include "stm32f4xx.h"

uint32_t ulsystime_Get_Time(){
  return HAL_GetTick();
}

uint8_t ulsystime_Its_Time(uint32_t start_time, uint32_t delay){
  uint32_t current_time = ulsystime_Get_Time();
  uint32_t delta = 0;
  uint8_t return_val = 0;
  if(current_time < start_time){
    delta = 0xFFFFFFFF - start_time + current_time;  
  }
  else{
    delta = current_time - start_time;
  }
  if (delta >= delay){
    return_val = 1;
  }
  else {
    return_val = 0;
  }
  return return_val;
}
