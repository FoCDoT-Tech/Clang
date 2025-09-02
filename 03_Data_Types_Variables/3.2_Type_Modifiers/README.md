# 3.2 Type Modifiers

## Overview

Type modifiers change the properties of basic data types, allowing you to control size, sign, and storage characteristics.

## Sign Modifiers

### signed (Default)
- Can store both positive and negative values
- Default for `int`, `char` (implementation-dependent)
```c
signed int temperature = -10;  // Can be negative
signed char grade = -5;        // Range: -128 to 127
```

### unsigned
- Can only store non-negative values (0 and positive)
- Doubles the positive range
```c
unsigned int count = 4000000000U;  // No negative values
unsigned char byte = 255;          // Range: 0 to 255
```

## Size Modifiers

### short
- Smaller integer type (at least 16 bits)
- Usually 2 bytes on most systems
```c
short int small_num = 32000;
short temperature = -100;  // 'int' is optional
```

### long
- Larger integer type (at least 32 bits)
- Usually 4 or 8 bytes depending on system
```c
long int big_num = 2147483648L;
long population = 7800000000L;  // 'int' is optional
```

### long long
- Even larger integer type (at least 64 bits)
- Usually 8 bytes on most systems
```c
long long huge_num = 9223372036854775807LL;
long long file_size = 1099511627776LL;  // 1TB in bytes
```

## Modifier Combinations

### Valid Combinations
```c
unsigned short int us_num;      // 0 to 65535 (typically)
unsigned long int ul_num;       // Large positive numbers
signed long long int sll_num;   // Very large signed numbers
```

### Size Hierarchy
```
char ≤ short ≤ int ≤ long ≤ long long
```

## Platform Variations

| Type | Minimum Size | Typical 32-bit | Typical 64-bit |
|------|-------------|----------------|----------------|
| short | 16 bits | 2 bytes | 2 bytes |
| int | 16 bits | 4 bytes | 4 bytes |
| long | 32 bits | 4 bytes | 8 bytes |
| long long | 64 bits | 8 bytes | 8 bytes |

## Best Practices

1. **Use `int` for general integers** - most efficient on target platform
2. **Use `unsigned` when values are always non-negative** - counters, sizes
3. **Use `long long` for very large numbers** - file sizes, timestamps
4. **Check sizes with `sizeof()`** - don't assume sizes across platforms

## Code Example

The [`type_modifiers_demo.c`](type_modifiers_demo.c) demonstrates all type modifier combinations with their sizes and ranges.

**Run the code:**
```bash
gcc type_modifiers_demo.c -o type_modifiers_demo && ./type_modifiers_demo
```
