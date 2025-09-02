#include <stdio.h>

// Function prototypes
void demonstrate_arithmetic_precedence(void);
void demonstrate_relational_precedence(void);
void demonstrate_logical_precedence(void);
void demonstrate_bitwise_precedence(void);
void demonstrate_assignment_associativity(void);
void demonstrate_common_pitfalls(void);
void demonstrate_best_practices(void);

int main() {
    printf("=== Operator Precedence & Associativity Demo ===\n\n");
    
    demonstrate_arithmetic_precedence();
    demonstrate_relational_precedence();
    demonstrate_logical_precedence();
    demonstrate_bitwise_precedence();
    demonstrate_assignment_associativity();
    demonstrate_common_pitfalls();
    demonstrate_best_practices();
    
    printf("✓ All precedence and associativity rules demonstrated!\n");
    return 0;
}

void demonstrate_arithmetic_precedence(void) {
    printf("1. ARITHMETIC OPERATOR PRECEDENCE:\n");
    
    // Multiplication before addition
    int result1 = 2 + 3 * 4;
    printf("2 + 3 * 4 = %d (multiplication first: 2 + 12)\n", result1);
    
    // Parentheses override precedence
    int result2 = (2 + 3) * 4;
    printf("(2 + 3) * 4 = %d (parentheses first: 5 * 4)\n", result2);
    
    // Multiple operators
    int result3 = 10 - 6 / 2 + 1;
    printf("10 - 6 / 2 + 1 = %d (division first: 10 - 3 + 1)\n", result3);
    
    // Left-to-right associativity for same precedence
    int result4 = 20 / 4 / 2;
    printf("20 / 4 / 2 = %d (left-to-right: (20 / 4) / 2 = 5 / 2)\n", result4);
    
    int result5 = 20 / (4 / 2);
    printf("20 / (4 / 2) = %d (parentheses change order: 20 / 2)\n", result5);
    
    printf("\n");
}

void demonstrate_relational_precedence(void) {
    printf("2. RELATIONAL OPERATOR PRECEDENCE:\n");
    
    int a = 5, b = 10, c = 15;
    printf("Given: a = %d, b = %d, c = %d\n", a, b, c);
    
    // Arithmetic before relational
    int result1 = a + b < c * 2;
    printf("a + b < c * 2 = %d + %d < %d * 2 = %d < %d = %d\n", 
           a, b, c, a + b, c * 2, result1);
    
    // Relational before equality
    int result2 = a < b == c > b;
    printf("a < b == c > b = (%d < %d) == (%d > %d) = %d == %d = %d\n", 
           a, b, c, b, a < b, c > b, result2);
    
    // Chained comparisons (common mistake)
    int x = 5;
    int wrong = 1 < x < 10;  // Evaluates as (1 < x) < 10
    printf("Wrong: 1 < x < 10 with x=%d gives %d (misleading!)\n", x, wrong);
    
    int correct = (1 < x) && (x < 10);
    printf("Correct: (1 < x) && (x < 10) gives %d\n", correct);
    
    printf("\n");
}

void demonstrate_logical_precedence(void) {
    printf("3. LOGICAL OPERATOR PRECEDENCE:\n");
    
    int p = 1, q = 0, r = 1;
    printf("Given: p = %d, q = %d, r = %d\n", p, q, r);
    
    // NOT has highest precedence
    int result1 = !p && q;
    printf("!p && q = (!%d) && %d = %d && %d = %d\n", p, q, !p, q, result1);
    
    // AND before OR
    int result2 = p || q && r;
    printf("p || q && r = %d || (%d && %d) = %d || %d = %d\n", 
           p, q, r, q && r, result2);
    
    // Parentheses change evaluation
    int result3 = (p || q) && r;
    printf("(p || q) && r = (%d || %d) && %d = %d && %d = %d\n", 
           p, q, r, p || q, result3);
    
    // Relational before logical
    int a = 5, b = 10;
    int result4 = a < b && b > 0;
    printf("a < b && b > 0 = (%d < %d) && (%d > 0) = %d && %d = %d\n", 
           a, b, b, a < b, b > 0, result4);
    
    printf("\n");
}

