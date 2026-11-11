#include <Arduino.h>
#include <esp_cpu.h>
extern "C" {
#include "../../../include/claudaris/arithmetic/pc_abs_diff_i64_u64.h"
#include "../../../include/claudaris/arithmetic/pc_abs_i64_safe_u64.h"
#include "../../../include/claudaris/arithmetic/pc_accumulate_abs_i32.h"
#include "../../../include/claudaris/arithmetic/pc_align_down_u32.h"
#include "../../../include/claudaris/arithmetic/pc_align_up_u32.h"
#include "../../../include/claudaris/arithmetic/pc_ceil_to_multiple_i32.h"
#include "../../../include/claudaris/arithmetic/pc_checked_abs_i64.h"
#include "../../../include/claudaris/arithmetic/pc_checked_add_i64.h"
#include "../../../include/claudaris/arithmetic/pc_checked_add_u64.h"
#include "../../../include/claudaris/arithmetic/pc_checked_mul_i64.h"
#include "../../../include/claudaris/arithmetic/pc_checked_mul_u64.h"
#include "../../../include/claudaris/arithmetic/pc_checked_neg_i64.h"
#include "../../../include/claudaris/arithmetic/pc_checked_shl_i32.h"
#include "../../../include/claudaris/arithmetic/pc_checked_shl_u32.h"
#include "../../../include/claudaris/arithmetic/pc_checked_sub_i64.h"
#include "../../../include/claudaris/arithmetic/pc_checked_sub_u64.h"
#include "../../../include/claudaris/arithmetic/pc_floor_to_multiple_i32.h"
#include "../../../include/claudaris/arithmetic/pc_fraction_compare_i32.h"
#include "../../../include/claudaris/arithmetic/pc_is_aligned_u32.h"
#include "../../../include/claudaris/arithmetic/pc_lookup_clamped_i32.h"
#include "../../../include/claudaris/arithmetic/pc_mask_range_u64.h"
#include "../../../include/claudaris/arithmetic/pc_nearest_multiple_u32.h"
#include "../../../include/claudaris/arithmetic/pc_offset_range_check_u32.h"
#include "../../../include/claudaris/arithmetic/pc_period_align_u32.h"
#include "../../../include/claudaris/arithmetic/pc_period_floor_u32.h"
#include "../../../include/claudaris/arithmetic/pc_range_center_i32.h"
#include "../../../include/claudaris/arithmetic/pc_range_intersects_i32.h"
#include "../../../include/claudaris/arithmetic/pc_range_shrink_i32.h"
#include "../../../include/claudaris/arithmetic/pc_ratio_between_u32.h"
#include "../../../include/claudaris/arithmetic/pc_ratio_ceil_u32.h"
#include "../../../include/claudaris/arithmetic/pc_ratio_round_even_u32.h"
#include "../../../include/claudaris/arithmetic/pc_round_to_multiple_i32.h"
#include "../../../include/claudaris/arithmetic/pc_saturating_add_i64.h"
#include "../../../include/claudaris/arithmetic/pc_saturating_add_u64.h"
#include "../../../include/claudaris/arithmetic/pc_saturating_cast_i64_i32.h"
#include "../../../include/claudaris/arithmetic/pc_saturating_cast_u64_u32.h"
#include "../../../include/claudaris/arithmetic/pc_saturating_mul_u64.h"
#include "../../../include/claudaris/arithmetic/pc_saturating_sub_i64.h"
#include "../../../include/claudaris/arithmetic/pc_saturating_sub_u64.h"
#include "../../../include/claudaris/arithmetic/pc_size_add_checked_u32.h"
#include "../../../include/claudaris/arithmetic/pc_size_mul_checked_u32.h"
#include "../../../include/claudaris/arithmetic/pc_time_convert_ceil_u64.h"
#include "../../../include/claudaris/arithmetic/pc_time_convert_floor_u64.h"
#include "../../../include/claudaris/arithmetic/pc_time_duration_absdiff_u64.h"
#include "../../../include/claudaris/arithmetic/pc_time_duration_clamp_u64.h"
#include "../../../include/claudaris/arithmetic/pc_time_scale_ratio_u64.h"
#include "../../../src/pc_abs_diff_i64_u64.c"
#include "../../../src/pc_abs_i64_safe_u64.c"
#include "../../../src/pc_accumulate_abs_i32.c"
#include "../../../src/pc_align_down_u32.c"
#include "../../../src/pc_align_up_u32.c"
#include "../../../src/pc_ceil_to_multiple_i32.c"
#include "../../../src/pc_checked_abs_i64.c"
#include "../../../src/pc_checked_add_i64.c"
#include "../../../src/pc_checked_add_u64.c"
#include "../../../src/pc_checked_mul_i64.c"
#include "../../../src/pc_checked_mul_u64.c"
#include "../../../src/pc_checked_neg_i64.c"
#include "../../../src/pc_checked_shl_i32.c"
#include "../../../src/pc_checked_shl_u32.c"
#include "../../../src/pc_checked_sub_i64.c"
#include "../../../src/pc_checked_sub_u64.c"
#include "../../../src/pc_floor_to_multiple_i32.c"
#include "../../../src/pc_fraction_compare_i32.c"
#include "../../../src/pc_is_aligned_u32.c"
#include "../../../src/pc_lookup_clamped_i32.c"
#include "../../../src/pc_mask_range_u64.c"
#include "../../../src/pc_nearest_multiple_u32.c"
#include "../../../src/pc_offset_range_check_u32.c"
#include "../../../src/pc_period_align_u32.c"
#include "../../../src/pc_period_floor_u32.c"
#include "../../../src/pc_range_center_i32.c"
#include "../../../src/pc_range_intersects_i32.c"
#include "../../../src/pc_range_shrink_i32.c"
#include "../../../src/pc_ratio_between_u32.c"
#include "../../../src/pc_ratio_ceil_u32.c"
#include "../../../src/pc_ratio_round_even_u32.c"
#include "../../../src/pc_round_to_multiple_i32.c"
#include "../../../src/pc_saturating_add_i64.c"
#include "../../../src/pc_saturating_add_u64.c"
#include "../../../src/pc_saturating_cast_i64_i32.c"
#include "../../../src/pc_saturating_cast_u64_u32.c"
#include "../../../src/pc_saturating_mul_u64.c"
#include "../../../src/pc_saturating_sub_i64.c"
#include "../../../src/pc_saturating_sub_u64.c"
#include "../../../src/pc_size_add_checked_u32.c"
#include "../../../src/pc_size_mul_checked_u32.c"
#include "../../../src/pc_time_convert_ceil_u64.c"
#include "../../../src/pc_time_convert_floor_u64.c"
#include "../../../src/pc_time_duration_absdiff_u64.c"
#include "../../../src/pc_time_duration_clamp_u64.c"
#include "../../../src/pc_time_ratio_internal.c"
#include "../../../src/pc_time_scale_ratio_u64.c"
}

