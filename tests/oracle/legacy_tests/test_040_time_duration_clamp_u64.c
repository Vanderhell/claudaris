#include <assert.h>
#include <stdint.h>
#include "pc_time_duration_clamp_u64.h"
int main(void)
{
    uint64_t out=77;
    assert(pc_time_duration_clamp_u64(5,10,20,&out) && out==10);
    assert(pc_time_duration_clamp_u64(10,10,20,&out) && out==10);
    assert(pc_time_duration_clamp_u64(20,10,20,&out) && out==20);
    assert(pc_time_duration_clamp_u64(21,10,20,&out) && out==20);
    assert(pc_time_duration_clamp_u64(UINT64_MAX,0,UINT64_MAX,&out) && out==UINT64_MAX);
    out=77;
    assert(!pc_time_duration_clamp_u64(12,20,10,&out) && out==77);
    assert(!pc_time_duration_clamp_u64(12,0,20,0));
    assert(pc_time_duration_clamp_u64(UINT64_C(1)<<63,0,UINT64_MAX,&out));
    assert(out==(UINT64_C(1)<<63));
    return 0;
}
