/*
 * runningleds.h
 *
 *  Created on: 4 дек. 2019 г.
 *      Author: Korpyc
 */

#ifndef RUNNINGLEDS_H_
#define RUNNINGLEDS_H_

#include "main.h"
#include "drvLeds.h"

void RunningLeds(uint16_t dutyCycle, uint16_t period, uint8_t ledqueue[3]);

#endif /* RUNNINGLEDS_H_ */
