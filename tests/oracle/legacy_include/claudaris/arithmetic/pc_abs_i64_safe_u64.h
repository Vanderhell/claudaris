#ifndef PC_PC_ABS_I64_SAFE_U64_H
#define PC_PC_ABS_I64_SAFE_U64_H

#include <stdint.h>

/* Return the exact unsigned magnitude of any int64, including INT64_MIN. */
uint64_t pc_abs_i64_safe_u64(int64_t value);

#endif
