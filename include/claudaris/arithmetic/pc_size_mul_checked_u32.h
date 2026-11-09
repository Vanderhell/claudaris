#ifndef PRIMITIVECORE_SIZE_MUL_CHECKED_U32_H
#define PRIMITIVECORE_SIZE_MUL_CHECKED_U32_H

#include <stdbool.h>
#include <stdint.h>

/* Multiply two uint32 size/count values. False for null output or overflow;
 * on failure, leave *product unchanged. */
bool pc_size_mul_checked_u32(uint32_t a, uint32_t b, uint32_t *product);

#endif
