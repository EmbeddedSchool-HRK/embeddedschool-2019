/*
 * drvTemperatureSensor.h
 *
 *  Created on: 19 янв. 2020 г.
 *      Author: user
 */

#ifndef INC_DRVTEMPERATURESENSOR_H_
#define INC_DRVTEMPERATURESENSOR_H_
#include "stm32f4xx_hal.h"
#define ADC_SAMPLE_COUNT_12 12
#define ADC_SAMPLE_COUNT_10 10


uint32_t drvTemperatureSensor_getTemperature(ADC_HandleTypeDef * ptr_hadc);




#endif /* INC_DRVTEMPERATURESENSOR_H_ */
