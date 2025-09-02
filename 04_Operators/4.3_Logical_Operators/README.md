# 4.3 Logical Operators

Logical operators perform Boolean logic operations and are essential for decision-making in programs.

## Logical Operators

### Binary Logical Operators
- `&&` Logical AND (both conditions must be true)
- `||` Logical OR (at least one condition must be true)

### Unary Logical Operator
- `!` Logical NOT (inverts the truth value)

## Key Concepts

### Truth Values
- `0` is considered false
- Any non-zero value is considered true
- Logical operators return `1` for true, `0` for false

### Short-Circuit Evaluation
```c
// AND: if first is false, second is not evaluated
if (ptr != NULL && ptr->value > 0) { ... }

// OR: if first is true, second is not evaluated  
if (x == 0 || y/x > 10) { ... }  // Safe: division only if x != 0
```

### Common Patterns
```c
// Range checking
if (x >= 0 && x <= 100) { ... }

// Multiple conditions
if (age >= 18 && hasLicense && !isDrunk) { ... }

// Default values
result = (input != 0) ? input : defaultValue;
```

## Truth Tables

### AND (`&&`)
| A | B | A && B |
|---|---|--------|
| 0 | 0 |   0    |
| 0 | 1 |   0    |
| 1 | 0 |   0    |
| 1 | 1 |   1    |

### OR (`||`)
| A | B | A \|\| B |
|---|---|----------|
| 0 | 0 |    0     |
| 0 | 1 |    1     |
| 1 | 0 |    1     |
| 1 | 1 |    1     |

### NOT (`!`)
| A | !A |
|---|----| 
| 0 | 1  |
| 1 | 0  |

## Code Example

The [`logical_demo.c`](logical_demo.c) program demonstrates all logical operators with practical examples.

**Run the code:**
```bash
make run
```
