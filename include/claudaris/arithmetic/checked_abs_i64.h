#ifndef CLAUDARIS_ARITHMETIC_CHECKED_ABS_I64_H
#define CLAUDARIS_ARITHMETIC_CHECKED_ABS_I64_H
#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif



/* Store |value| in *result. Return false if result is null or the result is
 * not representable (value == INT64_MIN); on failure, do not write output. */
bool claudaris_checked_abs_i64(int64_t value, int64_t *result);



#ifdef __cplusplus
}
#endif

#endif /* CLAUDARIS_ARITHMETIC_CHECKED_ABS_I64_H */
