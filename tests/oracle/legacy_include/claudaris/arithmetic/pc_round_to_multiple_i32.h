#ifndef PC_ROUND_TO_MULTIPLE_I32_H
#define PC_ROUND_TO_MULTIPLE_I32_H
#include <stdbool.h>
#include <stdint.h>
/* Nearest positive multiple, ties to even; false on invalid step/overflow. */
bool pc_round_to_multiple_i32(int32_t value, int32_t multiple,
                              int32_t *rounded);
#endif

/* Canonical facade; the legacy implementation and contract are preserved. */
#ifndef pc_round_to_multiple_i32
#define pc_round_to_multiple_i32 pc_round_to_multiple_i32
#endif
#ifndef pc_round_to_multiple_i32
#define pc_round_to_multiple_i32 pc_round_to_multiple_i32
#endif
#ifndef PC_PC_ROUND_TO_MULTIPLE_I32_H
#define PC_PC_ROUND_TO_MULTIPLE_I32_H PC_ROUND_TO_MULTIPLE_I32_H
#endif

