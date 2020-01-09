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

#define MEASUREMENT_COUNT 12
#define CORRECT_DATA_COUNT 10

static float slope = 0.f;
static float temperature = 0.f;

static float getAverageMeasurement(ADC_HandleTypeDef* ptr_adc);

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
	if (HAL_ADC_PollForConversion(ptr_adc, 1000) == HAL_OK)
	{
		uint16_t raw_data_adc = getAverageMeasurement(ptr_adc);
		temperature = (raw_data_adc - (float)(*TS_CAL_VAL_30)) * slope + TEMP_30;
	}
	HAL_ADC_Stop(ptr_adc);

}


//	Make 12 measurements.
//	Drop max and min.
//	Evaluate average of 10 left.
static float getAverageMeasurement(ADC_HandleTypeDef* ptr_adc)
{
	uint16_t data_arr[MEASUREMENT_COUNT];
	uint16_t max = 0;
	uint16_t min = UINT16_MAX;
	uint32_t sum = 0;

	for (uint8_t i = 0; i < MEASUREMENT_COUNT; i++)
	{
		data_arr[i] = HAL_ADC_GetValue(ptr_adc);
		if (data_arr[i] > max) max = data_arr[i];
		else if (data_arr[i] < min) min = data_arr[i];

		sum += data_arr[i];
	}
	sum = sum - min - max;

	float average_raw_data = (float)(sum) / (float)CORRECT_DATA_COUNT;
	return average_raw_data;
}
