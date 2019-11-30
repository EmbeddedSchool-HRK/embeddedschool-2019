/*
 * drvRunningLeds.h
 *
 *  Created on: 30 нояб. 2019 г.
 *      Author: user
 */

#ifndef INC_DRVRUNNINGLEDS_H_
#define INC_DRVRUNNINGLEDS_H_
#include "stm32f4xx.h"
#include "stm32f4xx_hal_gpio.h"
#include "drvLeds.h"
#define SCENARIO_AMOUNT 4

void drv_RunningLeds(uint32_t period, uint32_t dutycycle);
void drv_ActivateAllLeds(uint32_t period, uint32_t dutycycle);
#endif /* INC_DRVRUNNINGLEDS_H_ */
