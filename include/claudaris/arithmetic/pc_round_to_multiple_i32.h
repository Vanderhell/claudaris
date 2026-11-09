#ifndef PRIMITIVECORE_ROUND_TO_MULTIPLE_I32_H
#define PRIMITIVECORE_ROUND_TO_MULTIPLE_I32_H
#include <stdbool.h>
#include <stdint.h>
/* Nearest positive multiple, ties to even; false on invalid step/overflow. */
bool rm_round_to_multiple_i32(int32_t value, int32_t multiple,
                              int32_t *rounded);
#endif

/* Canonical facade; the legacy implementation and contract are preserved. */
#ifndef pc_round_to_multiple_i32
#define pc_round_to_multiple_i32 rm_round_to_multiple_i32
#endif
#ifndef pc_round_to_multiple_i32
#define pc_round_to_multiple_i32 rm_round_to_multiple_i32
#endif
#ifndef PC_PRIMITIVECORE_ROUND_TO_MULTIPLE_I32_H
#define PC_PRIMITIVECORE_ROUND_TO_MULTIPLE_I32_H PRIMITIVECORE_ROUND_TO_MULTIPLE_I32_H
#endif

