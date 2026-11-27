#ifndef CLAUDARIS_ARITHMETIC_SATURATING_ADD_U64_H
#define CLAUDARIS_ARITHMETIC_SATURATING_ADD_U64_H
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif



/* Return min(a+b, UINT64_MAX) without wrapping. */
uint64_t claudaris_saturating_add_u64(uint64_t a, uint64_t b);

#ifdef __cplusplus
}
#endif

#endif /* CLAUDARIS_ARITHMETIC_SATURATING_ADD_U64_H */
