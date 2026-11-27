#ifndef CLAUDARIS_ARITHMETIC_RATIO_CEIL_U32_H
#define CLAUDARIS_ARITHMETIC_RATIO_CEIL_U32_H
#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Return ceil(numerator/denominator). Zero denominator fails unchanged. */
bool claudaris_ratio_ceil_u32(uint32_t numerator, uint32_t denominator,
                       uint32_t *quotient);


#ifdef __cplusplus
}
#endif

#endif /* CLAUDARIS_ARITHMETIC_RATIO_CEIL_U32_H */
