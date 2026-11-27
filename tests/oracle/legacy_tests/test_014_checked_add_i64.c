#include "pc_checked_add_i64.h"
#include <limits.h>
#define CHECK(c) do { if (!(c)) return __LINE__; } while (0)
int main(void)
{
    const int64_t a[] = {INT64_MAX, INT64_MIN, INT64_MAX, INT64_MIN, 0, -2, 2};
    const int64_t b[] = {1, -1, -INT64_MAX, INT64_MAX, 0, 1, -1};
    const bool success[] = {false, false, true, true, true, true, true};
    const int64_t sums[] = {0, 0, 0, -1, 0, -1, 1};
    for (unsigned i = 0; i < sizeof(a) / sizeof(a[0]); ++i) {
        int64_t out = 91;
        bool ok = pc_checked_add_i64(a[i], b[i], &out);
        CHECK(ok == success[i]);
        CHECK(out == (success[i] ? sums[i] : 91));
    }
    CHECK(!pc_checked_add_i64(1, 2, 0));
    return 0;
}
