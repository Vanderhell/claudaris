#ifndef PC_PERIOD_ALIGN_U32_H
#define PC_PERIOD_ALIGN_U32_H
#include <stdbool.h>
#include <stdint.h>
/* First origin + k*period at or after time; false on invalid input/overflow. */
bool pc_period_align_u32(uint32_t time, uint32_t origin, uint32_t period,
                         uint32_t *aligned);
#endif

/* Canonical facade; the legacy implementation and contract are preserved. */
#ifndef pc_period_align_u32
#define pc_period_align_u32 pc_period_align_u32
#endif
#ifndef pc_period_align_u32
#define pc_period_align_u32 pc_period_align_u32
#endif
#ifndef PC_PC_PERIOD_ALIGN_U32_H
#define PC_PC_PERIOD_ALIGN_U32_H PC_PERIOD_ALIGN_U32_H
#endif

