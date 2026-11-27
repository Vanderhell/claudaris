#ifndef CLAUDARIS_ARITHMETIC_CHECKED_MUL_U64_H
#define CLAUDARIS_ARITHMETIC_CHECKED_MUL_U64_H
#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif



/* Store a*b exactly. False for null output or overflow; failure is atomic. */
bool claudaris_checked_mul_u64(uint64_t a, uint64_t b, uint64_t *result);

#ifdef __cplusplus
}
#endif

#endif /* CLAUDARIS_ARITHMETIC_CHECKED_MUL_U64_H */
