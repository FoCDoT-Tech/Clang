# 3.4 Constants

## Overview

Constants are values that cannot be changed during program execution. C provides several ways to define constants.

## Literal Constants

### Integer Literals
```c
42          // Decimal
052         // Octal (starts with 0)
0x2A        // Hexadecimal (starts with 0x)
42L         // Long integer
42U         // Unsigned integer
42UL        // Unsigned long
```

### Floating-point Literals
```c
3.14        // Double (default)
3.14f       // Float
3.14L       // Long double
1.5e10      // Scientific notation
```

### Character Literals
```c
'A'         // Single character
'\n'        // Escape sequence
'\0'        // Null character
'\x41'      // Hexadecimal character (A)
```

### String Literals
```c
"Hello"     // String constant
"Line 1\n"  // String with escape sequence
""          // Empty string
```

## const Keyword

### Basic Usage
```c
const int MAX_SIZE = 100;       // Cannot be modified
const float PI = 3.14159f;      // Read-only variable
```

### const with Pointers
```c
const int *ptr1;                // Pointer to constant int
int * const ptr2;               // Constant pointer to int
const int * const ptr3;         // Constant pointer to constant int
```

## #define Preprocessor

### Macro Constants
```c
#define MAX_STUDENTS 50         // Replaced before compilation
#define PI_VALUE 3.14159        // No memory allocation
#define GREETING "Hello World"  // String constant
```

### Function-like Macros
```c
#define SQUARE(x) ((x) * (x))   // Macro with parameter
#define MAX(a,b) ((a) > (b) ? (a) : (b))
```

## enum Enumeration

### Basic Enumeration
```c
enum Color {
    RED,        // 0
    GREEN,      // 1
    BLUE        // 2
};
```

### Custom Values
```c
enum Status {
    PENDING = 10,
    PROCESSING = 20,
    COMPLETED = 30
};
```

## Comparison

| Method | Memory | Type Safety | Scope | Debugging |
|--------|--------|-------------|-------|-----------|
| Literal | No | Yes | - | Good |
| const | Yes | Yes | Block/Global | Excellent |
| #define | No | No | Global | Poor |
| enum | No | Yes | Block/Global | Good |

## Best Practices

1. **Use `const` for type-safe constants**
2. **Use `#define` for conditional compilation**
3. **Use `enum` for related constant groups**
4. **Use UPPER_CASE for macro constants**
5. **Prefer `const` over `#define` when possible**

## Code Example

The [`constants_demo.c`](constants_demo.c) demonstrates all types of constants and their usage.

**Run the code:**
```bash
gcc constants_demo.c -o constants_demo && ./constants_demo
```
