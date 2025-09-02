#include <stdio.h>
#include <string.h>

// Function prototypes demonstrating different parameter types
void pass_by_value_demo(int x, double y);
void pass_by_reference_demo(int* x, double* y);
void swap_values(int* a, int* b);
void swap_values_wrong(int a, int b);
void print_array(const int arr[], int size);
void modify_array(int arr[], int size, int increment);
int sum_array(const int arr[], int size);
void process_string(char* str);
void process_string_const(const char* str);
double calculate_average(const int numbers[], int count);
void get_min_max(const int arr[], int size, int* min, int* max);
void demonstrate_scope(int param);

// Global variable for demonstration
int global_var = 100;

int main() {
    printf("=== Parameters & Arguments Demo ===\n\n");
    
    // 1. PASS BY VALUE
    printf("1. PASS BY VALUE\n");
    
    int num = 10;
    double decimal = 3.14;
    
    printf("Before function call: num = %d, decimal = %.2f\n", num, decimal);
    pass_by_value_demo(num, decimal);
    printf("After function call: num = %d, decimal = %.2f\n", num, decimal);
    printf("→ Original values unchanged (pass by value)\n\n");
    
    // 2. PASS BY REFERENCE (POINTERS)
    printf("2. PASS BY REFERENCE (POINTERS)\n");
    
    int x = 20;
    double y = 2.71;
    
    printf("Before function call: x = %d, y = %.2f\n", x, y);
    pass_by_reference_demo(&x, &y);
    printf("After function call: x = %d, y = %.2f\n", x, y);
    printf("→ Original values modified (pass by reference)\n\n");
    
    // 3. SWAPPING VALUES - CORRECT VS INCORRECT
    printf("3. SWAPPING VALUES DEMONSTRATION\n");
    
    int a = 5, b = 15;
    printf("Original: a = %d, b = %d\n", a, b);
    
    // Wrong way (pass by value)
    swap_values_wrong(a, b);
    printf("After wrong swap: a = %d, b = %d (no change)\n", a, b);
    
    // Correct way (pass by reference)
    swap_values(&a, &b);
    printf("After correct swap: a = %d, b = %d (swapped!)\n", a, b);
    printf("\n");
    
    // 4. ARRAY PARAMETERS
    printf("4. ARRAY PARAMETERS\n");
    
    int numbers[] = {1, 2, 3, 4, 5};
    int size = sizeof(numbers) / sizeof(numbers[0]);
    
    printf("Original array: ");
    print_array(numbers, size);
    
    printf("Sum of array: %d\n", sum_array(numbers, size));
    printf("Average: %.2f\n", calculate_average(numbers, size));
    
    // Modify array through function
    modify_array(numbers, size, 10);
    printf("After adding 10 to each element: ");
    print_array(numbers, size);
    printf("\n");
    
    // 5. MULTIPLE RETURN VALUES USING POINTERS
    printf("5. MULTIPLE RETURN VALUES\n");
    
    int test_array[] = {45, 12, 78, 23, 67, 34, 89, 56};
    int test_size = sizeof(test_array) / sizeof(test_array[0]);
    int min_val, max_val;
    
    printf("Array: ");
    print_array(test_array, test_size);
    
    get_min_max(test_array, test_size, &min_val, &max_val);
    printf("Minimum: %d, Maximum: %d\n\n", min_val, max_val);
    
    // 6. STRING PARAMETERS
    printf("6. STRING PARAMETERS\n");
    
    char message[] = "hello world";
    printf("Original string: \"%s\"\n", message);
    
    // Read-only processing
    process_string_const(message);
    printf("After const processing: \"%s\" (unchanged)\n", message);
    
    // Modifying processing
    process_string(message);
    printf("After modifying processing: \"%s\" (modified)\n", message);
    printf("\n");
    
    // 7. CONST PARAMETERS DEMONSTRATION
    printf("7. CONST PARAMETERS\n");
    
    const int readonly_array[] = {10, 20, 30, 40, 50};
    int readonly_size = 5;
    
    printf("Read-only array: ");
    print_array(readonly_array, readonly_size);
    printf("Sum (const function): %d\n", sum_array(readonly_array, readonly_size));
    
    // This would cause compilation error:
    // modify_array(readonly_array, readonly_size, 5);
    printf("→ Const arrays cannot be modified by functions\n\n");
    
    // 8. PARAMETER SCOPE DEMONSTRATION
    printf("8. PARAMETER SCOPE\n");
    
    int local_var = 50;
    printf("Before function: local_var = %d, global_var = %d\n", local_var, global_var);
    demonstrate_scope(local_var);
    printf("After function: local_var = %d, global_var = %d\n", local_var, global_var);
    printf("\n");
    
    // 9. PRACTICAL EXAMPLE - DATA PROCESSING
    printf("9. PRACTICAL EXAMPLE\n");
    
    int sales_data[] = {120, 85, 200, 150, 95, 175, 110};
    int days = sizeof(sales_data) / sizeof(sales_data[0]);
    
    printf("Weekly sales data: ");
    print_array(sales_data, days);
    
    printf("Total sales: %d\n", sum_array(sales_data, days));
    printf("Average daily sales: %.2f\n", calculate_average(sales_data, days));
    
    int min_sales, max_sales;
    get_min_max(sales_data, days, &min_sales, &max_sales);
    printf("Best day: %d sales, Worst day: %d sales\n", max_sales, min_sales);
    
    printf("\n=== Demo Complete ===\n");
    return 0;
}

