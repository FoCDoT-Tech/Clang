#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
void demonstrate_passing_pointers(void);
void demonstrate_returning_pointers(void);
void demonstrate_function_pointers(void);
void demonstrate_array_parameters(void);
void demonstrate_callback_functions(void);
void demonstrate_practical_applications(void);

// Helper functions for demonstrations
void swap_values(int *a, int *b);
void get_min_max(int arr[], int size, int *min, int *max);
int* find_largest(int arr[], int size);
char* create_greeting(const char* name);
int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
int divide_safe(int a, int b);
void double_value(int *x);
void square_value(int *x);
void negate_value(int *x);
void apply_operation(int *arr, int size, void (*operation)(int*));
int compare_ascending(const void *a, const void *b);
int compare_descending(const void *a, const void *b);

int main() {
    printf("=== Pointers and Functions Demo ===\n\n");
    
    demonstrate_passing_pointers();
    demonstrate_returning_pointers();
    demonstrate_function_pointers();
    demonstrate_array_parameters();
    demonstrate_callback_functions();
    demonstrate_practical_applications();
    
    printf("=== Demo Complete ===\n");
    return 0;
}

void demonstrate_passing_pointers(void) {
    printf("1. PASSING POINTERS TO FUNCTIONS\n");
    printf("----------------------------------------\n");
    
    // Basic pointer passing
    int x = 10, y = 20;
    printf("Before swap: x = %d, y = %d\n", x, y);
    swap_values(&x, &y);
    printf("After swap: x = %d, y = %d\n", x, y);
    
    // Multiple return values using pointers
    int numbers[] = {45, 12, 78, 23, 67, 34, 89, 56};
    int size = sizeof(numbers) / sizeof(numbers[0]);
    int min, max;
    
    printf("\nArray: [");
    for (int i = 0; i < size; i++) {
        printf("%d", numbers[i]);
        if (i < size - 1) printf(", ");
    }
    printf("]\n");
    
    get_min_max(numbers, size, &min, &max);
    printf("Min: %d, Max: %d\n", min, max);
    
    // Modifying array elements through pointers
    printf("\nModifying individual elements:\n");
    int value = 100;
    printf("  Original value: %d\n", value);
    
    int *ptr = &value;
    *ptr = 200;
    printf("  After modification via pointer: %d\n", value);
    
    // Pointer to pointer example
    int original = 42;
    int *p1 = &original;
    int **p2 = &p1;
    
    printf("\nPointer to pointer:\n");
    printf("  original = %d\n", original);
    printf("  *p1 = %d\n", *p1);
    printf("  **p2 = %d\n", **p2);
    
    **p2 = 84;
    printf("  After **p2 = 84: original = %d\n", original);
    printf("\n");
}

