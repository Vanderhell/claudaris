#include "pc_checked_abs_i64.h"

#include <limits.h>
#include <stddef.h>

bool pc_checked_abs_i64(int64_t value, int64_t *result)
{
    if (result == NULL || value == INT64_MIN) {
        return false;
    }

    *result = (value < 0) ? -value : value;
    return true;
}
