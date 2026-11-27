#ifndef CLAUDARIS_ARITHMETIC_SATURATING_CAST_I64_I32_H
#define CLAUDARIS_ARITHMETIC_SATURATING_CAST_I64_I32_H
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Clamp value to the int32_t range and return it. */
int32_t claudaris_saturating_cast_i64_i32(int64_t value);


#ifdef __cplusplus
}
#endif

#endif /* CLAUDARIS_ARITHMETIC_SATURATING_CAST_I64_I32_H */
