#include "pc_align_up_u32.h"
#include <stddef.h>

bool rm_align_up_u32(uint32_t value, uint32_t alignment, uint32_t *aligned)
{
    uint32_t remainder, padding;
    if (aligned == NULL || alignment == 0u) return false;
    remainder = value % alignment;
    padding = remainder == 0u ? 0u : alignment - remainder;
    if (value > UINT32_MAX - padding) return false;
    *aligned = value + padding;
    return true;
}
