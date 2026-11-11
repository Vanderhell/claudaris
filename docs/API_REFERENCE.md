# Claudaris API reference

The public API contains **46 callable functions** in 46 public headers. The private time-ratio helper is in `src/pc_time_ratio_internal.h` and is not part of the public API. The header declaration is authoritative for exact types and semantics.

Every public function below has an enabled direct test. The listed test files invoke the symbol directly; `test_042_uncovered_api_audit.c` adds seeded arithmetic differential checks and `test_043_time_ratio_differential.c` checks time conversions against widened exact arithmetic where supported.

## `pc_abs_diff_i64_u64`

**Header:** `include/claudaris/arithmetic/pc_abs_diff_i64_u64.h`
**Implementation:** `src/pc_abs_diff_i64_u64.c`
**Prototype:** `uint64_t pc_abs_diff_i64_u64(int64_t a, int64_t b);`

**Contract:** Return exact |a-b| as uint64 for any signed int64 inputs.

**Direct tests:** `tests/test_042_uncovered_api_audit.c`

## `pc_abs_i64_safe_u64`

**Header:** `include/claudaris/arithmetic/pc_abs_i64_safe_u64.h`
**Implementation:** `src/pc_abs_i64_safe_u64.c`
**Prototype:** `uint64_t pc_abs_i64_safe_u64(int64_t value);`

**Contract:** Return the exact unsigned magnitude of any int64, including INT64_MIN.

**Direct tests:** `tests/test_042_uncovered_api_audit.c`

## `pc_accumulate_abs_i32`

**Header:** `include/claudaris/arithmetic/pc_accumulate_abs_i32.h`
**Implementation:** `src/pc_accumulate_abs_i32.c`
**Prototype:** `bool pc_accumulate_abs_i32(int32_t value, uint64_t *accumulator);`

**Contract:** Add the exact magnitude of value to accumulator; overflow leaves it unchanged.

**Direct tests:** `tests/test_007_accumulate_abs_i32.c`

## `pc_align_down_u32`

**Header:** `include/claudaris/arithmetic/pc_align_down_u32.h`
**Implementation:** `src/pc_align_down_u32.c`
**Prototype:** `bool pc_align_down_u32(uint32_t value, uint32_t alignment, uint32_t *aligned);`

**Contract:** Round value down to a multiple of any positive alignment.

**Direct tests:** `tests/test_008_align_down_u32.c`

## `pc_align_up_u32`

**Header:** `include/claudaris/arithmetic/pc_align_up_u32.h`
**Implementation:** `src/pc_align_up_u32.c`
**Prototype:** `bool pc_align_up_u32(uint32_t value, uint32_t alignment, uint32_t *aligned);`

**Contract:** Round value up to a multiple of any positive alignment.

**Direct tests:** `tests/test_009_align_up_u32.c`

## `pc_ceil_to_multiple_i32`

**Header:** `include/claudaris/arithmetic/pc_ceil_to_multiple_i32.h`
**Implementation:** `src/pc_ceil_to_multiple_i32.c`
**Prototype:** `bool pc_ceil_to_multiple_i32(int32_t value, int32_t multiple, int32_t *rounded);`

**Contract:** Ceiling to a positive multiple; false on invalid step or result overflow.

**Direct tests:** `tests/test_010_ceil_to_multiple_i32.c`

## `pc_checked_abs_i64`

**Header:** `include/claudaris/arithmetic/pc_checked_abs_i64.h`
**Implementation:** `src/pc_checked_abs_i64.c`
**Prototype:** `bool pc_checked_abs_i64(int64_t value, int64_t *result);`

**Contract:** Store |value| in result. Return false if result is null or the result is not representable (value == INT64_MIN); on failure, do not write output.

**Direct tests:** `tests/test_013_checked_abs_i64.c`

## `pc_checked_add_i64`

