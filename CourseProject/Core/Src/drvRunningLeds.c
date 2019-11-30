/*
 * drvRunningLeds.c
 *
 *  Created on: 30 нояб. 2019 г.
 *      Author: user
 */


#include "drvRunningLeds.h"


const ledlist_t scenario[SCENARIO_AMOUNT] = { LED_BLUE, LED_ORANGE, LED_RED, LED_GREEN };

void drv_RunningLeds(uint32_t period, uint32_t dutycycle)
{
	for(int led =0 ; led < SCENARIO_AMOUNT; led++)
	{


		drvLeds_on(scenario[led]);
		HAL_Delay(dutycycle);
		drvLeds_off(scenario[led]);
		HAL_Delay(period - dutycycle);


	}
}
void drv_ActivateAllLeds(uint32_t period, uint32_t dutycycle)
{
	for(int led =0 ; led < SCENARIO_AMOUNT; led++)
	{
		drvLeds_on(scenario[led]);

	}
	HAL_Delay(dutycycle);
	for(int led =0 ; led < SCENARIO_AMOUNT; led++)
	{
		drvLeds_off(scenario[led]);
	}
	HAL_Delay(period - dutycycle);

}

