#ifndef PC_CEIL_TO_MULTIPLE_I32_H
#define PC_CEIL_TO_MULTIPLE_I32_H
#include <stdbool.h>
#include <stdint.h>
/* Ceiling to a positive multiple; false on invalid step or result overflow. */
bool pc_ceil_to_multiple_i32(int32_t value, int32_t multiple,
                             int32_t *rounded);
#endif

/* Canonical facade; the legacy implementation and contract are preserved. */
#ifndef pc_ceil_to_multiple_i32
#define pc_ceil_to_multiple_i32 pc_ceil_to_multiple_i32
#endif
#ifndef pc_ceil_to_multiple_i32
#define pc_ceil_to_multiple_i32 pc_ceil_to_multiple_i32
#endif
#ifndef PC_PC_CEIL_TO_MULTIPLE_I32_H
#define PC_PC_CEIL_TO_MULTIPLE_I32_H PC_CEIL_TO_MULTIPLE_I32_H
#endif

