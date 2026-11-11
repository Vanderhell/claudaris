#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include "pc_abs_diff_i64_u64.h"
#include "pc_abs_i64_safe_u64.h"
#include "pc_checked_add_u64.h"
#include "pc_checked_add_i64.h"
#include "pc_checked_mul_u64.h"
#include "pc_checked_mul_i64.h"
#include "pc_checked_sub_u64.h"
#include "pc_checked_sub_i64.h"
#include "pc_checked_shl_i32.h"
#include "pc_checked_shl_u32.h"
#include "pc_mask_range_u64.h"
#include "pc_ratio_between_u32.h"
#include "pc_ratio_ceil_u32.h"
#include "pc_ratio_round_even_u32.h"
#include "pc_saturating_add_i64.h"
#include "pc_saturating_add_u64.h"
#include "pc_saturating_mul_u64.h"
#include "pc_saturating_sub_i64.h"
#include "pc_saturating_sub_u64.h"

#define CHECK(c) do { if (!(c)) { (void)fprintf(stderr, "FAIL:%d: %s\n", __LINE__, #c); return 1; } } while (0)

#if defined(__SIZEOF_INT128__)
__extension__ typedef __int128 claudaris_test_i128;
#endif

static uint64_t rng_state = UINT64_C(0xA52C91D34B6E780F);
static uint64_t next_u64(void)
{
    rng_state ^= rng_state << 13;
    rng_state ^= rng_state >> 7;
    rng_state ^= rng_state << 17;
    return rng_state;
}

static int64_t next_i64(void)
{
    const uint64_t bits = next_u64();
    int64_t value;
    /* Construct signed values without an out-of-range unsigned conversion. */
    if (bits <= (uint64_t)INT64_MAX) return (int64_t)bits;
    value = (int64_t)(bits - (uint64_t)INT64_MAX - UINT64_C(1));
    return INT64_MIN + value;
}

static uint64_t reference_abs_i64(int64_t value)
{
    return value < 0 ? (uint64_t)(-(value + 1)) + UINT64_C(1) : (uint64_t)value;
}

static int64_t reference_sat_add_i64(int64_t a, int64_t b)
{
#if defined(__SIZEOF_INT128__)
    claudaris_test_i128 sum = (claudaris_test_i128)a + (claudaris_test_i128)b;
    if (sum > INT64_MAX) return INT64_MAX;
    if (sum < INT64_MIN) return INT64_MIN;
    return (int64_t)sum;
#else
    if (b > 0 && a > INT64_MAX - b) return INT64_MAX;
    if (b < 0 && a < INT64_MIN - b) return INT64_MIN;
    return a + b;
#endif
}

static int64_t reference_sat_sub_i64(int64_t a, int64_t b)
{
#if defined(__SIZEOF_INT128__)
    claudaris_test_i128 difference = (claudaris_test_i128)a - (claudaris_test_i128)b;
    if (difference > INT64_MAX) return INT64_MAX;
    if (difference < INT64_MIN) return INT64_MIN;
    return (int64_t)difference;
#else
    if (b < 0 && a > INT64_MAX + b) return INT64_MAX;
    if (b > 0 && a < INT64_MIN + b) return INT64_MIN;
    return a - b;
#endif
}

