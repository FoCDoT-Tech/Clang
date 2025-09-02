# 6.3 Function Types

Functions can be categorized by their return types and parameter requirements. Understanding different function types helps you choose the right approach for specific programming tasks.

## Function Categories

### 1. **Void Functions**
- Return type: `void`
- Don't return any value
- Used for actions/operations without results
- Can use `return;` to exit early

### 2. **Functions Returning Values**
- Return specific data types (`int`, `double`, `char*`, etc.)
- Must use `return value;` statement
- Caller can use returned value in expressions
- Return type must match declared type

### 3. **Functions with No Parameters**
- Parameter list: `void` or empty `()`
- Don't accept any input
- Often used for initialization, cleanup, or constants
- Called without arguments: `function_name()`

### 4. **Functions with Parameters**
- Accept input through parameters
- Can have single or multiple parameters
- Parameters can be different types
- Enable function reusability with different inputs

## Return Type Categories

### **Basic Return Types**
- `int` - integers, status codes, counts
- `double`/`float` - calculations, measurements
- `char` - single characters, boolean-like values
- `char*` - strings, text processing results

### **Pointer Return Types**
- `int*`, `double*` - return addresses
- `char*` - dynamically allocated strings
- Custom type pointers

### **Special Cases**
- `void` - no return value
- `const` return types - read-only results

## Common Patterns

### **Utility Functions**
- Input validation, formatting, conversions
- Usually return processed values or status

### **Action Functions**
- Perform operations without returning data
- Print functions, file operations, initialization

### **Query Functions**
- Return information about data or system state
- Getters, checkers, calculators

## Best Practices

- Choose return type based on function purpose
- Use `void` for actions, specific types for calculations
- Return status codes for operations that can fail
- Use `const` for read-only return values
- Keep function types consistent with their purpose

## Code Examples

Run the demo to see different function types:
```bash
make run
```

The demo covers:
- Void functions for actions and operations
- Functions returning different data types
- Functions with and without parameters
- Practical examples of each function type
- Common patterns and use cases
