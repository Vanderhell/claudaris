#ifndef PRIMITIVECORE_PC_SATURATING_ADD_I64_H
#define PRIMITIVECORE_PC_SATURATING_ADD_I64_H

#include <stdint.h>

/* Return a+b clipped to INT64_MIN..INT64_MAX without signed overflow. */
int64_t pc_saturating_add_i64(int64_t a, int64_t b);

#endif