**Header:** `include/claudaris/arithmetic/pc_checked_add_i64.h`
**Implementation:** `src/pc_checked_add_i64.c`
**Prototype:** `bool pc_checked_add_i64(int64_t a, int64_t b, int64_t *result);`

**Contract:** Store a+b exactly. False for null output or signed overflow; failure writes nothing to result.

**Direct tests:** `tests/test_014_checked_add_i64.c`, `tests/test_042_uncovered_api_audit.c`

## `pc_checked_add_u64`

**Header:** `include/claudaris/arithmetic/pc_checked_add_u64.h`
**Implementation:** `src/pc_checked_add_u64.c`
**Prototype:** `bool pc_checked_add_u64(uint64_t a, uint64_t b, uint64_t *result);`

**Contract:** Store a+b exactly. False for null output or overflow; failure is atomic.

**Direct tests:** `tests/test_042_uncovered_api_audit.c`

## `pc_checked_mul_i64`

**Header:** `include/claudaris/arithmetic/pc_checked_mul_i64.h`
**Implementation:** `src/pc_checked_mul_i64.c`
**Prototype:** `bool pc_checked_mul_i64(int64_t a, int64_t b, int64_t *result);`

**Contract:** Store a b exactly. False on signed overflow or null output; failure leaves output unchanged.

**Direct tests:** `tests/test_015_checked_mul_i64.c`, `tests/test_042_uncovered_api_audit.c`

## `pc_checked_mul_u64`

**Header:** `include/claudaris/arithmetic/pc_checked_mul_u64.h`
**Implementation:** `src/pc_checked_mul_u64.c`
**Prototype:** `bool pc_checked_mul_u64(uint64_t a, uint64_t b, uint64_t *result);`

**Contract:** Store a b exactly. False for null output or overflow; failure is atomic.

**Direct tests:** `tests/test_042_uncovered_api_audit.c`

## `pc_checked_neg_i64`

**Header:** `include/claudaris/arithmetic/pc_checked_neg_i64.h`
**Implementation:** `src/pc_checked_neg_i64.c`
**Prototype:** `bool pc_checked_neg_i64(int64_t value, int64_t *result);`

**Contract:** Store -value exactly; false for null output or INT64_MIN, preserving output.

**Direct tests:** `tests/test_016_checked_neg_i64.c`

## `pc_checked_shl_i32`

**Header:** `include/claudaris/arithmetic/pc_checked_shl_i32.h`
**Implementation:** `src/pc_checked_shl_i32.c`
**Prototype:** `bool pc_checked_shl_i32(int32_t value, unsigned shift, int32_t *result);`

**Contract:** Store value 2^shift exactly. False for shift >= 32, int32_t overflow, or null output; failure leaves output unchanged.

**Direct tests:** `tests/test_017_checked_shl_i32.c`, `tests/test_042_uncovered_api_audit.c`

## `pc_checked_shl_u32`

**Header:** `include/claudaris/arithmetic/pc_checked_shl_u32.h`
**Implementation:** `src/pc_checked_shl_u32.c`
**Prototype:** `bool pc_checked_shl_u32(uint32_t value, unsigned shift, uint32_t *result);`

**Contract:** Exact uint32_t left shift. False for shift >= 32, discarded high bits, or null output; on failure output is unchanged.

**Direct tests:** `tests/test_018_checked_shl_u32.c`, `tests/test_042_uncovered_api_audit.c`

## `pc_checked_sub_i64`

**Header:** `include/claudaris/arithmetic/pc_checked_sub_i64.h`
**Implementation:** `src/pc_checked_sub_i64.c`
**Prototype:** `bool pc_checked_sub_i64(int64_t a, int64_t b, int64_t *result);`

**Contract:** Store a-b exactly. False for null output or signed overflow; failure writes nothing to result.

**Direct tests:** `tests/test_019_checked_sub_i64.c`, `tests/test_042_uncovered_api_audit.c`

## `pc_checked_sub_u64`

