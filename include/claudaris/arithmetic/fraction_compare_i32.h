#ifndef CLAUDARIS_ARITHMETIC_FRACTION_COMPARE_I32_H
#define CLAUDARIS_ARITHMETIC_FRACTION_COMPARE_I32_H
#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Compare exact fractions; writes -1, 0, or 1. Zero denominator fails. */
bool claudaris_fraction_compare_i32(int32_t a_num, int32_t a_den,
                             int32_t b_num, int32_t b_den,
                             int *comparison);


#ifdef __cplusplus
}
#endif

#endif /* CLAUDARIS_ARITHMETIC_FRACTION_COMPARE_I32_H */
