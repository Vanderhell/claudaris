#include "pc_range_intersects_i32.h"

bool rm_range_intersects_i32(int32_t a_lower, int32_t a_upper,
                             int32_t b_lower, int32_t b_upper)
{
    return a_lower <= a_upper && b_lower <= b_upper &&
           a_lower <= b_upper && b_lower <= a_upper;
}
