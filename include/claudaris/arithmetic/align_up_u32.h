#ifndef CLAUDARIS_ARITHMETIC_ALIGN_UP_U32_H
#define CLAUDARIS_ARITHMETIC_ALIGN_UP_U32_H
#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif


/* Round value up to a multiple of any positive alignment. */
bool claudaris_align_up_u32(uint32_t value, uint32_t alignment, uint32_t *aligned);


#ifdef __cplusplus
}
#endif

#endif /* CLAUDARIS_ARITHMETIC_ALIGN_UP_U32_H */
