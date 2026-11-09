#include <assert.h>
#include <stdint.h>
#include "pc_is_aligned_u32.h"
int main(void){assert(pc_is_aligned_u32(0,7));assert(pc_is_aligned_u32(21,7));assert(!pc_is_aligned_u32(22,7));assert(pc_is_aligned_u32(UINT32_MAX,UINT32_MAX));assert(!pc_is_aligned_u32(0,0));return 0;}
