#ifndef CLAUDARIS_ARITHMETIC_RATIO_BETWEEN_U32_H
#define CLAUDARIS_ARITHMETIC_RATIO_BETWEEN_U32_H
#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Test inclusive ratio bounds. Invalid/zero denominators return false status. */
bool claudaris_ratio_between_u32(uint32_t numerator, uint32_t denominator,
                          uint32_t lower_num, uint32_t lower_den,
                          uint32_t upper_num, uint32_t upper_den,
                          bool *is_between);


#ifdef __cplusplus
}
#endif

#endif /* CLAUDARIS_ARITHMETIC_RATIO_BETWEEN_U32_H */
