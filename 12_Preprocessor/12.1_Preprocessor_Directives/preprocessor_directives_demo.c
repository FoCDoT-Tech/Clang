#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "config.h"

// Demonstrate different types of includes
#include <time.h>        // System header
#include <math.h>        // System header

// Function prototypes
void demonstrate_basic_directives(void);
void demonstrate_object_macros(void);
void demonstrate_function_macros(void);
void demonstrate_conditional_compilation(void);
void demonstrate_header_guards(void);
void demonstrate_macro_operations(void);

// Object-like macros
#define PI 3.14159265359
#define BUFFER_SIZE 256
#define PROGRAM_NAME "Preprocessor Demo"
#define AUTHOR "C Learning Project"

// Function-like macros
#define SQUARE(x) ((x) * (x))
#define CUBE(x) ((x) * (x) * (x))
#define IS_EVEN(n) (((n) % 2) == 0)
#define CLAMP(value, min, max) ((value) < (min) ? (min) : ((value) > (max) ? (max) : (value)))

// Multi-line macro
#define PRINT_SEPARATOR() do { \
    printf("----------------------------------------\n"); \
} while(0)

// Conditional compilation example
#ifdef ENABLE_ADVANCED_FEATURES
    #define ADVANCED_FUNCTION() printf("Advanced feature enabled\n")
#else
    #define ADVANCED_FUNCTION() printf("Advanced feature disabled\n")
#endif

int main(void) {
    printf("=== Preprocessor Directives Demo ===\n\n");
    
    demonstrate_basic_directives();
    demonstrate_object_macros();
    demonstrate_function_macros();
    demonstrate_conditional_compilation();
    demonstrate_header_guards();
    demonstrate_macro_operations();
    
    printf("=== Demo Complete ===\n");
    return 0;
}

void demonstrate_basic_directives(void) {
    printf("1. BASIC PREPROCESSOR DIRECTIVES\n");
    PRINT_SEPARATOR();
    
    printf("Program Information:\n");
    printf("  Name: %s\n", PROGRAM_NAME);
    printf("  Author: %s\n", AUTHOR);
    printf("  Version: %s\n", VERSION_STRING);
    printf("  Platform: %s\n", PLATFORM_NAME);
    printf("  Path Separator: '%c'\n", PATH_SEPARATOR);
    
    printf("\nIncluded Headers:\n");
    printf("  ✓ stdio.h - Standard I/O functions\n");
    printf("  ✓ stdlib.h - Standard library functions\n");
    printf("  ✓ string.h - String manipulation functions\n");
    printf("  ✓ time.h - Time and date functions\n");
    printf("  ✓ math.h - Mathematical functions\n");
    printf("  ✓ config.h - Custom configuration header\n");
    
    printf("\nBuffer Configuration:\n");
    printf("  Buffer size: %d bytes\n", BUFFER_SIZE);
    printf("  Max buffer size: %d bytes\n", MAX_BUFFER_SIZE);
    
    printf("\n");
}

void demonstrate_object_macros(void) {
    printf("2. OBJECT-LIKE MACROS\n");
    PRINT_SEPARATOR();
    
    printf("Mathematical Constants:\n");
    printf("  PI = %.10f\n", PI);
    printf("  PI * 2 = %.10f\n", PI * 2);
    
    printf("\nUsing PI in calculations:\n");
    double radius = 5.0;
    double area = PI * radius * radius;
    double circumference = 2 * PI * radius;
    printf("  Circle with radius %.1f:\n", radius);
    printf("    Area = %.2f\n", area);
    printf("    Circumference = %.2f\n", circumference);
    
    printf("\nString Macros:\n");
    printf("  Program: %s\n", PROGRAM_NAME);
    printf("  Author: %s\n", AUTHOR);
    
    printf("\nConfiguration Values:\n");
    printf("  Buffer size: %d\n", BUFFER_SIZE);
    printf("  Version: %s\n", VERSION_STRING);
    
    // Demonstrate macro replacement
    char buffer[BUFFER_SIZE];
    snprintf(buffer, BUFFER_SIZE, "This buffer has %d bytes", BUFFER_SIZE);
    printf("  Buffer content: %s\n", buffer);
    
    printf("\n");
}

void demonstrate_function_macros(void) {
    printf("3. FUNCTION-LIKE MACROS\n");
    PRINT_SEPARATOR();
    
    printf("Mathematical Function Macros:\n");
    
    // SQUARE macro
    int x = 5;
    printf("  SQUARE(%d) = %d\n", x, SQUARE(x));
    printf("  SQUARE(3 + 2) = %d\n", SQUARE(3 + 2));
    
    // CUBE macro
    printf("  CUBE(%d) = %d\n", x, CUBE(x));
    
    // MIN and MAX macros from config.h
    int a = 10, b = 20;
    printf("  MIN(%d, %d) = %d\n", a, b, MIN(a, b));
    printf("  MAX(%d, %d) = %d\n", a, b, MAX(a, b));
    
    // ABS macro
    int negative = -15;
    printf("  ABS(%d) = %d\n", negative, ABS(negative));
    
    printf("\nConditional Function Macros:\n");
    
    // IS_EVEN macro
    for (int i = 1; i <= 6; i++) {
        printf("  IS_EVEN(%d) = %s\n", i, IS_EVEN(i) ? "true" : "false");
    }
    
    printf("\nUtility Function Macros:\n");
    
    // CLAMP macro
    int values[] = {-5, 0, 5, 10, 15, 25};
    int min_val = 0, max_val = 20;
    
    printf("  Clamping values to range [%d, %d]:\n", min_val, max_val);
    for (int i = 0; i < 6; i++) {
        int clamped = CLAMP(values[i], min_val, max_val);
        printf("    CLAMP(%d) = %d\n", values[i], clamped);
    }
    
    printf("\n");
}

