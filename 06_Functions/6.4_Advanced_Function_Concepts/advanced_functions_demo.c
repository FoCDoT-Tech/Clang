#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <time.h>

// Function prototypes for recursion
int factorial_recursive(int n);
int fibonacci_recursive(int n);
int fibonacci_iterative(int n);
void print_countdown(int n);
int gcd(int a, int b);
int power_recursive(int base, int exp);
void print_binary(int n);

// Function prototypes for function pointers and callbacks
int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
int divide_safe(int a, int b);
void bubble_sort(int arr[], int size, int (*compare)(int, int));
int ascending_compare(int a, int b);
int descending_compare(int a, int b);
void process_array(int arr[], int size, void (*processor)(int*, int));
void double_value(int* value, int index);
void square_value(int* value, int index);

// Function prototypes for variadic functions
int sum_integers(int count, ...);
double average_doubles(int count, ...);
void print_formatted(const char* format, ...);
char* concatenate_strings(int count, ...);
int find_max_variadic(int count, ...);

// Calculator function pointer type
typedef int (*calculator_func)(int, int);

// Callback function type for array processing
typedef void (*array_processor)(int*, int);

int main() {
    printf("=== Advanced Function Concepts Demo ===\n\n");
    
    // 1. RECURSIVE FUNCTIONS
    printf("1. RECURSIVE FUNCTIONS\n");
    printf("----------------------------------------\n");
    
    // Factorial examples
    printf("Factorial calculations:\n");
    for (int i = 0; i <= 8; i++) {
        printf("%d! = %d\n", i, factorial_recursive(i));
    }
    
    // Fibonacci sequence
    printf("\nFibonacci sequence (first 12 numbers):\n");
    printf("Recursive: ");
    for (int i = 0; i < 12; i++) {
        printf("%d ", fibonacci_recursive(i));
    }
    printf("\nIterative: ");
    for (int i = 0; i < 12; i++) {
        printf("%d ", fibonacci_iterative(i));
    }
    printf("\n");
    
    // GCD (Greatest Common Divisor)
    printf("\nGCD calculations:\n");
    printf("GCD(48, 18) = %d\n", gcd(48, 18));
    printf("GCD(100, 25) = %d\n", gcd(100, 25));
    printf("GCD(17, 13) = %d\n", gcd(17, 13));
    
    // Power calculation
    printf("\nPower calculations:\n");
    printf("2^10 = %d\n", power_recursive(2, 10));
    printf("3^4 = %d\n", power_recursive(3, 4));
    printf("5^3 = %d\n", power_recursive(5, 3));
    
    // Binary representation
    printf("\nBinary representations:\n");
    int numbers[] = {10, 25, 42, 100};
    for (int i = 0; i < 4; i++) {
        printf("%d in binary: ", numbers[i]);
        print_binary(numbers[i]);
        printf("\n");
    }
    
    // Countdown demonstration
    printf("\nCountdown from 5:\n");
    print_countdown(5);
    printf("\n\n");
    
    // 2. FUNCTION POINTERS
    printf("2. FUNCTION POINTERS\n");
    printf("----------------------------------------\n");
    
    // Basic function pointer usage
    calculator_func calc_ptr;
    int x = 15, y = 7;
    
    printf("Calculator with x=%d, y=%d:\n", x, y);
    
    calc_ptr = add;
    printf("Addition: %d\n", calc_ptr(x, y));
    
    calc_ptr = subtract;
    printf("Subtraction: %d\n", calc_ptr(x, y));
    
    calc_ptr = multiply;
    printf("Multiplication: %d\n", calc_ptr(x, y));
    
    calc_ptr = divide_safe;
    printf("Division: %d\n", calc_ptr(x, y));
    
    // Function pointer array (function table)
    printf("\nFunction table demonstration:\n");
    calculator_func operations[] = {add, subtract, multiply, divide_safe};
    const char* op_names[] = {"Add", "Subtract", "Multiply", "Divide"};
    
    for (int i = 0; i < 4; i++) {
        printf("%s(%d, %d) = %d\n", op_names[i], x, y, operations[i](x, y));
    }
    printf("\n");
    
    // 3. CALLBACK FUNCTIONS
    printf("3. CALLBACK FUNCTIONS\n");
    printf("----------------------------------------\n");
    
    // Sorting with different comparison callbacks
    int arr1[] = {64, 34, 25, 12, 22, 11, 90};
    int arr2[] = {64, 34, 25, 12, 22, 11, 90};
    int size = sizeof(arr1) / sizeof(arr1[0]);
    
    printf("Original array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr1[i]);
    }
    printf("\n");
    
    // Sort ascending
    bubble_sort(arr1, size, ascending_compare);
    printf("Ascending sort: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr1[i]);
    }
    printf("\n");
    
    // Sort descending
    bubble_sort(arr2, size, descending_compare);
    printf("Descending sort: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr2[i]);
    }
    printf("\n");
    
    // Array processing with callbacks
    int data[] = {1, 2, 3, 4, 5};
    int data_size = sizeof(data) / sizeof(data[0]);
    
    printf("\nArray processing with callbacks:\n");
    printf("Original: ");
    for (int i = 0; i < data_size; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");
    
    // Double all values
    int data_copy1[] = {1, 2, 3, 4, 5};
    process_array(data_copy1, data_size, double_value);
    printf("Doubled: ");
    for (int i = 0; i < data_size; i++) {
        printf("%d ", data_copy1[i]);
    }
    printf("\n");
    
    // Square all values
    int data_copy2[] = {1, 2, 3, 4, 5};
    process_array(data_copy2, data_size, square_value);
    printf("Squared: ");
    for (int i = 0; i < data_size; i++) {
        printf("%d ", data_copy2[i]);
    }
    printf("\n\n");
    
    // 4. VARIABLE ARGUMENTS (VARIADIC FUNCTIONS)
    printf("4. VARIABLE ARGUMENTS (VARIADIC FUNCTIONS)\n");
    printf("----------------------------------------\n");
    
    // Sum function with variable arguments
    printf("Sum calculations:\n");
    printf("sum(3, 10, 20, 30) = %d\n", sum_integers(3, 10, 20, 30));
    printf("sum(5, 1, 2, 3, 4, 5) = %d\n", sum_integers(5, 1, 2, 3, 4, 5));
    printf("sum(2, 100, 200) = %d\n", sum_integers(2, 100, 200));
    
    // Average function
    printf("\nAverage calculations:\n");
    printf("avg(3, 10.5, 20.3, 15.2) = %.2f\n", average_doubles(3, 10.5, 20.3, 15.2));
    printf("avg(4, 1.0, 2.0, 3.0, 4.0) = %.2f\n", average_doubles(4, 1.0, 2.0, 3.0, 4.0));
    
    // Maximum finder
    printf("\nMaximum finder:\n");
    printf("max(4, 45, 23, 78, 12) = %d\n", find_max_variadic(4, 45, 23, 78, 12));
    printf("max(6, 10, 5, 25, 30, 15, 20) = %d\n", find_max_variadic(6, 10, 5, 25, 30, 15, 20));
    
    // String concatenation
    printf("\nString concatenation:\n");
    char* result1 = concatenate_strings(3, "Hello", " ", "World");
    printf("concat(\"Hello\", \" \", \"World\") = \"%s\"\n", result1);
    free(result1);
    
    char* result2 = concatenate_strings(4, "C", " is", " awesome", "!");
    printf("concat(\"C\", \" is\", \" awesome\", \"!\") = \"%s\"\n", result2);
    free(result2);
    
    // Custom formatted printing
    printf("\nCustom formatted printing:\n");
    print_formatted("Integer: %d, Float: %.2f, String: %s", 42, 3.14159, "Hello");
    printf("\n\n");
    
    // 5. PRACTICAL EXAMPLE - ADVANCED CALCULATOR
    printf("5. PRACTICAL EXAMPLE - ADVANCED CALCULATOR\n");
    printf("----------------------------------------\n");
    
    // Menu-driven calculator using function pointers
    printf("Advanced Calculator Menu:\n");
    printf("Available operations: Add, Subtract, Multiply, Divide\n");
    
    // Simulate user selections
    int operands[][2] = {{15, 3}, {20, 4}, {7, 2}, {100, 5}};
    int op_indices[] = {0, 1, 2, 3}; // Add, Subtract, Multiply, Divide
    
    for (int i = 0; i < 4; i++) {
        int a = operands[i][0];
        int b = operands[i][1];
        int op_idx = op_indices[i];
        
        printf("Operation: %s(%d, %d) = %d\n", 
               op_names[op_idx], a, b, operations[op_idx](a, b));
    }
    
    // Recursive calculation example
    printf("\nRecursive calculations:\n");
    printf("Factorial of 6: %d\n", factorial_recursive(6));
    printf("10th Fibonacci number: %d\n", fibonacci_recursive(10));
    printf("GCD of 84 and 36: %d\n", gcd(84, 36));
    
    // Variadic summary function
    printf("\nSummary statistics:\n");
    int stats_data[] = {85, 92, 78, 96, 88, 74, 91};
    int stats_count = sizeof(stats_data) / sizeof(stats_data[0]);
    
    // Using variadic function for flexible statistics
    printf("Sum of %d numbers: %d\n", stats_count, 
           sum_integers(stats_count, 85, 92, 78, 96, 88, 74, 91));
    printf("Average: %.2f\n", 
           average_doubles(stats_count, 85.0, 92.0, 78.0, 96.0, 88.0, 74.0, 91.0));
    printf("Maximum: %d\n", 
           find_max_variadic(stats_count, 85, 92, 78, 96, 88, 74, 91));
    
    printf("\n=== Demo Complete ===\n");
    return 0;
}

// RECURSIVE FUNCTION IMPLEMENTATIONS

int factorial_recursive(int n) {
    if (n < 0) return -1;  // Error case
    if (n == 0 || n == 1) return 1;  // Base case
    return n * factorial_recursive(n - 1);  // Recursive case
}

int fibonacci_recursive(int n) {
    if (n < 0) return -1;  // Error case
    if (n == 0) return 0;  // Base case
    if (n == 1) return 1;  // Base case
    return fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2);  // Recursive case
}

