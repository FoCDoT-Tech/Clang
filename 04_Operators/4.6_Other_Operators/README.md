# 4.6 Other Operators

Special operators that don't fit into the main categories but are essential for C programming.

## Special Operators

### Conditional Operator (Ternary)
- `? :` Conditional expression (ternary operator)

### Memory and Size Operators
- `sizeof` Size of data type or variable
- `&` Address-of operator
- `*` Dereference operator (indirection)

### Member Access Operators
- `.` Direct member access
- `->` Indirect member access (pointer to structure)

### Other Operators
- `()` Function call operator
- `[]` Array subscript operator
- `,` Comma operator

## Key Concepts

### Conditional Operator
```c
// Syntax: condition ? value_if_true : value_if_false
int max = (a > b) ? a : b;  // Get maximum of a and b
```

### sizeof Operator
```c
sizeof(int)        // Size of int type
sizeof(variable)   // Size of variable
sizeof(array)      // Total size of array
```

### Pointer Operators
```c
int x = 42;
int *ptr = &x;     // ptr holds address of x
int value = *ptr;  // value gets the value at address ptr
```

### Member Access
```c
struct Point p = {10, 20};
struct Point *ptr = &p;

p.x = 30;          // Direct access
ptr->y = 40;       // Indirect access (equivalent to (*ptr).y)
```

## Operator Precedence (High to Low)
1. `()` `[]` `->` `.` (postfix)
2. `sizeof` `&` `*` (unary)
3. Arithmetic operators
4. Relational operators
5. `? :` (ternary)
6. Assignment operators
7. `,` (comma)

## Code Example

The [`other_operators_demo.c`](other_operators_demo.c) program demonstrates all special operators with practical examples.

**Run the code:**
```bash
make run
```