int main(void)
{
    static const int64_t signed_edges[] = {INT64_MIN, INT64_MIN + 1, -1, 0, 1, INT64_MAX - 1, INT64_MAX};
    uint64_t out, a, b;
    int64_t sa, sb;
    unsigned i, j;

    for (i = 0u; i < sizeof signed_edges / sizeof signed_edges[0]; ++i) {
        CHECK(pc_abs_i64_safe_u64(signed_edges[i]) == reference_abs_i64(signed_edges[i]));
        for (j = 0u; j < sizeof signed_edges / sizeof signed_edges[0]; ++j) {
            uint64_t expected = signed_edges[i] >= signed_edges[j]
                ? (uint64_t)signed_edges[i] - (uint64_t)signed_edges[j]
                : (uint64_t)signed_edges[j] - (uint64_t)signed_edges[i];
            CHECK(pc_abs_diff_i64_u64(signed_edges[i], signed_edges[j]) == expected);
            CHECK(pc_saturating_add_i64(signed_edges[i], signed_edges[j]) == reference_sat_add_i64(signed_edges[i], signed_edges[j]));
            CHECK(pc_saturating_sub_i64(signed_edges[i], signed_edges[j]) == reference_sat_sub_i64(signed_edges[i], signed_edges[j]));
        }
    }

    for (i = 0u; i < 100000u; ++i) {
        a = next_u64(); b = next_u64();
        out = UINT64_C(0xC0FFEE);
        CHECK(pc_checked_add_u64(a, b, &out) == (b <= UINT64_MAX - a));
        if (b <= UINT64_MAX - a) CHECK(out == a + b); else CHECK(out == UINT64_C(0xC0FFEE));
        out = UINT64_C(0xC0FFEE);
        CHECK(pc_checked_sub_u64(a, b, &out) == (a >= b));
        if (a >= b) CHECK(out == a - b); else CHECK(out == UINT64_C(0xC0FFEE));
        out = UINT64_C(0xC0FFEE);
        CHECK(pc_checked_mul_u64(a, b, &out) == (b == 0u || a <= UINT64_MAX / b));
        if (b == 0u || a <= UINT64_MAX / b) CHECK(out == a * b); else CHECK(out == UINT64_C(0xC0FFEE));
        CHECK(pc_saturating_add_u64(a, b) == (b > UINT64_MAX - a ? UINT64_MAX : a + b));
        CHECK(pc_saturating_sub_u64(a, b) == (a >= b ? a - b : 0u));
        CHECK(pc_saturating_mul_u64(a, b) == (b != 0u && a > UINT64_MAX / b ? UINT64_MAX : a * b));

        sa = next_i64(); sb = next_i64();
#if defined(__SIZEOF_INT128__)
        {
            claudaris_test_i128 sum = (claudaris_test_i128)sa + sb;
            claudaris_test_i128 difference = (claudaris_test_i128)sa - sb;
            claudaris_test_i128 product = (claudaris_test_i128)sa * sb;
            int add_ok = sum >= INT64_MIN && sum <= INT64_MAX;
            int sub_ok = difference >= INT64_MIN && difference <= INT64_MAX;
            int mul_ok = product >= INT64_MIN && product <= INT64_MAX;
            int64_t signed_out = INT64_C(0x12345678);
            CHECK(pc_checked_add_i64(sa, sb, &signed_out) == add_ok);
            CHECK(add_ok ? signed_out == (int64_t)sum : signed_out == INT64_C(0x12345678));
            signed_out = INT64_C(0x12345678);
            CHECK(pc_checked_sub_i64(sa, sb, &signed_out) == sub_ok);
            CHECK(sub_ok ? signed_out == (int64_t)difference : signed_out == INT64_C(0x12345678));
            signed_out = INT64_C(0x12345678);
            CHECK(pc_checked_mul_i64(sa, sb, &signed_out) == mul_ok);
            CHECK(mul_ok ? signed_out == (int64_t)product : signed_out == INT64_C(0x12345678));
        }
#else
        {
            int add_ok = sb > 0 ? sa <= INT64_MAX - sb : (sb < 0 ? sa >= INT64_MIN - sb : 1);
            int sub_ok = sb < 0 ? sa <= INT64_MAX + sb : (sb > 0 ? sa >= INT64_MIN + sb : 1);
            int mul_ok = !(sa == INT64_MIN && sb == -1) && !(sb == INT64_MIN && sa == -1);
            if (mul_ok && sa > 0) mul_ok = sb > 0 ? sa <= INT64_MAX / sb : (sb >= INT64_MIN / sa);
            else if (mul_ok && sa < 0) mul_ok = sb > 0 ? sa >= INT64_MIN / sb : (sb >= 0 || sa >= INT64_MAX / sb);
            {
                int64_t signed_out = INT64_C(0x12345678);
                CHECK(pc_checked_add_i64(sa, sb, &signed_out) == add_ok);
                CHECK(add_ok ? signed_out == sa + sb : signed_out == INT64_C(0x12345678));
                signed_out = INT64_C(0x12345678);
                CHECK(pc_checked_sub_i64(sa, sb, &signed_out) == sub_ok);
                CHECK(sub_ok ? signed_out == sa - sb : signed_out == INT64_C(0x12345678));
                signed_out = INT64_C(0x12345678);
                CHECK(pc_checked_mul_i64(sa, sb, &signed_out) == mul_ok);
                CHECK(mul_ok ? signed_out == sa * sb : signed_out == INT64_C(0x12345678));
            }
        }
#endif
        {
            const uint32_t u = (uint32_t)a;
            const uint32_t bits = (uint32_t)a;
            const int32_t s = bits <= (uint32_t)INT32_MAX
                ? (int32_t)bits
                : INT32_MIN + (int32_t)(bits - (uint32_t)INT32_MAX - 1u);
            const unsigned shift = (unsigned)(b % 36u);
            uint32_t uout = UINT32_C(0x12345678);
            int32_t sout = INT32_C(0x12345678);
            int uok = shift < 32u && (shift == 0u || u <= (UINT32_MAX >> shift));
            int64_t scaled = (int64_t)s * (INT64_C(1) << (shift < 32u ? shift : 0u));
            int sok = shift < 32u && scaled >= INT32_MIN && scaled <= INT32_MAX;
            CHECK(pc_checked_shl_u32(u, shift, &uout) == uok);
            CHECK(uok ? uout == (u << shift) : uout == UINT32_C(0x12345678));
            CHECK(pc_checked_shl_i32(s, shift, &sout) == sok);
            CHECK(sok ? sout == (int32_t)scaled : sout == INT32_C(0x12345678));
        }
        {
            const uint32_t n = (uint32_t)a, d = (uint32_t)b | 1u;
            uint32_t q = UINT32_MAX, rounded = UINT32_MAX;
            const uint32_t quotient = n / d, rem = n % d;
            const uint32_t expected_ceil = quotient + (rem != 0u);
            const uint32_t expected_even = quotient +
                ((uint64_t)rem * 2u > d || ((uint64_t)rem * 2u == d && (quotient & 1u) != 0u));
            bool between = false;
            const uint32_t ln = (uint32_t)next_u64(), ld = ((uint32_t)next_u64()) | 1u;
            const uint32_t un = (uint32_t)next_u64(), ud = ((uint32_t)next_u64()) | 1u;
            const uint64_t order_l = (uint64_t)ln * ud;
            const uint64_t order_u = (uint64_t)un * ld;
            int valid = order_l <= order_u;
            int expected_between = valid && (uint64_t)n * ld >= (uint64_t)ln * d &&
                                   (uint64_t)n * ud <= (uint64_t)un * d;
            CHECK(pc_ratio_ceil_u32(n, d, &q) && q == expected_ceil);
            CHECK(pc_ratio_round_even_u32(n, d, &rounded) && rounded == expected_even);
            CHECK(pc_ratio_between_u32(n, d, ln, ld, un, ud, &between) == valid);
            if (valid) CHECK((int)between == expected_between);
        }
        CHECK(pc_saturating_add_i64(sa, sb) == reference_sat_add_i64(sa, sb));
        CHECK(pc_saturating_sub_i64(sa, sb) == reference_sat_sub_i64(sa, sb));
        CHECK(pc_abs_i64_safe_u64(sa) == reference_abs_i64(sa));
        CHECK(pc_abs_diff_i64_u64(sa, sb) == (sa >= sb ? (uint64_t)sa - (uint64_t)sb : (uint64_t)sb - (uint64_t)sa));
    }

    for (i = 0u; i < 64u; ++i) {
        for (j = i; j < 64u; ++j) {
            uint64_t expected = (j == 63u ? UINT64_MAX : ((UINT64_C(1) << (j + 1u)) - 1u));
            expected &= i == 0u ? UINT64_MAX : (UINT64_MAX << i);
            out = 0u;
            CHECK(pc_mask_range_u64((uint8_t)i, (uint8_t)j, &out));
            CHECK(out == expected);
        }
    }
    out = UINT64_C(0x12345678);
    CHECK(!pc_mask_range_u64(64u, 64u, &out) && out == UINT64_C(0x12345678));
    CHECK(!pc_mask_range_u64(4u, 3u, &out) && out == UINT64_C(0x12345678));
    CHECK(!pc_mask_range_u64(0u, 63u, NULL));
    CHECK(!pc_checked_add_u64(UINT64_MAX, 1u, &out) && out == UINT64_C(0x12345678));
    CHECK(!pc_checked_add_u64(1u, 1u, NULL));
    CHECK(!pc_checked_sub_u64(0u, 1u, &out) && out == UINT64_C(0x12345678));
    CHECK(!pc_checked_sub_u64(1u, 1u, NULL));
    CHECK(!pc_checked_mul_u64(UINT64_MAX, 2u, &out) && out == UINT64_C(0x12345678));
    CHECK(!pc_checked_mul_u64(1u, 1u, NULL));
    (void)puts("PASS: 11 previously uncovered public APIs; 100000 deterministic arithmetic cases");
    return 0;
}
