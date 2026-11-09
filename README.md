# Claudaris

Claudaris is a portable C99 library for bounded integer arithmetic, explicit
overflow handling, exact integer ratios, range operations, alignment and
time-scale calculations.

## Problem solved

Embedded firmware often needs arithmetic that cannot silently wrap, overflow,
or lose a boundary condition. Claudaris provides small stateless operations
with explicit boolean failure contracts or documented saturation semantics.

## Scope

This reference extraction contains 46 production source units from the
PrimitiveCore arithmetic family: checked and saturating arithmetic, ranges,
ratios, alignment, size validation and time conversion. The remaining family
records stay in PrimitiveCore until their source and validation evidence are
restored into independently buildable modules.

The public symbols retain their validated `pc_` names to avoid changing
numerical behavior or silently breaking existing callers.

## Architecture

The library is freestanding C99-oriented and stateless. Each operation is in a
separate source file and can be linked selectively. No heap, threads, global
state or operating-system services are required.

## Build and test

```sh
cmake -S . -B build -DCLAUDARIS_BUILD_TESTS=ON
cmake --build build --config Release
ctest --test-dir build --output-on-failure -C Release
```

## API and contracts

Public headers are in `include/claudaris/arithmetic`. Checked functions return
`false` for invalid output pointers or arithmetic overflow/underflow and leave
the output unchanged. Saturating functions clamp to the representable type
range. Ratio and time functions reject zero denominators. Exact function-level
contracts are in the public headers.

## Validation

The migrated unit tests are run independently through CTest. A representative
ESP32-S3 harness also passed 10,000 checked-add iterations plus boundary checks;
the hardware result is documented in `docs/TESTING.md`.
Footprint and cycle measurements are pending for this product and must not be
inferred from host builds.

## Origin and name

Claudaris combines the Latin-inspired ideas of *clausus* (bounded/closed) and
*clarus* (clear). The name reflects arithmetic with explicit limits and
unambiguous failure semantics. The product originates from the
PrimitiveCore `arithmetic/bounded_integer_and_overflow` family.

## License

Apache License 2.0, copyright Vanderhell. See `LICENSE` and `NOTICE`.
