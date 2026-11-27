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
| `include/claudaris/arithmetic/abs_diff_i64_u64.h` | `claudaris_abs_diff_i64_u64` | Return exact |a-b| as uint64 for any signed int64 inputs. | `test_uncovered_api_audit.c` |
| `include/claudaris/arithmetic/abs_i64_safe_u64.h` | `claudaris_abs_i64_safe_u64` | Return the exact unsigned magnitude of any int64, including INT64_MIN. | `test_uncovered_api_audit.c` |
| `include/claudaris/arithmetic/accumulate_abs_i32.h` | `claudaris_accumulate_abs_i32` | Add the exact magnitude of value to accumulator; overflow leaves it unchanged. | `test_accumulate_abs_i32.c` |
| `include/claudaris/arithmetic/align_down_u32.h` | `claudaris_align_down_u32` | Round value down to a multiple of any positive alignment. | `test_align_down_u32.c` |
| `include/claudaris/arithmetic/align_up_u32.h` | `claudaris_align_up_u32` | Round value up to a multiple of any positive alignment. | `test_align_up_u32.c` |
| `include/claudaris/arithmetic/ceil_to_multiple_i32.h` | `claudaris_ceil_to_multiple_i32` | Ceiling to a positive multiple; false on invalid step or result overflow. | `test_ceil_to_multiple_i32.c` |
| `include/claudaris/arithmetic/checked_abs_i64.h` | `claudaris_checked_abs_i64` | Store /value/ in result. Return false if result is null or the result is not representable (value == INT64_MIN); on failure, do not write output. | `test_checked_abs_i64.c` |
| `include/claudaris/arithmetic/checked_add_i64.h` | `claudaris_checked_add_i64` | Store a+b exactly. False for null output or signed overflow; failure writes nothing to result. | `test_checked_add_i64.c`, `test_uncovered_api_audit.c` |
| `include/claudaris/arithmetic/checked_add_u64.h` | `claudaris_checked_add_u64` | Store a+b exactly. False for null output or overflow; failure is atomic. | `test_uncovered_api_audit.c` |
| `include/claudaris/arithmetic/checked_mul_i64.h` | `claudaris_checked_mul_i64` | Store a b exactly. False on signed overflow or null output; failure leaves output unchanged. | `test_checked_mul_i64.c`, `test_uncovered_api_audit.c` |
| `include/claudaris/arithmetic/checked_mul_u64.h` | `claudaris_checked_mul_u64` | Store a b exactly. False for null output or overflow; failure is atomic. | `test_uncovered_api_audit.c` |
| `include/claudaris/arithmetic/checked_neg_i64.h` | `claudaris_checked_neg_i64` | Store -value exactly; false for null output or INT64_MIN, preserving output. | `test_checked_neg_i64.c` |
| `include/claudaris/arithmetic/checked_shl_i32.h` | `claudaris_checked_shl_i32` | Store value 2^shift exactly. False for shift >= 32, int32_t overflow, or null output; failure leaves output unchanged. | `test_checked_shl_i32.c`, `test_uncovered_api_audit.c` |
| `include/claudaris/arithmetic/checked_shl_u32.h` | `claudaris_checked_shl_u32` | Exact uint32_t left shift. False for shift >= 32, discarded high bits, or null output; on failure output is unchanged. | `test_checked_shl_u32.c`, `test_uncovered_api_audit.c` |
| `include/claudaris/arithmetic/checked_sub_i64.h` | `claudaris_checked_sub_i64` | Store a-b exactly. False for null output or signed overflow; failure writes nothing to result. | `test_checked_sub_i64.c`, `test_uncovered_api_audit.c` |
| `include/claudaris/arithmetic/checked_sub_u64.h` | `claudaris_checked_sub_u64` | Store a-b exactly. False for null output or underflow; failure is atomic. | `test_uncovered_api_audit.c` |
| `include/claudaris/arithmetic/floor_to_multiple_i32.h` | `claudaris_floor_to_multiple_i32` | Floor to a positive multiple; false on invalid step or result overflow. | `test_floor_to_multiple_i32.c` |
| `include/claudaris/arithmetic/fraction_compare_i32.h` | `claudaris_fraction_compare_i32` | Compare exact fractions; writes -1, 0, or 1. Zero denominator fails. | `test_fraction_compare_i32.c` |
| `include/claudaris/arithmetic/is_aligned_u32.h` | `claudaris_is_aligned_u32` | Return whether value is divisible by a positive alignment; zero is false. | `test_is_aligned_u32.c` |
| `include/claudaris/arithmetic/lookup_clamped_i32.h` | `claudaris_lookup_clamped_i32` | Return table[clamp(index, 0, count-1)]; invalid arguments leave value unchanged. table must reference count readable elements. | `test_lookup_clamped_i32.c` |
| `include/claudaris/arithmetic/mask_range_u64.h` | `claudaris_mask_range_u64` | Build a mask for inclusive LSB-zero interval [first_bit,last_bit]. | `test_uncovered_api_audit.c` |
| `include/claudaris/arithmetic/nearest_multiple_u32.h` | `claudaris_nearest_multiple_u32` | Round to nearest positive multiple; exact ties choose the even multiple index. | `test_nearest_multiple_u32.c`, `test_nearest_multiple_u32_extra2.c` |
| `include/claudaris/arithmetic/offset_range_check_u32.h` | `claudaris_offset_range_check_u32` | Check the half-open span [offset, offset + length) against capacity. An empty span at offset == capacity is valid. | `test_offset_range_check_u32.c` |
| `include/claudaris/arithmetic/period_align_u32.h` | `claudaris_period_align_u32` | First origin + k period at or after time; false on invalid input/overflow. | `test_period_align_u32.c` |
| `include/claudaris/arithmetic/period_floor_u32.h` | `claudaris_period_floor_u32` | Greatest origin + k period <= time for k>=0; false when none exists. | `test_period_floor_u32.c` |
| `include/claudaris/arithmetic/range_center_i32.h` | `claudaris_range_center_i32` | Return lower midpoint: lower + floor((upper-lower)/2). | `test_range_center_i32.c` |
| `include/claudaris/arithmetic/range_intersects_i32.h` | `claudaris_range_intersects_i32` | Closed interval intersection; either inverted interval yields false. | `test_range_intersects_i32.c` |
| `include/claudaris/arithmetic/range_shrink_i32.h` | `claudaris_range_shrink_i32` | Symmetrically shrink a closed range; crossing endpoints fails. | `test_range_shrink_i32.c` |
| `include/claudaris/arithmetic/ratio_between_u32.h` | `claudaris_ratio_between_u32` | Test inclusive ratio bounds. Invalid/zero denominators return false status. | `test_ratio_between_u32.c`, `test_uncovered_api_audit.c` |
| `include/claudaris/arithmetic/ratio_ceil_u32.h` | `claudaris_ratio_ceil_u32` | Return ceil(numerator/denominator). Zero denominator fails unchanged. | `test_ratio_ceil_u32.c`, `test_uncovered_api_audit.c` |
| `include/claudaris/arithmetic/ratio_round_even_u32.h` | `claudaris_ratio_round_even_u32` | Round numerator/denominator to nearest integer, ties to even. | `test_ratio_round_even_u32.c`, `test_uncovered_api_audit.c` |
| `include/claudaris/arithmetic/round_to_multiple_i32.h` | `claudaris_round_to_multiple_i32` | Nearest positive multiple, ties to even; false on invalid step/overflow. | `test_round_to_multiple_i32.c` |
| `include/claudaris/arithmetic/saturating_add_i64.h` | `claudaris_saturating_add_i64` | Return a+b clipped to INT64_MIN..INT64_MAX without signed overflow. | `test_uncovered_api_audit.c` |
| `include/claudaris/arithmetic/saturating_add_u64.h` | `claudaris_saturating_add_u64` | Return min(a+b, UINT64_MAX) without wrapping. | `test_uncovered_api_audit.c` |
| `include/claudaris/arithmetic/saturating_cast_i64_i32.h` | `claudaris_saturating_cast_i64_i32` | Clamp value to the int32_t range and return it. | `test_saturating_cast_i64_i32.c` |
| `include/claudaris/arithmetic/saturating_cast_u64_u32.h` | `claudaris_saturating_cast_u64_u32` | Clamp value to UINT32_MAX and return it. | `test_saturating_cast_u64_u32.c` |
| `include/claudaris/arithmetic/saturating_mul_u64.h` | `claudaris_saturating_mul_u64` | Return min(a b, UINT64_MAX) without wrapping. | `test_uncovered_api_audit.c` |
| `include/claudaris/arithmetic/saturating_sub_i64.h` | `claudaris_saturating_sub_i64` | Return a-b clipped to INT64_MIN..INT64_MAX without signed overflow. | `test_uncovered_api_audit.c` |
| `include/claudaris/arithmetic/saturating_sub_u64.h` | `claudaris_saturating_sub_u64` | Return max(a-b, 0) without unsigned underflow. | `test_uncovered_api_audit.c` |
| `include/claudaris/arithmetic/size_add_checked_u32.h` | `claudaris_size_add_checked_u32` | Add two uint32 size/count values. False for null output or overflow; on failure, leave sum unchanged. | `test_offset_range_check_u32.c`, `test_size_add_checked_u32.c` |
| `include/claudaris/arithmetic/size_mul_checked_u32.h` | `claudaris_size_mul_checked_u32` | Multiply two uint32 size/count values. False for null output or overflow; on failure, leave product unchanged. | `test_size_mul_checked_u32.c` |
| `include/claudaris/arithmetic/time_convert_ceil_u64.h` | `claudaris_time_convert_ceil_u64` | Store ceil(value numerator/denominator). False on zero denominator, null output, or uint64 result overflow; failure preserves output. | `test_time_convert_ceil_u64.c`, `test_time_convert_ceil_u64_extra2.c`, `test_time_ratio_differential.c` |
| `include/claudaris/arithmetic/time_convert_floor_u64.h` | `claudaris_time_convert_floor_u64` | Store floor(value numerator/denominator). False on zero denominator, null output, or uint64 result overflow; failure preserves output. | `test_time_convert_floor_u64.c`, `test_time_convert_floor_u64_extra2.c`, `test_time_ratio_differential.c` |
| `include/claudaris/arithmetic/time_duration_absdiff_u64.h` | `claudaris_time_duration_absdiff_u64` | Return ordinary unsigned magnitude |a-b|; this is not modular wrap math. | `test_time_duration_absdiff_u64.c`, `test_time_duration_absdiff_u64_extra2.c` |
| `include/claudaris/arithmetic/time_duration_clamp_u64.h` | `claudaris_time_duration_clamp_u64` | Clamp duration to inclusive [lower, upper]. False for invalid bounds or null output; failure leaves result unchanged. | `test_time_duration_clamp_u64.c`, `test_time_duration_clamp_u64_extra2.c` |
| `include/claudaris/arithmetic/time_scale_ratio_u64.h` | `claudaris_time_scale_ratio_u64` | Store nearest-even(value numerator / denominator). False for zero denominator, null output, or uint64 result overflow; failure preserves it. | `test_time_scale_ratio_u64.c`, `test_time_scale_ratio_u64_extra2.c`, `test_time_ratio_differential.c` |

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
