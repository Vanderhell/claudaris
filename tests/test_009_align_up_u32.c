#include <assert.h>
#include <stdint.h>
#include "pc_align_up_u32.h"
int main(void){uint32_t out=99;
 assert(pc_align_up_u32(13,8,&out)&&out==16);
 assert(pc_align_up_u32(16,8,&out)&&out==16);
 assert(pc_align_up_u32(1,3,&out)&&out==3);
 assert(pc_align_up_u32(UINT32_MAX,1,&out)&&out==UINT32_MAX);
 out=99;assert(!pc_align_up_u32(UINT32_MAX,2,&out)&&out==99);
 assert(!pc_align_up_u32(1,0,&out)&&out==99);
 assert(!pc_align_up_u32(1,1,0));return 0;}
