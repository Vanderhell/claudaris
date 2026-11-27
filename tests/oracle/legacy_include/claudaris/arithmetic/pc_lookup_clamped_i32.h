#ifndef PC_LOOKUP_CLAMPED_I32_H
#define PC_LOOKUP_CLAMPED_I32_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

/* Return table[clamp(index, 0, count-1)]; invalid arguments leave value unchanged.
 * table must reference count readable elements. */
bool pc_lookup_clamped_i32(const int32_t *table, size_t count, int32_t index,
                           int32_t *value);

#endif

/* Canonical facade; the legacy implementation and contract are preserved. */
#ifndef pc_lookup_clamped_i32
#define pc_lookup_clamped_i32 pc_lookup_clamped_i32
#endif
#ifndef pc_lookup_clamped_i32
#define pc_lookup_clamped_i32 pc_lookup_clamped_i32
#endif
#ifndef PC_LOOKUP_CLAMPED_I32_H
#define PC_LOOKUP_CLAMPED_I32_H PC_LOOKUP_CLAMPED_I32_H
#endif

