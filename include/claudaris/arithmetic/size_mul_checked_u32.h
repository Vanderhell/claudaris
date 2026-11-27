#ifndef CLAUDARIS_ARITHMETIC_SIZE_MUL_CHECKED_U32_H
#define CLAUDARIS_ARITHMETIC_SIZE_MUL_CHECKED_U32_H
#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif



/* Multiply two uint32 size/count values. False for null output or overflow;
 * on failure, leave *product unchanged. */
bool claudaris_size_mul_checked_u32(uint32_t a, uint32_t b, uint32_t *product);

#ifdef __cplusplus
}
#endif

#endif /* CLAUDARIS_ARITHMETIC_SIZE_MUL_CHECKED_U32_H */
