/*
 * drvTSensor.h
 *
 *  Created on: Jan 5, 2020
 *      Author: S1ckret
 */

#ifndef INC_DRVTSENSOR_H_
#define INC_DRVTSENSOR_H_

#include "stm32f4xx_hal.h"

void drvTSenosr_init();

void drvTSensor_update(ADC_HandleTypeDef* ptr_adc);

#endif /* INC_DRVTSENSOR_H_ */
