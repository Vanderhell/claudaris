#ifndef PC_RANGE_SHRINK_I32_H
#define PC_RANGE_SHRINK_I32_H
#include <stdbool.h>
#include <stdint.h>
/* Symmetrically shrink a closed range; crossing endpoints fails. */
bool pc_range_shrink_i32(int32_t lower, int32_t upper, uint32_t amount,
                         int32_t *shrunk_lower, int32_t *shrunk_upper);
#endif

/* Canonical facade; the legacy implementation and contract are preserved. */
#ifndef pc_range_shrink_i32
#define pc_range_shrink_i32 pc_range_shrink_i32
#endif
#ifndef pc_range_shrink_i32
#define pc_range_shrink_i32 pc_range_shrink_i32
#endif
#ifndef PC_PC_RANGE_SHRINK_I32_H
#define PC_PC_RANGE_SHRINK_I32_H PC_RANGE_SHRINK_I32_H
#endif

