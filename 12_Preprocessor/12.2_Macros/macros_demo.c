#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
void demonstrate_object_macros(void);
void demonstrate_function_macros(void);
void demonstrate_stringizing(void);
void demonstrate_token_pasting(void);
void demonstrate_variadic_macros(void);
void demonstrate_advanced_techniques(void);
void demonstrate_pitfalls(void);

// Inline function for safe max (used in pitfalls demo)
static inline int safe_max(int a, int b) {
    return (a > b) ? a : b;
}

// Object-like macros
#define PI 3.14159265359
#define MAX_BUFFER 1024
#define PROGRAM_VERSION "2.1.0"
#define AUTHOR_NAME "C Macro Expert"
#define TRUE 1
#define FALSE 0

// Mathematical constants
#define E 2.71828182846
#define GOLDEN_RATIO 1.61803398875
#define SQRT_2 1.41421356237

// Configuration macros
#define DEFAULT_PORT 8080
#define MAX_CONNECTIONS (100 + 50)
#define BUFFER_SIZE (1024 * 4)

// Function-like macros
#define SQUARE(x) ((x) * (x))
#define CUBE(x) ((x) * (x) * (x))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define ABS(x) ((x) < 0 ? -(x) : (x))
#define CLAMP(value, min_val, max_val) ((value) < (min_val) ? (min_val) : ((value) > (max_val) ? (max_val) : (value)))

// Utility macros
#define IS_EVEN(n) (((n) % 2) == 0)
#define IS_ODD(n) (((n) % 2) != 0)
#define IS_POWER_OF_2(n) (((n) != 0) && (((n) & ((n) - 1)) == 0))

// Multi-statement macros (using int for C99 compatibility)
#define SWAP_INT(a, b) do { \
    int temp = (a); \
    (a) = (b); \
    (b) = temp; \
} while(0)

#define SAFE_FREE(ptr) do { \
    if (ptr) { \
        free(ptr); \
        (ptr) = NULL; \
    } \
} while(0)

// Stringizing macros
#define STRINGIFY(x) #x
#define TOSTRING(x) STRINGIFY(x)
#define PRINT_VAR(var) printf(#var " = %d\n", var)
#define PRINT_FLOAT_VAR(var) printf(#var " = %.2f\n", var)

// Token pasting macros
#define CONCAT(a, b) a##b
#define MAKE_VARIABLE(prefix, suffix) prefix##_##suffix
#define DECLARE_GETTER(type, name) type get_##name(void)

// Variadic macros
#define DEBUG_PRINT(fmt, ...) printf("[DEBUG] " fmt "\n", ##__VA_ARGS__)
#define LOG_INFO(fmt, ...) printf("[INFO] " fmt "\n", ##__VA_ARGS__)
#define LOG_ERROR(fmt, ...) fprintf(stderr, "[ERROR] " fmt "\n", ##__VA_ARGS__)

// X-Macro example
#define ERROR_CODES \
    X(SUCCESS, 0, "Operation successful") \
    X(INVALID_INPUT, 1, "Invalid input provided") \
    X(MEMORY_ERROR, 2, "Memory allocation failed") \
    X(FILE_ERROR, 3, "File operation failed") \
    X(NETWORK_ERROR, 4, "Network connection failed")

// Generate error enum
typedef enum {
#define X(name, code, desc) ERR_##name = code,
    ERROR_CODES
#undef X
} error_code_t;

// Generate error descriptions array
static const char* error_descriptions[] = {
#define X(name, code, desc) [code] = desc,
    ERROR_CODES
#undef X
};

// Macro overloading simulation
#define GET_MACRO(_1, _2, _3, NAME, ...) NAME
#define PRINT_NUMS(...) GET_MACRO(__VA_ARGS__, PRINT3, PRINT2, PRINT1)(__VA_ARGS__)

#define PRINT1(a) printf("Number: %d\n", a)
#define PRINT2(a, b) printf("Numbers: %d, %d\n", a, b)
#define PRINT3(a, b, c) printf("Numbers: %d, %d, %d\n", a, b, c)

int main(void) {
    printf("=== Advanced Macros Demo ===\n\n");
    
    demonstrate_object_macros();
    demonstrate_function_macros();
    demonstrate_stringizing();
    demonstrate_token_pasting();
    demonstrate_variadic_macros();
    demonstrate_advanced_techniques();
    demonstrate_pitfalls();
    
    printf("=== Demo Complete ===\n");
    return 0;
}

