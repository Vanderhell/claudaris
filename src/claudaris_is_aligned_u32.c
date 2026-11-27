#include <claudaris/arithmetic/is_aligned_u32.h>

bool claudaris_is_aligned_u32(uint32_t value, uint32_t alignment)
{
    return alignment != 0u && value % alignment == 0u;
}
