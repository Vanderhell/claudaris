#ifndef PC_RANGE_INTERSECTS_I32_H
#define PC_RANGE_INTERSECTS_I32_H
#include <stdbool.h>
#include <stdint.h>
/* Closed interval intersection; either inverted interval yields false. */
bool pc_range_intersects_i32(int32_t a_lower, int32_t a_upper,
                             int32_t b_lower, int32_t b_upper);
#endif

/* Canonical facade; the legacy implementation and contract are preserved. */
#ifndef pc_range_intersects_i32
#define pc_range_intersects_i32 pc_range_intersects_i32
#endif
#ifndef pc_range_intersects_i32
#define pc_range_intersects_i32 pc_range_intersects_i32
#endif
#ifndef PC_PC_RANGE_INTERSECTS_I32_H
#define PC_PC_RANGE_INTERSECTS_I32_H PC_RANGE_INTERSECTS_I32_H
#endif

