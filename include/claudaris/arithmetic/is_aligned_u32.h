#ifndef CLAUDARIS_ARITHMETIC_IS_ALIGNED_U32_H
#define CLAUDARIS_ARITHMETIC_IS_ALIGNED_U32_H
#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif


/* Return whether value is divisible by a positive alignment; zero is false. */
bool claudaris_is_aligned_u32(uint32_t value, uint32_t alignment);


#ifdef __cplusplus
}
#endif

#endif /* CLAUDARIS_ARITHMETIC_IS_ALIGNED_U32_H */
