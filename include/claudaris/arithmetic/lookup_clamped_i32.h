#ifndef CLAUDARIS_ARITHMETIC_LOOKUP_CLAMPED_I32_H
#define CLAUDARIS_ARITHMETIC_LOOKUP_CLAMPED_I32_H
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif



/* Return table[clamp(index, 0, count-1)]; invalid arguments leave value unchanged.
 * table must reference count readable elements. */
bool claudaris_lookup_clamped_i32(const int32_t *table, size_t count, int32_t index,
                           int32_t *value);



#ifdef __cplusplus
}
#endif

#endif /* CLAUDARIS_ARITHMETIC_LOOKUP_CLAMPED_I32_H */
