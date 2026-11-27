#ifndef CLAUDARIS_ARITHMETIC_TIME_CONVERT_FLOOR_U64_H
#define CLAUDARIS_ARITHMETIC_TIME_CONVERT_FLOOR_U64_H
#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Store floor(value*numerator/denominator). False on zero denominator,
 * null output, or uint64 result overflow; failure preserves output. */
bool claudaris_time_convert_floor_u64(uint64_t value, uint64_t numerator,
                               uint64_t denominator, uint64_t *result);

#ifdef __cplusplus
}
#endif

#endif /* CLAUDARIS_ARITHMETIC_TIME_CONVERT_FLOOR_U64_H */
