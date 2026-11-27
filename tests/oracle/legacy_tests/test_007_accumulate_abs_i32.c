#include "pc_accumulate_abs_i32.h"
#include <limits.h>
#define CHECK(e) do { if (!(e)) return __LINE__; } while (0)
int main(void) {
 uint64_t a=0u,old; CHECK(pc_accumulate_abs_i32(0,&a) && a==0u);
 CHECK(pc_accumulate_abs_i32(INT32_MIN,&a) && a==UINT64_C(2147483648));
 CHECK(pc_accumulate_abs_i32(INT32_MAX,&a) && a==UINT64_C(4294967295));
 CHECK(pc_accumulate_abs_i32(-1,&a) && a==UINT64_C(4294967296));
 a=UINT64_MAX; CHECK(pc_accumulate_abs_i32(0,&a) && a==UINT64_MAX);
 old=a; CHECK(!pc_accumulate_abs_i32(1,&a) && a==old);
 a=UINT64_MAX-UINT32_C(2147483648); CHECK(pc_accumulate_abs_i32(INT32_MIN,&a) && a==UINT64_MAX);
 a=UINT64_MAX-UINT32_C(2147483647); old=a; CHECK(!pc_accumulate_abs_i32(INT32_MIN,&a) && a==old);
 CHECK(!pc_accumulate_abs_i32(1,0));
 return 0;
}
