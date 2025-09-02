# 4.5 Assignment Operators

Assignment operators assign values to variables and provide shorthand for common operations.

## Assignment Operators

### Basic Assignment
- `=` Simple assignment

### Compound Assignment (Arithmetic)
- `+=` Add and assign
- `-=` Subtract and assign
- `*=` Multiply and assign
- `/=` Divide and assign
- `%=` Modulo and assign

### Compound Assignment (Bitwise)
- `&=` Bitwise AND and assign
- `|=` Bitwise OR and assign
- `^=` Bitwise XOR and assign
- `<<=` Left shift and assign
- `>>=` Right shift and assign

## Key Concepts

### Assignment vs Equality
```c
int x = 5;    // Assignment: sets x to 5
if (x == 5)   // Equality: compares x with 5
```

### Assignment Returns Value
```c
int a, b, c;
a = b = c = 10;  // Chain assignment (right to left)
// Equivalent to: a = (b = (c = 10));
```

### Compound Assignment Benefits
```c
// Long form
array[index] = array[index] + value;

// Short form (more efficient)
array[index] += value;  // Evaluates array[index] only once
```

### Assignment Precedence
- Assignment has very low precedence
- Right-to-left associativity
- Often needs parentheses in expressions

## Common Patterns

### Accumulation
```c
sum += value;      // Add to running total
count++;           // Increment counter
```

### Bit Manipulation
```c
flags |= MASK;     // Set bits
flags &= ~MASK;    // Clear bits
flags ^= MASK;     // Toggle bits
```

### Scaling
```c
value *= 2;        // Double the value
size >>= 1;        // Halve the size (for powers of 2)
```

## Code Example

The [`assignment_demo.c`](assignment_demo.c) program demonstrates all assignment operators with practical examples.

**Run the code:**
```bash
make run
```
