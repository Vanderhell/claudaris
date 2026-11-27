#include "pc_size_mul_checked_u32.h"
#include <stddef.h>
#include <stdint.h>

static uint32_t state = UINT32_C(0x2283C0DE);

static uint32_t next_u32(void)
{
    state ^= state << 13u;
    state ^= state >> 17u;
    state ^= state << 5u;
    return state;
}

static int check(uint32_t a, uint32_t b)
{
    const uint64_t expected = (uint64_t)a * (uint64_t)b;
    const int valid = expected <= UINT32_MAX;
    uint32_t actual = UINT32_C(0xA55AA55A);
    const int ok = pc_size_mul_checked_u32(a, b, &actual);
    if (ok != valid) return 1;
    if (valid) return actual == (uint32_t)expected ? 0 : 2;
    return actual == UINT32_C(0xA55AA55A) ? 0 : 3;
}

int main(void)
{
    static const uint32_t edges[] = {
        0u, 1u, 2u, UINT32_C(0x7FFFFFFF), UINT32_C(0x80000000),
        UINT32_MAX - 1u, UINT32_MAX
    };
    uint32_t a, b, i, j, checks = 0u;
    for (a = 0u; a < 256u; ++a) {
        for (b = 0u; b < 256u; ++b) {
            if (check(a, b) != 0) return 1;
            ++checks;
        }
    }
    for (i = 0u; i < (uint32_t)(sizeof(edges) / sizeof(edges[0])); ++i) {
        for (j = 0u; j < (uint32_t)(sizeof(edges) / sizeof(edges[0])); ++j) {
            if (check(edges[i], edges[j]) != 0) return 2;
            ++checks;
        }
    }
    for (i = 0u; i < 1000000u; ++i) {
        a = next_u32();
        b = next_u32();
        if (check(a, b) != 0) return 3;
        ++checks;
    }
    {
        uint32_t output = UINT32_C(0x13579BDF);
        uint32_t alias = UINT32_MAX / 3u;
        if (pc_size_mul_checked_u32(1u, 2u, NULL)) return 4;
        if (pc_size_mul_checked_u32(2u, UINT32_MAX / 2u + 1u, &output)) return 5;
        if (output != UINT32_C(0x13579BDF)) return 6;
        if (!pc_size_mul_checked_u32(alias, 3u, &alias) || alias != UINT32_MAX) return 7;
        alias = UINT32_MAX / 2u + 1u;
        if (pc_size_mul_checked_u32(alias, 2u, &alias) || alias != UINT32_MAX / 2u + 1u) return 8;
        alias = 3u;
        if (!pc_size_mul_checked_u32(5u, alias, &alias) || alias != 15u) return 9;
        alias = UINT32_MAX;
        if (pc_size_mul_checked_u32(2u, alias, &alias) || alias != UINT32_MAX) return 10;
    }
    return checks == UINT32_C(1065585) ? 0 : 11;
}
