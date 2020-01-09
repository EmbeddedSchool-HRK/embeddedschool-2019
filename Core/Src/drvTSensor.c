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

#define TEMP_30 fx15q16_from_int(30)
#define TEMP_110 fx15q16_from_int(110)

#define MEASUREMENT_COUNT 12
#define CORRECT_DATA_COUNT 10

static fx15q16_t slope = 0;
static fx15q16_t temperature = 0;

static fx15q16_t getAverageMeasurement(ADC_HandleTypeDef* ptr_adc);

void drvTSenosr_init()
{
	fx15q16_t dividend = TEMP_110 - TEMP_30;
	fx15q16_t divider = fx15q16_from_int((*TS_CAL_VAL_110 - *TS_CAL_VAL_30));

	slope = fx15q16_div(dividend, divider);
}

int32_t drvTSensor_getTemperature()
{
	return fx15q16_into_int(temperature);
}

void drvTSensor_update(ADC_HandleTypeDef* ptr_adc)
{
	HAL_ADC_Start(ptr_adc);
	if (HAL_ADC_PollForConversion(ptr_adc, 1000) == HAL_OK)
	{
		fx15q16_t raw_data_adc = getAverageMeasurement(ptr_adc);
		fx15q16_t delta_from_30_degree = raw_data_adc - fx15q16_from_int((*TS_CAL_VAL_30));
		temperature = fx15q16_mul(delta_from_30_degree, slope) + TEMP_30;
	}
	HAL_ADC_Stop(ptr_adc);

}

//	Make 12 measurements.
//	Drop max and min.
//	Evaluate average of 10 left.
static fx15q16_t getAverageMeasurement(ADC_HandleTypeDef* ptr_adc)
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

	fx15q16_t average_raw_data = fx15q16_div(fx15q16_from_int(sum)
							      ,fx15q16_from_int(CORRECT_DATA_COUNT));
	return average_raw_data;
}