int fibonacci_iterative(int n) {
    if (n < 0) return -1;
    if (n == 0) return 0;
    if (n == 1) return 1;
    
    int prev = 0, curr = 1, next;
    for (int i = 2; i <= n; i++) {
        next = prev + curr;
        prev = curr;
        curr = next;
    }
    return curr;
}

void print_countdown(int n) {
    if (n <= 0) {
        printf("Blast off!\n");
        return;  // Base case
    }
    printf("%d... ", n);
    print_countdown(n - 1);  // Recursive case
}

int gcd(int a, int b) {
    if (b == 0) return a;  // Base case
    return gcd(b, a % b);  // Recursive case
}

int power_recursive(int base, int exp) {
    if (exp == 0) return 1;  // Base case
    if (exp == 1) return base;  // Base case
    return base * power_recursive(base, exp - 1);  // Recursive case
}

void print_binary(int n) {
    if (n == 0) return;  // Base case
    print_binary(n / 2);  // Recursive case
    printf("%d", n % 2);
}

// FUNCTION POINTER IMPLEMENTATIONS

int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

int divide_safe(int a, int b) {
    return (b != 0) ? a / b : 0;
}

// CALLBACK FUNCTION IMPLEMENTATIONS

void bubble_sort(int arr[], int size, int (*compare)(int, int)) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (compare(arr[j], arr[j + 1]) > 0) {
                // Swap elements
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int ascending_compare(int a, int b) {
    return a - b;  // Positive if a > b
}

int descending_compare(int a, int b) {
    return b - a;  // Positive if b > a
}

void process_array(int arr[], int size, void (*processor)(int*, int)) {
    for (int i = 0; i < size; i++) {
        processor(&arr[i], i);
    }
}

void double_value(int* value, int index) {
    (void)index;  // Unused parameter
    *value *= 2;
}

void square_value(int* value, int index) {
    (void)index;  // Unused parameter
    *value *= *value;
}

// VARIADIC FUNCTION IMPLEMENTATIONS

int sum_integers(int count, ...) {
    va_list args;
    va_start(args, count);
    
    int sum = 0;
    for (int i = 0; i < count; i++) {
        sum += va_arg(args, int);
    }
    
    va_end(args);
    return sum;
}

double average_doubles(int count, ...) {
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

void print_formatted(const char* format, ...) {
    va_list args;
    va_start(args, format);
    
    printf("Custom format: ");
    vprintf(format, args);
    
    va_end(args);
}

char* concatenate_strings(int count, ...) {
    va_list args;
    va_start(args, count);
    
    // Calculate total length needed
    int total_length = 1;  // For null terminator
    va_list args_copy;
    va_copy(args_copy, args);
    
    for (int i = 0; i < count; i++) {
        char* str = va_arg(args_copy, char*);
        total_length += strlen(str);
    }
    va_end(args_copy);
    
    // Allocate memory and concatenate
    char* result = malloc(total_length);
    if (result) {
        result[0] = '\0';
        for (int i = 0; i < count; i++) {
            char* str = va_arg(args, char*);
            strcat(result, str);
        }
    }
    
    va_end(args);
    return result;
}

int find_max_variadic(int count, ...) {
    if (count == 0) return 0;
    
    va_list args;
    va_start(args, count);
    
    int max = va_arg(args, int);
    for (int i = 1; i < count; i++) {
        int current = va_arg(args, int);
        if (current > max) {
            max = current;
        }
    }
    
    va_end(args);
    return max;
}
