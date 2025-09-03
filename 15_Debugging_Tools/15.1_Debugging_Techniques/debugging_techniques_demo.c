#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

// Debug macro - can be turned on/off with compilation flag
#ifdef DEBUG
    #define DBG_PRINT(fmt, ...) printf("[DEBUG] %s:%d: " fmt "\n", __FILE__, __LINE__, ##__VA_ARGS__)
#else
    #define DBG_PRINT(fmt, ...) do { (void)(fmt); } while(0)
#endif

// Function prototypes
void demonstrate_printf_debugging(void);
void demonstrate_debug_macros(void);
void demonstrate_assertion_debugging(void);
void demonstrate_systematic_debugging(void);
void demonstrate_memory_debugging(void);
void demonstrate_gdb_preparation(void);

// Helper functions with intentional bugs for demonstration
int buggy_factorial(int n);
char* buggy_string_copy(const char* src);
int buggy_array_sum(int arr[], int size);
void buggy_pointer_demo(void);

int main(void) {
    printf("=== Debugging Techniques Demo ===\n\n");
    
    demonstrate_printf_debugging();
    demonstrate_debug_macros();
    demonstrate_assertion_debugging();
    demonstrate_systematic_debugging();
    demonstrate_memory_debugging();
    demonstrate_gdb_preparation();
    
    printf("=== Demo Complete ===\n");
    printf("Compile with -DDEBUG to enable debug output\n");
    printf("Use 'gdb ./debugging_techniques_demo' to debug interactively\n");
    
    return 0;
}

void demonstrate_printf_debugging(void) {
    printf("1. PRINTF DEBUGGING\n");
    printf("----------------------------------------\n");
    
    printf("Basic printf debugging example:\n");
    
    int numbers[] = {1, 2, 3, 4, 5};
    int size = sizeof(numbers) / sizeof(numbers[0]);
    int sum = 0;
    
    printf("Starting array sum calculation...\n");
    printf("Array size: %d\n", size);
    
    for (int i = 0; i < size; i++) {
        printf("Processing element %d: value = %d\n", i, numbers[i]);
        sum += numbers[i];
        printf("Running sum: %d\n", sum);
    }
    
    printf("Final sum: %d\n", sum);
    
    // Demonstrate tracing function calls
    printf("\nFunction call tracing:\n");
    printf("Calling buggy_factorial(5)...\n");
    int result = buggy_factorial(5);
    printf("Result: %d\n", result);
    
    printf("\n");
}

void demonstrate_debug_macros(void) {
    printf("2. DEBUG MACROS\n");
    printf("----------------------------------------\n");
    
    printf("Using conditional debug macros:\n");
    
    int x = 10, y = 20;
    DBG_PRINT("Variables initialized: x=%d, y=%d", x, y);
    
    int result = x + y;
    DBG_PRINT("Addition result: %d + %d = %d", x, y, result);
    
    result = x * y;
    (void)result;  // Suppress unused variable warning
    DBG_PRINT("Multiplication result: %d * %d = %d", x, y, result);
    
    // Demonstrate function entry/exit tracing
    DBG_PRINT("About to call buggy_string_copy");
    char* copied = buggy_string_copy("Hello, World!");
    DBG_PRINT("Returned from buggy_string_copy, result: %s", copied ? copied : "NULL");
    
    if (copied) {
        free(copied);
    }
    
    printf("Note: Debug messages only appear when compiled with -DDEBUG\n");
    printf("\n");
}

void demonstrate_assertion_debugging(void) {
    printf("3. ASSERTION DEBUGGING\n");
    printf("----------------------------------------\n");
    
    printf("Using assertions for debugging:\n");
    
    int* ptr = malloc(sizeof(int) * 5);
    assert(ptr != NULL);  // Ensure allocation succeeded
    printf("Memory allocation successful\n");
    
    // Initialize array
    for (int i = 0; i < 5; i++) {
        ptr[i] = i * i;
        assert(ptr[i] >= 0);  // Ensure values are non-negative
    }
    
    // Verify array contents
    for (int i = 0; i < 5; i++) {
        printf("ptr[%d] = %d\n", i, ptr[i]);
        assert(ptr[i] == i * i);  // Verify expected values
    }
    
    free(ptr);
    printf("All assertions passed\n");
    
    // Demonstrate precondition checking
    printf("\nPrecondition checking example:\n");
    int arr[] = {1, 2, 3, 4, 5};
    int sum = buggy_array_sum(arr, 5);
    printf("Array sum: %d\n", sum);
    
    printf("\n");
}

void demonstrate_systematic_debugging(void) {
    printf("4. SYSTEMATIC DEBUGGING\n");
    printf("----------------------------------------\n");
    
    printf("Systematic approach to debugging:\n");
    
    // Step 1: Reproduce the problem
    printf("Step 1: Reproducing the problem...\n");
    printf("Calling function with known problematic input\n");
    
    // Step 2: Isolate the problem area
    printf("Step 2: Isolating the problem area...\n");
    printf("Testing individual components:\n");
    
    // Test basic functionality
    int test_val = 3;
    printf("Testing factorial(%d)...\n", test_val);
    int fact_result = buggy_factorial(test_val);
    printf("Result: %d (expected: 6)\n", fact_result);
    
    // Step 3: Binary search debugging
    printf("Step 3: Binary search debugging approach...\n");
    printf("Testing edge cases:\n");
    
    printf("factorial(0): %d\n", buggy_factorial(0));
    printf("factorial(1): %d\n", buggy_factorial(1));
    printf("factorial(2): %d\n", buggy_factorial(2));
    
    // Step 4: Verify the fix
    printf("Step 4: After identifying and fixing the bug...\n");
    printf("(In real debugging, you would fix the code and retest)\n");
    
    printf("\n");
}

