#ifndef CLAUDARIS_ARITHMETIC_ABS_I64_SAFE_U64_H
#define CLAUDARIS_ARITHMETIC_ABS_I64_SAFE_U64_H
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif



/* Return the exact unsigned magnitude of any int64, including INT64_MIN. */
uint64_t claudaris_abs_i64_safe_u64(int64_t value);

#ifdef __cplusplus
}
#endif

#endif /* CLAUDARIS_ARITHMETIC_ABS_I64_SAFE_U64_H */
