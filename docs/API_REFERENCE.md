# Claudaris API reference

This reference explains every public header in the Claudaris product. It is generated from the current headers and test sources; the header remains authoritative when a detail conflicts.

## Reading the entries
Each entry states the public symbol, implementation unit, contract, edge/failure behavior and a call extracted from the validating test source. The examples are evidence-oriented; adapt buffer ownership and numeric units to the application.

## include/claudaris/arithmetic/pc_abs_diff_i64_u64.h

**Public symbol:** pc_abs_diff_i64_u64

**Implementation unit:** src/pc_abs_diff_i64_u64.c

**Purpose and contract:** Return exact |a-b| as uint64 for any signed int64 inputs.

**Validation source:** No enabled test source was found by symbol search.

**Test-derived call:**
```c
No test-derived call was found.;
```

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/claudaris/arithmetic/pc_abs_i64_safe_u64.h

**Public symbol:** pc_abs_i64_safe_u64

**Implementation unit:** src/pc_abs_i64_safe_u64.c

**Purpose and contract:** Return the exact unsigned magnitude of any int64, including INT64_MIN.

**Validation source:** No enabled test source was found by symbol search.

**Test-derived call:**
```c
No test-derived call was found.;
```

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/claudaris/arithmetic/pc_accumulate_abs_i32.h

**Public symbol:** pc_accumulate_abs_i32

**Implementation unit:** src/pc_accumulate_abs_i32.c

**Purpose and contract:** Add the exact magnitude of value to *accumulator; overflow leaves it unchanged.

**Validation source:** tests/test_007_accumulate_abs_i32.c

**Test-derived call:**
```c
pc_accumulate_abs_i32(0,&a) && a==0u);
```

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/claudaris/arithmetic/pc_align_down_u32.h

**Public symbol:** pc_align_down_u32

**Implementation unit:** src/pc_align_down_u32.c

**Purpose and contract:** Round value down to a multiple of any positive alignment.

**Validation source:** tests/test_008_align_down_u32.c

**Test-derived call:**
```c
pc_align_down_u32(13,8,&out)&&out==8);
```

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/claudaris/arithmetic/pc_align_up_u32.h

**Public symbol:** pc_align_up_u32

**Implementation unit:** src/pc_align_up_u32.c

**Purpose and contract:** Round value up to a multiple of any positive alignment.

**Validation source:** tests/test_009_align_up_u32.c

**Test-derived call:**
```c
pc_align_up_u32(13,8,&out)&&out==16);
```

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/claudaris/arithmetic/pc_ceil_to_multiple_i32.h

**Public symbol:** pc_ceil_to_multiple_i32

**Implementation unit:** src/pc_ceil_to_multiple_i32.c

**Purpose and contract:** Ceiling to a positive multiple; false on invalid step or result overflow.

**Validation source:** tests/test_010_ceil_to_multiple_i32.c

**Test-derived call:**
```c
pc_ceil_to_multiple_i32(5, 2, &out) && out == 6);
```

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/claudaris/arithmetic/pc_floor_to_multiple_i32.h

**Public symbol:** pc_floor_to_multiple_i32

**Implementation unit:** src/pc_floor_to_multiple_i32.c

**Purpose and contract:** Floor to a positive multiple; false on invalid step or result overflow.

**Validation source:** tests/test_011_floor_to_multiple_i32.c

**Test-derived call:**
```c
pc_floor_to_multiple_i32(5, 2, &out) && out == 4);
```

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/claudaris/arithmetic/pc_fraction_compare_i32.h

**Public symbol:** pc_fraction_compare_i32

**Implementation unit:** src/pc_fraction_compare_i32.c

**Purpose and contract:** Compare exact fractions; writes -1, 0, or 1. Zero denominator fails.

**Validation source:** tests/test_012_fraction_compare_i32.c

**Test-derived call:**
```c
pc_fraction_compare_i32(1, 2, 2, 3, &c) && c == -1);
```

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/claudaris/arithmetic/pc_checked_abs_i64.h

**Public symbol:** pc_checked_abs_i64

**Implementation unit:** src/pc_checked_abs_i64.c

**Purpose and contract:** Store |value| in *result. Return false if result is null or the result is not representable (value == INT64_MIN); on failure, do not write output.

**Validation source:** tests/test_013_checked_abs_i64.c

