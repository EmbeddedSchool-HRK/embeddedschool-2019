/*
 * drvTSensor.c
 *
 *  Created on: Jan 5, 2020
 *      Author: S1ckret
 */

#include "drvTSensor.h"

static uint16_t raw_data_adc = 0;

void drvTSensor_update(ADC_HandleTypeDef* ptr_adc)
{
	HAL_ADC_Start(ptr_adc);
	HAL_ADC_PollForConversion(ptr_adc, 100);
	raw_data_adc = HAL_ADC_GetValue(ptr_adc);
	HAL_ADC_Stop(ptr_adc);
}
