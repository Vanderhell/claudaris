#ifndef PC_PC_SATURATING_SUB_I64_H
#define PC_PC_SATURATING_SUB_I64_H

#include <stdint.h>

/* Return a-b clipped to INT64_MIN..INT64_MAX without signed overflow. */
int64_t pc_saturating_sub_i64(int64_t a, int64_t b);

#endif