static uint32_t cycles[46];
static uint32_t passed = 0u;
static uint32_t first_failure = 0u;

#define RUN_API(index, expression) do { \
    const uint32_t start_cycle = esp_cpu_get_cycle_count(); \
    const bool ok = (expression); \
    cycles[(index) - 1u] = esp_cpu_get_cycle_count() - start_cycle; \
    if (ok) ++passed; else if (first_failure == 0u) first_failure = (index); \
} while (0)

void setup()
{
    Serial.begin(115200);
    delay(1500);
    int64_t i64 = 0;
    int32_t i32 = 0, lo = 0, hi = 0;
    int cmp = 0;
    uint32_t u32 = 0u;
    uint64_t u64 = 0u;
    bool flag = false;
    const int32_t table[3] = {3, 5, 8};
    RUN_API(1u, pc_abs_diff_i64_u64(INT64_MIN, INT64_MAX) == UINT64_MAX); /* pc_abs_diff_i64_u64 */
    RUN_API(2u, pc_abs_i64_safe_u64(INT64_MIN) == (UINT64_C(1) << 63)); /* pc_abs_i64_safe_u64 */
    RUN_API(3u, (u64 = 0u, pc_accumulate_abs_i32(-5, &u64) && u64 == 5u)); /* pc_accumulate_abs_i32 */
    RUN_API(4u, pc_align_down_u32(17u, 8u, &u32) && u32 == 16u); /* pc_align_down_u32 */
    RUN_API(5u, pc_align_up_u32(17u, 8u, &u32) && u32 == 24u); /* pc_align_up_u32 */
    RUN_API(6u, pc_ceil_to_multiple_i32(-5, 2, &i32) && i32 == -4); /* pc_ceil_to_multiple_i32 */
    RUN_API(7u, pc_checked_abs_i64(-7, &i64) && i64 == 7); /* pc_checked_abs_i64 */
    RUN_API(8u, pc_checked_add_i64(INT64_MAX, 0, &i64) && i64 == INT64_MAX); /* pc_checked_add_i64 */
    RUN_API(9u, pc_checked_add_u64(UINT64_MAX, 0u, &u64) && u64 == UINT64_MAX); /* pc_checked_add_u64 */
    RUN_API(10u, pc_checked_mul_i64(-7, 9, &i64) && i64 == -63); /* pc_checked_mul_i64 */
    RUN_API(11u, pc_checked_mul_u64(UINT64_MAX, 1u, &u64) && u64 == UINT64_MAX); /* pc_checked_mul_u64 */
    RUN_API(12u, pc_checked_neg_i64(-9, &i64) && i64 == 9); /* pc_checked_neg_i64 */
    RUN_API(13u, pc_checked_shl_i32(-3, 4u, &i32) && i32 == -48); /* pc_checked_shl_i32 */
    RUN_API(14u, pc_checked_shl_u32(1u, 31u, &u32) && u32 == UINT32_C(0x80000000)); /* pc_checked_shl_u32 */
    RUN_API(15u, pc_checked_sub_i64(INT64_MIN, 0, &i64) && i64 == INT64_MIN); /* pc_checked_sub_i64 */
    RUN_API(16u, pc_checked_sub_u64(UINT64_MAX, 0u, &u64) && u64 == UINT64_MAX); /* pc_checked_sub_u64 */
    RUN_API(17u, pc_floor_to_multiple_i32(-5, 2, &i32) && i32 == -6); /* pc_floor_to_multiple_i32 */
    RUN_API(18u, pc_fraction_compare_i32(-1, 2, 1, 3, &cmp) && cmp == -1); /* pc_fraction_compare_i32 */
    RUN_API(19u, pc_is_aligned_u32(21u, 7u)); /* pc_is_aligned_u32 */
    RUN_API(20u, pc_lookup_clamped_i32(table, 3u, 1, &i32) && i32 == 5); /* pc_lookup_clamped_i32 */
    RUN_API(21u, pc_mask_range_u64(1u, 3u, &u64) && u64 == UINT64_C(14)); /* pc_mask_range_u64 */
    RUN_API(22u, pc_nearest_multiple_u32(5u, 2u, &u32) && u32 == 4u); /* pc_nearest_multiple_u32 */
    RUN_API(23u, pc_offset_range_check_u32(3u, 4u, 7u)); /* pc_offset_range_check_u32 */
    RUN_API(24u, pc_period_align_u32(12u, 0u, 5u, &u32) && u32 == 15u); /* pc_period_align_u32 */
    RUN_API(25u, pc_period_floor_u32(12u, 0u, 5u, &u32) && u32 == 10u); /* pc_period_floor_u32 */
    RUN_API(26u, pc_range_center_i32(-3, 2, &i32) && i32 == -1); /* pc_range_center_i32 */
    RUN_API(27u, pc_range_intersects_i32(1, 3, 3, 5)); /* pc_range_intersects_i32 */
    RUN_API(28u, pc_range_shrink_i32(0, 10, 2u, &lo, &hi) && lo == 2 && hi == 8); /* pc_range_shrink_i32 */
    RUN_API(29u, pc_ratio_between_u32(1u, 2u, 1u, 3u, 2u, 3u, &flag) && flag); /* pc_ratio_between_u32 */
    RUN_API(30u, pc_ratio_ceil_u32(10u, 3u, &u32) && u32 == 4u); /* pc_ratio_ceil_u32 */
    RUN_API(31u, pc_ratio_round_even_u32(5u, 2u, &u32) && u32 == 2u); /* pc_ratio_round_even_u32 */
    RUN_API(32u, pc_round_to_multiple_i32(-5, 2, &i32) && i32 == -4); /* pc_round_to_multiple_i32 */
    RUN_API(33u, pc_saturating_add_i64(INT64_MAX, 1) == INT64_MAX); /* pc_saturating_add_i64 */
    RUN_API(34u, pc_saturating_add_u64(UINT64_MAX, 1u) == UINT64_MAX); /* pc_saturating_add_u64 */
    RUN_API(35u, pc_saturating_cast_i64_i32((int64_t)INT32_MAX + 1) == INT32_MAX); /* pc_saturating_cast_i64_i32 */
    RUN_API(36u, pc_saturating_cast_u64_u32((uint64_t)UINT32_MAX + 1u) == UINT32_MAX); /* pc_saturating_cast_u64_u32 */
    RUN_API(37u, pc_saturating_mul_u64(UINT64_MAX, 2u) == UINT64_MAX); /* pc_saturating_mul_u64 */
    RUN_API(38u, pc_saturating_sub_i64(INT64_MIN, 1) == INT64_MIN); /* pc_saturating_sub_i64 */
    RUN_API(39u, pc_saturating_sub_u64(0u, 1u) == 0u); /* pc_saturating_sub_u64 */
    RUN_API(40u, pc_size_add_checked_u32(2u, 3u, &u32) && u32 == 5u); /* pc_size_add_checked_u32 */
    RUN_API(41u, pc_size_mul_checked_u32(3u, 4u, &u32) && u32 == 12u); /* pc_size_mul_checked_u32 */
    RUN_API(42u, pc_time_convert_ceil_u64(3u, 1u, 2u, &u64) && u64 == 2u); /* pc_time_convert_ceil_u64 */
    RUN_API(43u, pc_time_convert_floor_u64(3u, 1u, 2u, &u64) && u64 == 1u); /* pc_time_convert_floor_u64 */
    RUN_API(44u, pc_time_duration_absdiff_u64(UINT64_MAX, 0u) == UINT64_MAX); /* pc_time_duration_absdiff_u64 */
    RUN_API(45u, pc_time_duration_clamp_u64(5u, 10u, 20u, &u64) && u64 == 10u); /* pc_time_duration_clamp_u64 */
    RUN_API(46u, pc_time_scale_ratio_u64(5u, 1u, 2u, &u64) && u64 == 2u); /* pc_time_scale_ratio_u64 */
    for (uint32_t i = 0u; i < 46u; ++i) {
        Serial.printf("CLAUDARIS_CYCLE|%lu|%lu\n", (unsigned long)(i + 1u), (unsigned long)cycles[i]);
    }
    Serial.printf("CLAUDARIS_ALL_PASS|passed=%lu/46|first_failed_api=%lu\n", (unsigned long)passed, (unsigned long)first_failure);
}

void loop() { delay(1000); }
