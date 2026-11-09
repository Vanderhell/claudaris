#include "pc_period_align_u32.h"
#include <stddef.h>

bool rm_period_align_u32(uint32_t time, uint32_t origin, uint32_t period,
                         uint32_t *aligned)
{
    uint32_t base, remainder, delta;
    if (aligned == NULL || period == 0u) return false;
    base = time < origin ? origin : time;
    remainder = (base - origin) % period;
    delta = remainder == 0u ? 0u : period - remainder;
    if (delta > UINT32_MAX - base) return false;
    *aligned = base + delta;
    return true;
}
