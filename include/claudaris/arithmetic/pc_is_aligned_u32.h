#ifndef PRIMITIVECORE_IS_ALIGNED_U32_H
#define PRIMITIVECORE_IS_ALIGNED_U32_H
#include <stdbool.h>
#include <stdint.h>

/* Return whether value is divisible by a positive alignment; zero is false. */
bool rm_is_aligned_u32(uint32_t value, uint32_t alignment);
#endif

/* Canonical facade; the legacy implementation and contract are preserved. */
#ifndef pc_is_aligned_u32
#define pc_is_aligned_u32 rm_is_aligned_u32
#endif
#ifndef pc_is_aligned_u32
#define pc_is_aligned_u32 rm_is_aligned_u32
#endif
#ifndef PC_PRIMITIVECORE_IS_ALIGNED_U32_H
#define PC_PRIMITIVECORE_IS_ALIGNED_U32_H PRIMITIVECORE_IS_ALIGNED_U32_H
#endif

