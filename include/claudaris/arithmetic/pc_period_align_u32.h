#ifndef PRIMITIVECORE_PERIOD_ALIGN_U32_H
#define PRIMITIVECORE_PERIOD_ALIGN_U32_H
#include <stdbool.h>
#include <stdint.h>
/* First origin + k*period at or after time; false on invalid input/overflow. */
bool rm_period_align_u32(uint32_t time, uint32_t origin, uint32_t period,
                         uint32_t *aligned);
#endif

/* Canonical facade; the legacy implementation and contract are preserved. */
#ifndef pc_period_align_u32
#define pc_period_align_u32 rm_period_align_u32
#endif
#ifndef pc_period_align_u32
#define pc_period_align_u32 rm_period_align_u32
#endif
#ifndef PC_PRIMITIVECORE_PERIOD_ALIGN_U32_H
#define PC_PRIMITIVECORE_PERIOD_ALIGN_U32_H PRIMITIVECORE_PERIOD_ALIGN_U32_H
#endif