void demonstrate_object_macros(void) {
    printf("1. OBJECT-LIKE MACROS\n");
    printf("----------------------------------------\n");
    
    printf("Basic Constants:\n");
    printf("  PI = %.10f\n", PI);
    printf("  E = %.10f\n", E);
    printf("  Golden Ratio = %.10f\n", GOLDEN_RATIO);
    printf("  Square Root of 2 = %.10f\n", SQRT_2);
    
    printf("\nString Constants:\n");
    printf("  Program Version: %s\n", PROGRAM_VERSION);
    printf("  Author: %s\n", AUTHOR_NAME);
    
    printf("\nConfiguration Values:\n");
    printf("  Max Buffer: %d bytes\n", MAX_BUFFER);
    printf("  Default Port: %d\n", DEFAULT_PORT);
    printf("  Max Connections: %d\n", MAX_CONNECTIONS);
    printf("  Buffer Size: %d bytes\n", BUFFER_SIZE);
    
    printf("\nBoolean Values:\n");
    printf("  TRUE = %d\n", TRUE);
    printf("  FALSE = %d\n", FALSE);
    
    // Using macros in calculations
    printf("\nUsing Macros in Calculations:\n");
    double radius = 5.0;
    double area = PI * radius * radius;
    double circumference = 2 * PI * radius;
    printf("  Circle (radius %.1f): area = %.2f, circumference = %.2f\n", 
           radius, area, circumference);
    
    // Array declaration using macro
    char buffer[MAX_BUFFER];
    snprintf(buffer, MAX_BUFFER, "Buffer size is %d", MAX_BUFFER);
    printf("  %s\n", buffer);
    
    printf("\n");
}

void demonstrate_function_macros(void) {
    printf("2. FUNCTION-LIKE MACROS\n");
    printf("----------------------------------------\n");
    
    printf("Mathematical Function Macros:\n");
    
    int x = 7, y = 3;
    printf("  x = %d, y = %d\n", x, y);
    printf("  SQUARE(%d) = %d\n", x, SQUARE(x));
    printf("  CUBE(%d) = %d\n", x, CUBE(x));
    printf("  MAX(%d, %d) = %d\n", x, y, MAX(x, y));
    printf("  MIN(%d, %d) = %d\n", x, y, MIN(x, y));
    
    int negative = -15;
    printf("  ABS(%d) = %d\n", negative, ABS(negative));
    
    printf("\nUtility Function Macros:\n");
    
    // Test IS_EVEN and IS_ODD
    for (int i = 1; i <= 8; i++) {
        printf("  %d is %s\n", i, IS_EVEN(i) ? "even" : "odd");
    }
    
    // Test IS_POWER_OF_2
    printf("\nPower of 2 Tests:\n");
    int test_values[] = {1, 2, 3, 4, 7, 8, 15, 16, 31, 32};
    for (int i = 0; i < 10; i++) {
        int val = test_values[i];
        printf("  IS_POWER_OF_2(%d) = %s\n", val, IS_POWER_OF_2(val) ? "true" : "false");
    }
    
    // Test CLAMP
    printf("\nClamping Tests (range [0, 10]):\n");
    int clamp_tests[] = {-5, 0, 3, 7, 10, 15};
    for (int i = 0; i < 6; i++) {
        int val = clamp_tests[i];
        int clamped = CLAMP(val, 0, 10);
        printf("  CLAMP(%d, 0, 10) = %d\n", val, clamped);
    }
    
    // Multi-statement macro
    printf("\nMulti-statement Macro (SWAP_INT):\n");
    int a = 10, b = 20;
    printf("  Before swap: a = %d, b = %d\n", a, b);
    SWAP_INT(a, b);
    printf("  After swap: a = %d, b = %d\n", a, b);
    
    printf("\n");
}

void demonstrate_stringizing(void) {
    printf("3. STRINGIZING (#)\n");
    printf("----------------------------------------\n");
    
    printf("Converting Tokens to Strings:\n");
    
    // Basic stringizing
    printf("  STRINGIFY(hello) = \"%s\"\n", STRINGIFY(hello));
    printf("  STRINGIFY(123) = \"%s\"\n", STRINGIFY(123));
    printf("  STRINGIFY(PI) = \"%s\"\n", STRINGIFY(PI));
    
    // Using TOSTRING for macro values
    printf("\nStringizing Macro Values:\n");
    printf("  TOSTRING(MAX_BUFFER) = \"%s\"\n", TOSTRING(MAX_BUFFER));
    printf("  TOSTRING(DEFAULT_PORT) = \"%s\"\n", TOSTRING(DEFAULT_PORT));
    
    // Debug printing macros
    printf("\nDebug Variable Printing:\n");
    int count = 42;
    float temperature = 23.5f;
    
    PRINT_VAR(count);
    PRINT_FLOAT_VAR(temperature);
    
    // Version string creation
    #define VERSION_MAJOR 2
    #define VERSION_MINOR 1
    #define VERSION_PATCH 0
    #define VERSION_STRING TOSTRING(VERSION_MAJOR) "." TOSTRING(VERSION_MINOR) "." TOSTRING(VERSION_PATCH)
    
    printf("\nVersion String Creation:\n");
    printf("  Version: %s\n", VERSION_STRING);
    
    printf("\n");
}

