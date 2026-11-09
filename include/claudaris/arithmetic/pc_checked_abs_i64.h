#ifndef PRIMITIVECORE_CHECKED_ABS_I64_H
#define PRIMITIVECORE_CHECKED_ABS_I64_H

#include <stdbool.h>
#include <stdint.h>

/* Store |value| in *result. Return false if result is null or the result is
 * not representable (value == INT64_MIN); on failure, do not write output. */
bool rm_checked_abs_i64(int64_t value, int64_t *result);

#endif

/* Canonical facade; the legacy implementation and contract are preserved. */
#ifndef pc_checked_abs_i64
#define pc_checked_abs_i64 rm_checked_abs_i64
#endif
#ifndef pc_checked_abs_i64
#define pc_checked_abs_i64 rm_checked_abs_i64
#endif
#ifndef PC_PRIMITIVECORE_CHECKED_ABS_I64_H
#define PC_PRIMITIVECORE_CHECKED_ABS_I64_H PRIMITIVECORE_CHECKED_ABS_I64_H
#endif

