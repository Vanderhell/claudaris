# CLAUDARIS technical audit register

Audit date: 2026-11-11. Branch: `main`. Scope: all checked-in production C units, public headers, CMake targets, tests, documentation, and the available ESP32-S3 sketch. No production arithmetic algorithm was changed.

## API and implementation inventory

| Classification | Count | Evidence |
|---|---:|---|
| Public callable APIs | 46 | 46 headers and callable declarations under `include/claudaris/arithmetic/` |
| Public implementation units | 46 | `src/pc_<symbol>.c` for each public symbol |
| Private shared implementation helper | 1 | `src/pc_time_ratio_internal.c` + `src/pc_time_ratio_internal.h` |
| CTest programs after audit | 43 | `tests/test_001_...c` through `tests/test_043_...c` |

The prior README count of 47 callable entries was counting the private time-ratio helper. `TESTING.md`'s count of 46 public functions was correct. The helper declaration has been moved from the public include tree into `src/` to make this distinction structural; its name and internal contract are unchanged. CMake also contained a duplicate `pc_saturating_sub_u64.c` source entry; it was removed without changing the resulting library behavior.

## API audit register

All 46 public operations were reviewed against their declarations, implementation units, and direct test calls. Full function-by-function contracts and test source mapping are in [API_REFERENCE.md](API_REFERENCE.md).

| Area | Result | Evidence / boundary |
|---|---|---|
| Checked signed/unsigned add, subtract, multiply, absolute, negate and shifts | OK | Boundary tests and deterministic differential tests; failure-preservation checks for output APIs |
| Saturating arithmetic and casts | OK | `INT64_MIN`, `INT64_MAX`, `UINT64_MAX`, and 100,000 deterministic cases for arithmetic under test |
| Rounding to multiples and ratios | OK | Positive/negative and exact-half cases; nearest-even rules in direct tests |
| Alignment and masks | OK | Non-power-of-two alignments; every valid inclusive bit interval in `[0,63]`; invalid ranges preserve outputs |
| Ranges, sizes, periods and offsets | OK | Exhaustive small domains, boundary vectors and deterministic random tests in applicable existing tests |
| 64-bit time conversion | OK | Independent `unsigned __int128` reference for 100,000 deterministic full-width cases on GCC/Clang; exact safe-factor fallback and edge vectors on compilers without it |
| Pointer and failure behavior | OK | Null-output and sentinel-preservation checks where applicable; caller-owned buffers only |
| C99 and implementation-defined behavior | OK for host matrix | Strict C99 extensions-off CMake; GCC, Clang, MSVC host builds below |
| Heap/OS dependencies | OK | No allocation or OS APIs in production source; no mandatory external dependency |

`OK` means the reviewed implementation and available tests agree with the documented contract; it is not a formal proof over all inputs.

## Confirmed findings and changes

| ID | Classification | Finding | Change / regression evidence |
|---|---|---|---|
| A-01 | BUG (validation coverage) | 11 callable APIs had no direct test despite the existing test count being 41 programs. | Added direct deterministic tests in `test_042_uncovered_api_audit.c`; each listed symbol is called, including invalid parameters and output preservation. |
| A-02 | BUG (test portability) | Existing Release CTest targets defined `NDEBUG`, disabling `assert`-based checks. | CMake now undefines `NDEBUG` for test targets. Release GCC, Clang, and MSVC runs pass all enabled checks. |
| A-03 | BUG (inventory/docs) | README counted 47 callable APIs and included a private helper; API docs also emitted nonexistent-test placeholders. | Count corrected to 46; internal header moved to `src/`; API reference regenerated from declarations and direct test source matches. |
| A-04 | BUG (build configuration) | `pc_saturating_sub_u64.c` appeared twice in the static-library source list. | Removed duplicate CMake entry; all toolchain builds pass. |
| A-05 | BUG (time-ratio validation) | Full-width intermediate-product overflow was not differentially tested independently. | Added `test_043_time_ratio_differential.c` with widened exact reference on supported compilers and deterministic safe-product fallback elsewhere. |

No confirmed production arithmetic defect was reproduced in this audit; therefore no production algorithm was modified. The above BUG classifications concern validation, inventory, or build configuration, not incorrect production results.

## Build and test evidence

| Compiler / job | Result |
|---|---|
| GCC 16.1.0 (MinGW UCRT), Debug and Release | PASS, 43/43 CTest each |
| Clang 22.1.8 (Windows GNU target), Debug and Release | PASS, 43/43 CTest each |
| MSVC 19.42.34444, Debug and Release | PASS, 43/43 CTest each |
| GCC ASan | PASS remotely; local runtime unavailable on Windows. |
| GCC UBSan | PASS remotely; local runtime unavailable on Windows. |
| ESP32-S3 all-API run | PASS, 46/46 representative calls on COM36; temporary `app0` backup/restore verified by matching SHA-256. |

The remote run [42995296516](https://github.com/Vanderhell/claudaris/actions/runs/42995296516) on commit `927114f05d08715327005b0314f52207eb469e9e` passed all eight jobs, including GCC ASan/UBSan and both Debug/Release builds for GCC, Clang and MSVC. Hardware validation and representative cycle measurements on COM36 are recorded in [TESTING.md](TESTING.md) and [PERFORMANCE.md](PERFORMANCE.md).

## Remaining limitations

- Host testing cannot establish MCU-specific timing, stack, or isolated flash cost. The current device run reports whole-firmware RAM; library static RAM is 0 bytes by inspection of production C units.
- Randomized testing is deterministic and broad but not exhaustive over 64-bit domains.
- Full-width `__int128` differential testing is available only on compilers that implement the extension; it is confined to test code.
- Hardware validation passed on COM36 after explicit user instruction. Its Estimora `app0` image was fully backed up and restored with matching SHA-256; no other partition was written. COM37 was not used.

## Hardware validation follow-up (2026-11-11)

COM37 was reserved and not opened. COM36 was identified as ESP32-S3 QFN56 rev 0.2, MAC `3c:0f:02:d9:76:f0`, running an Estimora image. Following the user's explicit instruction to try COM36, the full existing `app0` partition was backed up (SHA-256 `DED6AD129A6DA83DB94ACADF00C2B61814EAC9BB713BB13B2004416E8F707948`). The 301,056-byte Claudaris test image was temporarily written only at `0x10000`; firmware printed `CLAUDARIS_ALL_PASS|passed=46/46|first_failed_api=0`. The original full `app0` partition was then restored and read back with the same SHA-256. No NVS, partition table, SPIFFS, coredump, or other partition was written. Per-API medians are in [PERFORMANCE.md](PERFORMANCE.md).

The test firmware build reported 300,905 bytes total sketch program storage and 22,404 bytes total global/static RAM. Isolated library flash and stack usage remain **NOT MEASURED**. Source inspection finds no file-scope objects in the production C units, so isolated library static RAM is 0 bytes. COM19 was not used for this validation.
