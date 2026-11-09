#include "pc_checked_mul_i64.h"
#include <limits.h>
#include <stddef.h>

bool rm_checked_mul_i64(int64_t a, int64_t b, int64_t *result)
{
    if (result == NULL) return false;
    if (a == 0 || b == 0) {
        *result = 0;
        return true;
    }
    if (a == -1 && b == INT64_MIN) return false;
    if (b == -1 && a == INT64_MIN) return false;
    if (a > 0) {
        if ((b > 0 && a > INT64_MAX / b) ||
            (b < 0 && b < INT64_MIN / a)) return false;
    } else {
        if ((b > 0 && a < INT64_MIN / b) ||
            (b < 0 && a < INT64_MAX / b)) return false;
    }
    *result = a * b;
    return true;
}
