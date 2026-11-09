#include "pc_abs_i64_safe_u64.h"

uint64_t pc_abs_i64_safe_u64(int64_t value)
{
    if (value >= 0) return (uint64_t)value;
    return UINT64_C(0) - (uint64_t)value;
}
