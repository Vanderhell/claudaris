#include "pc_ratio_ceil_u32.h"
#include <stddef.h>

bool pc_ratio_ceil_u32(uint32_t numerator, uint32_t denominator,
                       uint32_t *quotient)
{
    uint32_t q, r;
    if (quotient == NULL || denominator == 0u) return false;
    q = numerator / denominator;
    r = numerator % denominator;
    if (r != 0u) ++q;
    *quotient = q;
    return true;
}
