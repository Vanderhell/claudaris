#include <claudaris/arithmetic/size_mul_checked_u32.h>
#include <stddef.h>

bool claudaris_size_mul_checked_u32(uint32_t a, uint32_t b, uint32_t *product)
{
    if (product == NULL || (a != 0u && b > UINT32_MAX / a)) {
        return false;
    }
    *product = a * b;
    return true;
}
