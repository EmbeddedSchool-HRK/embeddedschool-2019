/*
 * fx15q16.c
 *
 *  Created on: 9 янв. 2020 г.
 *      Author: S1ckret
 */

#include "fx15q16.h"

fx15q16_t fx15q16_mul(fx15q16_t lhs, fx15q16_t rhs)
{
    uint32_t int_lhs = fx15q16_into_int(lhs);
    uint32_t int_rhs = fx15q16_into_int(rhs);
    uint32_t fract_lhs = fx15q16_fractional_part(lhs);
    uint32_t fract_rhs = fx15q16_fractional_part(rhs);

    fx15q16_t result = fx15q16_from_int(int_lhs * int_rhs)
        			 + (int_lhs * fract_rhs + fract_lhs * int_rhs)
					 + (fract_lhs * fract_rhs >> SCALE);
    // Short 64 bit precision in half --------^^
    return result;
}

