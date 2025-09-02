# 7.1 Arrays

Arrays store multiple elements of the same data type in contiguous memory locations. They provide efficient access to collections of data using index-based addressing.

## Array Fundamentals

### 1. **Array Declaration**
```c
data_type array_name[size];
int numbers[10];        // Array of 10 integers
double values[5];       // Array of 5 doubles
char letters[26];       // Array of 26 characters
```

### 2. **Array Initialization**
```c
int arr1[5] = {1, 2, 3, 4, 5};           // Full initialization
int arr2[5] = {1, 2};                    // Partial initialization (rest are 0)
int arr3[] = {10, 20, 30};               // Size determined by elements
int arr4[5] = {0};                       // All elements initialized to 0
```

### 3. **Array Indexing**
- Arrays use zero-based indexing: `arr[0]` to `arr[size-1]`
- Index must be within bounds: `0 <= index < size`
- No automatic bounds checking in C

### 4. **Array Memory Layout**
- Elements stored in consecutive memory locations
- `sizeof(array)` gives total bytes used
- `sizeof(array)/sizeof(array[0])` gives number of elements

## Key Concepts

### **Array Properties**
- Fixed size determined at compile time
- All elements same data type
- Efficient random access via indexing
- Name represents address of first element

### **Array Operations**
- **Access**: Read/write elements using `array[index]`
- **Traversal**: Use loops to process all elements
- **Search**: Linear or binary search algorithms
- **Sort**: Bubble sort, selection sort, etc.

### **Function Parameters**
- Arrays passed by reference (address of first element)
- Array size information lost - pass size separately
- Function receives pointer to array

## Best Practices

- Always check array bounds before access
- Initialize arrays to avoid garbage values
- Use meaningful names and consistent indexing
- Pass array size as separate parameter to functions
- Use `const` for read-only array parameters

## Code Examples

Run the demo to see arrays in action:
```bash
make run
```

The demo covers:
- Array declaration and initialization techniques
- Array indexing and bounds checking
- Array operations: search, sort, statistics
- Passing arrays to functions
- Practical examples with real-world data
