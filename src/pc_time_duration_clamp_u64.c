#include "pc_time_duration_clamp_u64.h"

bool pc_time_duration_clamp_u64(uint64_t duration, uint64_t lower,
                                uint64_t upper, uint64_t *result)
{
    uint64_t clamped;
    if (result == 0 || lower > upper) return false;
    clamped = duration < lower ? lower : (duration > upper ? upper : duration);
    *result = clamped;
    return true;
}
