#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

// Function prototypes
void demonstrate_basic_variadic(void);
void demonstrate_type_safe_variadic(void);
void demonstrate_string_processing(void);
void demonstrate_mathematical_operations(void);
void demonstrate_logging_debugging(void);
void demonstrate_error_handling(void);
void demonstrate_performance_optimization(void);

// Type enumeration for type-safe variadic functions
typedef enum {
    ARG_INT,
    ARG_DOUBLE,
    ARG_STRING,
    ARG_END
} ArgType;

// Result enumeration for error handling
typedef enum {
    VARARG_SUCCESS,
    VARARG_NULL_POINTER,
    VARARG_INVALID_COUNT,
    VARARG_MEMORY_ERROR
} VarArgResult;

// Log levels
typedef enum {
    LOG_DEBUG,
    LOG_INFO,
    LOG_WARNING,
    LOG_ERROR
} LogLevel;

// Generic list structure
typedef struct {
    void** items;
    size_t count;
    size_t capacity;
} GenericList;

// Matrix structure
typedef struct {
    double* data;
    int rows, cols;
} Matrix;

// Command function pointer type
typedef void (*CommandFunc)(const char* format, ...);

// Command structure
typedef struct {
    const char* name;
    CommandFunc func;
} Command;

// Basic variadic functions
int sum_integers(int count, ...) {
    va_list args;
    va_start(args, count);
    
    int total = 0;
    for (int i = 0; i < count; i++) {
        total += va_arg(args, int);
    }
    
    va_end(args);
    return total;
}

void debug_printf(const char* format, ...) {
    printf("[DEBUG] ");
    
    va_list args;
    va_start(args, format);
    vprintf(format, args);
    va_end(args);
    
    printf("\n");
}

// Type-safe variadic function
void print_args(ArgType type, ...) {
    va_list args;
    va_start(args, type);
    
    while (type != ARG_END) {
        switch (type) {
            case ARG_INT:
                printf("Integer: %d\n", va_arg(args, int));
                break;
            case ARG_DOUBLE:
                printf("Double: %.2f\n", va_arg(args, double));
                break;
            case ARG_STRING:
                printf("String: %s\n", va_arg(args, char*));
                break;
            case ARG_END:
                break;
        }
        type = va_arg(args, ArgType);
    }
    
    va_end(args);
}

// Generic list creation
GenericList* create_list(size_t count, ...) {
    GenericList* list = malloc(sizeof(GenericList));
    if (list == NULL) return NULL;
    
    list->items = malloc(count * sizeof(void*));
    if (list->items == NULL) {
        free(list);
        return NULL;
    }
    
    list->count = count;
    list->capacity = count;
    
    va_list args;
    va_start(args, count);
    
    for (size_t i = 0; i < count; i++) {
        list->items[i] = va_arg(args, void*);
    }
    
    va_end(args);
    return list;
}

void free_list(GenericList* list) {
    if (list) {
        free(list->items);
        free(list);
    }
}

// String processing functions
int my_sprintf(char* buffer, const char* format, ...) {
    va_list args;
    va_start(args, format);
    
    int result = vsprintf(buffer, format, args);
    
    va_end(args);
    return result;
}

int my_snprintf(char* buffer, size_t size, const char* format, ...) {
    va_list args;
    va_start(args, format);
    
    int result = vsnprintf(buffer, size, format, args);
    
    va_end(args);
    return result;
}

char* concat_strings(int count, ...) {
    va_list args;
    va_start(args, count);
    
    // Calculate total length
    size_t total_len = 0;
    va_list args_copy;
    va_copy(args_copy, args);
    
    for (int i = 0; i < count; i++) {
        const char* str = va_arg(args_copy, const char*);
        if (str) total_len += strlen(str);
    }
    va_end(args_copy);
    
    // Allocate and concatenate
    char* result = malloc(total_len + 1);
    if (result == NULL) {
        va_end(args);
        return NULL;
    }
    
    result[0] = '\0';
    
    for (int i = 0; i < count; i++) {
        const char* str = va_arg(args, const char*);
        if (str) strcat(result, str);
    }
    
    va_end(args);
    return result;
}

