#include "pc_saturating_cast_u64_u32.h"
#include <limits.h>
#define CHECK(c) do { if (!(c)) return __LINE__; } while (0)
int main(void)
{
    CHECK(pc_saturating_cast_u64_u32(0) == 0);
    CHECK(pc_saturating_cast_u64_u32(UINT32_MAX) == UINT32_MAX);
    CHECK(pc_saturating_cast_u64_u32((uint64_t)UINT32_MAX + 1) == UINT32_MAX);
    CHECK(pc_saturating_cast_u64_u32(UINT64_MAX) == UINT32_MAX);
    return 0;
}
