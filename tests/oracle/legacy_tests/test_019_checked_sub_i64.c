#include "pc_checked_sub_i64.h"
#include <limits.h>
#define CHECK(c) do { if (!(c)) return __LINE__; } while (0)
int main(void)
{
    const int64_t a[] = {INT64_MIN, INT64_MIN, INT64_MAX, -1, 0, -2, 0};
    const int64_t b[] = {INT64_MIN, 1, -1, INT64_MIN, 0, -1, 1};
    const bool success[] = {true, false, false, true, true, true, true};
    const int64_t results[] = {0, 0, 0, INT64_MAX, 0, -1, -1};
    for (unsigned i = 0; i < sizeof(a) / sizeof(a[0]); ++i) {
        int64_t out = 33;
        bool ok = pc_checked_sub_i64(a[i], b[i], &out);
        CHECK(ok == success[i]);
        if (success[i]) CHECK(out == results[i]);
        else CHECK(out == 33);
    }
    CHECK(!pc_checked_sub_i64(1, 2, 0));
    return 0;
}