void demonstrate_token_pasting(void) {
    printf("4. TOKEN PASTING (##)\n");
    printf("----------------------------------------\n");
    
    printf("Token Concatenation:\n");
    
    // Basic token pasting
    #define PREFIX hello
    #define SUFFIX world
    printf("  Concatenating tokens: %s\n", STRINGIFY(CONCAT(PREFIX, SUFFIX)));
    
    // Variable generation
    int MAKE_VARIABLE(user, count) = 100;
    int MAKE_VARIABLE(session, id) = 12345;
    
    printf("  Generated variables:\n");
    printf("    user_count = %d\n", user_count);
    printf("    session_id = %d\n", session_id);
    
    // Function declaration generation
    printf("\nFunction Declaration Generation:\n");
    printf("  DECLARE_GETTER(int, age) generates: %s\n", 
           STRINGIFY(DECLARE_GETTER(int, age)));
    
    // Creating numbered variables
    #define DECLARE_VAR(type, name, num) type name##num = num * 10
    
    DECLARE_VAR(int, var, 1);
    DECLARE_VAR(int, var, 2);
    DECLARE_VAR(int, var, 3);
    
    printf("\nNumbered Variables:\n");
    printf("  var1 = %d\n", var1);
    printf("  var2 = %d\n", var2);
    printf("  var3 = %d\n", var3);
    
    // Enum generation
    #define MAKE_ENUM(name) ENUM_##name
    typedef enum {
        MAKE_ENUM(FIRST),
        MAKE_ENUM(SECOND),
        MAKE_ENUM(THIRD)
    } test_enum_t;
    
    printf("\nEnum Generation:\n");
    printf("  ENUM_FIRST = %d\n", ENUM_FIRST);
    printf("  ENUM_SECOND = %d\n", ENUM_SECOND);
    printf("  ENUM_THIRD = %d\n", ENUM_THIRD);
    
    printf("\n");
}

void demonstrate_variadic_macros(void) {
    printf("5. VARIADIC MACROS\n");
    printf("----------------------------------------\n");
    
    printf("Variable Argument Macros:\n");
    
    // Basic variadic macros
    DEBUG_PRINT("Simple debug message");
    DEBUG_PRINT("Debug with number: %d", 42);
    DEBUG_PRINT("Debug with multiple args: %d, %s, %.2f", 123, "test", 3.14);
    
    LOG_INFO("Application started");
    LOG_INFO("Processing %d items", 100);
    LOG_ERROR("Failed to open file: %s", "config.txt");
    
    // Macro overloading simulation
    printf("\nMacro Overloading Simulation:\n");
    PRINT_NUMS(1);
    PRINT_NUMS(1, 2);
    PRINT_NUMS(1, 2, 3);
    
    // Custom printf-like macro
    #define CUSTOM_PRINTF(level, fmt, ...) do { \
        printf("[%s] ", level); \
        printf(fmt, ##__VA_ARGS__); \
        printf("\n"); \
    } while(0)
    
    printf("\nCustom Printf-like Macro:\n");
    CUSTOM_PRINTF("INFO", "System initialized");
    CUSTOM_PRINTF("WARN", "Low memory: %d%% used", 85);
    CUSTOM_PRINTF("ERROR", "Connection failed after %d attempts", 3);
    
    printf("\n");
}

