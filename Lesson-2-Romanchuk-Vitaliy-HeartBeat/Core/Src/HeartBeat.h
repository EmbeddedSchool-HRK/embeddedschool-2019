/*
 * HeartBeat.h
 *
 *  Created on: 6 лист. 2019 р.
 *      Author: TheKeeper
 */

#ifndef SRC_HEARTBEAT_H_
#define SRC_HEARTBEAT_H_

#include "stdint.h"
#include "main.h"

void five_minutes_func(uint32_t period, uint32_t dutycycle);
void four_minutes_func(uint32_t period);

#endif /* SRC_HEARTBEAT_H_ */
