/*
 * fx15q16.h
 *
 *  Created on: 9 янв. 2020 г.
 *      Author: S1ckret
 */

#ifndef INC_FX15Q16_H_
#define INC_FX15Q16_H_

#include <stdint.h>

typedef int32_t fx15q16_t;

#define SCALE 16

#define fx15q16_from_int(x) ((fx15q16_t)(x << SCALE))
#define fx15q16_from_float(x) ((fx15q16_t)(x * (float)(1 << SCALE)))

#define fx15q16_into_int(x) ((int32_t)(x >> SCALE))
#define fx15q16_into_float(x) ((float)(x / (float)(1 << SCALE)))

#endif /* INC_FX15Q16_H_ */
