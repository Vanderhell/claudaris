#include "pc_saturating_sub_i64.h"
#include <limits.h>

int64_t pc_saturating_sub_i64(int64_t a, int64_t b)
{
    if (b < 0 && a > INT64_MAX + b) return INT64_MAX;
    if (b > 0 && a < INT64_MIN + b) return INT64_MIN;
    return a - b;
}
