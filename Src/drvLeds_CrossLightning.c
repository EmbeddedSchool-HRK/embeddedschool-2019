/*
 * drvLeds_CrossLightning.c
 *
 *  Created on: Nov 7, 2019
 *      Author: av
 */

#include "drvLeds_CrossLightning.h"
#include "drvLeds.h"
#include "main.h"

void drvLeds_CrossLightning(uint32_t Diode_glow_time, uint32_t Diode_on_delay) {
  drvLeds_off(LED_BLUE);
  drvLeds_off(LED_GREEN);
  drvLeds_off(LED_ORANGE);
  drvLeds_off(LED_RED);
  drvLeds_on(LED_ORANGE);
  HAL_Delay(Diode_glow_time+Diode_on_delay);
  drvLeds_off(LED_ORANGE);
  HAL_Delay(Diode_on_delay);
  drvLeds_on(LED_BLUE);
  HAL_Delay(Diode_glow_time+Diode_on_delay);
  drvLeds_off(LED_BLUE);
  HAL_Delay(Diode_on_delay);
  drvLeds_on(LED_GREEN);
  HAL_Delay(Diode_glow_time+Diode_on_delay);
  drvLeds_off(LED_GREEN);
  HAL_Delay(Diode_on_delay);
  drvLeds_on(LED_RED);
  HAL_Delay(Diode_glow_time+Diode_on_delay);
  drvLeds_off(LED_RED);
  HAL_Delay(Diode_on_delay);
}
