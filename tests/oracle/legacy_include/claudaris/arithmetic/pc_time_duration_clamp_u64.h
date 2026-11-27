#ifndef PC_PC_TIME_DURATION_CLAMP_U64_H
#define PC_PC_TIME_DURATION_CLAMP_U64_H
#include <stdbool.h>
#include <stdint.h>
/* Clamp duration to inclusive [lower, upper]. False for invalid bounds or
 * null output; failure leaves *result unchanged. */
bool pc_time_duration_clamp_u64(uint64_t duration, uint64_t lower,
                                uint64_t upper, uint64_t *result);
#endif