**Test-derived call:**
```c
pc_checked_abs_i64(inputs[i], &output);
```

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/claudaris/arithmetic/pc_checked_add_i64.h

**Public symbol:** pc_checked_add_i64

**Implementation unit:** src/pc_checked_add_i64.c

**Purpose and contract:** Store a+b exactly. False for null output or signed overflow; failure writes nothing to result.

**Validation source:** tests/test_014_checked_add_i64.c

**Test-derived call:**
```c
pc_checked_add_i64(a[i], b[i], &out);
```

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/claudaris/arithmetic/pc_checked_add_u64.h

**Public symbol:** pc_checked_add_u64

**Implementation unit:** src/pc_checked_add_u64.c

**Purpose and contract:** Store a+b exactly. False for null output or overflow; failure is atomic.

**Validation source:** No enabled test source was found by symbol search.

**Test-derived call:**
```c
No test-derived call was found.;
```

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/claudaris/arithmetic/pc_checked_mul_i64.h

**Public symbol:** pc_checked_mul_i64

**Implementation unit:** src/pc_checked_mul_i64.c

**Purpose and contract:** Store a*b exactly. False on signed overflow or null output; failure leaves output unchanged.

**Validation source:** tests/test_015_checked_mul_i64.c

**Test-derived call:**
```c
pc_checked_mul_i64(a[i], b[i], &out);
```

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/claudaris/arithmetic/pc_checked_mul_u64.h

**Public symbol:** pc_checked_mul_u64

**Implementation unit:** src/pc_checked_mul_u64.c

**Purpose and contract:** Store a*b exactly. False for null output or overflow; failure is atomic.

**Validation source:** No enabled test source was found by symbol search.

**Test-derived call:**
```c
No test-derived call was found.;
```

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/claudaris/arithmetic/pc_checked_neg_i64.h

**Public symbol:** pc_checked_neg_i64

**Implementation unit:** src/pc_checked_neg_i64.c

**Purpose and contract:** Store -value exactly; false for null output or INT64_MIN, preserving output.

**Validation source:** tests/test_016_checked_neg_i64.c

**Test-derived call:**
```c
pc_checked_neg_i64(x[i], &out);
```

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/claudaris/arithmetic/pc_checked_shl_i32.h

**Public symbol:** pc_checked_shl_i32

**Implementation unit:** src/pc_checked_shl_i32.c

**Purpose and contract:** Store value*2^shift exactly. False for shift >= 32, int32_t overflow, or null output; failure leaves output unchanged.

**Validation source:** tests/test_017_checked_shl_i32.c

**Test-derived call:**
```c
pc_checked_shl_i32(1, 30, &out) && out == INT32_C(1073741824\);
```

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/claudaris/arithmetic/pc_checked_shl_u32.h

**Public symbol:** pc_checked_shl_u32

**Implementation unit:** src/pc_checked_shl_u32.c

**Purpose and contract:** Exact uint32_t left shift. False for shift >= 32, discarded high bits, or null output; on failure output is unchanged.

**Validation source:** tests/test_018_checked_shl_u32.c

**Test-derived call:**
```c
pc_checked_shl_u32(1, 31, &out) && out == UINT32_C(0x80000000\);
```

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/claudaris/arithmetic/pc_checked_sub_i64.h

**Public symbol:** pc_checked_sub_i64

**Implementation unit:** src/pc_checked_sub_i64.c

**Purpose and contract:** Store a-b exactly. False for null output or signed overflow; failure writes nothing to result.

**Validation source:** tests/test_019_checked_sub_i64.c

**Test-derived call:**
```c
pc_checked_sub_i64(a[i], b[i], &out);
```

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/claudaris/arithmetic/pc_checked_sub_u64.h

**Public symbol:** pc_checked_sub_u64

**Implementation unit:** src/pc_checked_sub_u64.c

**Purpose and contract:** Store a-b exactly. False for null output or underflow; failure is atomic.

**Validation source:** No enabled test source was found by symbol search.

**Test-derived call:**
```c
No test-derived call was found.;
```

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/claudaris/arithmetic/pc_is_aligned_u32.h

**Public symbol:** pc_is_aligned_u32

**Implementation unit:** src/pc_is_aligned_u32.c

**Purpose and contract:** Return whether value is divisible by a positive alignment; zero is false.

**Validation source:** tests/test_020_is_aligned_u32.c

