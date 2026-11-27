#ifndef CLAUDARIS_ARITHMETIC_SATURATING_ADD_I64_H
#define CLAUDARIS_ARITHMETIC_SATURATING_ADD_I64_H
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif



/* Return a+b clipped to INT64_MIN..INT64_MAX without signed overflow. */
int64_t claudaris_saturating_add_i64(int64_t a, int64_t b);

#ifdef __cplusplus
}
#endif

#endif /* CLAUDARIS_ARITHMETIC_SATURATING_ADD_I64_H */
