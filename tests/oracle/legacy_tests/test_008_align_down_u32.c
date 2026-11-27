#include <assert.h>
#include <stdint.h>
#include "pc_align_down_u32.h"
int main(void){uint32_t out=99;
 assert(pc_align_down_u32(13,8,&out)&&out==8);
 assert(pc_align_down_u32(16,8,&out)&&out==16);
 assert(pc_align_down_u32(UINT32_MAX,UINT32_MAX,&out)&&out==UINT32_MAX);
 assert(pc_align_down_u32(UINT32_MAX,3,&out)&&out==UINT32_MAX-UINT32_MAX%3);
 out=99;assert(!pc_align_down_u32(1,0,&out)&&out==99);
 assert(!pc_align_down_u32(1,1,0));return 0;}
