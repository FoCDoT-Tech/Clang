/*
 * program_structure.c - Detailed breakdown of C program structure
 * Shows all essential components with explanations
 */

// 1. PREPROCESSOR DIRECTIVES
#include <stdio.h>   // Standard I/O functions (printf, scanf, etc.)
#include <stdlib.h>  // Standard library functions (malloc, free, etc.)

// 2. FUNCTION DECLARATIONS (optional for main)
void demonstrate_structure(void);

// 3. MAIN FUNCTION - Program entry point
int main() {
    printf("=== C Program Structure Demo ===\n\n");
    
    // 4. VARIABLE DECLARATIONS
    int number = 42;
    char letter = 'A';
    
    // 5. STATEMENTS AND EXPRESSIONS
    printf("Integer: %d\n", number);
    printf("Character: %c\n", letter);
    
    // 6. FUNCTION CALLS
    demonstrate_structure();
    
    // 7. RETURN STATEMENT
    return 0;  // 0 = success, non-zero = error
}

// 8. FUNCTION DEFINITIONS
void demonstrate_structure(void) {
    printf("\nThis function demonstrates:\n");
    printf("- Function definition syntax\n");
    printf("- void return type (no return value)\n");
    printf("- void parameter list (no parameters)\n");
}
