#ifndef CLAUDARIS_ARITHMETIC_TIME_DURATION_ABSDIFF_U64_H
#define CLAUDARIS_ARITHMETIC_TIME_DURATION_ABSDIFF_U64_H
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Return ordinary unsigned magnitude |a-b|; this is not modular wrap math. */
uint64_t claudaris_time_duration_absdiff_u64(uint64_t a, uint64_t b);

#ifdef __cplusplus
}
#endif

#endif /* CLAUDARIS_ARITHMETIC_TIME_DURATION_ABSDIFF_U64_H */
