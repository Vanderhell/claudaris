#include "pc_ratio_ceil_u32.h"
#include <limits.h>
#define CHECK(c) do { if (!(c)) return __LINE__; } while (0)
int main(void)
{
    uint32_t q = 9;
    CHECK(pc_ratio_ceil_u32(10, 3, &q) && q == 4);
    CHECK(pc_ratio_ceil_u32(UINT32_MAX, 1, &q) && q == UINT32_MAX);
    CHECK(pc_ratio_ceil_u32(UINT32_MAX, UINT32_MAX, &q) && q == 1);
    q = 9;
    CHECK(!pc_ratio_ceil_u32(UINT32_MAX, 0, &q) && q == 9);
    CHECK(!pc_ratio_ceil_u32(1, 2, 0));
    return 0;
}
