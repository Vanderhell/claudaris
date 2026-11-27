#include <claudaris/arithmetic/checked_mul_u64.h>
#include <stddef.h>

bool claudaris_checked_mul_u64(uint64_t a, uint64_t b, uint64_t *result)
{
    if (result == NULL || (b != 0u && a > UINT64_MAX / b)) return false;
    *result = a * b;
    return true;
}
