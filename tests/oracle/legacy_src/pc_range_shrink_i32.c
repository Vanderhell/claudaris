#include "pc_range_shrink_i32.h"
#include <stddef.h>

bool pc_range_shrink_i32(int32_t lower, int32_t upper, uint32_t amount,
                         int32_t *shrunk_lower, int32_t *shrunk_upper)
{
    int64_t new_lower, new_upper;
    if (shrunk_lower == NULL || shrunk_upper == NULL ||
        shrunk_lower == shrunk_upper || lower > upper) return false;
    new_lower = (int64_t)lower + amount;
    new_upper = (int64_t)upper - amount;
    if (new_lower > new_upper) return false;
    *shrunk_lower = (int32_t)new_lower;
    *shrunk_upper = (int32_t)new_upper;
    return true;
}
