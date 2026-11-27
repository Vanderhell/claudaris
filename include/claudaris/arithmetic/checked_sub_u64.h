#ifndef CLAUDARIS_ARITHMETIC_CHECKED_SUB_U64_H
#define CLAUDARIS_ARITHMETIC_CHECKED_SUB_U64_H
#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif



/* Store a-b exactly. False for null output or underflow; failure is atomic. */
bool claudaris_checked_sub_u64(uint64_t a, uint64_t b, uint64_t *result);

#ifdef __cplusplus
}
#endif

#endif /* CLAUDARIS_ARITHMETIC_CHECKED_SUB_U64_H */
