#ifndef CLAUDARIS_ARITHMETIC_RANGE_CENTER_I32_H
#define CLAUDARIS_ARITHMETIC_RANGE_CENTER_I32_H
#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Return lower midpoint: lower + floor((upper-lower)/2). */
bool claudaris_range_center_i32(int32_t lower, int32_t upper, int32_t *center);


#ifdef __cplusplus
}
#endif

#endif /* CLAUDARIS_ARITHMETIC_RANGE_CENTER_I32_H */
