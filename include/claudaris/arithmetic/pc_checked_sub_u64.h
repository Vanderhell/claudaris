#ifndef PRIMITIVECORE_PC_CHECKED_SUB_U64_H
#define PRIMITIVECORE_PC_CHECKED_SUB_U64_H

#include <stdbool.h>
#include <stdint.h>

/* Store a-b exactly. False for null output or underflow; failure is atomic. */
bool pc_checked_sub_u64(uint64_t a, uint64_t b, uint64_t *result);

#endif
