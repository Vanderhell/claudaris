#ifndef CLAUDARIS_ARITHMETIC_NEAREST_MULTIPLE_U32_H
#define CLAUDARIS_ARITHMETIC_NEAREST_MULTIPLE_U32_H
#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif


/* Round to nearest positive multiple; exact ties choose the even multiple index. */
bool claudaris_nearest_multiple_u32(uint32_t value, uint32_t multiple,
                             uint32_t *rounded);

#ifdef __cplusplus
}
#endif

#endif /* CLAUDARIS_ARITHMETIC_NEAREST_MULTIPLE_U32_H */
