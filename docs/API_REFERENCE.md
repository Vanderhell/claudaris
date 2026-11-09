# Claudaris API reference

Complete public-header inventory generated from the current source tree. Headers remain authoritative.

## include/claudaris/arithmetic/pc_abs_diff_i64_u64.h

Public API: pc_abs_diff_i64_u64

Contract: Return exact |a-b| as uint64 for any signed int64 inputs.

Header path: include/claudaris/arithmetic/pc_abs_diff_i64_u64.h

## include/claudaris/arithmetic/pc_abs_i64_safe_u64.h

Public API: pc_abs_i64_safe_u64

Contract: Return the exact unsigned magnitude of any int64, including INT64_MIN.

Header path: include/claudaris/arithmetic/pc_abs_i64_safe_u64.h

## include/claudaris/arithmetic/pc_accumulate_abs_i32.h

Public API: pc_accumulate_abs_i32

Contract: Add the exact magnitude of value to *accumulator; overflow leaves it unchanged.

Header path: include/claudaris/arithmetic/pc_accumulate_abs_i32.h

## include/claudaris/arithmetic/pc_align_down_u32.h

Public API: pc_align_down_u32

Contract: Round value down to a multiple of any positive alignment.

Header path: include/claudaris/arithmetic/pc_align_down_u32.h

## include/claudaris/arithmetic/pc_align_up_u32.h

Public API: pc_align_up_u32

Contract: Round value up to a multiple of any positive alignment.

Header path: include/claudaris/arithmetic/pc_align_up_u32.h

## include/claudaris/arithmetic/pc_ceil_to_multiple_i32.h

Public API: pc_ceil_to_multiple_i32

Contract: Ceiling to a positive multiple; false on invalid step or result overflow.

Header path: include/claudaris/arithmetic/pc_ceil_to_multiple_i32.h

## include/claudaris/arithmetic/pc_floor_to_multiple_i32.h

Public API: pc_floor_to_multiple_i32

Contract: Floor to a positive multiple; false on invalid step or result overflow.

Header path: include/claudaris/arithmetic/pc_floor_to_multiple_i32.h

## include/claudaris/arithmetic/pc_fraction_compare_i32.h

Public API: pc_fraction_compare_i32

Contract: Compare exact fractions; writes -1, 0, or 1. Zero denominator fails.

Header path: include/claudaris/arithmetic/pc_fraction_compare_i32.h

## include/claudaris/arithmetic/pc_checked_abs_i64.h

Public API: pc_checked_abs_i64

Contract: Store |value| in *result. Return false if result is null or the result is not representable (value == INT64_MIN); on failure, do not write output.

Header path: include/claudaris/arithmetic/pc_checked_abs_i64.h

## include/claudaris/arithmetic/pc_checked_add_i64.h

Public API: pc_checked_add_i64

Contract: Store a+b exactly. False for null output or signed overflow; failure writes nothing to result.

Header path: include/claudaris/arithmetic/pc_checked_add_i64.h

## include/claudaris/arithmetic/pc_checked_add_u64.h

Public API: pc_checked_add_u64

Contract: Store a+b exactly. False for null output or overflow; failure is atomic.

Header path: include/claudaris/arithmetic/pc_checked_add_u64.h

## include/claudaris/arithmetic/pc_checked_mul_i64.h

Public API: pc_checked_mul_i64

Contract: Store a*b exactly. False on signed overflow or null output; failure leaves output unchanged.

Header path: include/claudaris/arithmetic/pc_checked_mul_i64.h

## include/claudaris/arithmetic/pc_checked_mul_u64.h

Public API: pc_checked_mul_u64

Contract: Store a*b exactly. False for null output or overflow; failure is atomic.

Header path: include/claudaris/arithmetic/pc_checked_mul_u64.h

## include/claudaris/arithmetic/pc_checked_neg_i64.h

Public API: pc_checked_neg_i64

Contract: Store -value exactly; false for null output or INT64_MIN, preserving output.

Header path: include/claudaris/arithmetic/pc_checked_neg_i64.h

## include/claudaris/arithmetic/pc_checked_shl_i32.h

Public API: pc_checked_shl_i32

Contract: Store value*2^shift exactly. False for shift >= 32, int32_t overflow, or null output; failure leaves output unchanged.

Header path: include/claudaris/arithmetic/pc_checked_shl_i32.h

## include/claudaris/arithmetic/pc_checked_shl_u32.h

Public API: pc_checked_shl_u32

