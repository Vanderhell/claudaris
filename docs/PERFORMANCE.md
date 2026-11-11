# Performance and footprint

## Current audit

**HW BLOCKED.** Per-API ESP32-S3 cycle counts and isolated library flash/static-RAM contributions: **NOT MEASURED**. Stack usage: **NOT MEASURED**. COM19 and COM36 were identified as running Fortavis and Estimora firmware, respectively, so neither was overwritten; COM37 is reserved and was not queried. No clearly authorized Claudaris test board was available. Read-only partition/firmware inspection caused transient ROM-mode resets on COM19/COM36 but made no flash writes and did not access NVS. See [TESTING.md](TESTING.md).

The unflashed validation sketch compiled with Arduino ESP32 core 3.3.10 for `esp32:esp32:ozobot_drvkit`: **288,989 bytes** total sketch program storage and **21,948 bytes** total globals/static RAM. These are whole-sketch build totals, including harness/runtime overhead; they are not isolated Claudaris library contributions and do not measure runtime cycles.

Do not infer per-function performance from the host tests or from a total firmware size. Any future footprint report should compare a baseline and library-linked build with identical board, compiler, optimization, linker and partition settings, and should report library sections separately from firmware/runtime overhead. A stack watermark is not a maximum stack bound.

## Historical representative measurement

The previous version of this document recorded an ESP32-S3 QFN56 rev 0.2 checked-add-only run (Arduino ESP32 core 3.3.10, CPU configured at 240 MHz, COM37) with 10,000 loop iterations. It reported 1–24 observed cycles, 310,264 bytes total sketch program storage, and 22,184 bytes global/static RAM. These values include runtime and harness overhead, are not isolated library footprint, and do not constitute this audit's all-API hardware validation. The currently observed COM37 firmware is unrelated, so the measurement is retained only as historical evidence.

| Metric | Current audit status |
|---|---|
| Cycles per public API | NOT MEASURED |
| Isolated library flash contribution | NOT MEASURED |
| Isolated library static RAM contribution | NOT MEASURED |
| Stack bounds | NOT MEASURED |
| Heap requirement in the library | No dynamic allocation in audited implementation units |
