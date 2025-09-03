# 14.4 Memory Management (`stdlib.h`)

Dynamic memory allocation, conversion functions, and general utilities.

## Key Functions

### Dynamic Memory Allocation
- `malloc()` - Allocate memory block
- `calloc()` - Allocate and zero-initialize memory
- `realloc()` - Resize memory block
- `free()` - Deallocate memory

### String/Number Conversion
- `atoi()`, `atol()` - String to integer/long
- `atof()` - String to float
- `strtol()`, `strtoul()` - Advanced string to number conversion
- `strtod()` - String to double

### Random Number Generation
- `rand()` - Generate random number
- `srand()` - Seed random number generator
- `RAND_MAX` - Maximum random value

### Utility Functions
- `abs()`, `labs()` - Absolute value
- `div()`, `ldiv()` - Integer division with quotient and remainder
- `qsort()` - Quick sort array
- `bsearch()` - Binary search
- `system()` - Execute system command
- `exit()`, `abort()` - Program termination

## Code Example

**Run:** `make run`

The demo covers memory management, conversions, random numbers, and utility functions from stdlib.h.
