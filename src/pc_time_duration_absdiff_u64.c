#include "pc_time_duration_absdiff_u64.h"

uint64_t pc_time_duration_absdiff_u64(uint64_t a, uint64_t b)
{
    return a >= b ? a - b : b - a;
}
