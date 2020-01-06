/*
 * drvTSensor.c
 *
 *  Created on: Jan 5, 2020
 *      Author: S1ckret
 */

#include "drvTSensor.h"

// Temperature sensor calibration (raw) value.
#define TS_CAL_VAL_30 ((uint16_t*)0x1FFF7A2C)
#define TS_CAL_VAL_110 ((uint16_t*)0x1FFF7A2E)

#define TEMP_30 30
#define TEMP_110 110

static float slope = 0.f;
static float temperature = 0.f;

void drvTSenosr_init()
{
	slope = (float)(TEMP_110 - TEMP_30) / ((float)*TS_CAL_VAL_110 - (float)*TS_CAL_VAL_30);
}

int32_t drvTSensor_getTemperature()
{
	return (int32_t)temperature;
}

void drvTSensor_update(ADC_HandleTypeDef* ptr_adc)
{
	HAL_ADC_Start(ptr_adc);
	HAL_ADC_PollForConversion(ptr_adc, 100);
	uint16_t raw_data_adc = HAL_ADC_GetValue(ptr_adc);
	HAL_ADC_Stop(ptr_adc);

	temperature = (raw_data_adc - (float)(*TS_CAL_VAL_30)) * slope + TEMP_30;
}
