#include "pc_ratio_round_even_u32.h"
#include <limits.h>
#define CHECK(c) do { if (!(c)) return __LINE__; } while (0)
int main(void)
{
    uint32_t q = 9;
    CHECK(pc_ratio_round_even_u32(1, 2, &q) && q == 0);
    CHECK(pc_ratio_round_even_u32(3, 2, &q) && q == 2);
    CHECK(pc_ratio_round_even_u32(5, 2, &q) && q == 2);
    CHECK(pc_ratio_round_even_u32(7, 2, &q) && q == 4);
    CHECK(pc_ratio_round_even_u32(UINT32_MAX, 2, &q) && q == UINT32_C(0x80000000));
    q = 9;
    CHECK(!pc_ratio_round_even_u32(UINT32_MAX, 0, &q) && q == 9);
    CHECK(!pc_ratio_round_even_u32(1, 1, 0));
    return 0;
}
