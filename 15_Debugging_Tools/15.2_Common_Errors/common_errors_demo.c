#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
void demonstrate_syntax_error_patterns(void);
void demonstrate_runtime_errors(void);
void demonstrate_logic_errors(void);
void demonstrate_memory_errors(void);
void demonstrate_error_prevention(void);

// Helper functions that demonstrate common errors
int safe_divide(int a, int b);
char* safe_string_copy(const char* src);
void demonstrate_buffer_safety(void);
int* create_array_safely(int size);

int main(void) {
    printf("=== Common Errors Demo ===\n\n");
    
    demonstrate_syntax_error_patterns();
    demonstrate_runtime_errors();
    demonstrate_logic_errors();
    demonstrate_memory_errors();
    demonstrate_error_prevention();
    
    printf("=== Demo Complete ===\n");
    return 0;
}

void demonstrate_syntax_error_patterns(void) {
    printf("1. SYNTAX ERROR PATTERNS\n");
    printf("----------------------------------------\n");
    
    printf("Common syntax errors (shown as comments):\n\n");
    
    // Missing semicolon example
    printf("Missing semicolon:\n");
    printf("  int x = 5  // ERROR: missing semicolon\n");
    printf("  int x = 5; // CORRECT\n\n");
    
    // Unmatched braces
    printf("Unmatched braces:\n");
    printf("  if (condition) {\n");
    printf("      do_something();\n");
    printf("  // ERROR: missing closing brace\n");
    printf("  \n");
    printf("  if (condition) {\n");
    printf("      do_something();\n");
    printf("  } // CORRECT\n\n");
    
    // Incorrect function declaration
    printf("Function declaration errors:\n");
    printf("  int func(int x int y);     // ERROR: missing comma\n");
    printf("  int func(int x, int y);    // CORRECT\n");
    printf("  \n");
    printf("  void func() {              // ERROR: missing return type in some contexts\n");
    printf("  int func(void) {           // CORRECT: explicit void parameter\n\n");
    
    // Type mismatch
    printf("Type mismatch examples:\n");
    int int_var = 42;
    float float_var = 3.14f;
    printf("  int_var = %d, float_var = %.2f\n", int_var, float_var);
    printf("  int_var = float_var;       // WARNING: implicit conversion\n");
    printf("  int_var = (int)float_var;  // CORRECT: explicit cast\n");
    
    printf("\n");
}

void demonstrate_runtime_errors(void) {
    printf("2. RUNTIME ERRORS\n");
    printf("----------------------------------------\n");
    
    // Division by zero protection
    printf("Division by zero protection:\n");
    int result = safe_divide(10, 2);
    printf("10 / 2 = %d\n", result);
    
    result = safe_divide(10, 0);
    printf("10 / 0 = %d (handled safely)\n", result);
    
    // Array bounds checking
    printf("\nArray bounds checking:\n");
    int arr[5] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    printf("Array size: %d\n", size);
    for (int i = 0; i < size; i++) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }
    
    // Demonstrate bounds checking
    int index = 10;  // Out of bounds
    if (index >= 0 && index < size) {
        printf("arr[%d] = %d\n", index, arr[index]);
    } else {
        printf("Index %d is out of bounds (0-%d)\n", index, size - 1);
    }
    
    // Null pointer checking
    printf("\nNull pointer checking:\n");
    char* str = safe_string_copy("Hello, World!");
    if (str) {
        printf("Copied string: %s\n", str);
        free(str);
    }
    
    str = safe_string_copy(NULL);
    if (str) {
        printf("Copied string: %s\n", str);
        free(str);
    } else {
        printf("String copy failed safely\n");
    }
    
    // Stack overflow prevention
    printf("\nStack overflow prevention:\n");
    printf("Avoiding deep recursion with iteration or tail recursion\n");
    printf("Using heap allocation for large data structures\n");
    
    printf("\n");
}

