#ifndef PC_CHECKED_SHL_I32_H
#define PC_CHECKED_SHL_I32_H
#include <stdbool.h>
#include <stdint.h>
/* Store value*2^shift exactly. False for shift >= 32, int32_t overflow, or
 * null output; failure leaves output unchanged. */
bool pc_checked_shl_i32(int32_t value, unsigned shift, int32_t *result);
#endif

/* Canonical facade; the legacy implementation and contract are preserved. */
#ifndef pc_checked_shl_i32
#define pc_checked_shl_i32 pc_checked_shl_i32
#endif
#ifndef pc_checked_shl_i32
#define pc_checked_shl_i32 pc_checked_shl_i32
#endif
#ifndef PC_PC_CHECKED_SHL_I32_H
#define PC_PC_CHECKED_SHL_I32_H PC_CHECKED_SHL_I32_H
#endif

