# 12.2 Macros

Macros provide text replacement and code generation capabilities, enabling powerful metaprogramming techniques in C.

## Object-like Macros

### **Simple Constants**
```c
#define PI 3.14159
#define MAX_SIZE 100
#define TRUE 1
#define FALSE 0
```

### **String Literals**
```c
#define VERSION "1.0.0"
#define AUTHOR "Developer Name"
#define COPYRIGHT "Copyright 2024"
```

### **Complex Expressions**
```c
#define BUFFER_SIZE (1024 * 4)
#define MAX_USERS (100 + 50)
#define DEFAULT_CONFIG {0, 1, "default"}
```

## Function-like Macros

### **Basic Function Macros**
```c
#define SQUARE(x) ((x) * (x))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
```

### **Multi-statement Macros**
```c
#define SWAP(a, b) do { \
    typeof(a) temp = (a); \
    (a) = (b); \
    (b) = temp; \
} while(0)
```

### **Variadic Macros**
```c
#define DEBUG_PRINT(fmt, ...) printf("[DEBUG] " fmt "\n", ##__VA_ARGS__)
#define LOG(level, ...) fprintf(stderr, "[%s] ", level); fprintf(stderr, __VA_ARGS__)
```

## Macro Parameters

### **Parameter Substitution**
```c
#define MULTIPLY(x, y) ((x) * (y))
// MULTIPLY(3, 4) becomes ((3) * (4))
```

### **Side Effects**
```c
// Dangerous - evaluates arguments multiple times
#define BAD_MAX(a, b) ((a) > (b) ? (a) : (b))

// Better - use inline functions for complex operations
static inline int safe_max(int a, int b) {
    return (a > b) ? a : b;
}
```

## Stringizing (#)

### **Converting to String**
```c
#define STRINGIFY(x) #x
#define TOSTRING(x) STRINGIFY(x)

#define VERSION_MAJOR 1
#define VERSION_MINOR 2
// TOSTRING(VERSION_MAJOR) becomes "1"
```

### **Debugging Macros**
```c
#define PRINT_VAR(var) printf(#var " = %d\n", var)
// PRINT_VAR(count) becomes printf("count" " = %d\n", count)
```

## Token Pasting (##)

### **Concatenating Tokens**
```c
#define CONCAT(a, b) a##b
#define MAKE_FUNCTION(name) void func_##name(void)

MAKE_FUNCTION(init);  // Becomes: void func_init(void)
```

### **Variable Generation**
```c
#define DECLARE_VAR(type, name, num) type name##num
DECLARE_VAR(int, var, 1);  // Becomes: int var1;
```

## Advanced Macro Techniques

### **X-Macros**
```c
#define COLOR_LIST \
    X(RED, 0xFF0000) \
    X(GREEN, 0x00FF00) \
    X(BLUE, 0x0000FF)

// Generate enum
typedef enum {
#define X(name, value) COLOR_##name,
    COLOR_LIST
#undef X
} color_t;

// Generate array
static const int color_values[] = {
#define X(name, value) value,
    COLOR_LIST
#undef X
};
```

### **Macro Overloading**
```c
#define GET_MACRO(_1, _2, _3, NAME, ...) NAME
#define PRINT(...) GET_MACRO(__VA_ARGS__, PRINT3, PRINT2, PRINT1)(__VA_ARGS__)

#define PRINT1(a) printf("%d\n", a)
#define PRINT2(a, b) printf("%d %d\n", a, b)
#define PRINT3(a, b, c) printf("%d %d %d\n", a, b, c)
```

## Best Practices

### **Parentheses Usage**
```c
// Always parenthesize parameters and entire expression
#define GOOD_MACRO(x) ((x) * 2 + 1)
#define BAD_MACRO(x) x * 2 + 1  // Dangerous
```

### **Multi-line Macros**
```c
// Use do-while(0) for multi-statement macros
#define SAFE_FREE(ptr) do { \
    if (ptr) { \
        free(ptr); \
        (ptr) = NULL; \
    } \
} while(0)
```

### **Naming Conventions**
```c
// Use UPPERCASE for macros
#define MAX_BUFFER_SIZE 1024
#define CALCULATE_AREA(r) (PI * (r) * (r))
```

### **Avoiding Side Effects**
```c
// Prefer inline functions for complex operations
static inline int max_safe(int a, int b) {
    return (a > b) ? a : b;
}
```

## Common Pitfalls

### **Multiple Evaluation**
```c
#define BAD_INCREMENT(x) (++(x))
int i = 5;
int result = BAD_INCREMENT(i) + BAD_INCREMENT(i);  // i incremented twice
```

### **Operator Precedence**
```c
#define BAD_MULTIPLY(x, y) x * y
// BAD_MULTIPLY(2 + 3, 4) becomes 2 + 3 * 4 = 14 (not 20)

#define GOOD_MULTIPLY(x, y) ((x) * (y))
// GOOD_MULTIPLY(2 + 3, 4) becomes ((2 + 3) * (4)) = 20
```

### **Semicolon Issues**
```c
// Wrong - creates empty statement
#define BAD_MACRO(x) printf("%d\n", x);

// Right - no semicolon in macro
#define GOOD_MACRO(x) printf("%d\n", x)
```

## Code Example

Run the demo to see advanced macro techniques:
```bash
make run
```

The demo demonstrates:
- Object-like and function-like macro definitions
- Macro parameters and substitution
- Stringizing and token pasting operations
- Variadic macros with variable arguments
- Advanced techniques like X-macros
- Common pitfalls and how to avoid them
