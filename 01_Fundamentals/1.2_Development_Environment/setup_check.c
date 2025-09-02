/*
 * setup_check.c - Verify your C development environment
 * Compile and run this to ensure everything is working
 */

#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("=== C Development Environment Check ===\n\n");
    
    // Check basic compilation
    printf("✓ Compiler working - you're seeing this message!\n");
    
    // Check standard library
    printf("✓ Standard library linked correctly\n");
    
    // Check memory allocation
    int *test_ptr = malloc(sizeof(int)); // malloc is a standard library function coming from stdlib.h
    if (test_ptr != NULL) {
        *test_ptr = 42;
        printf("✓ Dynamic memory allocation working: %d\n", *test_ptr);
        printf("Address: %p\n", (void*)test_ptr); // %p is used to print pointer values
        free(test_ptr); // Free allocated memory , free is a standard library function coming from stdlib.h
        printf("✓ Memory deallocation working\n");
    } else {
        printf("✗ Memory allocation failed\n");
        return 1;
    }
    
    // Check compiler info
    printf("\nCompiler Information:\n");
    #ifdef __GNUC__
        printf("- Using GCC version %d.%d.%d\n", 
               __GNUC__, __GNUC_MINOR__, __GNUC_PATCHLEVEL__); // __GNUC__ is a predefined macro that is defined by the GCC compiler
    #endif
    
    #ifdef __clang__ // __clang__ is a predefined macro that is defined by the Clang compiler
        printf("- Using Clang compiler\n");
    #endif
    
    // Check C standard
    printf("- C Standard: ");
    #if __STDC_VERSION__ >= 201112L // __STDC_VERSION__ is a predefined macro that is defined by the compiler
        printf("C11 or later\n");
    #elif __STDC_VERSION__ >= 199901L // __STDC_VERSION__ is a predefined macro that is defined by the compiler
        printf("C99\n");
    #else
        printf("C90/C89\n");
    #endif
    
    printf("\n🎉 Your C development environment is ready!\n");
    printf("You can now compile and run C programs.\n");
    
    return 0;
}
