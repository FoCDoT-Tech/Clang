/*
 * type_conversion_demo.c - Demonstrates type conversions in C
 * Shows implicit/explicit conversions, promotion rules, and potential pitfalls
 */

#include <stdio.h>
#include <limits.h>

// Function declarations
void demonstrate_implicit_conversion(void);
void demonstrate_explicit_conversion(void);
void demonstrate_arithmetic_conversions(void);
void demonstrate_potential_issues(void);
void demonstrate_character_conversions(void);

int main() {
    printf("=== Type Conversion Demo ===\n\n");
    
    demonstrate_implicit_conversion();
    demonstrate_explicit_conversion();
    demonstrate_arithmetic_conversions();
    demonstrate_character_conversions();
    demonstrate_potential_issues();
    
    printf("✓ All type conversion concepts demonstrated!\n");
    return 0;
}

void demonstrate_implicit_conversion(void) {
    printf("1. IMPLICIT CONVERSION (Automatic):\n");
    
    // Type promotion in expressions
    int a = 5;
    float b = 2.5f;
    float result = a + b;  // 'a' automatically promoted to float
    
    printf("Type promotion in expressions:\n");
    printf("- int a = %d, float b = %.1f\n", a, b);
    printf("- a + b = %.1f (a promoted to float)\n", result);
    
    // Assignment conversions
    int i = 3.14;          // 3.14 truncated to 3
    float f = 10;          // 10 converted to 10.0f
    double d = 5;          // 5 converted to 5.0
    
    printf("\nAssignment conversions:\n");
    printf("- int i = 3.14 → i = %d (truncated)\n", i);
    printf("- float f = 10 → f = %.1f (converted)\n", f);
    printf("- double d = 5 → d = %.1f (converted)\n", d);
    
    // Mixed arithmetic
    int x = 7, y = 2;
    float mixed_result = x / y;  // Integer division, then convert to float
    
    printf("\nMixed arithmetic:\n");
    printf("- int x = %d, int y = %d\n", x, y);
    printf("- float result = x / y → %.1f (integer division first!)\n", mixed_result);
    
    printf("\n");
}

void demonstrate_explicit_conversion(void) {
    printf("2. EXPLICIT CONVERSION (Casting):\n");
    
    // Basic casting
    int a = 10, b = 3;
    float precise_division = (float)a / b;  // Cast for floating-point division
    
    printf("Explicit casting for precision:\n");
    printf("- int a = %d, int b = %d\n", a, b);
    printf("- a / b = %d (integer division)\n", a / b);
    printf("- (float)a / b = %.2f (floating-point division)\n", precise_division);
    
    // Truncation with casting
    double pi = 3.14159;
    int truncated = (int)pi;
    
    printf("\nTruncation with casting:\n");
    printf("- double pi = %.5f\n", pi);
    printf("- (int)pi = %d (truncated, not rounded)\n", truncated);
    
    // Size conversions
    long long big_num = 1234567890LL;
    int smaller = (int)big_num;
    
    printf("\nSize conversions:\n");
    printf("- long long big_num = %lld\n", big_num);
    printf("- (int)big_num = %d\n", smaller);
    
    printf("\n");
}

void demonstrate_arithmetic_conversions(void) {
    printf("3. ARITHMETIC CONVERSION RULES:\n");
    
    // Promotion hierarchy demonstration
    char c = 10;
    short s = 20;
    int i = 30;
    float f = 40.5f;
    double d = 50.75;
    
    printf("Promotion hierarchy: char → short → int → float → double\n");
    printf("- char c = %d\n", c);
    printf("- short s = %d\n", s);
    printf("- int i = %d\n", i);
    printf("- float f = %.1f\n", f);
    printf("- double d = %.2f\n", d);
    
    // Mixed operations
    printf("\nMixed operations (result type):\n");
    printf("- c + s = %d (promoted to int)\n", c + s);
    printf("- i + f = %.1f (promoted to float)\n", i + f);
    printf("- f + d = %.2f (promoted to double)\n", f + d);
    
    // Integer promotion
    char small1 = 100, small2 = 50;
    int promoted_result = small1 + small2;  // Both promoted to int
    
    printf("\nInteger promotion:\n");
    printf("- char small1 = %d, char small2 = %d\n", small1, small2);
    printf("- small1 + small2 = %d (both promoted to int)\n", promoted_result);
    
    printf("\n");
}

void demonstrate_character_conversions(void) {
    printf("4. CHARACTER CONVERSIONS:\n");
    
    // Character to integer
    char letter = 'A';
    int ascii_value = letter;  // Implicit conversion
    
    printf("Character to integer:\n");
    printf("- char letter = '%c'\n", letter);
    printf("- int ascii_value = %d (ASCII value)\n", ascii_value);
    
    // Integer to character
    int ascii_code = 66;
    char converted_char = (char)ascii_code;
    
    printf("\nInteger to character:\n");
    printf("- int ascii_code = %d\n", ascii_code);
    printf("- (char)ascii_code = '%c'\n", converted_char);
    
    // Character arithmetic
    char start = 'A';
    char next = start + 1;  // Character arithmetic
    
    printf("\nCharacter arithmetic:\n");
    printf("- char start = '%c'\n", start);
    printf("- start + 1 = '%c' (next letter)\n", next);
    
    printf("\n");
}

void demonstrate_potential_issues(void) {
    printf("5. POTENTIAL CONVERSION ISSUES:\n");
    
    // Data loss in size conversion
    int big_int = 70000;
    short small_short = (short)big_int;  // May overflow
    
    printf("Data loss in size conversion:\n");
    printf("- int big_int = %d\n", big_int);
    printf("- (short)big_int = %d", small_short);
    if (small_short != big_int) {
        printf(" ⚠️  Data loss occurred!");
    }
    printf("\n");
    
    // Sign conversion issues
    unsigned int u_max = UINT_MAX;
    int signed_result = (int)u_max;
    
    printf("\nSign conversion issues:\n");
    printf("- unsigned int u_max = %u\n", u_max);
    printf("- (int)u_max = %d", signed_result);
    if (signed_result < 0) {
        printf(" ⚠️  Became negative!");
    }
    printf("\n");
    
    // Precision loss
    double precise = 3.141592653589793;
    float less_precise = (float)precise;
    
    printf("\nPrecision loss:\n");
    printf("- double precise = %.15f\n", precise);
    printf("- (float)precise = %.15f", (double)less_precise);
    if (precise != (double)less_precise) {
        printf(" ⚠️  Precision lost!");
    }
    printf("\n");
    
    // Unexpected integer division
    int numerator = 7, denominator = 2;
    float wrong_result = numerator / denominator;  // Integer division first!
    float correct_result = (float)numerator / denominator;
    
    printf("\nInteger division trap:\n");
    printf("- int numerator = %d, int denominator = %d\n", numerator, denominator);
    printf("- numerator / denominator = %.1f (wrong: integer division first)\n", wrong_result);
    printf("- (float)numerator / denominator = %.1f (correct)\n", correct_result);
    
    printf("\nBest practices:\n");
    printf("- Be explicit with casts to show intent\n");
    printf("- Check value ranges before conversion\n");
    printf("- Use appropriate types for your data\n");
    printf("- Be careful with mixed arithmetic\n");
    
    printf("\n");
}
