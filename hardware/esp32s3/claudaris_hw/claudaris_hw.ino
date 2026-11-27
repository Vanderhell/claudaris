#include <Arduino.h>
#include <esp_cpu.h>
extern "C" {
#include <claudaris/arithmetic/abs_diff_i64_u64.h>
#include <claudaris/arithmetic/abs_i64_safe_u64.h>
#include <claudaris/arithmetic/accumulate_abs_i32.h>
#include <claudaris/arithmetic/align_down_u32.h>
#include <claudaris/arithmetic/align_up_u32.h>
#include <claudaris/arithmetic/ceil_to_multiple_i32.h>
#include <claudaris/arithmetic/checked_abs_i64.h>
#include <claudaris/arithmetic/checked_add_i64.h>
#include <claudaris/arithmetic/checked_add_u64.h>
#include <claudaris/arithmetic/checked_mul_i64.h>
#include <claudaris/arithmetic/checked_mul_u64.h>
#include <claudaris/arithmetic/checked_neg_i64.h>
#include <claudaris/arithmetic/checked_shl_i32.h>
#include <claudaris/arithmetic/checked_shl_u32.h>
#include <claudaris/arithmetic/checked_sub_i64.h>
#include <claudaris/arithmetic/checked_sub_u64.h>
#include <claudaris/arithmetic/floor_to_multiple_i32.h>
#include <claudaris/arithmetic/fraction_compare_i32.h>
#include <claudaris/arithmetic/is_aligned_u32.h>
#include <claudaris/arithmetic/lookup_clamped_i32.h>
#include <claudaris/arithmetic/mask_range_u64.h>
#include <claudaris/arithmetic/nearest_multiple_u32.h>
#include <claudaris/arithmetic/offset_range_check_u32.h>
#include <claudaris/arithmetic/period_align_u32.h>
#include <claudaris/arithmetic/period_floor_u32.h>
#include <claudaris/arithmetic/range_center_i32.h>
#include <claudaris/arithmetic/range_intersects_i32.h>
#include <claudaris/arithmetic/range_shrink_i32.h>
#include <claudaris/arithmetic/ratio_between_u32.h>
#include <claudaris/arithmetic/ratio_ceil_u32.h>
#include <claudaris/arithmetic/ratio_round_even_u32.h>
#include <claudaris/arithmetic/round_to_multiple_i32.h>
#include <claudaris/arithmetic/saturating_add_i64.h>
#include <claudaris/arithmetic/saturating_add_u64.h>
#include <claudaris/arithmetic/saturating_cast_i64_i32.h>
#include <claudaris/arithmetic/saturating_cast_u64_u32.h>
#include <claudaris/arithmetic/saturating_mul_u64.h>
#include <claudaris/arithmetic/saturating_sub_i64.h>
#include <claudaris/arithmetic/saturating_sub_u64.h>
#include <claudaris/arithmetic/size_add_checked_u32.h>
#include <claudaris/arithmetic/size_mul_checked_u32.h>
#include <claudaris/arithmetic/time_convert_ceil_u64.h>
#include <claudaris/arithmetic/time_convert_floor_u64.h>
#include <claudaris/arithmetic/time_duration_absdiff_u64.h>
#include <claudaris/arithmetic/time_duration_clamp_u64.h>
#include <claudaris/arithmetic/time_scale_ratio_u64.h>
#include "../../../src/claudaris_abs_diff_i64_u64.c"
#include "../../../src/claudaris_abs_i64_safe_u64.c"
#include "../../../src/claudaris_accumulate_abs_i32.c"
#include "../../../src/claudaris_align_down_u32.c"
#include "../../../src/claudaris_align_up_u32.c"
#include "../../../src/claudaris_ceil_to_multiple_i32.c"
#include "../../../src/claudaris_checked_abs_i64.c"
#include "../../../src/claudaris_checked_add_i64.c"
#include "../../../src/claudaris_checked_add_u64.c"
#include "../../../src/claudaris_checked_mul_i64.c"
#include "../../../src/claudaris_checked_mul_u64.c"
#include "../../../src/claudaris_checked_neg_i64.c"
#include "../../../src/claudaris_checked_shl_i32.c"
#include "../../../src/claudaris_checked_shl_u32.c"
#include "../../../src/claudaris_checked_sub_i64.c"
#include "../../../src/claudaris_checked_sub_u64.c"
#include "../../../src/claudaris_floor_to_multiple_i32.c"
#include "../../../src/claudaris_fraction_compare_i32.c"
#include "../../../src/claudaris_is_aligned_u32.c"
#include "../../../src/claudaris_lookup_clamped_i32.c"
#include "../../../src/claudaris_mask_range_u64.c"
#include "../../../src/claudaris_nearest_multiple_u32.c"
#include "../../../src/claudaris_offset_range_check_u32.c"
#include "../../../src/claudaris_period_align_u32.c"
#include "../../../src/claudaris_period_floor_u32.c"
#include "../../../src/claudaris_range_center_i32.c"
#include "../../../src/claudaris_range_intersects_i32.c"
#include "../../../src/claudaris_range_shrink_i32.c"
#include "../../../src/claudaris_ratio_between_u32.c"
#include "../../../src/claudaris_ratio_ceil_u32.c"
#include "../../../src/claudaris_ratio_round_even_u32.c"
#include "../../../src/claudaris_round_to_multiple_i32.c"
#include "../../../src/claudaris_saturating_add_i64.c"
#include "../../../src/claudaris_saturating_add_u64.c"
#include "../../../src/claudaris_saturating_cast_i64_i32.c"
#include "../../../src/claudaris_saturating_cast_u64_u32.c"
#include "../../../src/claudaris_saturating_mul_u64.c"
#include "../../../src/claudaris_saturating_sub_i64.c"
#include "../../../src/claudaris_saturating_sub_u64.c"
#include "../../../src/claudaris_size_add_checked_u32.c"
#include "../../../src/claudaris_size_mul_checked_u32.c"
#include "../../../src/claudaris_time_convert_ceil_u64.c"
#include "../../../src/claudaris_time_convert_floor_u64.c"
#include "../../../src/claudaris_time_duration_absdiff_u64.c"
#include "../../../src/claudaris_time_duration_clamp_u64.c"
#include "../../../src/claudaris_time_ratio_internal.c"
#include "../../../src/claudaris_time_scale_ratio_u64.c"
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

static uint64_t (* volatile api_ptr_claudaris_abs_diff_i64_u64)(int64_t, int64_t) = &claudaris_abs_diff_i64_u64;
static uint64_t baseline_claudaris_abs_diff_i64_u64(int64_t a, int64_t b)
{
    (void)a;
    (void)b;
    return (uint64_t)0;
}
static uint64_t (* volatile baseline_ptr_claudaris_abs_diff_i64_u64)(int64_t, int64_t) = &baseline_claudaris_abs_diff_i64_u64;
static CLAUDARIS_NOINLINE uint64_t bench_actual_claudaris_abs_diff_i64_u64(void)
{
    const uint64_t value = api_ptr_claudaris_abs_diff_i64_u64(arg_i64[0], arg_i64[1]);
    return (uint64_t)value;
}
static CLAUDARIS_NOINLINE uint64_t bench_baseline_claudaris_abs_diff_i64_u64(void)
{
    const uint64_t value = baseline_ptr_claudaris_abs_diff_i64_u64(arg_i64[0], arg_i64[1]);
    return (uint64_t)value;
}
static uint64_t (* volatile api_ptr_claudaris_abs_i64_safe_u64)(int64_t) = &claudaris_abs_i64_safe_u64;
static uint64_t baseline_claudaris_abs_i64_safe_u64(int64_t value)
{
    (void)value;
    return (uint64_t)0;
}
static uint64_t (* volatile baseline_ptr_claudaris_abs_i64_safe_u64)(int64_t) = &baseline_claudaris_abs_i64_safe_u64;
static CLAUDARIS_NOINLINE uint64_t bench_actual_claudaris_abs_i64_safe_u64(void)
{
    const uint64_t value = api_ptr_claudaris_abs_i64_safe_u64(arg_i64[0]);
    return (uint64_t)value;
}
static CLAUDARIS_NOINLINE uint64_t bench_baseline_claudaris_abs_i64_safe_u64(void)
{
    const uint64_t value = baseline_ptr_claudaris_abs_i64_safe_u64(arg_i64[0]);
    return (uint64_t)value;
}
static bool (* volatile api_ptr_claudaris_accumulate_abs_i32)(int32_t, uint64_t *) = &claudaris_accumulate_abs_i32;
static bool baseline_claudaris_accumulate_abs_i32(int32_t value, uint64_t * accumulator)
{
    (void)value;
    *accumulator = (uint64_t)0;
    return true;
}
static bool (* volatile baseline_ptr_claudaris_accumulate_abs_i32)(int32_t, uint64_t *) = &baseline_claudaris_accumulate_abs_i32;
static CLAUDARIS_NOINLINE uint64_t bench_actual_claudaris_accumulate_abs_i32(void)
{
    uint64_t accumulator = (uint64_t)0;
    const bool status = api_ptr_claudaris_accumulate_abs_i32(arg_i32[0], &accumulator);
    uint64_t value = status ? UINT64_C(1) : UINT64_C(0);
    value ^= (uint64_t)accumulator;
    return value;
}
static CLAUDARIS_NOINLINE uint64_t bench_baseline_claudaris_accumulate_abs_i32(void)
{
    uint64_t accumulator = (uint64_t)0;
    const bool status = baseline_ptr_claudaris_accumulate_abs_i32(arg_i32[0], &accumulator);
    uint64_t value = status ? UINT64_C(1) : UINT64_C(0);
    value ^= (uint64_t)accumulator;
    return value;
}
static bool (* volatile api_ptr_claudaris_align_down_u32)(uint32_t, uint32_t, uint32_t *) = &claudaris_align_down_u32;
static bool baseline_claudaris_align_down_u32(uint32_t value, uint32_t alignment, uint32_t * aligned)
{
    (void)value;
    (void)alignment;
    *aligned = (uint32_t)0;
    return true;
}
static bool (* volatile baseline_ptr_claudaris_align_down_u32)(uint32_t, uint32_t, uint32_t *) = &baseline_claudaris_align_down_u32;
static CLAUDARIS_NOINLINE uint64_t bench_actual_claudaris_align_down_u32(void)
{
    uint32_t aligned = (uint32_t)0;
    const bool status = api_ptr_claudaris_align_down_u32(arg_u32[0], arg_u32[1], &aligned);
    uint64_t value = status ? UINT64_C(1) : UINT64_C(0);
    value ^= (uint64_t)aligned;
    return value;
}
static CLAUDARIS_NOINLINE uint64_t bench_baseline_claudaris_align_down_u32(void)
{
    uint32_t aligned = (uint32_t)0;
    const bool status = baseline_ptr_claudaris_align_down_u32(arg_u32[0], arg_u32[1], &aligned);
    uint64_t value = status ? UINT64_C(1) : UINT64_C(0);
    value ^= (uint64_t)aligned;
    return value;
}
static bool (* volatile api_ptr_claudaris_align_up_u32)(uint32_t, uint32_t, uint32_t *) = &claudaris_align_up_u32;
static bool baseline_claudaris_align_up_u32(uint32_t value, uint32_t alignment, uint32_t * aligned)
{
    (void)value;
    (void)alignment;
    *aligned = (uint32_t)0;
    return true;
}
static bool (* volatile baseline_ptr_claudaris_align_up_u32)(uint32_t, uint32_t, uint32_t *) = &baseline_claudaris_align_up_u32;
static CLAUDARIS_NOINLINE uint64_t bench_actual_claudaris_align_up_u32(void)
{
    uint32_t aligned = (uint32_t)0;
    const bool status = api_ptr_claudaris_align_up_u32(arg_u32[0], arg_u32[1], &aligned);
    uint64_t value = status ? UINT64_C(1) : UINT64_C(0);
    value ^= (uint64_t)aligned;
    return value;
}
static CLAUDARIS_NOINLINE uint64_t bench_baseline_claudaris_align_up_u32(void)
{
    uint32_t aligned = (uint32_t)0;
    const bool status = baseline_ptr_claudaris_align_up_u32(arg_u32[0], arg_u32[1], &aligned);
    uint64_t value = status ? UINT64_C(1) : UINT64_C(0);
    value ^= (uint64_t)aligned;
    return value;
}
static bool (* volatile api_ptr_claudaris_ceil_to_multiple_i32)(int32_t, int32_t, int32_t *) = &claudaris_ceil_to_multiple_i32;
static bool baseline_claudaris_ceil_to_multiple_i32(int32_t value, int32_t multiple, int32_t * rounded)
{
    (void)value;
    (void)multiple;
    *rounded = (int32_t)0;
    return true;
}
static bool (* volatile baseline_ptr_claudaris_ceil_to_multiple_i32)(int32_t, int32_t, int32_t *) = &baseline_claudaris_ceil_to_multiple_i32;
static CLAUDARIS_NOINLINE uint64_t bench_actual_claudaris_ceil_to_multiple_i32(void)
{
    int32_t rounded = (int32_t)0;
    const bool status = api_ptr_claudaris_ceil_to_multiple_i32(arg_i32[0], arg_i32[2], &rounded);
    uint64_t value = status ? UINT64_C(1) : UINT64_C(0);
    value ^= (uint64_t)rounded;
    return value;
}
static CLAUDARIS_NOINLINE uint64_t bench_baseline_claudaris_ceil_to_multiple_i32(void)
{
    int32_t rounded = (int32_t)0;
    const bool status = baseline_ptr_claudaris_ceil_to_multiple_i32(arg_i32[0], arg_i32[2], &rounded);
    uint64_t value = status ? UINT64_C(1) : UINT64_C(0);
    value ^= (uint64_t)rounded;
    return value;
}
static bool (* volatile api_ptr_claudaris_checked_abs_i64)(int64_t, int64_t *) = &claudaris_checked_abs_i64;
static bool baseline_claudaris_checked_abs_i64(int64_t value, int64_t * result)
{
    (void)value;
    *result = (int64_t)0;
    return true;
}
static bool (* volatile baseline_ptr_claudaris_checked_abs_i64)(int64_t, int64_t *) = &baseline_claudaris_checked_abs_i64;
static CLAUDARIS_NOINLINE uint64_t bench_actual_claudaris_checked_abs_i64(void)
{
    int64_t result = (int64_t)0;
    const bool status = api_ptr_claudaris_checked_abs_i64(arg_i64[2], &result);
    uint64_t checksum = status ? UINT64_C(1) : UINT64_C(0);
    checksum ^= (uint64_t)result;
    return checksum;
}
static CLAUDARIS_NOINLINE uint64_t bench_baseline_claudaris_checked_abs_i64(void)
{
    int64_t result = (int64_t)0;
    const bool status = baseline_ptr_claudaris_checked_abs_i64(arg_i64[2], &result);
    uint64_t checksum = status ? UINT64_C(1) : UINT64_C(0);
    checksum ^= (uint64_t)result;
    return checksum;
}
static bool (* volatile api_ptr_claudaris_checked_add_i64)(int64_t, int64_t, int64_t *) = &claudaris_checked_add_i64;
static bool baseline_claudaris_checked_add_i64(int64_t a, int64_t b, int64_t * result)
{
    (void)a;
    (void)b;
    *result = (int64_t)0;
    return true;
}
static bool (* volatile baseline_ptr_claudaris_checked_add_i64)(int64_t, int64_t, int64_t *) = &baseline_claudaris_checked_add_i64;
static CLAUDARIS_NOINLINE uint64_t bench_actual_claudaris_checked_add_i64(void)
{
    int64_t result = (int64_t)0;
    const bool status = api_ptr_claudaris_checked_add_i64(arg_i64[1], arg_i64[4], &result);
    uint64_t checksum = status ? UINT64_C(1) : UINT64_C(0);
    checksum ^= (uint64_t)result;
    return checksum;
}
static CLAUDARIS_NOINLINE uint64_t bench_baseline_claudaris_checked_add_i64(void)
{
    int64_t result = (int64_t)0;
    const bool status = baseline_ptr_claudaris_checked_add_i64(arg_i64[1], arg_i64[4], &result);
    uint64_t checksum = status ? UINT64_C(1) : UINT64_C(0);
    checksum ^= (uint64_t)result;
    return checksum;
}
static bool (* volatile api_ptr_claudaris_checked_add_u64)(uint64_t, uint64_t, uint64_t *) = &claudaris_checked_add_u64;
static bool baseline_claudaris_checked_add_u64(uint64_t a, uint64_t b, uint64_t * result)
{
    (void)a;
    (void)b;
    *result = (uint64_t)0;
    return true;
}
static bool (* volatile baseline_ptr_claudaris_checked_add_u64)(uint64_t, uint64_t, uint64_t *) = &baseline_claudaris_checked_add_u64;
static CLAUDARIS_NOINLINE uint64_t bench_actual_claudaris_checked_add_u64(void)
{
    uint64_t result = (uint64_t)0;
    const bool status = api_ptr_claudaris_checked_add_u64(arg_u64[0], arg_u64[1], &result);
    uint64_t checksum = status ? UINT64_C(1) : UINT64_C(0);
    checksum ^= (uint64_t)result;
    return checksum;
}
static CLAUDARIS_NOINLINE uint64_t bench_baseline_claudaris_checked_add_u64(void)
{
    uint64_t result = (uint64_t)0;
    const bool status = baseline_ptr_claudaris_checked_add_u64(arg_u64[0], arg_u64[1], &result);
    uint64_t checksum = status ? UINT64_C(1) : UINT64_C(0);
    checksum ^= (uint64_t)result;
    return checksum;
}
static bool (* volatile api_ptr_claudaris_checked_mul_i64)(int64_t, int64_t, int64_t *) = &claudaris_checked_mul_i64;
static bool baseline_claudaris_checked_mul_i64(int64_t a, int64_t b, int64_t * result)
{
    (void)a;
    (void)b;
    *result = (int64_t)0;
    return true;
}
static bool (* volatile baseline_ptr_claudaris_checked_mul_i64)(int64_t, int64_t, int64_t *) = &baseline_claudaris_checked_mul_i64;
static CLAUDARIS_NOINLINE uint64_t bench_actual_claudaris_checked_mul_i64(void)
{
    int64_t result = (int64_t)0;
    const bool status = api_ptr_claudaris_checked_mul_i64(arg_i64[2], arg_i64[3], &result);
    uint64_t checksum = status ? UINT64_C(1) : UINT64_C(0);
    checksum ^= (uint64_t)result;
    return checksum;
}
static CLAUDARIS_NOINLINE uint64_t bench_baseline_claudaris_checked_mul_i64(void)
{
    int64_t result = (int64_t)0;
    const bool status = baseline_ptr_claudaris_checked_mul_i64(arg_i64[2], arg_i64[3], &result);
    uint64_t checksum = status ? UINT64_C(1) : UINT64_C(0);
    checksum ^= (uint64_t)result;
    return checksum;
}
static bool (* volatile api_ptr_claudaris_checked_mul_u64)(uint64_t, uint64_t, uint64_t *) = &claudaris_checked_mul_u64;
static bool baseline_claudaris_checked_mul_u64(uint64_t a, uint64_t b, uint64_t * result)
{
    (void)a;
    (void)b;
    *result = (uint64_t)0;
    return true;
}
static bool (* volatile baseline_ptr_claudaris_checked_mul_u64)(uint64_t, uint64_t, uint64_t *) = &baseline_claudaris_checked_mul_u64;
static CLAUDARIS_NOINLINE uint64_t bench_actual_claudaris_checked_mul_u64(void)
{
    uint64_t result = (uint64_t)0;
    const bool status = api_ptr_claudaris_checked_mul_u64(arg_u64[0], arg_u64[2], &result);
    uint64_t checksum = status ? UINT64_C(1) : UINT64_C(0);
    checksum ^= (uint64_t)result;
    return checksum;
}
static CLAUDARIS_NOINLINE uint64_t bench_baseline_claudaris_checked_mul_u64(void)
{
    uint64_t result = (uint64_t)0;
    const bool status = baseline_ptr_claudaris_checked_mul_u64(arg_u64[0], arg_u64[2], &result);
    uint64_t checksum = status ? UINT64_C(1) : UINT64_C(0);
    checksum ^= (uint64_t)result;
    return checksum;
}
static bool (* volatile api_ptr_claudaris_checked_neg_i64)(int64_t, int64_t *) = &claudaris_checked_neg_i64;
static bool baseline_claudaris_checked_neg_i64(int64_t value, int64_t * result)
{
    (void)value;
    *result = (int64_t)0;
    return true;
}
static bool (* volatile baseline_ptr_claudaris_checked_neg_i64)(int64_t, int64_t *) = &baseline_claudaris_checked_neg_i64;
static CLAUDARIS_NOINLINE uint64_t bench_actual_claudaris_checked_neg_i64(void)
{
    int64_t result = (int64_t)0;
    const bool status = api_ptr_claudaris_checked_neg_i64(arg_i64[2], &result);
    uint64_t checksum = status ? UINT64_C(1) : UINT64_C(0);
    checksum ^= (uint64_t)result;
    return checksum;
}
static CLAUDARIS_NOINLINE uint64_t bench_baseline_claudaris_checked_neg_i64(void)
{
    int64_t result = (int64_t)0;
    const bool status = baseline_ptr_claudaris_checked_neg_i64(arg_i64[2], &result);
    uint64_t checksum = status ? UINT64_C(1) : UINT64_C(0);
    checksum ^= (uint64_t)result;
    return checksum;
}
static bool (* volatile api_ptr_claudaris_checked_shl_i32)(int32_t, unsigned, int32_t *) = &claudaris_checked_shl_i32;
static bool baseline_claudaris_checked_shl_i32(int32_t value, unsigned shift, int32_t * result)
{
    (void)value;
    (void)shift;
    *result = (int32_t)0;
    return true;
}
static bool (* volatile baseline_ptr_claudaris_checked_shl_i32)(int32_t, unsigned, int32_t *) = &baseline_claudaris_checked_shl_i32;
static CLAUDARIS_NOINLINE uint64_t bench_actual_claudaris_checked_shl_i32(void)
{
    int32_t result = (int32_t)0;
    const bool status = api_ptr_claudaris_checked_shl_i32(arg_i32[1], arg_unsigned[0], &result);
    uint64_t checksum = status ? UINT64_C(1) : UINT64_C(0);
    checksum ^= (uint64_t)result;
    return checksum;
}
static CLAUDARIS_NOINLINE uint64_t bench_baseline_claudaris_checked_shl_i32(void)
{
    int32_t result = (int32_t)0;
    const bool status = baseline_ptr_claudaris_checked_shl_i32(arg_i32[1], arg_unsigned[0], &result);
    uint64_t checksum = status ? UINT64_C(1) : UINT64_C(0);
    checksum ^= (uint64_t)result;
    return checksum;
}
static bool (* volatile api_ptr_claudaris_checked_shl_u32)(uint32_t, unsigned, uint32_t *) = &claudaris_checked_shl_u32;
static bool baseline_claudaris_checked_shl_u32(uint32_t value, unsigned shift, uint32_t * result)
{
    (void)value;
    (void)shift;
    *result = (uint32_t)0;
    return true;
}
static bool (* volatile baseline_ptr_claudaris_checked_shl_u32)(uint32_t, unsigned, uint32_t *) = &baseline_claudaris_checked_shl_u32;
static CLAUDARIS_NOINLINE uint64_t bench_actual_claudaris_checked_shl_u32(void)
{
    uint32_t result = (uint32_t)0;
    const bool status = api_ptr_claudaris_checked_shl_u32(arg_u32[11], arg_unsigned[1], &result);
    uint64_t checksum = status ? UINT64_C(1) : UINT64_C(0);
    checksum ^= (uint64_t)result;
    return checksum;
}
static CLAUDARIS_NOINLINE uint64_t bench_baseline_claudaris_checked_shl_u32(void)
{
    uint32_t result = (uint32_t)0;
    const bool status = baseline_ptr_claudaris_checked_shl_u32(arg_u32[11], arg_unsigned[1], &result);
    uint64_t checksum = status ? UINT64_C(1) : UINT64_C(0);
    checksum ^= (uint64_t)result;
    return checksum;
}
static bool (* volatile api_ptr_claudaris_checked_sub_i64)(int64_t, int64_t, int64_t *) = &claudaris_checked_sub_i64;
static bool baseline_claudaris_checked_sub_i64(int64_t a, int64_t b, int64_t * result)
{
    (void)a;
    (void)b;
    *result = (int64_t)0;
    return true;
}
static bool (* volatile baseline_ptr_claudaris_checked_sub_i64)(int64_t, int64_t, int64_t *) = &baseline_claudaris_checked_sub_i64;
static CLAUDARIS_NOINLINE uint64_t bench_actual_claudaris_checked_sub_i64(void)
{
    int64_t result = (int64_t)0;
    const bool status = api_ptr_claudaris_checked_sub_i64(arg_i64[0], arg_i64[4], &result);
    uint64_t checksum = status ? UINT64_C(1) : UINT64_C(0);
    checksum ^= (uint64_t)result;
    return checksum;
}
static CLAUDARIS_NOINLINE uint64_t bench_baseline_claudaris_checked_sub_i64(void)
{
    int64_t result = (int64_t)0;
    const bool status = baseline_ptr_claudaris_checked_sub_i64(arg_i64[0], arg_i64[4], &result);
    uint64_t checksum = status ? UINT64_C(1) : UINT64_C(0);
    checksum ^= (uint64_t)result;
    return checksum;
}
static bool (* volatile api_ptr_claudaris_checked_sub_u64)(uint64_t, uint64_t, uint64_t *) = &claudaris_checked_sub_u64;
static bool baseline_claudaris_checked_sub_u64(uint64_t a, uint64_t b, uint64_t * result)
{
    (void)a;
    (void)b;
    *result = (uint64_t)0;
    return true;
}
static bool (* volatile baseline_ptr_claudaris_checked_sub_u64)(uint64_t, uint64_t, uint64_t *) = &baseline_claudaris_checked_sub_u64;
static CLAUDARIS_NOINLINE uint64_t bench_actual_claudaris_checked_sub_u64(void)
{
    uint64_t result = (uint64_t)0;
    const bool status = api_ptr_claudaris_checked_sub_u64(arg_u64[0], arg_u64[1], &result);
    uint64_t checksum = status ? UINT64_C(1) : UINT64_C(0);
    checksum ^= (uint64_t)result;
    return checksum;
}
static CLAUDARIS_NOINLINE uint64_t bench_baseline_claudaris_checked_sub_u64(void)
{
    uint64_t result = (uint64_t)0;
    const bool status = baseline_ptr_claudaris_checked_sub_u64(arg_u64[0], arg_u64[1], &result);
    uint64_t checksum = status ? UINT64_C(1) : UINT64_C(0);
    checksum ^= (uint64_t)result;
    return checksum;
}
static bool (* volatile api_ptr_claudaris_floor_to_multiple_i32)(int32_t, int32_t, int32_t *) = &claudaris_floor_to_multiple_i32;
static bool baseline_claudaris_floor_to_multiple_i32(int32_t value, int32_t multiple, int32_t * rounded)
{
    (void)value;
    (void)multiple;
    *rounded = (int32_t)0;
    return true;
}
static bool (* volatile baseline_ptr_claudaris_floor_to_multiple_i32)(int32_t, int32_t, int32_t *) = &baseline_claudaris_floor_to_multiple_i32;
static CLAUDARIS_NOINLINE uint64_t bench_actual_claudaris_floor_to_multiple_i32(void)
{
    int32_t rounded = (int32_t)0;
    const bool status = api_ptr_claudaris_floor_to_multiple_i32(arg_i32[0], arg_i32[2], &rounded);
    uint64_t value = status ? UINT64_C(1) : UINT64_C(0);
    value ^= (uint64_t)rounded;
    return value;
}
static CLAUDARIS_NOINLINE uint64_t bench_baseline_claudaris_floor_to_multiple_i32(void)
{
    int32_t rounded = (int32_t)0;
    const bool status = baseline_ptr_claudaris_floor_to_multiple_i32(arg_i32[0], arg_i32[2], &rounded);
    uint64_t value = status ? UINT64_C(1) : UINT64_C(0);
    value ^= (uint64_t)rounded;
    return value;
}
static bool (* volatile api_ptr_claudaris_fraction_compare_i32)(int32_t, int32_t, int32_t, int32_t, int *) = &claudaris_fraction_compare_i32;
static bool baseline_claudaris_fraction_compare_i32(int32_t a_num, int32_t a_den, int32_t b_num, int32_t b_den, int * comparison)
{
    (void)a_num;
    (void)a_den;
    (void)b_num;
    (void)b_den;
    *comparison = (int)0;
    return true;
}
static bool (* volatile baseline_ptr_claudaris_fraction_compare_i32)(int32_t, int32_t, int32_t, int32_t, int *) = &baseline_claudaris_fraction_compare_i32;
static CLAUDARIS_NOINLINE uint64_t bench_actual_claudaris_fraction_compare_i32(void)
{
    int comparison = (int)0;
    const bool status = api_ptr_claudaris_fraction_compare_i32(arg_i32[6], arg_i32[2], arg_i32[4], arg_i32[5], &comparison);
    uint64_t value = status ? UINT64_C(1) : UINT64_C(0);
    value ^= (uint64_t)comparison;
    return value;
}
static CLAUDARIS_NOINLINE uint64_t bench_baseline_claudaris_fraction_compare_i32(void)
{
    int comparison = (int)0;
    const bool status = baseline_ptr_claudaris_fraction_compare_i32(arg_i32[6], arg_i32[2], arg_i32[4], arg_i32[5], &comparison);
    uint64_t value = status ? UINT64_C(1) : UINT64_C(0);
    value ^= (uint64_t)comparison;
    return value;
}
static bool (* volatile api_ptr_claudaris_is_aligned_u32)(uint32_t, uint32_t) = &claudaris_is_aligned_u32;
static bool baseline_claudaris_is_aligned_u32(uint32_t value, uint32_t alignment)
{
    (void)value;
    (void)alignment;
    return true;
}
static bool (* volatile baseline_ptr_claudaris_is_aligned_u32)(uint32_t, uint32_t) = &baseline_claudaris_is_aligned_u32;
static CLAUDARIS_NOINLINE uint64_t bench_actual_claudaris_is_aligned_u32(void)
{
    const bool status = api_ptr_claudaris_is_aligned_u32(arg_u32[2], arg_u32[3]);
    return (uint64_t)status;
}
static CLAUDARIS_NOINLINE uint64_t bench_baseline_claudaris_is_aligned_u32(void)
{
    const bool status = baseline_ptr_claudaris_is_aligned_u32(arg_u32[2], arg_u32[3]);
    return (uint64_t)status;
}
static bool (* volatile api_ptr_claudaris_lookup_clamped_i32)(const int32_t *, size_t, int32_t, int32_t *) = &claudaris_lookup_clamped_i32;
static bool baseline_claudaris_lookup_clamped_i32(const int32_t * table, size_t count, int32_t index, int32_t * value)
{
    (void)table;
    (void)count;
    (void)index;
    *value = (int32_t)0;
    return true;
}
static bool (* volatile baseline_ptr_claudaris_lookup_clamped_i32)(const int32_t *, size_t, int32_t, int32_t *) = &baseline_claudaris_lookup_clamped_i32;
static CLAUDARIS_NOINLINE uint64_t bench_actual_claudaris_lookup_clamped_i32(void)
{
    int32_t output = (int32_t)0;
    const bool status = api_ptr_claudaris_lookup_clamped_i32(table_data, 3u, arg_i32[7], &output);
    uint64_t checksum = status ? UINT64_C(1) : UINT64_C(0);
    checksum ^= (uint64_t)(int64_t)output;
    return checksum;
}
static CLAUDARIS_NOINLINE uint64_t bench_baseline_claudaris_lookup_clamped_i32(void)
{
    int32_t output = (int32_t)0;
    const bool status = baseline_ptr_claudaris_lookup_clamped_i32(table_data, 3u, arg_i32[7], &output);
    uint64_t checksum = status ? UINT64_C(1) : UINT64_C(0);
    checksum ^= (uint64_t)(int64_t)output;
    return checksum;
}
static bool (* volatile api_ptr_claudaris_mask_range_u64)(uint8_t, uint8_t, uint64_t *) = &claudaris_mask_range_u64;
static bool baseline_claudaris_mask_range_u64(uint8_t first_bit, uint8_t last_bit, uint64_t * mask)
{
    (void)first_bit;
    (void)last_bit;
    *mask = (uint64_t)0;
    return true;
}
static bool (* volatile baseline_ptr_claudaris_mask_range_u64)(uint8_t, uint8_t, uint64_t *) = &baseline_claudaris_mask_range_u64;
static CLAUDARIS_NOINLINE uint64_t bench_actual_claudaris_mask_range_u64(void)
{
    uint64_t mask = (uint64_t)0;
    const bool status = api_ptr_claudaris_mask_range_u64(arg_u32[11], arg_u32[6], &mask);
    uint64_t value = status ? UINT64_C(1) : UINT64_C(0);
    value ^= (uint64_t)mask;
    return value;
}
static CLAUDARIS_NOINLINE uint64_t bench_baseline_claudaris_mask_range_u64(void)
{
    uint64_t mask = (uint64_t)0;
    const bool status = baseline_ptr_claudaris_mask_range_u64(arg_u32[11], arg_u32[6], &mask);
    uint64_t value = status ? UINT64_C(1) : UINT64_C(0);
    value ^= (uint64_t)mask;
    return value;
}
static bool (* volatile api_ptr_claudaris_nearest_multiple_u32)(uint32_t, uint32_t, uint32_t *) = &claudaris_nearest_multiple_u32;
static bool baseline_claudaris_nearest_multiple_u32(uint32_t value, uint32_t multiple, uint32_t * rounded)
{
    (void)value;
    (void)multiple;
    *rounded = (uint32_t)0;
    return true;
}
static bool (* volatile baseline_ptr_claudaris_nearest_multiple_u32)(uint32_t, uint32_t, uint32_t *) = &baseline_claudaris_nearest_multiple_u32;
static CLAUDARIS_NOINLINE uint64_t bench_actual_claudaris_nearest_multiple_u32(void)
{
    uint32_t rounded = (uint32_t)0;
    const bool status = api_ptr_claudaris_nearest_multiple_u32(arg_u32[4], arg_u32[5], &rounded);
    uint64_t value = status ? UINT64_C(1) : UINT64_C(0);
    value ^= (uint64_t)rounded;
    return value;
}
static CLAUDARIS_NOINLINE uint64_t bench_baseline_claudaris_nearest_multiple_u32(void)
{
    uint32_t rounded = (uint32_t)0;
    const bool status = baseline_ptr_claudaris_nearest_multiple_u32(arg_u32[4], arg_u32[5], &rounded);
    uint64_t value = status ? UINT64_C(1) : UINT64_C(0);
    value ^= (uint64_t)rounded;
    return value;
}
static bool (* volatile api_ptr_claudaris_offset_range_check_u32)(uint32_t, uint32_t, uint32_t) = &claudaris_offset_range_check_u32;
static bool baseline_claudaris_offset_range_check_u32(uint32_t offset, uint32_t length, uint32_t capacity)
{
    (void)offset;
    (void)length;
    (void)capacity;
    return true;
}
static bool (* volatile baseline_ptr_claudaris_offset_range_check_u32)(uint32_t, uint32_t, uint32_t) = &baseline_claudaris_offset_range_check_u32;
static CLAUDARIS_NOINLINE uint64_t bench_actual_claudaris_offset_range_check_u32(void)
{
    const bool status = api_ptr_claudaris_offset_range_check_u32(arg_u32[6], arg_u32[7], arg_u32[8]);
    return (uint64_t)status;
}
static CLAUDARIS_NOINLINE uint64_t bench_baseline_claudaris_offset_range_check_u32(void)
{
    const bool status = baseline_ptr_claudaris_offset_range_check_u32(arg_u32[6], arg_u32[7], arg_u32[8]);
    return (uint64_t)status;
}
static bool (* volatile api_ptr_claudaris_period_align_u32)(uint32_t, uint32_t, uint32_t, uint32_t *) = &claudaris_period_align_u32;
static bool baseline_claudaris_period_align_u32(uint32_t time, uint32_t origin, uint32_t period, uint32_t * aligned)
{
    (void)time;
    (void)origin;
    (void)period;
    *aligned = (uint32_t)0;
    return true;
}
static bool (* volatile baseline_ptr_claudaris_period_align_u32)(uint32_t, uint32_t, uint32_t, uint32_t *) = &baseline_claudaris_period_align_u32;
static CLAUDARIS_NOINLINE uint64_t bench_actual_claudaris_period_align_u32(void)
{
    uint32_t aligned = (uint32_t)0;
    const bool status = api_ptr_claudaris_period_align_u32(arg_u32[8], arg_u32[10], arg_u32[4], &aligned);
    uint64_t value = status ? UINT64_C(1) : UINT64_C(0);
    value ^= (uint64_t)aligned;
    return value;
}
static CLAUDARIS_NOINLINE uint64_t bench_baseline_claudaris_period_align_u32(void)
{
    uint32_t aligned = (uint32_t)0;
    const bool status = baseline_ptr_claudaris_period_align_u32(arg_u32[8], arg_u32[10], arg_u32[4], &aligned);
    uint64_t value = status ? UINT64_C(1) : UINT64_C(0);
    value ^= (uint64_t)aligned;
    return value;
}
static bool (* volatile api_ptr_claudaris_period_floor_u32)(uint32_t, uint32_t, uint32_t, uint32_t *) = &claudaris_period_floor_u32;
static bool baseline_claudaris_period_floor_u32(uint32_t time, uint32_t origin, uint32_t period, uint32_t * aligned)
{
    (void)time;
    (void)origin;
    (void)period;
    *aligned = (uint32_t)0;
    return true;
}
static bool (* volatile baseline_ptr_claudaris_period_floor_u32)(uint32_t, uint32_t, uint32_t, uint32_t *) = &baseline_claudaris_period_floor_u32;
static CLAUDARIS_NOINLINE uint64_t bench_actual_claudaris_period_floor_u32(void)
{
    uint32_t aligned = (uint32_t)0;
    const bool status = api_ptr_claudaris_period_floor_u32(arg_u32[8], arg_u32[10], arg_u32[4], &aligned);
    uint64_t value = status ? UINT64_C(1) : UINT64_C(0);
    value ^= (uint64_t)aligned;
    return value;
}
static CLAUDARIS_NOINLINE uint64_t bench_baseline_claudaris_period_floor_u32(void)
{
    uint32_t aligned = (uint32_t)0;
    const bool status = baseline_ptr_claudaris_period_floor_u32(arg_u32[8], arg_u32[10], arg_u32[4], &aligned);
    uint64_t value = status ? UINT64_C(1) : UINT64_C(0);
    value ^= (uint64_t)aligned;
    return value;
}
static bool (* volatile api_ptr_claudaris_range_center_i32)(int32_t, int32_t, int32_t *) = &claudaris_range_center_i32;
static bool baseline_claudaris_range_center_i32(int32_t lower, int32_t upper, int32_t * center)
{
    (void)lower;
    (void)upper;
    *center = (int32_t)0;
    return true;
}
static bool (* volatile baseline_ptr_claudaris_range_center_i32)(int32_t, int32_t, int32_t *) = &baseline_claudaris_range_center_i32;
static CLAUDARIS_NOINLINE uint64_t bench_actual_claudaris_range_center_i32(void)
{
    int32_t center = (int32_t)0;
    const bool status = api_ptr_claudaris_range_center_i32(arg_i32[1], arg_i32[2], &center);
    uint64_t value = status ? UINT64_C(1) : UINT64_C(0);
    value ^= (uint64_t)center;
    return value;
}
static CLAUDARIS_NOINLINE uint64_t bench_baseline_claudaris_range_center_i32(void)
{
    int32_t center = (int32_t)0;
    const bool status = baseline_ptr_claudaris_range_center_i32(arg_i32[1], arg_i32[2], &center);
    uint64_t value = status ? UINT64_C(1) : UINT64_C(0);
    value ^= (uint64_t)center;
    return value;
}
static bool (* volatile api_ptr_claudaris_range_intersects_i32)(int32_t, int32_t, int32_t, int32_t) = &claudaris_range_intersects_i32;
static bool baseline_claudaris_range_intersects_i32(int32_t a_lower, int32_t a_upper, int32_t b_lower, int32_t b_upper)
{
    (void)a_lower;
    (void)a_upper;
    (void)b_lower;
    (void)b_upper;
    return true;
}
static bool (* volatile baseline_ptr_claudaris_range_intersects_i32)(int32_t, int32_t, int32_t, int32_t) = &baseline_claudaris_range_intersects_i32;
static CLAUDARIS_NOINLINE uint64_t bench_actual_claudaris_range_intersects_i32(void)
{
    const bool status = api_ptr_claudaris_range_intersects_i32(arg_i32[11], arg_i32[12], arg_i32[12], arg_i32[9]);
    return (uint64_t)status;
}
static CLAUDARIS_NOINLINE uint64_t bench_baseline_claudaris_range_intersects_i32(void)
{
    const bool status = baseline_ptr_claudaris_range_intersects_i32(arg_i32[11], arg_i32[12], arg_i32[12], arg_i32[9]);
    return (uint64_t)status;
}
static bool (* volatile api_ptr_claudaris_range_shrink_i32)(int32_t, int32_t, uint32_t, int32_t *, int32_t *) = &claudaris_range_shrink_i32;
static bool baseline_claudaris_range_shrink_i32(int32_t lower, int32_t upper, uint32_t amount, int32_t * shrunk_lower, int32_t * shrunk_upper)
{
    (void)lower;
    (void)upper;
    (void)amount;
    *shrunk_lower = (int32_t)0;
    *shrunk_upper = (int32_t)0;
    return true;
}
static bool (* volatile baseline_ptr_claudaris_range_shrink_i32)(int32_t, int32_t, uint32_t, int32_t *, int32_t *) = &baseline_claudaris_range_shrink_i32;
static CLAUDARIS_NOINLINE uint64_t bench_actual_claudaris_range_shrink_i32(void)
{
    int32_t shrunk_lower = (int32_t)0;
    int32_t shrunk_upper = (int32_t)0;
    const bool status = api_ptr_claudaris_range_shrink_i32(arg_i32[7], arg_i32[8], arg_u32[5], &shrunk_lower, &shrunk_upper);
    uint64_t value = status ? UINT64_C(1) : UINT64_C(0);
    value ^= (uint64_t)shrunk_lower;
    value ^= (uint64_t)shrunk_upper;
    return value;
}
static CLAUDARIS_NOINLINE uint64_t bench_baseline_claudaris_range_shrink_i32(void)
{
    int32_t shrunk_lower = (int32_t)0;
    int32_t shrunk_upper = (int32_t)0;
    const bool status = baseline_ptr_claudaris_range_shrink_i32(arg_i32[7], arg_i32[8], arg_u32[5], &shrunk_lower, &shrunk_upper);
    uint64_t value = status ? UINT64_C(1) : UINT64_C(0);
    value ^= (uint64_t)shrunk_lower;
    value ^= (uint64_t)shrunk_upper;
    return value;
}
static bool (* volatile api_ptr_claudaris_ratio_between_u32)(uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, bool *) = &claudaris_ratio_between_u32;
static bool baseline_claudaris_ratio_between_u32(uint32_t numerator, uint32_t denominator, uint32_t lower_num, uint32_t lower_den, uint32_t upper_num, uint32_t upper_den, bool * is_between)
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
static bool (* volatile baseline_ptr_claudaris_ratio_between_u32)(uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, bool *) = &baseline_claudaris_ratio_between_u32;
static CLAUDARIS_NOINLINE uint64_t bench_actual_claudaris_ratio_between_u32(void)
{
    bool is_between = (bool)0;
    const bool status = api_ptr_claudaris_ratio_between_u32(arg_u32[11], arg_u32[5], arg_u32[11], arg_u32[6], arg_u32[5], arg_u32[6], &is_between);
    uint64_t value = status ? UINT64_C(1) : UINT64_C(0);
    value ^= (uint64_t)is_between;
    return value;
}
static CLAUDARIS_NOINLINE uint64_t bench_baseline_claudaris_ratio_between_u32(void)
{
    bool is_between = (bool)0;
    const bool status = baseline_ptr_claudaris_ratio_between_u32(arg_u32[11], arg_u32[5], arg_u32[11], arg_u32[6], arg_u32[5], arg_u32[6], &is_between);
    uint64_t value = status ? UINT64_C(1) : UINT64_C(0);
    value ^= (uint64_t)is_between;
    return value;
}
static bool (* volatile api_ptr_claudaris_ratio_ceil_u32)(uint32_t, uint32_t, uint32_t *) = &claudaris_ratio_ceil_u32;
static bool baseline_claudaris_ratio_ceil_u32(uint32_t numerator, uint32_t denominator, uint32_t * quotient)
{
    (void)numerator;
    (void)denominator;
    *quotient = (uint32_t)0;
    return true;
}
static bool (* volatile baseline_ptr_claudaris_ratio_ceil_u32)(uint32_t, uint32_t, uint32_t *) = &baseline_claudaris_ratio_ceil_u32;
static CLAUDARIS_NOINLINE uint64_t bench_actual_claudaris_ratio_ceil_u32(void)
{
    uint32_t quotient = (uint32_t)0;
    const bool status = api_ptr_claudaris_ratio_ceil_u32(arg_u32[9], arg_u32[6], &quotient);
    uint64_t value = status ? UINT64_C(1) : UINT64_C(0);
    value ^= (uint64_t)quotient;
    return value;
}
static CLAUDARIS_NOINLINE uint64_t bench_baseline_claudaris_ratio_ceil_u32(void)
{
    uint32_t quotient = (uint32_t)0;
    const bool status = baseline_ptr_claudaris_ratio_ceil_u32(arg_u32[9], arg_u32[6], &quotient);
    uint64_t value = status ? UINT64_C(1) : UINT64_C(0);
    value ^= (uint64_t)quotient;
    return value;
}
static bool (* volatile api_ptr_claudaris_ratio_round_even_u32)(uint32_t, uint32_t, uint32_t *) = &claudaris_ratio_round_even_u32;
static bool baseline_claudaris_ratio_round_even_u32(uint32_t numerator, uint32_t denominator, uint32_t * rounded)
{
    (void)numerator;
    (void)denominator;
    *rounded = (uint32_t)0;
    return true;
}
static bool (* volatile baseline_ptr_claudaris_ratio_round_even_u32)(uint32_t, uint32_t, uint32_t *) = &baseline_claudaris_ratio_round_even_u32;
static CLAUDARIS_NOINLINE uint64_t bench_actual_claudaris_ratio_round_even_u32(void)
{
    uint32_t rounded = (uint32_t)0;
    const bool status = api_ptr_claudaris_ratio_round_even_u32(arg_u32[4], arg_u32[5], &rounded);
    uint64_t value = status ? UINT64_C(1) : UINT64_C(0);
    value ^= (uint64_t)rounded;
    return value;
}
static CLAUDARIS_NOINLINE uint64_t bench_baseline_claudaris_ratio_round_even_u32(void)
{
    uint32_t rounded = (uint32_t)0;
    const bool status = baseline_ptr_claudaris_ratio_round_even_u32(arg_u32[4], arg_u32[5], &rounded);
    uint64_t value = status ? UINT64_C(1) : UINT64_C(0);
    value ^= (uint64_t)rounded;
    return value;
}
static bool (* volatile api_ptr_claudaris_round_to_multiple_i32)(int32_t, int32_t, int32_t *) = &claudaris_round_to_multiple_i32;
static bool baseline_claudaris_round_to_multiple_i32(int32_t value, int32_t multiple, int32_t * rounded)
{
    (void)value;
    (void)multiple;
    *rounded = (int32_t)0;
    return true;
}
static bool (* volatile baseline_ptr_claudaris_round_to_multiple_i32)(int32_t, int32_t, int32_t *) = &baseline_claudaris_round_to_multiple_i32;
static CLAUDARIS_NOINLINE uint64_t bench_actual_claudaris_round_to_multiple_i32(void)
{
    int32_t rounded = (int32_t)0;
    const bool status = api_ptr_claudaris_round_to_multiple_i32(arg_i32[0], arg_i32[2], &rounded);
    uint64_t value = status ? UINT64_C(1) : UINT64_C(0);
    value ^= (uint64_t)rounded;
    return value;
}
static CLAUDARIS_NOINLINE uint64_t bench_baseline_claudaris_round_to_multiple_i32(void)
{
    int32_t rounded = (int32_t)0;
    const bool status = baseline_ptr_claudaris_round_to_multiple_i32(arg_i32[0], arg_i32[2], &rounded);
    uint64_t value = status ? UINT64_C(1) : UINT64_C(0);
    value ^= (uint64_t)rounded;
    return value;
}
static int64_t (* volatile api_ptr_claudaris_saturating_add_i64)(int64_t, int64_t) = &claudaris_saturating_add_i64;
static int64_t baseline_claudaris_saturating_add_i64(int64_t a, int64_t b)
{
    (void)a;
    (void)b;
    return (int64_t)0;
}
static int64_t (* volatile baseline_ptr_claudaris_saturating_add_i64)(int64_t, int64_t) = &baseline_claudaris_saturating_add_i64;
static CLAUDARIS_NOINLINE uint64_t bench_actual_claudaris_saturating_add_i64(void)
{
    const int64_t value = api_ptr_claudaris_saturating_add_i64(arg_i64[1], arg_i64[5]);
    return (uint64_t)value;
}
static CLAUDARIS_NOINLINE uint64_t bench_baseline_claudaris_saturating_add_i64(void)
{
    const int64_t value = baseline_ptr_claudaris_saturating_add_i64(arg_i64[1], arg_i64[5]);
    return (uint64_t)value;
}
static uint64_t (* volatile api_ptr_claudaris_saturating_add_u64)(uint64_t, uint64_t) = &claudaris_saturating_add_u64;
static uint64_t baseline_claudaris_saturating_add_u64(uint64_t a, uint64_t b)
{
    (void)a;
    (void)b;
    return (uint64_t)0;
}
static uint64_t (* volatile baseline_ptr_claudaris_saturating_add_u64)(uint64_t, uint64_t) = &baseline_claudaris_saturating_add_u64;
static CLAUDARIS_NOINLINE uint64_t bench_actual_claudaris_saturating_add_u64(void)
{
    const uint64_t value = api_ptr_claudaris_saturating_add_u64(arg_u64[0], arg_u64[2]);
    return (uint64_t)value;
}
static CLAUDARIS_NOINLINE uint64_t bench_baseline_claudaris_saturating_add_u64(void)
{
    const uint64_t value = baseline_ptr_claudaris_saturating_add_u64(arg_u64[0], arg_u64[2]);
    return (uint64_t)value;
}
static int32_t (* volatile api_ptr_claudaris_saturating_cast_i64_i32)(int64_t) = &claudaris_saturating_cast_i64_i32;
static int32_t baseline_claudaris_saturating_cast_i64_i32(int64_t value)
{
    (void)value;
    return (int32_t)0;
}
static int32_t (* volatile baseline_ptr_claudaris_saturating_cast_i64_i32)(int64_t) = &baseline_claudaris_saturating_cast_i64_i32;
static CLAUDARIS_NOINLINE uint64_t bench_actual_claudaris_saturating_cast_i64_i32(void)
{
    const int32_t value = api_ptr_claudaris_saturating_cast_i64_i32(arg_i64[1]);
    return (uint64_t)value;
}
static CLAUDARIS_NOINLINE uint64_t bench_baseline_claudaris_saturating_cast_i64_i32(void)
{
    const int32_t value = baseline_ptr_claudaris_saturating_cast_i64_i32(arg_i64[1]);
    return (uint64_t)value;
}
static uint32_t (* volatile api_ptr_claudaris_saturating_cast_u64_u32)(uint64_t) = &claudaris_saturating_cast_u64_u32;
static uint32_t baseline_claudaris_saturating_cast_u64_u32(uint64_t value)
{
    (void)value;
    return (uint32_t)0;
}
static uint32_t (* volatile baseline_ptr_claudaris_saturating_cast_u64_u32)(uint64_t) = &baseline_claudaris_saturating_cast_u64_u32;
static CLAUDARIS_NOINLINE uint64_t bench_actual_claudaris_saturating_cast_u64_u32(void)
{
    const uint32_t value = api_ptr_claudaris_saturating_cast_u64_u32(arg_u64[3]);
    return (uint64_t)value;
}
static CLAUDARIS_NOINLINE uint64_t bench_baseline_claudaris_saturating_cast_u64_u32(void)
{
    const uint32_t value = baseline_ptr_claudaris_saturating_cast_u64_u32(arg_u64[3]);
    return (uint64_t)value;
}
static uint64_t (* volatile api_ptr_claudaris_saturating_mul_u64)(uint64_t, uint64_t) = &claudaris_saturating_mul_u64;
static uint64_t baseline_claudaris_saturating_mul_u64(uint64_t a, uint64_t b)
{
    (void)a;
    (void)b;
    return (uint64_t)0;
}
static uint64_t (* volatile baseline_ptr_claudaris_saturating_mul_u64)(uint64_t, uint64_t) = &baseline_claudaris_saturating_mul_u64;
static CLAUDARIS_NOINLINE uint64_t bench_actual_claudaris_saturating_mul_u64(void)
{
    const uint64_t value = api_ptr_claudaris_saturating_mul_u64(arg_u64[0], arg_u64[4]);
    return (uint64_t)value;
}
static CLAUDARIS_NOINLINE uint64_t bench_baseline_claudaris_saturating_mul_u64(void)
{
    const uint64_t value = baseline_ptr_claudaris_saturating_mul_u64(arg_u64[0], arg_u64[4]);
    return (uint64_t)value;
}
static int64_t (* volatile api_ptr_claudaris_saturating_sub_i64)(int64_t, int64_t) = &claudaris_saturating_sub_i64;
static int64_t baseline_claudaris_saturating_sub_i64(int64_t a, int64_t b)
{
    (void)a;
    (void)b;
    return (int64_t)0;
}
static int64_t (* volatile baseline_ptr_claudaris_saturating_sub_i64)(int64_t, int64_t) = &baseline_claudaris_saturating_sub_i64;
static CLAUDARIS_NOINLINE uint64_t bench_actual_claudaris_saturating_sub_i64(void)
{
    const int64_t value = api_ptr_claudaris_saturating_sub_i64(arg_i64[0], arg_i64[5]);
    return (uint64_t)value;
}
static CLAUDARIS_NOINLINE uint64_t bench_baseline_claudaris_saturating_sub_i64(void)
{
    const int64_t value = baseline_ptr_claudaris_saturating_sub_i64(arg_i64[0], arg_i64[5]);
    return (uint64_t)value;
}
static uint64_t (* volatile api_ptr_claudaris_saturating_sub_u64)(uint64_t, uint64_t) = &claudaris_saturating_sub_u64;
static uint64_t baseline_claudaris_saturating_sub_u64(uint64_t a, uint64_t b)
{
    (void)a;
    (void)b;
    return (uint64_t)0;
}
static uint64_t (* volatile baseline_ptr_claudaris_saturating_sub_u64)(uint64_t, uint64_t) = &baseline_claudaris_saturating_sub_u64;
static CLAUDARIS_NOINLINE uint64_t bench_actual_claudaris_saturating_sub_u64(void)
{
    const uint64_t value = api_ptr_claudaris_saturating_sub_u64(arg_u64[1], arg_u64[2]);
    return (uint64_t)value;
}
static CLAUDARIS_NOINLINE uint64_t bench_baseline_claudaris_saturating_sub_u64(void)
{
    const uint64_t value = baseline_ptr_claudaris_saturating_sub_u64(arg_u64[1], arg_u64[2]);
    return (uint64_t)value;
}
static bool (* volatile api_ptr_claudaris_size_add_checked_u32)(uint32_t, uint32_t, uint32_t *) = &claudaris_size_add_checked_u32;
static bool baseline_claudaris_size_add_checked_u32(uint32_t a, uint32_t b, uint32_t * sum)
{
    (void)a;
    (void)b;
    *sum = (uint32_t)0;
    return true;
}
static bool (* volatile baseline_ptr_claudaris_size_add_checked_u32)(uint32_t, uint32_t, uint32_t *) = &baseline_claudaris_size_add_checked_u32;
static CLAUDARIS_NOINLINE uint64_t bench_actual_claudaris_size_add_checked_u32(void)
{
    uint32_t sum = (uint32_t)0;
    const bool status = api_ptr_claudaris_size_add_checked_u32(arg_u32[5], arg_u32[6], &sum);
    uint64_t value = status ? UINT64_C(1) : UINT64_C(0);
    value ^= (uint64_t)sum;
    return value;
}
static CLAUDARIS_NOINLINE uint64_t bench_baseline_claudaris_size_add_checked_u32(void)
{
    uint32_t sum = (uint32_t)0;
    const bool status = baseline_ptr_claudaris_size_add_checked_u32(arg_u32[5], arg_u32[6], &sum);
    uint64_t value = status ? UINT64_C(1) : UINT64_C(0);
    value ^= (uint64_t)sum;
    return value;
}
static bool (* volatile api_ptr_claudaris_size_mul_checked_u32)(uint32_t, uint32_t, uint32_t *) = &claudaris_size_mul_checked_u32;
static bool baseline_claudaris_size_mul_checked_u32(uint32_t a, uint32_t b, uint32_t * product)
{
    (void)a;
    (void)b;
    *product = (uint32_t)0;
    return true;
}
static bool (* volatile baseline_ptr_claudaris_size_mul_checked_u32)(uint32_t, uint32_t, uint32_t *) = &baseline_claudaris_size_mul_checked_u32;
static CLAUDARIS_NOINLINE uint64_t bench_actual_claudaris_size_mul_checked_u32(void)
{
    uint32_t product = (uint32_t)0;
    const bool status = api_ptr_claudaris_size_mul_checked_u32(arg_u32[6], arg_u32[7], &product);
    uint64_t value = status ? UINT64_C(1) : UINT64_C(0);
    value ^= (uint64_t)product;
    return value;
}
static CLAUDARIS_NOINLINE uint64_t bench_baseline_claudaris_size_mul_checked_u32(void)
{
    uint32_t product = (uint32_t)0;
    const bool status = baseline_ptr_claudaris_size_mul_checked_u32(arg_u32[6], arg_u32[7], &product);
    uint64_t value = status ? UINT64_C(1) : UINT64_C(0);
    value ^= (uint64_t)product;
    return value;
}
static bool (* volatile api_ptr_claudaris_time_convert_ceil_u64)(uint64_t, uint64_t, uint64_t, uint64_t *) = &claudaris_time_convert_ceil_u64;
static bool baseline_claudaris_time_convert_ceil_u64(uint64_t value, uint64_t numerator, uint64_t denominator, uint64_t * result)
{
    (void)value;
    (void)numerator;
    (void)denominator;
    *result = (uint64_t)0;
    return true;
}
static bool (* volatile baseline_ptr_claudaris_time_convert_ceil_u64)(uint64_t, uint64_t, uint64_t, uint64_t *) = &baseline_claudaris_time_convert_ceil_u64;
static CLAUDARIS_NOINLINE uint64_t bench_actual_claudaris_time_convert_ceil_u64(void)
{
    uint64_t result = (uint64_t)0;
    const bool status = api_ptr_claudaris_time_convert_ceil_u64(arg_u64[5], arg_u64[2], arg_u64[6], &result);
    uint64_t checksum = status ? UINT64_C(1) : UINT64_C(0);
    checksum ^= (uint64_t)result;
    return checksum;
}
static CLAUDARIS_NOINLINE uint64_t bench_baseline_claudaris_time_convert_ceil_u64(void)
{
    uint64_t result = (uint64_t)0;
    const bool status = baseline_ptr_claudaris_time_convert_ceil_u64(arg_u64[5], arg_u64[2], arg_u64[6], &result);
    uint64_t checksum = status ? UINT64_C(1) : UINT64_C(0);
    checksum ^= (uint64_t)result;
    return checksum;
}
static bool (* volatile api_ptr_claudaris_time_convert_floor_u64)(uint64_t, uint64_t, uint64_t, uint64_t *) = &claudaris_time_convert_floor_u64;
static bool baseline_claudaris_time_convert_floor_u64(uint64_t value, uint64_t numerator, uint64_t denominator, uint64_t * result)
{
    (void)value;
    (void)numerator;
    (void)denominator;
    *result = (uint64_t)0;
    return true;
}
static bool (* volatile baseline_ptr_claudaris_time_convert_floor_u64)(uint64_t, uint64_t, uint64_t, uint64_t *) = &baseline_claudaris_time_convert_floor_u64;
static CLAUDARIS_NOINLINE uint64_t bench_actual_claudaris_time_convert_floor_u64(void)
{
    uint64_t result = (uint64_t)0;
    const bool status = api_ptr_claudaris_time_convert_floor_u64(arg_u64[5], arg_u64[2], arg_u64[6], &result);
    uint64_t checksum = status ? UINT64_C(1) : UINT64_C(0);
    checksum ^= (uint64_t)result;
    return checksum;
}
static CLAUDARIS_NOINLINE uint64_t bench_baseline_claudaris_time_convert_floor_u64(void)
{
    uint64_t result = (uint64_t)0;
    const bool status = baseline_ptr_claudaris_time_convert_floor_u64(arg_u64[5], arg_u64[2], arg_u64[6], &result);
    uint64_t checksum = status ? UINT64_C(1) : UINT64_C(0);
    checksum ^= (uint64_t)result;
    return checksum;
}
static uint64_t (* volatile api_ptr_claudaris_time_duration_absdiff_u64)(uint64_t, uint64_t) = &claudaris_time_duration_absdiff_u64;
static uint64_t baseline_claudaris_time_duration_absdiff_u64(uint64_t a, uint64_t b)
{
    (void)a;
    (void)b;
    return (uint64_t)0;
}
static uint64_t (* volatile baseline_ptr_claudaris_time_duration_absdiff_u64)(uint64_t, uint64_t) = &baseline_claudaris_time_duration_absdiff_u64;
static CLAUDARIS_NOINLINE uint64_t bench_actual_claudaris_time_duration_absdiff_u64(void)
{
    const uint64_t value = api_ptr_claudaris_time_duration_absdiff_u64(arg_u64[0], arg_u64[1]);
    return (uint64_t)value;
}
static CLAUDARIS_NOINLINE uint64_t bench_baseline_claudaris_time_duration_absdiff_u64(void)
{
    const uint64_t value = baseline_ptr_claudaris_time_duration_absdiff_u64(arg_u64[0], arg_u64[1]);
    return (uint64_t)value;
}
static bool (* volatile api_ptr_claudaris_time_duration_clamp_u64)(uint64_t, uint64_t, uint64_t, uint64_t *) = &claudaris_time_duration_clamp_u64;
static bool baseline_claudaris_time_duration_clamp_u64(uint64_t duration, uint64_t lower, uint64_t upper, uint64_t * result)
{
    (void)duration;
    (void)lower;
    (void)upper;
    *result = (uint64_t)0;
    return true;
}
static bool (* volatile baseline_ptr_claudaris_time_duration_clamp_u64)(uint64_t, uint64_t, uint64_t, uint64_t *) = &baseline_claudaris_time_duration_clamp_u64;
static CLAUDARIS_NOINLINE uint64_t bench_actual_claudaris_time_duration_clamp_u64(void)
{
    uint64_t result = (uint64_t)0;
    const bool status = api_ptr_claudaris_time_duration_clamp_u64(arg_u64[7], arg_u64[8], arg_u64[9], &result);
    uint64_t checksum = status ? UINT64_C(1) : UINT64_C(0);
    checksum ^= (uint64_t)result;
    return checksum;
}
static CLAUDARIS_NOINLINE uint64_t bench_baseline_claudaris_time_duration_clamp_u64(void)
{
    uint64_t result = (uint64_t)0;
    const bool status = baseline_ptr_claudaris_time_duration_clamp_u64(arg_u64[7], arg_u64[8], arg_u64[9], &result);
    uint64_t checksum = status ? UINT64_C(1) : UINT64_C(0);
    checksum ^= (uint64_t)result;
    return checksum;
}
static bool (* volatile api_ptr_claudaris_time_scale_ratio_u64)(uint64_t, uint64_t, uint64_t, uint64_t *) = &claudaris_time_scale_ratio_u64;
static bool baseline_claudaris_time_scale_ratio_u64(uint64_t value, uint64_t numerator, uint64_t denominator, uint64_t * result)
{
    (void)value;
    (void)numerator;
    (void)denominator;
    *result = (uint64_t)0;
    return true;
}
static bool (* volatile baseline_ptr_claudaris_time_scale_ratio_u64)(uint64_t, uint64_t, uint64_t, uint64_t *) = &baseline_claudaris_time_scale_ratio_u64;
static CLAUDARIS_NOINLINE uint64_t bench_actual_claudaris_time_scale_ratio_u64(void)
{
    uint64_t result = (uint64_t)0;
    const bool status = api_ptr_claudaris_time_scale_ratio_u64(arg_u64[5], arg_u64[2], arg_u64[6], &result);
    uint64_t checksum = status ? UINT64_C(1) : UINT64_C(0);
    checksum ^= (uint64_t)result;
    return checksum;
}
static CLAUDARIS_NOINLINE uint64_t bench_baseline_claudaris_time_scale_ratio_u64(void)
{
    uint64_t result = (uint64_t)0;
    const bool status = baseline_ptr_claudaris_time_scale_ratio_u64(arg_u64[5], arg_u64[2], arg_u64[6], &result);
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
    bench_actual_claudaris_abs_diff_i64_u64,
    bench_actual_claudaris_abs_i64_safe_u64,
    bench_actual_claudaris_accumulate_abs_i32,
    bench_actual_claudaris_align_down_u32,
    bench_actual_claudaris_align_up_u32,
    bench_actual_claudaris_ceil_to_multiple_i32,
    bench_actual_claudaris_checked_abs_i64,
    bench_actual_claudaris_checked_add_i64,
    bench_actual_claudaris_checked_add_u64,
    bench_actual_claudaris_checked_mul_i64,
    bench_actual_claudaris_checked_mul_u64,
    bench_actual_claudaris_checked_neg_i64,
    bench_actual_claudaris_checked_shl_i32,
    bench_actual_claudaris_checked_shl_u32,
    bench_actual_claudaris_checked_sub_i64,
    bench_actual_claudaris_checked_sub_u64,
    bench_actual_claudaris_floor_to_multiple_i32,
    bench_actual_claudaris_fraction_compare_i32,
    bench_actual_claudaris_is_aligned_u32,
    bench_actual_claudaris_lookup_clamped_i32,
    bench_actual_claudaris_mask_range_u64,
    bench_actual_claudaris_nearest_multiple_u32,
    bench_actual_claudaris_offset_range_check_u32,
    bench_actual_claudaris_period_align_u32,
    bench_actual_claudaris_period_floor_u32,
    bench_actual_claudaris_range_center_i32,
    bench_actual_claudaris_range_intersects_i32,
    bench_actual_claudaris_range_shrink_i32,
    bench_actual_claudaris_ratio_between_u32,
    bench_actual_claudaris_ratio_ceil_u32,
    bench_actual_claudaris_ratio_round_even_u32,
    bench_actual_claudaris_round_to_multiple_i32,
    bench_actual_claudaris_saturating_add_i64,
    bench_actual_claudaris_saturating_add_u64,
    bench_actual_claudaris_saturating_cast_i64_i32,
    bench_actual_claudaris_saturating_cast_u64_u32,
    bench_actual_claudaris_saturating_mul_u64,
    bench_actual_claudaris_saturating_sub_i64,
    bench_actual_claudaris_saturating_sub_u64,
    bench_actual_claudaris_size_add_checked_u32,
    bench_actual_claudaris_size_mul_checked_u32,
    bench_actual_claudaris_time_convert_ceil_u64,
    bench_actual_claudaris_time_convert_floor_u64,
    bench_actual_claudaris_time_duration_absdiff_u64,
    bench_actual_claudaris_time_duration_clamp_u64,
    bench_actual_claudaris_time_scale_ratio_u64,
};
static bench_fn_t const baseline_bench[46] = {
    bench_baseline_claudaris_abs_diff_i64_u64,
    bench_baseline_claudaris_abs_i64_safe_u64,
    bench_baseline_claudaris_accumulate_abs_i32,
    bench_baseline_claudaris_align_down_u32,
    bench_baseline_claudaris_align_up_u32,
    bench_baseline_claudaris_ceil_to_multiple_i32,
    bench_baseline_claudaris_checked_abs_i64,
    bench_baseline_claudaris_checked_add_i64,
    bench_baseline_claudaris_checked_add_u64,
    bench_baseline_claudaris_checked_mul_i64,
    bench_baseline_claudaris_checked_mul_u64,
    bench_baseline_claudaris_checked_neg_i64,
    bench_baseline_claudaris_checked_shl_i32,
    bench_baseline_claudaris_checked_shl_u32,
    bench_baseline_claudaris_checked_sub_i64,
    bench_baseline_claudaris_checked_sub_u64,
    bench_baseline_claudaris_floor_to_multiple_i32,
    bench_baseline_claudaris_fraction_compare_i32,
    bench_baseline_claudaris_is_aligned_u32,
    bench_baseline_claudaris_lookup_clamped_i32,
    bench_baseline_claudaris_mask_range_u64,
    bench_baseline_claudaris_nearest_multiple_u32,
    bench_baseline_claudaris_offset_range_check_u32,
    bench_baseline_claudaris_period_align_u32,
    bench_baseline_claudaris_period_floor_u32,
    bench_baseline_claudaris_range_center_i32,
    bench_baseline_claudaris_range_intersects_i32,
    bench_baseline_claudaris_range_shrink_i32,
    bench_baseline_claudaris_ratio_between_u32,
    bench_baseline_claudaris_ratio_ceil_u32,
    bench_baseline_claudaris_ratio_round_even_u32,
    bench_baseline_claudaris_round_to_multiple_i32,
    bench_baseline_claudaris_saturating_add_i64,
    bench_baseline_claudaris_saturating_add_u64,
    bench_baseline_claudaris_saturating_cast_i64_i32,
    bench_baseline_claudaris_saturating_cast_u64_u32,
    bench_baseline_claudaris_saturating_mul_u64,
    bench_baseline_claudaris_saturating_sub_i64,
    bench_baseline_claudaris_saturating_sub_u64,
    bench_baseline_claudaris_size_add_checked_u32,
    bench_baseline_claudaris_size_mul_checked_u32,
    bench_baseline_claudaris_time_convert_ceil_u64,
    bench_baseline_claudaris_time_convert_floor_u64,
    bench_baseline_claudaris_time_duration_absdiff_u64,
    bench_baseline_claudaris_time_duration_clamp_u64,
    bench_baseline_claudaris_time_scale_ratio_u64,
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
    RUN_API(1u, claudaris_abs_diff_i64_u64(INT64_MIN, INT64_MAX) == UINT64_MAX); /* claudaris_abs_diff_i64_u64 */
    RUN_API(2u, claudaris_abs_i64_safe_u64(INT64_MIN) == (UINT64_C(1) << 63)); /* claudaris_abs_i64_safe_u64 */
    RUN_API(3u, (u64 = 0u, claudaris_accumulate_abs_i32(-5, &u64) && u64 == 5u)); /* claudaris_accumulate_abs_i32 */
    RUN_API(4u, claudaris_align_down_u32(17u, 8u, &u32) && u32 == 16u); /* claudaris_align_down_u32 */
    RUN_API(5u, claudaris_align_up_u32(17u, 8u, &u32) && u32 == 24u); /* claudaris_align_up_u32 */
    RUN_API(6u, claudaris_ceil_to_multiple_i32(-5, 2, &i32) && i32 == -4); /* claudaris_ceil_to_multiple_i32 */
    RUN_API(7u, claudaris_checked_abs_i64(-7, &i64) && i64 == 7); /* claudaris_checked_abs_i64 */
    RUN_API(8u, claudaris_checked_add_i64(INT64_MAX, 0, &i64) && i64 == INT64_MAX); /* claudaris_checked_add_i64 */
    RUN_API(9u, claudaris_checked_add_u64(UINT64_MAX, 0u, &u64) && u64 == UINT64_MAX); /* claudaris_checked_add_u64 */
    RUN_API(10u, claudaris_checked_mul_i64(-7, 9, &i64) && i64 == -63); /* claudaris_checked_mul_i64 */
    RUN_API(11u, claudaris_checked_mul_u64(UINT64_MAX, 1u, &u64) && u64 == UINT64_MAX); /* claudaris_checked_mul_u64 */
    RUN_API(12u, claudaris_checked_neg_i64(-9, &i64) && i64 == 9); /* claudaris_checked_neg_i64 */
    RUN_API(13u, claudaris_checked_shl_i32(-3, 4u, &i32) && i32 == -48); /* claudaris_checked_shl_i32 */
    RUN_API(14u, claudaris_checked_shl_u32(1u, 31u, &u32) && u32 == UINT32_C(0x80000000)); /* claudaris_checked_shl_u32 */
    RUN_API(15u, claudaris_checked_sub_i64(INT64_MIN, 0, &i64) && i64 == INT64_MIN); /* claudaris_checked_sub_i64 */
    RUN_API(16u, claudaris_checked_sub_u64(UINT64_MAX, 0u, &u64) && u64 == UINT64_MAX); /* claudaris_checked_sub_u64 */
    RUN_API(17u, claudaris_floor_to_multiple_i32(-5, 2, &i32) && i32 == -6); /* claudaris_floor_to_multiple_i32 */
    RUN_API(18u, claudaris_fraction_compare_i32(-1, 2, 1, 3, &cmp) && cmp == -1); /* claudaris_fraction_compare_i32 */
    RUN_API(19u, claudaris_is_aligned_u32(21u, 7u)); /* claudaris_is_aligned_u32 */
    RUN_API(20u, claudaris_lookup_clamped_i32(table, 3u, 1, &i32) && i32 == 5); /* claudaris_lookup_clamped_i32 */
    RUN_API(21u, claudaris_mask_range_u64(1u, 3u, &u64) && u64 == UINT64_C(14)); /* claudaris_mask_range_u64 */
    RUN_API(22u, claudaris_nearest_multiple_u32(5u, 2u, &u32) && u32 == 4u); /* claudaris_nearest_multiple_u32 */
    RUN_API(23u, claudaris_offset_range_check_u32(3u, 4u, 7u)); /* claudaris_offset_range_check_u32 */
    RUN_API(24u, claudaris_period_align_u32(12u, 0u, 5u, &u32) && u32 == 15u); /* claudaris_period_align_u32 */
    RUN_API(25u, claudaris_period_floor_u32(12u, 0u, 5u, &u32) && u32 == 10u); /* claudaris_period_floor_u32 */
    RUN_API(26u, claudaris_range_center_i32(-3, 2, &i32) && i32 == -1); /* claudaris_range_center_i32 */
    RUN_API(27u, claudaris_range_intersects_i32(1, 3, 3, 5)); /* claudaris_range_intersects_i32 */
    RUN_API(28u, claudaris_range_shrink_i32(0, 10, 2u, &lo, &hi) && lo == 2 && hi == 8); /* claudaris_range_shrink_i32 */
    RUN_API(29u, claudaris_ratio_between_u32(1u, 2u, 1u, 3u, 2u, 3u, &flag) && flag); /* claudaris_ratio_between_u32 */
    RUN_API(30u, claudaris_ratio_ceil_u32(10u, 3u, &u32) && u32 == 4u); /* claudaris_ratio_ceil_u32 */
    RUN_API(31u, claudaris_ratio_round_even_u32(5u, 2u, &u32) && u32 == 2u); /* claudaris_ratio_round_even_u32 */
    RUN_API(32u, claudaris_round_to_multiple_i32(-5, 2, &i32) && i32 == -4); /* claudaris_round_to_multiple_i32 */
    RUN_API(33u, claudaris_saturating_add_i64(INT64_MAX, 1) == INT64_MAX); /* claudaris_saturating_add_i64 */
    RUN_API(34u, claudaris_saturating_add_u64(UINT64_MAX, 1u) == UINT64_MAX); /* claudaris_saturating_add_u64 */
    RUN_API(35u, claudaris_saturating_cast_i64_i32((int64_t)INT32_MAX + 1) == INT32_MAX); /* claudaris_saturating_cast_i64_i32 */
    RUN_API(36u, claudaris_saturating_cast_u64_u32((uint64_t)UINT32_MAX + 1u) == UINT32_MAX); /* claudaris_saturating_cast_u64_u32 */
    RUN_API(37u, claudaris_saturating_mul_u64(UINT64_MAX, 2u) == UINT64_MAX); /* claudaris_saturating_mul_u64 */
    RUN_API(38u, claudaris_saturating_sub_i64(INT64_MIN, 1) == INT64_MIN); /* claudaris_saturating_sub_i64 */
    RUN_API(39u, claudaris_saturating_sub_u64(0u, 1u) == 0u); /* claudaris_saturating_sub_u64 */
    RUN_API(40u, claudaris_size_add_checked_u32(2u, 3u, &u32) && u32 == 5u); /* claudaris_size_add_checked_u32 */
    RUN_API(41u, claudaris_size_mul_checked_u32(3u, 4u, &u32) && u32 == 12u); /* claudaris_size_mul_checked_u32 */
    RUN_API(42u, claudaris_time_convert_ceil_u64(3u, 1u, 2u, &u64) && u64 == 2u); /* claudaris_time_convert_ceil_u64 */
    RUN_API(43u, claudaris_time_convert_floor_u64(3u, 1u, 2u, &u64) && u64 == 1u); /* claudaris_time_convert_floor_u64 */
    RUN_API(44u, claudaris_time_duration_absdiff_u64(UINT64_MAX, 0u) == UINT64_MAX); /* claudaris_time_duration_absdiff_u64 */
    RUN_API(45u, claudaris_time_duration_clamp_u64(5u, 10u, 20u, &u64) && u64 == 10u); /* claudaris_time_duration_clamp_u64 */
    RUN_API(46u, claudaris_time_scale_ratio_u64(5u, 1u, 2u, &u64) && u64 == 2u); /* claudaris_time_scale_ratio_u64 */
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
