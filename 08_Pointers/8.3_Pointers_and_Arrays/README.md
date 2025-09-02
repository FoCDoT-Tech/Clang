# 8.3 Pointers and Arrays

Arrays and pointers are closely related in C. Understanding their relationship is crucial for effective C programming and memory manipulation.

## Array Name as Pointer

The array name acts as a pointer to the first element:

```c
int arr[5] = {10, 20, 30, 40, 50};
int *ptr = arr;        // arr is equivalent to &arr[0]
printf("%d\n", *ptr);  // Prints: 10
```

## Pointer Indexing

You can use array notation with pointers:

```c
int arr[] = {1, 2, 3, 4, 5};
int *ptr = arr;

// These are equivalent:
printf("%d\n", arr[2]);    // Array notation
printf("%d\n", ptr[2]);    // Pointer with array notation
printf("%d\n", *(ptr+2));  // Pointer arithmetic
```

## Pointer vs Array Notation

Both notations can be used interchangeably for accessing elements:

```c
int data[] = {100, 200, 300};
int *p = data;

// All equivalent ways to access second element:
data[1]     // Array subscript
*(data+1)   // Array name with pointer arithmetic
p[1]        // Pointer with subscript
*(p+1)      // Pointer arithmetic
```

## Key Differences

### **Array Name**
- Fixed address - cannot be reassigned
- Represents the entire array
- `sizeof(arr)` gives total array size

### **Pointer Variable**
- Can be reassigned to point elsewhere
- Stores address of single element
- `sizeof(ptr)` gives pointer size (8 bytes on 64-bit)

```c
int arr[5] = {1, 2, 3, 4, 5};
int *ptr = arr;

// arr = ptr;     // ERROR: Cannot assign to array name
ptr = arr + 2;    // OK: Pointer can be reassigned
```

## Multi-dimensional Arrays

Pointers work with multi-dimensional arrays through pointer arithmetic:

```c
int matrix[3][4] = {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}};
int *ptr = &matrix[0][0];  // Points to first element

// Access matrix[1][2] using pointer:
int value = *(ptr + 1*4 + 2);  // Row*columns + column
```

## Array of Pointers vs Pointer to Array

### **Array of Pointers**
```c
int *arr[3];     // Array of 3 int pointers
char *names[4];  // Array of 4 string pointers
```

### **Pointer to Array**
```c
int (*ptr)[5];   // Pointer to array of 5 integers
char (*str)[10]; // Pointer to array of 10 characters
```

## String Arrays

Arrays of strings are implemented as arrays of character pointers:

```c
char *fruits[] = {"apple", "banana", "orange"};
// fruits[0] points to "apple"
// fruits[1] points to "banana"
// fruits[2] points to "orange"
```

## Practical Applications

### **Dynamic Array Access**
```c
int arr[] = {10, 20, 30, 40, 50};
int *ptr = arr;
for (int i = 0; i < 5; i++) {
    printf("%d ", ptr[i]);  // or *(ptr + i)
}
```

### **Array Parameter in Functions**
```c
void process_array(int *arr, int size) {
    // arr is actually a pointer parameter
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
}
```

## Best Practices

- Use array notation for clarity when accessing elements
- Use pointer arithmetic for efficient array traversal
- Remember that array parameters in functions are pointers
- Be careful with bounds checking when using pointers

## Code Examples

Run the demo to see pointers and arrays in action:
```bash
make run
```

The demo covers:
- Array name as pointer equivalence
- Pointer indexing and array notation
- Multi-dimensional array access with pointers
- Array of pointers vs pointer to array
- String array manipulation
- Practical array processing techniques
