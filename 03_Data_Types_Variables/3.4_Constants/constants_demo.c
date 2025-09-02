/*
 * constants_demo.c - Demonstrates all types of constants in C
 * Shows literal constants, const keyword, #define macros, and enumerations
 */

#include <stdio.h>
#include <string.h>  // For strlen()

// Preprocessor constants (#define)
#define MAX_STUDENTS 50
#define PI_VALUE 3.14159
#define GREETING "Hello from #define!"
#define SQUARE(x) ((x) * (x))
#define MAX(a,b) ((a) > (b) ? (a) : (b))

// Enumeration constants
enum Color {
    RED,        // 0
    GREEN,      // 1
    BLUE        // 2
};

enum Status {
    PENDING = 10,
    PROCESSING = 20,
    COMPLETED = 30
};

// Global const variables
const int GLOBAL_CONST = 999;
const char* const PROGRAM_NAME = "Constants Demo";

// Function declarations
void demonstrate_literal_constants(void);
void demonstrate_const_keyword(void);
void demonstrate_define_macros(void);
void demonstrate_enumerations(void);
void demonstrate_const_pointers(void);

int main() {
    printf("=== Constants Demo ===\n\n");
    
    demonstrate_literal_constants();
    demonstrate_const_keyword();
    demonstrate_define_macros();
    demonstrate_enumerations();
    demonstrate_const_pointers();
    
    printf("✓ All constant types demonstrated!\n");
    return 0;
}

void demonstrate_literal_constants(void) {
    printf("1. LITERAL CONSTANTS:\n");
    
    // Integer literals
    int decimal = 42;           // Decimal literal
    int octal = 052;            // Octal literal (starts with 0)
    int hex = 0x2A;             // Hexadecimal literal (starts with 0x)
    long long_num = 42L;        // Long literal
    unsigned int unsigned_num = 42U; // Unsigned literal
    
    printf("Integer literals:\n");
    printf("- Decimal: %d\n", decimal);
    printf("- Octal: %d (052)\n", octal);
    printf("- Hexadecimal: %d (0x2A)\n", hex);
    printf("- Long: %ld (42L)\n", long_num);
    printf("- Unsigned: %u (42U)\n", unsigned_num);
    
    // Floating-point literals
    double double_num = 3.14;       // Double literal (default)
    float float_num = 3.14f;        // Float literal
    double scientific = 1.5e10;     // Scientific notation
    
    printf("\nFloating-point literals:\n");
    printf("- Double: %.2f\n", double_num);
    printf("- Float: %.2f (3.14f)\n", float_num);
    printf("- Scientific: %.2e (1.5e10)\n", scientific);
    
    // Character literals
    char letter = 'A';              // Character literal
    char newline = '\n';            // Escape sequence
    char hex_char = '\x41';         // Hexadecimal character (A)
    
    printf("\nCharacter literals:\n");
    printf("- Letter: %c (ASCII: %d)\n", letter, letter);
    printf("- Newline: ASCII %d\n", newline);
    printf("- Hex char: %c (\\x41)\n", hex_char);
    
    // String literals
    char* message = "Hello World";   // String literal
    char* empty = "";               // Empty string literal
    
    printf("\nString literals:\n");
    printf("- Message: \"%s\"\n", message);
    printf("- Empty string length: %zu\n", strlen(empty));
    
    printf("\n");
}

void demonstrate_const_keyword(void) {
    printf("2. CONST KEYWORD:\n");
    
    // Local const variables
    const int MAX_SIZE = 100;
    const float LOCAL_PI = 3.14159f;
    const char GRADE = 'A';
    
    printf("Local const variables:\n");
    printf("- MAX_SIZE: %d\n", MAX_SIZE);
    printf("- LOCAL_PI: %.5f\n", LOCAL_PI);
    printf("- GRADE: %c\n", GRADE);
    
    // Global const (defined at top of file)
    printf("- GLOBAL_CONST: %d\n", GLOBAL_CONST);
    printf("- PROGRAM_NAME: %s\n", PROGRAM_NAME);
    
    // Attempting to modify const would cause compilation error:
    // MAX_SIZE = 200;  // ERROR: assignment of read-only variable
    
    printf("- const variables cannot be modified after initialization\n");
    printf("\n");
}

