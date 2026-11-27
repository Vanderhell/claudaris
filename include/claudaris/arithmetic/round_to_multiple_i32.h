#ifndef CLAUDARIS_ARITHMETIC_ROUND_TO_MULTIPLE_I32_H
#define CLAUDARIS_ARITHMETIC_ROUND_TO_MULTIPLE_I32_H
#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Nearest positive multiple, ties to even; false on invalid step/overflow. */
bool claudaris_round_to_multiple_i32(int32_t value, int32_t multiple,
                              int32_t *rounded);


#ifdef __cplusplus
}
#endif

#endif /* CLAUDARIS_ARITHMETIC_ROUND_TO_MULTIPLE_I32_H */
