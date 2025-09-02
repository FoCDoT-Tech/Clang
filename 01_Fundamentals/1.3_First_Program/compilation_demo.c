/*
 * compilation_demo.c - Demonstrates compilation process and linking
 * Shows how preprocessor, compiler, and linker work together
 */

#include <stdio.h>
#include <math.h>    // Requires linking with -lm flag

#define GREETING "Hello from preprocessor!"  // Macro definition
#define SQUARE(x) ((x) * (x))               // Function-like macro

int main() {
    printf("=== Compilation Process Demo ===\n\n");
    
    // 1. Preprocessor demonstration
    printf("1. Preprocessor replaces macros:\n");
    printf("   %s\n", GREETING);
    printf("   Square of 5: %d\n\n", SQUARE(5));
    
    // 2. Compiler demonstration
    printf("2. Compiler converts to machine code:\n");
    printf("   This printf call becomes assembly instructions\n");
    printf("   Variables are allocated memory addresses\n\n");
    
    // 3. Linker demonstration
    printf("3. Linker resolves external functions:\n");
    printf("   printf() comes from standard library\n");
    printf("   sqrt() comes from math library: %.2f\n", sqrt(16.0));
    printf("   All functions linked into final executable\n\n");
    
    printf("✓ Compilation successful - you're running the program!\n");
    
    return 0;
}
