#ifndef PRIMITIVECORE_PC_TIME_CONVERT_CEIL_U64_H
#define PRIMITIVECORE_PC_TIME_CONVERT_CEIL_U64_H
#include <stdbool.h>
#include <stdint.h>
/* Store ceil(value*numerator/denominator). False on zero denominator,
 * null output, or uint64 result overflow; failure preserves output. */
bool pc_time_convert_ceil_u64(uint64_t value, uint64_t numerator,
                              uint64_t denominator, uint64_t *result);
#endif
