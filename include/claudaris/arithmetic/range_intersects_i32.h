#ifndef CLAUDARIS_ARITHMETIC_RANGE_INTERSECTS_I32_H
#define CLAUDARIS_ARITHMETIC_RANGE_INTERSECTS_I32_H
#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Closed interval intersection; either inverted interval yields false. */
bool claudaris_range_intersects_i32(int32_t a_lower, int32_t a_upper,
                             int32_t b_lower, int32_t b_upper);


#ifdef __cplusplus
}
#endif

#endif /* CLAUDARIS_ARITHMETIC_RANGE_INTERSECTS_I32_H */
