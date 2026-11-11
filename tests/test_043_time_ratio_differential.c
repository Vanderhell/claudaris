#include <stdint.h>
#include <stdio.h>
#include "pc_time_convert_ceil_u64.h"
#include "pc_time_convert_floor_u64.h"
#include "pc_time_scale_ratio_u64.h"

#define CHECK(c) do { if (!(c)) { (void)fprintf(stderr, "FAIL:%d: %s\n", __LINE__, #c); return 1; } } while (0)

#if defined(__SIZEOF_INT128__)
__extension__ typedef unsigned __int128 claudaris_test_u128;
#endif

static uint64_t rng_state = UINT64_C(0xF17A28C05B3D94E1);
static uint64_t next_u64(void)
{
    rng_state ^= rng_state << 13;
    rng_state ^= rng_state >> 7;
    rng_state ^= rng_state << 17;
    return rng_state;
}

static int check_case(uint64_t value, uint64_t numerator, uint64_t denominator)
{
    uint64_t floor_out = UINT64_C(0xA55AA55A);
    uint64_t ceil_out = UINT64_C(0xA55AA55A);
    uint64_t nearest_out = UINT64_C(0xA55AA55A);
    uint64_t quotient, remainder, ceiling, nearest;
    int floor_ok, ceil_ok, nearest_ok;

    if (denominator == 0u) denominator = 1u;
#if defined(__SIZEOF_INT128__)
    {
        claudaris_test_u128 product = (claudaris_test_u128)value * numerator;
        claudaris_test_u128 q = product / denominator;
        remainder = (uint64_t)(product % denominator);
        floor_ok = q <= UINT64_MAX;
        quotient = (uint64_t)q;
    }
#else
    /* On compilers without a wider integer, use inputs whose product is exact
       in uint64_t; separately exercise full-width edge vectors below. */
    {
        uint64_t product = value * numerator;
        quotient = product / denominator;
        remainder = product % denominator;
        floor_ok = 1;
    }
#endif
    ceiling = quotient;
    if (remainder != 0u) {
        if (ceiling == UINT64_MAX) ceil_ok = 0;
        else { ++ceiling; ceil_ok = floor_ok; }
    } else ceil_ok = floor_ok;
    nearest = quotient;
    if (remainder > denominator - remainder ||
        (remainder == denominator - remainder && (quotient & UINT64_C(1)) != 0u)) {
        if (nearest == UINT64_MAX) nearest_ok = 0;
        else { ++nearest; nearest_ok = floor_ok; }
    } else nearest_ok = floor_ok;

    CHECK(pc_time_convert_floor_u64(value, numerator, denominator, &floor_out) == floor_ok);
    if (floor_ok) CHECK(floor_out == quotient); else CHECK(floor_out == UINT64_C(0xA55AA55A));
    CHECK(pc_time_convert_ceil_u64(value, numerator, denominator, &ceil_out) == ceil_ok);
    if (ceil_ok) CHECK(ceil_out == ceiling); else CHECK(ceil_out == UINT64_C(0xA55AA55A));
    CHECK(pc_time_scale_ratio_u64(value, numerator, denominator, &nearest_out) == nearest_ok);
    if (nearest_ok) CHECK(nearest_out == nearest); else CHECK(nearest_out == UINT64_C(0xA55AA55A));
    return 0;
}

int main(void)
{
    uint32_t i;
#if defined(__SIZEOF_INT128__)
    CHECK(check_case(UINT64_MAX, UINT64_MAX, UINT64_MAX) == 0);
    CHECK(check_case(UINT64_MAX, UINT64_MAX, UINT64_MAX - 1u) == 0);
    CHECK(check_case(UINT64_MAX, UINT64_MAX, 1u) == 0);
    CHECK(check_case(UINT64_MAX, 1u, UINT64_MAX) == 0);
    CHECK(check_case(UINT64_MAX - 1u, UINT64_MAX, UINT64_MAX) == 0);
    for (i = 0u; i < 100000u; ++i) {
        uint64_t d = next_u64();
        CHECK(check_case(next_u64(), next_u64(), d == 0u ? 1u : d) == 0);
    }
#else
    CHECK(check_case(UINT64_MAX, 1u, UINT64_MAX) == 0);
    CHECK(check_case(UINT64_MAX - 1u, 1u, 2u) == 0);
    for (i = 0u; i < 100000u; ++i) {
        uint64_t v = (uint32_t)next_u64();
        uint64_t n = (uint32_t)next_u64();
        uint64_t d = (uint32_t)next_u64();
        CHECK(check_case(v, n, d == 0u ? 1u : d) == 0);
    }
#endif
    (void)puts("PASS: 3 time ratio APIs; 100000 seeded exact-reference cases");
    return 0;
}
