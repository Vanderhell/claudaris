#include "pc_checked_mul_i64.h"
#include <limits.h>
#define CHECK(c) do { if (!(c)) return __LINE__; } while (0)
int main(void)
{
    const int64_t a[] = {INT64_MIN, INT64_MIN, INT64_MIN, INT64_MAX, -3, 3, 0};
    const int64_t b[] = {-1, 1, 0, 2, 2, -2, INT64_MIN};
    const bool success[] = {false, true, true, false, true, true, true};
    const int64_t result[] = {0, INT64_MIN, 0, 0, -6, -6, 0};
    for (unsigned i = 0; i < sizeof(a) / sizeof(a[0]); ++i) {
        int64_t out = 75;
        bool ok = pc_checked_mul_i64(a[i], b[i], &out);
        CHECK(ok == success[i]);
        CHECK(out == (success[i] ? result[i] : 75));
    }
    CHECK(!pc_checked_mul_i64(1, 2, 0));
    return 0;
}
