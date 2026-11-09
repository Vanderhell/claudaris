#ifndef PC_FRACTION_COMPARE_I32_H
#define PC_FRACTION_COMPARE_I32_H
#include <stdbool.h>
#include <stdint.h>
/* Compare exact fractions; writes -1, 0, or 1. Zero denominator fails. */
bool pc_fraction_compare_i32(int32_t a_num, int32_t a_den,
                             int32_t b_num, int32_t b_den,
                             int *comparison);
#endif

/* Canonical facade; the legacy implementation and contract are preserved. */
#ifndef pc_fraction_compare_i32
#define pc_fraction_compare_i32 pc_fraction_compare_i32
#endif
#ifndef pc_fraction_compare_i32
#define pc_fraction_compare_i32 pc_fraction_compare_i32
#endif
#ifndef PC_PC_FRACTION_COMPARE_I32_H
#define PC_PC_FRACTION_COMPARE_I32_H PC_FRACTION_COMPARE_I32_H
#endif

