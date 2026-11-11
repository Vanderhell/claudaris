#ifndef PC_TIME_RATIO_INTERNAL_H
#define PC_TIME_RATIO_INTERNAL_H
#include <stdbool.h>
#include <stdint.h>
/* Private shared primitive; intentionally kept outside the public include tree. */
bool pc_time_ratio_mul_divmod_u64(uint64_t value, uint64_t numerator,
                                  uint64_t denominator, uint64_t *quotient,
                                  uint64_t *remainder);
#endif
