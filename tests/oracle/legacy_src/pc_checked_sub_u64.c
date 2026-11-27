#include "pc_checked_sub_u64.h"
#include <stddef.h>

bool pc_checked_sub_u64(uint64_t a, uint64_t b, uint64_t *result)
{
    if (result == NULL || b > a) return false;
    *result = a - b;
    return true;
}
