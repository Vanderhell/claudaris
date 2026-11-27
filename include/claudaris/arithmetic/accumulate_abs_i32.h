#ifndef CLAUDARIS_ARITHMETIC_ACCUMULATE_ABS_I32_H
#define CLAUDARIS_ARITHMETIC_ACCUMULATE_ABS_I32_H
#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Add the exact magnitude of value to *accumulator; overflow leaves it unchanged. */
bool claudaris_accumulate_abs_i32(int32_t value, uint64_t *accumulator);


#ifdef __cplusplus
}
#endif

#endif /* CLAUDARIS_ARITHMETIC_ACCUMULATE_ABS_I32_H */
