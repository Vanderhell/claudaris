#ifndef PRIMITIVECORE_PC_TIME_DURATION_ABSDIFF_U64_H
#define PRIMITIVECORE_PC_TIME_DURATION_ABSDIFF_U64_H
#include <stdint.h>
/* Return ordinary unsigned magnitude |a-b|; this is not modular wrap math. */
uint64_t pc_time_duration_absdiff_u64(uint64_t a, uint64_t b);
#endif
