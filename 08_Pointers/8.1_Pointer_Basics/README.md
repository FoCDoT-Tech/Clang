# 8.1 Pointer Basics

Pointers are variables that store memory addresses of other variables. They provide direct access to memory locations and enable powerful programming techniques.

## What are Pointers?

A **pointer** is a variable that contains the memory address of another variable. Instead of storing a value directly, it stores the location where the value is stored.

```c
int x = 42;        // Regular variable storing value 42
int *ptr = &x;     // Pointer storing address of x
```

## Pointer Declaration

Pointers are declared using the `*` operator:

```c
int *ptr;          // Pointer to int
char *str;         // Pointer to char
double *dptr;      // Pointer to double
```

## Address Operator (&)

The `&` operator returns the memory address of a variable:

```c
int num = 10;
printf("Value: %d\n", num);           // Prints: 10
printf("Address: %p\n", &num);        // Prints: 0x7fff5fbff6ac (example)
```

## Dereference Operator (*)

The `*` operator accesses the value at the memory address stored in a pointer:

```c
int x = 25;
int *ptr = &x;
printf("Value via pointer: %d\n", *ptr);  // Prints: 25
*ptr = 50;         // Changes x to 50
```

## Null Pointers

A null pointer doesn't point to any valid memory location:

```c
int *ptr = NULL;   // Initialize to NULL
if (ptr != NULL) {
    // Safe to dereference
    printf("%d\n", *ptr);
}
```

## Key Concepts

### **Memory Addresses**
- Every variable has a unique memory address
- Addresses are typically displayed in hexadecimal format
- Address size depends on system architecture (32-bit vs 64-bit)

### **Pointer Size**
- All pointers have the same size regardless of data type
- Size depends on system architecture (4 bytes on 32-bit, 8 bytes on 64-bit)

### **Initialization**
- Always initialize pointers before use
- Uninitialized pointers contain garbage values
- Dereferencing uninitialized pointers causes undefined behavior

## Best Practices

- Initialize pointers to NULL when declared
- Check for NULL before dereferencing
- Set pointers to NULL after freeing memory
- Use meaningful variable names for pointers

## Code Examples

Run the demo to see pointer basics in action:
```bash
make run
```

The demo covers:
- Pointer declaration and initialization
- Address and dereference operators
- Pointer size and memory addresses
- Null pointer handling and safety checks
- Practical examples with different data types
