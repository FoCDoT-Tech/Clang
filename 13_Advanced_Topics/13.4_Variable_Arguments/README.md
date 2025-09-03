# 13.4 Variable Arguments

Functions that accept a variable number of arguments using `stdarg.h` for flexible APIs.

## Basic Variadic Functions

### **stdarg.h Macros**
```c
#include <stdarg.h>

// va_list: type to hold argument information
// va_start(ap, last): initialize argument list
// va_arg(ap, type): retrieve next argument of specified type
// va_end(ap): cleanup argument list
```

### **Simple Variadic Function**
```c
#include <stdarg.h>

int sum_integers(int count, ...) {
    va_list args;
    va_start(args, count);
    
    int total = 0;
    for (int i = 0; i < count; i++) {
        total += va_arg(args, int);
    }
    
    va_end(args);
    return total;
}

// Usage
int result = sum_integers(4, 10, 20, 30, 40);  // 100
```

### **String Formatting Function**
```c
#include <stdio.h>
#include <stdarg.h>

void debug_printf(const char* format, ...) {
    printf("[DEBUG] ");
    
    va_list args;
    va_start(args, format);
    vprintf(format, args);  // Use vprintf for va_list
    va_end(args);
    
    printf("\n");
}

// Usage
debug_printf("Value: %d, Name: %s", 42, "test");
```

## Advanced Variadic Patterns

### **Type-Safe Variadic Functions**
```c
typedef enum {
    ARG_INT,
    ARG_DOUBLE,
    ARG_STRING,
    ARG_END
} ArgType;

void print_args(ArgType type, ...) {
    va_list args;
    va_start(args, type);
    
    while (type != ARG_END) {
        switch (type) {
            case ARG_INT:
                printf("Integer: %d\n", va_arg(args, int));
                break;
            case ARG_DOUBLE:
                printf("Double: %.2f\n", va_arg(args, double));
                break;
            case ARG_STRING:
                printf("String: %s\n", va_arg(args, char*));
                break;
            case ARG_END:
                break;
        }
        type = va_arg(args, ArgType);
    }
    
    va_end(args);
}

// Usage
print_args(ARG_INT, 42, 
           ARG_STRING, "Hello", 
           ARG_DOUBLE, 3.14, 
           ARG_END);
```

### **Generic Container Functions**
```c
typedef struct {
    void** items;
    size_t count;
    size_t capacity;
} GenericList;

GenericList* create_list(size_t count, ...) {
    GenericList* list = malloc(sizeof(GenericList));
    list->items = malloc(count * sizeof(void*));
    list->count = count;
    list->capacity = count;
    
    va_list args;
    va_start(args, count);
    
    for (size_t i = 0; i < count; i++) {
        list->items[i] = va_arg(args, void*);
    }
    
    va_end(args);
    return list;
}

// Usage
int a = 1, b = 2, c = 3;
GenericList* list = create_list(3, &a, &b, &c);
```

## String Processing with Variadic Functions

### **Custom sprintf Implementation**
```c
#include <stdarg.h>
#include <string.h>

int my_sprintf(char* buffer, const char* format, ...) {
    va_list args;
    va_start(args, format);
    
    int result = vsprintf(buffer, format, args);
    
    va_end(args);
    return result;
}

// Safe version with buffer size
int my_snprintf(char* buffer, size_t size, const char* format, ...) {
    va_list args;
    va_start(args, format);
    
    int result = vsnprintf(buffer, size, format, args);
    
    va_end(args);
    return result;
}
```

### **String Concatenation**
```c
char* concat_strings(int count, ...) {
    va_list args;
    va_start(args, count);
    
    // Calculate total length
    size_t total_len = 0;
    va_list args_copy;
    va_copy(args_copy, args);  // Copy va_list for second pass
    
    for (int i = 0; i < count; i++) {
        const char* str = va_arg(args_copy, const char*);
        total_len += strlen(str);
    }
    va_end(args_copy);
    
    // Allocate and concatenate
    char* result = malloc(total_len + 1);
    result[0] = '\0';
    
    for (int i = 0; i < count; i++) {
        const char* str = va_arg(args, const char*);
        strcat(result, str);
    }
    
    va_end(args);
    return result;
}

// Usage
char* combined = concat_strings(3, "Hello", " ", "World");
```

## Mathematical Operations

