# 5.3 Jump Statements

Jump statements alter the normal flow of program execution by transferring control to different parts of the program.

## Types of Jump Statements

### 1. **break** Statement
- Exits from loops (`for`, `while`, `do-while`) or `switch` statements
- Only exits the innermost loop/switch
- Control transfers to the statement after the loop/switch

### 2. **continue** Statement  
- Skips remaining statements in current loop iteration
- Jumps to the beginning of the next iteration
- Only works inside loops (not in `switch`)

### 3. **goto** Statement
- Unconditional jump to a labeled statement
- Generally discouraged (makes code hard to follow)
- Useful for error handling and breaking out of nested loops

### 4. **return** Statement
- Exits from a function and optionally returns a value
- Can be used multiple times in a function
- `return;` for void functions, `return value;` for others

## Key Concepts

- **Loop Control**: `break` and `continue` provide fine control over loop execution
- **Function Exit**: `return` terminates function execution immediately
- **Nested Structures**: `break` only affects the innermost loop/switch
- **Error Handling**: `goto` can simplify complex error cleanup

## Best Practices

- Use `break` and `continue` for clear loop control logic
- Avoid `goto` except for error handling in complex functions
- Use multiple `return` statements for early function exits
- Label `goto` targets clearly and keep jumps minimal

## Code Examples

Run the demo to see all jump statements in action:
```bash
make run
```

The demo covers:
- Loop control with `break` and `continue`
- Switch statement `break` usage
- Function returns and early exits
- Practical `goto` usage for error handling
- Nested loop control patterns
