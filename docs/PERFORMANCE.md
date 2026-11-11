# Performance and footprint

## ESP32-S3 validation and measurements (2026-11-11)

Device COM36: ESP32-S3 QFN56 rev 0.2, 240 MHz. Arduino CLI 1.4.1, ESP32 Arduino core 3.3.10, `esp32:esp32:ozobot_drvkit`; core release optimization `-Os`. The firmware image is 301,056 bytes (Arduino reports 300,905 bytes program storage); whole-sketch global/static RAM is 22,404 bytes. These totals include the Arduino runtime, validation harness, and fixtures; flash was not isolated to the library.

The firmware passed all 46 representative API checks. Per API: 31 paired samples, 1,000 repetitions per sample, alternating actual and same-signature no-op batches; calls used volatile inputs/function pointers and a volatile sink. The separate empty-loop batch baseline was 29 cycles/call. Values below are median paired actual-minus-no-op batch differences divided by 1,000, at the reported 240 MHz. The pairing subtracts loop, indirect-call, and sink costs to estimate incremental API cost. Very small results (especially 1 to 10 cycles) are near the measurement resolution and should be treated as approximate; no worst-case timing guarantee is implied.

| API | Median cycles/call |
|---|---:|
| `pc_abs_diff_i64_u64` | 10 |
| `pc_abs_i64_safe_u64` | 6 |
| `pc_accumulate_abs_i32` | 16 |
| `pc_align_down_u32` | 9 |
| `pc_align_up_u32` | 16 |
| `pc_ceil_to_multiple_i32` | 220 |
| `pc_checked_abs_i64` | 18 |
| `pc_checked_add_i64` | 16 |
| `pc_checked_add_u64` | 14 |
| `pc_checked_mul_i64` | 225 |
| `pc_checked_mul_u64` | 29 |
| `pc_checked_neg_i64` | 13 |
| `pc_checked_shl_i32` | 27 |
| `pc_checked_shl_u32` | 12 |
| `pc_checked_sub_i64` | 14 |
| `pc_checked_sub_u64` | 11 |
| `pc_floor_to_multiple_i32` | 218 |
| `pc_fraction_compare_i32` | 49 |
| `pc_is_aligned_u32` | 9 |
| `pc_lookup_clamped_i32` | 15 |
| `pc_mask_range_u64` | 60 |
| `pc_nearest_multiple_u32` | 31 |
| `pc_offset_range_check_u32` | 7 |
| `pc_period_align_u32` | 20 |
| `pc_period_floor_u32` | 14 |
| `pc_range_center_i32` | 15 |
| `pc_range_intersects_i32` | 17 |
| `pc_range_shrink_i32` | 25 |
| `pc_ratio_between_u32` | 39 |
| `pc_ratio_ceil_u32` | 16 |
| `pc_ratio_round_even_u32` | 17 |
| `pc_round_to_multiple_i32` | 233 |
| `pc_saturating_add_i64` | 13 |
| `pc_saturating_add_u64` | 12 |
| `pc_saturating_cast_i64_i32` | 7 |
| `pc_saturating_cast_u64_u32` | 1 |
| `pc_saturating_mul_u64` | 17 |
| `pc_saturating_sub_i64` | 18 |
| `pc_saturating_sub_u64` | 9 |
| `pc_size_add_checked_u32` | 6 |
| `pc_size_mul_checked_u32` | 7 |
| `pc_time_convert_ceil_u64` | 242 |
| `pc_time_convert_floor_u64` | 227 |
| `pc_time_duration_absdiff_u64` | 7 |
| `pc_time_duration_clamp_u64` | 9 |
| `pc_time_scale_ratio_u64` | 250 |

The original COM36 `app0` was backed up before testing and restored afterward; full-partition readback SHA-256 matched the backup. Only `app0` at offset `0x10000` was written. NVS and other partitions were left untouched. COM37 was not used.

## Footprint status

| Metric | Result |
|---|---|
| Whole validation firmware program storage | 300,905 bytes (Arduino CLI report) |
| Validation firmware binary file | 301,056 bytes |
| Whole sketch global/static RAM | 22,404 bytes |
| Isolated library flash contribution | NOT MEASURED |
| Isolated library static RAM contribution | 0 bytes by inspection of production C units (no file-scope objects) |
| Stack usage / maximum stack | NOT MEASURED |
| Dynamic allocation in production library | None found in audited C units |

A total firmware image size must not be presented as library-only flash usage. Stack bounds cannot be inferred from a single watermark. The cycle figures describe only the recorded representative inputs, board, compiler and optimization configuration.

## Historical representative measurement

The previous version of this document recorded an ESP32-S3 QFN56 rev 0.2 checked-add-only run (Arduino ESP32 core 3.3.10, CPU configured at 240 MHz, COM37) with 10,000 loop iterations. It reported 1–24 observed cycles, 310,264 bytes total sketch program storage, and 22,184 bytes global/static RAM. These values include runtime and harness overhead, are not isolated library footprint, and do not constitute this audit's all-API hardware validation. The currently observed COM37 firmware is unrelated, so the measurement is retained only as historical evidence.

| Metric | Current audit status |
|---|---|
| Cycles per public API | NOT MEASURED |
| Isolated library flash contribution | NOT MEASURED |
| Isolated library static RAM contribution | NOT MEASURED |
| Stack bounds | NOT MEASURED |
| Heap requirement in the library | No dynamic allocation in audited implementation units |
