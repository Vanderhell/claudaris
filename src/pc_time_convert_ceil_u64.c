#include "pc_time_convert_ceil_u64.h"
#include "pc_time_ratio_internal.h"

bool pc_time_convert_ceil_u64(uint64_t value, uint64_t numerator,
                              uint64_t denominator, uint64_t *result)
{
    uint64_t quotient;
    uint64_t remainder;
    if (result == 0 || denominator == 0u) return false;
    if (!pc_time_ratio_mul_divmod_u64(value, numerator, denominator,
                                      &quotient, &remainder)) return false;
    if (remainder != 0u) {
        if (quotient == UINT64_MAX) return false;
        ++quotient;
    }
    *result = quotient;
    return true;
}
