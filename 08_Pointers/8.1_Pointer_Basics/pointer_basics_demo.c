#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
void demonstrate_basic_pointers(void);
void demonstrate_address_operations(void);
void demonstrate_pointer_types(void);
void demonstrate_null_pointers(void);
void demonstrate_pointer_safety(void);
void demonstrate_practical_examples(void);

int main() {
    printf("=== Pointer Basics Demo ===\n\n");
    
    demonstrate_basic_pointers();
    demonstrate_address_operations();
    demonstrate_pointer_types();
    demonstrate_null_pointers();
    demonstrate_pointer_safety();
    demonstrate_practical_examples();
    
    printf("=== Demo Complete ===\n");
    return 0;
}

void demonstrate_basic_pointers(void) {
    printf("1. BASIC POINTER CONCEPTS\n");
    printf("----------------------------------------\n");
    
    // Basic variable and pointer
    int number = 42;
    int *ptr = &number;
    
    printf("Variable 'number':\n");
    printf("  Value: %d\n", number);
    printf("  Address: %p\n", (void*)&number);
    printf("  Size: %zu bytes\n\n", sizeof(number));
    
    printf("Pointer 'ptr':\n");
    printf("  Points to address: %p\n", (void*)ptr);
    printf("  Value at address: %d\n", *ptr);
    printf("  Pointer's own address: %p\n", (void*)&ptr);
    printf("  Pointer size: %zu bytes\n\n", sizeof(ptr));
    
    // Modifying value through pointer
    printf("Modifying value through pointer:\n");
    printf("  Original value: %d\n", number);
    *ptr = 100;
    printf("  After *ptr = 100: %d\n", number);
    printf("  Both 'number' and '*ptr' show: %d\n\n", *ptr);
}

void demonstrate_address_operations(void) {
    printf("2. ADDRESS OPERATIONS\n");
    printf("----------------------------------------\n");
    
    int a = 10, b = 20, c = 30;
    
    printf("Three variables in memory:\n");
    printf("  a = %d at address %p\n", a, (void*)&a);
    printf("  b = %d at address %p\n", b, (void*)&b);
    printf("  c = %d at address %p\n", c, (void*)&c);
    
    // Calculate address differences
    printf("\nAddress differences (bytes):\n");
    printf("  &b - &a = %ld\n", (char*)&b - (char*)&a);
    printf("  &c - &b = %ld\n", (char*)&c - (char*)&b);
    
    // Pointer reassignment
    int *ptr = &a;
    printf("\nPointer reassignment:\n");
    printf("  ptr points to a: *ptr = %d\n", *ptr);
    
    ptr = &b;
    printf("  ptr points to b: *ptr = %d\n", *ptr);
    
    ptr = &c;
    printf("  ptr points to c: *ptr = %d\n", *ptr);
    printf("\n");
}

void demonstrate_pointer_types(void) {
    printf("3. DIFFERENT POINTER TYPES\n");
    printf("----------------------------------------\n");
    
    // Different data types
    char ch = 'A';
    int num = 1234;
    float flt = 3.14f;
    double dbl = 2.71828;
    
    // Corresponding pointers
    char *char_ptr = &ch;
    int *int_ptr = &num;
    float *float_ptr = &flt;
    double *double_ptr = &dbl;
    
    printf("Pointer types and sizes:\n");
    printf("  char*   : %zu bytes, points to '%c' at %p\n", 
           sizeof(char_ptr), *char_ptr, (void*)char_ptr);
    printf("  int*    : %zu bytes, points to %d at %p\n", 
           sizeof(int_ptr), *int_ptr, (void*)int_ptr);
    printf("  float*  : %zu bytes, points to %.2f at %p\n", 
           sizeof(float_ptr), *float_ptr, (void*)float_ptr);
    printf("  double* : %zu bytes, points to %.5f at %p\n", 
           sizeof(double_ptr), *double_ptr, (void*)double_ptr);
    
    printf("\nAll pointers have the same size regardless of type!\n");
    
    // String pointer
    char *str = "Hello, Pointers!";
    printf("\nString pointer:\n");
    printf("  str points to: \"%s\"\n", str);
    printf("  First character: '%c'\n", *str);
    printf("  String address: %p\n", (void*)str);
    printf("\n");
}

void demonstrate_null_pointers(void) {
    printf("4. NULL POINTERS\n");
    printf("----------------------------------------\n");
    
    int *ptr1 = NULL;
    int *ptr2 = 0;      // Also NULL
    int *ptr3;          // Uninitialized (dangerous!)
    
    printf("Null pointer checks:\n");
    printf("  ptr1 = NULL: %s\n", (ptr1 == NULL) ? "true" : "false");
    printf("  ptr2 = 0: %s\n", (ptr2 == NULL) ? "true" : "false");
    printf("  ptr1 == ptr2: %s\n", (ptr1 == ptr2) ? "true" : "false");
    
    // Safe dereferencing
    printf("\nSafe pointer usage:\n");
    if (ptr1 != NULL) {
        printf("  ptr1 is safe to dereference\n");
    } else {
        printf("  ptr1 is NULL - cannot dereference safely\n");
    }
    
    // Initialize and use
    int value = 99;
    ptr1 = &value;
    
    if (ptr1 != NULL) {
        printf("  ptr1 now points to value: %d\n", *ptr1);
    }
    
    // Reset to NULL
    ptr1 = NULL;
    printf("  ptr1 reset to NULL\n\n");
}

