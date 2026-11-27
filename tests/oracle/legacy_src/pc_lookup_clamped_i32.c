#include "pc_lookup_clamped_i32.h"

bool pc_lookup_clamped_i32(const int32_t *table, size_t count, int32_t index,
                           int32_t *value)
{
    size_t selected;
    if (table == NULL || count == 0u || value == NULL) return false;
    if (index < 0) selected = 0u;
    else if ((uint32_t)index >= count) selected = count - 1u;
    else selected = (size_t)(uint32_t)index;
    *value = table[selected];
    return true;
}
