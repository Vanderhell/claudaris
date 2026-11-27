#include "pc_checked_shl_i32.h"
#include <limits.h>
#define CHECK(c) do { if (!(c)) return __LINE__; } while (0)
int main(void)
{
    int32_t out = 88;
    CHECK(pc_checked_shl_i32(1, 30, &out) && out == INT32_C(1073741824));
    out = 88;
    CHECK(!pc_checked_shl_i32(1, 31, &out) && out == 88);
    CHECK(pc_checked_shl_i32(-1, 31, &out) && out == INT32_MIN);
    out = 88;
    CHECK(!pc_checked_shl_i32(-2, 31, &out) && out == 88);
    CHECK(pc_checked_shl_i32(0, 31, &out) && out == 0);
    CHECK(!pc_checked_shl_i32(1, 32, &out));
    CHECK(!pc_checked_shl_i32(1, 1, 0));
    return 0;
}