// Mathematical operations
double average(int count, ...) {
    if (count == 0) return 0.0;
    
    va_list args;
    va_start(args, count);
    
    double sum = 0.0;
    for (int i = 0; i < count; i++) {
        sum += va_arg(args, double);
    }
    
    va_end(args);
    return sum / count;
}

double max_value(int count, ...) {
    if (count == 0) return 0.0;
    
    va_list args;
    va_start(args, count);
    
    double max = va_arg(args, double);
    for (int i = 1; i < count; i++) {
        double val = va_arg(args, double);
        if (val > max) max = val;
    }
    
    va_end(args);
    return max;
}

Matrix* create_matrix_from_values(int rows, int cols, ...) {
    Matrix* matrix = malloc(sizeof(Matrix));
    if (matrix == NULL) return NULL;
    
    matrix->rows = rows;
    matrix->cols = cols;
    matrix->data = malloc(rows * cols * sizeof(double));
    if (matrix->data == NULL) {
        free(matrix);
        return NULL;
    }
    
    va_list args;
    va_start(args, cols);
    
    for (int i = 0; i < rows * cols; i++) {
        matrix->data[i] = va_arg(args, double);
    }
    
    va_end(args);
    return matrix;
}

void free_matrix(Matrix* matrix) {
    if (matrix) {
        free(matrix->data);
        free(matrix);
    }
}

void print_matrix(Matrix* matrix) {
    if (matrix == NULL) return;
    
    for (int i = 0; i < matrix->rows; i++) {
        for (int j = 0; j < matrix->cols; j++) {
            printf("%6.2f ", matrix->data[i * matrix->cols + j]);
        }
        printf("\n");
    }
}

// Logging functions
void log_message(LogLevel level, const char* format, ...) {
    const char* level_names[] = {"DEBUG", "INFO", "WARN", "ERROR"};
    
    printf("[%s] ", level_names[level]);
    
    va_list args;
    va_start(args, format);
    vprintf(format, args);
    va_end(args);
    
    printf("\n");
}

void assert_with_message(int condition, const char* format, ...) {
    if (!condition) {
        printf("Assertion failed: ");
        
        va_list args;
        va_start(args, format);
        vprintf(format, args);
        va_end(args);
        
        printf("\n");
        // In real code, you would call abort() here
        // abort();
    }
}

// Command functions
void cmd_print(const char* format, ...) {
    va_list args;
    va_start(args, format);
    vprintf(format, args);
    va_end(args);
    printf("\n");
}

void cmd_error(const char* format, ...) {
    printf("ERROR: ");
    va_list args;
    va_start(args, format);
    vprintf(format, args);
    va_end(args);
    printf("\n");
}

// Command array
Command commands[] = {
    {"print", cmd_print},
    {"error", cmd_error},
    {NULL, NULL}
};

void execute_command(const char* cmd_name, const char* format, ...) {
    for (int i = 0; commands[i].name; i++) {
        if (strcmp(commands[i].name, cmd_name) == 0) {
            va_list args;
            va_start(args, format);
            
            // Create a temporary buffer for the formatted string
            char buffer[1024];
            vsnprintf(buffer, sizeof(buffer), format, args);
            
            // Call the command function with the formatted string
            commands[i].func("%s", buffer);
            
            va_end(args);
            return;
        }
    }
    printf("Unknown command: %s\n", cmd_name);
}

// Error handling functions
VarArgResult safe_sum(double* result, int count, ...) {
    if (result == NULL) return VARARG_NULL_POINTER;
    if (count < 0) return VARARG_INVALID_COUNT;
    
    *result = 0.0;
    
    if (count == 0) return VARARG_SUCCESS;
    
    va_list args;
    va_start(args, count);
    
    for (int i = 0; i < count; i++) {
        *result += va_arg(args, double);
    }
    
    va_end(args);
    return VARARG_SUCCESS;
}

