#include "pc_checked_shl_i32.h"
#include <limits.h>
#include <stddef.h>

bool rm_checked_shl_i32(int32_t value, unsigned shift, int32_t *result)
{
    if (result == NULL || shift >= 32u) return false;
    if (shift == 0u) {
        *result = value;
        return true;
    }
    if (value >= 0) {
        uint32_t magnitude = (uint32_t)value;
        if (magnitude > ((uint32_t)INT32_MAX >> shift)) return false;
        *result = (int32_t)(magnitude << shift);
    } else {
        uint32_t magnitude = (uint32_t)(-(value + 1)) + 1u;
        uint32_t limit = UINT32_C(1) << (31u - shift);
        if (magnitude > limit) return false;
        magnitude <<= shift;
        *result = (magnitude == (UINT32_C(1) << 31))
                      ? INT32_MIN : -(int32_t)magnitude;
    }
    return true;
}
