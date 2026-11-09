#include "pc_period_floor_u32.h"
#include <stddef.h>

bool rm_period_floor_u32(uint32_t time, uint32_t origin, uint32_t period,
                         uint32_t *aligned)
{
    if (aligned == NULL || period == 0u || time < origin) return false;
    *aligned = time - ((time - origin) % period);
    return true;
}
