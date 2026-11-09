#include "pc_floor_to_multiple_i32.h"
#include <stddef.h>

bool rm_floor_to_multiple_i32(int32_t value, int32_t multiple,
                              int32_t *rounded)
{
    int64_t q, r, result;
    if (rounded == NULL || multiple <= 0) return false;
    q = (int64_t)value / multiple;
    r = (int64_t)value % multiple;
    if (r < 0) --q;
    result = q * multiple;
    if (result < INT32_MIN || result > INT32_MAX) return false;
    *rounded = (int32_t)result;
    return true;
}
