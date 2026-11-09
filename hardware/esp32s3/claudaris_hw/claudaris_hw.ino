#include <Arduino.h>
#include <esp_cpu.h>

extern "C" {
#include "../../../include/claudaris/arithmetic/pc_checked_add_u64.h"
#include "../../../include/claudaris/arithmetic/pc_saturating_add_u64.h"
#include "../../../include/claudaris/arithmetic/pc_ratio_round_even_u32.h"
#include "../../../include/claudaris/arithmetic/pc_align_up_u32.h"
#include "../../../include/claudaris/arithmetic/pc_time_scale_ratio_u64.h"
#include "../../../src/pc_checked_add_u64.c"
#include "../../../src/pc_saturating_add_u64.c"
#include "../../../src/pc_ratio_round_even_u32.c"
#include "../../../src/pc_align_up_u32.c"
#include "../../../src/pc_time_ratio_internal.c"
#include "../../../src/pc_time_scale_ratio_u64.c"
}

void setup()
{
    bool pass = true;
    uint64_t value = 0u;
    uint32_t rounded = 0u;
    uint32_t aligned = 0u;
    uint32_t checksum = 0u;
    uint32_t min_cycles = UINT32_MAX;
    uint32_t max_cycles = 0u;
    pass &= pc_checked_add_u64(1u, 2u, &value) && value == 3u;
    pass &= !pc_checked_add_u64(UINT64_MAX, 1u, &value);
    pass &= pc_saturating_add_u64(UINT64_MAX, 1u) == UINT64_MAX;
    pass &= pc_ratio_round_even_u32(5u, 2u, &rounded) && rounded == 2u;
    pass &= pc_align_up_u32(17u, 8u, &aligned) && aligned == 24u;
    pass &= pc_time_scale_ratio_u64(1000u, 3u, 2u, &value) && value == 1500u;
    for (uint32_t i = 0u; i < 10000u; ++i) {
        const uint32_t start = esp_cpu_get_cycle_count();
        pass &= pc_checked_add_u64(i, i + 1u, &value);
        const uint32_t elapsed = esp_cpu_get_cycle_count() - start;
        if (elapsed < min_cycles) min_cycles = elapsed;
        if (elapsed > max_cycles) max_cycles = elapsed;
        checksum ^= (uint32_t)value;
    }
    Serial.begin(115200);
    Serial.printf("CLAUDARIS_HW|%s|mcu=ESP32-S3|cpu_mhz=%u|tests=10000+boundaries|checksum=%u|checked_add_cycles_min=%u|checked_add_cycles_max=%u\n",
                  pass ? "PASS" : "FAIL", getCpuFrequencyMhz(), checksum,
                  min_cycles, max_cycles);
}

void loop()
{
    delay(1000);
}