// Sentinel validation
#define MAGIC_SENTINEL 0xDEADBEEF

int validated_sum(uint32_t sentinel, int count, ...) {
    if (sentinel != MAGIC_SENTINEL) {
        fprintf(stderr, "Invalid sentinel value\n");
        return -1;
    }
    
    va_list args;
    va_start(args, count);
    
    int sum = 0;
    for (int i = 0; i < count; i++) {
        sum += va_arg(args, int);
    }
    
    va_end(args);
    return sum;
}

// Performance optimization functions
static inline int sum_2(int a, int b) {
    return a + b;
}

static inline int sum_3(int a, int b, int c) {
    return a + b + c;
}

int sum_array(const int* values, size_t count) {
    int sum = 0;
    for (size_t i = 0; i < count; i++) {
        sum += values[i];
    }
    return sum;
}

int sum_large(int count, ...) {
    if (count <= 10) {
        va_list args;
        va_start(args, count);
        int sum = 0;
        for (int i = 0; i < count; i++) {
            sum += va_arg(args, int);
        }
        va_end(args);
        return sum;
    } else {
        int* temp = malloc(count * sizeof(int));
        if (temp == NULL) return 0;
        
        va_list args;
        va_start(args, count);
        for (int i = 0; i < count; i++) {
            temp[i] = va_arg(args, int);
        }
        va_end(args);
        
        int result = sum_array(temp, count);
        free(temp);
        return result;
    }
}

// Format multiple function
char* format_multiple(int count, ...) {
    va_list args;
    va_start(args, count);
    
    size_t total_len = 1;  // Start with 1 for null terminator
    char* result = malloc(total_len);
    if (result == NULL) {
        va_end(args);
        return NULL;
    }
    result[0] = '\0';
    
    for (int i = 0; i < count; i++) {
        const char* format = va_arg(args, const char*);
        
        char buffer[256];
        if (strstr(format, "%s")) {
            const char* str_val = va_arg(args, const char*);
            snprintf(buffer, sizeof(buffer), format, str_val);
        } else if (strstr(format, "%d")) {
            int int_val = va_arg(args, int);
            snprintf(buffer, sizeof(buffer), format, int_val);
        } else if (strstr(format, "%f") || strstr(format, "%.")) {
            double double_val = va_arg(args, double);
            snprintf(buffer, sizeof(buffer), format, double_val);
        } else {
            strcpy(buffer, format);
        }
        
        size_t buffer_len = strlen(buffer);
        size_t separator_len = (i > 0) ? 2 : 0;  // ", "
        size_t new_total = total_len + buffer_len + separator_len;
        
        char* new_result = realloc(result, new_total);
        if (new_result == NULL) {
            free(result);
            va_end(args);
            return NULL;
        }
        result = new_result;
        
        if (i > 0) strcat(result, ", ");
        strcat(result, buffer);
        total_len = new_total;
    }
    
    va_end(args);
    return result;
}

int main(void) {
    printf("=== Variable Arguments Demo ===\n\n");
    
    demonstrate_basic_variadic();
    demonstrate_type_safe_variadic();
    demonstrate_string_processing();
    demonstrate_mathematical_operations();
    demonstrate_logging_debugging();
    demonstrate_error_handling();
    demonstrate_performance_optimization();
    
    printf("=== Demo Complete ===\n");
    return 0;
}

void demonstrate_basic_variadic(void) {
    printf("1. BASIC VARIADIC FUNCTIONS\n");
    printf("----------------------------------------\n");
    
    // Sum integers
    printf("Sum of integers:\n");
    printf("  sum_integers(4, 10, 20, 30, 40) = %d\n", 
           sum_integers(4, 10, 20, 30, 40));
    printf("  sum_integers(3, 5, 15, 25) = %d\n", 
           sum_integers(3, 5, 15, 25));
    printf("  sum_integers(1, 100) = %d\n", 
           sum_integers(1, 100));
    
    // Debug printf
    printf("\nDebug printf examples:\n");
    debug_printf("Value: %d, Name: %s", 42, "test");
    debug_printf("Connection established to %s:%d", "localhost", 8080);
    debug_printf("Processing %d items", 150);
    
    printf("\n");
}

