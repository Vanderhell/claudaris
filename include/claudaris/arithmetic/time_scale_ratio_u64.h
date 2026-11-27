#ifndef CLAUDARIS_ARITHMETIC_TIME_SCALE_RATIO_U64_H
#define CLAUDARIS_ARITHMETIC_TIME_SCALE_RATIO_U64_H
#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Store nearest-even(value * numerator / denominator). False for zero
 * denominator, null output, or uint64 result overflow; failure preserves it. */
bool claudaris_time_scale_ratio_u64(uint64_t value, uint64_t numerator,
                             uint64_t denominator, uint64_t *result);

#ifdef __cplusplus
}
#endif

#endif /* CLAUDARIS_ARITHMETIC_TIME_SCALE_RATIO_U64_H */