**Test-derived call:**
```c
pc_is_aligned_u32(0,7\);
```

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/claudaris/arithmetic/pc_lookup_clamped_i32.h

**Public symbol:** pc_lookup_clamped_i32

**Implementation unit:** src/pc_lookup_clamped_i32.c

**Purpose and contract:** Return table[clamp(index, 0, count-1)]; invalid arguments leave value unchanged. table must reference count readable elements.

**Validation source:** tests/test_021_lookup_clamped_i32.c

**Test-derived call:**
```c
pc_lookup_clamped_i32(table, n, (int32_t)probe, &got\);
```

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/claudaris/arithmetic/pc_mask_range_u64.h

**Public symbol:** pc_mask_range_u64

**Implementation unit:** src/pc_mask_range_u64.c

**Purpose and contract:** Build a mask for inclusive LSB-zero interval [first_bit,last_bit].

**Validation source:** No enabled test source was found by symbol search.

**Test-derived call:**
```c
No test-derived call was found.;
```

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/claudaris/arithmetic/pc_nearest_multiple_u32.h

**Public symbol:** pc_nearest_multiple_u32

**Implementation unit:** src/pc_nearest_multiple_u32.c

**Purpose and contract:** Round to nearest positive multiple; exact ties choose the even multiple index.

**Validation source:** tests/test_001_nearest_multiple_u32.c

**Test-derived call:**
```c
pc_nearest_multiple_u32(v,m,&o)==ref(v,m,&e\);
```

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/claudaris/arithmetic/pc_offset_range_check_u32.h

**Public symbol:** pc_offset_range_check_u32

**Implementation unit:** src/pc_offset_range_check_u32.c

**Purpose and contract:** Check the half-open span [offset, offset + length) against capacity. An empty span at offset == capacity is valid.

**Validation source:** tests/test_023_offset_range_check_u32.c

**Test-derived call:**
```c
pc_offset_range_check_u32(offset, length, capacity);
```

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/claudaris/arithmetic/pc_period_align_u32.h

**Public symbol:** pc_period_align_u32

**Implementation unit:** src/pc_period_align_u32.c

**Purpose and contract:** First origin + k*period at or after time; false on invalid input/overflow.

**Validation source:** tests/test_024_period_align_u32.c

**Test-derived call:**
```c
pc_period_align_u32(10,0,5,&out)&&out==10);
```

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/claudaris/arithmetic/pc_period_floor_u32.h

**Public symbol:** pc_period_floor_u32

**Implementation unit:** src/pc_period_floor_u32.c

**Purpose and contract:** Greatest origin + k*period <= time for k>=0; false when none exists.

**Validation source:** tests/test_025_period_floor_u32.c

**Test-derived call:**
```c
pc_period_floor_u32(10,0,5,&out)&&out==10);
```

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/claudaris/arithmetic/pc_range_center_i32.h

**Public symbol:** pc_range_center_i32

**Implementation unit:** src/pc_range_center_i32.c

**Purpose and contract:** Return lower midpoint: lower + floor((upper-lower)/2).

**Validation source:** tests/test_026_range_center_i32.c

**Test-derived call:**
```c
pc_range_center_i32(-3, 2, &c) && c == -1);
```

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/claudaris/arithmetic/pc_range_intersects_i32.h

**Public symbol:** pc_range_intersects_i32

**Implementation unit:** src/pc_range_intersects_i32.c

**Purpose and contract:** Closed interval intersection; either inverted interval yields false.

**Validation source:** tests/test_027_range_intersects_i32.c

**Test-derived call:**
```c
pc_range_intersects_i32(1, 4, 4, 8\);
```

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/claudaris/arithmetic/pc_range_shrink_i32.h

**Public symbol:** pc_range_shrink_i32

**Implementation unit:** src/pc_range_shrink_i32.c

**Purpose and contract:** Symmetrically shrink a closed range; crossing endpoints fails.

**Validation source:** tests/test_028_range_shrink_i32.c

**Test-derived call:**
```c
pc_range_shrink_i32(2, 8, 3, &lo, &hi) && lo == 5 && hi == 5);
```

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/claudaris/arithmetic/pc_ratio_between_u32.h

**Public symbol:** pc_ratio_between_u32

**Implementation unit:** src/pc_ratio_between_u32.c

