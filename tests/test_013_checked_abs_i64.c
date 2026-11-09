#include "pc_checked_abs_i64.h"

#include <limits.h>

#define CHECK(condition) do { if (!(condition)) return __LINE__; } while (0)

int main(void)
{
    const int64_t inputs[] = {INT64_MIN, INT64_MIN + 1, -1, 0, 1,
                              INT64_MAX - 1, INT64_MAX};
    const int64_t expected[] = {0, INT64_MAX, 1, 0, 1,
                                INT64_MAX - 1, INT64_MAX};
    for (unsigned i = 0; i < sizeof(inputs) / sizeof(inputs[0]); ++i) {
        int64_t output = 123;
        const bool ok = pc_checked_abs_i64(inputs[i], &output);
        CHECK(ok == (inputs[i] != INT64_MIN));
        CHECK(output == ((inputs[i] == INT64_MIN) ? 123 : expected[i]));
    }
    CHECK(!pc_checked_abs_i64(1, 0));
    return 0;
}