void demonstrate_conditional_compilation(void) {
    printf("4. CONDITIONAL COMPILATION\n");
    PRINT_SEPARATOR();
    
    printf("Feature Flags:\n");
    
    // Check logging feature
    #if ENABLE_LOGGING
        printf("  ✓ Logging is ENABLED\n");
        LOG_INFO("This is an info message");
        LOG_ERROR("This is an error message");
    #else
        printf("  ✗ Logging is DISABLED\n");
    #endif
    
    // Check debug feature
    #if ENABLE_DEBUG
        printf("  ✓ Debug mode is ENABLED\n");
        DEBUG_PRINT("Debug message with no args");
        DEBUG_PRINT("Debug message with arg: %d", 42);
    #else
        printf("  ✗ Debug mode is DISABLED\n");
    #endif
    
    // Platform-specific code
    printf("\nPlatform-Specific Code:\n");
    printf("  Detected platform: %s\n", PLATFORM_NAME);
    printf("  Path separator: '%c'\n", PATH_SEPARATOR);
    
    #ifdef _WIN32
        printf("  Windows-specific code would run here\n");
    #elif defined(__linux__)
        printf("  Linux-specific code would run here\n");
    #elif defined(__APPLE__)
        printf("  macOS-specific code would run here\n");
    #else
        printf("  Generic Unix code would run here\n");
    #endif
    
    // Version-based compilation
    printf("\nVersion-Based Features:\n");
    printf("  Version: %d.%d.%d\n", VERSION_MAJOR, VERSION_MINOR, VERSION_PATCH);
    
    #if VERSION_MAJOR >= 1
        printf("  ✓ Version 1+ features available\n");
        
        #if VERSION_MINOR >= 2
            printf("  ✓ Version 1.2+ features available\n");
        #else
            printf("  ✗ Version 1.2+ features not available\n");
        #endif
    #else
        printf("  ✗ This is a pre-release version\n");
    #endif
    
    // Advanced features check
    printf("\nAdvanced Features:\n");
    ADVANCED_FUNCTION();
    
    printf("\n");
}

void demonstrate_header_guards(void) {
    printf("5. HEADER GUARDS\n");
    PRINT_SEPARATOR();
    
    printf("Header Guard Demonstration:\n");
    printf("  config.h uses traditional header guards:\n");
    printf("    #ifndef CONFIG_H\n");
    printf("    #define CONFIG_H\n");
    printf("    // header content\n");
    printf("    #endif /* CONFIG_H */\n");
    
    printf("\nBenefits of Header Guards:\n");
    printf("  ✓ Prevents multiple inclusion of the same header\n");
    printf("  ✓ Avoids redefinition errors\n");
    printf("  ✓ Reduces compilation time\n");
    printf("  ✓ Works with all C compilers\n");
    
    printf("\nAlternative: #pragma once\n");
    printf("  Modern compilers support: #pragma once\n");
    printf("  Pros: Simpler syntax, less typing\n");
    printf("  Cons: Not part of C standard, compiler-specific\n");
    
    printf("\nHeader Guard Naming Convention:\n");
    printf("  Use: FILENAME_H or PROJECT_FILENAME_H\n");
    printf("  Example: CONFIG_H, MYPROJECT_UTILS_H\n");
    
    printf("\n");
}

void demonstrate_macro_operations(void) {
    printf("6. MACRO OPERATIONS\n");
    PRINT_SEPARATOR();
    
    printf("Macro Redefinition:\n");
    
    // Show original definition
    #define TEMP_VALUE 100
    printf("  Original TEMP_VALUE: %d\n", TEMP_VALUE);
    
    // Redefine (will show compiler warning)
    #undef TEMP_VALUE
    #define TEMP_VALUE 200
    printf("  Redefined TEMP_VALUE: %d\n", TEMP_VALUE);
    
    // Clean up
    #undef TEMP_VALUE
    
    printf("\nMacro Existence Checking:\n");
    
    #ifdef PI
        printf("  ✓ PI is defined (value: %.5f)\n", PI);
    #else
        printf("  ✗ PI is not defined\n");
    #endif
    
    #ifdef UNDEFINED_MACRO
        printf("  ✓ UNDEFINED_MACRO is defined\n");
    #else
        printf("  ✗ UNDEFINED_MACRO is not defined\n");
    #endif
    
    printf("\nUsing 'defined' operator:\n");
    
    #if defined(ENABLE_LOGGING) && defined(ENABLE_DEBUG)
        printf("  ✓ Both logging and debug are enabled\n");
    #elif defined(ENABLE_LOGGING)
        printf("  ✓ Only logging is enabled\n");
    #elif defined(ENABLE_DEBUG)
        printf("  ✓ Only debug is enabled\n");
    #else
        printf("  ✗ Neither logging nor debug is enabled\n");
    #endif
    
    printf("\nMacro Best Practices Demonstration:\n");
    
    // Show safe macro usage
    int test_val = 5;
    printf("  Safe macro: SQUARE(%d) = %d\n", test_val, SQUARE(test_val));
    
    // Show why parentheses matter
    printf("  Expression: SQUARE(2 + 3) = %d (correct: 25)\n", SQUARE(2 + 3));
    
    // Demonstrate multi-line macro
    printf("  Multi-line macro (PRINT_SEPARATOR):\n");
    PRINT_SEPARATOR();
    
    printf("\n");
}
