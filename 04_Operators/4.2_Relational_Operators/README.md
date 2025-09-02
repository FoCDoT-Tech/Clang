# 4.2 Relational Operators

Relational operators compare two values and return either 1 (true) or 0 (false).

## Comparison Operators

### Inequality Operators
- `<` Less than
- `>` Greater than
- `<=` Less than or equal to
- `>=` Greater than or equal to

### Equality Operators
- `==` Equal to
- `!=` Not equal to

## Key Concepts

### Return Values
- All relational operators return `int` values
- `1` represents true
- `0` represents false

### Common Mistakes
```c
// Wrong: assignment instead of comparison
if (x = 5) { ... }    // Assigns 5 to x, always true

// Correct: comparison
if (x == 5) { ... }   // Compares x with 5
```

### Floating-Point Comparisons
```c
// Dangerous: exact equality with floats
if (0.1 + 0.2 == 0.3) { ... }  // May fail due to precision

// Better: tolerance-based comparison
if (fabs((0.1 + 0.2) - 0.3) < 0.0001) { ... }
```

### Chaining Comparisons
```c
// Wrong: doesn't work as expected
if (1 < x < 10) { ... }  // Always true if x exists

// Correct: use logical operators
if (x > 1 && x < 10) { ... }
```

## Operator Precedence
1. `<`, `>`, `<=`, `>=` (higher precedence)
2. `==`, `!=` (lower precedence)

## Code Example

The [`relational_demo.c`](relational_demo.c) program demonstrates all relational operators with practical examples.

**Run the code:**
```bash
make run
```