void demonstrate_bitwise_precedence(void) {
    printf("4. BITWISE OPERATOR PRECEDENCE:\n");
    
    unsigned char a = 5, b = 3, c = 1;  // 101, 011, 001
    printf("Given: a = %d, b = %d, c = %d\n", a, b, c);
    
    // Shift before bitwise AND/OR
    unsigned char result1 = a & b << c;
    printf("a & b << c = %d & (%d << %d) = %d & %d = %d\n", 
           a, b, c, b << c, result1);
    
    // AND before XOR before OR
    unsigned char result2 = a | b & c;
    printf("a | b & c = %d | (%d & %d) = %d | %d = %d\n", 
           a, b, c, b & c, result2);
    
    // Arithmetic before bitwise
    unsigned char result3 = a + b & c;
    printf("a + b & c = (%d + %d) & %d = %d & %d = %d\n", 
           a, b, c, a + b, result3);
    
    // Common mistake: bitwise vs logical
    int x = 4, y = 2;
    printf("\nBitwise vs Logical (x = %d, y = %d):\n", x, y);
    printf("x & y = %d (bitwise AND)\n", x & y);
    printf("x && y = %d (logical AND)\n", x && y);
    
    printf("\n");
}

void demonstrate_assignment_associativity(void) {
    printf("5. ASSIGNMENT ASSOCIATIVITY (Right-to-Left):\n");
    
    // Chain assignment
    int a, b, c;
    a = b = c = 10;
    printf("a = b = c = 10; → a = %d, b = %d, c = %d\n", a, b, c);
    printf("Evaluates as: a = (b = (c = 10))\n");
    
    // Assignment in expressions
    int x = 0, y = 0;
    y = (x = 5) + 3;
    printf("y = (x = 5) + 3; → x = %d, y = %d\n", x, y);
    
    // Compound assignment precedence
    int value = 10;
    value += 2 * 3;  // Addition assignment has lower precedence than multiplication
    printf("value += 2 * 3 with value=10 → value = %d (10 + 6)\n", value);
    
    // Assignment vs equality precedence
    int test = 5;
    if ((test = 3) == 3) {  // Assignment, then comparison
        printf("Assignment in condition: test is now %d\n", test);
    }
    
    printf("\n");
}

void demonstrate_common_pitfalls(void) {
    printf("6. COMMON PRECEDENCE PITFALLS:\n");
    
    // Bitwise AND with equality
    int num = 6;  // Binary: 110
    printf("Checking if number %d is even:\n", num);
    
    // Wrong: & has lower precedence than ==
    int wrong = num & 1 == 0;
    printf("Wrong: num & 1 == 0 = %d & (%d == 0) = %d & %d = %d\n", 
           num, 1, 1, 0, wrong);
    
    // Correct: use parentheses
    int correct = (num & 1) == 0;
    printf("Correct: (num & 1) == 0 = (%d & 1) == 0 = %d == 0 = %d\n", 
           num, num & 1, correct);
    
    // Shift operator precedence
    int shift_wrong = 1 << 2 + 1;  // 1 << (2 + 1) = 1 << 3 = 8
    int shift_intended = (1 << 2) + 1;  // (1 << 2) + 1 = 4 + 1 = 5
    printf("\nShift precedence:\n");
    printf("1 << 2 + 1 = %d (addition first: 1 << 3)\n", shift_wrong);
    printf("(1 << 2) + 1 = %d (shift first: 4 + 1)\n", shift_intended);
    
    // Conditional operator precedence
    int a = 5, b = 10;
    int cond_result = a > b ? a : b + 1;  // a > b ? a : (b + 1)
    printf("\nConditional precedence:\n");
    printf("a > b ? a : b + 1 with a=%d, b=%d = %d\n", a, b, cond_result);
    
    printf("\n");
}

void demonstrate_best_practices(void) {
    printf("7. BEST PRACTICES:\n");
    
    // Use parentheses for clarity
    int a = 5, b = 10, c = 15;
    
    // Without parentheses (relies on precedence knowledge)
    int unclear = a + b * c - a / b;
    printf("Unclear: a + b * c - a / b = %d\n", unclear);
    
    // With parentheses (explicit and clear)
    int clear = a + (b * c) - (a / b);
    printf("Clear: a + (b * c) - (a / b) = %d\n", clear);
    
    // Break complex expressions
    printf("\nBreaking complex expressions:\n");
    
    // Complex (hard to read)
    int complex = (a > b) ? (a * c + b) : (b * c - a);
    printf("Complex: %d\n", complex);
    
    // Broken down (easier to understand)
    int condition = (a > b);
    int true_value = (a * c) + b;
    int false_value = (b * c) - a;
    int simple = condition ? true_value : false_value;
    printf("Broken down: %d\n", simple);
    
    // Use meaningful variable names
    int test_num = 8;
    int is_even = (test_num & 1) == 0;
    int is_power_of_two = (test_num > 0) && ((test_num & (test_num - 1)) == 0);
    printf("\nMeaningful expressions (test_num = %d):\n", test_num);
    printf("is_even = %d\n", is_even);
    printf("is_power_of_two = %d\n", is_power_of_two);
    
    printf("\nRemember: When in doubt, use parentheses!\n\n");
}
