#include <assert.h>
#include <stdint.h>
#include "pc_time_convert_ceil_u64.h"
int main(void)
{
    uint64_t out=77;
    assert(pc_time_convert_ceil_u64(1,1,2,&out) && out==1);
    assert(pc_time_convert_ceil_u64(3,1,2,&out) && out==2);
    assert(pc_time_convert_ceil_u64(4,1,2,&out) && out==2);
    assert(pc_time_convert_ceil_u64(UINT64_MAX,UINT64_MAX,UINT64_MAX,&out));
    assert(out==UINT64_MAX);
    assert(pc_time_convert_ceil_u64(0,UINT64_MAX,1,&out) && out==0);
    out=77;
    assert(!pc_time_convert_ceil_u64(UINT64_MAX,UINT64_MAX,1,&out) && out==77);
    assert(!pc_time_convert_ceil_u64(1,1,0,&out) && out==77);
    assert(!pc_time_convert_ceil_u64(1,1,1,0));
    return 0;
}
