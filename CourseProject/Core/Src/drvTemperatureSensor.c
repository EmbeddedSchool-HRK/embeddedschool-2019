/*
 * drvTemperatureSensor.c
 *
 *  Created on: 19 янв. 2020 г.
 *      Author: user
 */

#include "drvTemperatureSensor.h"

static uint32_t ADC_Value = 0;
static float ADC_Voltage = 0.0;
static float temperature = 0.0;
static uint32_t ADC_min = UINT32_MAX;
static uint32_t ADC_max = 0;

static void drvTemperatureSensor_getADCValues(ADC_HandleTypeDef * ptr_hadc);
static void drvTemperatureSensor_ADCVoltageConversion();




static void drvTemperatureSensor_ADCVoltageConversion()
{
	ADC_Voltage = ADC_Value * ADC_VOLTAGE_KOEF;
}


static void drvTemperatureSensor_getADCFilteredValue(ADC_HandleTypeDef * ptr_hadc)
{

	ADC_Value = 0;
	HAL_ADC_Start(ptr_hadc);
	HAL_ADC_PollForConversion(ptr_hadc, 100);
	for(int index = 1; index <= ADC_SAMPLE_COUNT_12; index++)
	{

		uint32_t tempSample = HAL_ADC_GetValue(ptr_hadc);
		if(tempSample < ADC_min)
		{
			ADC_min = tempSample;

		}
		if(tempSample > ADC_max)
		{
			ADC_max = tempSample;
		}
		ADC_Value += tempSample;
		HAL_Delay(83);
	}
	ADC_Value = ADC_Value - ADC_min - ADC_max;
	ADC_Value /= ADC_SAMPLE_COUNT_10;
	HAL_ADC_Stop(ptr_hadc);
}

int32_t drvTemperatureSensor_getTemperature(ADC_HandleTypeDef * ptr_hadc)
{
	drvTemperatureSensor_getADCFilteredValue(ptr_hadc);
	drvTemperatureSensor_ADCVoltageConversion();
	temperature = 100 - ADC_Voltage * 50;
	return (int32_t)temperature;
}
