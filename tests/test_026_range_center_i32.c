#include "pc_range_center_i32.h"
#include <limits.h>
#define CHECK(c) do { if (!(c)) return __LINE__; } while (0)
int main(void)
{
    int32_t c = 77;
    CHECK(pc_range_center_i32(-3, 2, &c) && c == -1);
    CHECK(pc_range_center_i32(-2, 1, &c) && c == -1);
    CHECK(pc_range_center_i32(INT32_MIN, INT32_MAX, &c) && c == -1);
    c = 77;
    CHECK(!pc_range_center_i32(2, 1, &c) && c == 77);
    CHECK(!pc_range_center_i32(0, 1, 0));
    return 0;
}