**Header:** `include/claudaris/arithmetic/pc_checked_sub_u64.h`
**Implementation:** `src/pc_checked_sub_u64.c`
**Prototype:** `bool pc_checked_sub_u64(uint64_t a, uint64_t b, uint64_t *result);`

**Contract:** Store a-b exactly. False for null output or underflow; failure is atomic.

**Direct tests:** `tests/test_042_uncovered_api_audit.c`

## `pc_floor_to_multiple_i32`

**Header:** `include/claudaris/arithmetic/pc_floor_to_multiple_i32.h`
**Implementation:** `src/pc_floor_to_multiple_i32.c`
**Prototype:** `bool pc_floor_to_multiple_i32(int32_t value, int32_t multiple, int32_t *rounded);`

**Contract:** Floor to a positive multiple; false on invalid step or result overflow.

**Direct tests:** `tests/test_011_floor_to_multiple_i32.c`

## `pc_fraction_compare_i32`

**Header:** `include/claudaris/arithmetic/pc_fraction_compare_i32.h`
**Implementation:** `src/pc_fraction_compare_i32.c`
**Prototype:** `bool pc_fraction_compare_i32(int32_t a_num, int32_t a_den, int32_t b_num, int32_t b_den, int *comparison);`

**Contract:** Compare exact fractions; writes -1, 0, or 1. Zero denominator fails.

**Direct tests:** `tests/test_012_fraction_compare_i32.c`

## `pc_is_aligned_u32`

**Header:** `include/claudaris/arithmetic/pc_is_aligned_u32.h`
**Implementation:** `src/pc_is_aligned_u32.c`
**Prototype:** `bool pc_is_aligned_u32(uint32_t value, uint32_t alignment);`

**Contract:** Return whether value is divisible by a positive alignment; zero is false.

**Direct tests:** `tests/test_020_is_aligned_u32.c`

## `pc_lookup_clamped_i32`

**Header:** `include/claudaris/arithmetic/pc_lookup_clamped_i32.h`
**Implementation:** `src/pc_lookup_clamped_i32.c`
**Prototype:** `bool pc_lookup_clamped_i32(const int32_t *table, size_t count, int32_t index, int32_t *value);`

**Contract:** Return table[clamp(index, 0, count-1)]; invalid arguments leave value unchanged. table must reference count readable elements.

**Direct tests:** `tests/test_021_lookup_clamped_i32.c`

## `pc_mask_range_u64`

**Header:** `include/claudaris/arithmetic/pc_mask_range_u64.h`
**Implementation:** `src/pc_mask_range_u64.c`
**Prototype:** `bool pc_mask_range_u64(uint8_t first_bit, uint8_t last_bit, uint64_t *mask);`

**Contract:** Build a mask for inclusive LSB-zero interval [first_bit,last_bit].

**Direct tests:** `tests/test_042_uncovered_api_audit.c`

## `pc_nearest_multiple_u32`

**Header:** `include/claudaris/arithmetic/pc_nearest_multiple_u32.h`
**Implementation:** `src/pc_nearest_multiple_u32.c`
**Prototype:** `bool pc_nearest_multiple_u32(uint32_t value, uint32_t multiple, uint32_t *rounded);`

**Contract:** Round to nearest positive multiple; exact ties choose the even multiple index.

**Direct tests:** `tests/test_001_nearest_multiple_u32.c`, `tests/test_022_nearest_multiple_u32.c`

## `pc_offset_range_check_u32`

**Header:** `include/claudaris/arithmetic/pc_offset_range_check_u32.h`
**Implementation:** `src/pc_offset_range_check_u32.c`
**Prototype:** `bool pc_offset_range_check_u32(uint32_t offset, uint32_t length, uint32_t capacity);`

**Contract:** Check the half-open span [offset, offset + length) against capacity. An empty span at offset == capacity is valid.

**Direct tests:** `tests/test_023_offset_range_check_u32.c`

## `pc_period_align_u32`

