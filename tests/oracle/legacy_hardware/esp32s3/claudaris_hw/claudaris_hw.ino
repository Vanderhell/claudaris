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

static uint32_t passed = 0u;
static uint32_t first_failure = 0u;
static volatile int64_t arg_i64[6] = {INT64_MIN, INT64_MAX, -7, 9, 0, 1};
static volatile int32_t arg_i32[13] = {-5, -3, 2, 5, 1, 3, -1, 0, 10, 5, 0, 1, 3};
static volatile uint64_t arg_u64[10] = {UINT64_MAX, 0u, 1u, UINT64_C(4294967296), 2u, 3u, 2u, 5u, 10u, 20u};
static volatile uint32_t arg_u32[13] = {17u, 8u, 21u, 7u, 5u, 2u, 3u, 4u, 12u, 10u, 0u, 1u, UINT32_MAX};
static volatile unsigned arg_unsigned[2] = {4u, 31u};
static const int32_t table_data[3] = {3, 5, 8};
static volatile uint64_t benchmark_sink = 0u;
static volatile uint32_t empty_input = UINT32_C(0x35);
static const uint32_t benchmark_repetitions = 1000u;
static const uint32_t benchmark_samples = 31u;

#if defined(__GNUC__)
#define CLAUDARIS_NOINLINE __attribute__((noinline))
#else
#define CLAUDARIS_NOINLINE
#endif
typedef uint64_t (*bench_fn_t)(void);
#define RUN_API(index, expression) do { \
    const bool ok = (expression); \
    if (ok) ++passed; else if (first_failure == 0u) first_failure = (index); \
} while (0)