void demonstrate_type_safe_variadic(void) {
    printf("2. TYPE-SAFE VARIADIC FUNCTIONS\n");
    printf("----------------------------------------\n");
    
    printf("Type-safe argument printing:\n");
    print_args(ARG_INT, 42, 
               ARG_STRING, "Hello World", 
               ARG_DOUBLE, 3.14159, 
               ARG_INT, 100,
               ARG_STRING, "Goodbye",
               ARG_END);
    
    // Generic list
    printf("\nGeneric list creation:\n");
    int a = 10, b = 20, c = 30;
    char str1[] = "First";
    char str2[] = "Second";
    
    GenericList* int_list = create_list(3, &a, &b, &c);
    GenericList* str_list = create_list(2, str1, str2);
    
    if (int_list) {
        printf("Integer list: ");
        for (size_t i = 0; i < int_list->count; i++) {
            printf("%d ", *(int*)int_list->items[i]);
        }
        printf("\n");
        free_list(int_list);
    }
    
    if (str_list) {
        printf("String list: ");
        for (size_t i = 0; i < str_list->count; i++) {
            printf("'%s' ", (char*)str_list->items[i]);
        }
        printf("\n");
        free_list(str_list);
    }
    
    printf("\n");
}

void demonstrate_string_processing(void) {
    printf("3. STRING PROCESSING\n");
    printf("----------------------------------------\n");
    
    // Custom sprintf
    printf("Custom sprintf functions:\n");
    char buffer[256];
    
    my_sprintf(buffer, "Value: %d, Pi: %.2f", 42, 3.14159);
    printf("  my_sprintf result: %s\n", buffer);
    
    my_snprintf(buffer, sizeof(buffer), "Safe formatting: %s %d", "test", 123);
    printf("  my_snprintf result: %s\n", buffer);
    
    // String concatenation
    printf("\nString concatenation:\n");
    char* combined = concat_strings(4, "Hello", " ", "World", "!");
    if (combined) {
        printf("  Concatenated: '%s'\n", combined);
        free(combined);
    }
    
    char* path = concat_strings(3, "/usr", "/local", "/bin");
    if (path) {
        printf("  Path: '%s'\n", path);
        free(path);
    }
    
    printf("\n");
}

void demonstrate_mathematical_operations(void) {
    printf("4. MATHEMATICAL OPERATIONS\n");
    printf("----------------------------------------\n");
    
    // Statistical functions
    printf("Statistical functions:\n");
    double avg1 = average(4, 1.0, 2.0, 3.0, 4.0);
    printf("  average(4, 1.0, 2.0, 3.0, 4.0) = %.2f\n", avg1);
    
    double avg2 = average(5, 10.5, 20.3, 15.7, 8.2, 12.1);
    printf("  average(5, 10.5, 20.3, 15.7, 8.2, 12.1) = %.2f\n", avg2);
    
    double max1 = max_value(3, 5.5, 2.1, 8.3);
    printf("  max_value(3, 5.5, 2.1, 8.3) = %.2f\n", max1);
    
    double max2 = max_value(4, -1.5, -3.2, -0.8, -2.1);
    printf("  max_value(4, -1.5, -3.2, -0.8, -2.1) = %.2f\n", max2);
    
    // Matrix creation
    printf("\nMatrix creation from values:\n");
    Matrix* matrix = create_matrix_from_values(3, 3,
                                              1.0, 2.0, 3.0,
                                              4.0, 5.0, 6.0,
                                              7.0, 8.0, 9.0);
    if (matrix) {
        printf("  3x3 Matrix:\n");
        print_matrix(matrix);
        free_matrix(matrix);
    }
    
    printf("\n");
}

