#include "pc_checked_shl_u32.h"
#include <limits.h>
#define CHECK(c) do { if (!(c)) return __LINE__; } while (0)
int main(void)
{
    uint32_t out = 91;
    CHECK(pc_checked_shl_u32(1, 31, &out) && out == UINT32_C(0x80000000));
    out = 91;
    CHECK(!pc_checked_shl_u32(2, 31, &out) && out == 91);
    CHECK(pc_checked_shl_u32(UINT32_MAX, 0, &out) && out == UINT32_MAX);
    out = 91;
    CHECK(!pc_checked_shl_u32(1, 32, &out) && out == 91);
    CHECK(!pc_checked_shl_u32(0, 100, &out));
    CHECK(!pc_checked_shl_u32(1, 1, 0));
    return 0;
}
