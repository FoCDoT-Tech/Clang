# 10.2 Pointers and Structures

Pointers to structures enable dynamic memory allocation, efficient parameter passing, and complex data structures like linked lists.

## Pointer to Structure

Declaring and using pointers to structures:
```c
struct Point {
    int x, y;
};

struct Point p = {10, 20};
struct Point *ptr = &p;
```

## Arrow Operator (`->`)

Two ways to access structure members through pointers:
```c
// Method 1: Dereference then access
(*ptr).x = 30;

// Method 2: Arrow operator (preferred)
ptr->x = 30;
ptr->y = 40;
```

## Dynamic Allocation of Structures

Allocating structures on the heap:
```c
struct Point *ptr = malloc(sizeof(struct Point));
if (ptr != NULL) {
    ptr->x = 10;
    ptr->y = 20;
    free(ptr);
}
```

## Passing Structures to Functions

### **By Value (Copy)**
```c
void print_point(struct Point p) {
    printf("(%d, %d)", p.x, p.y);
}
```

### **By Pointer (Reference)**
```c
void modify_point(struct Point *p) {
    p->x = 100;
    p->y = 200;
}
```

## Returning Pointers from Functions

Functions can return pointers to structures:
```c
struct Point* create_point(int x, int y) {
    struct Point *p = malloc(sizeof(struct Point));
    if (p != NULL) {
        p->x = x;
        p->y = y;
    }
    return p;
}
```

## Self-Referential Structures

Structures can contain pointers to themselves:
```c
struct Node {
    int data;
    struct Node *next;  // Pointer to another Node
};
```

## Key Concepts

### **Memory Efficiency**
- Passing by pointer avoids copying large structures
- Dynamic allocation allows flexible memory usage
- Pointer arithmetic works with structure arrays

### **Safety Considerations**
- Always check for NULL pointers
- Free dynamically allocated memory
- Avoid dangling pointers

### **Performance**
- Pointer access is faster for large structures
- Arrow operator is syntactic sugar for `(*ptr).member`
- Cache locality matters for structure arrays

## Best Practices

### **Always Check malloc()**
```c
struct Point *p = malloc(sizeof(struct Point));
if (p == NULL) {
    // Handle allocation failure
    return -1;
}
```

### **Initialize Pointers**
```c
struct Point *ptr = NULL;  // Good practice
```

### **Free Memory**
```c
free(ptr);
ptr = NULL;  // Prevent accidental reuse
```

## Code Example

Run the demo to see pointers and structures in action:
```bash
make run
```

The demo demonstrates:
- Pointer to structure declaration and usage
- Arrow operator vs dereference syntax
- Dynamic structure allocation
- Function parameter passing by pointer
- Self-referential structures (linked list basics)
- Memory management best practices
