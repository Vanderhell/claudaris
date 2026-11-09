#include "pc_ratio_between_u32.h"
#include <limits.h>
#define CHECK(c) do { if (!(c)) return __LINE__; } while (0)
int main(void)
{
    bool result = false;
    CHECK(pc_ratio_between_u32(1, 2, 1, 3, 2, 3, &result) && result);
    CHECK(pc_ratio_between_u32(1, 3, 1, 3, 1, 3, &result) && result);
    CHECK(pc_ratio_between_u32(1, 4, 1, 3, 2, 3, &result) && !result);
    result = true;
    CHECK(!pc_ratio_between_u32(1, 2, 2, 1, 1, 1, &result) && result);
    CHECK(!pc_ratio_between_u32(1, 2, 1, 3, 2, 3, 0));
    return 0;
}
