# 8.5 Advanced Pointer Concepts

Advanced pointer concepts include multi-level pointers, arrays of pointers, pointers to arrays, and const qualifiers with pointers.

## Pointer to Pointer

A pointer can point to another pointer, creating multiple levels of indirection:

```c
int value = 42;
int *ptr = &value;      // Pointer to int
int **ptr_to_ptr = &ptr; // Pointer to pointer to int

printf("%d\n", **ptr_to_ptr);  // Prints: 42
```

## Array of Pointers

An array where each element is a pointer:

```c
int a = 10, b = 20, c = 30;
int *ptr_array[3] = {&a, &b, &c};

for (int i = 0; i < 3; i++) {
    printf("%d ", *ptr_array[i]);  // Prints: 10 20 30
}
```

## Pointer to Array

A single pointer that points to an entire array:

```c
int arr[5] = {1, 2, 3, 4, 5};
int (*ptr_to_array)[5] = &arr;

// Access elements: (*ptr_to_array)[index]
printf("%d\n", (*ptr_to_array)[2]);  // Prints: 3
```

## Const with Pointers

Four different const combinations with pointers:

### **Pointer to Constant**
```c
const int *ptr;        // Cannot modify value through pointer
int const *ptr;        // Same as above
```

### **Constant Pointer**
```c
int *const ptr = &var; // Cannot reassign pointer
```

### **Constant Pointer to Constant**
```c
const int *const ptr = &var; // Cannot modify value or reassign pointer
```

### **Pointer to Constant vs Constant Pointer**
```c
const int *p1;    // Pointer to const int
int *const p2;    // Const pointer to int
```

## Complex Pointer Declarations

Understanding complex pointer syntax:

```c
int *ptr[10];          // Array of 10 pointers to int
int (*ptr)[10];        // Pointer to array of 10 ints
int *(*ptr)[10];       // Pointer to array of 10 pointers to int
int (*ptr[10])();      // Array of 10 pointers to functions returning int
```

## Multi-dimensional Pointer Arrays

Working with complex data structures:

```c
char *names[] = {"Alice", "Bob", "Charlie"};
int *matrix_rows[3];   // Array of pointers to int arrays
```

## Key Concepts

### **Indirection Levels**
- `*ptr` - Single indirection
- `**ptr` - Double indirection  
- `***ptr` - Triple indirection (rarely used)

### **Memory Layout**
- Array of pointers: Each element can point to different memory locations
- Pointer to array: Points to contiguous memory block

### **Const Placement**
- `const` before `*`: Value cannot be modified
- `const` after `*`: Pointer cannot be reassigned

## Best Practices

- Use meaningful variable names for complex pointer types
- Prefer `typedef` for complex pointer declarations
- Initialize pointers to avoid undefined behavior
- Use const appropriately to prevent accidental modifications

## Code Examples

Run the demo to see advanced pointer concepts in action:
```bash
make run
```

The demo covers:
- Multi-level pointer indirection
- Array of pointers vs pointer to array
- Const qualifiers with pointers
- Complex pointer declarations and usage
- Practical applications of advanced pointer concepts
