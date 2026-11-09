#ifndef PC_PC_TIME_SCALE_RATIO_U64_H
#define PC_PC_TIME_SCALE_RATIO_U64_H
#include <stdbool.h>
#include <stdint.h>
/* Store nearest-even(value * numerator / denominator). False for zero
 * denominator, null output, or uint64 result overflow; failure preserves it. */
bool pc_time_scale_ratio_u64(uint64_t value, uint64_t numerator,
                             uint64_t denominator, uint64_t *result);
#endif
