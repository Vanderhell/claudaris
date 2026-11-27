# Testing and verification

## Coverage

- 46 public callable APIs are declared in 46 public headers and each is called
  directly by at least one of the 43 enabled C tests.
- One C++ smoke-test target independently includes all 46 public headers.
- The time-ratio multiply/divide helper is private under `src/` and is excluded
  from the public count.
- The preserved audit tests include deterministic boundary checks and 100,000
  fixed-seed cases for checked/saturating arithmetic and full-width time
  conversion where an independent widened oracle is supported.
- Tests use explicit checks and the CMake configuration undefines `NDEBUG` for
  test targets, so checks remain active in Release builds.
- Random testing supplements boundary and invariant checks; it is not an
  exhaustive proof over all 64-bit inputs.

## Build and test

```sh
cmake -S . -B build -DCLAUDARIS_BUILD_TESTS=ON -DCLAUDARIS_STRICT_WARNINGS=ON
cmake --build build --config Release --parallel
ctest --test-dir build -C Release --output-on-failure
```

The library requires ISO C99 with extensions disabled. GCC/Clang use
`-Wall -Wextra -Wpedantic -Werror`; MSVC uses `/W4 /WX`.

## Historical source-revision results

The prior public-symbol revision was tested on 2026-11-11:

| Toolchain | Configuration | Result |
|---|---|---|
| GCC 16.1.0 (MinGW UCRT) | Debug / Release | PASS, 43/43 each |
| Clang 22.1.8 (Windows GNU target) | Debug / Release | PASS, 43/43 each |
| MSVC 19.42.34444 | Debug / Release | PASS, 43/43 each |
| GCC ASan / UBSan | Remote workflow | PASS |

The associated remote run is [42995296516](https://github.com/Vanderhell/claudaris/actions/runs/42995296516), on pre-migration commit `927114f05d08715327005b0314f52207eb469e9e`. It is not validation of the renamed source revision.

## Namespace-migrated revision results

| Toolchain/check | Result |
|---|---|
| MSVC 19.42.34444 Debug / Release | PASS, 44/44 CTest entries each |
| GCC 16.1.0 (MinGW UCRT) Debug / Release | PASS, 44/44 each |
| Clang 22.1.8 (Windows GNU target) Debug / Release | PASS, 44/44 each |
| GCC 13.3.0 AddressSanitizer / UndefinedBehaviorSanitizer (Ubuntu 24.04 under WSL) | PASS, 44/44 each |
| GitHub Actions for migrated revision | NOT RUN; push not yet performed |
| ESP32-S3 for migrated revision | HW NOT VERIFIED |

## Historical ESP32-S3 evidence

The pre-migration revision has a recorded representative hardware run on an
ESP32-S3 at 240 MHz: 46/46 API checks passed. The Arduino CLI 1.4.1 and ESP32
Arduino core 3.3.10 build used `-Os`. Its firmware printed
`CLAUDARIS_ALL_PASS|passed=46/46|first_failed_api=0`. This historical test used
one representative expected result per API; it was not exhaustive MCU-domain
testing. The existing application image was restored and verified after the
run according to the internal test record. No claim is made that the renamed
revision has been flashed or tested on hardware.

## Limits

Full-width random testing is not exhaustive. The `unsigned __int128` reference
is test-only and optional on compilers without that extension. Stack bounds
and isolated library flash have not been measured. See
[`PERFORMANCE.md`](PERFORMANCE.md) for historical cycle data and footprint
limits.