**Purpose and contract:** Test inclusive ratio bounds. Invalid/zero denominators return false status.

**Validation source:** tests/test_029_ratio_between_u32.c

**Test-derived call:**
```c
pc_ratio_between_u32(1, 2, 1, 3, 2, 3, &result) && result);
```

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/claudaris/arithmetic/pc_ratio_ceil_u32.h

**Public symbol:** pc_ratio_ceil_u32

**Implementation unit:** src/pc_ratio_ceil_u32.c

**Purpose and contract:** Return ceil(numerator/denominator). Zero denominator fails unchanged.

**Validation source:** tests/test_030_ratio_ceil_u32.c

**Test-derived call:**
```c
pc_ratio_ceil_u32(10, 3, &q) && q == 4);
```

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/claudaris/arithmetic/pc_ratio_round_even_u32.h

**Public symbol:** pc_ratio_round_even_u32

**Implementation unit:** src/pc_ratio_round_even_u32.c

**Purpose and contract:** Round numerator/denominator to nearest integer, ties to even.

**Validation source:** tests/test_031_ratio_round_even_u32.c

**Test-derived call:**
```c
pc_ratio_round_even_u32(1, 2, &q) && q == 0);
```

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/claudaris/arithmetic/pc_round_to_multiple_i32.h

**Public symbol:** pc_round_to_multiple_i32

**Implementation unit:** src/pc_round_to_multiple_i32.c

**Purpose and contract:** Nearest positive multiple, ties to even; false on invalid step/overflow.

**Validation source:** tests/test_032_round_to_multiple_i32.c

**Test-derived call:**
```c
pc_round_to_multiple_i32(5, 2, &out) && out == 4);
```

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/claudaris/arithmetic/pc_saturating_add_i64.h

**Public symbol:** pc_saturating_add_i64

**Implementation unit:** src/pc_saturating_add_i64.c

**Purpose and contract:** Return a+b clipped to INT64_MIN..INT64_MAX without signed overflow.

**Validation source:** No enabled test source was found by symbol search.

**Test-derived call:**
```c
No test-derived call was found.;
```

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/claudaris/arithmetic/pc_saturating_add_u64.h

**Public symbol:** pc_saturating_add_u64

**Implementation unit:** src/pc_saturating_add_u64.c

**Purpose and contract:** Return min(a+b, UINT64_MAX) without wrapping.

**Validation source:** No enabled test source was found by symbol search.

**Test-derived call:**
```c
No test-derived call was found.;
```

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/claudaris/arithmetic/pc_saturating_cast_i64_i32.h

**Public symbol:** pc_saturating_cast_i64_i32

**Implementation unit:** src/pc_saturating_cast_i64_i32.c

**Purpose and contract:** Clamp value to the int32_t range and return it.

**Validation source:** tests/test_033_saturating_cast_i64_i32.c

**Test-derived call:**
```c
pc_saturating_cast_i64_i32((int64_t)INT32_MIN - 1) == INT32_MIN);
```

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/claudaris/arithmetic/pc_saturating_cast_u64_u32.h

**Public symbol:** pc_saturating_cast_u64_u32

**Implementation unit:** src/pc_saturating_cast_u64_u32.c

**Purpose and contract:** Clamp value to UINT32_MAX and return it.

**Validation source:** tests/test_034_saturating_cast_u64_u32.c

**Test-derived call:**
```c
pc_saturating_cast_u64_u32(0) == 0);
```

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/claudaris/arithmetic/pc_saturating_mul_u64.h

**Public symbol:** pc_saturating_mul_u64

**Implementation unit:** src/pc_saturating_mul_u64.c

**Purpose and contract:** Return min(a*b, UINT64_MAX) without wrapping.

**Validation source:** No enabled test source was found by symbol search.

**Test-derived call:**
```c
No test-derived call was found.;
```

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/claudaris/arithmetic/pc_saturating_sub_i64.h

**Public symbol:** pc_saturating_sub_i64

**Implementation unit:** src/pc_saturating_sub_i64.c

**Purpose and contract:** Return a-b clipped to INT64_MIN..INT64_MAX without signed overflow.

**Validation source:** No enabled test source was found by symbol search.

**Test-derived call:**
```c
No test-derived call was found.;
```

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/claudaris/arithmetic/pc_saturating_sub_u64.h

**Public symbol:** pc_saturating_sub_u64

