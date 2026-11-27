#ifndef CLAUDARIS_ARITHMETIC_CHECKED_MUL_I64_H
#define CLAUDARIS_ARITHMETIC_CHECKED_MUL_I64_H
#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Store a*b exactly. False on signed overflow or null output; failure leaves
 * output unchanged. */
bool claudaris_checked_mul_i64(int64_t a, int64_t b, int64_t *result);


#ifdef __cplusplus
}
#endif

#endif /* CLAUDARIS_ARITHMETIC_CHECKED_MUL_I64_H */
