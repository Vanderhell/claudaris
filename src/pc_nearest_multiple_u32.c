#include "pc_nearest_multiple_u32.h"
#include <stddef.h>

bool pc_nearest_multiple_u32(uint32_t value, uint32_t multiple,
                             uint32_t *rounded)
{
    uint32_t quotient, remainder;
    uint64_t result;
    if (rounded == NULL || multiple == 0u) return false;
    quotient = value / multiple;
    remainder = value % multiple;
    if ((uint64_t)remainder > (uint64_t)multiple - remainder ||
        ((uint64_t)remainder == (uint64_t)multiple - remainder &&
         (quotient & 1u) != 0u)) {
        ++quotient;
    }
    result = (uint64_t)quotient * multiple;
    if (result > UINT32_MAX) return false;
    *rounded = (uint32_t)result;
    return true;
}

