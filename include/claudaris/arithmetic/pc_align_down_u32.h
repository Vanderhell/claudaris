#ifndef PRIMITIVECORE_ALIGN_DOWN_U32_H
#define PRIMITIVECORE_ALIGN_DOWN_U32_H
#include <stdbool.h>
#include <stdint.h>

/* Round value down to a multiple of any positive alignment. */
bool rm_align_down_u32(uint32_t value, uint32_t alignment, uint32_t *aligned);
#endif

/* Canonical facade; the legacy implementation and contract are preserved. */
#ifndef pc_align_down_u32
#define pc_align_down_u32 rm_align_down_u32
#endif
#ifndef pc_align_down_u32
#define pc_align_down_u32 rm_align_down_u32
#endif
#ifndef PC_PRIMITIVECORE_ALIGN_DOWN_U32_H
#define PC_PRIMITIVECORE_ALIGN_DOWN_U32_H PRIMITIVECORE_ALIGN_DOWN_U32_H
#endif

