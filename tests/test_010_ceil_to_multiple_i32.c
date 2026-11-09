#include "pc_ceil_to_multiple_i32.h"
#include <limits.h>
#define CHECK(c) do { if (!(c)) return __LINE__; } while (0)
int main(void)
{
    int32_t out = 77;
    CHECK(pc_ceil_to_multiple_i32(5, 2, &out) && out == 6);
    CHECK(pc_ceil_to_multiple_i32(-5, 2, &out) && out == -4);
    CHECK(pc_ceil_to_multiple_i32(-6, 4, &out) && out == -4);
    CHECK(pc_ceil_to_multiple_i32(-4, 4, &out) && out == -4);
    CHECK(pc_ceil_to_multiple_i32(INT32_MIN, 1, &out) && out == INT32_MIN);
    out = 77;
    CHECK(!pc_ceil_to_multiple_i32(INT32_MAX, 3, &out) && out == 77);
    CHECK(!pc_ceil_to_multiple_i32(1, 0, &out) && out == 77);
    CHECK(!pc_ceil_to_multiple_i32(1, -2, &out) && out == 77);
    CHECK(!pc_ceil_to_multiple_i32(1, 1, 0));
    return 0;
}
