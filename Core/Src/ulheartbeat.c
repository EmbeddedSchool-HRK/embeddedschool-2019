/*
 * ulheartbeat.c
 *
 *  Created on: 15 нояб. 2019 г.
 *      Author: Herr Satan
 */


#include "ulheartbeat.h"
#include "driver_LEDs.h"
#include "ulsystime.h"
#include "stdint.h"

static uint8_t istime = 0;
static uint32_t start_time = 0;
static heartbeat_t currentstate = 0;

void ulHeartbeat (ledlist_t color, int period, int duty_cycle){
  switch (currentstate){
    case STATE_ON:{
      start_time = ulsystime_Get_Time();
      Led_On(color);
      currentstate = STATE_DUTY_CYCLE;
      break;
    }
    case STATE_DUTY_CYCLE:{
      istime = ulsystime_Its_Time(start_time, duty_cycle);
      if (istime == 1){
        currentstate = STATE_OFF;
      }
      break;
    }
    case STATE_OFF:{
      start_time = ulsystime_Get_Time();
      Led_Off(color);
      currentstate = STATE_PERIOD;
      break;
    }
    case STATE_PERIOD:{
      istime = ulsystime_Its_Time(start_time, period - duty_cycle);
      if(istime == 1){
        currentstate = STATE_ON;
      }
      break;
    }
    default:{
      currentstate = STATE_ON;
      break;
    }
  }
}
