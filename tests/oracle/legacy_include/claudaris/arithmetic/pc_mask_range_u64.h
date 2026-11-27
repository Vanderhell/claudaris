#ifndef PC_PC_MASK_RANGE_U64_H
#define PC_PC_MASK_RANGE_U64_H

#include <stdbool.h>
#include <stdint.h>

/* Build a mask for inclusive LSB-zero interval [first_bit,last_bit]. */
bool pc_mask_range_u64(uint8_t first_bit, uint8_t last_bit, uint64_t *mask);

#endif
