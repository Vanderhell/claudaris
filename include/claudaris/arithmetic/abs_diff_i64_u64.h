#ifndef CLAUDARIS_ARITHMETIC_ABS_DIFF_I64_U64_H
#define CLAUDARIS_ARITHMETIC_ABS_DIFF_I64_U64_H
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif



/* Return exact |a-b| as uint64 for any signed int64 inputs. */
uint64_t claudaris_abs_diff_i64_u64(int64_t a, int64_t b);

#ifdef __cplusplus
}
#endif

#endif /* CLAUDARIS_ARITHMETIC_ABS_DIFF_I64_U64_H */