**Header:** `include/claudaris/arithmetic/pc_period_align_u32.h`
**Implementation:** `src/pc_period_align_u32.c`
**Prototype:** `bool pc_period_align_u32(uint32_t time, uint32_t origin, uint32_t period, uint32_t *aligned);`

**Contract:** First origin + k period at or after time; false on invalid input/overflow.

**Direct tests:** `tests/test_024_period_align_u32.c`

## `pc_period_floor_u32`

**Header:** `include/claudaris/arithmetic/pc_period_floor_u32.h`
**Implementation:** `src/pc_period_floor_u32.c`
**Prototype:** `bool pc_period_floor_u32(uint32_t time, uint32_t origin, uint32_t period, uint32_t *aligned);`

**Contract:** Greatest origin + k period <= time for k>=0; false when none exists.

**Direct tests:** `tests/test_025_period_floor_u32.c`

## `pc_range_center_i32`

**Header:** `include/claudaris/arithmetic/pc_range_center_i32.h`
**Implementation:** `src/pc_range_center_i32.c`
**Prototype:** `bool pc_range_center_i32(int32_t lower, int32_t upper, int32_t *center);`

**Contract:** Return lower midpoint: lower + floor((upper-lower)/2).

**Direct tests:** `tests/test_026_range_center_i32.c`

## `pc_range_intersects_i32`

**Header:** `include/claudaris/arithmetic/pc_range_intersects_i32.h`
**Implementation:** `src/pc_range_intersects_i32.c`
**Prototype:** `bool pc_range_intersects_i32(int32_t a_lower, int32_t a_upper, int32_t b_lower, int32_t b_upper);`

**Contract:** Closed interval intersection; either inverted interval yields false.

**Direct tests:** `tests/test_027_range_intersects_i32.c`

## `pc_range_shrink_i32`

**Header:** `include/claudaris/arithmetic/pc_range_shrink_i32.h`
**Implementation:** `src/pc_range_shrink_i32.c`
**Prototype:** `bool pc_range_shrink_i32(int32_t lower, int32_t upper, uint32_t amount, int32_t *shrunk_lower, int32_t *shrunk_upper);`

**Contract:** Symmetrically shrink a closed range; crossing endpoints fails.

**Direct tests:** `tests/test_028_range_shrink_i32.c`

## `pc_ratio_between_u32`

**Header:** `include/claudaris/arithmetic/pc_ratio_between_u32.h`
**Implementation:** `src/pc_ratio_between_u32.c`
**Prototype:** `bool pc_ratio_between_u32(uint32_t numerator, uint32_t denominator, uint32_t lower_num, uint32_t lower_den, uint32_t upper_num, uint32_t upper_den, bool *is_between);`

**Contract:** Test inclusive ratio bounds. Invalid/zero denominators return false status.

**Direct tests:** `tests/test_029_ratio_between_u32.c`, `tests/test_042_uncovered_api_audit.c`

## `pc_ratio_ceil_u32`

**Header:** `include/claudaris/arithmetic/pc_ratio_ceil_u32.h`
**Implementation:** `src/pc_ratio_ceil_u32.c`
**Prototype:** `bool pc_ratio_ceil_u32(uint32_t numerator, uint32_t denominator, uint32_t *quotient);`

**Contract:** Return ceil(numerator/denominator). Zero denominator fails unchanged.

**Direct tests:** `tests/test_030_ratio_ceil_u32.c`, `tests/test_042_uncovered_api_audit.c`

## `pc_ratio_round_even_u32`

**Header:** `include/claudaris/arithmetic/pc_ratio_round_even_u32.h`
**Implementation:** `src/pc_ratio_round_even_u32.c`
**Prototype:** `bool pc_ratio_round_even_u32(uint32_t numerator, uint32_t denominator, uint32_t *rounded);`

**Contract:** Round numerator/denominator to nearest integer, ties to even.

**Direct tests:** `tests/test_031_ratio_round_even_u32.c`, `tests/test_042_uncovered_api_audit.c`

