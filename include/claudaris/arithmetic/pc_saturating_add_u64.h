#ifndef PC_PC_SATURATING_ADD_U64_H
#define PC_PC_SATURATING_ADD_U64_H

#include <stdint.h>

/* Return min(a+b, UINT64_MAX) without wrapping. */
uint64_t pc_saturating_add_u64(uint64_t a, uint64_t b);

#endif
