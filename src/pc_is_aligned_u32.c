#include "pc_is_aligned_u32.h"

bool rm_is_aligned_u32(uint32_t value, uint32_t alignment)
{
    return alignment != 0u && value % alignment == 0u;
}
