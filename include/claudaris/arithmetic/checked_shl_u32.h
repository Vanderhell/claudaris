#ifndef CLAUDARIS_ARITHMETIC_CHECKED_SHL_U32_H
#define CLAUDARIS_ARITHMETIC_CHECKED_SHL_U32_H
#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Exact uint32_t left shift. False for shift >= 32, discarded high bits, or
 * null output; on failure output is unchanged. */
bool claudaris_checked_shl_u32(uint32_t value, unsigned shift, uint32_t *result);


#ifdef __cplusplus
}
#endif

#endif /* CLAUDARIS_ARITHMETIC_CHECKED_SHL_U32_H */
