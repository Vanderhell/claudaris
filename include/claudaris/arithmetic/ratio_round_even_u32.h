#ifndef CLAUDARIS_ARITHMETIC_RATIO_ROUND_EVEN_U32_H
#define CLAUDARIS_ARITHMETIC_RATIO_ROUND_EVEN_U32_H
#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Round numerator/denominator to nearest integer, ties to even. */
bool claudaris_ratio_round_even_u32(uint32_t numerator, uint32_t denominator,
                             uint32_t *rounded);


#ifdef __cplusplus
}
#endif

#endif /* CLAUDARIS_ARITHMETIC_RATIO_ROUND_EVEN_U32_H */
