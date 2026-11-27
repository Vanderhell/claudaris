#ifndef PC_ALIGN_UP_U32_H
#define PC_ALIGN_UP_U32_H
#include <stdbool.h>
#include <stdint.h>

/* Round value up to a multiple of any positive alignment. */
bool pc_align_up_u32(uint32_t value, uint32_t alignment, uint32_t *aligned);
#endif

/* Canonical facade; the legacy implementation and contract are preserved. */
#ifndef pc_align_up_u32
#define pc_align_up_u32 pc_align_up_u32
#endif
#ifndef pc_align_up_u32
#define pc_align_up_u32 pc_align_up_u32
#endif
#ifndef PC_PC_ALIGN_UP_U32_H
#define PC_PC_ALIGN_UP_U32_H PC_ALIGN_UP_U32_H
#endif