Contract: Exact uint32_t left shift. False for shift >= 32, discarded high bits, or null output; on failure output is unchanged.

Header path: include/claudaris/arithmetic/pc_checked_shl_u32.h

## include/claudaris/arithmetic/pc_checked_sub_i64.h

Public API: pc_checked_sub_i64

Contract: Store a-b exactly. False for null output or signed overflow; failure writes nothing to result.

Header path: include/claudaris/arithmetic/pc_checked_sub_i64.h

## include/claudaris/arithmetic/pc_checked_sub_u64.h

Public API: pc_checked_sub_u64

Contract: Store a-b exactly. False for null output or underflow; failure is atomic.

Header path: include/claudaris/arithmetic/pc_checked_sub_u64.h

## include/claudaris/arithmetic/pc_is_aligned_u32.h

Public API: pc_is_aligned_u32

Contract: Return whether value is divisible by a positive alignment; zero is false.

Header path: include/claudaris/arithmetic/pc_is_aligned_u32.h

## include/claudaris/arithmetic/pc_lookup_clamped_i32.h

Public API: pc_lookup_clamped_i32

Contract: Return table[clamp(index, 0, count-1)]; invalid arguments leave value unchanged. table must reference count readable elements.

Header path: include/claudaris/arithmetic/pc_lookup_clamped_i32.h

## include/claudaris/arithmetic/pc_mask_range_u64.h

Public API: pc_mask_range_u64

Contract: Build a mask for inclusive LSB-zero interval [first_bit,last_bit].

Header path: include/claudaris/arithmetic/pc_mask_range_u64.h

## include/claudaris/arithmetic/pc_nearest_multiple_u32.h

Public API: pc_nearest_multiple_u32

Contract: Round to nearest positive multiple; exact ties choose the even multiple index.

Header path: include/claudaris/arithmetic/pc_nearest_multiple_u32.h

## include/claudaris/arithmetic/pc_offset_range_check_u32.h

Public API: pc_offset_range_check_u32

Contract: Check the half-open span [offset, offset + length) against capacity. An empty span at offset == capacity is valid.

Header path: include/claudaris/arithmetic/pc_offset_range_check_u32.h

## include/claudaris/arithmetic/pc_period_align_u32.h

Public API: pc_period_align_u32

Contract: First origin + k*period at or after time; false on invalid input/overflow.

Header path: include/claudaris/arithmetic/pc_period_align_u32.h

## include/claudaris/arithmetic/pc_period_floor_u32.h

Public API: pc_period_floor_u32

Contract: Greatest origin + k*period <= time for k>=0; false when none exists.

Header path: include/claudaris/arithmetic/pc_period_floor_u32.h

## include/claudaris/arithmetic/pc_range_center_i32.h

Public API: pc_range_center_i32

Contract: Return lower midpoint: lower + floor((upper-lower)/2).

Header path: include/claudaris/arithmetic/pc_range_center_i32.h

## include/claudaris/arithmetic/pc_range_intersects_i32.h

Public API: pc_range_intersects_i32

Contract: Closed interval intersection; either inverted interval yields false.

Header path: include/claudaris/arithmetic/pc_range_intersects_i32.h

## include/claudaris/arithmetic/pc_range_shrink_i32.h

Public API: pc_range_shrink_i32

Contract: Symmetrically shrink a closed range; crossing endpoints fails.

Header path: include/claudaris/arithmetic/pc_range_shrink_i32.h

## include/claudaris/arithmetic/pc_ratio_between_u32.h

Public API: pc_ratio_between_u32

Contract: Test inclusive ratio bounds. Invalid/zero denominators return false status.

Header path: include/claudaris/arithmetic/pc_ratio_between_u32.h

## include/claudaris/arithmetic/pc_ratio_ceil_u32.h

Public API: pc_ratio_ceil_u32

Contract: Return ceil(numerator/denominator). Zero denominator fails unchanged.

Header path: include/claudaris/arithmetic/pc_ratio_ceil_u32.h

## include/claudaris/arithmetic/pc_ratio_round_even_u32.h

Public API: pc_ratio_round_even_u32

Contract: Round numerator/denominator to nearest integer, ties to even.

Header path: include/claudaris/arithmetic/pc_ratio_round_even_u32.h

## include/claudaris/arithmetic/pc_round_to_multiple_i32.h

Public API: pc_round_to_multiple_i32

Contract: Nearest positive multiple, ties to even; false on invalid step/overflow.

Header path: include/claudaris/arithmetic/pc_round_to_multiple_i32.h

