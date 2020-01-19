/*
 * drvTemperatureSensor.c
 *
 *  Created on: 19 янв. 2020 г.
 *      Author: user
 */

#include "drvTemperatureSensor.h"

static uint32_t ADC_Values = 0;
static float ADC_Voltage = 0.0;
static void drvTemperatureSensor_getADCValues(ADC_HandleTypeDef * ptr_hadc);
static void drvTemperatureSensor_ADCVoltageConversion();



static void drvTemperatureSensor_ADCVoltageConversion()
{
	ADC_Voltage = ADC_Values * ADC_VOLTAGE_KOEF;
}


static void drvTemperatureSensor_getADCValues(ADC_HandleTypeDef * ptr_hadc)
{
	HAL_ADC_Start(ptr_hadc);
	HAL_ADC_PollForConversion(ptr_hadc, 100);
	ADC_Values = HAL_ADC_GetValue(ptr_hadc);
	HAL_ADC_Stop(ptr_hadc);
}

uint32_t drvTemperatureSensor_getTemperature(ADC_HandleTypeDef * ptr_hadc)
{
	drvTemperatureSensor_getADCValues(ptr_hadc);
	drvTemperatureSensor_ADCVoltageConversion();
	return ADC_Values;
}
