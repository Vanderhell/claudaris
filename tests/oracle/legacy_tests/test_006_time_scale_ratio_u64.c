#include <assert.h>
#include <stdint.h>
#include "pc_time_scale_ratio_u64.h"
int main(void)
{
    uint64_t out = 77;
    assert(pc_time_scale_ratio_u64(1, 1, 2, &out) && out == 0);
    assert(pc_time_scale_ratio_u64(3, 1, 2, &out) && out == 2);
    assert(pc_time_scale_ratio_u64(5, 1, 2, &out) && out == 2);
    assert(pc_time_scale_ratio_u64(UINT64_MAX, 1, UINT64_MAX, &out) && out == 1);
    assert(pc_time_scale_ratio_u64(UINT64_MAX, UINT64_MAX, UINT64_MAX, &out));
    assert(out == UINT64_MAX);
    out = 77;
    assert(!pc_time_scale_ratio_u64(UINT64_MAX, UINT64_MAX, 1, &out));
    assert(out == 77);
    assert(!pc_time_scale_ratio_u64(1, 1, 0, &out) && out == 77);
    assert(!pc_time_scale_ratio_u64(1, 1, 1, 0));
    assert(pc_time_scale_ratio_u64(0, UINT64_MAX, 1, &out) && out == 0);
    return 0;
}
