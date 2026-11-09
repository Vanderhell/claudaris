#include "pc_lookup_clamped_i32.h"
#include <assert.h>
#include <limits.h>
#include <stdint.h>
#include <stdio.h>

static uint32_t rng = 0x850C1A4u;
static uint32_t next_u32(void)
{
    rng ^= rng << 13; rng ^= rng >> 17; rng ^= rng << 5; return rng;
}

static size_t oracle_index(size_t count, int32_t index)
{
    if (index < 0) return 0u;
    if ((uint64_t)(uint32_t)index >= (uint64_t)count) return count - 1u;
    return (size_t)(uint32_t)index;
}

int main(void)
{
    int32_t table[64], got;
    size_t n, i;
    int64_t probe;
    for (n = 1u; n <= 64u; ++n) {
        for (i = 0u; i < n; ++i) table[i] = (int32_t)next_u32();
        for (probe = -((int64_t)n + 2); probe <= (int64_t)n + 2; ++probe) {
            size_t at = oracle_index(n, (int32_t)probe);
            assert(pc_lookup_clamped_i32(table, n, (int32_t)probe, &got));
            assert(got == table[at]);
        }
        for (i = 0u; i < 10000u; ++i) {
            int32_t index = (int32_t)next_u32();
            size_t at = oracle_index(n, index);
            assert(pc_lookup_clamped_i32(table, n, index, &got));
            assert(got == table[at]);
        }
    }
    got = 123;
    assert(!pc_lookup_clamped_i32(NULL, 1u, 0, &got) && got == 123);
    assert(!pc_lookup_clamped_i32(table, 0u, 0, &got) && got == 123);
    assert(!pc_lookup_clamped_i32(table, 64u, 0, NULL));
    assert(pc_lookup_clamped_i32(table, 64u, INT32_MIN, &got) && got == table[0]);
    assert(pc_lookup_clamped_i32(table, 64u, INT32_MAX, &got) && got == table[63]);
    puts("lookup clamped tests passed: 64 small domains and 640k seeded full-width cases");
    return 0;
}
