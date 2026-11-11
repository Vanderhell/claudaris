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

## ESP32-S3 (2026-11-11)

**PASS: 46/46 APIs** on COM36, ESP32-S3 QFN56 rev 0.2, MAC `3c:0f:02:d9:76:f0`, 16 MB flash / 8 MB PSRAM. The device was identified as an Estimora board; the user's explicit instruction to try COM36 authorized this temporary validation. Before flashing, the existing `app0` partition (`0x10000`, size `0x300000`) was read to a local backup (SHA-256 `DED6AD129A6DA83DB94ACADF00C2B61814EAC9BB713BB13B2004416E8F707948`). The validation image was written only at `0x10000`; no partition table, NVS, SPIFFS, or coredump region was written or read for this test. After validation, the complete backed-up `app0` was restored and read back; its SHA-256 matched exactly. COM37 was not opened or otherwise used.

The firmware printed `CLAUDARIS_ALL_PASS|passed=46/46|first_failed_api=0`. It checked one representative expected result for each public operation. Build: Arduino CLI 1.4.1, ESP32 Arduino core 3.3.10, FQBN `esp32:esp32:ozobot_drvkit`; image 301,056 bytes, CLI reports 300,905 bytes sketch program storage and 22,404 bytes total global/static RAM. Optimization setting was `-Os`; runtime CPU frequency reported 240 MHz. The benchmark used 31 paired samples of 1,000 repetitions per API, alternating actual and same-signature no-op batches, with a volatile sink. The separately measured empty-loop/batch cost was 29 cycles/call. Per-API estimates are the median paired actual-minus-no-op difference, divided by repetitions; see [PERFORMANCE.md](PERFORMANCE.md). These are measurements of this firmware/build and representative inputs, not worst-case bounds.

## Known validation limits

- No exhaustive enumeration of the 64-bit input domains is possible; random and boundary tests do not prove all values.
- The `__int128` differential oracle is optional and test-only; production remains strict C99.
- Stack bounds and isolated library flash contribution were not measured. The production C units contain no static objects, so isolated library static RAM contribution is 0 bytes by source inspection; stack usage remains unmeasured.
- Final host, sanitizer and CI results are recorded above; hardware validation covers one representative input per API on COM36; it is not exhaustive MCU-domain testing.
