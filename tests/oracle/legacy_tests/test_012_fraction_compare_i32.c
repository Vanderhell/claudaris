#include "pc_fraction_compare_i32.h"
#include <limits.h>
#define CHECK(c) do { if (!(c)) return __LINE__; } while (0)
int main(void)
{
    int c = 77;
    CHECK(pc_fraction_compare_i32(1, 2, 2, 3, &c) && c == -1);
    CHECK(pc_fraction_compare_i32(2, -4, -1, 2, &c) && c == 0);
    CHECK(pc_fraction_compare_i32(INT32_MIN, -1, INT32_MAX, 1, &c) && c == 1);
    c = 77;
    CHECK(!pc_fraction_compare_i32(1, 0, 1, 2, &c) && c == 77);
    CHECK(!pc_fraction_compare_i32(1, 2, 1, 3, 0));
    return 0;
}
