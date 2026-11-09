#include "pc_period_floor_u32.h"
#include <assert.h>
#include <stdint.h>
int main(void){uint32_t out=99;assert(pc_period_floor_u32(10,0,5,&out)&&out==10);assert(pc_period_floor_u32(14,0,5,&out)&&out==10);assert(pc_period_floor_u32(15,10,5,&out)&&out==15);out=15;assert(!pc_period_floor_u32(9,10,5,&out)&&out==15);out=77;assert(!pc_period_floor_u32(10,0,0,&out)&&out==77);assert(!pc_period_floor_u32(10,0,1,0));for(uint32_t t=0;t<256;t++)for(uint32_t o=0;o<256;o++)for(uint32_t p=1;p<256;p++){int ok=t>=o;out=77;assert(pc_period_floor_u32(t,o,p,&out)==ok);if(ok){assert(out==t-((t-o)%p));assert(out<=t&&out>=o&&(out-o)%p==0);assert((uint64_t)out+p>t);}else assert(out==77);}return 0;}

