#include "pc_round_to_multiple_i32.h"
#include <stddef.h>

bool rm_round_to_multiple_i32(int32_t value, int32_t multiple,
                              int32_t *rounded)
{
    int64_t q, r, magnitude, twice, result;
    if (rounded == NULL || multiple <= 0) return false;
    q = (int64_t)value / multiple;
    r = (int64_t)value % multiple;
    magnitude = r < 0 ? -r : r;
    twice = magnitude * 2;
    if (twice > multiple || (twice == multiple && q % 2 != 0))
        q += value < 0 ? -1 : 1;
    result = q * multiple;
    if (result < INT32_MIN || result > INT32_MAX) return false;
    *rounded = (int32_t)result;
    return true;
}
