#ifndef PRIMITIVECORE_SATURATING_CAST_U64_U32_H
#define PRIMITIVECORE_SATURATING_CAST_U64_U32_H
#include <stdint.h>
/* Clamp value to UINT32_MAX and return it. */
uint32_t rm_saturating_cast_u64_u32(uint64_t value);
#endif

/* Canonical facade; the legacy implementation and contract are preserved. */
#ifndef pc_saturating_cast_u64_u32
#define pc_saturating_cast_u64_u32 rm_saturating_cast_u64_u32
#endif
#ifndef pc_saturating_cast_u64_u32
#define pc_saturating_cast_u64_u32 rm_saturating_cast_u64_u32
#endif
#ifndef PC_PRIMITIVECORE_SATURATING_CAST_U64_U32_H
#define PC_PRIMITIVECORE_SATURATING_CAST_U64_U32_H PRIMITIVECORE_SATURATING_CAST_U64_U32_H
#endif

