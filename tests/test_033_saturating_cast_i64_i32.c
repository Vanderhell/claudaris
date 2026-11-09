#include "pc_saturating_cast_i64_i32.h"
#include <limits.h>
#define CHECK(c) do { if (!(c)) return __LINE__; } while (0)
int main(void)
{
    CHECK(pc_saturating_cast_i64_i32((int64_t)INT32_MIN - 1) == INT32_MIN);
    CHECK(pc_saturating_cast_i64_i32(INT32_MIN) == INT32_MIN);
    CHECK(pc_saturating_cast_i64_i32(0) == 0);
    CHECK(pc_saturating_cast_i64_i32(INT32_MAX) == INT32_MAX);
    CHECK(pc_saturating_cast_i64_i32((int64_t)INT32_MAX + 1) == INT32_MAX);
    CHECK(pc_saturating_cast_i64_i32(INT64_MIN) == INT32_MIN);
    CHECK(pc_saturating_cast_i64_i32(INT64_MAX) == INT32_MAX);
    return 0;
}
