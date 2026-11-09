# Testing

## Status

This is the first independent extraction of the Claudaris arithmetic subset.
The source family records show validation for the migrated units. The
independent CMake test suite must be treated as the extraction regression gate.

| Test category | Count | Platform | Result | Evidence |
|---|---:|---|---|---|
| Migrated unit tests | 41 source programs | Windows host, MSVC 19.42.34444, Release | PASS 41/41 | `tests/`, CTest |
| Representative hardware validation | 1 run, 10,000 iterations plus boundary checks | ESP32-S3 QFN56 rev0.2, 240 MHz, COM37 | PASS | `hardware/esp32s3/claudaris_hw/claudaris_hw.ino` |
| Sanitizers | 0 | Host | NOT TESTED | Toolchain setup pending |

## Reproducibility

```sh
cmake -S . -B build -DCLAUDARIS_BUILD_TESTS=ON
cmake --build build --config Release
ctest --test-dir build --output-on-failure -C Release
```

## Known gaps

- The independent host build and test run are the next verification gate.
- The hardware run covers representative checked arithmetic, saturation, ratio,
  alignment and time-scale calls; it is not exhaustive for all 46 public
  functions.
- Isolated flash/RAM footprint and per-function stack measurements are not yet
  available.
- The family contains additional specialized records that are not part of this
  first independently buildable subset because their migrated source evidence
  is incomplete or their source is not present in the canonical C tree.
