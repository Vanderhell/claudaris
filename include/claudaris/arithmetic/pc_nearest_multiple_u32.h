#ifndef PRIMITIVECORE_NEAREST_MULTIPLE_U32_H
#define PRIMITIVECORE_NEAREST_MULTIPLE_U32_H
#include <stdbool.h>
#include <stdint.h>

/* Round to nearest positive multiple; exact ties choose the even multiple index. */
bool pc_nearest_multiple_u32(uint32_t value, uint32_t multiple,
                             uint32_t *rounded);
#endif
