# Architecture

Claudaris is a static C99 library of checked integer arithmetic, bounded range,
alignment, ratio, rounding, and time-conversion operations. Its 46 public
functions use the `claudaris_` namespace and are grouped under
`include/claudaris/arithmetic/`. Public headers are self-contained and expose
fixed-width integer contracts.

Each public function has a dedicated implementation unit under `src/`.
Time-conversion functions share a private overflow-safe multiply/divide helper
in `src/`; it is not installed or exposed as public API. Callers own all input,
output, and state storage. The library has no mandatory runtime initialization,
heap allocation, threading, operating-system services, or third-party
dependencies.

The build exports the `Claudaris::Claudaris` CMake target. Consumers can also
compile selected implementation units directly when they need a small subset
of the library.
