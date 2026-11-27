#ifndef CLAUDARIS_ARITHMETIC_RANGE_SHRINK_I32_H
#define CLAUDARIS_ARITHMETIC_RANGE_SHRINK_I32_H
#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Symmetrically shrink a closed range; crossing endpoints fails. */
bool claudaris_range_shrink_i32(int32_t lower, int32_t upper, uint32_t amount,
                         int32_t *shrunk_lower, int32_t *shrunk_upper);


#ifdef __cplusplus
}
#endif

#endif /* CLAUDARIS_ARITHMETIC_RANGE_SHRINK_I32_H */
