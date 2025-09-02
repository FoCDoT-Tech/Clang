# 8.2 Pointer Arithmetic

Pointer arithmetic allows you to perform mathematical operations on pointers to navigate through memory efficiently. This is fundamental for array processing and memory manipulation.

## Basic Operations

### **Increment/Decrement**
```c
int arr[] = {10, 20, 30};
int *ptr = arr;

ptr++;        // Move to next element
ptr--;        // Move to previous element
++ptr;        // Pre-increment
--ptr;        // Pre-decrement
```

### **Addition/Subtraction**
```c
int *ptr = arr;
ptr = ptr + 2;    // Move 2 elements forward
ptr = ptr - 1;    // Move 1 element backward
ptr += 3;         // Move 3 elements forward
ptr -= 2;         // Move 2 elements backward
```

## How Pointer Arithmetic Works

When you add 1 to a pointer, it doesn't add 1 byte - it adds the size of the data type:

```c
int *int_ptr;     // Adding 1 moves 4 bytes (sizeof(int))
char *char_ptr;   // Adding 1 moves 1 byte (sizeof(char))
double *dbl_ptr;  // Adding 1 moves 8 bytes (sizeof(double))
```

## Pointer Comparison

Pointers can be compared using relational operators:

```c
int arr[] = {1, 2, 3, 4, 5};
int *p1 = &arr[1];
int *p2 = &arr[3];

if (p1 < p2) {        // true - p1 points to earlier address
    printf("p1 comes before p2\n");
}
```

## Pointer Difference

The difference between two pointers gives the number of elements between them:

```c
int arr[] = {10, 20, 30, 40, 50};
int *start = &arr[1];
int *end = &arr[4];

ptrdiff_t diff = end - start;  // Result: 3 elements
```

## Key Concepts

### **Scale Factor**
- Pointer arithmetic is scaled by the size of the pointed-to type
- `ptr + 1` moves by `sizeof(*ptr)` bytes
- This makes array traversal intuitive

### **Valid Operations**
- Addition/subtraction of integers to/from pointers
- Subtraction of two pointers (same type)
- Comparison of pointers
- Assignment between compatible pointer types

### **Invalid Operations**
- Addition of two pointers
- Multiplication/division of pointers
- Arithmetic on void pointers (without casting)

## Practical Applications

### **Array Traversal**
```c
int arr[] = {1, 2, 3, 4, 5};
for (int *ptr = arr; ptr < arr + 5; ptr++) {
    printf("%d ", *ptr);
}
```

### **String Processing**
```c
char *str = "Hello";
while (*str != '\0') {
    printf("%c", *str);
    str++;
}
```

### **Memory Navigation**
```c
int matrix[3][4];
int *ptr = &matrix[0][0];
// ptr + 4 points to matrix[1][0]
// ptr + 8 points to matrix[2][0]
```

## Best Practices

- Ensure pointers stay within valid memory bounds
- Use pointer arithmetic for array processing
- Be careful with pointer types - arithmetic depends on size
- Use `ptrdiff_t` for pointer differences

## Code Examples

Run the demo to see pointer arithmetic in action:
```bash
make run
```

The demo covers:
- Increment and decrement operations
- Addition and subtraction with integers
- Pointer comparison and ordering
- Pointer difference calculations
- Practical array and string processing examples
