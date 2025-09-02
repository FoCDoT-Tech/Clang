/*
 * basic_types_demo.c - Demonstrates all basic data types in C
 * Shows sizes, ranges, and practical usage of char, int, float, double, void
 */

#include <stdio.h>
#include <limits.h>  // For integer limits
#include <float.h>   // For floating-point limits

// Function using void return type
void demonstrate_void_usage(void);

int main() {
    printf("=== Basic Data Types Demo ===\n\n");
    
    // 1. CHARACTER TYPE
    printf("1. CHAR (Character Type):\n");
    char letter = 'A';
    char digit = '5';
    char symbol = '@';
    
    printf("- Size: %zu byte(s)\n", sizeof(char));
    printf("- Range: %d to %d\n", CHAR_MIN, CHAR_MAX);
    printf("- Examples:\n");
    printf("  letter = '%c' (ASCII: %d)\n", letter, letter);
    printf("  digit = '%c' (ASCII: %d)\n", digit, digit);
    printf("  symbol = '%c' (ASCII: %d)\n", symbol, symbol);
    printf("\n");
    
    // 2. INTEGER TYPE
    printf("2. INT (Integer Type):\n");
    int age = 25;
    int temperature = -10;
    int large_number = 2000000000;
    
    printf("- Size: %zu byte(s)\n", sizeof(int));
    printf("- Range: %d to %d\n", INT_MIN, INT_MAX);
    printf("- Examples:\n");
    printf("  age = %d\n", age);
    printf("  temperature = %d°C\n", temperature);
    printf("  large_number = %d\n", large_number);
    printf("\n");
    
    // 3. FLOAT TYPE
    printf("3. FLOAT (Single Precision):\n");
    float price = 19.99f;
    float pi = 3.14159f;
    float scientific = 1.23e6f;  // Scientific notation
    
    printf("- Size: %zu byte(s)\n", sizeof(float));
    printf("- Precision: ~%d decimal digits\n", FLT_DIG);
    printf("- Range: %e to %e\n", FLT_MIN, FLT_MAX);
    printf("- Examples:\n");
    printf("  price = $%.2f\n", price);
    printf("  pi = %.5f\n", pi);
    printf("  scientific = %.2e\n", scientific);
    printf("\n");
    
    // 4. DOUBLE TYPE
    printf("4. DOUBLE (Double Precision):\n");
    double precise_pi = 3.141592653589793;
    double very_small = 1.23e-100;
    double very_large = 1.23e100;
    
    printf("- Size: %zu byte(s)\n", sizeof(double));
    printf("- Precision: ~%d decimal digits\n", DBL_DIG);
    printf("- Range: %e to %e\n", DBL_MIN, DBL_MAX);
    printf("- Examples:\n");
    printf("  precise_pi = %.15f\n", precise_pi);
    printf("  very_small = %.2e\n", very_small);
    printf("  very_large = %.2e\n", very_large);
    printf("\n");
    
    // 5. VOID TYPE
    printf("5. VOID (No Value Type):\n");
    printf("- Size: No storage (cannot create void variables)\n");
    printf("- Usage: Function return types, generic pointers\n");
    printf("- Examples:\n");
    printf("  void function_name(void) - returns nothing\n");
    printf("  void *ptr - generic pointer\n");
    
    // Demonstrate void function
    demonstrate_void_usage();
    printf("\n");
    
    // COMPARISON TABLE
    printf("SUMMARY TABLE:\n");
    printf("Type     | Size | Range/Precision\n");
    printf("---------|------|------------------\n");
    printf("char     | %zu    | %d to %d\n", sizeof(char), CHAR_MIN, CHAR_MAX);
    printf("int      | %zu    | %d to %d\n", sizeof(int), INT_MIN, INT_MAX);
    printf("float    | %zu    | ~%d digits, ±%.1e\n", sizeof(float), FLT_DIG, FLT_MAX);
    printf("double   | %zu    | ~%d digits, ±%.1e\n", sizeof(double), DBL_DIG, DBL_MAX);
    printf("void     | -    | No storage\n");
    
    printf("\n✓ All basic data types demonstrated!\n");
    return 0;
}

// Function demonstrating void return type
void demonstrate_void_usage(void) {
    printf("  This function uses 'void' - returns nothing\n");
    
    // Example of void pointer (generic pointer)
    int number = 42;
    void *generic_ptr = &number;  // Can point to any type
    
    printf("  void pointer can point to any type: %p\n", generic_ptr);
}
