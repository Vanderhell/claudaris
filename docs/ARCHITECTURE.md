# Architecture

Claudaris is a static C99 library with one implementation unit per public
operation. Public headers contain the original `pc_` symbols and explicit
fixed-width integer contracts. The library has no required runtime
initialization, heap allocation, thread, or operating-system service.

The 46 public operations are grouped by contract:

- checked arithmetic and saturating conversion;
- exact ratios and rounding-to-multiple operations;
- bounded ranges and buffer-size validation;
- period/alignment helpers;
- unsigned time scaling with an internal overflow-safe multiply/divide helper.

The internal time-ratio helper is private to the time conversion units and is
not part of the public API. Consumers can link individual object files when
their build system uses function-level or object-level selection.
