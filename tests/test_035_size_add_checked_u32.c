#include "pc_size_add_checked_u32.h"
#include <stddef.h>
#include <stdint.h>

static uint32_t random_state = UINT32_C(0x2281A11D);
static uint32_t next_u32(void)
{
    random_state ^= random_state << 13u;
    random_state ^= random_state >> 17u;
    random_state ^= random_state << 5u;
    return random_state;
}

static int check(uint32_t a, uint32_t b)
{
    const uint64_t total = (uint64_t)a + (uint64_t)b;
    const int expected_ok = total <= UINT32_MAX;
    uint32_t actual = UINT32_C(0xA55AA55A);
    const int actual_ok = pc_size_add_checked_u32(a, b, &actual);
    if (actual_ok != expected_ok) return 1;
    if (expected_ok) return actual == (uint32_t)total ? 0 : 2;
    return actual == UINT32_C(0xA55AA55A) ? 0 : 3;
}

int main(void)
{
    uint32_t a, b, i;
    const uint32_t edges[] = {0u, 1u, UINT32_C(0x7FFFFFFF),
                              UINT32_C(0x80000000), UINT32_MAX - 1u, UINT32_MAX};
    const uint32_t edge_count = (uint32_t)(sizeof(edges) / sizeof(edges[0]));
    uint32_t checks = 0u;
    for (a = 0u; a <= UINT32_C(255); ++a) {
        for (b = 0u; b <= UINT32_C(255); ++b) {
            if (check(a, b) != 0) return 1;
            ++checks;
        }
    }
    for (i = 0u; i < edge_count; ++i) {
        uint32_t j;
        for (j = 0u; j < edge_count; ++j) {
            if (check(edges[i], edges[j]) != 0) return 2;
            ++checks;
        }
    }
    for (i = 0u; i < UINT32_C(1000000); ++i) {
        a = next_u32();
        b = next_u32();
        if (check(a, b) != 0) return 3;
        ++checks;
    }
    {
        uint32_t sentinel = UINT32_C(0x13579BDF);
        uint32_t aliased = UINT32_MAX - 1u;
        if (pc_size_add_checked_u32(1u, 2u, NULL)) return 4;
        if (sentinel != UINT32_C(0x13579BDF)) return 5;
        if (!pc_size_add_checked_u32(aliased, 1u, &aliased) || aliased != UINT32_MAX) return 6;
        aliased = UINT32_MAX;
        if (pc_size_add_checked_u32(aliased, 1u, &aliased) || aliased != UINT32_MAX) return 7;
    }
    return checks == UINT32_C(1065572) ? 0 : 8;
}
