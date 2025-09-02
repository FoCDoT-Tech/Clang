# 9.1 Memory Layout

Understanding how C programs organize memory is crucial for effective programming and debugging.

## Memory Segments

C programs divide memory into distinct segments:

### **Stack**
- Stores local variables and function parameters
- Automatic allocation/deallocation
- Limited size (typically 1-8MB)
- LIFO (Last In, First Out) structure
- Fast access

### **Heap**
- Dynamic memory allocation area
- Managed by `malloc()`, `free()`, etc.
- Larger than stack
- Manual management required
- Slower access than stack

### **Code Segment (Text)**
- Contains executable instructions
- Read-only in most systems
- Shared among processes running same program

### **Data Segment**
- **Initialized Data**: Global/static variables with initial values
- **BSS (Block Started by Symbol)**: Uninitialized global/static variables
- Zero-initialized at program start

## Memory Layout Visualization

```
High Address
+------------------+
|      Stack       | ← Grows downward
|        ↓         |
+------------------+
|                  |
|   Free Memory    |
|                  |
+------------------+
|        ↑         |
|      Heap        | ← Grows upward
+------------------+
|   BSS Segment    | ← Uninitialized data
+------------------+
|  Data Segment    | ← Initialized data
+------------------+
|  Code Segment    | ← Program instructions
+------------------+
Low Address
```

## Variable Storage Locations

### **Stack Variables**
```c
void function() {
    int local_var = 10;        // Stack
    char array[100];           // Stack
}
```

### **Heap Variables**
```c
int *ptr = malloc(sizeof(int));  // Heap allocation
```

### **Global/Static Variables**
```c
int global_var = 42;           // Data segment
static int static_var;         // BSS segment
```

## Key Concepts

### **Stack Overflow**
- Occurs when stack grows too large
- Common causes: deep recursion, large local arrays

### **Memory Fragmentation**
- Heap becomes fragmented with repeated allocations
- Can lead to allocation failures despite available memory

### **Memory Alignment**
- Data aligned to word boundaries for performance
- Compiler may add padding between structure members

## Code Example

Run the demo to see memory layout in action:
```bash
make run
```

The demo demonstrates:
- Variable addresses in different memory segments
- Stack growth direction
- Memory allocation patterns
- Address space layout
