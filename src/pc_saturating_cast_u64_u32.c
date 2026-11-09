#include "pc_saturating_cast_u64_u32.h"
#include <limits.h>

uint32_t rm_saturating_cast_u64_u32(uint64_t value)
{
    return value > UINT32_MAX ? UINT32_MAX : (uint32_t)value;
}
