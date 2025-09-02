# 8.4 Pointers and Functions

Pointers and functions work together to enable powerful programming techniques including pass-by-reference, dynamic function calls, and callback mechanisms.

## Passing Pointers to Functions

Functions can receive pointers as parameters to modify original variables:

```c
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int x = 10, y = 20;
swap(&x, &y);  // x becomes 20, y becomes 10
```

## Returning Pointers from Functions

Functions can return pointers to data:

```c
int* find_max(int arr[], int size) {
    int *max = &arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > *max) {
            max = &arr[i];
        }
    }
    return max;
}
```

## Function Pointers

Pointers can point to functions, enabling dynamic function calls:

```c
int add(int a, int b) { return a + b; }
int multiply(int a, int b) { return a * b; }

int (*operation)(int, int) = add;
int result = operation(5, 3);  // Calls add(5, 3)

operation = multiply;
result = operation(5, 3);      // Calls multiply(5, 3)
```

## Array Parameters

Arrays passed to functions are actually pointers:

```c
void process_array(int arr[], int size) {
    // arr is actually int *arr
    for (int i = 0; i < size; i++) {
        arr[i] *= 2;  // Modifies original array
    }
}
```

## Callback Functions

Function pointers enable callback mechanisms:

```c
void process_data(int *arr, int size, void (*callback)(int*)) {
    for (int i = 0; i < size; i++) {
        callback(&arr[i]);
    }
}

void double_value(int *x) { *x *= 2; }
void square_value(int *x) { *x *= *x; }

// Usage:
process_data(array, size, double_value);  // Doubles all elements
process_data(array, size, square_value);  // Squares all elements
```

## Key Concepts

### **Pass by Reference**
- Use pointers to allow functions to modify original variables
- Essential for functions that need to return multiple values
- More efficient for large data structures

### **Function Pointer Syntax**
```c
return_type (*pointer_name)(parameter_types)
```

### **Array Decay**
- Array names decay to pointers when passed to functions
- Size information is lost - must be passed separately
- Functions receive pointer to first element

## Common Patterns

### **Multiple Return Values**
```c
void get_min_max(int arr[], int size, int *min, int *max) {
    *min = *max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < *min) *min = arr[i];
        if (arr[i] > *max) *max = arr[i];
    }
}
```

### **Function Tables**
```c
int (*operations[])(int, int) = {add, subtract, multiply, divide};
int result = operations[choice](a, b);
```

### **Generic Processing**
```c
void apply_to_array(int *arr, int size, int (*func)(int)) {
    for (int i = 0; i < size; i++) {
        arr[i] = func(arr[i]);
    }
}
```

## Best Practices

- Always validate pointer parameters for NULL
- Use const for read-only pointer parameters
- Be careful with returning pointers to local variables
- Use function pointers for flexible, reusable code

## Code Examples

Run the demo to see pointers and functions in action:
```bash
make run
```

The demo covers:
- Passing pointers to functions for modification
- Returning pointers from functions
- Function pointer declaration and usage
- Callback function implementations
- Array processing with function pointers
- Practical applications and design patterns
