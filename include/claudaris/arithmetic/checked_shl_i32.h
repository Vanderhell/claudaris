#ifndef CLAUDARIS_ARITHMETIC_CHECKED_SHL_I32_H
#define CLAUDARIS_ARITHMETIC_CHECKED_SHL_I32_H
#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Store value*2^shift exactly. False for shift >= 32, int32_t overflow, or
 * null output; failure leaves output unchanged. */
bool claudaris_checked_shl_i32(int32_t value, unsigned shift, int32_t *result);


#ifdef __cplusplus
}
#endif

#endif /* CLAUDARIS_ARITHMETIC_CHECKED_SHL_I32_H */
