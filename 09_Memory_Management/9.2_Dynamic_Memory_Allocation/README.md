# 9.2 Dynamic Memory Allocation

Dynamic memory allocation allows programs to request memory at runtime from the heap.

## Core Functions

### **malloc()**
Allocates uninitialized memory block:
```c
void *malloc(size_t size);
int *ptr = malloc(sizeof(int));
int *arr = malloc(10 * sizeof(int));
```

### **calloc()**
Allocates zero-initialized memory block:
```c
void *calloc(size_t num, size_t size);
int *ptr = calloc(10, sizeof(int));  // Array of 10 zeros
```

### **realloc()**
Resizes previously allocated memory:
```c
void *realloc(void *ptr, size_t new_size);
ptr = realloc(ptr, 20 * sizeof(int));  // Resize array
```

### **free()**
Deallocates memory block:
```c
void free(void *ptr);
free(ptr);
ptr = NULL;  // Good practice
```

## Key Concepts

### **Memory Allocation Process**
1. Request memory from heap
2. Operating system finds suitable block
3. Returns pointer to allocated memory
4. Use memory through pointer
5. Free memory when done

### **malloc() vs calloc()**
- `malloc()`: Faster, uninitialized memory
- `calloc()`: Slower, zero-initialized memory
- `calloc()` also checks for overflow

### **realloc() Behavior**
- May move data to new location
- Original pointer may become invalid
- Always assign return value back to pointer
- Can be used to shrink or expand memory

## Best Practices

### **Always Check Return Values**
```c
int *ptr = malloc(sizeof(int));
if (ptr == NULL) {
    // Handle allocation failure
    return -1;
}
```

### **Free All Allocated Memory**
```c
char *buffer = malloc(100);
// Use buffer...
free(buffer);
buffer = NULL;  // Prevent accidental reuse
```

### **Avoid Double Free**
```c
free(ptr);
// free(ptr);  // ERROR: Double free
ptr = NULL;    // Safe guard
```

### **Match Allocation with Deallocation**
- Every `malloc()` needs a `free()`
- Every `calloc()` needs a `free()`
- Every successful `realloc()` needs a `free()`

## Common Patterns

### **Dynamic Arrays**
```c
int *arr = malloc(size * sizeof(int));
// Use array...
free(arr);
```

### **Dynamic Strings**
```c
char *str = malloc(length + 1);  // +1 for null terminator
strcpy(str, "Hello");
free(str);
```

### **Dynamic 2D Arrays**
```c
int **matrix = malloc(rows * sizeof(int*));
for (int i = 0; i < rows; i++) {
    matrix[i] = malloc(cols * sizeof(int));
}
// Free in reverse order
for (int i = 0; i < rows; i++) {
    free(matrix[i]);
}
free(matrix);
```

## Code Example

Run the demo to see dynamic memory allocation in action:
```bash
make run
```

The demo demonstrates:
- Basic malloc/free usage
- calloc vs malloc differences
- realloc for resizing arrays
- Dynamic string manipulation
- 2D array allocation
- Error handling patterns