void demonstrate_logging_debugging(void) {
    printf("5. LOGGING AND DEBUGGING\n");
    printf("----------------------------------------\n");
    
    // Multi-level logging
    printf("Multi-level logging:\n");
    log_message(LOG_DEBUG, "Debug message: variable x = %d", 42);
    log_message(LOG_INFO, "Server started on port %d", 8080);
    log_message(LOG_WARNING, "Low memory warning: %d%% used", 85);
    log_message(LOG_ERROR, "Failed to connect to %s:%d", "database", 3306);
    
    // Assertions with messages
    printf("\nAssertion with custom messages:\n");
    int* test_ptr = malloc(sizeof(int));
    *test_ptr = 100;
    
    assert_with_message(test_ptr != NULL, "Pointer %p should not be NULL", (void*)test_ptr);
    printf("  Assertion passed: pointer is valid\n");
    
    assert_with_message(*test_ptr > 0, "Value %d must be positive", *test_ptr);
    printf("  Assertion passed: value is positive\n");
    
    free(test_ptr);
    
    // Command dispatcher
    printf("\nCommand dispatcher:\n");
    execute_command("print", "Hello from command: %s", "print");
    execute_command("error", "Error code: %d", 404);
    execute_command("unknown", "This won't work");
    
    printf("\n");
}

void demonstrate_error_handling(void) {
    printf("6. ERROR HANDLING AND SAFETY\n");
    printf("----------------------------------------\n");
    
    // Safe variadic functions
    printf("Safe variadic functions:\n");
    double result;
    VarArgResult res;
    
    res = safe_sum(&result, 3, 1.0, 2.0, 3.0);
    if (res == VARARG_SUCCESS) {
        printf("  Safe sum successful: %.2f\n", result);
    } else {
        printf("  Safe sum failed with error: %d\n", res);
    }
    
    res = safe_sum(NULL, 3, 1.0, 2.0, 3.0);
    printf("  Safe sum with NULL pointer: %s\n", 
           (res == VARARG_NULL_POINTER) ? "Correctly detected error" : "Failed");
    
    res = safe_sum(&result, -1, 1.0);
    printf("  Safe sum with negative count: %s\n", 
           (res == VARARG_INVALID_COUNT) ? "Correctly detected error" : "Failed");
    
    // Sentinel validation
    printf("\nSentinel validation:\n");
    int valid_result = validated_sum(MAGIC_SENTINEL, 3, 10, 20, 30);
    printf("  Valid sentinel result: %d\n", valid_result);
    
    int invalid_result = validated_sum(0x12345678, 3, 10, 20, 30);
    printf("  Invalid sentinel result: %d\n", invalid_result);
    
    printf("\n");
}

void demonstrate_performance_optimization(void) {
    printf("7. PERFORMANCE OPTIMIZATION\n");
    printf("----------------------------------------\n");
    
    // Inline functions for small cases
    printf("Optimized functions:\n");
    printf("  sum_2(10, 20) = %d\n", sum_2(10, 20));
    printf("  sum_3(5, 10, 15) = %d\n", sum_3(5, 10, 15));
    
    // Large argument handling
    printf("\nLarge argument list handling:\n");
    int small_result = sum_large(4, 1, 2, 3, 4);
    printf("  Small list (4 args): %d\n", small_result);
    
    int large_result = sum_large(15, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
    printf("  Large list (15 args): %d\n", large_result);
    
    // Format multiple demonstration
    printf("\nAdvanced formatting:\n");
    char* formatted = format_multiple(3, 
                                    "Name: %s", "John Doe",
                                    "Age: %d", 30,
                                    "Score: %.1f", 95.5);
    if (formatted) {
        printf("  Formatted result: %s\n", formatted);
        free(formatted);
    }
    
    printf("\n");
}
