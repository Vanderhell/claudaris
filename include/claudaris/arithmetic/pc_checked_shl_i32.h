#ifndef PRIMITIVECORE_CHECKED_SHL_I32_H
#define PRIMITIVECORE_CHECKED_SHL_I32_H
#include <stdbool.h>
#include <stdint.h>
/* Store value*2^shift exactly. False for shift >= 32, int32_t overflow, or
 * null output; failure leaves output unchanged. */
bool rm_checked_shl_i32(int32_t value, unsigned shift, int32_t *result);
#endif

/* Canonical facade; the legacy implementation and contract are preserved. */
#ifndef pc_checked_shl_i32
#define pc_checked_shl_i32 rm_checked_shl_i32
#endif
#ifndef pc_checked_shl_i32
#define pc_checked_shl_i32 rm_checked_shl_i32
#endif
#ifndef PC_PRIMITIVECORE_CHECKED_SHL_I32_H
#define PC_PRIMITIVECORE_CHECKED_SHL_I32_H PRIMITIVECORE_CHECKED_SHL_I32_H
#endif

