/*
 * drvTSensor.h
 *
 *  Created on: Jan 5, 2020
 *      Author: S1ckret
 */

#ifndef INC_DRVTSENSOR_H_
#define INC_DRVTSENSOR_H_

#include "stm32f4xx_hal.h"
#include <stdint.h>

void drvTSenosr_init();

int32_t drvTSensor_getTemperature();

void drvTSensor_update(ADC_HandleTypeDef* ptr_adc);

#endif /* INC_DRVTSENSOR_H_ */
