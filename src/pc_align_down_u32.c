#include "pc_align_down_u32.h"
#include <stddef.h>

bool rm_align_down_u32(uint32_t value, uint32_t alignment, uint32_t *aligned)
{
    if (aligned == NULL || alignment == 0u) return false;
    *aligned = value - value % alignment;
    return true;
}
