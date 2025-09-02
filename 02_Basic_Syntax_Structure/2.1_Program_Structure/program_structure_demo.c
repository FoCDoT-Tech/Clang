/*
 * program_structure_demo.c - Complete breakdown of C program structure
 * Demonstrates all essential components with clear examples
 */

// 1. PREPROCESSOR DIRECTIVES - Include necessary headers
#include <stdio.h>   // Standard I/O functions
#include <stdlib.h>  // Standard library functions
#include <string.h>  // String manipulation functions

// 2. FUNCTION DECLARATIONS (Prototypes)
void demonstrate_includes(void);
void demonstrate_comments(void);
int calculate_sum(int a, int b);

// 3. MAIN FUNCTION - Program entry point
int main(int argc, char *argv[]) {
    printf("=== C Program Structure Demo ===\n\n");
    
    // Show command line arguments
    printf("Command line arguments:\n");
    printf("argc (argument count): %d\n", argc);
    for (int i = 0; i < argc; i++) {
        printf("argv[%d]: %s\n", i, argv[i]);
    }
    printf("\n");
    
    // Call functions to demonstrate structure
    demonstrate_includes();
    demonstrate_comments();
    
    // Function call with return value
    int result = calculate_sum(15, 25);
    printf("Function call result: %d\n\n", result);
    
    printf("✓ Program structure demonstration complete!\n");
    
    // Return 0 for successful execution
    return 0;
}

// 4. FUNCTION DEFINITIONS

/*
 * demonstrate_includes - Shows what different headers provide
 * This function uses functions from various included headers
 */
void demonstrate_includes(void) {
    printf("Header file demonstrations:\n");
    
    // stdio.h functions
    printf("- stdio.h: printf() for output\n");
    
    // stdlib.h functions
    int *ptr = malloc(sizeof(int));
    if (ptr != NULL) {
        *ptr = 42;
        printf("- stdlib.h: malloc() allocated memory for: %d\n", *ptr);
        free(ptr);
    }
    
    // string.h functions
    char str1[20] = "Hello";
    char str2[] = " World";
    strcat(str1, str2);
    printf("- string.h: strcat() result: %s\n", str1);
    printf("- string.h: strlen() length: %zu\n\n", strlen(str1)); 
    
    /* FORMAT SPECIFIER EXPLANATION: %zu vs %d
     * 
     * strlen() returns size_t, not int - here's why this matters:
     * 
     * 1. TYPE SAFETY:
     *    - size_t: unsigned integer type (can't be negative)
     *    - int: signed integer type (can be negative)
     *    - String length is always ≥ 0, so unsigned makes sense
     * 
     * 2. SIZE CONSIDERATIONS:
     *    - size_t: typically 8 bytes on 64-bit systems (can hold very large values)
     *    - int: typically 4 bytes (limited to ~2 billion)
     *    - Large strings need size_t's bigger range
     * 
     * 3. FORMAT SPECIFIER MATCHING:
     *    - %zu: correct format for size_t (z = size_t modifier, u = unsigned)
     *    - %d: format for signed int - WRONG for size_t!
     *    - Using %d with size_t causes undefined behavior/warnings
     * 
     * 4. PLATFORM PORTABILITY:
     *    - size_t size varies by platform (32-bit vs 64-bit)
     *    - %zu adapts automatically to the platform's size_t
     *    - %d would truncate on some platforms
     * 
     * MEMORY: Always match format specifiers to data types for safety!
     */ 
}


// Single-line comment function
void demonstrate_comments(void) {
    printf("Comment types in C:\n");
    
    // This is a single-line comment
    printf("- Single-line comments use //\n");
    
    /*
     * This is a multi-line comment
     * It can span multiple lines
     * Useful for detailed explanations
     */
    printf("- Multi-line comments use /* */\n\n");
}

/**
 * calculate_sum - Adds two integers
 * @a: First integer
 * @b: Second integer
 * 
 * Return: Sum of a and b
 */
int calculate_sum(int a, int b) {
    return a + b;  // Simple addition with inline comment
}
