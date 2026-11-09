#include <assert.h>
#include <stdint.h>
#include "pc_time_duration_absdiff_u64.h"
int main(void)
{
    assert(pc_time_duration_absdiff_u64(0,0)==0);
    assert(pc_time_duration_absdiff_u64(5,3)==2);
    assert(pc_time_duration_absdiff_u64(3,5)==2);
    assert(pc_time_duration_absdiff_u64(UINT64_MAX,0)==UINT64_MAX);
    assert(pc_time_duration_absdiff_u64(UINT64_MAX,UINT64_MAX-1)==1);
    assert(pc_time_duration_absdiff_u64(UINT64_MAX,1)==UINT64_MAX-1);
    return 0;
}