## include/claudaris/arithmetic/pc_saturating_add_i64.h

Public API: pc_saturating_add_i64

Contract: Return a+b clipped to INT64_MIN..INT64_MAX without signed overflow.

Header path: include/claudaris/arithmetic/pc_saturating_add_i64.h

## include/claudaris/arithmetic/pc_saturating_add_u64.h

Public API: pc_saturating_add_u64

Contract: Return min(a+b, UINT64_MAX) without wrapping.

Header path: include/claudaris/arithmetic/pc_saturating_add_u64.h

## include/claudaris/arithmetic/pc_saturating_cast_i64_i32.h

Public API: pc_saturating_cast_i64_i32

Contract: Clamp value to the int32_t range and return it.

Header path: include/claudaris/arithmetic/pc_saturating_cast_i64_i32.h

## include/claudaris/arithmetic/pc_saturating_cast_u64_u32.h

Public API: pc_saturating_cast_u64_u32

Contract: Clamp value to UINT32_MAX and return it.

Header path: include/claudaris/arithmetic/pc_saturating_cast_u64_u32.h

## include/claudaris/arithmetic/pc_saturating_mul_u64.h

Public API: pc_saturating_mul_u64

Contract: Return min(a*b, UINT64_MAX) without wrapping.

Header path: include/claudaris/arithmetic/pc_saturating_mul_u64.h

## include/claudaris/arithmetic/pc_saturating_sub_i64.h

Public API: pc_saturating_sub_i64

Contract: Return a-b clipped to INT64_MIN..INT64_MAX without signed overflow.

Header path: include/claudaris/arithmetic/pc_saturating_sub_i64.h

## include/claudaris/arithmetic/pc_saturating_sub_u64.h

Public API: pc_saturating_sub_u64

Contract: Return max(a-b, 0) without unsigned underflow.

Header path: include/claudaris/arithmetic/pc_saturating_sub_u64.h

## include/claudaris/arithmetic/pc_size_add_checked_u32.h

Public API: pc_size_add_checked_u32

Contract: Add two uint32 size/count values. False for null output or overflow; on failure, leave *sum unchanged.

Header path: include/claudaris/arithmetic/pc_size_add_checked_u32.h

## include/claudaris/arithmetic/pc_size_mul_checked_u32.h

Public API: pc_size_mul_checked_u32

Contract: Multiply two uint32 size/count values. False for null output or overflow; on failure, leave *product unchanged.

Header path: include/claudaris/arithmetic/pc_size_mul_checked_u32.h

## include/claudaris/arithmetic/pc_time_convert_ceil_u64.h

Public API: pc_time_convert_ceil_u64

Contract: Store ceil(value*numerator/denominator). False on zero denominator, null output, or uint64 result overflow; failure preserves output.

Header path: include/claudaris/arithmetic/pc_time_convert_ceil_u64.h

## include/claudaris/arithmetic/pc_time_convert_floor_u64.h

Public API: pc_time_convert_floor_u64

Contract: Store floor(value*numerator/denominator). False on zero denominator, null output, or uint64 result overflow; failure preserves output.

Header path: include/claudaris/arithmetic/pc_time_convert_floor_u64.h

## include/claudaris/arithmetic/pc_time_duration_absdiff_u64.h

Public API: pc_time_duration_absdiff_u64

Contract: Return ordinary unsigned magnitude |a-b|; this is not modular wrap math.

Header path: include/claudaris/arithmetic/pc_time_duration_absdiff_u64.h

## include/claudaris/arithmetic/pc_time_duration_clamp_u64.h

Public API: pc_time_duration_clamp_u64

Contract: Clamp duration to inclusive [lower, upper]. False for invalid bounds or null output; failure leaves *result unchanged.

Header path: include/claudaris/arithmetic/pc_time_duration_clamp_u64.h

## include/claudaris/arithmetic/pc_time_ratio_internal.h

Public API: pc_time_ratio_mul_divmod_u64

Contract: Private shared primitive. Computes floor(value*numerator/denominator) and its remainder exactly. False on invalid pointers/denominator or quotient overflow; outputs remain unchanged on failure.

Header path: include/claudaris/arithmetic/pc_time_ratio_internal.h

## include/claudaris/arithmetic/pc_time_scale_ratio_u64.h

Public API: pc_time_scale_ratio_u64

Contract: Store nearest-even(value * numerator / denominator). False for zero denominator, null output, or uint64 result overflow; failure preserves it.

Header path: include/claudaris/arithmetic/pc_time_scale_ratio_u64.h
