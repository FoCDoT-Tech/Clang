#include <stdio.h>

// Function prototypes
void demonstrate_basic_arithmetic(void);
void demonstrate_unary_operators(void);
void demonstrate_increment_decrement(void);
void demonstrate_division_types(void);
void demonstrate_modulo_operations(void);
void demonstrate_operator_precedence(void);

int main() {
    printf("=== Arithmetic Operators Demo ===\n\n");
    
    demonstrate_basic_arithmetic();
    demonstrate_unary_operators();
    demonstrate_increment_decrement();
    demonstrate_division_types();
    demonstrate_modulo_operations();
    demonstrate_operator_precedence();
    
    printf("✓ All arithmetic operators demonstrated!\n");
    return 0;
}

void demonstrate_basic_arithmetic(void) {
    printf("1. BASIC ARITHMETIC OPERATORS:\n");
    
    int a = 15, b = 4;
    printf("Given: a = %d, b = %d\n", a, b);
    
    printf("Addition (+):       a + b = %d\n", a + b);
    printf("Subtraction (-):    a - b = %d\n", a - b);
    printf("Multiplication (*): a * b = %d\n", a * b);
    printf("Division (/):       a / b = %d\n", a / b);
    printf("Modulo (%%):         a %% b = %d\n\n", a % b);
}

void demonstrate_unary_operators(void) {
    printf("2. UNARY OPERATORS:\n");
    
    int positive = 42;
    int negative = -25;
    
    printf("Original values: positive = %d, negative = %d\n", positive, negative);
    printf("Unary plus (+):  +positive = %d\n", +positive);
    printf("Unary minus (-): -positive = %d\n", -positive);
    printf("Unary minus (-): -negative = %d\n", -negative);
    
    // Practical use: sign flipping
    int temperature = -10;
    int absolute_temp = -temperature;  // Make positive
    printf("Temperature: %d°C, Absolute: %d°C\n\n", temperature, absolute_temp);
}

void demonstrate_increment_decrement(void) {
    printf("3. INCREMENT/DECREMENT OPERATORS:\n");
    
    // Pre-increment vs Post-increment
    int x = 5;
    printf("Initial value: x = %d\n", x);
    
    printf("Pre-increment (++x):  x = %d, returns %d\n", ++x, x);
    
    x = 5;  // Reset
    printf("Post-increment (x++): returns %d, x becomes %d\n", x++, x);
    
    // Pre-decrement vs Post-decrement
    x = 5;  // Reset
    printf("Pre-decrement (--x):  x = %d, returns %d\n", --x, x);
    
    x = 5;  // Reset
    printf("Post-decrement (x--): returns %d, x becomes %d\n", x--, x);
    
    // Practical example: loop counter
    printf("Practical use - counting down: ");
    for (int i = 3; i > 0; i--) {
        printf("%d ", i);
    }
    printf("Go!\n\n");
}

void demonstrate_division_types(void) {
    printf("4. DIVISION TYPES:\n");
    
    int int_a = 7, int_b = 2;
    float float_a = 7.0f, float_b = 2.0f;
    
    printf("Integer division: %d / %d = %d (truncated)\n", int_a, int_b, int_a / int_b);
    printf("Float division:   %.1f / %.1f = %.2f\n", float_a, float_b, float_a / float_b);
    
    // Mixed division - common mistake
    printf("Mixed (wrong):    %d / %d = %.2f (still integer division!)\n", 
           int_a, int_b, (float)(int_a / int_b));
    
    // Correct way to get float result from integers
    printf("Mixed (correct):  (float)%d / %d = %.2f\n", 
           int_a, int_b, (float)int_a / int_b);
    
    // Practical example: percentage calculation
    int score = 85, total = 100;
    float percentage = (float)score / total * 100;
    printf("Score: %d/%d = %.1f%%\n\n", score, total, percentage);
}

void demonstrate_modulo_operations(void) {
    printf("5. MODULO OPERATIONS:\n");
    
    int dividend = 17, divisor = 5;
    printf("%d %% %d = %d (remainder)\n", dividend, divisor, dividend % divisor);
    
    // Practical applications
    printf("Practical applications:\n");
    
    // Even/odd checking
    for (int i = 1; i <= 6; i++) {
        if (i % 2 == 0) {
            printf("  %d is even\n", i);
        } else {
            printf("  %d is odd\n", i);
        }
    }
    
    // Cycling through values (0-6 repeatedly)
    printf("Cycling days of week (0=Sun, 6=Sat): ");
    for (int day = 0; day < 10; day++) {
        printf("%d ", day % 7);
    }
    printf("\n\n");
}

void demonstrate_operator_precedence(void) {
    printf("6. OPERATOR PRECEDENCE:\n");
    
    int a = 2, b = 3, c = 4;
    printf("Given: a = %d, b = %d, c = %d\n", a, b, c);
    
    // Multiplication before addition
    int result1 = a + b * c;
    printf("a + b * c = %d + %d * %d = %d (multiplication first)\n", a, b, c, result1);
    
    // Parentheses override precedence
    int result2 = (a + b) * c;
    printf("(a + b) * c = (%d + %d) * %d = %d (parentheses first)\n", a, b, c, result2);
    
    // Complex expression
    int x = 10;
    int result3 = ++x * 2 + x--;  // Pre-increment, multiply, add, post-decrement
    printf("++x * 2 + x-- = %d (x ends up as %d)\n", result3, x);
    
    printf("Always use parentheses for clarity!\n\n");
}
