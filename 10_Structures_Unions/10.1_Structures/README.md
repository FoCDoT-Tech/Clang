# 10.1 Structures

Structures group related data of different types into a single unit, enabling complex data modeling.

## Structure Declaration

Basic structure syntax:
```c
struct StructureName {
    data_type member1;
    data_type member2;
    // ... more members
};
```

## Structure Definition and Initialization

### **Declaration and Initialization**
```c
struct Point {
    int x;
    int y;
};

struct Point p1 = {10, 20};        // Initialize during declaration
struct Point p2 = {.x = 5, .y = 8}; // Designated initializers
```

### **Member Access**
```c
p1.x = 15;          // Dot operator for direct access
int value = p1.y;   // Reading member value
```

## Nested Structures

Structures can contain other structures:
```c
struct Address {
    char street[50];
    char city[30];
    int zipcode;
};

struct Person {
    char name[30];
    int age;
    struct Address addr;  // Nested structure
};
```

## Array of Structures

Multiple instances of the same structure:
```c
struct Student students[100];  // Array of 100 students
students[0].age = 20;         // Access individual elements
```

## Structure Assignment

Entire structures can be assigned:
```c
struct Point p1 = {10, 20};
struct Point p2 = p1;  // Copy all members
```

## Key Concepts

### **Memory Layout**
- Members stored sequentially in memory
- Padding may be added for alignment
- Total size may be larger than sum of member sizes

### **Structure vs Array**
- **Array**: Same data type, indexed access
- **Structure**: Different data types, named access

### **Initialization Rules**
- Uninitialized members default to zero
- Partial initialization allowed
- Order matters unless using designated initializers

## Best Practices

### **Meaningful Names**
```c
struct StudentRecord {    // Clear, descriptive name
    int student_id;
    char name[50];
    float gpa;
};
```

### **Consistent Naming**
- Use consistent naming conventions
- Group related data logically
- Consider memory alignment for performance

## Code Example

Run the demo to see structures in action:
```bash
make run
```

The demo demonstrates:
- Structure declaration and initialization
- Member access and modification
- Nested structures
- Arrays of structures
- Memory layout and size calculations
- Practical applications with real-world examples