### **Statistical Functions**
```c
double average(int count, ...) {
    if (count == 0) return 0.0;
    
    va_list args;
    va_start(args, count);
    
    double sum = 0.0;
    for (int i = 0; i < count; i++) {
        sum += va_arg(args, double);
    }
    
    va_end(args);
    return sum / count;
}

double max_value(int count, ...) {
    if (count == 0) return 0.0;
    
    va_list args;
    va_start(args, count);
    
    double max = va_arg(args, double);
    for (int i = 1; i < count; i++) {
        double val = va_arg(args, double);
        if (val > max) max = val;
    }
    
    va_end(args);
    return max;
}

// Usage
double avg = average(4, 1.0, 2.0, 3.0, 4.0);  // 2.5
double max = max_value(3, 5.5, 2.1, 8.3);     // 8.3
```

### **Matrix Operations**
```c
typedef struct {
    double* data;
    int rows, cols;
} Matrix;

Matrix* create_matrix_from_values(int rows, int cols, ...) {
    Matrix* matrix = malloc(sizeof(Matrix));
    matrix->rows = rows;
    matrix->cols = cols;
    matrix->data = malloc(rows * cols * sizeof(double));
    
    va_list args;
    va_start(args, cols);
    
    for (int i = 0; i < rows * cols; i++) {
        matrix->data[i] = va_arg(args, double);
    }
    
    va_end(args);
    return matrix;
}

// Usage
Matrix* m = create_matrix_from_values(2, 2, 
                                     1.0, 2.0,
                                     3.0, 4.0);
```

## Logging and Debugging

### **Multi-Level Logger**
```c
typedef enum {
    LOG_DEBUG,
    LOG_INFO,
    LOG_WARNING,
    LOG_ERROR
} LogLevel;

void log_message(LogLevel level, const char* format, ...) {
    const char* level_names[] = {"DEBUG", "INFO", "WARN", "ERROR"};
    
    printf("[%s] ", level_names[level]);
    
    va_list args;
    va_start(args, format);
    vprintf(format, args);
    va_end(args);
    
    printf("\n");
}

// Usage
log_message(LOG_INFO, "Server started on port %d", 8080);
log_message(LOG_ERROR, "Failed to connect to %s:%d", "localhost", 3306);
```

### **Assertion with Custom Messages**
```c
void assert_with_message(int condition, const char* format, ...) {
    if (!condition) {
        printf("Assertion failed: ");
        
        va_list args;
        va_start(args, format);
        vprintf(format, args);
        va_end(args);
        
        printf("\n");
        abort();
    }
}

// Usage
assert_with_message(ptr != NULL, "Pointer %p should not be NULL", ptr);
assert_with_message(size > 0, "Size %d must be positive", size);
```

## Function Pointer Arrays with Variadic Functions

### **Command Dispatcher**
```c
typedef void (*CommandFunc)(const char* format, ...);

void cmd_print(const char* format, ...) {
    va_list args;
    va_start(args, format);
    vprintf(format, args);
    va_end(args);
    printf("\n");
}

void cmd_error(const char* format, ...) {
    printf("ERROR: ");
    va_list args;
    va_start(args, format);
    vprintf(format, args);
    va_end(args);
    printf("\n");
}

typedef struct {
    const char* name;
    CommandFunc func;
} Command;

Command commands[] = {
    {"print", cmd_print},
    {"error", cmd_error},
    {NULL, NULL}
};

void execute_command(const char* cmd_name, const char* format, ...) {
    for (int i = 0; commands[i].name; i++) {
        if (strcmp(commands[i].name, cmd_name) == 0) {
            va_list args;
            va_start(args, format);
            
            // Forward variadic arguments
            commands[i].func(format, args);
            
            va_end(args);
            return;
        }
    }
    printf("Unknown command: %s\n", cmd_name);
}
```

## Error Handling and Safety

### **Safe Variadic Functions**
```c
typedef enum {
    VARARG_SUCCESS,
    VARARG_NULL_POINTER,
    VARARG_INVALID_COUNT,
    VARARG_MEMORY_ERROR
} VarArgResult;

VarArgResult safe_sum(double* result, int count, ...) {
    if (result == NULL) return VARARG_NULL_POINTER;
    if (count < 0) return VARARG_INVALID_COUNT;
    
    *result = 0.0;
    
    if (count == 0) return VARARG_SUCCESS;
    
    va_list args;
    va_start(args, count);
    
    for (int i = 0; i < count; i++) {
        *result += va_arg(args, double);
    }
    
    va_end(args);
    return VARARG_SUCCESS;
}

// Usage with error checking
double sum;
VarArgResult res = safe_sum(&sum, 3, 1.0, 2.0, 3.0);
if (res == VARARG_SUCCESS) {
    printf("Sum: %.2f\n", sum);
} else {
    printf("Error: %d\n", res);
}
```

