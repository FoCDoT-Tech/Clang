#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for demonstrating member access operators
struct Point {
    int x;
    int y;
    char label[10];
};

// Function prototypes
void demonstrate_conditional_operator(void);
void demonstrate_sizeof_operator(void);
void demonstrate_address_dereference(void);
void demonstrate_member_access(void);
void demonstrate_function_call_operator(void);
void demonstrate_array_subscript(void);
void demonstrate_comma_operator(void);
int max_function(int a, int b);
void print_point(struct Point p);

int main() {
    printf("=== Other Operators Demo ===\n\n");
    
    demonstrate_conditional_operator();
    demonstrate_sizeof_operator();
    demonstrate_address_dereference();
    demonstrate_member_access();
    demonstrate_function_call_operator();
    demonstrate_array_subscript();
    demonstrate_comma_operator();
    
    printf("✓ All special operators demonstrated!\n");
    return 0;
}

void demonstrate_conditional_operator(void) {
    printf("1. CONDITIONAL OPERATOR (? :):\n");
    
    int a = 15, b = 10;
    printf("Given: a = %d, b = %d\n", a, b);
    
    // Basic ternary operation
    int max = (a > b) ? a : b;
    printf("max = (a > b) ? a : b; → %d\n", max);
    
    // Nested ternary (not recommended for readability)
    int c = 20;
    int largest = (a > b) ? ((a > c) ? a : c) : ((b > c) ? b : c);
    printf("Largest of %d, %d, %d: %d\n", a, b, c, largest);
    
    // Practical examples
    int age = 17;
    char *status = (age >= 18) ? "Adult" : "Minor";
    printf("Age %d: %s\n", age, status);
    
    int score = 85;
    char grade = (score >= 90) ? 'A' : 
                 (score >= 80) ? 'B' : 
                 (score >= 70) ? 'C' : 'F';
    printf("Score %d: Grade %c\n", score, grade);
    
    // Alternative to if-else for simple assignments
    int x = -5;
    int absolute = (x < 0) ? -x : x;
    printf("Absolute value of %d: %d\n", x, absolute);
    printf("\n");
}

void demonstrate_sizeof_operator(void) {
    printf("2. SIZEOF OPERATOR:\n");
    
    // Size of basic types
    printf("Size of basic types:\n");
    printf("sizeof(char):   %zu bytes\n", sizeof(char));
    printf("sizeof(int):    %zu bytes\n", sizeof(int));
    printf("sizeof(float):  %zu bytes\n", sizeof(float));
    printf("sizeof(double): %zu bytes\n", sizeof(double));
    printf("sizeof(void*):  %zu bytes\n", sizeof(void*));
    
    // Size of variables
    int number = 42;
    double pi = 3.14159;
    printf("\nSize of variables:\n");
    printf("sizeof(number): %zu bytes (int variable)\n", sizeof(number));
    printf("sizeof(pi):     %zu bytes (double variable)\n", sizeof(pi));
    
    // Size of arrays
    int array[10];
    char string[50];
    printf("\nSize of arrays:\n");
    printf("int array[10]:  %zu bytes (%zu elements)\n", 
           sizeof(array), sizeof(array)/sizeof(array[0]));
    printf("char string[50]: %zu bytes\n", sizeof(string));
    
    // Size of structures
    struct Point point;
    printf("\nSize of structures:\n");
    printf("sizeof(struct Point): %zu bytes\n", sizeof(struct Point));
    printf("sizeof(point):        %zu bytes\n", sizeof(point));
    
    // Practical use: array length
    int numbers[] = {1, 2, 3, 4, 5, 6, 7, 8};
    size_t length = sizeof(numbers) / sizeof(numbers[0]);
    printf("\nArray length calculation:\n");
    printf("Array has %zu elements\n", length);
    printf("\n");
}

void demonstrate_address_dereference(void) {
    printf("3. ADDRESS (&) AND DEREFERENCE (*) OPERATORS:\n");
    
    int value = 42;
    int *ptr;
    
    printf("Original variable: value = %d\n", value);
    printf("Address of value: &value = %p\n", (void*)&value);
    
    // Address operator
    ptr = &value;  // ptr now holds the address of value
    printf("Pointer assignment: ptr = &value\n");
    printf("Pointer value: ptr = %p\n", (void*)ptr);
    
    // Dereference operator
    printf("Dereferencing: *ptr = %d\n", *ptr);
    
    // Modifying through pointer
    *ptr = 100;
    printf("After *ptr = 100:\n");
    printf("  value = %d (original variable changed)\n", value);
    printf("  *ptr = %d (same value through pointer)\n", *ptr);
    
    // Multiple levels of indirection
    int **ptr_to_ptr = &ptr;
    printf("\nDouble indirection:\n");
    printf("ptr_to_ptr = %p (address of ptr)\n", (void*)ptr_to_ptr);
    printf("*ptr_to_ptr = %p (value of ptr)\n", (void*)*ptr_to_ptr);
    printf("**ptr_to_ptr = %d (value of value)\n", **ptr_to_ptr);
    
    // Practical example: swapping values
    int a = 10, b = 20;
    printf("\nSwapping example:\n");
    printf("Before: a = %d, b = %d\n", a, b);
    
    int *p1 = &a, *p2 = &b;
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
    
    printf("After:  a = %d, b = %d\n", a, b);
    printf("\n");
}

