#ifndef PC_PC_ABS_DIFF_I64_U64_H
#define PC_PC_ABS_DIFF_I64_U64_H

#include <stdint.h>

/* Return exact |a-b| as uint64 for any signed int64 inputs. */
uint64_t pc_abs_diff_i64_u64(int64_t a, int64_t b);

#endif
