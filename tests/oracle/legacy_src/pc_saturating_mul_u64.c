#include "pc_saturating_mul_u64.h"

uint64_t pc_saturating_mul_u64(uint64_t a, uint64_t b)
{
    if (b != 0u && a > UINT64_MAX / b) return UINT64_MAX;
    return a * b;
}
