#include "pc_range_shrink_i32.h"
#include <limits.h>
#define CHECK(c) do { if (!(c)) return __LINE__; } while (0)
int main(void)
{
    int32_t lo = 0, hi = 0;
    CHECK(pc_range_shrink_i32(2, 8, 3, &lo, &hi) && lo == 5 && hi == 5);
    lo = 99; hi = 77;
    CHECK(!pc_range_shrink_i32(2, 8, 4, &lo, &hi) && lo == 99 && hi == 77);
    CHECK(pc_range_shrink_i32(2, 8, 0, &lo, &hi) && lo == 2 && hi == 8);
    lo = 99; hi = 77;
    CHECK(!pc_range_shrink_i32(8, 2, 0, &lo, &hi) && lo == 99 && hi == 77);
    CHECK(!pc_range_shrink_i32(1, 2, 0, &lo, &lo));
    return 0;
}
