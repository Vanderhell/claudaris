#ifndef PRIMITIVECORE_RATIO_CEIL_U32_H
#define PRIMITIVECORE_RATIO_CEIL_U32_H
#include <stdbool.h>
#include <stdint.h>
/* Return ceil(numerator/denominator). Zero denominator fails unchanged. */
bool rm_ratio_ceil_u32(uint32_t numerator, uint32_t denominator,
                       uint32_t *quotient);
#endif

/* Canonical facade; the legacy implementation and contract are preserved. */
#ifndef pc_ratio_ceil_u32
#define pc_ratio_ceil_u32 rm_ratio_ceil_u32
#endif
#ifndef pc_ratio_ceil_u32
#define pc_ratio_ceil_u32 rm_ratio_ceil_u32
#endif
#ifndef PC_PRIMITIVECORE_RATIO_CEIL_U32_H
#define PC_PRIMITIVECORE_RATIO_CEIL_U32_H PRIMITIVECORE_RATIO_CEIL_U32_H
#endif