void demonstrate_pointer_safety(void) {
    printf("5. POINTER SAFETY\n");
    printf("----------------------------------------\n");
    
    int numbers[] = {10, 20, 30, 40, 50};
    int *safe_ptr = numbers;  // Points to first element
    
    printf("Safe pointer operations:\n");
    printf("  Array: [%d, %d, %d, %d, %d]\n", 
           numbers[0], numbers[1], numbers[2], numbers[3], numbers[4]);
    
    // Safe access
    for (int i = 0; i < 5; i++) {
        printf("  numbers[%d] = %d (via pointer: %d)\n", 
               i, numbers[i], *(safe_ptr + i));
    }
    
    // Demonstrate bounds checking
    printf("\nBounds checking example:\n");
    int *ptr = numbers;
    int array_size = 5;
    
    for (int i = 0; i < array_size + 2; i++) {  // Intentionally go beyond bounds
        if (i < array_size) {
            printf("  Safe access [%d]: %d\n", i, *(ptr + i));
        } else {
            printf("  Unsafe access [%d]: Would access beyond array bounds!\n", i);
        }
    }
    
    // Common mistakes to avoid
    printf("\nCommon mistakes to avoid:\n");
    printf("  ✗ Dereferencing NULL pointers\n");
    printf("  ✗ Using uninitialized pointers\n");
    printf("  ✗ Accessing beyond array bounds\n");
    printf("  ✗ Using freed memory (dangling pointers)\n");
    printf("  ✓ Always initialize pointers\n");
    printf("  ✓ Check for NULL before dereferencing\n");
    printf("  ✓ Respect array boundaries\n");
    printf("  ✓ Set pointers to NULL after freeing\n\n");
}

void demonstrate_practical_examples(void) {
    printf("6. PRACTICAL EXAMPLES\n");
    printf("----------------------------------------\n");
    
    // Example 1: Swapping values using pointers
    printf("Example 1: Swapping values\n");
    int x = 100, y = 200;
    printf("  Before swap: x = %d, y = %d\n", x, y);
    
    // Swap using pointers
    int *px = &x, *py = &y;
    int temp = *px;
    *px = *py;
    *py = temp;
    
    printf("  After swap: x = %d, y = %d\n", x, y);
    
    // Example 2: Finding maximum using pointers
    printf("\nExample 2: Finding maximum\n");
    int a = 45, b = 67, c = 23;
    int *max_ptr = &a;
    
    if (*max_ptr < b) max_ptr = &b;
    if (*max_ptr < c) max_ptr = &c;
    
    printf("  Numbers: a=%d, b=%d, c=%d\n", a, b, c);
    printf("  Maximum: %d (at address %p)\n", *max_ptr, (void*)max_ptr);
    
    // Example 3: String manipulation
    printf("\nExample 3: String manipulation\n");
    char message[] = "Hello World";
    char *str_ptr = message;
    
    printf("  Original: \"%s\"\n", message);
    printf("  Character by character: ");
    while (*str_ptr != '\0') {
        printf("%c", *str_ptr);
        str_ptr++;
    }
    printf("\n");
    
    // Example 4: Array processing
    printf("\nExample 4: Array processing\n");
    int data[] = {5, 15, 25, 35, 45};
    int *data_ptr = data;
    int sum = 0;
    
    printf("  Array: [");
    for (int i = 0; i < 5; i++) {
        printf("%d", *(data_ptr + i));
        sum += *(data_ptr + i);
        if (i < 4) printf(", ");
    }
    printf("]\n");
    printf("  Sum using pointer arithmetic: %d\n", sum);
    printf("  Average: %.2f\n", sum / 5.0);
    
    // Example 5: Memory layout visualization
    printf("\nExample 5: Memory layout\n");
    int arr[3] = {100, 200, 300};
    printf("  Array elements and their addresses:\n");
    for (int i = 0; i < 3; i++) {
        printf("    arr[%d] = %d at address %p\n", 
               i, arr[i], (void*)&arr[i]);
    }
    
    int *p = arr;
    printf("  Pointer arithmetic:\n");
    printf("    p points to: %d at %p\n", *p, (void*)p);
    printf("    p+1 points to: %d at %p\n", *(p+1), (void*)(p+1));
    printf("    p+2 points to: %d at %p\n", *(p+2), (void*)(p+2));
    
    printf("\n  Address differences:\n");
    printf("    (p+1) - p = %ld bytes\n", (char*)(p+1) - (char*)p);
    printf("    (p+2) - (p+1) = %ld bytes\n", (char*)(p+2) - (char*)(p+1));
}
