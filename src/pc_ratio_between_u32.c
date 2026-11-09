#include "pc_ratio_between_u32.h"
#include <stddef.h>

bool rm_ratio_between_u32(uint32_t numerator, uint32_t denominator,
                          uint32_t lower_num, uint32_t lower_den,
                          uint32_t upper_num, uint32_t upper_den,
                          bool *is_between)
{
    if (is_between == NULL || denominator == 0u || lower_den == 0u ||
        upper_den == 0u) return false;
    if ((uint64_t)lower_num * upper_den > (uint64_t)upper_num * lower_den)
        return false;
    *is_between = (uint64_t)numerator * lower_den >= (uint64_t)lower_num * denominator &&
                  (uint64_t)numerator * upper_den <= (uint64_t)upper_num * denominator;
    return true;
}
