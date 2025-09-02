# 5.1 Conditional Statements

Conditional statements execute different code blocks based on boolean conditions.

## Types of Conditional Statements

### Basic if Statement
```c
if (condition) {
    // Execute if condition is true
}
```

### if-else Statement
```c
if (condition) {
    // Execute if true
} else {
    // Execute if false
}
```

### else if Ladder
```c
if (condition1) {
    // Execute if condition1 is true
} else if (condition2) {
    // Execute if condition2 is true
} else {
    // Execute if all conditions are false
}
```

### switch-case Statement
```c
switch (expression) {
    case value1:
        // Execute for value1
        break;
    case value2:
        // Execute for value2
        break;
    default:
        // Execute if no case matches
}
```

## Key Concepts

### Condition Evaluation
- Any non-zero value is considered true
- Zero is considered false
- Use relational and logical operators for conditions

### Nested Conditionals
- if statements can be nested inside other if statements
- Use proper indentation for readability
- Consider using logical operators instead of deep nesting

### switch vs if-else
- **switch**: Best for multiple discrete values
- **if-else**: Best for ranges and complex conditions

## Best Practices

1. **Use braces** even for single statements
2. **Avoid deep nesting** (max 3 levels)
3. **Use switch** for multiple discrete values
4. **Handle all cases** in switch statements

## Code Example

The [`conditional_demo.c`](conditional_demo.c) program demonstrates all conditional statements with practical examples.

**Run the code:**
```bash
make run
```
