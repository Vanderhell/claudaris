#include "pc_saturating_sub_u64.h"

uint64_t pc_saturating_sub_u64(uint64_t a, uint64_t b)
{
    return b > a ? 0u : a - b;
}
