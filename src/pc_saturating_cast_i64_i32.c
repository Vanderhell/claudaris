#include "pc_saturating_cast_i64_i32.h"
#include <limits.h>

int32_t pc_saturating_cast_i64_i32(int64_t value)
{
    if (value > INT32_MAX) return INT32_MAX;
    if (value < INT32_MIN) return INT32_MIN;
    return (int32_t)value;
}
