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

#define FRACTIONAL_MASK (0xFFFFFFFF >> (32 - SCALE))
//Flip fractional mask
#define WHOLE_MASK (-1 ^ FRACTIONAL_MASK)

#define fx15q16_fractional_part(x) (x & FRACTIONAL_MASK)
#define fx15q16_whole_part(x) (x & WHOLE_MASK)

// Source:
// http://tqfp.org/programming/chisla-s-fiksirovannoy-zapyatoy.html
fx15q16_t fx15q16_mul(fx15q16_t lhs, fx15q16_t rhs);
fx15q16_t fx15q16_div(fx15q16_t divedend, fx15q16_t divider);

#endif /* INC_FX15Q16_H_ */