void demonstrate_define_macros(void) {
    printf("3. #DEFINE MACROS:\n");
    
    printf("Preprocessor constants:\n");
    printf("- MAX_STUDENTS: %d\n", MAX_STUDENTS);
    printf("- PI_VALUE: %.5f\n", PI_VALUE);
    printf("- GREETING: %s\n", GREETING);
    
    // Function-like macros
    int num = 5;
    int result1 = SQUARE(num);
    int result2 = MAX(10, 20);
    
    printf("\nFunction-like macros:\n");
    printf("- SQUARE(%d): %d\n", num, result1);
    printf("- MAX(10, 20): %d\n", result2);
    
    // Macro expansion happens before compilation
    printf("- Macros are replaced by preprocessor (no memory allocation)\n");
    printf("- No type checking (can cause issues)\n");
    
    printf("\n");
}

void demonstrate_enumerations(void) {
    printf("4. ENUMERATIONS:\n");
    
    // Basic enumeration
    enum Color favorite_color = BLUE;
    enum Color primary_colors[] = {RED, GREEN, BLUE};
    
    printf("Basic enumeration (Color):\n");
    printf("- RED: %d\n", RED);
    printf("- GREEN: %d\n", GREEN);
    printf("- BLUE: %d\n", BLUE);
    printf("- favorite_color: %d (BLUE)\n", favorite_color);
    
    // Enumeration with custom values
    enum Status current_status = PROCESSING;
    
    printf("\nEnumeration with custom values (Status):\n");
    printf("- PENDING: %d\n", PENDING);
    printf("- PROCESSING: %d\n", PROCESSING);
    printf("- COMPLETED: %d\n", COMPLETED);
    printf("- current_status: %d (PROCESSING)\n", current_status);
    
    // Enums provide type safety and readability
    printf("- Enums provide named constants with type safety\n");
    printf("- Better than magic numbers in code\n");
    
    printf("\n");
}

void demonstrate_const_pointers(void) {
    printf("5. CONST WITH POINTERS:\n");
    
    int value1 = 10, value2 = 20;
    
    // Pointer to constant int
    const int *ptr_to_const = &value1;
    printf("- const int *ptr: pointer to constant int\n");
    printf("  Can change pointer, cannot change value through pointer\n");
    printf("  *ptr_to_const = %d\n", *ptr_to_const);
    ptr_to_const = &value2;  // OK: can change pointer
    printf("  After changing pointer: *ptr_to_const = %d\n", *ptr_to_const);
    // *ptr_to_const = 30;   // ERROR: cannot modify value
    
    // Constant pointer to int
    int * const const_ptr = &value1;
    printf("\n- int * const ptr: constant pointer to int\n");
    printf("  Cannot change pointer, can change value through pointer\n");
    printf("  *const_ptr = %d\n", *const_ptr);
    *const_ptr = 30;         // OK: can modify value
    printf("  After modifying value: *const_ptr = %d\n", *const_ptr);
    // const_ptr = &value2;  // ERROR: cannot change pointer
    
    // Constant pointer to constant int
    const int * const const_ptr_to_const = &value2;
    printf("\n- const int * const ptr: constant pointer to constant int\n");
    printf("  Cannot change pointer, cannot change value\n");
    printf("  *const_ptr_to_const = %d\n", *const_ptr_to_const);
    // const_ptr_to_const = &value1;  // ERROR: cannot change pointer
    // *const_ptr_to_const = 40;      // ERROR: cannot modify value
    
    printf("\n");
}