void demonstrate_member_access(void) {
    printf("4. MEMBER ACCESS OPERATORS (. and ->):\n");
    
    // Direct member access with dot operator
    struct Point point1 = {10, 20, "Origin"};
    printf("Direct access (point1.x, point1.y):\n");
    printf("point1.x = %d\n", point1.x);
    printf("point1.y = %d\n", point1.y);
    printf("point1.label = \"%s\"\n", point1.label);
    
    // Modify members directly
    point1.x = 30;
    point1.y = 40;
    strcpy(point1.label, "Modified");
    printf("After modification: (%d, %d) \"%s\"\n", 
           point1.x, point1.y, point1.label);
    
    // Indirect member access with arrow operator
    struct Point *ptr = &point1;
    printf("\nIndirect access (ptr->x, ptr->y):\n");
    printf("ptr->x = %d\n", ptr->x);
    printf("ptr->y = %d\n", ptr->y);
    printf("ptr->label = \"%s\"\n", ptr->label);
    
    // Arrow operator is equivalent to (*ptr).member
    printf("\nEquivalent expressions:\n");
    printf("ptr->x = %d\n", ptr->x);
    printf("(*ptr).x = %d\n", (*ptr).x);
    
    // Dynamic allocation
    struct Point *dynamic_point = malloc(sizeof(struct Point));
    if (dynamic_point != NULL) {
        dynamic_point->x = 100;
        dynamic_point->y = 200;
        strcpy(dynamic_point->label, "Dynamic");
        printf("Dynamic point: (%d, %d) \"%s\"\n", 
               dynamic_point->x, dynamic_point->y, dynamic_point->label);
        free(dynamic_point);
    }
    printf("\n");
}

void demonstrate_function_call_operator(void) {
    printf("5. FUNCTION CALL OPERATOR ():\n");
    
    // Direct function calls
    int result1 = max_function(15, 25);
    printf("max_function(15, 25) = %d\n", result1);
    
    // Function calls in expressions
    int a = 10, b = 20;
    int sum = max_function(a, b) + max_function(5, 8);
    printf("max_function(%d, %d) + max_function(5, 8) = %d\n", a, b, sum);
    
    // Function pointers
    int (*func_ptr)(int, int) = max_function;
    int result2 = func_ptr(30, 40);  // Call through function pointer
    printf("Function pointer call: func_ptr(30, 40) = %d\n", result2);
    
    // Alternative function pointer syntax
    int result3 = (*func_ptr)(50, 60);
    printf("Alternative syntax: (*func_ptr)(50, 60) = %d\n", result3);
    
    printf("\n");
}

void demonstrate_array_subscript(void) {
    printf("6. ARRAY SUBSCRIPT OPERATOR []:\n");
    
    int numbers[] = {10, 20, 30, 40, 50};
    printf("Array: {10, 20, 30, 40, 50}\n");
    
    // Basic array access
    printf("numbers[0] = %d\n", numbers[0]);
    printf("numbers[2] = %d\n", numbers[2]);
    printf("numbers[4] = %d\n", numbers[4]);
    
    // Array subscript is equivalent to pointer arithmetic
    printf("\nEquivalent expressions:\n");
    printf("numbers[2] = %d\n", numbers[2]);
    printf("*(numbers + 2) = %d\n", *(numbers + 2));
    printf("2[numbers] = %d (unusual but valid)\n", 2[numbers]);
    
    // Modifying array elements
    numbers[1] = 99;
    printf("After numbers[1] = 99: numbers[1] = %d\n", numbers[1]);
    
    // Multi-dimensional arrays
    int matrix[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    printf("\n3x3 Matrix access:\n");
    printf("matrix[1][2] = %d\n", matrix[1][2]);
    printf("matrix[2][0] = %d\n", matrix[2][0]);
    
    // String as character array
    char greeting[] = "Hello";
    printf("\nString access:\n");
    printf("greeting[0] = '%c'\n", greeting[0]);
    printf("greeting[4] = '%c'\n", greeting[4]);
    printf("\n");
}

void demonstrate_comma_operator(void) {
    printf("7. COMMA OPERATOR (,):\n");
    
    // Basic comma operator usage
    int a, b, c;
    a = (b = 5, c = 10, b + c);  // Evaluates left to right, returns rightmost
    printf("a = (b = 5, c = 10, b + c); → a = %d, b = %d, c = %d\n", a, b, c);
    
    // Comma in for loops
    printf("Comma operator in for loop:\n");
    for (int i = 0, j = 10; i < 5; i++, j--) {
        printf("i = %d, j = %d\n", i, j);
    }
    
    // Multiple assignments
    int x, y, z;
    x = 1, y = 2, z = 3;  // Equivalent to: (x = 1), (y = 2), (z = 3)
    printf("Multiple assignments: x = %d, y = %d, z = %d\n", x, y, z);
    
    // Comma vs parentheses
    int result1 = (1, 2, 3);  // result1 = 3 (last value)
    int result2;
    result2 = 1, 2, 3;        // result2 = 1 (assignment has higher precedence)
    printf("With parentheses: (1, 2, 3) = %d\n", result1);
    printf("Without parentheses: result = 1, 2, 3 → result = %d\n", result2);
    
    printf("Note: Comma operator has lowest precedence\n\n");
}

// Helper functions
int max_function(int a, int b) {
    return (a > b) ? a : b;
}

void print_point(struct Point p) {
    printf("Point: (%d, %d) \"%s\"\n", p.x, p.y, p.label);
}
