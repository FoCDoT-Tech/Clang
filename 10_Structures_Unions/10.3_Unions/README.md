# 10.3 Unions

Unions allow multiple variables to share the same memory location, providing memory-efficient data representation for mutually exclusive values.

## Union Declaration

Basic union syntax:
```c
union UnionName {
    data_type member1;
    data_type member2;
    // ... more members
};
```

## Union vs Structure

### **Structure**
- Each member has its own memory location
- All members can hold values simultaneously
- Size = sum of all member sizes (plus padding)

### **Union**
- All members share the same memory location
- Only one member can hold a value at a time
- Size = size of largest member

## Memory Sharing

All union members start at the same memory address:
```c
union Data {
    int i;
    float f;
    char str[20];
};

union Data data;
data.i = 42;        // Store integer
data.f = 3.14f;     // Overwrites integer
```

## Practical Applications

### **Type Conversion**
```c
union FloatBytes {
    float f;
    unsigned char bytes[4];
};
```

### **Variant Data Types**
```c
union Value {
    int int_val;
    float float_val;
    char* string_val;
};
```

### **Memory Optimization**
When you need to store different types but only one at a time.

## Tagged Unions

Combine union with enum to track active member:
```c
enum DataType { INT_TYPE, FLOAT_TYPE, STRING_TYPE };

struct TaggedUnion {
    enum DataType type;
    union {
        int i;
        float f;
        char* s;
    } data;
};
```

## Key Concepts

### **Memory Layout**
- All members share the same starting address
- Union size equals the largest member size
- Accessing wrong member gives undefined behavior

### **Initialization**
- Only first member can be initialized in declaration
- Use designated initializers for other members

### **Safety**
- Programmer must track which member is active
- No automatic type checking
- Reading wrong member is undefined behavior

## Best Practices

### **Use Tagged Unions**
Always track which member is currently valid.

### **Initialize Properly**
```c
union Data data = {0};  // Initialize first member
union Data data = {.f = 3.14f};  // Designated initializer
```

### **Document Usage**
Clearly document which member should be active when.

## Code Example

Run the demo to see unions in action:
```bash
make run
```

The demo demonstrates:
- Union declaration and memory sharing
- Union vs structure size comparison
- Tagged unions for safe usage
- Practical applications like type conversion
- Memory layout visualization
- Common pitfalls and safe practices
