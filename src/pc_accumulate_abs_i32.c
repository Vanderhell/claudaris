#include "pc_accumulate_abs_i32.h"
#include <stddef.h>

bool rm_accumulate_abs_i32(int32_t value, uint64_t *accumulator)
{
    uint32_t magnitude;
    if (accumulator == NULL) return false;
    magnitude = (value < 0) ? (uint32_t)(-(int64_t)value) : (uint32_t)value;
    if (UINT64_MAX - *accumulator < magnitude) return false;
    *accumulator += magnitude;
    return true;
}

