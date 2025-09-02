# 4.1 Arithmetic Operators

Arithmetic operators perform mathematical calculations on numeric values.

## Basic Arithmetic Operators

### Binary Operators
- `+` Addition
- `-` Subtraction  
- `*` Multiplication
- `/` Division
- `%` Modulo (remainder)

### Unary Operators
- `+` Unary plus (positive sign)
- `-` Unary minus (negative sign)

### Increment/Decrement
- `++` Increment (add 1)
- `--` Decrement (subtract 1)

## Key Concepts

### Integer vs Floating-Point Division
```c
int a = 7, b = 2;
int result = a / b;        // Result: 3 (truncated)
float fresult = a / b;     // Still 3.0 (integer division first)
float correct = (float)a / b;  // 3.5 (proper division)
```

### Modulo Operator
- Only works with integers
- Returns remainder after division
- Useful for checking even/odd, cycling values

### Pre vs Post Increment
```c
int x = 5;
int a = ++x;  // Pre-increment: x becomes 6, a gets 6
int b = x++;  // Post-increment: b gets 6, then x becomes 7
```

## Operator Precedence
1. `++`, `--` (postfix)
2. `++`, `--`, `+`, `-` (prefix/unary)
3. `*`, `/`, `%`
4. `+`, `-` (binary)

## Code Example

The [`arithmetic_demo.c`](arithmetic_demo.c) program demonstrates all arithmetic operators with practical examples.

**Run the code:**
```bash
make run
```