static uint64_t (* volatile api_ptr_pc_abs_diff_i64_u64)(int64_t, int64_t) = &pc_abs_diff_i64_u64;
static uint64_t baseline_pc_abs_diff_i64_u64(int64_t a, int64_t b)
{
    (void)a;
    (void)b;
    return (uint64_t)0;
}
static uint64_t (* volatile baseline_ptr_pc_abs_diff_i64_u64)(int64_t, int64_t) = &baseline_pc_abs_diff_i64_u64;
static CLAUDARIS_NOINLINE uint64_t bench_actual_pc_abs_diff_i64_u64(void)
{
    const uint64_t value = api_ptr_pc_abs_diff_i64_u64(arg_i64[0], arg_i64[1]);
    return (uint64_t)value;
}
static CLAUDARIS_NOINLINE uint64_t bench_baseline_pc_abs_diff_i64_u64(void)
{
    const uint64_t value = baseline_ptr_pc_abs_diff_i64_u64(arg_i64[0], arg_i64[1]);
    return (uint64_t)value;
}
static uint64_t (* volatile api_ptr_pc_abs_i64_safe_u64)(int64_t) = &pc_abs_i64_safe_u64;
static uint64_t baseline_pc_abs_i64_safe_u64(int64_t value)
{
    (void)value;
    return (uint64_t)0;
}
static uint64_t (* volatile baseline_ptr_pc_abs_i64_safe_u64)(int64_t) = &baseline_pc_abs_i64_safe_u64;
static CLAUDARIS_NOINLINE uint64_t bench_actual_pc_abs_i64_safe_u64(void)
{
    const uint64_t value = api_ptr_pc_abs_i64_safe_u64(arg_i64[0]);
    return (uint64_t)value;
}
static CLAUDARIS_NOINLINE uint64_t bench_baseline_pc_abs_i64_safe_u64(void)
{
    const uint64_t value = baseline_ptr_pc_abs_i64_safe_u64(arg_i64[0]);
    return (uint64_t)value;
}
static bool (* volatile api_ptr_pc_accumulate_abs_i32)(int32_t, uint64_t *) = &pc_accumulate_abs_i32;
static bool baseline_pc_accumulate_abs_i32(int32_t value, uint64_t * accumulator)
{
    (void)value;
    *accumulator = (uint64_t)0;
    return true;
}
static bool (* volatile baseline_ptr_pc_accumulate_abs_i32)(int32_t, uint64_t *) = &baseline_pc_accumulate_abs_i32;
static CLAUDARIS_NOINLINE uint64_t bench_actual_pc_accumulate_abs_i32(void)
{
    uint64_t accumulator = (uint64_t)0;
    const bool status = api_ptr_pc_accumulate_abs_i32(arg_i32[0], &accumulator);
    uint64_t value = status ? UINT64_C(1) : UINT64_C(0);
    value ^= (uint64_t)accumulator;
    return value;
}
static CLAUDARIS_NOINLINE uint64_t bench_baseline_pc_accumulate_abs_i32(void)
{
    uint64_t accumulator = (uint64_t)0;
    const bool status = baseline_ptr_pc_accumulate_abs_i32(arg_i32[0], &accumulator);
    uint64_t value = status ? UINT64_C(1) : UINT64_C(0);
    value ^= (uint64_t)accumulator;
    return value;
}
static bool (* volatile api_ptr_pc_align_down_u32)(uint32_t, uint32_t, uint32_t *) = &pc_align_down_u32;
static bool baseline_pc_align_down_u32(uint32_t value, uint32_t alignment, uint32_t * aligned)
{
    (void)value;
    (void)alignment;
    *aligned = (uint32_t)0;
    return true;
}
static bool (* volatile baseline_ptr_pc_align_down_u32)(uint32_t, uint32_t, uint32_t *) = &baseline_pc_align_down_u32;
static CLAUDARIS_NOINLINE uint64_t bench_actual_pc_align_down_u32(void)
{
    uint32_t aligned = (uint32_t)0;
    const bool status = api_ptr_pc_align_down_u32(arg_u32[0], arg_u32[1], &aligned);
    uint64_t value = status ? UINT64_C(1) : UINT64_C(0);
    value ^= (uint64_t)aligned;
    return value;
}
static CLAUDARIS_NOINLINE uint64_t bench_baseline_pc_align_down_u32(void)
{
    uint32_t aligned = (uint32_t)0;
    const bool status = baseline_ptr_pc_align_down_u32(arg_u32[0], arg_u32[1], &aligned);
    uint64_t value = status ? UINT64_C(1) : UINT64_C(0);
    value ^= (uint64_t)aligned;
    return value;
}
static bool (* volatile api_ptr_pc_align_up_u32)(uint32_t, uint32_t, uint32_t *) = &pc_align_up_u32;
static bool baseline_pc_align_up_u32(uint32_t value, uint32_t alignment, uint32_t * aligned)
{
    (void)value;
    (void)alignment;
    *aligned = (uint32_t)0;
    return true;
}
static bool (* volatile baseline_ptr_pc_align_up_u32)(uint32_t, uint32_t, uint32_t *) = &baseline_pc_align_up_u32;
static CLAUDARIS_NOINLINE uint64_t bench_actual_pc_align_up_u32(void)
{
    uint32_t aligned = (uint32_t)0;
    const bool status = api_ptr_pc_align_up_u32(arg_u32[0], arg_u32[1], &aligned);
    uint64_t value = status ? UINT64_C(1) : UINT64_C(0);
    value ^= (uint64_t)aligned;
    return value;
}
static CLAUDARIS_NOINLINE uint64_t bench_baseline_pc_align_up_u32(void)
{
    uint32_t aligned = (uint32_t)0;
    const bool status = baseline_ptr_pc_align_up_u32(arg_u32[0], arg_u32[1], &aligned);
    uint64_t value = status ? UINT64_C(1) : UINT64_C(0);
    value ^= (uint64_t)aligned;
    return value;
}
static bool (* volatile api_ptr_pc_ceil_to_multiple_i32)(int32_t, int32_t, int32_t *) = &pc_ceil_to_multiple_i32;
static bool baseline_pc_ceil_to_multiple_i32(int32_t value, int32_t multiple, int32_t * rounded)
{
    (void)value;
    (void)multiple;
    *rounded = (int32_t)0;
    return true;
}
static bool (* volatile baseline_ptr_pc_ceil_to_multiple_i32)(int32_t, int32_t, int32_t *) = &baseline_pc_ceil_to_multiple_i32;
static CLAUDARIS_NOINLINE uint64_t bench_actual_pc_ceil_to_multiple_i32(void)
{
    int32_t rounded = (int32_t)0;
    const bool status = api_ptr_pc_ceil_to_multiple_i32(arg_i32[0], arg_i32[2], &rounded);
    uint64_t value = status ? UINT64_C(1) : UINT64_C(0);
    value ^= (uint64_t)rounded;
    return value;
}
static CLAUDARIS_NOINLINE uint64_t bench_baseline_pc_ceil_to_multiple_i32(void)
{
    int32_t rounded = (int32_t)0;
    const bool status = baseline_ptr_pc_ceil_to_multiple_i32(arg_i32[0], arg_i32[2], &rounded);
    uint64_t value = status ? UINT64_C(1) : UINT64_C(0);
    value ^= (uint64_t)rounded;
    return value;
}
static bool (* volatile api_ptr_pc_checked_abs_i64)(int64_t, int64_t *) = &pc_checked_abs_i64;
static bool baseline_pc_checked_abs_i64(int64_t value, int64_t * result)
{
    (void)value;
    *result = (int64_t)0;
    return true;
}
static bool (* volatile baseline_ptr_pc_checked_abs_i64)(int64_t, int64_t *) = &baseline_pc_checked_abs_i64;
static CLAUDARIS_NOINLINE uint64_t bench_actual_pc_checked_abs_i64(void)
{
    int64_t result = (int64_t)0;
    const bool status = api_ptr_pc_checked_abs_i64(arg_i64[2], &result);
    uint64_t checksum = status ? UINT64_C(1) : UINT64_C(0);
    checksum ^= (uint64_t)result;
    return checksum;
}
static CLAUDARIS_NOINLINE uint64_t bench_baseline_pc_checked_abs_i64(void)
{
    int64_t result = (int64_t)0;
    const bool status = baseline_ptr_pc_checked_abs_i64(arg_i64[2], &result);
    uint64_t checksum = status ? UINT64_C(1) : UINT64_C(0);
    checksum ^= (uint64_t)result;
    return checksum;
}
static bool (* volatile api_ptr_pc_checked_add_i64)(int64_t, int64_t, int64_t *) = &pc_checked_add_i64;
static bool baseline_pc_checked_add_i64(int64_t a, int64_t b, int64_t * result)
{
    (void)a;
    (void)b;
    *result = (int64_t)0;
    return true;
}
static bool (* volatile baseline_ptr_pc_checked_add_i64)(int64_t, int64_t, int64_t *) = &baseline_pc_checked_add_i64;
static CLAUDARIS_NOINLINE uint64_t bench_actual_pc_checked_add_i64(void)
{
    int64_t result = (int64_t)0;
    const bool status = api_ptr_pc_checked_add_i64(arg_i64[1], arg_i64[4], &result);
    uint64_t checksum = status ? UINT64_C(1) : UINT64_C(0);
    checksum ^= (uint64_t)result;
    return checksum;
}
static CLAUDARIS_NOINLINE uint64_t bench_baseline_pc_checked_add_i64(void)
{
    int64_t result = (int64_t)0;
    const bool status = baseline_ptr_pc_checked_add_i64(arg_i64[1], arg_i64[4], &result);
    uint64_t checksum = status ? UINT64_C(1) : UINT64_C(0);
    checksum ^= (uint64_t)result;
    return checksum;
}
static bool (* volatile api_ptr_pc_checked_add_u64)(uint64_t, uint64_t, uint64_t *) = &pc_checked_add_u64;
static bool baseline_pc_checked_add_u64(uint64_t a, uint64_t b, uint64_t * result)
{
    (void)a;
    (void)b;
    *result = (uint64_t)0;
    return true;
}
static bool (* volatile baseline_ptr_pc_checked_add_u64)(uint64_t, uint64_t, uint64_t *) = &baseline_pc_checked_add_u64;
static CLAUDARIS_NOINLINE uint64_t bench_actual_pc_checked_add_u64(void)
{
    uint64_t result = (uint64_t)0;
    const bool status = api_ptr_pc_checked_add_u64(arg_u64[0], arg_u64[1], &result);
    uint64_t checksum = status ? UINT64_C(1) : UINT64_C(0);
    checksum ^= (uint64_t)result;
    return checksum;
}
static CLAUDARIS_NOINLINE uint64_t bench_baseline_pc_checked_add_u64(void)
{
    uint64_t result = (uint64_t)0;
    const bool status = baseline_ptr_pc_checked_add_u64(arg_u64[0], arg_u64[1], &result);
    uint64_t checksum = status ? UINT64_C(1) : UINT64_C(0);
    checksum ^= (uint64_t)result;
    return checksum;
}
static bool (* volatile api_ptr_pc_checked_mul_i64)(int64_t, int64_t, int64_t *) = &pc_checked_mul_i64;
static bool baseline_pc_checked_mul_i64(int64_t a, int64_t b, int64_t * result)
{
    (void)a;
    (void)b;
    *result = (int64_t)0;
    return true;
}
static bool (* volatile baseline_ptr_pc_checked_mul_i64)(int64_t, int64_t, int64_t *) = &baseline_pc_checked_mul_i64;
static CLAUDARIS_NOINLINE uint64_t bench_actual_pc_checked_mul_i64(void)
{
    int64_t result = (int64_t)0;
    const bool status = api_ptr_pc_checked_mul_i64(arg_i64[2], arg_i64[3], &result);
    uint64_t checksum = status ? UINT64_C(1) : UINT64_C(0);
    checksum ^= (uint64_t)result;
    return checksum;
}
static CLAUDARIS_NOINLINE uint64_t bench_baseline_pc_checked_mul_i64(void)
{
    int64_t result = (int64_t)0;
    const bool status = baseline_ptr_pc_checked_mul_i64(arg_i64[2], arg_i64[3], &result);
    uint64_t checksum = status ? UINT64_C(1) : UINT64_C(0);
    checksum ^= (uint64_t)result;
    return checksum;
}
static bool (* volatile api_ptr_pc_checked_mul_u64)(uint64_t, uint64_t, uint64_t *) = &pc_checked_mul_u64;
static bool baseline_pc_checked_mul_u64(uint64_t a, uint64_t b, uint64_t * result)
{
    (void)a;
    (void)b;
    *result = (uint64_t)0;
    return true;
}
static bool (* volatile baseline_ptr_pc_checked_mul_u64)(uint64_t, uint64_t, uint64_t *) = &baseline_pc_checked_mul_u64;
static CLAUDARIS_NOINLINE uint64_t bench_actual_pc_checked_mul_u64(void)
{
    uint64_t result = (uint64_t)0;
    const bool status = api_ptr_pc_checked_mul_u64(arg_u64[0], arg_u64[2], &result);
    uint64_t checksum = status ? UINT64_C(1) : UINT64_C(0);
    checksum ^= (uint64_t)result;
    return checksum;
}
static CLAUDARIS_NOINLINE uint64_t bench_baseline_pc_checked_mul_u64(void)
{
    uint64_t result = (uint64_t)0;
    const bool status = baseline_ptr_pc_checked_mul_u64(arg_u64[0], arg_u64[2], &result);
    uint64_t checksum = status ? UINT64_C(1) : UINT64_C(0);
    checksum ^= (uint64_t)result;
    return checksum;
}
static bool (* volatile api_ptr_pc_checked_neg_i64)(int64_t, int64_t *) = &pc_checked_neg_i64;
static bool baseline_pc_checked_neg_i64(int64_t value, int64_t * result)
{
    (void)value;
    *result = (int64_t)0;
    return true;
}
static bool (* volatile baseline_ptr_pc_checked_neg_i64)(int64_t, int64_t *) = &baseline_pc_checked_neg_i64;
static CLAUDARIS_NOINLINE uint64_t bench_actual_pc_checked_neg_i64(void)
{
    int64_t result = (int64_t)0;
    const bool status = api_ptr_pc_checked_neg_i64(arg_i64[2], &result);
    uint64_t checksum = status ? UINT64_C(1) : UINT64_C(0);
    checksum ^= (uint64_t)result;
    return checksum;
}
static CLAUDARIS_NOINLINE uint64_t bench_baseline_pc_checked_neg_i64(void)
{
    int64_t result = (int64_t)0;
    const bool status = baseline_ptr_pc_checked_neg_i64(arg_i64[2], &result);
    uint64_t checksum = status ? UINT64_C(1) : UINT64_C(0);
    checksum ^= (uint64_t)result;
    return checksum;
}
static bool (* volatile api_ptr_pc_checked_shl_i32)(int32_t, unsigned, int32_t *) = &pc_checked_shl_i32;
static bool baseline_pc_checked_shl_i32(int32_t value, unsigned shift, int32_t * result)
{
    (void)value;
    (void)shift;
    *result = (int32_t)0;
    return true;
}
static bool (* volatile baseline_ptr_pc_checked_shl_i32)(int32_t, unsigned, int32_t *) = &baseline_pc_checked_shl_i32;
static CLAUDARIS_NOINLINE uint64_t bench_actual_pc_checked_shl_i32(void)
{
    int32_t result = (int32_t)0;
    const bool status = api_ptr_pc_checked_shl_i32(arg_i32[1], arg_unsigned[0], &result);
    uint64_t checksum = status ? UINT64_C(1) : UINT64_C(0);
    checksum ^= (uint64_t)result;
    return checksum;
}
static CLAUDARIS_NOINLINE uint64_t bench_baseline_pc_checked_shl_i32(void)
{
    int32_t result = (int32_t)0;
    const bool status = baseline_ptr_pc_checked_shl_i32(arg_i32[1], arg_unsigned[0], &result);
    uint64_t checksum = status ? UINT64_C(1) : UINT64_C(0);
    checksum ^= (uint64_t)result;
    return checksum;
}
static bool (* volatile api_ptr_pc_checked_shl_u32)(uint32_t, unsigned, uint32_t *) = &pc_checked_shl_u32;
static bool baseline_pc_checked_shl_u32(uint32_t value, unsigned shift, uint32_t * result)
{
    (void)value;
    (void)shift;
    *result = (uint32_t)0;
    return true;
}
static bool (* volatile baseline_ptr_pc_checked_shl_u32)(uint32_t, unsigned, uint32_t *) = &baseline_pc_checked_shl_u32;
static CLAUDARIS_NOINLINE uint64_t bench_actual_pc_checked_shl_u32(void)
{
    uint32_t result = (uint32_t)0;
    const bool status = api_ptr_pc_checked_shl_u32(arg_u32[11], arg_unsigned[1], &result);
    uint64_t checksum = status ? UINT64_C(1) : UINT64_C(0);
    checksum ^= (uint64_t)result;
    return checksum;
}
static CLAUDARIS_NOINLINE uint64_t bench_baseline_pc_checked_shl_u32(void)
{
    uint32_t result = (uint32_t)0;
    const bool status = baseline_ptr_pc_checked_shl_u32(arg_u32[11], arg_unsigned[1], &result);
    uint64_t checksum = status ? UINT64_C(1) : UINT64_C(0);
    checksum ^= (uint64_t)result;
    return checksum;
}
static bool (* volatile api_ptr_pc_checked_sub_i64)(int64_t, int64_t, int64_t *) = &pc_checked_sub_i64;
static bool baseline_pc_checked_sub_i64(int64_t a, int64_t b, int64_t * result)
{
    (void)a;
    (void)b;
    *result = (int64_t)0;
    return true;
}
static bool (* volatile baseline_ptr_pc_checked_sub_i64)(int64_t, int64_t, int64_t *) = &baseline_pc_checked_sub_i64;
static CLAUDARIS_NOINLINE uint64_t bench_actual_pc_checked_sub_i64(void)
{
    int64_t result = (int64_t)0;
    const bool status = api_ptr_pc_checked_sub_i64(arg_i64[0], arg_i64[4], &result);
    uint64_t checksum = status ? UINT64_C(1) : UINT64_C(0);
    checksum ^= (uint64_t)result;
    return checksum;
}
static CLAUDARIS_NOINLINE uint64_t bench_baseline_pc_checked_sub_i64(void)
{
    int64_t result = (int64_t)0;
    const bool status = baseline_ptr_pc_checked_sub_i64(arg_i64[0], arg_i64[4], &result);
    uint64_t checksum = status ? UINT64_C(1) : UINT64_C(0);
    checksum ^= (uint64_t)result;
    return checksum;
}
static bool (* volatile api_ptr_pc_checked_sub_u64)(uint64_t, uint64_t, uint64_t *) = &pc_checked_sub_u64;
static bool baseline_pc_checked_sub_u64(uint64_t a, uint64_t b, uint64_t * result)
{
    (void)a;
    (void)b;
    *result = (uint64_t)0;
    return true;
}
static bool (* volatile baseline_ptr_pc_checked_sub_u64)(uint64_t, uint64_t, uint64_t *) = &baseline_pc_checked_sub_u64;
static CLAUDARIS_NOINLINE uint64_t bench_actual_pc_checked_sub_u64(void)
{
    uint64_t result = (uint64_t)0;
    const bool status = api_ptr_pc_checked_sub_u64(arg_u64[0], arg_u64[1], &result);
    uint64_t checksum = status ? UINT64_C(1) : UINT64_C(0);
    checksum ^= (uint64_t)result;
    return checksum;
}
static CLAUDARIS_NOINLINE uint64_t bench_baseline_pc_checked_sub_u64(void)
{
    uint64_t result = (uint64_t)0;
    const bool status = baseline_ptr_pc_checked_sub_u64(arg_u64[0], arg_u64[1], &result);
    uint64_t checksum = status ? UINT64_C(1) : UINT64_C(0);
    checksum ^= (uint64_t)result;
    return checksum;
}
static bool (* volatile api_ptr_pc_floor_to_multiple_i32)(int32_t, int32_t, int32_t *) = &pc_floor_to_multiple_i32;
static bool baseline_pc_floor_to_multiple_i32(int32_t value, int32_t multiple, int32_t * rounded)
{
    (void)value;
    (void)multiple;
    *rounded = (int32_t)0;
    return true;
}
static bool (* volatile baseline_ptr_pc_floor_to_multiple_i32)(int32_t, int32_t, int32_t *) = &baseline_pc_floor_to_multiple_i32;
static CLAUDARIS_NOINLINE uint64_t bench_actual_pc_floor_to_multiple_i32(void)
{
    int32_t rounded = (int32_t)0;
    const bool status = api_ptr_pc_floor_to_multiple_i32(arg_i32[0], arg_i32[2], &rounded);
    uint64_t value = status ? UINT64_C(1) : UINT64_C(0);
    value ^= (uint64_t)rounded;
    return value;
}
static CLAUDARIS_NOINLINE uint64_t bench_baseline_pc_floor_to_multiple_i32(void)
{
    int32_t rounded = (int32_t)0;
    const bool status = baseline_ptr_pc_floor_to_multiple_i32(arg_i32[0], arg_i32[2], &rounded);
    uint64_t value = status ? UINT64_C(1) : UINT64_C(0);
    value ^= (uint64_t)rounded;
    return value;
}
static bool (* volatile api_ptr_pc_fraction_compare_i32)(int32_t, int32_t, int32_t, int32_t, int *) = &pc_fraction_compare_i32;
static bool baseline_pc_fraction_compare_i32(int32_t a_num, int32_t a_den, int32_t b_num, int32_t b_den, int * comparison)
{
    (void)a_num;
    (void)a_den;
    (void)b_num;
    (void)b_den;
    *comparison = (int)0;
    return true;
}
static bool (* volatile baseline_ptr_pc_fraction_compare_i32)(int32_t, int32_t, int32_t, int32_t, int *) = &baseline_pc_fraction_compare_i32;
static CLAUDARIS_NOINLINE uint64_t bench_actual_pc_fraction_compare_i32(void)
{
    int comparison = (int)0;
    const bool status = api_ptr_pc_fraction_compare_i32(arg_i32[6], arg_i32[2], arg_i32[4], arg_i32[5], &comparison);
    uint64_t value = status ? UINT64_C(1) : UINT64_C(0);
    value ^= (uint64_t)comparison;
    return value;
}
static CLAUDARIS_NOINLINE uint64_t bench_baseline_pc_fraction_compare_i32(void)
{
    int comparison = (int)0;
    const bool status = baseline_ptr_pc_fraction_compare_i32(arg_i32[6], arg_i32[2], arg_i32[4], arg_i32[5], &comparison);
    uint64_t value = status ? UINT64_C(1) : UINT64_C(0);
    value ^= (uint64_t)comparison;
    return value;
}
static bool (* volatile api_ptr_pc_is_aligned_u32)(uint32_t, uint32_t) = &pc_is_aligned_u32;
static bool baseline_pc_is_aligned_u32(uint32_t value, uint32_t alignment)
{
    (void)value;
    (void)alignment;
    return true;
}
static bool (* volatile baseline_ptr_pc_is_aligned_u32)(uint32_t, uint32_t) = &baseline_pc_is_aligned_u32;
static CLAUDARIS_NOINLINE uint64_t bench_actual_pc_is_aligned_u32(void)
{
    const bool status = api_ptr_pc_is_aligned_u32(arg_u32[2], arg_u32[3]);
    return (uint64_t)status;
}
static CLAUDARIS_NOINLINE uint64_t bench_baseline_pc_is_aligned_u32(void)
{
    const bool status = baseline_ptr_pc_is_aligned_u32(arg_u32[2], arg_u32[3]);
    return (uint64_t)status;
}
static bool (* volatile api_ptr_pc_lookup_clamped_i32)(const int32_t *, size_t, int32_t, int32_t *) = &pc_lookup_clamped_i32;
static bool baseline_pc_lookup_clamped_i32(const int32_t * table, size_t count, int32_t index, int32_t * value)
{
    (void)table;
    (void)count;
    (void)index;
    *value = (int32_t)0;
    return true;
}
static bool (* volatile baseline_ptr_pc_lookup_clamped_i32)(const int32_t *, size_t, int32_t, int32_t *) = &baseline_pc_lookup_clamped_i32;
static CLAUDARIS_NOINLINE uint64_t bench_actual_pc_lookup_clamped_i32(void)
{
    int32_t output = (int32_t)0;
    const bool status = api_ptr_pc_lookup_clamped_i32(table_data, 3u, arg_i32[7], &output);
    uint64_t checksum = status ? UINT64_C(1) : UINT64_C(0);
    checksum ^= (uint64_t)(int64_t)output;
    return checksum;
}
static CLAUDARIS_NOINLINE uint64_t bench_baseline_pc_lookup_clamped_i32(void)
{
    int32_t output = (int32_t)0;
    const bool status = baseline_ptr_pc_lookup_clamped_i32(table_data, 3u, arg_i32[7], &output);
    uint64_t checksum = status ? UINT64_C(1) : UINT64_C(0);
    checksum ^= (uint64_t)(int64_t)output;
    return checksum;
}
static bool (* volatile api_ptr_pc_mask_range_u64)(uint8_t, uint8_t, uint64_t *) = &pc_mask_range_u64;
static bool baseline_pc_mask_range_u64(uint8_t first_bit, uint8_t last_bit, uint64_t * mask)
{
    (void)first_bit;
    (void)last_bit;
    *mask = (uint64_t)0;
    return true;
}
static bool (* volatile baseline_ptr_pc_mask_range_u64)(uint8_t, uint8_t, uint64_t *) = &baseline_pc_mask_range_u64;
static CLAUDARIS_NOINLINE uint64_t bench_actual_pc_mask_range_u64(void)
{
    uint64_t mask = (uint64_t)0;
    const bool status = api_ptr_pc_mask_range_u64(arg_u32[11], arg_u32[6], &mask);
    uint64_t value = status ? UINT64_C(1) : UINT64_C(0);
    value ^= (uint64_t)mask;
    return value;
}
static CLAUDARIS_NOINLINE uint64_t bench_baseline_pc_mask_range_u64(void)
{
    uint64_t mask = (uint64_t)0;
    const bool status = baseline_ptr_pc_mask_range_u64(arg_u32[11], arg_u32[6], &mask);
    uint64_t value = status ? UINT64_C(1) : UINT64_C(0);
    value ^= (uint64_t)mask;
    return value;
}
static bool (* volatile api_ptr_pc_nearest_multiple_u32)(uint32_t, uint32_t, uint32_t *) = &pc_nearest_multiple_u32;
static bool baseline_pc_nearest_multiple_u32(uint32_t value, uint32_t multiple, uint32_t * rounded)
{
    (void)value;
    (void)multiple;
    *rounded = (uint32_t)0;
    return true;
}
static bool (* volatile baseline_ptr_pc_nearest_multiple_u32)(uint32_t, uint32_t, uint32_t *) = &baseline_pc_nearest_multiple_u32;
static CLAUDARIS_NOINLINE uint64_t bench_actual_pc_nearest_multiple_u32(void)
{
    uint32_t rounded = (uint32_t)0;
    const bool status = api_ptr_pc_nearest_multiple_u32(arg_u32[4], arg_u32[5], &rounded);
    uint64_t value = status ? UINT64_C(1) : UINT64_C(0);
    value ^= (uint64_t)rounded;
    return value;
}
static CLAUDARIS_NOINLINE uint64_t bench_baseline_pc_nearest_multiple_u32(void)
{
    uint32_t rounded = (uint32_t)0;
    const bool status = baseline_ptr_pc_nearest_multiple_u32(arg_u32[4], arg_u32[5], &rounded);
    uint64_t value = status ? UINT64_C(1) : UINT64_C(0);
    value ^= (uint64_t)rounded;
    return value;
}
static bool (* volatile api_ptr_pc_offset_range_check_u32)(uint32_t, uint32_t, uint32_t) = &pc_offset_range_check_u32;
static bool baseline_pc_offset_range_check_u32(uint32_t offset, uint32_t length, uint32_t capacity)
{
    (void)offset;
    (void)length;
    (void)capacity;
    return true;
}
static bool (* volatile baseline_ptr_pc_offset_range_check_u32)(uint32_t, uint32_t, uint32_t) = &baseline_pc_offset_range_check_u32;
static CLAUDARIS_NOINLINE uint64_t bench_actual_pc_offset_range_check_u32(void)
{
    const bool status = api_ptr_pc_offset_range_check_u32(arg_u32[6], arg_u32[7], arg_u32[8]);
    return (uint64_t)status;
}
static CLAUDARIS_NOINLINE uint64_t bench_baseline_pc_offset_range_check_u32(void)
{
    const bool status = baseline_ptr_pc_offset_range_check_u32(arg_u32[6], arg_u32[7], arg_u32[8]);
    return (uint64_t)status;
}
static bool (* volatile api_ptr_pc_period_align_u32)(uint32_t, uint32_t, uint32_t, uint32_t *) = &pc_period_align_u32;
static bool baseline_pc_period_align_u32(uint32_t time, uint32_t origin, uint32_t period, uint32_t * aligned)
{
    (void)time;
    (void)origin;
    (void)period;
    *aligned = (uint32_t)0;
    return true;
}
static bool (* volatile baseline_ptr_pc_period_align_u32)(uint32_t, uint32_t, uint32_t, uint32_t *) = &baseline_pc_period_align_u32;
static CLAUDARIS_NOINLINE uint64_t bench_actual_pc_period_align_u32(void)
{
    uint32_t aligned = (uint32_t)0;
    const bool status = api_ptr_pc_period_align_u32(arg_u32[8], arg_u32[10], arg_u32[4], &aligned);
    uint64_t value = status ? UINT64_C(1) : UINT64_C(0);
    value ^= (uint64_t)aligned;
    return value;
}
static CLAUDARIS_NOINLINE uint64_t bench_baseline_pc_period_align_u32(void)
{
    uint32_t aligned = (uint32_t)0;
    const bool status = baseline_ptr_pc_period_align_u32(arg_u32[8], arg_u32[10], arg_u32[4], &aligned);
    uint64_t value = status ? UINT64_C(1) : UINT64_C(0);
    value ^= (uint64_t)aligned;
    return value;
}
static bool (* volatile api_ptr_pc_period_floor_u32)(uint32_t, uint32_t, uint32_t, uint32_t *) = &pc_period_floor_u32;
static bool baseline_pc_period_floor_u32(uint32_t time, uint32_t origin, uint32_t period, uint32_t * aligned)
{
    (void)time;
    (void)origin;
    (void)period;
    *aligned = (uint32_t)0;
    return true;
}
static bool (* volatile baseline_ptr_pc_period_floor_u32)(uint32_t, uint32_t, uint32_t, uint32_t *) = &baseline_pc_period_floor_u32;
static CLAUDARIS_NOINLINE uint64_t bench_actual_pc_period_floor_u32(void)
{
    uint32_t aligned = (uint32_t)0;
    const bool status = api_ptr_pc_period_floor_u32(arg_u32[8], arg_u32[10], arg_u32[4], &aligned);
    uint64_t value = status ? UINT64_C(1) : UINT64_C(0);
    value ^= (uint64_t)aligned;
    return value;
}
static CLAUDARIS_NOINLINE uint64_t bench_baseline_pc_period_floor_u32(void)
{
    uint32_t aligned = (uint32_t)0;
    const bool status = baseline_ptr_pc_period_floor_u32(arg_u32[8], arg_u32[10], arg_u32[4], &aligned);
    uint64_t value = status ? UINT64_C(1) : UINT64_C(0);
    value ^= (uint64_t)aligned;
    return value;
}
static bool (* volatile api_ptr_pc_range_center_i32)(int32_t, int32_t, int32_t *) = &pc_range_center_i32;
static bool baseline_pc_range_center_i32(int32_t lower, int32_t upper, int32_t * center)
{
    (void)lower;
    (void)upper;
    *center = (int32_t)0;
    return true;
}
static bool (* volatile baseline_ptr_pc_range_center_i32)(int32_t, int32_t, int32_t *) = &baseline_pc_range_center_i32;
static CLAUDARIS_NOINLINE uint64_t bench_actual_pc_range_center_i32(void)
{
    int32_t center = (int32_t)0;
    const bool status = api_ptr_pc_range_center_i32(arg_i32[1], arg_i32[2], &center);
    uint64_t value = status ? UINT64_C(1) : UINT64_C(0);
    value ^= (uint64_t)center;
    return value;
}
static CLAUDARIS_NOINLINE uint64_t bench_baseline_pc_range_center_i32(void)
{
    int32_t center = (int32_t)0;
    const bool status = baseline_ptr_pc_range_center_i32(arg_i32[1], arg_i32[2], &center);
    uint64_t value = status ? UINT64_C(1) : UINT64_C(0);
    value ^= (uint64_t)center;
    return value;
}
static bool (* volatile api_ptr_pc_range_intersects_i32)(int32_t, int32_t, int32_t, int32_t) = &pc_range_intersects_i32;
static bool baseline_pc_range_intersects_i32(int32_t a_lower, int32_t a_upper, int32_t b_lower, int32_t b_upper)
{
    (void)a_lower;
    (void)a_upper;
    (void)b_lower;
    (void)b_upper;
    return true;
}
static bool (* volatile baseline_ptr_pc_range_intersects_i32)(int32_t, int32_t, int32_t, int32_t) = &baseline_pc_range_intersects_i32;
static CLAUDARIS_NOINLINE uint64_t bench_actual_pc_range_intersects_i32(void)
{
    const bool status = api_ptr_pc_range_intersects_i32(arg_i32[11], arg_i32[12], arg_i32[12], arg_i32[9]);
    return (uint64_t)status;
}
static CLAUDARIS_NOINLINE uint64_t bench_baseline_pc_range_intersects_i32(void)
{
    const bool status = baseline_ptr_pc_range_intersects_i32(arg_i32[11], arg_i32[12], arg_i32[12], arg_i32[9]);
    return (uint64_t)status;
}
static bool (* volatile api_ptr_pc_range_shrink_i32)(int32_t, int32_t, uint32_t, int32_t *, int32_t *) = &pc_range_shrink_i32;
static bool baseline_pc_range_shrink_i32(int32_t lower, int32_t upper, uint32_t amount, int32_t * shrunk_lower, int32_t * shrunk_upper)
{
    (void)lower;
    (void)upper;
    (void)amount;
    *shrunk_lower = (int32_t)0;
    *shrunk_upper = (int32_t)0;
    return true;
}
static bool (* volatile baseline_ptr_pc_range_shrink_i32)(int32_t, int32_t, uint32_t, int32_t *, int32_t *) = &baseline_pc_range_shrink_i32;
static CLAUDARIS_NOINLINE uint64_t bench_actual_pc_range_shrink_i32(void)
{
    int32_t shrunk_lower = (int32_t)0;
    int32_t shrunk_upper = (int32_t)0;
    const bool status = api_ptr_pc_range_shrink_i32(arg_i32[7], arg_i32[8], arg_u32[5], &shrunk_lower, &shrunk_upper);
    uint64_t value = status ? UINT64_C(1) : UINT64_C(0);
    value ^= (uint64_t)shrunk_lower;
    value ^= (uint64_t)shrunk_upper;
    return value;
}
static CLAUDARIS_NOINLINE uint64_t bench_baseline_pc_range_shrink_i32(void)
{
    int32_t shrunk_lower = (int32_t)0;
    int32_t shrunk_upper = (int32_t)0;
    const bool status = baseline_ptr_pc_range_shrink_i32(arg_i32[7], arg_i32[8], arg_u32[5], &shrunk_lower, &shrunk_upper);
    uint64_t value = status ? UINT64_C(1) : UINT64_C(0);
    value ^= (uint64_t)shrunk_lower;
    value ^= (uint64_t)shrunk_upper;
    return value;
}
static bool (* volatile api_ptr_pc_ratio_between_u32)(uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, bool *) = &pc_ratio_between_u32;
static bool baseline_pc_ratio_between_u32(uint32_t numerator, uint32_t denominator, uint32_t lower_num, uint32_t lower_den, uint32_t upper_num, uint32_t upper_den, bool * is_between)
{
    (void)numerator;
    (void)denominator;
    (void)lower_num;
    (void)lower_den;
    (void)upper_num;
    (void)upper_den;
    *is_between = (bool)0;
    return true;
}
static bool (* volatile baseline_ptr_pc_ratio_between_u32)(uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, bool *) = &baseline_pc_ratio_between_u32;
static CLAUDARIS_NOINLINE uint64_t bench_actual_pc_ratio_between_u32(void)
{
    bool is_between = (bool)0;
    const bool status = api_ptr_pc_ratio_between_u32(arg_u32[11], arg_u32[5], arg_u32[11], arg_u32[6], arg_u32[5], arg_u32[6], &is_between);
    uint64_t value = status ? UINT64_C(1) : UINT64_C(0);
    value ^= (uint64_t)is_between;
    return value;
}
static CLAUDARIS_NOINLINE uint64_t bench_baseline_pc_ratio_between_u32(void)
{
    bool is_between = (bool)0;
    const bool status = baseline_ptr_pc_ratio_between_u32(arg_u32[11], arg_u32[5], arg_u32[11], arg_u32[6], arg_u32[5], arg_u32[6], &is_between);
    uint64_t value = status ? UINT64_C(1) : UINT64_C(0);
    value ^= (uint64_t)is_between;
    return value;
}
static bool (* volatile api_ptr_pc_ratio_ceil_u32)(uint32_t, uint32_t, uint32_t *) = &pc_ratio_ceil_u32;
static bool baseline_pc_ratio_ceil_u32(uint32_t numerator, uint32_t denominator, uint32_t * quotient)
{
    (void)numerator;
    (void)denominator;
    *quotient = (uint32_t)0;
    return true;
}
static bool (* volatile baseline_ptr_pc_ratio_ceil_u32)(uint32_t, uint32_t, uint32_t *) = &baseline_pc_ratio_ceil_u32;
static CLAUDARIS_NOINLINE uint64_t bench_actual_pc_ratio_ceil_u32(void)
{
    uint32_t quotient = (uint32_t)0;
    const bool status = api_ptr_pc_ratio_ceil_u32(arg_u32[9], arg_u32[6], &quotient);
    uint64_t value = status ? UINT64_C(1) : UINT64_C(0);
    value ^= (uint64_t)quotient;
    return value;
}
static CLAUDARIS_NOINLINE uint64_t bench_baseline_pc_ratio_ceil_u32(void)
{
    uint32_t quotient = (uint32_t)0;
    const bool status = baseline_ptr_pc_ratio_ceil_u32(arg_u32[9], arg_u32[6], &quotient);
    uint64_t value = status ? UINT64_C(1) : UINT64_C(0);
    value ^= (uint64_t)quotient;
    return value;
}
static bool (* volatile api_ptr_pc_ratio_round_even_u32)(uint32_t, uint32_t, uint32_t *) = &pc_ratio_round_even_u32;
static bool baseline_pc_ratio_round_even_u32(uint32_t numerator, uint32_t denominator, uint32_t * rounded)
{
    (void)numerator;
    (void)denominator;
    *rounded = (uint32_t)0;
    return true;
}
static bool (* volatile baseline_ptr_pc_ratio_round_even_u32)(uint32_t, uint32_t, uint32_t *) = &baseline_pc_ratio_round_even_u32;
static CLAUDARIS_NOINLINE uint64_t bench_actual_pc_ratio_round_even_u32(void)
{
    uint32_t rounded = (uint32_t)0;
    const bool status = api_ptr_pc_ratio_round_even_u32(arg_u32[4], arg_u32[5], &rounded);
    uint64_t value = status ? UINT64_C(1) : UINT64_C(0);
    value ^= (uint64_t)rounded;
    return value;
}
static CLAUDARIS_NOINLINE uint64_t bench_baseline_pc_ratio_round_even_u32(void)
{
    uint32_t rounded = (uint32_t)0;
    const bool status = baseline_ptr_pc_ratio_round_even_u32(arg_u32[4], arg_u32[5], &rounded);
    uint64_t value = status ? UINT64_C(1) : UINT64_C(0);
    value ^= (uint64_t)rounded;
    return value;
}
static bool (* volatile api_ptr_pc_round_to_multiple_i32)(int32_t, int32_t, int32_t *) = &pc_round_to_multiple_i32;
static bool baseline_pc_round_to_multiple_i32(int32_t value, int32_t multiple, int32_t * rounded)
{
    (void)value;
    (void)multiple;
    *rounded = (int32_t)0;
    return true;
}
static bool (* volatile baseline_ptr_pc_round_to_multiple_i32)(int32_t, int32_t, int32_t *) = &baseline_pc_round_to_multiple_i32;
static CLAUDARIS_NOINLINE uint64_t bench_actual_pc_round_to_multiple_i32(void)
{
    int32_t rounded = (int32_t)0;
    const bool status = api_ptr_pc_round_to_multiple_i32(arg_i32[0], arg_i32[2], &rounded);
    uint64_t value = status ? UINT64_C(1) : UINT64_C(0);
    value ^= (uint64_t)rounded;
    return value;
}
static CLAUDARIS_NOINLINE uint64_t bench_baseline_pc_round_to_multiple_i32(void)
{
    int32_t rounded = (int32_t)0;
    const bool status = baseline_ptr_pc_round_to_multiple_i32(arg_i32[0], arg_i32[2], &rounded);
    uint64_t value = status ? UINT64_C(1) : UINT64_C(0);
    value ^= (uint64_t)rounded;
    return value;
}
static int64_t (* volatile api_ptr_pc_saturating_add_i64)(int64_t, int64_t) = &pc_saturating_add_i64;
static int64_t baseline_pc_saturating_add_i64(int64_t a, int64_t b)
{
    (void)a;
    (void)b;
    return (int64_t)0;
}
static int64_t (* volatile baseline_ptr_pc_saturating_add_i64)(int64_t, int64_t) = &baseline_pc_saturating_add_i64;
static CLAUDARIS_NOINLINE uint64_t bench_actual_pc_saturating_add_i64(void)
{
    const int64_t value = api_ptr_pc_saturating_add_i64(arg_i64[1], arg_i64[5]);
    return (uint64_t)value;
}
static CLAUDARIS_NOINLINE uint64_t bench_baseline_pc_saturating_add_i64(void)
{
    const int64_t value = baseline_ptr_pc_saturating_add_i64(arg_i64[1], arg_i64[5]);
    return (uint64_t)value;
}
static uint64_t (* volatile api_ptr_pc_saturating_add_u64)(uint64_t, uint64_t) = &pc_saturating_add_u64;
static uint64_t baseline_pc_saturating_add_u64(uint64_t a, uint64_t b)
{
    (void)a;
    (void)b;
    return (uint64_t)0;
}
static uint64_t (* volatile baseline_ptr_pc_saturating_add_u64)(uint64_t, uint64_t) = &baseline_pc_saturating_add_u64;
static CLAUDARIS_NOINLINE uint64_t bench_actual_pc_saturating_add_u64(void)
{
    const uint64_t value = api_ptr_pc_saturating_add_u64(arg_u64[0], arg_u64[2]);
    return (uint64_t)value;
}
static CLAUDARIS_NOINLINE uint64_t bench_baseline_pc_saturating_add_u64(void)
{
    const uint64_t value = baseline_ptr_pc_saturating_add_u64(arg_u64[0], arg_u64[2]);
    return (uint64_t)value;
}
static int32_t (* volatile api_ptr_pc_saturating_cast_i64_i32)(int64_t) = &pc_saturating_cast_i64_i32;
static int32_t baseline_pc_saturating_cast_i64_i32(int64_t value)
{
    (void)value;
    return (int32_t)0;
}
static int32_t (* volatile baseline_ptr_pc_saturating_cast_i64_i32)(int64_t) = &baseline_pc_saturating_cast_i64_i32;
static CLAUDARIS_NOINLINE uint64_t bench_actual_pc_saturating_cast_i64_i32(void)
{
    const int32_t value = api_ptr_pc_saturating_cast_i64_i32(arg_i64[1]);
    return (uint64_t)value;
}
static CLAUDARIS_NOINLINE uint64_t bench_baseline_pc_saturating_cast_i64_i32(void)
{
    const int32_t value = baseline_ptr_pc_saturating_cast_i64_i32(arg_i64[1]);
    return (uint64_t)value;
}
static uint32_t (* volatile api_ptr_pc_saturating_cast_u64_u32)(uint64_t) = &pc_saturating_cast_u64_u32;
static uint32_t baseline_pc_saturating_cast_u64_u32(uint64_t value)
{
    (void)value;
    return (uint32_t)0;
}
static uint32_t (* volatile baseline_ptr_pc_saturating_cast_u64_u32)(uint64_t) = &baseline_pc_saturating_cast_u64_u32;
static CLAUDARIS_NOINLINE uint64_t bench_actual_pc_saturating_cast_u64_u32(void)
{
    const uint32_t value = api_ptr_pc_saturating_cast_u64_u32(arg_u64[3]);
    return (uint64_t)value;
}
static CLAUDARIS_NOINLINE uint64_t bench_baseline_pc_saturating_cast_u64_u32(void)
{
    const uint32_t value = baseline_ptr_pc_saturating_cast_u64_u32(arg_u64[3]);
    return (uint64_t)value;
}
static uint64_t (* volatile api_ptr_pc_saturating_mul_u64)(uint64_t, uint64_t) = &pc_saturating_mul_u64;
static uint64_t baseline_pc_saturating_mul_u64(uint64_t a, uint64_t b)
{
    (void)a;
    (void)b;
    return (uint64_t)0;
}
static uint64_t (* volatile baseline_ptr_pc_saturating_mul_u64)(uint64_t, uint64_t) = &baseline_pc_saturating_mul_u64;
static CLAUDARIS_NOINLINE uint64_t bench_actual_pc_saturating_mul_u64(void)
{
    const uint64_t value = api_ptr_pc_saturating_mul_u64(arg_u64[0], arg_u64[4]);
    return (uint64_t)value;
}
static CLAUDARIS_NOINLINE uint64_t bench_baseline_pc_saturating_mul_u64(void)
{
    const uint64_t value = baseline_ptr_pc_saturating_mul_u64(arg_u64[0], arg_u64[4]);
    return (uint64_t)value;
}
static int64_t (* volatile api_ptr_pc_saturating_sub_i64)(int64_t, int64_t) = &pc_saturating_sub_i64;
static int64_t baseline_pc_saturating_sub_i64(int64_t a, int64_t b)
{
    (void)a;
    (void)b;
    return (int64_t)0;
}
static int64_t (* volatile baseline_ptr_pc_saturating_sub_i64)(int64_t, int64_t) = &baseline_pc_saturating_sub_i64;
static CLAUDARIS_NOINLINE uint64_t bench_actual_pc_saturating_sub_i64(void)
{
    const int64_t value = api_ptr_pc_saturating_sub_i64(arg_i64[0], arg_i64[5]);
    return (uint64_t)value;
}
static CLAUDARIS_NOINLINE uint64_t bench_baseline_pc_saturating_sub_i64(void)
{
    const int64_t value = baseline_ptr_pc_saturating_sub_i64(arg_i64[0], arg_i64[5]);
    return (uint64_t)value;
}
static uint64_t (* volatile api_ptr_pc_saturating_sub_u64)(uint64_t, uint64_t) = &pc_saturating_sub_u64;
static uint64_t baseline_pc_saturating_sub_u64(uint64_t a, uint64_t b)
{
    (void)a;
    (void)b;
    return (uint64_t)0;
}
static uint64_t (* volatile baseline_ptr_pc_saturating_sub_u64)(uint64_t, uint64_t) = &baseline_pc_saturating_sub_u64;
static CLAUDARIS_NOINLINE uint64_t bench_actual_pc_saturating_sub_u64(void)
{
    const uint64_t value = api_ptr_pc_saturating_sub_u64(arg_u64[1], arg_u64[2]);
    return (uint64_t)value;
}
static CLAUDARIS_NOINLINE uint64_t bench_baseline_pc_saturating_sub_u64(void)
{
    const uint64_t value = baseline_ptr_pc_saturating_sub_u64(arg_u64[1], arg_u64[2]);
    return (uint64_t)value;
}
static bool (* volatile api_ptr_pc_size_add_checked_u32)(uint32_t, uint32_t, uint32_t *) = &pc_size_add_checked_u32;
static bool baseline_pc_size_add_checked_u32(uint32_t a, uint32_t b, uint32_t * sum)
{
    (void)a;
    (void)b;
    *sum = (uint32_t)0;
    return true;
}
static bool (* volatile baseline_ptr_pc_size_add_checked_u32)(uint32_t, uint32_t, uint32_t *) = &baseline_pc_size_add_checked_u32;
static CLAUDARIS_NOINLINE uint64_t bench_actual_pc_size_add_checked_u32(void)
{
    uint32_t sum = (uint32_t)0;
    const bool status = api_ptr_pc_size_add_checked_u32(arg_u32[5], arg_u32[6], &sum);
    uint64_t value = status ? UINT64_C(1) : UINT64_C(0);
    value ^= (uint64_t)sum;
    return value;
}
static CLAUDARIS_NOINLINE uint64_t bench_baseline_pc_size_add_checked_u32(void)
{
    uint32_t sum = (uint32_t)0;
    const bool status = baseline_ptr_pc_size_add_checked_u32(arg_u32[5], arg_u32[6], &sum);
    uint64_t value = status ? UINT64_C(1) : UINT64_C(0);
    value ^= (uint64_t)sum;
    return value;
}
static bool (* volatile api_ptr_pc_size_mul_checked_u32)(uint32_t, uint32_t, uint32_t *) = &pc_size_mul_checked_u32;
static bool baseline_pc_size_mul_checked_u32(uint32_t a, uint32_t b, uint32_t * product)
{
    (void)a;
    (void)b;
    *product = (uint32_t)0;
    return true;
}
static bool (* volatile baseline_ptr_pc_size_mul_checked_u32)(uint32_t, uint32_t, uint32_t *) = &baseline_pc_size_mul_checked_u32;
static CLAUDARIS_NOINLINE uint64_t bench_actual_pc_size_mul_checked_u32(void)
{
    uint32_t product = (uint32_t)0;
    const bool status = api_ptr_pc_size_mul_checked_u32(arg_u32[6], arg_u32[7], &product);
    uint64_t value = status ? UINT64_C(1) : UINT64_C(0);
    value ^= (uint64_t)product;
    return value;
}
static CLAUDARIS_NOINLINE uint64_t bench_baseline_pc_size_mul_checked_u32(void)
{
    uint32_t product = (uint32_t)0;
    const bool status = baseline_ptr_pc_size_mul_checked_u32(arg_u32[6], arg_u32[7], &product);
    uint64_t value = status ? UINT64_C(1) : UINT64_C(0);
    value ^= (uint64_t)product;
    return value;
}
static bool (* volatile api_ptr_pc_time_convert_ceil_u64)(uint64_t, uint64_t, uint64_t, uint64_t *) = &pc_time_convert_ceil_u64;
static bool baseline_pc_time_convert_ceil_u64(uint64_t value, uint64_t numerator, uint64_t denominator, uint64_t * result)
{
    (void)value;
    (void)numerator;
    (void)denominator;
    *result = (uint64_t)0;
    return true;
}
static bool (* volatile baseline_ptr_pc_time_convert_ceil_u64)(uint64_t, uint64_t, uint64_t, uint64_t *) = &baseline_pc_time_convert_ceil_u64;
static CLAUDARIS_NOINLINE uint64_t bench_actual_pc_time_convert_ceil_u64(void)
{
    uint64_t result = (uint64_t)0;
    const bool status = api_ptr_pc_time_convert_ceil_u64(arg_u64[5], arg_u64[2], arg_u64[6], &result);
    uint64_t checksum = status ? UINT64_C(1) : UINT64_C(0);
    checksum ^= (uint64_t)result;
    return checksum;
}
static CLAUDARIS_NOINLINE uint64_t bench_baseline_pc_time_convert_ceil_u64(void)
{
    uint64_t result = (uint64_t)0;
    const bool status = baseline_ptr_pc_time_convert_ceil_u64(arg_u64[5], arg_u64[2], arg_u64[6], &result);
    uint64_t checksum = status ? UINT64_C(1) : UINT64_C(0);
    checksum ^= (uint64_t)result;
    return checksum;
}
static bool (* volatile api_ptr_pc_time_convert_floor_u64)(uint64_t, uint64_t, uint64_t, uint64_t *) = &pc_time_convert_floor_u64;
static bool baseline_pc_time_convert_floor_u64(uint64_t value, uint64_t numerator, uint64_t denominator, uint64_t * result)
{
    (void)value;
    (void)numerator;
    (void)denominator;
    *result = (uint64_t)0;
    return true;
}
static bool (* volatile baseline_ptr_pc_time_convert_floor_u64)(uint64_t, uint64_t, uint64_t, uint64_t *) = &baseline_pc_time_convert_floor_u64;
static CLAUDARIS_NOINLINE uint64_t bench_actual_pc_time_convert_floor_u64(void)
{
    uint64_t result = (uint64_t)0;
    const bool status = api_ptr_pc_time_convert_floor_u64(arg_u64[5], arg_u64[2], arg_u64[6], &result);
    uint64_t checksum = status ? UINT64_C(1) : UINT64_C(0);
    checksum ^= (uint64_t)result;
    return checksum;
}
static CLAUDARIS_NOINLINE uint64_t bench_baseline_pc_time_convert_floor_u64(void)
{
    uint64_t result = (uint64_t)0;
    const bool status = baseline_ptr_pc_time_convert_floor_u64(arg_u64[5], arg_u64[2], arg_u64[6], &result);
    uint64_t checksum = status ? UINT64_C(1) : UINT64_C(0);
    checksum ^= (uint64_t)result;
    return checksum;
}
static uint64_t (* volatile api_ptr_pc_time_duration_absdiff_u64)(uint64_t, uint64_t) = &pc_time_duration_absdiff_u64;
static uint64_t baseline_pc_time_duration_absdiff_u64(uint64_t a, uint64_t b)
{
    (void)a;
    (void)b;
    return (uint64_t)0;
}
static uint64_t (* volatile baseline_ptr_pc_time_duration_absdiff_u64)(uint64_t, uint64_t) = &baseline_pc_time_duration_absdiff_u64;
static CLAUDARIS_NOINLINE uint64_t bench_actual_pc_time_duration_absdiff_u64(void)
{
    const uint64_t value = api_ptr_pc_time_duration_absdiff_u64(arg_u64[0], arg_u64[1]);
    return (uint64_t)value;
}
static CLAUDARIS_NOINLINE uint64_t bench_baseline_pc_time_duration_absdiff_u64(void)
{
    const uint64_t value = baseline_ptr_pc_time_duration_absdiff_u64(arg_u64[0], arg_u64[1]);
    return (uint64_t)value;
}
static bool (* volatile api_ptr_pc_time_duration_clamp_u64)(uint64_t, uint64_t, uint64_t, uint64_t *) = &pc_time_duration_clamp_u64;
static bool baseline_pc_time_duration_clamp_u64(uint64_t duration, uint64_t lower, uint64_t upper, uint64_t * result)
{
    (void)duration;
    (void)lower;
    (void)upper;
    *result = (uint64_t)0;
    return true;
}
static bool (* volatile baseline_ptr_pc_time_duration_clamp_u64)(uint64_t, uint64_t, uint64_t, uint64_t *) = &baseline_pc_time_duration_clamp_u64;
static CLAUDARIS_NOINLINE uint64_t bench_actual_pc_time_duration_clamp_u64(void)
{
    uint64_t result = (uint64_t)0;
    const bool status = api_ptr_pc_time_duration_clamp_u64(arg_u64[7], arg_u64[8], arg_u64[9], &result);
    uint64_t checksum = status ? UINT64_C(1) : UINT64_C(0);
    checksum ^= (uint64_t)result;
    return checksum;
}
static CLAUDARIS_NOINLINE uint64_t bench_baseline_pc_time_duration_clamp_u64(void)
{
    uint64_t result = (uint64_t)0;
    const bool status = baseline_ptr_pc_time_duration_clamp_u64(arg_u64[7], arg_u64[8], arg_u64[9], &result);
    uint64_t checksum = status ? UINT64_C(1) : UINT64_C(0);
    checksum ^= (uint64_t)result;
    return checksum;
}
static bool (* volatile api_ptr_pc_time_scale_ratio_u64)(uint64_t, uint64_t, uint64_t, uint64_t *) = &pc_time_scale_ratio_u64;
static bool baseline_pc_time_scale_ratio_u64(uint64_t value, uint64_t numerator, uint64_t denominator, uint64_t * result)
{
    (void)value;
    (void)numerator;
    (void)denominator;
    *result = (uint64_t)0;
    return true;
}
static bool (* volatile baseline_ptr_pc_time_scale_ratio_u64)(uint64_t, uint64_t, uint64_t, uint64_t *) = &baseline_pc_time_scale_ratio_u64;
static CLAUDARIS_NOINLINE uint64_t bench_actual_pc_time_scale_ratio_u64(void)
{
    uint64_t result = (uint64_t)0;
    const bool status = api_ptr_pc_time_scale_ratio_u64(arg_u64[5], arg_u64[2], arg_u64[6], &result);
    uint64_t checksum = status ? UINT64_C(1) : UINT64_C(0);
    checksum ^= (uint64_t)result;
    return checksum;
}
static CLAUDARIS_NOINLINE uint64_t bench_baseline_pc_time_scale_ratio_u64(void)
{
    uint64_t result = (uint64_t)0;
    const bool status = baseline_ptr_pc_time_scale_ratio_u64(arg_u64[5], arg_u64[2], arg_u64[6], &result);
    uint64_t checksum = status ? UINT64_C(1) : UINT64_C(0);
    checksum ^= (uint64_t)result;
    return checksum;
}
typedef uint64_t (*bench_fn_t)(void);
static CLAUDARIS_NOINLINE uint64_t bench_empty(void) { return (uint64_t)empty_input; }
static uint32_t timed_batch(bench_fn_t fn)
{
    const uint32_t start = esp_cpu_get_cycle_count();
    for (uint32_t i = 0u; i < benchmark_repetitions; ++i) benchmark_sink ^= fn();
    return esp_cpu_get_cycle_count() - start;
}
static int32_t median_i32(int32_t *v, uint32_t count)
{
    for (uint32_t i=1u;i<count;++i){int32_t x=v[i];uint32_t j=i;while(j>0u&&v[j-1u]>x){v[j]=v[j-1u];--j;}v[j]=x;}
    return v[count/2u];
}
static uint32_t median_u32(uint32_t *v, uint32_t count)
{
    for (uint32_t i=1u;i<count;++i){uint32_t x=v[i];uint32_t j=i;while(j>0u&&v[j-1u]>x){v[j]=v[j-1u];--j;}v[j]=x;}
    return v[count/2u];
}
static int32_t measure_api(bench_fn_t actual, bench_fn_t baseline)
{
    int32_t delta[31];
    for(uint32_t s=0u;s<benchmark_samples;++s){uint32_t a,b;if((s&1u)==0u){a=timed_batch(actual);b=timed_batch(baseline);}else{b=timed_batch(baseline);a=timed_batch(actual);}delta[s]=(int32_t)(a-b);}
    return median_i32(delta, benchmark_samples)/(int32_t)benchmark_repetitions;
}
static uint32_t measure_loop_overhead(void)
{
    uint32_t samples[31];for(uint32_t s=0u;s<benchmark_samples;++s)samples[s]=timed_batch(bench_empty);
    return median_u32(samples,benchmark_samples)/benchmark_repetitions;
}
static bench_fn_t const actual_bench[46] = {
    bench_actual_pc_abs_diff_i64_u64,
    bench_actual_pc_abs_i64_safe_u64,
    bench_actual_pc_accumulate_abs_i32,
    bench_actual_pc_align_down_u32,
    bench_actual_pc_align_up_u32,
    bench_actual_pc_ceil_to_multiple_i32,
    bench_actual_pc_checked_abs_i64,
    bench_actual_pc_checked_add_i64,
    bench_actual_pc_checked_add_u64,
    bench_actual_pc_checked_mul_i64,
    bench_actual_pc_checked_mul_u64,
    bench_actual_pc_checked_neg_i64,
    bench_actual_pc_checked_shl_i32,
    bench_actual_pc_checked_shl_u32,
    bench_actual_pc_checked_sub_i64,
    bench_actual_pc_checked_sub_u64,
    bench_actual_pc_floor_to_multiple_i32,
    bench_actual_pc_fraction_compare_i32,
    bench_actual_pc_is_aligned_u32,
    bench_actual_pc_lookup_clamped_i32,
    bench_actual_pc_mask_range_u64,
    bench_actual_pc_nearest_multiple_u32,
    bench_actual_pc_offset_range_check_u32,
    bench_actual_pc_period_align_u32,
    bench_actual_pc_period_floor_u32,
    bench_actual_pc_range_center_i32,
    bench_actual_pc_range_intersects_i32,
    bench_actual_pc_range_shrink_i32,
    bench_actual_pc_ratio_between_u32,
    bench_actual_pc_ratio_ceil_u32,
    bench_actual_pc_ratio_round_even_u32,
    bench_actual_pc_round_to_multiple_i32,
    bench_actual_pc_saturating_add_i64,
    bench_actual_pc_saturating_add_u64,
    bench_actual_pc_saturating_cast_i64_i32,
    bench_actual_pc_saturating_cast_u64_u32,
    bench_actual_pc_saturating_mul_u64,
    bench_actual_pc_saturating_sub_i64,
    bench_actual_pc_saturating_sub_u64,
    bench_actual_pc_size_add_checked_u32,
    bench_actual_pc_size_mul_checked_u32,
    bench_actual_pc_time_convert_ceil_u64,
    bench_actual_pc_time_convert_floor_u64,
    bench_actual_pc_time_duration_absdiff_u64,
    bench_actual_pc_time_duration_clamp_u64,
    bench_actual_pc_time_scale_ratio_u64,
};
static bench_fn_t const baseline_bench[46] = {
    bench_baseline_pc_abs_diff_i64_u64,
    bench_baseline_pc_abs_i64_safe_u64,
    bench_baseline_pc_accumulate_abs_i32,
    bench_baseline_pc_align_down_u32,
    bench_baseline_pc_align_up_u32,
    bench_baseline_pc_ceil_to_multiple_i32,
    bench_baseline_pc_checked_abs_i64,
    bench_baseline_pc_checked_add_i64,
    bench_baseline_pc_checked_add_u64,
    bench_baseline_pc_checked_mul_i64,
    bench_baseline_pc_checked_mul_u64,
    bench_baseline_pc_checked_neg_i64,
    bench_baseline_pc_checked_shl_i32,
    bench_baseline_pc_checked_shl_u32,
    bench_baseline_pc_checked_sub_i64,
    bench_baseline_pc_checked_sub_u64,
    bench_baseline_pc_floor_to_multiple_i32,
    bench_baseline_pc_fraction_compare_i32,
    bench_baseline_pc_is_aligned_u32,
    bench_baseline_pc_lookup_clamped_i32,
    bench_baseline_pc_mask_range_u64,
    bench_baseline_pc_nearest_multiple_u32,
    bench_baseline_pc_offset_range_check_u32,
    bench_baseline_pc_period_align_u32,
    bench_baseline_pc_period_floor_u32,
    bench_baseline_pc_range_center_i32,
    bench_baseline_pc_range_intersects_i32,
    bench_baseline_pc_range_shrink_i32,
    bench_baseline_pc_ratio_between_u32,
    bench_baseline_pc_ratio_ceil_u32,
    bench_baseline_pc_ratio_round_even_u32,
    bench_baseline_pc_round_to_multiple_i32,
    bench_baseline_pc_saturating_add_i64,
    bench_baseline_pc_saturating_add_u64,
    bench_baseline_pc_saturating_cast_i64_i32,
    bench_baseline_pc_saturating_cast_u64_u32,
    bench_baseline_pc_saturating_mul_u64,
    bench_baseline_pc_saturating_sub_i64,
    bench_baseline_pc_saturating_sub_u64,
    bench_baseline_pc_size_add_checked_u32,
    bench_baseline_pc_size_mul_checked_u32,
    bench_baseline_pc_time_convert_ceil_u64,
    bench_baseline_pc_time_convert_floor_u64,
    bench_baseline_pc_time_duration_absdiff_u64,
    bench_baseline_pc_time_duration_clamp_u64,
    bench_baseline_pc_time_scale_ratio_u64,
};

void setup()
{
    Serial.begin(115200);
    delay(5000);
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
    Serial.printf("CLAUDARIS_ALL_PASS|passed=%lu/46|first_failed_api=%lu\n", (unsigned long)passed, (unsigned long)first_failure);
    if (passed == 46u) {
        const uint32_t loop_overhead = measure_loop_overhead();
        Serial.printf("CLAUDARIS_BENCH_META|cpu_mhz=%u|repetitions=%lu|samples=%lu|cycle_overhead_per_call=%lu|method=median(actual-minus-matched-noop)\n", getCpuFrequencyMhz(), (unsigned long)benchmark_repetitions, (unsigned long)benchmark_samples, (unsigned long)loop_overhead);
        for (uint32_t i = 0u; i < 46u; ++i) {
            const int32_t cycles = measure_api(actual_bench[i], baseline_bench[i]);
            Serial.printf("CLAUDARIS_CYCLE_MEDIAN|api_index=%lu|cycles=%ld\n", (unsigned long)(i + 1u), (long)cycles);
        }
        Serial.printf("CLAUDARIS_BENCH_SINK|%llu\n", (unsigned long long)benchmark_sink);
    }
}

void loop() { delay(1000); }
