/*
 * history_demo.c - Demonstrates C's evolution and key features
 * This program shows why C became so influential in programming
 */

#include <stdio.h>
#include <stdlib.h>

int main() {
    // C's simplicity - direct memory access and control
    printf("=== C Language History Demo ===\n\n");
    
    // 1. Direct memory management (key C feature)
    int *numbers = malloc(5 * sizeof(int));  // Manual allocation
    if (numbers == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    
    // 2. Efficient loops and pointer arithmetic
    printf("Memory addresses and values:\n");
    for (int i = 0; i < 5; i++) {
        numbers[i] = (i + 1) * 10;
        printf("numbers[%d] = %d (address: %p)\n", 
               i, numbers[i], (void*)&numbers[i]);
    }
    
    // 3. System-level programming capabilities
    printf("\nSystem information:\n");
    printf("Size of int: %zu bytes\n", sizeof(int));
    printf("Size of pointer: %zu bytes\n", sizeof(void*));
    printf("Size of char: %zu bytes\n", sizeof(char));
    
    // 4. Portable code - works on any system with C compiler
    printf("\nPortability features:\n");
    printf("This code compiles on Windows, Linux, macOS\n");
    printf("C provides consistent behavior across platforms\n");
    
    // Clean up - manual memory management
    free(numbers);
    printf("\nMemory freed - no garbage collector needed!\n");
    
    return 0;
}
