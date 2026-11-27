#ifndef CLAUDARIS_ARITHMETIC_PERIOD_ALIGN_U32_H
#define CLAUDARIS_ARITHMETIC_PERIOD_ALIGN_U32_H
#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/* First origin + k*period at or after time; false on invalid input/overflow. */
bool claudaris_period_align_u32(uint32_t time, uint32_t origin, uint32_t period,
                         uint32_t *aligned);


#ifdef __cplusplus
}
#endif

#endif /* CLAUDARIS_ARITHMETIC_PERIOD_ALIGN_U32_H */
