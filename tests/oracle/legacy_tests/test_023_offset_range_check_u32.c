#include "pc_offset_range_check_u32.h"
#include "pc_size_add_checked_u32.h"
#include <stdint.h>

static uint32_t state = UINT32_C(0x2285C0DE);

static uint32_t next_u32(void)
{
    state ^= state << 13u;
    state ^= state >> 17u;
    state ^= state << 5u;
    return state;
}

static int check(uint32_t offset, uint32_t length, uint32_t capacity)
{
    const uint64_t endpoint = (uint64_t)offset + (uint64_t)length;
    const int expected = endpoint <= capacity;
    uint32_t end = 0u;
    const int composed = pc_size_add_checked_u32(offset, length, &end) &&
                         end <= capacity;
    if (pc_offset_range_check_u32(offset, length, capacity) != expected ||
        composed != expected) return 1;
    if (expected && capacity < UINT32_MAX &&
        !pc_offset_range_check_u32(offset, length, capacity + 1u)) return 2;
    return 0;
}

int main(void)
{
    static const uint32_t edges[] = {
        0u, 1u, 2u, UINT32_MAX - 2u, UINT32_MAX - 1u, UINT32_MAX
    };
    uint32_t offset, length, capacity, i, j, k, checks = 0u;
    for (offset = 0u; offset < 256u; ++offset) {
        for (length = 0u; length < 256u; ++length) {
            for (capacity = 0u; capacity < 256u; ++capacity) {
                if (check(offset, length, capacity) != 0) return 1;
                ++checks;
            }
        }
    }
    for (i = 0u; i < (uint32_t)(sizeof(edges) / sizeof(edges[0])); ++i) {
        for (j = 0u; j < (uint32_t)(sizeof(edges) / sizeof(edges[0])); ++j) {
            for (k = 0u; k < (uint32_t)(sizeof(edges) / sizeof(edges[0])); ++k) {
                if (check(edges[i], edges[j], edges[k]) != 0) return 2;
                ++checks;
            }
        }
    }
    for (i = 0u; i < 1000000u; ++i) {
        offset = next_u32();
        length = next_u32();
        capacity = next_u32();
        if (check(offset, length, capacity) != 0) return 3;
        ++checks;
    }
    if (!pc_offset_range_check_u32(0u, 0u, 0u)) return 4;
    if (!pc_offset_range_check_u32(UINT32_MAX, 0u, UINT32_MAX)) return 5;
    if (pc_offset_range_check_u32(UINT32_MAX, 1u, UINT32_MAX)) return 6;
    return checks == UINT32_C(17777432) ? 0 : 7;
}
