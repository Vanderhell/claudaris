#include "pc_mask_range_u64.h"

#include <stddef.h>

bool pc_mask_range_u64(uint8_t first_bit, uint8_t last_bit, uint64_t *mask)
{
    uint32_t width;
    uint64_t low_mask;
    uint64_t result;

    if (mask == NULL || first_bit > last_bit || last_bit > 63u) {
        return false;
    }
    width = (uint32_t)last_bit - (uint32_t)first_bit + 1u;
    low_mask = width == 64u ? UINT64_MAX : ((UINT64_C(1) << width) - 1u);
    result = low_mask << first_bit;
    *mask = result;
    return true;
}
