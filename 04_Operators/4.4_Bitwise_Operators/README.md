# 4.4 Bitwise Operators

Bitwise operators work on individual bits of integer values, enabling low-level manipulation and efficient operations.

## Bitwise Operators

### Binary Bitwise Operators
- `&` Bitwise AND
- `|` Bitwise OR  
- `^` Bitwise XOR (exclusive OR)
- `<<` Left shift
- `>>` Right shift

### Unary Bitwise Operator
- `~` Bitwise NOT (complement)

## Key Concepts

### Bit Representation
```c
unsigned char a = 5;   // Binary: 00000101
unsigned char b = 3;   // Binary: 00000011
```

### Common Use Cases
- **Flags and masks**: Store multiple boolean values in one integer
- **Performance**: Bitwise operations are very fast
- **Memory optimization**: Pack data efficiently
- **Hardware control**: Direct register manipulation

### Bitwise vs Logical
```c
// Logical operators (&&, ||, !) work on truth values
// Bitwise operators (&, |, ^, ~) work on individual bits
int a = 5, b = 3;
printf("%d\n", a && b);  // 1 (both non-zero)
printf("%d\n", a & b);   // 1 (101 & 011 = 001)
```

## Bit Manipulation Patterns

### Setting a bit
```c
number |= (1 << position);  // Set bit at position
```

### Clearing a bit
```c
number &= ~(1 << position); // Clear bit at position
```

### Toggling a bit
```c
number ^= (1 << position);  // Toggle bit at position
```

### Checking a bit
```c
if (number & (1 << position)) { ... }  // Check if bit is set
```

## Code Example

The [`bitwise_demo.c`](bitwise_demo.c) program demonstrates all bitwise operators with practical examples.

**Run the code:**
```bash
make run
```