**Implementation unit:** src/pc_saturating_sub_u64.c

**Purpose and contract:** Return max(a-b, 0) without unsigned underflow.

**Validation source:** No enabled test source was found by symbol search.

**Test-derived call:**
```c
No test-derived call was found.;
```

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/claudaris/arithmetic/pc_size_add_checked_u32.h

**Public symbol:** pc_size_add_checked_u32

**Implementation unit:** src/pc_size_add_checked_u32.c

**Purpose and contract:** Add two uint32 size/count values. False for null output or overflow; on failure, leave *sum unchanged.

**Validation source:** tests/test_023_offset_range_check_u32.c

**Test-derived call:**
```c
pc_size_add_checked_u32(offset, length, &end);
```

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/claudaris/arithmetic/pc_size_mul_checked_u32.h

**Public symbol:** pc_size_mul_checked_u32

**Implementation unit:** src/pc_size_mul_checked_u32.c

**Purpose and contract:** Multiply two uint32 size/count values. False for null output or overflow; on failure, leave *product unchanged.

**Validation source:** tests/test_036_size_mul_checked_u32.c

**Test-derived call:**
```c
pc_size_mul_checked_u32(a, b, &actual);
```

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/claudaris/arithmetic/pc_time_convert_ceil_u64.h

**Public symbol:** pc_time_convert_ceil_u64

**Implementation unit:** src/pc_time_convert_ceil_u64.c

**Purpose and contract:** Store ceil(value*numerator/denominator). False on zero denominator, null output, or uint64 result overflow; failure preserves output.

**Validation source:** tests/test_002_time_convert_ceil_u64.c

**Test-derived call:**
```c
pc_time_convert_ceil_u64(1,1,2,&out) && out==1);
```

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/claudaris/arithmetic/pc_time_convert_floor_u64.h

**Public symbol:** pc_time_convert_floor_u64

**Implementation unit:** src/pc_time_convert_floor_u64.c

**Purpose and contract:** Store floor(value*numerator/denominator). False on zero denominator, null output, or uint64 result overflow; failure preserves output.

**Validation source:** tests/test_003_time_convert_floor_u64.c

**Test-derived call:**
```c
pc_time_convert_floor_u64(3,1,2,&out) && out==1);
```

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/claudaris/arithmetic/pc_time_duration_absdiff_u64.h

**Public symbol:** pc_time_duration_absdiff_u64

**Implementation unit:** src/pc_time_duration_absdiff_u64.c

**Purpose and contract:** Return ordinary unsigned magnitude |a-b|; this is not modular wrap math.

**Validation source:** tests/test_004_time_duration_absdiff_u64.c

**Test-derived call:**
```c
pc_time_duration_absdiff_u64(0,0)==0);
```

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/claudaris/arithmetic/pc_time_duration_clamp_u64.h

**Public symbol:** pc_time_duration_clamp_u64

**Implementation unit:** src/pc_time_duration_clamp_u64.c

**Purpose and contract:** Clamp duration to inclusive [lower, upper]. False for invalid bounds or null output; failure leaves *result unchanged.

**Validation source:** tests/test_005_time_duration_clamp_u64.c

**Test-derived call:**
```c
pc_time_duration_clamp_u64(5,10,20,&out) && out==10);
```

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/claudaris/arithmetic/pc_time_ratio_internal.h

**Public symbol:** pc_time_ratio_mul_divmod_u64

**Implementation unit:** src/pc_time_ratio_internal.c

**Purpose and contract:** Private shared primitive. Computes floor(value*numerator/denominator) and its remainder exactly. False on invalid pointers/denominator or quotient overflow; outputs remain unchanged on failure.

**Validation source:** No enabled test source was found by symbol search.

**Test-derived call:**
```c
No test-derived call was found.;
```

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/claudaris/arithmetic/pc_time_scale_ratio_u64.h

**Public symbol:** pc_time_scale_ratio_u64

**Implementation unit:** src/pc_time_scale_ratio_u64.c

**Purpose and contract:** Store nearest-even(value * numerator / denominator). False for zero denominator, null output, or uint64 result overflow; failure preserves it.

**Validation source:** tests/test_006_time_scale_ratio_u64.c

**Test-derived call:**
```c
pc_time_scale_ratio_u64(1, 1, 2, &out) && out == 0);
```

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

