# 7.2 Multi-dimensional Arrays

Multi-dimensional arrays store data in a table-like structure with rows and columns. They're essential for matrices, game boards, images, and any data requiring multiple indices.

## Multi-dimensional Array Concepts

### 1. **Two-dimensional Arrays**
```c
data_type array_name[rows][columns];
int matrix[3][4];        // 3 rows, 4 columns
double table[5][5];      // 5x5 square matrix
char board[8][8];        // Chess board
```

### 2. **Initialization Techniques**
```c
// Method 1: Row-by-row initialization
int matrix[3][3] = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
};

// Method 2: Linear initialization
int matrix[3][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

// Method 3: Partial initialization
int matrix[3][3] = {{1, 2}, {4}, {7, 8, 9}};
```

### 3. **Memory Layout**
- Elements stored in row-major order
- `matrix[i][j]` located at: `base + (i * columns + j) * sizeof(element)`
- Contiguous memory allocation for entire array

### 4. **Array Access**
```c
matrix[row][column] = value;    // Assignment
value = matrix[row][column];    // Access
```

## Key Concepts

### **Dimensions**
- **2D**: `array[rows][columns]` - matrices, tables
- **3D**: `array[depth][rows][columns]` - 3D grids, RGB images
- **Higher**: More dimensions for complex data structures

### **Function Parameters**
```c
// 2D array parameter - must specify column size
void process_matrix(int matrix[][COLS], int rows);
void process_matrix(int matrix[ROWS][COLS]);
```

### **Common Operations**
- **Traversal**: Nested loops for row/column access
- **Matrix arithmetic**: Addition, multiplication, transpose
- **Search**: Finding elements in 2D space
- **Initialization**: Setting values, patterns, identity matrices

## Best Practices

- Use nested loops for traversal: outer for rows, inner for columns
- Always specify all dimensions except the first in function parameters
- Use meaningful variable names: `row`, `col` instead of `i`, `j`
- Initialize arrays to avoid garbage values
- Check bounds for both dimensions

## Code Examples

Run the demo to see multi-dimensional arrays:
```bash
make run
```

The demo covers:
- 2D array declaration and initialization
- Matrix operations and traversal patterns
- 3D arrays and higher dimensions
- Practical examples: game boards, data tables
- Memory layout and access patterns
