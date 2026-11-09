#include "pc_nearest_multiple_u32.h"
#include <assert.h>
#include <stdint.h>
#include <stdio.h>
static uint32_t st=1994u;static uint32_t rng(void){st^=st<<13;st^=st>>17;st^=st<<5;return st;}
static int ref(uint32_t v,uint32_t m,uint32_t *o){uint64_t q,r,z;if(!m)return 0;q=v/m;r=v%m;if(2*r>m||(2*r==m&&(q&1u)))q++;z=q*m;if(z>UINT32_MAX)return 0;*o=(uint32_t)z;return 1;}
int main(void){uint32_t v,m,o,e;for(v=0;v<256;v++)for(m=1;m<256;m++){o=77;e=88;assert(pc_nearest_multiple_u32(v,m,&o)==ref(v,m,&e));if(o!=77||e!=88)assert(o==e);}assert(pc_nearest_multiple_u32(5,2,&o)&&o==4);assert(pc_nearest_multiple_u32(7,2,&o)&&o==8);assert(pc_nearest_multiple_u32(UINT32_MAX,1,&o)&&o==UINT32_MAX);o=77;assert(!pc_nearest_multiple_u32(UINT32_MAX,2,&o)&&o==77);assert(!pc_nearest_multiple_u32(1,0,&o)&&o==77);assert(!pc_nearest_multiple_u32(1,1,NULL));for(unsigned i=0;i<1000000;i++){v=rng();m=rng();o=77;e=88;int a=pc_nearest_multiple_u32(v,m,&o),b=ref(v,m,&e);assert(a==b);if(a)assert(o==e);else assert(o==77);}puts("PASS: exhaustive 255x255 small domain + ties/endpoints +1000000 seeded pairs");return 0;}