## `pc_round_to_multiple_i32`

**Header:** `include/claudaris/arithmetic/pc_round_to_multiple_i32.h`
**Implementation:** `src/pc_round_to_multiple_i32.c`
**Prototype:** `bool pc_round_to_multiple_i32(int32_t value, int32_t multiple, int32_t *rounded);`

**Contract:** Nearest positive multiple, ties to even; false on invalid step/overflow.

**Direct tests:** `tests/test_032_round_to_multiple_i32.c`

## `pc_saturating_add_i64`

**Header:** `include/claudaris/arithmetic/pc_saturating_add_i64.h`
**Implementation:** `src/pc_saturating_add_i64.c`
**Prototype:** `int64_t pc_saturating_add_i64(int64_t a, int64_t b);`

**Contract:** Return a+b clipped to INT64_MIN..INT64_MAX without signed overflow.

**Direct tests:** `tests/test_042_uncovered_api_audit.c`

## `pc_saturating_add_u64`

**Header:** `include/claudaris/arithmetic/pc_saturating_add_u64.h`
**Implementation:** `src/pc_saturating_add_u64.c`
**Prototype:** `uint64_t pc_saturating_add_u64(uint64_t a, uint64_t b);`

**Contract:** Return min(a+b, UINT64_MAX) without wrapping.

**Direct tests:** `tests/test_042_uncovered_api_audit.c`

## `pc_saturating_cast_i64_i32`

**Header:** `include/claudaris/arithmetic/pc_saturating_cast_i64_i32.h`
**Implementation:** `src/pc_saturating_cast_i64_i32.c`
**Prototype:** `int32_t pc_saturating_cast_i64_i32(int64_t value);`

**Contract:** Clamp value to the int32_t range and return it.

**Direct tests:** `tests/test_033_saturating_cast_i64_i32.c`

## `pc_saturating_cast_u64_u32`

**Header:** `include/claudaris/arithmetic/pc_saturating_cast_u64_u32.h`
**Implementation:** `src/pc_saturating_cast_u64_u32.c`
**Prototype:** `uint32_t pc_saturating_cast_u64_u32(uint64_t value);`

**Contract:** Clamp value to UINT32_MAX and return it.

**Direct tests:** `tests/test_034_saturating_cast_u64_u32.c`

## `pc_saturating_mul_u64`

**Header:** `include/claudaris/arithmetic/pc_saturating_mul_u64.h`
**Implementation:** `src/pc_saturating_mul_u64.c`
**Prototype:** `uint64_t pc_saturating_mul_u64(uint64_t a, uint64_t b);`

**Contract:** Return min(a b, UINT64_MAX) without wrapping.

**Direct tests:** `tests/test_042_uncovered_api_audit.c`

## `pc_saturating_sub_i64`

**Header:** `include/claudaris/arithmetic/pc_saturating_sub_i64.h`
**Implementation:** `src/pc_saturating_sub_i64.c`
**Prototype:** `int64_t pc_saturating_sub_i64(int64_t a, int64_t b);`

**Contract:** Return a-b clipped to INT64_MIN..INT64_MAX without signed overflow.

**Direct tests:** `tests/test_042_uncovered_api_audit.c`

## `pc_saturating_sub_u64`

**Header:** `include/claudaris/arithmetic/pc_saturating_sub_u64.h`
**Implementation:** `src/pc_saturating_sub_u64.c`
**Prototype:** `uint64_t pc_saturating_sub_u64(uint64_t a, uint64_t b);`

**Contract:** Return max(a-b, 0) without unsigned underflow.

**Direct tests:** `tests/test_042_uncovered_api_audit.c`

## `pc_size_add_checked_u32`

**Header:** `include/claudaris/arithmetic/pc_size_add_checked_u32.h`
**Implementation:** `src/pc_size_add_checked_u32.c`
**Prototype:** `bool pc_size_add_checked_u32(uint32_t a, uint32_t b, uint32_t *sum);`

