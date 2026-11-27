#ifndef CLAUDARIS_ARITHMETIC_TIME_DURATION_CLAMP_U64_H
#define CLAUDARIS_ARITHMETIC_TIME_DURATION_CLAMP_U64_H
#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Clamp duration to inclusive [lower, upper]. False for invalid bounds or
 * null output; failure leaves *result unchanged. */
bool claudaris_time_duration_clamp_u64(uint64_t duration, uint64_t lower,
                                uint64_t upper, uint64_t *result);

#ifdef __cplusplus
}
#endif

#endif /* CLAUDARIS_ARITHMETIC_TIME_DURATION_CLAMP_U64_H */
