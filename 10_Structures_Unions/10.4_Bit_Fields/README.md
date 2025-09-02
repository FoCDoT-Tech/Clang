# 10.4 Bit Fields

Bit fields allow packing multiple small values into a single storage unit, providing memory-efficient storage for flags and small integers.

## Bit Field Declaration

Bit fields are declared inside structures with a colon and bit count:
```c
struct Flags {
    unsigned int flag1 : 1;    // 1 bit
    unsigned int flag2 : 1;    // 1 bit
    unsigned int value : 6;    // 6 bits
};
```

## Syntax Rules

### **Basic Syntax**
```c
type field_name : width;
```

### **Valid Types**
- `int`, `unsigned int`
- `signed int` 
- `char`, `unsigned char`
- Implementation-defined for other types

### **Width Constraints**
- Width must be ≤ size of the type in bits
- Width of 0 forces alignment to next storage unit
- Unnamed fields can be used for padding

## Memory Packing

Bit fields are packed into storage units:
```c
struct PackedData {
    unsigned int a : 3;  // bits 0-2
    unsigned int b : 5;  // bits 3-7
    unsigned int c : 8;  // bits 8-15
    // Total: 16 bits (2 bytes)
};
```

## Practical Applications

### **Hardware Registers**
```c
struct StatusRegister {
    unsigned int ready    : 1;
    unsigned int error    : 1;
    unsigned int reserved : 6;
};
```

### **Protocol Headers**
```c
struct IPHeader {
    unsigned int version  : 4;
    unsigned int ihl      : 4;
    unsigned int tos      : 8;
    unsigned int length   : 16;
};
```

### **Configuration Flags**
```c
struct Config {
    unsigned int debug    : 1;
    unsigned int verbose  : 1;
    unsigned int log_level: 3;
    unsigned int unused   : 3;
};
```

## Key Concepts

### **Storage Units**
- Compiler packs fields into storage units
- Adjacent fields may share the same unit
- Implementation-defined packing order

### **Alignment**
- Zero-width fields force alignment
- Unnamed fields provide padding
- May not be addressable with `&`

### **Portability**
- Bit order is implementation-defined
- Packing behavior varies between compilers
- Use with caution in portable code

## Limitations

### **Cannot Take Address**
```c
struct Flags f;
int *ptr = &f.flag;  // ERROR: Cannot take address
```

### **No Arrays**
```c
unsigned int flags[5] : 1;  // ERROR: Invalid syntax
```

### **Limited Operations**
- Cannot use `sizeof` on bit fields
- Assignment and comparison only
- No pointer arithmetic

## Best Practices

### **Use Unsigned Types**
Prefer `unsigned int` for predictable behavior.

### **Document Bit Layout**
```c
struct Register {
    unsigned int enable : 1;  // bit 0
    unsigned int mode   : 2;  // bits 1-2
    unsigned int speed  : 5;  // bits 3-7
};
```

### **Consider Portability**
Use bit fields for space optimization, not for specific bit layouts.

## Code Example

Run the demo to see bit fields in action:
```bash
make run
```

The demo demonstrates:
- Bit field declaration and usage
- Memory packing and size comparison
- Practical applications (flags, registers, protocols)
- Bit manipulation and masking
- Portability considerations
- Performance implications
