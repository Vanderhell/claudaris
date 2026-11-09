#include "pc_range_center_i32.h"
#include <stddef.h>

bool rm_range_center_i32(int32_t lower, int32_t upper, int32_t *center)
{
    int64_t delta;
    if (center == NULL || lower > upper) return false;
    delta = (int64_t)upper - lower;
    *center = (int32_t)((int64_t)lower + delta / 2);
    return true;
}
