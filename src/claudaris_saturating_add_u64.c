#include <claudaris/arithmetic/saturating_add_u64.h>

uint64_t claudaris_saturating_add_u64(uint64_t a, uint64_t b)
{
    return b > UINT64_MAX - a ? UINT64_MAX : a + b;
}