void demonstrate_memory_debugging(void) {
    printf("5. MEMORY DEBUGGING\n");
    printf("----------------------------------------\n");
    
    printf("Memory debugging techniques:\n");
    
    // Initialize memory to detect uninitialized usage
    printf("Initializing memory to detect uninitialized access...\n");
    int* buffer = malloc(10 * sizeof(int));
    if (buffer) {
        // Initialize with recognizable pattern
        for (int i = 0; i < 10; i++) {
            buffer[i] = 0xDEADBEEF;  // Recognizable pattern
        }
        
        printf("Memory initialized with pattern 0xDEADBEEF\n");
        
        // Use only part of the buffer
        for (int i = 0; i < 5; i++) {
            buffer[i] = i + 1;
        }
        
        // Check for corruption
        printf("Checking for memory corruption...\n");
        for (int i = 5; i < 10; i++) {
            if (buffer[i] != (int)0xDEADBEEF) {
                printf("Memory corruption detected at index %d: 0x%X\n", i, buffer[i]);
            }
        }
        
        free(buffer);
        printf("Memory freed successfully\n");
    }
    
    // Demonstrate pointer debugging
    printf("\nPointer debugging example:\n");
    buggy_pointer_demo();
    
    printf("\n");
}

void demonstrate_gdb_preparation(void) {
    printf("6. GDB PREPARATION\n");
    printf("----------------------------------------\n");
    
    printf("Preparing code for GDB debugging:\n");
    
    // Code with clear variable names and structure for debugging
    int loop_counter = 0;
    int accumulator = 0;
    int test_array[] = {10, 20, 30, 40, 50};
    int array_length = sizeof(test_array) / sizeof(test_array[0]);
    
    printf("Variables set up for easy GDB inspection:\n");
    printf("loop_counter: %d\n", loop_counter);
    printf("accumulator: %d\n", accumulator);
    printf("array_length: %d\n", array_length);
    
    // Loop with clear breakpoint opportunities
    for (loop_counter = 0; loop_counter < array_length; loop_counter++) {
        int current_value = test_array[loop_counter];  // Good breakpoint location
        accumulator += current_value;                   // Another breakpoint location
        
        printf("Iteration %d: current_value=%d, accumulator=%d\n", 
               loop_counter, current_value, accumulator);
    }
    
    printf("\nGDB debugging tips:\n");
    printf("- Compile with -g flag for debug symbols\n");
    printf("- Use meaningful variable names\n");
    printf("- Add strategic breakpoint locations\n");
    printf("- Keep functions reasonably small\n");
    printf("- Use 'gdb ./program' to start debugging\n");
    printf("- Key GDB commands: break, run, next, step, print, backtrace\n");
    
    printf("\n");
}

// Helper functions with intentional bugs for demonstration

int buggy_factorial(int n) {
    DBG_PRINT("Entering buggy_factorial with n=%d", n);
    
    // Bug: doesn't handle n=0 case properly
    if (n <= 1) {
        DBG_PRINT("Base case reached, returning 1");
        return 1;  // Should return 1 for n=0, but this works
    }
    
    int result = n * buggy_factorial(n - 1);
    DBG_PRINT("Calculated %d! = %d", n, result);
    return result;
}

char* buggy_string_copy(const char* src) {
    DBG_PRINT("Entering buggy_string_copy with src='%s'", src ? src : "NULL");
    
    if (!src) {
        DBG_PRINT("Source is NULL, returning NULL");
        return NULL;
    }
    
    size_t len = strlen(src);
    DBG_PRINT("Source length: %zu", len);
    
    // Allocate memory (correct)
    char* dest = malloc(len + 1);
    if (!dest) {
        DBG_PRINT("Memory allocation failed");
        return NULL;
    }
    
    // Copy string (correct)
    strcpy(dest, src);
    DBG_PRINT("String copied successfully: '%s'", dest);
    
    return dest;
}

int buggy_array_sum(int arr[], int size) {
    // Precondition checks
    assert(arr != NULL);
    assert(size >= 0);
    
    DBG_PRINT("Calculating sum of array with %d elements", size);
    
    int sum = 0;
    for (int i = 0; i < size; i++) {
        DBG_PRINT("Adding arr[%d] = %d", i, arr[i]);
        sum += arr[i];
    }
    
    DBG_PRINT("Final sum: %d", sum);
    return sum;
}

void buggy_pointer_demo(void) {
    DBG_PRINT("Entering buggy_pointer_demo");
    
    int value = 42;
    int* ptr = &value;
    
    printf("Original value: %d\n", value);
    printf("Pointer address: %p\n", (void*)ptr);
    printf("Value through pointer: %d\n", *ptr);
    
    // Demonstrate pointer validation
    if (ptr != NULL) {
        printf("Pointer is valid\n");
        *ptr = 100;
        printf("Modified value: %d\n", value);
    } else {
        printf("Pointer is NULL - would cause segmentation fault\n");
    }
    
    // Reset pointer to NULL to demonstrate checking
    ptr = NULL;
    printf("After setting pointer to NULL:\n");
    
    if (ptr != NULL) {
        printf("Value through pointer: %d\n", *ptr);  // Would crash
    } else {
        printf("Pointer is NULL - avoiding dereference\n");
    }
    
    DBG_PRINT("Exiting buggy_pointer_demo");
}
