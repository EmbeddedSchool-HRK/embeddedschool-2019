/*
 * drvTemperatureSensor.h
 *
 *  Created on: 19 янв. 2020 г.
 *      Author: user
 */

#ifndef INC_DRVTEMPERATURESENSOR_H_
#define INC_DRVTEMPERATURESENSOR_H_
#include "stm32f4xx_hal.h"
#include "ulSysTime.h"
#define ADC_SAMPLE_COUNT_12 12
#define ADC_SAMPLE_COUNT_10 10
#define ADC_MIN_SAMPLE_INDEX 1
#define ADC_MAX_SAMPLE_INDEX 2
#define ADC_VOLTAGE_KOEF 0.0008


int32_t drvTemperatureSensor_getTemperature(ADC_HandleTypeDef * ptr_hadc);




#endif /* INC_DRVTEMPERATURESENSOR_H_ */
