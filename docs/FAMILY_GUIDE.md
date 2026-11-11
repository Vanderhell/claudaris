# Claudaris family guide

## What this family solves

**Checked and saturating arithmetic.** Checked arithmetic, saturation, ratios, ranges, alignment and time conversion.

This guide describes the 46-function public API as an independent embedded-C product. A private time-ratio helper is implementation-only and is not a public callable API. Each public primitive remains separately linkable; select only the headers and source units required by the application.

## When to use this family

Use Claudaris when the application needs the operations listed below and requires deterministic behavior, explicit caller-owned memory, and no mandatory operating-system services.

## Family at a glance

```mermaid
flowchart LR
    A[Application input] --> B[Validate representation and bounds]
    B --> C[Select one public primitive]
    C --> D[Check status or output contract]
    D --> E[Use result with documented units]
```

## Primitive map

| Public header | Callable API | Contract summary | Direct test |
|---|---|---|---|
| `include/claudaris/arithmetic/pc_abs_diff_i64_u64.h` | `pc_abs_diff_i64_u64` | Return exact |a-b| as uint64 for any signed int64 inputs. | `test_042_uncovered_api_audit.c` |
| `include/claudaris/arithmetic/pc_abs_i64_safe_u64.h` | `pc_abs_i64_safe_u64` | Return the exact unsigned magnitude of any int64, including INT64_MIN. | `test_042_uncovered_api_audit.c` |
| `include/claudaris/arithmetic/pc_accumulate_abs_i32.h` | `pc_accumulate_abs_i32` | Add the exact magnitude of value to accumulator; overflow leaves it unchanged. | `test_007_accumulate_abs_i32.c` |
| `include/claudaris/arithmetic/pc_align_down_u32.h` | `pc_align_down_u32` | Round value down to a multiple of any positive alignment. | `test_008_align_down_u32.c` |
| `include/claudaris/arithmetic/pc_align_up_u32.h` | `pc_align_up_u32` | Round value up to a multiple of any positive alignment. | `test_009_align_up_u32.c` |
| `include/claudaris/arithmetic/pc_ceil_to_multiple_i32.h` | `pc_ceil_to_multiple_i32` | Ceiling to a positive multiple; false on invalid step or result overflow. | `test_010_ceil_to_multiple_i32.c` |
| `include/claudaris/arithmetic/pc_checked_abs_i64.h` | `pc_checked_abs_i64` | Store /value/ in result. Return false if result is null or the result is not representable (value == INT64_MIN); on failure, do not write output. | `test_013_checked_abs_i64.c` |
| `include/claudaris/arithmetic/pc_checked_add_i64.h` | `pc_checked_add_i64` | Store a+b exactly. False for null output or signed overflow; failure writes nothing to result. | `test_014_checked_add_i64.c`, `test_042_uncovered_api_audit.c` |
| `include/claudaris/arithmetic/pc_checked_add_u64.h` | `pc_checked_add_u64` | Store a+b exactly. False for null output or overflow; failure is atomic. | `test_042_uncovered_api_audit.c` |
| `include/claudaris/arithmetic/pc_checked_mul_i64.h` | `pc_checked_mul_i64` | Store a b exactly. False on signed overflow or null output; failure leaves output unchanged. | `test_015_checked_mul_i64.c`, `test_042_uncovered_api_audit.c` |
| `include/claudaris/arithmetic/pc_checked_mul_u64.h` | `pc_checked_mul_u64` | Store a b exactly. False for null output or overflow; failure is atomic. | `test_042_uncovered_api_audit.c` |
| `include/claudaris/arithmetic/pc_checked_neg_i64.h` | `pc_checked_neg_i64` | Store -value exactly; false for null output or INT64_MIN, preserving output. | `test_016_checked_neg_i64.c` |
| `include/claudaris/arithmetic/pc_checked_shl_i32.h` | `pc_checked_shl_i32` | Store value 2^shift exactly. False for shift >= 32, int32_t overflow, or null output; failure leaves output unchanged. | `test_017_checked_shl_i32.c`, `test_042_uncovered_api_audit.c` |
| `include/claudaris/arithmetic/pc_checked_shl_u32.h` | `pc_checked_shl_u32` | Exact uint32_t left shift. False for shift >= 32, discarded high bits, or null output; on failure output is unchanged. | `test_018_checked_shl_u32.c`, `test_042_uncovered_api_audit.c` |
| `include/claudaris/arithmetic/pc_checked_sub_i64.h` | `pc_checked_sub_i64` | Store a-b exactly. False for null output or signed overflow; failure writes nothing to result. | `test_019_checked_sub_i64.c`, `test_042_uncovered_api_audit.c` |
| `include/claudaris/arithmetic/pc_checked_sub_u64.h` | `pc_checked_sub_u64` | Store a-b exactly. False for null output or underflow; failure is atomic. | `test_042_uncovered_api_audit.c` |
| `include/claudaris/arithmetic/pc_floor_to_multiple_i32.h` | `pc_floor_to_multiple_i32` | Floor to a positive multiple; false on invalid step or result overflow. | `test_011_floor_to_multiple_i32.c` |
| `include/claudaris/arithmetic/pc_fraction_compare_i32.h` | `pc_fraction_compare_i32` | Compare exact fractions; writes -1, 0, or 1. Zero denominator fails. | `test_012_fraction_compare_i32.c` |
| `include/claudaris/arithmetic/pc_is_aligned_u32.h` | `pc_is_aligned_u32` | Return whether value is divisible by a positive alignment; zero is false. | `test_020_is_aligned_u32.c` |
| `include/claudaris/arithmetic/pc_lookup_clamped_i32.h` | `pc_lookup_clamped_i32` | Return table[clamp(index, 0, count-1)]; invalid arguments leave value unchanged. table must reference count readable elements. | `test_021_lookup_clamped_i32.c` |
| `include/claudaris/arithmetic/pc_mask_range_u64.h` | `pc_mask_range_u64` | Build a mask for inclusive LSB-zero interval [first_bit,last_bit]. | `test_042_uncovered_api_audit.c` |
| `include/claudaris/arithmetic/pc_nearest_multiple_u32.h` | `pc_nearest_multiple_u32` | Round to nearest positive multiple; exact ties choose the even multiple index. | `test_001_nearest_multiple_u32.c`, `test_022_nearest_multiple_u32.c` |
| `include/claudaris/arithmetic/pc_offset_range_check_u32.h` | `pc_offset_range_check_u32` | Check the half-open span [offset, offset + length) against capacity. An empty span at offset == capacity is valid. | `test_023_offset_range_check_u32.c` |
| `include/claudaris/arithmetic/pc_period_align_u32.h` | `pc_period_align_u32` | First origin + k period at or after time; false on invalid input/overflow. | `test_024_period_align_u32.c` |
| `include/claudaris/arithmetic/pc_period_floor_u32.h` | `pc_period_floor_u32` | Greatest origin + k period <= time for k>=0; false when none exists. | `test_025_period_floor_u32.c` |
| `include/claudaris/arithmetic/pc_range_center_i32.h` | `pc_range_center_i32` | Return lower midpoint: lower + floor((upper-lower)/2). | `test_026_range_center_i32.c` |
| `include/claudaris/arithmetic/pc_range_intersects_i32.h` | `pc_range_intersects_i32` | Closed interval intersection; either inverted interval yields false. | `test_027_range_intersects_i32.c` |
| `include/claudaris/arithmetic/pc_range_shrink_i32.h` | `pc_range_shrink_i32` | Symmetrically shrink a closed range; crossing endpoints fails. | `test_028_range_shrink_i32.c` |
| `include/claudaris/arithmetic/pc_ratio_between_u32.h` | `pc_ratio_between_u32` | Test inclusive ratio bounds. Invalid/zero denominators return false status. | `test_029_ratio_between_u32.c`, `test_042_uncovered_api_audit.c` |
| `include/claudaris/arithmetic/pc_ratio_ceil_u32.h` | `pc_ratio_ceil_u32` | Return ceil(numerator/denominator). Zero denominator fails unchanged. | `test_030_ratio_ceil_u32.c`, `test_042_uncovered_api_audit.c` |
| `include/claudaris/arithmetic/pc_ratio_round_even_u32.h` | `pc_ratio_round_even_u32` | Round numerator/denominator to nearest integer, ties to even. | `test_031_ratio_round_even_u32.c`, `test_042_uncovered_api_audit.c` |
| `include/claudaris/arithmetic/pc_round_to_multiple_i32.h` | `pc_round_to_multiple_i32` | Nearest positive multiple, ties to even; false on invalid step/overflow. | `test_032_round_to_multiple_i32.c` |
| `include/claudaris/arithmetic/pc_saturating_add_i64.h` | `pc_saturating_add_i64` | Return a+b clipped to INT64_MIN..INT64_MAX without signed overflow. | `test_042_uncovered_api_audit.c` |
| `include/claudaris/arithmetic/pc_saturating_add_u64.h` | `pc_saturating_add_u64` | Return min(a+b, UINT64_MAX) without wrapping. | `test_042_uncovered_api_audit.c` |
| `include/claudaris/arithmetic/pc_saturating_cast_i64_i32.h` | `pc_saturating_cast_i64_i32` | Clamp value to the int32_t range and return it. | `test_033_saturating_cast_i64_i32.c` |
| `include/claudaris/arithmetic/pc_saturating_cast_u64_u32.h` | `pc_saturating_cast_u64_u32` | Clamp value to UINT32_MAX and return it. | `test_034_saturating_cast_u64_u32.c` |
| `include/claudaris/arithmetic/pc_saturating_mul_u64.h` | `pc_saturating_mul_u64` | Return min(a b, UINT64_MAX) without wrapping. | `test_042_uncovered_api_audit.c` |
| `include/claudaris/arithmetic/pc_saturating_sub_i64.h` | `pc_saturating_sub_i64` | Return a-b clipped to INT64_MIN..INT64_MAX without signed overflow. | `test_042_uncovered_api_audit.c` |
| `include/claudaris/arithmetic/pc_saturating_sub_u64.h` | `pc_saturating_sub_u64` | Return max(a-b, 0) without unsigned underflow. | `test_042_uncovered_api_audit.c` |
| `include/claudaris/arithmetic/pc_size_add_checked_u32.h` | `pc_size_add_checked_u32` | Add two uint32 size/count values. False for null output or overflow; on failure, leave sum unchanged. | `test_023_offset_range_check_u32.c`, `test_035_size_add_checked_u32.c` |
| `include/claudaris/arithmetic/pc_size_mul_checked_u32.h` | `pc_size_mul_checked_u32` | Multiply two uint32 size/count values. False for null output or overflow; on failure, leave product unchanged. | `test_036_size_mul_checked_u32.c` |
| `include/claudaris/arithmetic/pc_time_convert_ceil_u64.h` | `pc_time_convert_ceil_u64` | Store ceil(value numerator/denominator). False on zero denominator, null output, or uint64 result overflow; failure preserves output. | `test_002_time_convert_ceil_u64.c`, `test_037_time_convert_ceil_u64.c`, `test_043_time_ratio_differential.c` |
| `include/claudaris/arithmetic/pc_time_convert_floor_u64.h` | `pc_time_convert_floor_u64` | Store floor(value numerator/denominator). False on zero denominator, null output, or uint64 result overflow; failure preserves output. | `test_003_time_convert_floor_u64.c`, `test_038_time_convert_floor_u64.c`, `test_043_time_ratio_differential.c` |
| `include/claudaris/arithmetic/pc_time_duration_absdiff_u64.h` | `pc_time_duration_absdiff_u64` | Return ordinary unsigned magnitude |a-b|; this is not modular wrap math. | `test_004_time_duration_absdiff_u64.c`, `test_039_time_duration_absdiff_u64.c` |
| `include/claudaris/arithmetic/pc_time_duration_clamp_u64.h` | `pc_time_duration_clamp_u64` | Clamp duration to inclusive [lower, upper]. False for invalid bounds or null output; failure leaves result unchanged. | `test_005_time_duration_clamp_u64.c`, `test_040_time_duration_clamp_u64.c` |
| `include/claudaris/arithmetic/pc_time_scale_ratio_u64.h` | `pc_time_scale_ratio_u64` | Store nearest-even(value numerator / denominator). False for zero denominator, null output, or uint64 result overflow; failure preserves it. | `test_006_time_scale_ratio_u64.c`, `test_041_time_scale_ratio_u64.c`, `test_043_time_ratio_differential.c` |

## Selection guidance

- Choose the primitive whose width, representation, rounding, saturation, wrapping, and error contract match the application.
- Do not substitute a similarly named function without checking the public header.
- Allocate state and buffers in the caller; respect documented aliasing and output-preservation rules.
- Treat entries marked without a validation source as requiring additional product-level tests before release.

## Integration checklist

1. Include only the required public header.
2. Compile the matching source translation unit or use the product CMake target.
3. Check every boolean/status return before consuming an output.
4. Add application-specific boundary tests for units, widths, invalid inputs, and overflow behavior.
5. Run the documented host tests before target integration.

## Complexity and footprint

The product is split into independent translation units. Exact flash, RAM, stack, and cycle costs depend on the selected functions, compiler, optimization, and MCU; unmeasured values remain explicitly marked PENDING in the testing documentation.

## Validation boundary

The API reference links each public entry to its implementation and available validation source. Hardware status is reported only when reproducible target evidence exists.
