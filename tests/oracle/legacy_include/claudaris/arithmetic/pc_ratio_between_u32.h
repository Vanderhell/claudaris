#ifndef PC_RATIO_BETWEEN_U32_H
#define PC_RATIO_BETWEEN_U32_H
#include <stdbool.h>
#include <stdint.h>
/* Test inclusive ratio bounds. Invalid/zero denominators return false status. */
bool pc_ratio_between_u32(uint32_t numerator, uint32_t denominator,
                          uint32_t lower_num, uint32_t lower_den,
                          uint32_t upper_num, uint32_t upper_den,
                          bool *is_between);
#endif

/* Canonical facade; the legacy implementation and contract are preserved. */
#ifndef pc_ratio_between_u32
#define pc_ratio_between_u32 pc_ratio_between_u32
#endif
#ifndef pc_ratio_between_u32
#define pc_ratio_between_u32 pc_ratio_between_u32
#endif
#ifndef PC_PC_RATIO_BETWEEN_U32_H
#define PC_PC_RATIO_BETWEEN_U32_H PC_RATIO_BETWEEN_U32_H
#endif