void demonstrate_logic_errors(void) {
    printf("3. LOGIC ERRORS\n");
    printf("----------------------------------------\n");
    
    // Off-by-one errors
    printf("Off-by-one error examples:\n");
    
    int numbers[] = {10, 20, 30, 40, 50};
    int count = sizeof(numbers) / sizeof(numbers[0]);
    
    printf("Array: ");
    for (int i = 0; i < count; i++) {  // CORRECT: i < count
        printf("%d ", numbers[i]);
    }
    printf("\n");
    
    printf("Common off-by-one mistakes:\n");
    printf("  for (i = 0; i <= count; i++)  // ERROR: goes one past end\n");
    printf("  for (i = 1; i < count; i++)   // ERROR: skips first element\n");
    printf("  for (i = 0; i < count; i++)   // CORRECT\n");
    
    // Loop condition errors
    printf("\nLoop condition errors:\n");
    
    // Correct countdown
    printf("Countdown (correct): ");
    for (int i = 5; i > 0; i--) {
        printf("%d ", i);
    }
    printf("\n");
    
    printf("Common mistakes:\n");
    printf("  for (i = 5; i >= 0; i--)      // ERROR: includes 0, might be wrong\n");
    printf("  for (i = 5; i > 0; i--)       // CORRECT: stops at 1\n");
    
    // String comparison errors
    printf("\nString comparison:\n");
    char str1[] = "hello";
    char str2[] = "hello";
    char* str3 = "hello";
    char* str4 = "hello";
    
    printf("str1 == str2: %s (arrays - compares addresses)\n", 
           (str1 == str2) ? "true" : "false");
    printf("strcmp(str1, str2) == 0: %s (correct string comparison)\n",
           (strcmp(str1, str2) == 0) ? "true" : "false");
    
    printf("str3 == str4: %s (string literals - may be same address)\n",
           (str3 == str4) ? "true" : "false");
    printf("strcmp(str3, str4) == 0: %s (correct string comparison)\n",
           (strcmp(str3, str4) == 0) ? "true" : "false");
    
    // Assignment vs comparison
    printf("\nAssignment vs comparison:\n");
    int x = 5;
    printf("Original x: %d\n", x);
    
    if (x = 10) {  // ERROR: assignment instead of comparison
        printf("This will always execute because x = 10 returns 10 (true)\n");
        printf("x is now: %d\n", x);
    }
    
    x = 5;  // Reset
    if (x == 5) {  // CORRECT: comparison
        printf("Correct comparison: x equals 5\n");
    }
    
    printf("\n");
}

void demonstrate_memory_errors(void) {
    printf("4. MEMORY ERRORS\n");
    printf("----------------------------------------\n");
    
    // Memory leak demonstration and prevention
    printf("Memory leak prevention:\n");
    
    // Correct memory management
    int* ptr = create_array_safely(5);
    if (ptr) {
        for (int i = 0; i < 5; i++) {
            ptr[i] = i * i;
        }
        
        printf("Array contents: ");
        for (int i = 0; i < 5; i++) {
            printf("%d ", ptr[i]);
        }
        printf("\n");
        
        free(ptr);  // IMPORTANT: free allocated memory
        ptr = NULL; // GOOD PRACTICE: set to NULL after freeing
        printf("Memory freed and pointer set to NULL\n");
    }
    
    // Double free prevention
    printf("\nDouble free prevention:\n");
    char* buffer = malloc(100);
    if (buffer) {
        strcpy(buffer, "Test string");
        printf("Buffer content: %s\n", buffer);
        
        free(buffer);
        buffer = NULL;  // Prevent double free
        
        // This would be safe now
        if (buffer) {
            free(buffer);  // Won't execute
        } else {
            printf("Buffer already freed, avoiding double free\n");
        }
    }
    
    // Use after free prevention
    printf("\nUse after free prevention:\n");
    char* data = malloc(50);
    if (data) {
        strcpy(data, "Important data");
        printf("Data before free: %s\n", data);
        
        free(data);
        data = NULL;  // Prevent use after free
        
        // Safe check before use
        if (data) {
            printf("Data after free: %s\n", data);  // Won't execute
        } else {
            printf("Data pointer is NULL, avoiding use after free\n");
        }
    }
    
    // Buffer overflow prevention
    printf("\nBuffer overflow prevention:\n");
    demonstrate_buffer_safety();
    
    // Uninitialized memory
    printf("\nUninitialized memory prevention:\n");
    int initialized_array[5] = {0};  // Initialize to zero
    printf("Initialized array: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", initialized_array[i]);
    }
    printf("\n");
    
    // Dynamic memory initialization
    int* dynamic_array = calloc(5, sizeof(int));  // Initialized to zero
    if (dynamic_array) {
        printf("Calloc array (zero-initialized): ");
        for (int i = 0; i < 5; i++) {
            printf("%d ", dynamic_array[i]);
        }
        printf("\n");
        free(dynamic_array);
    }
    
    printf("\n");
}

