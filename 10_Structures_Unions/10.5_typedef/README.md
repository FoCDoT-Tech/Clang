# 10.5 typedef

The `typedef` keyword creates aliases for existing data types, improving code readability and maintainability.

## Basic typedef Syntax

Creating type aliases:
```c
typedef existing_type new_name;
typedef int Integer;
typedef float Real;
```

## typedef with Structures

### **Without typedef**
```c
struct Point {
    int x, y;
};
struct Point p1, p2;  // Verbose
```

### **With typedef**
```c
typedef struct Point {
    int x, y;
} Point;
Point p1, p2;  // Clean and simple
```

## Common Patterns

### **Anonymous Structures**
```c
typedef struct {
    int x, y;
} Point;  // No struct name needed
```

### **Self-Referential Structures**
```c
typedef struct Node {
    int data;
    struct Node *next;  // Must use struct Node
} Node;
```

## typedef with Pointers

Creating pointer type aliases:
```c
typedef int* IntPtr;
typedef char* String;
typedef struct Student* StudentPtr;

IntPtr ptr;     // Same as int *ptr;
String name;    // Same as char *name;
```

## typedef with Arrays

Array type aliases:
```c
typedef int Matrix[3][3];
typedef char Buffer[256];

Matrix m;       // Same as int m[3][3];
Buffer buf;     // Same as char buf[256];
```

## typedef with Function Pointers

Simplifying function pointer syntax:
```c
typedef int (*Operation)(int, int);
typedef void (*Callback)(void);

Operation add_func = &add;
Callback cleanup = &cleanup_function;
```

## Practical Applications

### **Platform Abstraction**
```c
typedef unsigned int uint32_t;
typedef unsigned char byte;
```

### **Code Clarity**
```c
typedef enum { FALSE, TRUE } Boolean;
typedef struct { float x, y; } Vector2D;
```

### **API Design**
```c
typedef struct Database DB;
typedef struct Connection Conn;
```

## Key Benefits

### **Readability**
- Shorter, more descriptive names
- Hides implementation details
- Self-documenting code

### **Maintainability**
- Change type definition in one place
- Easy to modify underlying types
- Consistent naming across codebase

### **Portability**
- Abstract platform-specific types
- Easier to adapt to different systems
- Standardized interfaces

## Best Practices

### **Naming Conventions**
```c
typedef struct point Point;      // CamelCase
typedef int error_code_t;        // snake_case with _t suffix
typedef enum color Color;        // Match your project style
```

### **Use Meaningful Names**
```c
typedef float Temperature;       // Good: descriptive
typedef float f;                 // Bad: unclear
```

### **Avoid Hiding Pointers**
```c
typedef struct Node* NodePtr;    // OK: clearly a pointer
typedef struct Node Node;        // Better: not hiding pointer nature
```

## Common Pitfalls

### **Pointer Confusion**
```c
typedef int* IntPtr;
IntPtr a, b;  // Only 'a' is pointer, 'b' is int!
```

### **Forward Declarations**
```c
typedef struct Node Node;  // Forward declaration
struct Node {
    int data;
    Node *next;  // Can use typedef name
};
```

## Code Example

Run the demo to see typedef in action:
```bash
make run
```

The demo demonstrates:
- Basic typedef usage with primitive types
- typedef with structures and unions
- Function pointer typedefs
- Array and pointer type aliases
- Practical applications and best practices
- Common pitfalls and how to avoid them
