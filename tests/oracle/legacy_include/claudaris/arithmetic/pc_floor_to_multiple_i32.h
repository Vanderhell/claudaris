#ifndef PC_FLOOR_TO_MULTIPLE_I32_H
#define PC_FLOOR_TO_MULTIPLE_I32_H
#include <stdbool.h>
#include <stdint.h>
/* Floor to a positive multiple; false on invalid step or result overflow. */
bool pc_floor_to_multiple_i32(int32_t value, int32_t multiple,
                              int32_t *rounded);
#endif

/* Canonical facade; the legacy implementation and contract are preserved. */
#ifndef pc_floor_to_multiple_i32
#define pc_floor_to_multiple_i32 pc_floor_to_multiple_i32
#endif
#ifndef pc_floor_to_multiple_i32
#define pc_floor_to_multiple_i32 pc_floor_to_multiple_i32
#endif
#ifndef PC_PC_FLOOR_TO_MULTIPLE_I32_H
#define PC_PC_FLOOR_TO_MULTIPLE_I32_H PC_FLOOR_TO_MULTIPLE_I32_H
#endif