void demonstrate_error_prevention(void) {
    printf("5. ERROR PREVENTION STRATEGIES\n");
    printf("----------------------------------------\n");
    
    printf("Best practices for error prevention:\n\n");
    
    printf("1. Always check return values:\n");
    FILE* file = fopen("nonexistent.txt", "r");
    if (file) {
        printf("File opened successfully\n");
        fclose(file);
    } else {
        printf("Failed to open file (expected for demo)\n");
    }
    
    printf("\n2. Initialize variables:\n");
    int counter = 0;  // Always initialize
    char buffer[100] = {0};  // Initialize arrays
    printf("Counter initialized to: %d\n", counter);
    printf("Buffer initialized (first char): %d\n", buffer[0]);
    
    printf("\n3. Use const for read-only data:\n");
    const char* message = "This cannot be modified";
    printf("Message: %s\n", message);
    // message[0] = 'X';  // Would cause compiler error
    
    printf("\n4. Validate function parameters:\n");
    char* result = safe_string_copy("Test string");
    if (result) {
        printf("Safe copy result: %s\n", result);
        free(result);
    }
    
    printf("\n5. Use appropriate data types:\n");
    size_t array_size = 10;  // Use size_t for sizes
    unsigned int positive_count = 0;  // Use unsigned for counts
    printf("Array size: %zu, Count: %u\n", array_size, positive_count);
    
    printf("\n6. Compiler warnings are your friend:\n");
    printf("Always compile with -Wall -Wextra -Wpedantic\n");
    printf("Treat warnings as errors in production code\n");
    
    printf("\n7. Static analysis tools:\n");
    printf("Use tools like: cppcheck, clang-static-analyzer, valgrind\n");
    
    printf("\n");
}

// Helper function implementations

int safe_divide(int a, int b) {
    if (b == 0) {
        printf("Error: Division by zero attempted\n");
        return 0;  // or return an error code
    }
    return a / b;
}

char* safe_string_copy(const char* src) {
    if (!src) {
        printf("Error: NULL source string\n");
        return NULL;
    }
    
    size_t len = strlen(src);
    char* dest = malloc(len + 1);
    
    if (!dest) {
        printf("Error: Memory allocation failed\n");
        return NULL;
    }
    
    strcpy(dest, src);
    return dest;
}

void demonstrate_buffer_safety(void) {
    char safe_buffer[20];
    const char* source = "This is a long string that might overflow";
    
    printf("Source string length: %zu\n", strlen(source));
    printf("Buffer size: %zu\n", sizeof(safe_buffer));
    
    // Safe copy with bounds checking
    strncpy(safe_buffer, source, sizeof(safe_buffer) - 1);
    safe_buffer[sizeof(safe_buffer) - 1] = '\0';  // Ensure null termination
    
    printf("Safely copied: %s\n", safe_buffer);
    
    // Demonstrate safe input
    printf("Safe string input example (simulated):\n");
    char input_buffer[50];
    snprintf(input_buffer, sizeof(input_buffer), "User input: %.20s", "Very long user input that gets truncated");
    printf("%s\n", input_buffer);
}

int* create_array_safely(int size) {
    if (size <= 0) {
        printf("Error: Invalid array size: %d\n", size);
        return NULL;
    }
    
    if (size > 1000000) {  // Reasonable limit
        printf("Error: Array size too large: %d\n", size);
        return NULL;
    }
    
    int* array = malloc(size * sizeof(int));
    if (!array) {
        printf("Error: Failed to allocate memory for %d integers\n", size);
        return NULL;
    }
    
    // Initialize to zero
    for (int i = 0; i < size; i++) {
        array[i] = 0;
    }
    
    return array;
}
