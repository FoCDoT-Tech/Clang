# 3.5 Type Conversion

## Overview

Type conversion is the process of converting one data type to another. C supports both implicit (automatic) and explicit (manual) conversions.

## Implicit Conversion (Automatic)

### Type Promotion
Smaller types are automatically promoted to larger types in expressions.

```c
int a = 5;
float b = 2.5f;
float result = a + b;  // 'a' promoted to float
```

### Promotion Hierarchy
```
char → short → int → long → long long → float → double → long double
```

### Assignment Conversion
```c
int i = 3.14;      // 3.14 truncated to 3
float f = 10;      // 10 converted to 10.0f
```

## Explicit Conversion (Casting)

### Cast Operator Syntax
```c
(target_type) expression
```

### Examples
```c
int a = 10, b = 3;
float result = (float)a / b;    // Cast a to float for precise division

double d = 3.14159;
int i = (int)d;                 // Truncate to 3
```

## Common Conversion Scenarios

### Integer Division
```c
int a = 7, b = 2;
int result1 = a / b;            // 3 (integer division)
float result2 = (float)a / b;   // 3.5 (floating-point division)
```

### Floating to Integer
```c
float f = 3.99f;
int i = (int)f;                 // 3 (truncation, not rounding)
```

### Character and Integer
```c
char c = 'A';
int ascii = c;                  // 65 (ASCII value)
char letter = 65;               // 'A'
```

## Conversion Rules

### Arithmetic Conversions
1. If either operand is `long double`, convert both to `long double`
2. If either operand is `double`, convert both to `double`
3. If either operand is `float`, convert both to `float`
4. Otherwise, perform integer promotions

### Integer Promotions
- `char` and `short` promoted to `int`
- `unsigned char` and `unsigned short` promoted to `int` or `unsigned int`

## Potential Issues

### Data Loss
```c
int big = 1000000;
short small = (short)big;       // May lose data if big > SHRT_MAX
```

### Sign Issues
```c
unsigned int u = 4294967295U;   // Maximum unsigned int
int s = (int)u;                 // May become -1 (implementation-dependent)
```

### Precision Loss
```c
double precise = 3.141592653589793;
float less_precise = (float)precise;  // Loses precision
```

## Best Practices

1. **Be explicit with casts** - makes intent clear
2. **Check ranges** - ensure values fit in target type
3. **Use appropriate types** - choose types that fit your data range
4. **Avoid unnecessary conversions** - they can introduce errors

## Code Example

The [`type_conversion_demo.c`](type_conversion_demo.c) demonstrates all types of conversions and potential pitfalls.

**Run the code:**
```bash
gcc type_conversion_demo.c -o type_conversion_demo && ./type_conversion_demo
```
