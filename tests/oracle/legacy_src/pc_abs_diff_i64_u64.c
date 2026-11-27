#include "pc_abs_diff_i64_u64.h"

uint64_t pc_abs_diff_i64_u64(int64_t a, int64_t b)
{
    const uint64_t ua = (uint64_t)a;
    const uint64_t ub = (uint64_t)b;
    return a >= b ? ua - ub : ub - ua;
}
