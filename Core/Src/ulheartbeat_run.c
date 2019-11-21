/*
 * ulheartbeat_run.c
 *
 *  Created on: 16 нояб. 2019 г.
 *      Author: Herr Satan
 */

#include "ulheartbeat_run.h"
#include "ulheartbeat.h"
#include "driver_LEDs.h"
#include "ulsystime.h"
#include "stdint.h"

static ledlist_t step = 0;
static uint8_t istime = 0;
static uint32_t start_time = 0;
static heartbeat_t currentstate = 0;

static int led_size = sizeof(scenario)/sizeof(ledlist_t);

static ledlist_t scenario[led_size] = {LED_GREEN,LED_RED,LED_BLUE,LED_RED};

void ulHeartbeat_Run (int duty_cycle){
  switch (currentstate){
    case STATE_ON:{
      start_time = ulsystime_Get_Time();
      Led_On(scenario[step]);
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
      Led_Off(scenario[step]);
      currentstate = STATE_LED_Increment;
      break;
    }
    case STATE_LED_Increment:{
      currentstate = STATE_ON;
      if (color  < led_size){
        step++;
      }
      else{
        step = 0;
      }
      break;
    }
    default:{
      currentstate = STATE_ON;
      break;
    }
  }
}