#ifndef CLAUDARIS_ARITHMETIC_PERIOD_FLOOR_U32_H
#define CLAUDARIS_ARITHMETIC_PERIOD_FLOOR_U32_H
#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Greatest origin + k*period <= time for k>=0; false when none exists. */
bool claudaris_period_floor_u32(uint32_t time, uint32_t origin, uint32_t period,
                         uint32_t *aligned);


#ifdef __cplusplus
}
#endif

#endif /* CLAUDARIS_ARITHMETIC_PERIOD_FLOOR_U32_H */