// Function implementations

// Pass by value - parameters are copies
void pass_by_value_demo(int x, double y) {
    printf("Inside function (before): x = %d, y = %.2f\n", x, y);
    x = 999;        // Modifying the copy
    y = 999.99;     // Modifying the copy
    printf("Inside function (after): x = %d, y = %.2f\n", x, y);
}

// Pass by reference - parameters are addresses
void pass_by_reference_demo(int* x, double* y) {
    printf("Inside function (before): *x = %d, *y = %.2f\n", *x, *y);
    *x = 999;       // Modifying original variable
    *y = 999.99;    // Modifying original variable
    printf("Inside function (after): *x = %d, *y = %.2f\n", *x, *y);
}

// Correct way to swap using pointers
void swap_values(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Wrong way to swap (doesn't work)
void swap_values_wrong(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
    // Changes are lost when function ends
}

// Print array (const parameter - read-only)
void print_array(const int arr[], int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) printf(", ");
    }
    printf("]\n");
}

// Modify array elements (array passed by reference)
void modify_array(int arr[], int size, int increment) {
    for (int i = 0; i < size; i++) {
        arr[i] += increment;
    }
}

// Calculate sum (const parameter)
int sum_array(const int arr[], int size) {
    int total = 0;
    for (int i = 0; i < size; i++) {
        total += arr[i];
    }
    return total;
}

// Calculate average
double calculate_average(const int numbers[], int count) {
    if (count == 0) return 0.0;
    return (double)sum_array(numbers, count) / count;
}

// Return multiple values using pointer parameters
void get_min_max(const int arr[], int size, int* min, int* max) {
    if (size == 0) return;
    
    *min = arr[0];
    *max = arr[0];
    
    for (int i = 1; i < size; i++) {
        if (arr[i] < *min) *min = arr[i];
        if (arr[i] > *max) *max = arr[i];
    }
}

// Modify string (non-const parameter)
void process_string(char* str) {
    // Convert to uppercase
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - 'a' + 'A';
        }
    }
}

// Read-only string processing (const parameter)
void process_string_const(const char* str) {
    int length = strlen(str);
    int vowels = 0;
    
    for (int i = 0; i < length; i++) {
        char c = str[i];
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
            vowels++;
        }
    }
    
    printf("String analysis: length = %d, vowels = %d\n", length, vowels);
}

// Demonstrate parameter scope
void demonstrate_scope(int param) {
    printf("Inside function: param = %d (copy of argument)\n", param);
    param = 777;  // Modifying the copy
    global_var = 888;  // Modifying global variable
    printf("Inside function: param = %d, global_var = %d\n", param, global_var);
}