### **Type Validation**
```c
#include <stdint.h>

// Sentinel-based validation
#define MAGIC_SENTINEL 0xDEADBEEF

int validated_sum(uint32_t sentinel, int count, ...) {
    if (sentinel != MAGIC_SENTINEL) {
        fprintf(stderr, "Invalid sentinel value\n");
        return -1;
    }
    
    va_list args;
    va_start(args, count);
    
    int sum = 0;
    for (int i = 0; i < count; i++) {
        sum += va_arg(args, int);
    }
    
    va_end(args);
    return sum;
}

// Usage
int result = validated_sum(MAGIC_SENTINEL, 3, 10, 20, 30);
```

## Performance Considerations

### **Optimized Variadic Functions**
```c
// Inline small variadic functions
static inline int sum_2(int a, int b) {
    return a + b;
}

static inline int sum_3(int a, int b, int c) {
    return a + b + c;
}

// Use macro for common cases
#define SUM_SMALL(...) _Generic((void*)0, \
    default: sum_integers(sizeof((int[]){__VA_ARGS__})/sizeof(int), __VA_ARGS__))

// Batch processing for large argument lists
int sum_array(const int* values, size_t count) {
    int sum = 0;
    for (size_t i = 0; i < count; i++) {
        sum += values[i];
    }
    return sum;
}

int sum_large(int count, ...) {
    if (count <= 10) {
        // Use variadic for small counts
        va_list args;
        va_start(args, count);
        int sum = 0;
        for (int i = 0; i < count; i++) {
            sum += va_arg(args, int);
        }
        va_end(args);
        return sum;
    } else {
        // Copy to array for large counts
        int* temp = malloc(count * sizeof(int));
        va_list args;
        va_start(args, count);
        for (int i = 0; i < count; i++) {
            temp[i] = va_arg(args, int);
        }
        va_end(args);
        
        int result = sum_array(temp, count);
        free(temp);
        return result;
    }
}
```

## Best Practices

### **Documentation and Usage**
```c
/**
 * Creates a formatted string with multiple format specifiers
 * @param count Number of format-value pairs
 * @param ... Alternating format strings and values
 * @return Allocated string (caller must free)
 * 
 * Example: format_multiple(2, "Name: %s", "John", "Age: %d", 25)
 * Returns: "Name: John, Age: 25"
 */
char* format_multiple(int count, ...) {
    va_list args;
    va_start(args, count);
    
    size_t total_len = 0;
    char* result = malloc(1);
    result[0] = '\0';
    
    for (int i = 0; i < count; i++) {
        const char* format = va_arg(args, const char*);
        
        // Get the value based on format specifier
        char buffer[256];
        if (strstr(format, "%s")) {
            const char* str_val = va_arg(args, const char*);
            snprintf(buffer, sizeof(buffer), format, str_val);
        } else if (strstr(format, "%d")) {
            int int_val = va_arg(args, int);
            snprintf(buffer, sizeof(buffer), format, int_val);
        } else if (strstr(format, "%f")) {
            double double_val = va_arg(args, double);
            snprintf(buffer, sizeof(buffer), format, double_val);
        }
        
        size_t new_len = total_len + strlen(buffer) + 3;
        result = realloc(result, new_len);
        
        if (i > 0) strcat(result, ", ");
        strcat(result, buffer);
        total_len = strlen(result);
    }
    
    va_end(args);
    return result;
}
```

### **Memory Management**
```c
// Always pair va_start with va_end
// Use va_copy when you need to traverse arguments multiple times
// Be careful with argument types (int promotion, double for float)
// Consider using sentinel values or count parameters for safety

void safe_variadic_example(int count, ...) {
    va_list args;
    va_start(args, count);
    
    // Process arguments
    for (int i = 0; i < count; i++) {
        int value = va_arg(args, int);
        printf("%d ", value);
    }
    
    va_end(args);  // Always cleanup
}
```

## Code Example

Run the demo to see variadic functions in action:
```bash
make run
```

The demo demonstrates:
- Basic variadic function patterns
- Type-safe argument handling
- String processing and formatting
- Mathematical operations with variable arguments
- Logging and debugging utilities
- Error handling and validation
- Performance optimization techniques