void demonstrate_advanced_techniques(void) {
    printf("6. ADVANCED MACRO TECHNIQUES\n");
    printf("----------------------------------------\n");
    
    printf("X-Macro Pattern:\n");
    
    // Show generated enum values
    printf("  Error Codes:\n");
    printf("    ERR_SUCCESS = %d\n", ERR_SUCCESS);
    printf("    ERR_INVALID_INPUT = %d\n", ERR_INVALID_INPUT);
    printf("    ERR_MEMORY_ERROR = %d\n", ERR_MEMORY_ERROR);
    printf("    ERR_FILE_ERROR = %d\n", ERR_FILE_ERROR);
    printf("    ERR_NETWORK_ERROR = %d\n", ERR_NETWORK_ERROR);
    
    // Show error descriptions
    printf("\n  Error Descriptions:\n");
    for (int i = 0; i <= 4; i++) {
        printf("    Code %d: %s\n", i, error_descriptions[i]);
    }
    
    // Conditional macro definition
    #ifdef DEBUG_MODE
        #define DBG_PRINT(x) printf("DEBUG: " x "\n")
    #else
        #define DBG_PRINT(x)
    #endif
    
    printf("\nConditional Macro Definition:\n");
    #ifndef DEBUG_MODE
        printf("  Debug mode is OFF - DBG_PRINT does nothing\n");
    #else
        printf("  Debug mode is ON - DBG_PRINT is active\n");
    #endif
    
    // Macro for loop unrolling
    #define UNROLL_4(stmt) do { \
        stmt; stmt; stmt; stmt; \
    } while(0)
    
    printf("\nLoop Unrolling Macro:\n");
    int sum = 0;
    int increment = 5;
    printf("  Adding %d four times using UNROLL_4:\n", increment);
    UNROLL_4(sum += increment; printf("    sum = %d\n", sum));
    
    // Type-specific swap macros (C99 compatible)
    #define SWAP_FLOAT(a, b) do { \
        float temp = (a); \
        (a) = (b); \
        (b) = temp; \
    } while(0)
    
    printf("\nType-specific Swap Macros:\n");
    int int_a = 100, int_b = 200;
    float float_a = 1.5f, float_b = 2.5f;
    
    printf("  Before: int_a = %d, int_b = %d\n", int_a, int_b);
    SWAP_INT(int_a, int_b);
    printf("  After: int_a = %d, int_b = %d\n", int_a, int_b);
    
    printf("  Before: float_a = %.1f, float_b = %.1f\n", float_a, float_b);
    SWAP_FLOAT(float_a, float_b);
    printf("  After: float_a = %.1f, float_b = %.1f\n", float_a, float_b);
    
    printf("\n");
}

void demonstrate_pitfalls(void) {
    printf("7. COMMON MACRO PITFALLS\n");
    printf("----------------------------------------\n");
    
    printf("Demonstrating Common Issues:\n");
    
    // Multiple evaluation problem
    #define BAD_MAX(a, b) ((a) > (b) ? (a) : (b))
    
    printf("\n1. Multiple Evaluation Problem:\n");
    int counter = 0;
    
    // This will increment counter twice!
    printf("  counter = %d\n", counter);
    printf("  BAD_MAX(++counter, 5) = %d\n", BAD_MAX(++counter, 5));
    printf("  counter after BAD_MAX = %d (incremented twice!)\n", counter);
    
    // Reset counter
    counter = 0;
    
    // Better approach with inline function (already defined at top)
    
    printf("  counter = %d\n", counter);
    printf("  safe_max(++counter, 5) = %d\n", safe_max(++counter, 5));
    printf("  counter after safe_max = %d (incremented once)\n", counter);
    
    // Operator precedence problem
    printf("\n2. Operator Precedence Problem:\n");
    #define BAD_MULTIPLY(x, y) x * y
    #define GOOD_MULTIPLY(x, y) ((x) * (y))
    
    printf("  BAD_MULTIPLY(2 + 3, 4) = %d (should be 20, but is 14)\n", 
           BAD_MULTIPLY(2 + 3, 4));
    printf("  GOOD_MULTIPLY(2 + 3, 4) = %d (correct: 20)\n", 
           GOOD_MULTIPLY(2 + 3, 4));
    
    // Semicolon problem
    printf("\n3. Semicolon Problem:\n");
    #define BAD_PRINT(x) printf("Value: %d\n", x);
    #define GOOD_PRINT(x) printf("Value: %d\n", x)
    
    printf("  BAD_PRINT creates extra semicolon issues in if statements\n");
    printf("  GOOD_PRINT doesn't include semicolon in definition\n");
    
    int test_val = 42;
    if (test_val > 0)
        GOOD_PRINT(test_val);  // Works correctly
    else
        printf("Negative value\n");
    
    // Memory management pitfall
    printf("\n4. Safe Memory Management:\n");
    char *ptr = malloc(100);
    if (ptr) {
        strcpy(ptr, "Test string");
        printf("  Allocated and used pointer: %s\n", ptr);
        
        SAFE_FREE(ptr);
        printf("  After SAFE_FREE: ptr = %p (NULL)\n", (void*)ptr);
        
        // Safe to call again
        SAFE_FREE(ptr);
        printf("  SAFE_FREE can be called multiple times safely\n");
    }
    
    printf("\n5. Best Practices Summary:\n");
    printf("  ✓ Always parenthesize macro parameters\n");
    printf("  ✓ Parenthesize the entire macro expression\n");
    printf("  ✓ Use do-while(0) for multi-statement macros\n");
    printf("  ✓ Avoid side effects in macro arguments\n");
    printf("  ✓ Use inline functions for complex operations\n");
    printf("  ✓ Use UPPERCASE names for macros\n");
    printf("  ✓ Don't include semicolons in macro definitions\n");
    
    printf("\n");
}
