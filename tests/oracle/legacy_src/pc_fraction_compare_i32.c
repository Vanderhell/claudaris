#include "pc_fraction_compare_i32.h"
#include <stddef.h>

bool pc_fraction_compare_i32(int32_t a_num, int32_t a_den,
                             int32_t b_num, int32_t b_den,
                             int *comparison)
{
    int64_t an = a_num, ad = a_den, bn = b_num, bd = b_den;
    int64_t left, right;
    if (comparison == NULL || ad == 0 || bd == 0) return false;
    if (ad < 0) { an = -an; ad = -ad; }
    if (bd < 0) { bn = -bn; bd = -bd; }
    left = an * bd;
    right = bn * ad;
    *comparison = (left > right) - (left < right);
    return true;
}
