# 9.3 Memory Leaks & Debugging

Memory leaks occur when allocated memory is not properly freed, leading to wasted memory and potential program crashes.

## Common Memory Errors

### **Memory Leaks**
Allocated memory never freed:
```c
void leak_example() {
    int *ptr = malloc(sizeof(int));
    // Missing free(ptr) - MEMORY LEAK
}
```

### **Double Free**
Freeing same memory twice:
```c
free(ptr);
free(ptr);  // ERROR: Double free
```

### **Use After Free**
Accessing freed memory:
```c
free(ptr);
*ptr = 10;  // ERROR: Use after free
```

### **Buffer Overflow**
Writing beyond allocated memory:
```c
int *arr = malloc(5 * sizeof(int));
arr[10] = 42;  // ERROR: Buffer overflow
```

### **Uninitialized Memory**
Reading uninitialized memory:
```c
int *ptr = malloc(sizeof(int));
printf("%d", *ptr);  // ERROR: Reading garbage
```

## Detection Techniques

### **Static Analysis**
- Compiler warnings (`-Wall -Wextra`)
- Static analysis tools (Clang Static Analyzer)
- Code review and manual inspection

### **Runtime Detection**
- Valgrind (Linux/macOS)
- AddressSanitizer (`-fsanitize=address`)
- Custom debugging malloc implementations

### **Manual Debugging**
- Print statements for allocation/deallocation
- Memory usage tracking
- Systematic code review

## Valgrind Usage

### **Basic Commands**
```bash
# Compile with debug info
gcc -g -o program program.c

# Run with Valgrind
valgrind --leak-check=full ./program
valgrind --tool=memcheck ./program
```

### **Common Valgrind Output**
```
==12345== HEAP SUMMARY:
==12345==     in use at exit: 40 bytes in 1 blocks
==12345==   total heap usage: 2 allocs, 1 frees, 1,064 bytes allocated
==12345== 
==12345== 40 bytes in 1 blocks are definitely lost
```

## AddressSanitizer

### **Compilation**
```bash
gcc -fsanitize=address -g -o program program.c
./program
```

### **Benefits**
- Fast runtime detection
- Detailed error reports
- Stack trace information
- Built into GCC/Clang

## Prevention Strategies

### **RAII Pattern (Resource Acquisition Is Initialization)**
```c
typedef struct {
    int *data;
    size_t size;
} SafeArray;

SafeArray* create_array(size_t size) {
    SafeArray *arr = malloc(sizeof(SafeArray));
    if (arr) {
        arr->data = malloc(size * sizeof(int));
        arr->size = arr->data ? size : 0;
    }
    return arr;
}

void destroy_array(SafeArray *arr) {
    if (arr) {
        free(arr->data);
        free(arr);
    }
}
```

### **Defensive Programming**
```c
void safe_free(void **ptr) {
    if (ptr && *ptr) {
        free(*ptr);
        *ptr = NULL;
    }
}

// Usage: safe_free((void**)&my_ptr);
```

### **Memory Pools**
Pre-allocate large blocks and manage sub-allocations manually.

## Best Practices

### **Always Initialize Pointers**
```c
int *ptr = NULL;  // Good practice
```

### **Check All Allocations**
```c
ptr = malloc(size);
if (!ptr) {
    // Handle allocation failure
    return ERROR_CODE;
}
```

### **Free in Reverse Order**
Free nested structures from innermost to outermost.

### **Use Static Analysis Tools**
- Enable all compiler warnings
- Use tools like Valgrind, AddressSanitizer
- Regular code reviews

### **Test with Different Scenarios**
- Test with large allocations
- Test allocation failures
- Test edge cases

## Code Example

Run the demo to see memory debugging techniques:
```bash
make run
```

The demo demonstrates:
- Common memory error patterns
- Detection techniques
- Debugging strategies
- Prevention methods
- Safe memory management patterns
