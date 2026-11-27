#ifndef CLAUDARIS_ARITHMETIC_FLOOR_TO_MULTIPLE_I32_H
#define CLAUDARIS_ARITHMETIC_FLOOR_TO_MULTIPLE_I32_H
#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Floor to a positive multiple; false on invalid step or result overflow. */
bool claudaris_floor_to_multiple_i32(int32_t value, int32_t multiple,
                              int32_t *rounded);


#ifdef __cplusplus
}
#endif

#endif /* CLAUDARIS_ARITHMETIC_FLOOR_TO_MULTIPLE_I32_H */
