# 3.1 Basic Data Types

## Overview

C provides five fundamental data types that form the building blocks for all other data structures.

## The Five Basic Types

### 1. char (Character)
- **Size**: 1 byte (8 bits)
- **Range**: -128 to 127 (signed) or 0 to 255 (unsigned)
- **Usage**: Store single characters or small integers
```c
char letter = 'A';
char digit = '5';
```

### 2. int (Integer)
- **Size**: Usually 4 bytes (32 bits) on modern systems
- **Range**: -2,147,483,648 to 2,147,483,647 (32-bit)
- **Usage**: Store whole numbers
```c
int age = 25;
int temperature = -10;
```

### 3. float (Single Precision)
- **Size**: 4 bytes (32 bits)
- **Precision**: ~7 decimal digits
- **Range**: ±3.4 × 10^±38
- **Usage**: Store decimal numbers with moderate precision
```c
float price = 19.99f;
float pi = 3.14159f;
```

### 4. double (Double Precision)
- **Size**: 8 bytes (64 bits)
- **Precision**: ~15 decimal digits
- **Range**: ±1.7 × 10^±308
- **Usage**: Store decimal numbers with high precision
```c
double precise_pi = 3.141592653589793;
double scientific = 1.23e-10;
```

### 5. void (No Value)
- **Size**: No storage
- **Usage**: Function return type, generic pointers
```c
void print_message(void);  // Function returns nothing
void *generic_ptr;         // Generic pointer
```

## Memory Layout

| Type   | Size | Alignment | Typical Range |
|--------|------|-----------|---------------|
| char   | 1    | 1         | -128 to 127   |
| int    | 4    | 4         | ±2.1 billion  |
| float  | 4    | 4         | ±3.4 × 10^38  |
| double | 8    | 8         | ±1.7 × 10^308 |

## Platform Differences

- **char**: Always 1 byte on all platforms
- **int**: Can be 2, 4, or 8 bytes depending on architecture
- **float/double**: IEEE 754 standard on most systems
- Use `sizeof()` operator to check actual sizes

## Code Example

The [`basic_types_demo.c`](basic_types_demo.c) demonstrates all basic data types with their sizes, ranges, and usage.

**Run the code:**
```bash
gcc basic_types_demo.c -o basic_types_demo && ./basic_types_demo
```
