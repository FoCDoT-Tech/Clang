#include <stdio.h>
#include <math.h>

// Function prototypes
void demonstrate_basic_comparisons(void);
void demonstrate_equality_operators(void);
void demonstrate_common_mistakes(void);
void demonstrate_floating_point_comparisons(void);
void demonstrate_practical_applications(void);
void demonstrate_operator_precedence(void);

int main() {
    printf("=== Relational Operators Demo ===\n\n");
    
    demonstrate_basic_comparisons();
    demonstrate_equality_operators();
    demonstrate_common_mistakes();
    demonstrate_floating_point_comparisons();
    demonstrate_practical_applications();
    demonstrate_operator_precedence();
    
    printf("✓ All relational operators demonstrated!\n");
    return 0;
}

void demonstrate_basic_comparisons(void) {
    printf("1. BASIC COMPARISON OPERATORS:\n");
    
    int a = 10, b = 20, c = 10;
    printf("Given: a = %d, b = %d, c = %d\n", a, b, c);
    
    printf("a < b:  %d < %d = %d (true)\n", a, b, a < b);
    printf("a > b:  %d > %d = %d (false)\n", a, b, a > b);
    printf("a <= c: %d <= %d = %d (true)\n", a, c, a <= c);
    printf("b >= a: %d >= %d = %d (true)\n", b, a, b >= a);
    
    // Demonstrating return values
    int result = (a < b);
    printf("Storing comparison result: (a < b) = %d\n\n", result);
}

void demonstrate_equality_operators(void) {
    printf("2. EQUALITY OPERATORS:\n");
    
    int x = 15, y = 15, z = 25;
    printf("Given: x = %d, y = %d, z = %d\n", x, y, z);
    
    printf("x == y: %d == %d = %d (true)\n", x, y, x == y);
    printf("x == z: %d == %d = %d (false)\n", x, z, x == z);
    printf("x != y: %d != %d = %d (false)\n", x, y, x != y);
    printf("x != z: %d != %d = %d (true)\n", x, z, x != z);
    
    // Character comparisons
    char ch1 = 'A', ch2 = 'B';
    printf("Character comparison: '%c' < '%c' = %d (ASCII: %d < %d)\n\n", 
           ch1, ch2, ch1 < ch2, ch1, ch2);
}

void demonstrate_common_mistakes(void) {
    printf("3. COMMON MISTAKES:\n");
    
    int value = 10;
    
    // Assignment vs comparison mistake
    printf("Original value: %d\n", value);
    
    // This is assignment, not comparison!
    if (value = 5) {  // Warning: assignment in condition
        printf("Assignment mistake: value is now %d (always true)\n", value);
    }
    
    value = 10;  // Reset
    
    // Correct comparison
    if (value == 5) {
        printf("This won't print (value is %d)\n", value);
    } else {
        printf("Correct comparison: value (%d) is not equal to 5\n", value);
    }
    
    // Chaining comparison mistake
    int num = 15;
    printf("Testing chained comparison with num = %d:\n", num);
    
    // Wrong way (doesn't work as expected)
    if (1 < num < 10) {  // Evaluates as (1 < num) < 10, which is 1 < 10 = true
        printf("Wrong chaining: appears to work but logic is flawed\n");
    }
    
    // Correct way
    if (num > 1 && num < 10) {
        printf("Correct chaining: num is between 1 and 10\n");
    } else {
        printf("Correct chaining: num (%d) is NOT between 1 and 10\n", num);
    }
    printf("\n");
}

void demonstrate_floating_point_comparisons(void) {
    printf("4. FLOATING-POINT COMPARISONS:\n");
    
    float a = 0.1f + 0.2f;
    float b = 0.3f;
    
    printf("a = 0.1 + 0.2 = %.10f\n", a);
    printf("b = 0.3       = %.10f\n", b);
    
    // Dangerous: exact equality
    if (a == b) {
        printf("Exact equality: a == b is true\n");
    } else {
        printf("Exact equality: a == b is false (precision issue!)\n");
    }
    
    // Better: tolerance-based comparison
    float tolerance = 0.0001f;
    if (fabs(a - b) < tolerance) {
        printf("Tolerance-based: |a - b| < %.4f is true\n", tolerance);
    } else {
        printf("Tolerance-based: |a - b| < %.4f is false\n", tolerance);
    }
    
    printf("Always use tolerance for float comparisons!\n\n");
}

void demonstrate_practical_applications(void) {
    printf("5. PRACTICAL APPLICATIONS:\n");
    
    // Grade classification
    int score = 85;
    printf("Student score: %d\n", score);
    
    if (score >= 90) {
        printf("Grade: A (Excellent)\n");
    } else if (score >= 80) {
        printf("Grade: B (Good)\n");
    } else if (score >= 70) {
        printf("Grade: C (Average)\n");
    } else if (score >= 60) {
        printf("Grade: D (Below Average)\n");
    } else {
        printf("Grade: F (Fail)\n");
    }
    
    // Range checking
    int age = 25;
    printf("Age validation for age %d:\n", age);
    
    if (age < 0) {
        printf("Invalid age (negative)\n");
    } else if (age < 18) {
        printf("Minor\n");
    } else if (age <= 65) {
        printf("Adult\n");
    } else {
        printf("Senior citizen\n");
    }
    
    // Even/odd using modulo and comparison
    int number = 17;
    if (number % 2 == 0) {
        printf("%d is even\n", number);
    } else {
        printf("%d is odd\n", number);
    }
    printf("\n");
}

void demonstrate_operator_precedence(void) {
    printf("6. OPERATOR PRECEDENCE:\n");
    
    int a = 5, b = 10, c = 15;
    printf("Given: a = %d, b = %d, c = %d\n", a, b, c);
    
    // Arithmetic vs relational precedence
    int result1 = a + b < c;  // Addition first, then comparison
    printf("a + b < c = %d + %d < %d = %d < %d = %d\n", a, b, c, a+b, c, result1);
    
    // Comparison vs equality precedence
    int result2 = a < b == c > b;  // (a < b) == (c > b)
    printf("a < b == c > b = (%d < %d) == (%d > %d) = %d == %d = %d\n", 
           a, b, c, b, a < b, c > b, result2);
    
    // Using parentheses for clarity
    int result3 = (a + b) < (c - 2);
    printf("(a + b) < (c - 2) = (%d + %d) < (%d - 2) = %d < %d = %d\n", 
           a, b, c, a+b, c-2, result3);
    
    printf("Use parentheses to make intentions clear!\n\n");
}
