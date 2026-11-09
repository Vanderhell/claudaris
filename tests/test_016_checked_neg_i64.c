#include "pc_checked_neg_i64.h"
#include <limits.h>
#define CHECK(c) do { if (!(c)) return __LINE__; } while (0)
int main(void)
{
    const int64_t x[] = {INT64_MIN, INT64_MIN + 1, -1, 0, 1, INT64_MAX};
    const int64_t y[] = {0, INT64_MAX, 1, 0, -1, -INT64_MAX};
    for (unsigned i = 0; i < sizeof(x) / sizeof(x[0]); ++i) {
        int64_t out = 42;
        bool ok = pc_checked_neg_i64(x[i], &out);
        CHECK(ok == (x[i] != INT64_MIN));
        CHECK(out == (x[i] == INT64_MIN ? 42 : y[i]));
    }
    CHECK(!pc_checked_neg_i64(3, 0));
    return 0;
}
