# Claudaris audit register

## Scope and inventory

The product exposes 46 callable C99 functions. Their public headers are in
`include/claudaris/arithmetic/`; each has one implementation unit in `src/`.
The shared time-ratio helper is private under `src/` and is not included in the
public API count. The migrated tree contains 43 direct C test programs plus
one C++ public-header smoke test (44 CTest entries).
Original source, public headers, tests, and hardware sketch are retained under
`tests/oracle/` for provenance and regression comparison.

## Historical audit evidence

The previous symbol revision was audited on 2026-11-11. Its records report
GCC, Clang, and MSVC Debug/Release tests passing 43/43, remote ASan and UBSan
passing, and a representative ESP32-S3 run exercising 46/46 APIs. That device
run and its cycle measurements predate the `claudaris_` namespace migration;
they are historical evidence and do not verify the migrated revision.

The historical audit found no reproduced production arithmetic defect. It
added direct API coverage, kept Release checks active, corrected API inventory
and test documentation, removed a duplicate source entry, and added
differential time-ratio tests. Details and original evidence are retained in
the archived source and test trees.

## Current migrated revision

| Check | Result |
|---|---|
| Public API migration | 46/46 declarations and definitions renamed; public signatures otherwise unchanged |
| Oracle preservation | Original include, source, test and hardware trees archived and hash-checked by the migration tool |
| MSVC 19.42.34444 Debug / Release | PASS, 44/44 CTest entries each |
| GCC 16.1.0 (MinGW UCRT) Debug / Release | PASS, 44/44 each |
| Clang 22.1.8 (Windows GNU target) Debug / Release | PASS, 44/44 each |
| GCC 13.3.0 ASan / UBSan (Ubuntu 24.04 under WSL) | PASS, 44/44 each |
| Remote CI for migrated revision | NOT RUN; no push has triggered a run |
| ESP32-S3 for migrated revision | HW NOT VERIFIED |
| Installed `find_package(Claudaris)` consumer | PASS |

No production arithmetic algorithm was changed as part of namespace migration.
The hardware measurements in `PERFORMANCE.md` remain historical and are not
claimed as measurements of this revision.

## Limitations

Randomized tests are deterministic evidence, not an exhaustive proof over
64-bit domains. The optional `unsigned __int128` oracle is test-only and not
available on every C99 compiler. Isolated library flash and stack bounds have
not been measured. The implementation has no mandatory heap or OS dependency.