void demonstrate_returning_pointers(void) {
    printf("2. RETURNING POINTERS FROM FUNCTIONS\n");
    printf("----------------------------------------\n");
    
    // Finding largest element
    int data[] = {15, 42, 8, 23, 67, 31, 9};
    int size = sizeof(data) / sizeof(data[0]);
    
    printf("Array: [");
    for (int i = 0; i < size; i++) {
        printf("%d", data[i]);
        if (i < size - 1) printf(", ");
    }
    printf("]\n");
    
    int *largest_ptr = find_largest(data, size);
    if (largest_ptr != NULL) {
        printf("Largest element: %d at index %ld\n", *largest_ptr, largest_ptr - data);
        
        // Modify the largest element
        *largest_ptr = 999;
        printf("After modifying largest: [");
        for (int i = 0; i < size; i++) {
            printf("%d", data[i]);
            if (i < size - 1) printf(", ");
        }
        printf("]\n");
    }
    
    // String creation function
    printf("\nString creation:\n");
    char *greeting1 = create_greeting("Alice");
    char *greeting2 = create_greeting("Bob");
    
    if (greeting1 && greeting2) {
        printf("  %s\n", greeting1);
        printf("  %s\n", greeting2);
        
        // Free allocated memory
        free(greeting1);
        free(greeting2);
    }
    
    // Returning array elements
    printf("\nReturning specific array elements:\n");
    int matrix[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    
    // Find and return pointer to center element
    int *center = &matrix[1][1];
    printf("  Matrix center element: %d\n", *center);
    printf("  Modifying center to 50\n");
    *center = 50;
    
    printf("  Updated matrix:\n");
    for (int i = 0; i < 3; i++) {
        printf("    [");
        for (int j = 0; j < 3; j++) {
            printf("%d", matrix[i][j]);
            if (j < 2) printf(", ");
        }
        printf("]\n");
    }
    printf("\n");
}

void demonstrate_function_pointers(void) {
    printf("3. FUNCTION POINTERS\n");
    printf("----------------------------------------\n");
    
    // Basic function pointer usage
    int a = 15, b = 7;
    printf("Operands: a = %d, b = %d\n", a, b);
    
    // Declare and use function pointers
    int (*operation)(int, int);
    
    operation = add;
    printf("  add: %d + %d = %d\n", a, b, operation(a, b));
    
    operation = subtract;
    printf("  subtract: %d - %d = %d\n", a, b, operation(a, b));
    
    operation = multiply;
    printf("  multiply: %d * %d = %d\n", a, b, operation(a, b));
    
    operation = divide_safe;
    printf("  divide: %d / %d = %d\n", a, b, operation(a, b));
    
    // Array of function pointers
    printf("\nFunction pointer array (calculator):\n");
    int (*operations[])(int, int) = {add, subtract, multiply, divide_safe};
    char *op_names[] = {"add", "subtract", "multiply", "divide"};
    
    for (int i = 0; i < 4; i++) {
        int result = operations[i](a, b);
        printf("  %s(%d, %d) = %d\n", op_names[i], a, b, result);
    }
    
    // Function pointer as parameter
    printf("\nUsing function pointers for flexible operations:\n");
    int x = 10, y = 5;
    
    typedef int (*BinaryOp)(int, int);
    BinaryOp ops[] = {add, multiply};
    char *names[] = {"addition", "multiplication"};
    
    for (int i = 0; i < 2; i++) {
        printf("  %s: %d and %d = %d\n", names[i], x, y, ops[i](x, y));
    }
    printf("\n");
}

void demonstrate_array_parameters(void) {
    printf("4. ARRAY PARAMETERS\n");
    printf("----------------------------------------\n");
    
    int numbers[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int size = sizeof(numbers) / sizeof(numbers[0]);
    
    printf("Original array: [");
    for (int i = 0; i < size; i++) {
        printf("%d", numbers[i]);
        if (i < size - 1) printf(", ");
    }
    printf("]\n");
    
    // Apply different operations
    printf("\nApplying operations to array:\n");
    
    // Double all values
    apply_operation(numbers, size, double_value);
    printf("  After doubling: [");
    for (int i = 0; i < size; i++) {
        printf("%d", numbers[i]);
        if (i < size - 1) printf(", ");
    }
    printf("]\n");
    
    // Square all values
    apply_operation(numbers, size, square_value);
    printf("  After squaring: [");
    for (int i = 0; i < size; i++) {
        printf("%d", numbers[i]);
        if (i < size - 1) printf(", ");
    }
    printf("]\n");
    
    // Negate all values
    apply_operation(numbers, size, negate_value);
    printf("  After negating: [");
    for (int i = 0; i < size; i++) {
        printf("%d", numbers[i]);
        if (i < size - 1) printf(", ");
    }
    printf("]\n");
    
    // Sorting with function pointers
    printf("\nSorting with different comparison functions:\n");
    int sort_data[] = {64, 34, 25, 12, 22, 11, 90};
    int sort_size = sizeof(sort_data) / sizeof(sort_data[0]);
    
    printf("  Original: [");
    for (int i = 0; i < sort_size; i++) {
        printf("%d", sort_data[i]);
        if (i < sort_size - 1) printf(", ");
    }
    printf("]\n");
    
    // Sort ascending
    qsort(sort_data, sort_size, sizeof(int), compare_ascending);
    printf("  Ascending: [");
    for (int i = 0; i < sort_size; i++) {
        printf("%d", sort_data[i]);
        if (i < sort_size - 1) printf(", ");
    }
    printf("]\n");
    
    // Sort descending
    qsort(sort_data, sort_size, sizeof(int), compare_descending);
    printf("  Descending: [");
    for (int i = 0; i < sort_size; i++) {
        printf("%d", sort_data[i]);
        if (i < sort_size - 1) printf(", ");
    }
    printf("]\n\n");
}

void demonstrate_callback_functions(void) {
    printf("5. CALLBACK FUNCTIONS\n");
    printf("----------------------------------------\n");
    
    // Callback function demonstration
    int data[] = {1, 2, 3, 4, 5};
    int size = sizeof(data) / sizeof(data[0]);
    
    printf("Original data: [");
    for (int i = 0; i < size; i++) {
        printf("%d", data[i]);
        if (i < size - 1) printf(", ");
    }
    printf("]\n");
    
    // Create copies for different operations
    int doubled[5], squared[5], negated[5];
    memcpy(doubled, data, sizeof(data));
    memcpy(squared, data, sizeof(data));
    memcpy(negated, data, sizeof(data));
    
    // Apply different callbacks
    apply_operation(doubled, size, double_value);
    apply_operation(squared, size, square_value);
    apply_operation(negated, size, negate_value);
    
    printf("After double callback: [");
    for (int i = 0; i < size; i++) {
        printf("%d", doubled[i]);
        if (i < size - 1) printf(", ");
    }
    printf("]\n");
    
    printf("After square callback: [");
    for (int i = 0; i < size; i++) {
        printf("%d", squared[i]);
        if (i < size - 1) printf(", ");
    }
    printf("]\n");
    
    printf("After negate callback: [");
    for (int i = 0; i < size; i++) {
        printf("%d", negated[i]);
        if (i < size - 1) printf(", ");
    }
    printf("]\n");
    
    // Event-driven callback simulation
    printf("\nEvent-driven callback simulation:\n");
    void (*event_handlers[])(int*) = {double_value, square_value, negate_value};
    char *event_names[] = {"DOUBLE", "SQUARE", "NEGATE"};
    
    int value = 3;
    for (int event = 0; event < 3; event++) {
        int temp = value;
        printf("  Event %s: %d -> ", event_names[event], temp);
        event_handlers[event](&temp);
        printf("%d\n", temp);
    }
    printf("\n");
}

void demonstrate_practical_applications(void) {
    printf("6. PRACTICAL APPLICATIONS\n");
    printf("----------------------------------------\n");
    
    // Application 1: Generic data processing
    printf("Application 1: Generic data processing\n");
    int dataset[] = {10, 25, 5, 40, 15, 30, 20};
    int size = sizeof(dataset) / sizeof(dataset[0]);
    
    printf("  Dataset: [");
    for (int i = 0; i < size; i++) {
        printf("%d", dataset[i]);
        if (i < size - 1) printf(", ");
    }
    printf("]\n");
    
    // Find statistics using pointers
    int min, max;
    get_min_max(dataset, size, &min, &max);
    printf("  Statistics: min=%d, max=%d, range=%d\n", min, max, max - min);
    
    // Application 2: Function dispatch table
    printf("\nApplication 2: Function dispatch table\n");
    typedef enum { ADD_OP, SUB_OP, MUL_OP, DIV_OP } operation_t;
    
    int (*calc_ops[])(int, int) = {add, subtract, multiply, divide_safe};
    char *op_symbols[] = {"+", "-", "*", "/"};
    
    int operand1 = 20, operand2 = 4;
    printf("  Operands: %d and %d\n", operand1, operand2);
    
    for (operation_t op = ADD_OP; op <= DIV_OP; op++) {
        int result = calc_ops[op](operand1, operand2);
        printf("    %d %s %d = %d\n", operand1, op_symbols[op], operand2, result);
    }
    
    // Application 3: Plugin-style architecture
    printf("\nApplication 3: Plugin-style processing\n");
    void (*processors[])(int*) = {double_value, square_value};
    char *processor_names[] = {"Doubler", "Squarer"};
    
    int test_values[] = {2, 3, 4, 5};
    int test_size = sizeof(test_values) / sizeof(test_values[0]);
    
    for (int p = 0; p < 2; p++) {
        printf("  Using %s processor:\n", processor_names[p]);
        int temp_values[4];
        memcpy(temp_values, test_values, sizeof(test_values));
        
        printf("    Before: [");
        for (int i = 0; i < test_size; i++) {
            printf("%d", temp_values[i]);
            if (i < test_size - 1) printf(", ");
        }
        printf("]\n");
        
        apply_operation(temp_values, test_size, processors[p]);
        
        printf("    After:  [");
        for (int i = 0; i < test_size; i++) {
            printf("%d", temp_values[i]);
            if (i < test_size - 1) printf(", ");
        }
        printf("]\n");
    }
    
    // Application 4: State machine using function pointers
    printf("\nApplication 4: Simple state machine\n");
    typedef enum { STATE_INIT, STATE_PROCESS, STATE_FINISH } state_t;
    
    char *state_names[] = {"INIT", "PROCESS", "FINISH"};
    char *state_messages[] = {
        "    Initializing system...",
        "    Processing data...",
        "    Finishing operations..."
    };
    
    for (state_t state = STATE_INIT; state <= STATE_FINISH; state++) {
        printf("  State %s:\n", state_names[state]);
        printf("%s\n", state_messages[state]);
    }
}

// Helper function implementations
void swap_values(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void get_min_max(int arr[], int size, int *min, int *max) {
    if (size <= 0) return;
    
    *min = *max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < *min) *min = arr[i];
        if (arr[i] > *max) *max = arr[i];
    }
}

int* find_largest(int arr[], int size) {
    if (size <= 0) return NULL;
    
    int *largest = &arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > *largest) {
            largest = &arr[i];
        }
    }
    return largest;
}

char* create_greeting(const char* name) {
    if (name == NULL) return NULL;
    
    size_t len = strlen("Hello, ") + strlen(name) + strlen("!") + 1;
    char *greeting = malloc(len);
    
    if (greeting != NULL) {
        sprintf(greeting, "Hello, %s!", name);
    }
    
    return greeting;
}

int add(int a, int b) { return a + b; }
int subtract(int a, int b) { return a - b; }
int multiply(int a, int b) { return a * b; }
int divide_safe(int a, int b) { return (b != 0) ? a / b : 0; }

void double_value(int *x) { *x *= 2; }
void square_value(int *x) { *x *= *x; }
void negate_value(int *x) { *x = -*x; }

void apply_operation(int *arr, int size, void (*operation)(int*)) {
    for (int i = 0; i < size; i++) {
        operation(&arr[i]);
    }
}

int compare_ascending(const void *a, const void *b) {
    int ia = *(const int*)a;
    int ib = *(const int*)b;
    return (ia > ib) - (ia < ib);
}

int compare_descending(const void *a, const void *b) {
    int ia = *(const int*)a;
    int ib = *(const int*)b;
    return (ib > ia) - (ib < ia);
}
