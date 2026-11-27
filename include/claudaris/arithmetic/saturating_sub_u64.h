#ifndef CLAUDARIS_ARITHMETIC_SATURATING_SUB_U64_H
#define CLAUDARIS_ARITHMETIC_SATURATING_SUB_U64_H
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif



/* Return max(a-b, 0) without unsigned underflow. */
uint64_t claudaris_saturating_sub_u64(uint64_t a, uint64_t b);

#ifdef __cplusplus
}
#endif

#endif /* CLAUDARIS_ARITHMETIC_SATURATING_SUB_U64_H */
