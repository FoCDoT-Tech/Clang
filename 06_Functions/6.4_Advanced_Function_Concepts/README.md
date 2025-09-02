# 6.4 Advanced Function Concepts

Advanced function concepts enable powerful programming patterns including recursion, function pointers, callbacks, and variable arguments. These techniques provide flexibility and elegance for complex problems.

## Advanced Concepts

### 1. **Recursive Functions**
- Functions that call themselves
- Must have base case to prevent infinite recursion
- Useful for problems with self-similar subproblems
- Examples: factorial, Fibonacci, tree traversal

### 2. **Function Pointers**
- Variables that store addresses of functions
- Enable dynamic function calls at runtime
- Useful for callbacks, function tables, and polymorphism
- Syntax: `return_type (*pointer_name)(parameters)`

### 3. **Callback Functions**
- Functions passed as arguments to other functions
- Called back by the receiving function when needed
- Enable customizable behavior and event handling
- Common in sorting, filtering, and event systems

### 4. **Variable Arguments (Variadic Functions)**
- Functions accepting variable number of arguments
- Use `stdarg.h` library (`va_list`, `va_start`, `va_arg`, `va_end`)
- Examples: `printf()`, `scanf()`, custom logging functions
- First parameter must indicate argument count or type

## Key Concepts

### **Recursion Requirements**
- **Base Case**: Condition to stop recursion
- **Recursive Case**: Function calls itself with modified parameters
- **Progress**: Each call must move toward base case

### **Function Pointer Syntax**
```c
// Declaration
int (*func_ptr)(int, int);

// Assignment
func_ptr = &add_function;

// Call
result = func_ptr(5, 3);
```

### **Variadic Function Pattern**
```c
#include <stdarg.h>

int sum(int count, ...) {
    va_list args;
    va_start(args, count);
    // Process arguments
    va_end(args);
}
```

## Best Practices

- **Recursion**: Always ensure base case is reachable
- **Function Pointers**: Check for NULL before calling
- **Callbacks**: Document expected function signature
- **Variadic**: Provide way to determine argument count/types
- **Memory**: Be careful with stack overflow in deep recursion

## Code Examples

Run the demo to see advanced function concepts:
```bash
make run
```

The demo covers:
- Recursive algorithms (factorial, Fibonacci, tree operations)
- Function pointers and function tables
- Callback functions for sorting and filtering
- Variable argument functions for flexible APIs
- Practical examples combining multiple concepts
