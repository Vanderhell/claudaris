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
| ESP32-S3 all-API run | HW NOT VERIFIED; no safe authorized Claudaris board could be identified. |

The remote run [42995054763](https://github.com/Vanderhell/claudaris/actions/runs/42995054763) on code commit `f355ce99cd46cbd7a1e5ba096db91cba9c7579ea` passed all eight jobs, including GCC ASan/UBSan and both Debug/Release builds for GCC, Clang and MSVC. The final documentation commit has its own run and will be verified before this audit is reported complete. See [TESTING.md](TESTING.md) for host commands and [PERFORMANCE.md](PERFORMANCE.md) for measurement limits.

## Remaining limitations

- Host testing cannot establish MCU-specific timing, stack, flash or static-RAM costs.
- Randomized testing is deterministic and broad but not exhaustive over 64-bit domains.
- Full-width `__int128` differential testing is available only on compilers that implement the extension; it is confined to test code.
- Hardware validation is NOT RUN, and the firmware sketch was not uploaded to avoid replacing unrelated application firmware.
