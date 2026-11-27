#ifndef PC_PC_CHECKED_MUL_U64_H
#define PC_PC_CHECKED_MUL_U64_H

#include <stdbool.h>
#include <stdint.h>

/* Store a*b exactly. False for null output or overflow; failure is atomic. */
bool pc_checked_mul_u64(uint64_t a, uint64_t b, uint64_t *result);

#endif
