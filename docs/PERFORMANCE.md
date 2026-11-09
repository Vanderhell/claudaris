# Performance

The representative harness was measured on 2026-11-09 using an ESP32-S3 QFN56
revision 0.2 board at 240 MHz, USB-Serial/JTAG on COM37, Arduino ESP32 core
3.3.10 and `CDCOnBoot=cdc`. It ran 10,000 checked-add calls plus boundary
checks. The values include the Arduino runtime and harness.

| Measurement | Status |
|---|---|
| ESP32-S3 checked-add cycles, minimum | 1 cycle observed |
| ESP32-S3 checked-add cycles, maximum | 24 cycles observed |
| ESP32-S3 harness program storage | 310,264 bytes |
| ESP32-S3 harness global/static RAM | 22,184 bytes |
| Stack usage | NOT MEASURED |
| Heap usage | No heap API; runtime heap use not required |
| Host timing | Not a substitute for MCU measurement |

The values above are not the isolated library footprint. A baseline/minimal
link-time comparison and per-function stack measurement remain pending.