**Contract:** Add two uint32 size/count values. False for null output or overflow; on failure, leave sum unchanged.

**Direct tests:** `tests/test_023_offset_range_check_u32.c`, `tests/test_035_size_add_checked_u32.c`

## `pc_size_mul_checked_u32`

**Header:** `include/claudaris/arithmetic/pc_size_mul_checked_u32.h`
**Implementation:** `src/pc_size_mul_checked_u32.c`
**Prototype:** `bool pc_size_mul_checked_u32(uint32_t a, uint32_t b, uint32_t *product);`

**Contract:** Multiply two uint32 size/count values. False for null output or overflow; on failure, leave product unchanged.

**Direct tests:** `tests/test_036_size_mul_checked_u32.c`

## `pc_time_convert_ceil_u64`

**Header:** `include/claudaris/arithmetic/pc_time_convert_ceil_u64.h`
**Implementation:** `src/pc_time_convert_ceil_u64.c`
**Prototype:** `bool pc_time_convert_ceil_u64(uint64_t value, uint64_t numerator, uint64_t denominator, uint64_t *result);`

**Contract:** Store ceil(value numerator/denominator). False on zero denominator, null output, or uint64 result overflow; failure preserves output.

**Direct tests:** `tests/test_002_time_convert_ceil_u64.c`, `tests/test_037_time_convert_ceil_u64.c`, `tests/test_043_time_ratio_differential.c`

## `pc_time_convert_floor_u64`

**Header:** `include/claudaris/arithmetic/pc_time_convert_floor_u64.h`
**Implementation:** `src/pc_time_convert_floor_u64.c`
**Prototype:** `bool pc_time_convert_floor_u64(uint64_t value, uint64_t numerator, uint64_t denominator, uint64_t *result);`

**Contract:** Store floor(value numerator/denominator). False on zero denominator, null output, or uint64 result overflow; failure preserves output.

**Direct tests:** `tests/test_003_time_convert_floor_u64.c`, `tests/test_038_time_convert_floor_u64.c`, `tests/test_043_time_ratio_differential.c`

## `pc_time_duration_absdiff_u64`

**Header:** `include/claudaris/arithmetic/pc_time_duration_absdiff_u64.h`
**Implementation:** `src/pc_time_duration_absdiff_u64.c`
**Prototype:** `uint64_t pc_time_duration_absdiff_u64(uint64_t a, uint64_t b);`

**Contract:** Return ordinary unsigned magnitude |a-b|; this is not modular wrap math.

**Direct tests:** `tests/test_004_time_duration_absdiff_u64.c`, `tests/test_039_time_duration_absdiff_u64.c`

## `pc_time_duration_clamp_u64`

**Header:** `include/claudaris/arithmetic/pc_time_duration_clamp_u64.h`
**Implementation:** `src/pc_time_duration_clamp_u64.c`
**Prototype:** `bool pc_time_duration_clamp_u64(uint64_t duration, uint64_t lower, uint64_t upper, uint64_t *result);`

**Contract:** Clamp duration to inclusive [lower, upper]. False for invalid bounds or null output; failure leaves result unchanged.

**Direct tests:** `tests/test_005_time_duration_clamp_u64.c`, `tests/test_040_time_duration_clamp_u64.c`

## `pc_time_scale_ratio_u64`

**Header:** `include/claudaris/arithmetic/pc_time_scale_ratio_u64.h`
**Implementation:** `src/pc_time_scale_ratio_u64.c`
**Prototype:** `bool pc_time_scale_ratio_u64(uint64_t value, uint64_t numerator, uint64_t denominator, uint64_t *result);`

**Contract:** Store nearest-even(value numerator / denominator). False for zero denominator, null output, or uint64 result overflow; failure preserves it.

**Direct tests:** `tests/test_006_time_scale_ratio_u64.c`, `tests/test_041_time_scale_ratio_u64.c`, `tests/test_043_time_ratio_differential.c`
