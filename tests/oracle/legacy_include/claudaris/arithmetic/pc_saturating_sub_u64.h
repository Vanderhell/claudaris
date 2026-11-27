#ifndef PC_PC_SATURATING_SUB_U64_H
#define PC_PC_SATURATING_SUB_U64_H

#include <stdint.h>

/* Return max(a-b, 0) without unsigned underflow. */
uint64_t pc_saturating_sub_u64(uint64_t a, uint64_t b);

#endif
