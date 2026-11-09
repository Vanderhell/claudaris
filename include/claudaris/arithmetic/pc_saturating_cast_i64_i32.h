#ifndef PRIMITIVECORE_SATURATING_CAST_I64_I32_H
#define PRIMITIVECORE_SATURATING_CAST_I64_I32_H
#include <stdint.h>
/* Clamp value to the int32_t range and return it. */
int32_t rm_saturating_cast_i64_i32(int64_t value);
#endif

/* Canonical facade; the legacy implementation and contract are preserved. */
#ifndef pc_saturating_cast_i64_i32
#define pc_saturating_cast_i64_i32 rm_saturating_cast_i64_i32
#endif
#ifndef pc_saturating_cast_i64_i32
#define pc_saturating_cast_i64_i32 rm_saturating_cast_i64_i32
#endif
#ifndef PC_PRIMITIVECORE_SATURATING_CAST_I64_I32_H
#define PC_PRIMITIVECORE_SATURATING_CAST_I64_I32_H PRIMITIVECORE_SATURATING_CAST_I64_I32_H
#endif

