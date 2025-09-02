#include <stdio.h>
#include <math.h>
#include <string.h>

// Function declarations (prototypes) - placed before main()
int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
double divide(double a, double b);
void print_separator(void);
void greet_user(const char* name);
int is_even(int number);
int factorial(int n);
double power(double base, int exponent);
int find_max(int a, int b, int c);
void print_number_info(int num);

// Global variable (accessible by all functions)
int global_counter = 0;

int main() {
    printf("=== Function Basics Demo ===\n\n");
    
    // 1. BASIC FUNCTION CALLS
    printf("1. BASIC ARITHMETIC FUNCTIONS\n");
    
    int x = 15, y = 7;
    printf("x = %d, y = %d\n", x, y);
    
    // Function calls with return values
    int sum = add(x, y);
    int diff = subtract(x, y);
    int product = multiply(x, y);
    double quotient = divide(x, y);
    
    printf("add(%d, %d) = %d\n", x, y, sum);
    printf("subtract(%d, %d) = %d\n", x, y, diff);
    printf("multiply(%d, %d) = %d\n", x, y, product);
    printf("divide(%d, %d) = %.2f\n", x, y, quotient);
    
    print_separator();
    
    // 2. VOID FUNCTIONS (NO RETURN VALUE)
    printf("2. VOID FUNCTIONS\n");
    
    greet_user("Alice");
    greet_user("Bob");
    print_separator();
    
    // 3. FUNCTIONS WITH DIFFERENT RETURN TYPES
    printf("3. DIFFERENT RETURN TYPES\n");
    
    int test_numbers[] = {4, 7, 12, 15};
    for (int i = 0; i < 4; i++) {
        int num = test_numbers[i];
        if (is_even(num)) {
            printf("%d is even\n", num);
        } else {
            printf("%d is odd\n", num);
        }
    }
    
    print_separator();
    
    // 4. MATHEMATICAL FUNCTIONS
    printf("4. MATHEMATICAL FUNCTIONS\n");
    
    // Factorial function
    for (int i = 0; i <= 6; i++) {
        printf("%d! = %d\n", i, factorial(i));
    }
    
    printf("\nPower calculations:\n");
    printf("2^3 = %.0f\n", power(2.0, 3));
    printf("5^2 = %.0f\n", power(5.0, 2));
    printf("3^4 = %.0f\n", power(3.0, 4));
    
    print_separator();
    
    // 5. FUNCTIONS WITH MULTIPLE PARAMETERS
    printf("5. MULTIPLE PARAMETERS\n");
    
    printf("Maximum of (10, 25, 18): %d\n", find_max(10, 25, 18));
    printf("Maximum of (7, 3, 12): %d\n", find_max(7, 3, 12));
    printf("Maximum of (50, 50, 30): %d\n", find_max(50, 50, 30));
    
    print_separator();
    
    // 6. LOCAL VS GLOBAL VARIABLES
    printf("6. LOCAL VS GLOBAL SCOPE\n");
    
    printf("Initial global_counter: %d\n", global_counter);
    
    // Local variable in main
    int local_var = 100;
    printf("Local variable in main: %d\n", local_var);
    
    // Call function that uses global variable
    print_number_info(42);
    print_number_info(17);
    
    printf("Final global_counter: %d\n", global_counter);
    
    print_separator();
    
    // 7. FUNCTION CALL CHAIN
    printf("7. FUNCTION CALL CHAIN\n");
    
    // Functions calling other functions
    int a = 8, b = 12, c = 6;
    int max_val = find_max(a, b, c);
    printf("Numbers: %d, %d, %d\n", a, b, c);
    printf("Maximum: %d\n", max_val);
    printf("Is maximum even? %s\n", is_even(max_val) ? "Yes" : "No");
    printf("Maximum factorial: %d\n", factorial(max_val));
    
    print_separator();
    
    // 8. PRACTICAL EXAMPLE - CALCULATOR
    printf("8. CALCULATOR FUNCTIONS\n");
    
    double num1 = 25.5, num2 = 4.2;
    printf("Calculator with %.1f and %.1f:\n", num1, num2);
    printf("Addition: %.1f + %.1f = %.1f\n", num1, num2, num1 + num2);
    printf("Subtraction: %.1f - %.1f = %.1f\n", num1, num2, num1 - num2);
    printf("Multiplication: %.1f × %.1f = %.1f\n", num1, num2, num1 * num2);
    printf("Division: %.1f ÷ %.1f = %.2f\n", num1, num2, divide(num1, num2));
    
    printf("\n=== Demo Complete ===\n");
    return 0;
}

// Function definitions (implementations)

// Basic arithmetic functions
int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

double divide(double a, double b) {
    if (b != 0) {
        return a / b;
    } else {
        printf("Error: Division by zero!\n");
        return 0.0;
    }
}

// Void function - no return value
void print_separator(void) {
    printf("\n" "----------------------------------------" "\n\n");
}

// Void function with parameter
void greet_user(const char* name) {
    printf("Hello, %s! Welcome to C programming.\n", name);
}

// Function returning boolean-like value (int)
int is_even(int number) {
    return (number % 2 == 0);
}

// Recursive-style function (iterative implementation for basics)
int factorial(int n) {
    if (n < 0) {
        return -1;  // Error case
    }
    if (n == 0 || n == 1) {
        return 1;
    }
    
    int result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

// Function with floating point return
double power(double base, int exponent) {
    if (exponent == 0) {
        return 1.0;
    }
    if (exponent < 0) {
        return 1.0 / power(base, -exponent);
    }
    
    double result = 1.0;
    for (int i = 0; i < exponent; i++) {
        result *= base;
    }
    return result;
}

// Function with multiple parameters
int find_max(int a, int b, int c) {
    int max = a;
    if (b > max) {
        max = b;
    }
    if (c > max) {
        max = c;
    }
    return max;
}

// Function demonstrating local vs global scope
void print_number_info(int num) {
    // Local variable - only exists in this function
    int local_count = 1;
    
    // Access global variable
    global_counter++;
    
    printf("Processing number: %d\n", num);
    printf("  Local count: %d\n", local_count);
    printf("  Global counter: %d\n", global_counter);
    printf("  Is even: %s\n", is_even(num) ? "Yes" : "No");
    
    // local_count goes out of scope when function ends
}
