#include <claudaris/arithmetic/offset_range_check_u32.h>

bool claudaris_offset_range_check_u32(uint32_t offset, uint32_t length,
                               uint32_t capacity)
{
    return offset <= capacity && length <= capacity - offset;
}
