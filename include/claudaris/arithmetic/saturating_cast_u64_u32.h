#ifndef CLAUDARIS_ARITHMETIC_SATURATING_CAST_U64_U32_H
#define CLAUDARIS_ARITHMETIC_SATURATING_CAST_U64_U32_H
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Clamp value to UINT32_MAX and return it. */
uint32_t claudaris_saturating_cast_u64_u32(uint64_t value);


#ifdef __cplusplus
}
#endif

#endif /* CLAUDARIS_ARITHMETIC_SATURATING_CAST_U64_U32_H */
