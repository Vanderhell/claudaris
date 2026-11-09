#ifndef PC_ACCUMULATE_ABS_I32_H
#define PC_ACCUMULATE_ABS_I32_H
#include <stdbool.h>
#include <stdint.h>
/* Add the exact magnitude of value to *accumulator; overflow leaves it unchanged. */
bool pc_accumulate_abs_i32(int32_t value, uint64_t *accumulator);
#endif

/* Canonical facade; the legacy implementation and contract are preserved. */
#ifndef pc_accumulate_abs_i32
#define pc_accumulate_abs_i32 pc_accumulate_abs_i32
#endif
#ifndef pc_accumulate_abs_i32
#define pc_accumulate_abs_i32 pc_accumulate_abs_i32
#endif
#ifndef PC_ACCUMULATE_ABS_I32_H
#define PC_ACCUMULATE_ABS_I32_H PC_ACCUMULATE_ABS_I32_H
#endif

