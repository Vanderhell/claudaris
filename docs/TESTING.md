# Testing and verification

## Inventory and coverage

- **46 public callable APIs** are declared in 46 headers under `include/`.
- `pc_time_ratio_mul_divmod_u64` is private, declared in `src/pc_time_ratio_internal.h`, and is not counted as public API.
- 43 CTest programs are enabled by `CLAUDARIS_BUILD_TESTS`; each of the 46 public symbols is called directly by at least one enabled test.
- `test_042_uncovered_api_audit.c` directly covers the eleven previously untested APIs and performs 100,000 fixed-seed cases for its unsigned and signed checked/saturating arithmetic, shift and ratio operations. It uses `__int128` as an independent exact oracle where supported and safe portable bounds checks otherwise.
- `test_043_time_ratio_differential.c` performs 100,000 deterministic differential cases for floor, ceil and nearest-even 64-bit time conversion. GCC/Clang use an independent `unsigned __int128` product oracle; other compilers use exact 32-bit-factor cases plus full-width edge vectors.
- Existing nearest-multiple, size arithmetic, offset range and period tests include deterministic domain/boundary coverage. Randomized testing is evidence, not a proof of exhaustive correctness.
- Test checks remain active in Release: CMake undefines `NDEBUG` for test targets. New audit tests use explicit failure-returning checks.

## Reproduce

```sh
cmake -S . -B build -DCLAUDARIS_BUILD_TESTS=ON -DCLAUDARIS_STRICT_WARNINGS=ON
cmake --build build --config Release --parallel
ctest --test-dir build -C Release --output-on-failure
```

CMake requests C99 with extensions disabled. GCC and Clang apply strict C99 mode with `-Wall -Wextra -Wpedantic -Werror`; MSVC compiles the same C99-compatible code with `/W4 /WX`.

## Local audit run (2026-11-11)

| Toolchain | Configuration | Build | Tests |
|---|---|---:|---:|
| GCC 16.1.0 (MinGW UCRT) | Debug | PASS | PASS 43/43 |
| GCC 16.1.0 (MinGW UCRT) | Release | PASS | PASS 43/43 |
| Clang 22.1.8 (Windows GNU target) | Debug | PASS | PASS 43/43 |
| Clang 22.1.8 (Windows GNU target) | Release | PASS | PASS 43/43 |
| MSVC 19.42.34444 | Debug | PASS | PASS 43/43 |
| MSVC 19.42.34444 | Release | PASS | PASS 43/43 |
| GCC AddressSanitizer | Windows host | NOT RUN — GCC sanitizer runtime not installed |
| GCC UndefinedBehaviorSanitizer | Windows host | NOT RUN — GCC sanitizer runtime not installed |

## Remote GitHub Actions

Run [42995296516](https://github.com/Vanderhell/claudaris/actions/runs/42995296516) on commit `927114f05d08715327005b0314f52207eb469e9e` completed with **8/8 jobs PASS**: GCC Debug/Release, Clang Debug/Release, MSVC Debug/Release, GCC ASan, and GCC UBSan. This remote run supersedes the local sanitizer `NOT RUN` results above.

## ESP32-S3

`HW BLOCKED`. Read-only inventory identified COM19 as ESP32-S3 QFN56 rev 0.2 with 16 MB flash/8 MB PSRAM and firmware project `fortavis_esp32_hardware`; its layout has NVS, two app slots, SPIFFS and coredump partitions. COM36 is the same chip class/capacity and contains an Estimora firmware image (`ESTIMORA_ALL19_*` strings); its layout has NVS, an app slot, SPIFFS and coredump. These belong to other projects and are not authorized Claudaris test devices. COM37 is reserved and was not queried beyond OS port enumeration. Esptool read operations caused COM19/COM36 to reset through RTS while entering/leaving ROM download mode; no flash writes, erase, NVS access, partition change or firmware upload occurred. The temporary read-only dumps were removed. No candidate is clearly authorized, so hardware testing stopped here; the sketch was not uploaded and no all-API result or cycle measurements are claimed.

Historical documentation records a representative checked-add run on an ESP32-S3, but it did not cover all 46 APIs and is not evidence for this audit's hardware acceptance.

## Known validation limits

- No exhaustive enumeration of the 64-bit input domains is possible; random and boundary tests do not prove all values.
- The `__int128` differential oracle is optional and test-only; production remains strict C99.
- Stack, per-function cycle counts, and isolated library flash/RAM were not measured for this audit.
- Final host, sanitizer and CI results are recorded above; hardware remains blocked pending an explicitly designated Claudaris test device.
