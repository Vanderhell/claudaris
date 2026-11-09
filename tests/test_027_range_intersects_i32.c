#include "pc_range_intersects_i32.h"
#include <limits.h>
#define CHECK(c) do { if (!(c)) return __LINE__; } while (0)
int main(void)
{
    CHECK(pc_range_intersects_i32(1, 4, 4, 8));
    CHECK(pc_range_intersects_i32(4, 4, 4, 4));
    CHECK(pc_range_intersects_i32(INT32_MIN, 0, 0, INT32_MAX));
    CHECK(!pc_range_intersects_i32(1, 3, 4, 8));
    CHECK(!pc_range_intersects_i32(3, 1, 0, 4));
    CHECK(!pc_range_intersects_i32(0, 4, 3, 1));
    CHECK(pc_range_intersects_i32(INT32_MIN, INT32_MAX, INT32_MIN, INT32_MAX));
    return 0;
}
