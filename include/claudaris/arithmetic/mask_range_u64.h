#ifndef CLAUDARIS_ARITHMETIC_MASK_RANGE_U64_H
#define CLAUDARIS_ARITHMETIC_MASK_RANGE_U64_H
#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif



/* Build a mask for inclusive LSB-zero interval [first_bit,last_bit]. */
bool claudaris_mask_range_u64(uint8_t first_bit, uint8_t last_bit, uint64_t *mask);

#ifdef __cplusplus
}
#endif

#endif /* CLAUDARIS_ARITHMETIC_MASK_RANGE_U64_H */
