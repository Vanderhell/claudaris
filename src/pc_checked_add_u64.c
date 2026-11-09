#include "pc_checked_add_u64.h"
#include <stddef.h>

bool pc_checked_add_u64(uint64_t a, uint64_t b, uint64_t *result)
{
    if (result == NULL || b > UINT64_MAX - a) return false;
    *result = a + b;
    return true;
}
