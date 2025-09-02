# 5.2 Loops

Loops execute a block of code repeatedly until a condition is met. They are essential for repetitive tasks and data processing.

## Types of Loops

### for Loop
```c
for (initialization; condition; increment) {
    // Loop body
}
```
- Best for counter-controlled iteration
- All loop control in one line

### while Loop
```c
while (condition) {
    // Loop body
    // Update condition inside loop
}
```
- Best for condition-controlled iteration
- Pre-test loop (condition checked before execution)

### do-while Loop
```c
do {
    // Loop body
    // Update condition inside loop
} while (condition);
```
- Post-test loop (condition checked after execution)
- Executes at least once

### Nested Loops
```c
for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
        // Inner loop body
    }
}
```

## Key Concepts

### Loop Control Variables
- **Initialization**: Set starting value
- **Condition**: Test for continuation
- **Update**: Modify control variable

### Common Patterns
- **Counting**: `for (int i = 0; i < n; i++)`
- **Accumulation**: Sum, product, concatenation
- **Search**: Find specific elements
- **Validation**: Input checking

### Performance Considerations
- Minimize work inside loops
- Avoid unnecessary calculations
- Use appropriate loop type for the task

## Best Practices

1. **Initialize loop variables** properly
2. **Ensure termination** conditions are reachable
3. **Use meaningful variable names** (i, j, k for simple counters)
4. **Avoid infinite loops** with proper condition updates

## Code Example

The [`loops_demo.c`](loops_demo.c) program demonstrates all loop types with practical examples.

**Run the code:**
```bash
make run
```
